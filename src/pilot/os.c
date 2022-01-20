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

// Sprite indexes
#define const_particle_sprite_first 0
#define player_sprite 16

signed short player_xs;
signed short player_ys;

#define screen_center_x 176
#define screen_center_y 144

float player_v_x;
float player_v_y;
#define player_v_friction 0.97f

unsigned char player_a;
signed char player_turn_timer;
signed char player_turn_timer_max = 4;
#define player_thrust_mag 0.05f
#define player_thrust_rev_mag -0.025f
float player_thrust_x[direction_count];
float player_thrust_y[direction_count];
float player_thrust_rev_x[direction_count];
float player_thrust_rev_y[direction_count];
float player_trail_offset_x[direction_count];
float player_trail_offset_y[direction_count];

#define player_trail_timer_max 32
unsigned char player_trail_timer = player_trail_timer_max;
#define particle_timer_max 4

unsigned char sf_dir_x_last;
unsigned char sf_dir_y_last;

signed char vector_x[direction_count] = {0, 49, 90, 117, 127, 117, 90, 49, 0, -49, -90, -117, -127, -117, -90, -49};
signed char vector_y[direction_count] = {-127, -117, -90, -49, 0, 49, 90, 117, 127, 117, 90, 49, 0, -49, -90, -117};

#define v_divider 127.0f
float v_x[direction_count];
float v_y[direction_count];

#define const_particle_max 16
float v_y[direction_count];
bool particle_on[const_particle_max];
unsigned char particle_timer[const_particle_max];
float particle_x[const_particle_max];
float particle_y[const_particle_max];
float particle_v_x[const_particle_max];
float particle_v_y[const_particle_max];

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
		// Generate unit vector
		v_x[v] = ((float)vector_x[v]) / v_divider;
		v_y[v] = ((float)vector_y[v]) / v_divider;

		// Player thrust vectors
		player_thrust_x[v] = (v_x[v]) * player_thrust_mag;
		player_thrust_y[v] = (v_y[v]) * player_thrust_mag;
		player_thrust_rev_x[v] = (v_x[v]) * player_thrust_rev_mag;
		player_thrust_rev_y[v] = (v_y[v]) * player_thrust_rev_mag;
		// Player trail start offset vectors
		player_trail_offset_x[v] = (v_x[v]) * -7;
		player_trail_offset_y[v] = (v_y[v]) * -7;
	}
	clear_char_area(0, 0, 0, 40, 0);

	// Enable player sprite
	enable_sprite(player_sprite, sprite_palette_player, sprite_size_player, 0);
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

			if (input_left)
				player_turn_timer--;
			if (input_right)
				player_turn_timer++;

			if (player_turn_timer < -player_turn_timer_max)
			{
				player_turn_timer = 0;
				if (player_a == 0)
					player_a = 15;
				else
					player_a--;
			}
			if (player_turn_timer > player_turn_timer_max)
			{
				player_turn_timer = 0;
				if (player_a == 15)
					player_a = 0;
				else
					player_a++;
			}

			player_v_x *= player_v_friction;
			player_v_y *= player_v_friction;
			signed char player_thrust = 0;
			if (input_up)
			{
				player_v_x += player_thrust_x[player_a];
				player_v_y += player_thrust_y[player_a];
				player_thrust = player_thrust_mag * 24;
				player_trail_timer += player_thrust;
			}
			else if (input_down)
			{
				player_v_x += player_thrust_rev_x[player_a];
				player_v_y += player_thrust_rev_y[player_a];
				player_thrust = player_thrust_rev_mag * 24;
				player_trail_timer -= player_thrust;
			}

			float player_speed = sqrtf((player_v_x * player_v_x) + (player_v_y * player_v_y));
			unsigned char player_speed_int = (unsigned char)player_speed;

			set_starfield_speed_x(player_v_x);
			set_starfield_speed_y(player_v_y);

			// Set player sprite index
			spr_index[player_sprite] = sprite_index_player_first + player_a;

			if (player_trail_timer >= 4)
			{
				player_trail_timer -= 4;

				for (unsigned char p = 0; p < const_particle_max; p++)
				{
					if (!particle_on[p])
					{
						particle_on[p] = true;
						particle_x[p] = (screen_center_x - sprite_halfpixelsize_trails) + player_trail_offset_x[player_a];
						particle_y[p] = (screen_center_y - sprite_halfpixelsize_trails) + player_trail_offset_y[player_a];
						particle_v_x[p] = v_x[player_a] * -player_thrust;
						particle_v_y[p] = v_y[player_a] * -player_thrust;
						particle_timer[p] = particle_timer_max;
						unsigned char s = const_particle_sprite_first + p;
						spr_on[s] = 1;
						spr_index[s] = const_particle_sprite_first;
						break;
					}
				}
			}

			for (unsigned char p = 0; p < const_particle_max; p++)
			{
				if (particle_on[p])
				{
					unsigned char s = const_particle_sprite_first + p;
					particle_x[p] -= player_v_x;
					particle_y[p] -= player_v_y;
					particle_x[p] += particle_v_x[p];
					particle_y[p] += particle_v_y[p];
					set_sprite_position(s, (unsigned short)particle_x[p], (unsigned short)particle_y[p]);
					particle_timer[p]--;
					if (particle_timer[p] == 0)
					{
						if (spr_index[s] == const_particle_sprite_first + 3)
						{
							spr_on[s] = 0;
							particle_on[p] = 0;
						}
						else
						{
							particle_timer[p] = particle_timer_max;
							spr_index[s]++;
						}
					}
				}
			}
		}
		vblank_last = vblank;
	}
}