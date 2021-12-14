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
	0-9	- Trails
	10	- Pickup
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
#include "zorblaxx_pickups.h"
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
	game_start,
	enter_field,
	in_field,
	field_ending,
	field_complete,
	in_warp,
	approaching_field,
	game_over,
	game_over_waitforstats,
	game_over_stats,
	game_over_waitforscoreentry

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
const unsigned short level_progress_base = 20000;
const unsigned short level_progress_per_level = 3000;
const unsigned short game_state_warp_timeout_first = 120;
const unsigned short game_state_warp_timeout = 240;
const unsigned short game_state_danger_timeout = 120;
// const unsigned short game_state_warp_timeout_first = 12;
// const unsigned short game_state_warp_timeout = 24;
// const unsigned short game_state_danger_timeout = 12;

const unsigned char asteroids_difficulty_base = 3;
const unsigned char asteroids_difficulty_multiplier = 2;

unsigned char pickup_spawn_timer = 0;
unsigned char pickup_spawn_timer_min = 120;

unsigned long high_score = 5000;
unsigned char bonus_score_multiplier = 10;
unsigned long player_score = 0;
unsigned long player_score_last;
unsigned char high_score_passed = 0;
unsigned char player_score_timer = 0;
unsigned char player_score_timer_frequency = 100;

unsigned char button_a;
unsigned char button_a_last;

void setup_area()
{
	x_h_min = (unsigned short)(x_min * x_divisor);
	x_h_max = (unsigned short)(x_max * x_divisor);
}

