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
#include "../shared/ps2.h"
#include "sprite_images.h"
#include "sound_samples.h"

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
unsigned char x_off = 0;
unsigned char y_off = 0;

// Track joypad 1 directions and start for menu control
void basic_input()
{
	input_up_last = input_up;
	input_down_last = input_down;
	input_left_last = input_left;
	input_right_last = input_right;
	input_a_last = input_a;
	input_up = CHECK_BIT(joystick[0], 3) || kbd_down[KEY_UP];
	input_down = CHECK_BIT(joystick[0], 2) || kbd_down[KEY_DOWN];
	input_left = CHECK_BIT(joystick[0], 1) || kbd_down[KEY_LEFT];
	input_right = CHECK_BIT(joystick[0], 0) || kbd_down[KEY_RIGHT];
	input_a = CHECK_BIT(joystick[0], 4) || kbd_down[KEY_ENTER];
}

// void update_section(unsigned char lx, unsigned char rx, unsigned char ty, unsigned char by)
// {
// 	for (unsigned char y = ty; y <= by; y++)
// 	{
// 		for (unsigned char x = lx; x <= rx; x++)
// 		{
// 			unsigned short p = ((y)*32) + (x);
// 			tilemapram[p] = tilemap_index[y + y_off - 1][x + x_off - 1];
// 		}
// 	}
// }

unsigned short player_x;
unsigned short player_y;
signed short player_xs;
signed short player_ys;
unsigned char player_a;

signed char player_turn_timer;
signed char player_turn_timer_max = 4;

#define player_sprite 0

unsigned char scale = 16;
unsigned char vscale = 4;
unsigned char sf_scale = 32;

signed char vector_x[16] = {0, 6, 11, 15, 16, 15, 11, 6, 0, -6, -11, -15, -16, -15, -11, -6};
signed char vector_y[16] = {-16, -15, -11, -6, -0, 6, 11, 15, 16, 15, 11, 6, 0, -6, -11, -15};

// Main entry
void main()
{

	chram_size = chram_cols * chram_rows;
	// update_section(0, 22, 0, 16);
	// tilemap_offset_x = 0;
	// tilemap_offset_y = 0;

	// unsigned char scroll_speed = 4;
	// unsigned char x_off_max = const_tilemap_index_x_max - 20;
	// unsigned char y_off_max = const_tilemap_index_y_max - 15;

	enable_sprite(player_sprite, sprite_palette_player, sprite_size_player, 0);
	player_x = 64 * scale;
	player_y = 64 * scale;

	// for (unsigned char s = 1; s < 16; s++)
	// {
	// 	enable_sprite(s, sprite_palette_player, sprite_size_player, 0);
	// 	set_sprite_position(s, 16 + (s * 16), 32);
	// }

	clear_bgcolor(0);

	// Init starfields
	starfield1[0] = 1;
	starfield2[0] = 1;
	starfield3[0] = 1;

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
			if (input_up)
			{
				player_xs += vector_x[player_a];
				player_ys += vector_y[player_a];
			}
			else
			{
				if (player_xs > 0)
				{
					player_xs--;
				}
				else if (player_xs < 0)
				{
					player_xs++;
				}
				if (player_ys > 0)
				{
					player_ys--;
				}
				else if (player_ys < 0)
				{
					player_ys++;
				}
			}

			unsigned char sf_dir_x = (player_xs < 0);
			unsigned char sf_dir_y = (player_ys < 0);
			unsigned char sf_spd_x = (abs(player_xs / sf_scale));
			unsigned char sf_spd_y = (abs(player_ys / sf_scale));

			starfield3[1] = sf_dir_x;
			starfield3[2] = sf_spd_x;
			starfield3[3] = sf_dir_y;
			starfield3[4] = sf_spd_y;
			sf_spd_x = sf_spd_x << 1;
			sf_spd_y = sf_spd_y << 1;
			starfield2[1] = sf_dir_x;
			starfield2[2] = sf_spd_x;
			starfield2[3] = sf_dir_y;
			starfield2[4] = sf_spd_y;
			sf_spd_x = sf_spd_x << 1;
			sf_spd_y = sf_spd_y << 1;
			starfield1[1] = sf_dir_x;
			starfield1[2] = sf_spd_x;
			starfield1[3] = sf_dir_y;
			starfield1[4] = sf_spd_y;

			player_x = 176 * scale;
			player_y = 144 * scale;
			// player_x += player_xs / vscale;
			// player_y += player_ys / vscale;

			spr_index[player_sprite] = sprite_index_player_first + player_a;
			unsigned short x = player_x / scale;
			unsigned short y = player_y / scale;

			set_sprite_position(player_sprite, x, y);
		}
		vblank_last = vblank;
	}
}