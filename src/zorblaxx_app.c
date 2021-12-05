/*============================================================================
	Aznable OS - Zorblaxx demo application

	Author: Jim Gregory - https://github.com/JimmyStones/
	Version: 1.0
	Date: 2021-11-27

	This program is free software; you can redistribute it and/or modify it
	under the terms of the GNU General Public License as published by the Free
	Software Foundation; either version 3 of the License, or (at your option)
	any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License along
	with this program. If not, see <http://www.gnu.org/licenses/>.
===========================================================================*/

/*
	Sprite indexes:
	0-10	- Trails
	11		- Player
	12-27   - Asteroids
	28-31	- Explosions
*/

#include "sys.h"
#include "sprite.h"
#include "ui.h"
#include "music.h"
#include "zorblaxx_app.h"
#include "zorblaxx_player.h"
#include "zorblaxx_trails.h"
#include "zorblaxx_explosions.h"
#include "zorblaxx_asteroids.h"

// Area and units
const unsigned char x_divisor = 16;
const unsigned char y_divisor = 16;
unsigned short x_min = 2;
unsigned short x_max = 336;
unsigned short x_h_min;
unsigned short x_h_max;
unsigned char scroll_speed;

// Game defaults
unsigned short player_spawn_x = 166;
unsigned short player_spawn_y = 200;

// Game states
typedef enum
{
	enter_field,
	in_field,
	field_ending,
	field_complete,
	in_warp,
	approaching_field
} game_state_enum;

game_state_enum game_state = 0;
unsigned short game_state_timer = 0;

// Level progression
unsigned char level_number = 0;
unsigned char level_time = 0;
unsigned char level_time_timer = 0;
unsigned char level_playercontrol = 0;
unsigned short level_progress = 0;
unsigned char level_progress_timer = 0;
unsigned short level_progress_max;
const unsigned short level_progress_base = 30000;
const unsigned short level_progress_per_level = 2500;
const unsigned short game_state_warp_timeout_first = 60;
const unsigned short game_state_warp_timeout = 300;
const unsigned short game_state_danger_timeout = 120;

unsigned long high_score = 5000;
unsigned long player_score = 0;
unsigned char player_score_timer = 0;
unsigned char player_score_timer_frequency = 100;

void setup_area()
{
	x_h_min = (unsigned short)(x_min * x_divisor);
	x_h_max = (unsigned short)(x_max * x_divisor);
}

