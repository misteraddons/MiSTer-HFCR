/*============================================================================
	Aznable OS - 'Pilot' demo

	Author: Jim Gregory - https://github.com/JimmyStones/
	Version: 1.0
	Date: 2022-01-13

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
#include "../shared/sys.h"
#include "../shared/ui.h"
#include "../shared/sprite.h"
#include "../shared/sound.h"
#include "../shared/tilemap.h"
#include "../shared/starfield.h"
#include "pilot.h"
#include "particles.h"
#include "projectiles.h"
#include "sprite_images.h"
#include "sound_samples.h"
#include <stdio.h>
#include <math.h>

// DPAD tracker
bool input_left = 0;
bool input_left_last = 0;
bool input_right = 0;
bool input_right_last = 0;
bool input_up = 0;
bool input_up_last = 0;
bool input_down = 0;
bool input_down_last = 0;
bool input_a;
bool input_a_last = 0;

// Track joypad 1 directions and start for menu control
void basic_input()
{
	input_up_last = input_up;
	input_down_last = input_down;
	input_left_last = input_left;
	input_right_last = input_right;
	input_a_last = input_a;
	input_up = CHECK_BIT(joystick[0], 3);
	input_down = CHECK_BIT(joystick[0], 2);
	input_left = CHECK_BIT(joystick[0], 1);
	input_right = CHECK_BIT(joystick[0], 0);
	input_a = CHECK_BIT(joystick[0], 4);
}

unsigned short screen_center_scaled_x = ((screen_center_x - sprite_halfpixelsize_trails) * scale);
unsigned short screen_center_scaled_y = ((screen_center_y - sprite_halfpixelsize_trails) * scale);

signed short scroll_v_x;
signed short scroll_v_y;
#define player_v_friction 90

unsigned char player_a_acc;
unsigned char player_a;
#define player_turn_speed_max 4
#define player_thrust_mag 20
#define player_thrust_rev_mag -10
signed short player_thrust_x[direction_count];
signed short player_thrust_y[direction_count];
signed short player_thrust_rev_x[direction_count];
signed short player_thrust_rev_y[direction_count];
signed short player_trail_offset_x[direction_count];
signed short player_trail_offset_y[direction_count];
signed short player_shot_offset_x[direction_count];
signed short player_shot_offset_y[direction_count];

unsigned char player_trail_timer;
unsigned char player_trail_freq = 4;

#define player_shot_timer_max 6
unsigned char player_shot_timer;
#define player_shot_speed 6

unsigned char sf_dir_x_last;
unsigned char sf_dir_y_last;

signed char vector_x[direction_count] = {0, 49, 90, 117, 127, 117, 90, 49, 0, -49, -90, -117, -127, -117, -90, -49};
signed char vector_y[direction_count] = {-127, -117, -90, -49, 0, 49, 90, 117, 127, 117, 90, 49, 0, -49, -90, -117};

#define bounds_x_min 2000
#define bounds_x_max 46000
#define bounds_y_min 2000
#define bounds_y_max 33000

#define const_enemy_max 3
bool enemy_on[const_enemy_max];
unsigned short enemy_x[const_enemy_max];
unsigned short enemy_y[const_enemy_max];

// #define DISABLE_PARTICLES
// #define DISABLE_PROJECTILES

// Main entry
void main()
{
	// Initialise char map
	chram_size = chram_cols * chram_rows;
	clear_bgcolor(transparent_char);

	write_string("CALCULATING VECTORS", 0xFF, 0, 0);

	// Generate float vectors for various angles
	for (unsigned char v = 0; v < direction_count; v++)
	{
		// Player thrust vectors
		player_thrust_x[v] = (vector_x[v] * player_thrust_mag) / 100;
		player_thrust_y[v] = (vector_y[v] * player_thrust_mag) / 100;
		player_thrust_rev_x[v] = (vector_x[v] * player_thrust_rev_mag) / 100;
		player_thrust_rev_y[v] = (vector_y[v] * player_thrust_rev_mag) / 100;

		// Player trail start offset vectors
		player_trail_offset_x[v] = (vector_x[v]) * -8;
		player_trail_offset_y[v] = (vector_y[v]) * -8;

		// Player shot start offset vectors
		player_shot_offset_x[v] = (vector_x[v]) * 11;
		player_shot_offset_y[v] = (vector_y[v]) * 11;
	}
	clear_char_area(0, 0, 0, 40, 0);

	// Enable player sprite
	enable_sprite(player_sprite, sprite_palette_player, sprite_size_player, 1);
	// Set player start position
	set_sprite_position(player_sprite, screen_center_x - sprite_halfpixelsize_player, screen_center_y - sprite_halfpixelsize_player);

	// Init starfields
	enable_starfield();

	// Init particles
	init_particles();
	// Init projectiles
	init_projectiles();

	unsigned char enemy_wanted_count = const_enemy_max;
	unsigned char enemy_active_count = 0;
	for (unsigned char e = 0; e < const_enemy_max; e++)
	{
		unsigned char s = const_enemy_sprite_first + e;
		enable_sprite(s, sprite_palette_enemy, sprite_size_enemy, true);
		spr_index[s] = sprite_index_enemy_first;
		spr_on[s] = 0;
	}

	// Draw score area
	write_bgcol_row(0b00000000, 1, 29, 40);
	write_string("Score might be here, or some other stuff", 0xFF, 0, 29);

	while (1)
	{
		vblank = CHECK_BIT(input0, INPUT_VBLANK);

		if (VBLANK_RISING)
		{
			update_sprites();
		}
		if (VBLANK_FALLING)
		{
			basic_input();

			// Reset hw timer
			timer[0] = 0;

			unsigned char target_a_acc = player_a_acc;
			if (input_left)
			{
				if (input_up)
				{
					target_a_acc = 231;
				}
				else if (input_down)
				{
					target_a_acc = 167;
				}
				else
				{
					target_a_acc = 200;
				}
			}
			else if (input_right)
			{
				if (input_up)
				{
					target_a_acc = 40;
				}
				else if (input_down)
				{
					target_a_acc = 104;
				}
				else
				{
					target_a_acc = 72;
				}
			}
			else
			{
				if (input_up)
				{
					target_a_acc = 8;
				}
				else if (input_down)
				{
					target_a_acc = 136;
				}
			}

			if (target_a_acc != player_a_acc)
			{
				unsigned char diff = target_a_acc - player_a_acc;
				if (diff > 127)
				{
					diff = 255 - (diff - 1);
					if (diff > player_turn_speed_max)
					{
						diff = player_turn_speed_max;
					}
					player_a_acc -= diff;
				}
				else
				{
					if (diff > player_turn_speed_max)
					{
						diff = player_turn_speed_max;
					}
					player_a_acc += diff;
				}
			}

			player_a = player_a_acc >> 4;

			//  Set player sprite index
			spr_index[player_sprite] = sprite_index_player_first + player_a;

			scroll_v_x += player_thrust_x[player_a];
			scroll_v_y += player_thrust_y[player_a];

			bool player_thrust = true;

			// This is tragically bad
			scroll_v_x = (signed short)(((signed long)scroll_v_x * player_v_friction) / 100);
			scroll_v_y = (signed short)(((signed long)scroll_v_y * player_v_friction) / 100);

			if (player_shot_timer > 0)
			{
				player_shot_timer--;
			}
			else
			{
				if (input_a)
				{
					for (unsigned char p = 0; p < const_projectile_max; p++)
					{
						if (!projectile_on[p])
						{
							projectile_on[p] = true;
							projectile_x[p] = (screen_center_scaled_x + player_shot_offset_x[player_a]) + scale_half;
							projectile_y[p] = (screen_center_scaled_y + player_shot_offset_y[player_a]) + scale_half;
							projectile_v_x[p] = scroll_v_x + (vector_x[player_a] * player_shot_speed);
							projectile_v_y[p] = scroll_v_y + (vector_y[player_a] * player_shot_speed);
							projectile_timer[p] = projectile_timer_max;
							unsigned char s = const_projectile_sprite_first + p;
							spr_on[s] = 1;
							spr_index[s] = sprite_index_shots_first + player_a;
							break;
						}
					}
					player_shot_timer = player_shot_timer_max;
				}
			}

			set_starfield_speed_x(scroll_v_x >> 2);
			set_starfield_speed_y(scroll_v_y >> 2);

#ifndef DISABLE_PARTICLES

			// Generate player trail
			if (player_trail_timer == 0)
			{
				player_trail_timer = player_trail_freq;
				spawn_particle(screen_center_scaled_x + player_trail_offset_x[player_a], screen_center_scaled_y + player_trail_offset_y[player_a]);
			}
			else
			{
				player_trail_timer--;
			}

			// Particles
			handle_particles();

#endif

#ifndef DISABLE_PROJECTILES
			// Projectiles
			handle_projectiles();
#endif

			// Enemies
			//  Spawn
			if (enemy_active_count < enemy_wanted_count)
			{
				for (unsigned char e = 0; e < const_enemy_max; e++)
				{
					if (!enemy_on[e])
					{
						// Random entry location...
						unsigned char side = rand_uchar(0, 3);
						write_stringf("%d", 0xFF, 5, 3 + e, side);
						switch (side)
						{
						case 0:
							// Top spawn
							enemy_y[e] = bounds_y_min + scale;
							enemy_x[e] = rand_ushort(bounds_x_min + scale, bounds_x_max - scale);
							break;
						case 1:
							// Right spawn
							enemy_y[e] = rand_ushort(bounds_y_min + scale, bounds_y_max - scale);
							enemy_x[e] = bounds_x_max - scale;
							break;
						case 2:
							// Bottom spawn
							enemy_y[e] = bounds_y_max - scale;
							enemy_x[e] = rand_ushort(bounds_x_min + scale, bounds_x_max - scale);
							break;
						case 4:
							// Left spawn
							enemy_y[e] = rand_ushort(bounds_y_min + scale, bounds_y_max - scale);
							enemy_x[e] = bounds_x_min + scale;
							break;
						}

						enemy_on[e] = true;
						enemy_active_count++;

						unsigned char s = const_enemy_sprite_first + e;
						spr_on[s] = true;
						set_sprite_position(s, enemy_x[e] / scale, enemy_y[e] / scale);

						break;
					}
				}
			}

			for (unsigned char e = 0; e < const_enemy_max; e++)
			{
				unsigned char s = const_enemy_sprite_first + e;
				enemy_x[e] = (enemy_x[e] - scroll_v_x);
				enemy_y[e] = (enemy_y[e] - scroll_v_y);
				set_sprite_position(s, enemy_x[e] / scale, enemy_y[e] / scale);
				// bool on = true;
				// if (test_y > bounds_y_max || test_y < bounds_y_min || test_x > bounds_x_max || test_x < bounds_x_min)
				// {
				// 	on = false;
				// }
				if (spritecollisionram[s])
				{
					// 	// Find what was colliding?
					// 	for (unsigned char p = 0; p < const_projectile_max; p++)
					// 	{
					// 		if (spritecollisionram[const_projectile_sprite_first + p])
					// 		{
					// 			write_char('P', 0xFF, 0, p + 1);
					// 			kill_projectile(p);
					// 			spritecollisionram[const_projectile_sprite_first + p] = 0;
					// 		}
					// 	}
					// 	spritecollisionram[31] = 0;
				}
			}

			unsigned short l = (GET_TIMER);
			write_stringf_ushort("%6d", 0xFF, 0, 0, l);
		}
		vblank_last = vblank;
	}
}