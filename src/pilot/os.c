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

// Constants
#define direction_count 16
#define screen_center_x 176
#define screen_center_y 144
#define scale (unsigned short)128
#define scale_half 64

// Sprite indexes
#define const_particle_sprite_first 1
#define const_projectile_sprite_first 13
#define player_sprite 0

unsigned short screen_center_scaled_x = ((screen_center_x - sprite_halfpixelsize_trails) * scale);
unsigned short screen_center_scaled_y = ((screen_center_y - sprite_halfpixelsize_trails) * scale);

signed short player_v_x;
signed short player_v_y;
#define player_v_friction 90

unsigned char player_a_acc;
unsigned char player_a;
signed char player_turn_timer;
signed char player_turn_timer_max = 4;
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

#define const_particle_max 12
#define particle_timer_max 4
bool particle_on[const_particle_max];
unsigned char particle_timer[const_particle_max];
unsigned short particle_x[const_particle_max];
unsigned short particle_y[const_particle_max];
signed short particle_v_x[const_particle_max];
signed short particle_v_y[const_particle_max];

#define const_projectile_max 8
#define projectile_timer_max 40
bool projectile_on[const_projectile_max];
unsigned char projectile_timer[const_projectile_max];
unsigned short projectile_x[const_projectile_max];
unsigned short projectile_y[const_projectile_max];
signed short projectile_v_x[const_projectile_max];
signed short projectile_v_y[const_projectile_max];

unsigned short test_x;
unsigned short test_y;

void kill_projectile(unsigned char p)
{
	spr_on[const_projectile_sprite_first + p] = 0;
	projectile_on[p] = 0;
}