void test_loop()
{
	clear_bgcolor(0);

	clear_sprites();

	// Setup title sprites
	unsigned char title_sprite = 0;
	unsigned short title_x = 115;
	signed short title_y = 100;
	unsigned char si = 0;
	for (unsigned char y = 0; y < 1; y++)
	{
		for (unsigned char x = 0; x < 4; x++)
		{
			enable_sprite(title_sprite, 0, 1);
			spr_index[title_sprite] = 8;
			set_sprite_position(title_sprite, title_x + (x * 18), title_y + (y * 18));
			si++;
			title_sprite++;
		}
	}

	set_sprite_position(0, 64, 160);
	set_sprite_position(1, 77, 164);
	set_sprite_position(2, 90, 168);

	set_sprite_position(3, 200, 100);

	// set_sprite_position(2, 164, 164);
	// set_sprite_position(3, 179, 167);

	update_sprites();

	while (1)
	{
		vblank = input0 & 0x10;

		if (VBLANK_RISING)
		{
			//  for (unsigned char sprite = 0; sprite < sprite_max; sprite++)
			//  {
			//  	write_char(spritecollisionram[sprite] ? 'O' : '.', 0xFF, sprite + 1, 5);
			//  	spr_y_l[sprite]++;
			//  	spritecollisionram[sprite] = 0;
			//  }

			for (unsigned char sprite = 0; sprite < sprite_max; sprite++)
			{
				write_char(spritecollisionram[sprite] ? 'O' : '.', 0xFF, sprite, 3);
			}
			for (unsigned char sprite = 0; sprite < 2; sprite++)
			{
				if (spritecollisionram[sprite] > 0)
				{
					system_pause[0] = 1;
					update_sprites();
				}
				spritecollisionram[sprite] = 0;
			}
		}

		if (VBLANK_FALLING)
		{
		}

		vblank_last = vblank;
	}
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
			set_sprite_position(title_sprite, title_x + (x * 16), -32 + (y * 16));
			si++;
			title_sprite++;
		}
	}

	unsigned char show_instruction = 0;
	unsigned char title_ready = 0;

	while (1)
	{
		vblank = input0 & 0x10;

		if (VBLANK_RISING)
		{

			button_a_last = button_a;
			button_a = CHECK_BIT(joystick[0], 4);
			// If button pressed, leave intro and start game
			if (button_a && !button_a_last)
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

	game_state = game_start;

	while (1)
	{
		vblank = input0 & 0x10;

		if (VBLANK_RISING)
		{
			// timer[0] = 1;

			// Detect player collision
			if (spritecollisionram[player_sprite])
			{
				if (spritecollisionram[pickup_sprite_first])
				{
					// Player collects pickup
					if (pickup_state[0] == 1)
					{
						enable_sprite(pickup_sprite_first, pickup_sprite_palette, 0);
						player_score += pickup_value[0];
						pickup_state[0] = 2;
						pickup_timer[0] = 40;
						spr_index[pickup_sprite_first] += pickup_type_count;
					}
				}
				else
				{
					for (unsigned char a = 0; a < asteroids_max; a++)
					{
						if (spritecollisionram[asteroids_sprite_first + a])
						{
							player_hit = true;
							break;
						}
					}
				}
			}
			for (unsigned char sprite = 0; sprite < sprite_max; sprite++)
			{
				spritecollisionram[sprite] = 0;
			}

			// Update sprite registers
			update_sprites();

			// 
			button_a_last = button_a;
			button_a = CHECK_BIT(joystick[0], 4);

			// Update starfield
			scroll_speed = player_speed;
			if (scroll_speed != scroll_speed_last)
			{
				scroll_speed_last = scroll_speed;
				unsigned char s = scroll_speed >> 2;
				starfield[0] = s;
				starfield[2] = s >> 1;
				starfield[4] = s >> 1;
			}
		}

		if (VBLANK_FALLING)
		{
			if (player_lives > 0)
			{
				handle_player(level_playercontrol);
			}
			handle_trails();
			handle_explosions();
			handle_asteroids(game_state == in_field);
			handle_pickups();

			if (game_state == in_field || game_state == field_ending)
			{
				level_time_timer++;
				if (level_time_timer >= 60)
				{
					level_time++;
					level_time_timer = 0;
				}
			}

			// Game state machine
			switch (game_state)
			{
			case game_start:

				// Reset progress
				level_number = 0;
				level_progress = 0;
				level_playercontrol = 0;

				// Reset player
				player_lives = 3;
				player_lives_changed = true;

				setup_player(player_spawn_x, 260);
				player_speed = player_speed_warp; // Preset player to warp speed!

				// Reset scores and stats
				player_score = 0;
				player_score_last = 999;
				player_score_timer = 0;
				high_score_passed = 0;
				asteroids_passed = 0;

				// Setup asteroids
				setup_asteroids();

				// Setup explosions
				setup_explosions();

				// Setup pickups
				setup_pickups();
				pickup_spawn_timer = pickup_spawn_timer_min;

				// Draw score titles
				write_string("1UP", 0b00111111, 2, 0);
				write_string("HIGH SCORE", 0b00111111, 15, 0);
				write_string("SHIPS", 0b00111111, 35, 0);
				write_stringf("%2d", 0xFF, 38, 1, player_lives);

				// Draw instructions for first warp

				write_string("Avoid the asteroids!", 0b00111111, 10, 11);
				write_string("Use A to boost for time bonus", 0b00111000, 5, 14);
				write_string("Collect gems for extra points", 0b00011111, 5, 17);

				game_state = in_warp;
				game_state_timer = game_state_warp_timeout_first;

				break;
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
				asteroids_difficulty = asteroids_difficulty_base + (level_number * asteroids_difficulty_multiplier);
				asteroids_difficulty_speedspread = 2 + (asteroids_difficulty / 4);

				asteroids_active_max = asteroids_max;
				// asteroids_active_max = 5 + asteroids_difficulty;
				if (asteroids_active_max > asteroids_max)
				{
					asteroids_active_max = asteroids_max;
				}

				// Write 0% progress indicator
				write_stringf("%3d%%", 0xFF, 18, 29, 0);

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

				// Generate pickups
				pickup_spawn_timer--;
				if (pickup_spawn_timer == 0)
				{
					pickup_spawn_timer = pickup_spawn_timer_min;
					spawn_pickup();
				}

				// Player score
				player_score_timer += player_speed;
				if (player_score_timer >= player_score_timer_frequency)
				{
					player_score_timer -= player_score_timer_frequency;
					player_score++;
				}

				if (player_lives_changed)
				{
					write_stringf("%2d", 0xFF, 38, 1, player_lives);
					player_lives_changed = false;
					if (player_lives == 0)
					{
						game_state = game_over;
					}
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

					write_stringf_ushort("-- FIELD %d COMPLETED --", 0xFF, 9, 11, level_number);

					unsigned short par_time = level_progress_max / 60 / (player_speed_min + (player_speed_min / 2));
					unsigned short bonus = 0;
					if (level_time < par_time)
					{
						bonus = (par_time - level_time) * bonus_score_multiplier;
					}
					player_score += bonus;

					write_stringf_ushort("Time: %6d", 0xFF, 14, 13, level_time);
					write_stringf_ushort("Par: %6d", 0xFF, 15, 14, par_time);
					if (bonus > 0)
					{
						write_stringf_ushort("Bonus: %6d", 0b00011000, 13, 16, bonus);
					}
					else
					{
						write_string("No bonus :(", 0b01011011, 14, 16);
					}
					write_stringf_ulong("Score: %6d", 0xFF, 13, 18, player_score);
					clear_char_area(0, 10, 29, 30, 29);
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
				if (game_state_timer == 0)
				{
					clear_char_area(0, 0, 2, 39, 20);
					write_string("- Entering asteroid field -", 0xFF, 07, 16);
					game_state = approaching_field;
					game_state_timer = game_state_danger_timeout;
					level_time = 0;
				}
				break;
			case approaching_field: // Slow down again ready for start
				move_player_to_target();
				if (player_speed > player_speed_min)
				{
					player_speed--;
				}

				level_time_timer++;
				if (level_time_timer >= 15)
				{
					write_string("DANGER!", level_time ? 0b00000111 : 0b00111111, 16, 14);
					level_time = !level_time;
					level_time_timer = 0;
				}

				game_state_timer--;
				if (game_state_timer == 0)
				{
					clear_char_area(0, 0, 14, 39, 16);
					game_state = enter_field;
					setup_asteroids();
				}
				break;
			case game_over:
				write_string("GAME OVER", 0b00000011, 16, 14);
				game_state_timer = 120;
				game_state = game_over_waitforstats;
				break;
			case game_over_waitforstats:
				game_state_timer--;
				if (game_state_timer == 0)
				{
					clear_char_area(0, 0, 14, 39, 14);

					// Write stats
					write_stringf_ulong("Final Score: %6d", 0xFF, 10, 14, player_score);
					write_stringf_ulong("Asteroids passed: %6d", 0xFF, 5, 15, asteroids_passed);

					write_string("Press A to continue", 0xFF, 10, 17);

					game_state = game_over_waitforscoreentry;
				}
				break;
			case game_over_waitforscoreentry:
				if (button_a && !button_a_last)
				{
					return;
				}
				break;
			}

			// Only update scores if they have changed
			if (player_score != player_score_last)
			{
				// Update high score
				if (player_score > high_score)
				{
					high_score = player_score;
				}

				// Draw player score
				write_stringf_ulong("%d", 0xFF, 0, 1, player_score);

				// Draw highscore
				write_stringf_ulong("%6d", 0xFF, 16, 1, high_score);

				player_score_last = player_score;
			}
		}

		vblank_last = vblank;
	}
}

void app_zorblaxx()
{
	while (1)
	{
		clear_chars(0);
		setup_area();
		setup_player(player_spawn_x, 256);
		set_player_target(player_spawn_x * x_divisor, player_spawn_y * y_divisor, 6, 24);
		setup_trails();

		//test_loop();

		intro_loop();

		// Clear character map and title sprites
		clear_chars(0);
		clear_sprites_range(16, 32);

		game_loop();
	}
}