void intro_loop()
{
	clear_bgcolor(0);

	// Start intro music loop
	play_music(0);

	// Setup starfield layer speeds
	starfield[0] = 8;
	starfield[1] = 16;
	starfield[2] = 32;

	// Setup title sprites
	unsigned char title_sprite = 16;
	unsigned short title_x = 115;
	signed short title_y = -32 * y_divisor;
	signed short title_target_y = 100 * y_divisor;
	unsigned char si = 0;
	for (unsigned char y = 0; y < 2; y++)
	{
		for (unsigned char x = 0; x < 8; x++)
		{
			enable_sprite(title_sprite, 2, 0);
			spr_index[title_sprite] = title_sprite_index_first + si;
			spr_x[title_sprite] = title_x + (x * 16);
			signed short sy = -32 + (y * 16);
			spr_y_h[title_sprite] = sy >> 8;
			spr_y_l[title_sprite] = (unsigned char)sy;
			si++;
			title_sprite++;
		}
	}

	// unsigned char smax = 32;
	// unsigned char x = 16;
	// signed short sy = 32;
	// for (unsigned char s = 0; s < smax; s++)
	// {
	// 	enable_sprite(s, 0, false);
	// 	spr_index[s] = asteroids_sprite_index_first;
	// 	spr_x[s] = x;
	// 	x += 8;
	// 	spr_y_h[s] = sy >> 8;
	// 	spr_y_l[s] = (unsigned char)sy;
	// }

	unsigned char show_instruction = 0;
	unsigned char title_ready = 0;

	while (1)
	{
		vblank = input0 & 0x10;

		if (VBLANK_RISING)
		{
			// If button pressed, leave intro and start game
			if (CHECK_BIT(joystick[0], 4))
			{
				return;
			}
			update_sprites();
		}

		if (VBLANK_FALLING)
		{
			// Move title into position
			if (title_y < title_target_y)
			{
				signed short diff = (title_target_y - title_y) / 6;
				if (diff > 64)
				{
					diff = 64;
				}
				else if (diff == 0)
				{
					diff = 2;
				}
				title_y += diff;
				title_sprite = 16;
				for (unsigned char y = 0; y < 2; y++)
				{
					unsigned short sy = (title_y / y_divisor) + (y * 16);
					for (unsigned char x = 0; x < 8; x++)
					{
						spr_y_h[title_sprite] = sy >> 8;
						spr_y_l[title_sprite] = (unsigned char)sy;
						title_sprite++;
					}
				}
			}
			else
			{
				title_ready = 1;
			}

			// Move player into position
			move_player_to_target();

			if (show_instruction == 0 && player_ready == 1 && title_ready == 1)
			{
				write_string("Press A to start", 0xFF, 12, 17);
				show_instruction = 1;
			}

			// Trail
			player_trail_timer--;
			if (player_trail_timer <= 0)
			{
				player_trail_timer = player_trail_frequency - ((player_speed * 10) / 50);
				if (player_trail_timer <= 0)
				{
					player_trail_timer = 1;
				}
				add_player_trail();
			}
			handle_trails();
		}
		vblank_last = vblank;
	}
}

// Starfield variables
unsigned char scroll_speed_last = 0;
unsigned char sf_speed1 = 4;
// unsigned char sound_timer = 0;