// Main entry
void main()
{
	// Initialise char map
	chram_size = chram_cols * chram_rows;
	clear_bgcolor(0);

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
	for (unsigned char p = 0; p < const_particle_max; p++)
	{
		unsigned char s = p + const_particle_sprite_first;
		enable_sprite(s, sprite_palette_trails, sprite_size_trails, 0);
		spr_on[s] = 0;
	}
	// Init projectiles
	for (unsigned char p = 0; p < const_projectile_max; p++)
	{
		unsigned char s = p + const_projectile_sprite_first;
		enable_sprite(s, sprite_palette_shots, sprite_size_shots, 1);
		spr_on[s] = 0;
	}

	enable_sprite(31, sprite_palette_player, sprite_size_player, 1);
	spr_index[31] = sprite_index_player_first;
	test_x = (screen_center_x - sprite_halfpixelsize_player + 64) * scale;
	test_y = (screen_center_y - sprite_halfpixelsize_player + 64) * scale;

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

			unsigned short t = GET_TIMER;

			// if (input_left)
			// 	player_turn_timer--;
			// if (input_right)
			// 	player_turn_timer++;

			// if (player_turn_timer < -player_turn_timer_max)
			// {
			// 	player_turn_timer = 0;
			// 	if (player_a == 0)
			// 		player_a = 15;
			// 	else
			// 		player_a--;
			// }
			// if (player_turn_timer > player_turn_timer_max)
			// {
			// 	player_turn_timer = 0;
			// 	if (player_a == 15)
			// 		player_a = 0;
			// 	else
			// 		player_a++;
			// }

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

			// write_stringf("target: %3d", 0xFF, 5, 5, target_a_acc);
			// write_stringf("player: %3d", 0xFF, 5, 6, player_a_acc);
			if (target_a_acc != player_a_acc)
			{
				unsigned char diff = target_a_acc - player_a_acc;
				// write_stringf("diff: %3d", 0xFF, 5, 7, diff);
				if (diff > 127)
				{
					diff = 255 - (diff - 1);
					if (diff > 4)
					{
						diff = 4;
					}
					// write_stringf("mdiff: %3d", 0xFF, 5, 8, diff);
					player_a_acc -= diff;
				}
				else
				{
					if (diff > 4)
					{
						diff = 4;
					}
					// write_stringf("mdiff: %3d", 0xFF, 5, 8, diff);
					player_a_acc += diff;
				}
			}

			player_a = player_a_acc / 16;
			// write_stringf("player_a: %3d", 0xFF, 5, 9, player_a);
			//  Set player sprite index
			spr_index[player_sprite] = sprite_index_player_first + player_a;

			player_v_x += player_thrust_x[player_a];
			player_v_y += player_thrust_y[player_a];


			player_v_x += player_thrust_x[player_a];
			player_v_y += player_thrust_y[player_a];

			signed short player_thrust = player_thrust_mag;

			// This is tragically bad
			player_v_x = (signed short)(((signed long)player_v_x * player_v_friction) / 100);
			player_v_y = (signed short)(((signed long)player_v_y * player_v_friction) / 100);

			// if (input_up)
			// {
			// 	player_v_x += player_thrust_x[player_a];
			// 	player_v_y += player_thrust_y[player_a];
			// 	player_thrust = player_thrust_mag;
			// }
			// else if (input_down)
			// {
			// 	player_v_x += player_thrust_rev_x[player_a];
			// 	player_v_y += player_thrust_rev_y[player_a];
			// 	player_thrust = player_thrust_rev_mag;
			// }

			
			// player_thrust = player_thrust_mag;

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
							projectile_v_x[p] = player_v_x + (vector_x[player_a] * player_shot_speed);
							projectile_v_y[p] = player_v_y + (vector_y[player_a] * player_shot_speed);
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

			float player_speed = sqrtf((player_v_x * player_v_x) + (player_v_y * player_v_y));
			unsigned char player_speed_int = (unsigned char)player_speed;

			set_starfield_speed_x(player_v_x >> 2);
			set_starfield_speed_y(player_v_y >> 2);

			// Generate player trail
			if (player_trail_timer == 0)
			{
				if (player_thrust != 0)
				{
					player_trail_timer = player_trail_freq;

					for (unsigned char pt = 0; pt < const_particle_max; pt++)
					{
						if (!particle_on[pt])
						{
							particle_on[pt] = true;
							particle_x[pt] = screen_center_scaled_x + player_trail_offset_x[player_a];
							particle_y[pt] = screen_center_scaled_y + player_trail_offset_y[player_a];
							// particle_v_x[pt] = (vector_x[player_a] * -player_thrust) >> 8;
							// particle_v_y[pt] = (vector_y[player_a] * -player_thrust) >> 8;
							particle_timer[pt] = particle_timer_max;
							unsigned char ps = const_particle_sprite_first + pt;
							spr_on[ps] = 1;
							spr_index[ps] = sprite_index_trails_first;
							break;
						}
					}
				}
			}
			else
			{
				player_trail_timer--;
			}

			// Particles
			for (unsigned char p = 0; p < const_particle_max; p++)
			{
				if (particle_on[p])
				{
					unsigned char s = const_particle_sprite_first + p;
					particle_timer[p]--;
					if (particle_timer[p] == 0)
					{
						if (spr_index[s] == sprite_index_trails_last)
						{
							spr_on[s] = 0;
							particle_on[p] = 0;
							continue;
						}
						else
						{
							particle_timer[p] = particle_timer_max;
							spr_index[s]++;
						}
					}
					set_sprite_position(s, particle_x[p] / scale, particle_y[p] / scale);
					particle_x[p] -= player_v_x;
					particle_y[p] -= player_v_y;
					particle_x[p] += particle_v_x[p];
					particle_y[p] += particle_v_y[p];
				}
			}

			// Projectiles
			for (unsigned char p = 0; p < const_projectile_max; p++)
			{
				if (projectile_on[p])
				{
					projectile_timer[p]--;
					if (projectile_timer[p] == 0)
					{
						kill_projectile(p);
						continue;
					}
					set_sprite_position(const_projectile_sprite_first + p, projectile_x[p] / scale, projectile_y[p] / scale);
					projectile_x[p] -= player_v_x;
					projectile_y[p] -= player_v_y;
					projectile_x[p] += projectile_v_x[p];
					projectile_y[p] += projectile_v_y[p];
				}
			}

			test_x -= player_v_x;
			test_y -= player_v_y;

			set_sprite_position(31, test_x / scale, test_y / scale);

			if (spritecollisionram[31])
			{
				// Find what was colliding?
				for (unsigned char p = 0; p < const_projectile_max; p++)
				{
					if (spritecollisionram[const_projectile_sprite_first + p])
					{
						write_char('P', 0xFF, 0, p + 1);
						kill_projectile(p);
						spritecollisionram[const_projectile_sprite_first + p] = 0;
					}
				}
				spritecollisionram[31] = 0;
			}

			unsigned short l = (GET_TIMER)-t;
			write_stringf_ushort("%6d", 0xFF, 0, 0, l);
		}
		vblank_last = vblank;
	}
}