void game_loop()
{

	// Reset progress
	level_number = 0;
	level_progress = 0;
	level_playercontrol = 0;

	game_state = 4; // Start in warp mode
	game_state_timer = game_state_warp_timeout_first;

	// Setup player
	setup_player(player_spawn_x, 260);
	player_speed = player_speed_warp;
	player_score = 0;
	player_score_timer = 0;

	// Setup asteroids
	setup_asteroids();

	// Setup explosions
	setup_explosions();

	while (1)
	{
		vblank = input0 & 0x10;

		if (VBLANK_RISING)
		{
			// Update sprite registers
			update_sprites();

			// Update starfield
			scroll_speed = player_speed;
			if (scroll_speed != scroll_speed_last)
			{
				scroll_speed_last = scroll_speed;
				unsigned char s = scroll_speed / sf_speed1;
				starfield[0] = s;
				s = s / 2;
				starfield[2] = s;
				s = s / 2;
				starfield[4] = s;
			}

			// Detect player collision
			if (spritecollisionram[player_sprite])
			{
				player_hit = true;
				spritecollisionram[player_sprite] = 0;
			}
		}

		if (VBLANK_FALLING)
		{

			handle_player(level_playercontrol);
			handle_trails();
			handle_explosions();
			handle_asteroids(game_state == 1);

			level_time_timer++;
			if (level_time_timer >= 60)
			{
				level_time++;
				level_time_timer = 0;
			}

			// Game state machine
			switch (game_state)
			{
			case enter_field: // Player is entering a new field
				game_state = in_field;
				level_progress = 0;
				level_progress_timer = 0;
				level_number++;
				level_time = 0;
				level_time_timer = 0;
				level_playercontrol = 1;
				unsigned short per_level = level_number < 13 ? (level_number * level_progress_per_level) : 13 * level_progress_per_level;
				level_progress_max = level_progress_base + per_level;

				// Start main music loop
				play_music(1);

				// Update asteroid difficulty
				asteroids_difficulty = level_number * 2;
				asteroids_active_max = 5 + asteroids_difficulty;
				if (asteroids_active_max > asteroids_max)
				{
					asteroids_active_max = asteroids_max;
				}

				write_stringf("Field %d", 0xFF, 15, 0, level_number);
				break;
			case in_field:
				// Level progress
				level_progress += player_speed;
				level_progress_timer++;
				if (level_progress_timer > 10)
				{
					unsigned char progress = level_progress / (level_progress_max / 100);
					write_stringf("%3d%%", 0xFF, 18, 29, progress);
					level_progress_timer = 0;
				}
				if (level_progress >= level_progress_max)
				{
					write_string("100%", 0xFF, 18, 29);
					game_state = field_ending;
				}

				// Player score
				player_score_timer += player_speed;
				if (player_score_timer >= player_score_timer_frequency)
				{
					player_score_timer -= player_score_timer_frequency;
					player_score++;
				}

				break;
			case field_ending:
				// Level ended - wait for all asteroids to clear

				// Keep scoring until asteroids are clear
				player_score_timer += player_speed;
				if (player_score_timer >= player_score_timer_frequency)
				{
					player_score_timer -= player_score_timer_frequency;
					player_score++;
				}
				if (asteroids_active == 0)
				{
					game_state = field_complete;
					game_state_timer = 0;
					game_state_timer = game_state_warp_timeout;

					// Start score music loop
					play_music(2);

					level_playercontrol = 0;
					set_player_target(player_spawn_x * x_divisor, player_spawn_y * y_divisor, 6, 24);

					write_stringf_ushort("FIELD COMPLETED", 0xFF, 10, 11, level_number);
					write_string("---------------", 0xFF, 10, 12);

					unsigned short par_time = level_progress_max / 60 / (player_speed_min + (player_speed_min / 2));
					unsigned short bonus = 0;
					if (level_time < par_time)
					{
						bonus = (par_time - level_time) * 2;
					}
					player_score += bonus;

					write_stringf_ushort("Time: %6d", 0xFF, 12, 14, level_time);
					write_stringf_ushort("Par: %6d", 0xFF, 13, 15, par_time);
					if (bonus > 0)
					{
						write_stringf_ushort("Bonus: %6d", 0b00011000, 11, 17, bonus);
					}
					else
					{
						write_string("No bonus :(", 0b01011011, 12, 17);
					}
					write_stringf_ulong("Score: %6d", 0xFF, 11, 19, player_score);
				}
				break;
			case field_complete: // Display field completed screen while bringing ship up to speed
				move_player_to_target();
				if (player_speed < player_speed_warp)
				{
					player_speed++;
				}
				else
				{
					game_state = in_warp;
				}
				break;
			case in_warp: // Do a bit of warp speed
				move_player_to_target();
				game_state_timer--;

				write_stringf_ushort("%6d", 0xFF, 0, 2, game_state_timer);
				if (game_state_timer == 0)
				{
					clear_chars(0);
					write_string("DANGER!", 0b00000011, 16, 14);
					write_string("- Entering asteroid field -", 0xFF, 07, 16);
					game_state = approaching_field;
					game_state_timer = game_state_danger_timeout;
				}
				break;
			case approaching_field: // Slow down again ready for start
				move_player_to_target();
				if (player_speed > player_speed_min)
				{
					player_speed--;
				}

				game_state_timer--;
				if (game_state_timer == 0)
				{
					clear_chars(0);
					game_state = enter_field;
				}
				break;
			}

			// Draw player score last
			write_stringf_ulong("%10d", 0xFF, 30, 0, player_score);
		}

		vblank_last = vblank;
	}
}

void app_zorblaxx()
{
	setup_area();
	setup_player(player_spawn_x, 256);
	set_player_target(player_spawn_x * x_divisor, player_spawn_y * y_divisor, 6, 24);
	setup_trails();

	intro_loop();

	// Clear character map and title sprites
	clear_chars(0);
	clear_sprites_range(16, 32);

	game_loop();
}