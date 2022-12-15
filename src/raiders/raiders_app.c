/*============================================================================
	Aznable OS - Raiders demo

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

#include "../shared/sys.h"
#include "../shared/sprite.h"
#include "../shared/ui.h"
#include "sprite_images.h"
#include "raiders_app.h"
#include "../shared/tilemap.h"
#include "tilemap_indexes.h"

int logo_sprite = 0;
int player_sprite = 1;
unsigned char player_x = 50;
unsigned char player_y = 180;
unsigned char player_moving = 0;

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

signed char x_off = 0;
signed char y_off = -2;

unsigned char scroll_speed = 1;

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

void update_section(unsigned char lx, unsigned char rx, unsigned char ty, unsigned char by)
{
	for (unsigned char y = ty; y <= by; y++)
	{
		unsigned short p = (y * 32) + lx;
		unsigned char yi = (y + y_off - 1);
		for (unsigned char x = lx; x <= rx; x++)
		{
			tilemapram[p] = tilemap_index[yi][x + x_off - 1];
			p++;
		}
	}
}

unsigned char screen_width = 22;

void app_main()
{
	chram_size = chram_cols * chram_rows;
	clear_chars(0);
	clear_sprites();

	enable_sprite(logo_sprite, sprite_palette_logos, sprite_size_logos, 0);
	set_sprite_position(logo_sprite, 30, 32);
	spr_index[logo_sprite] = sprite_index_logos_first;

	enable_sprite(player_sprite, sprite_palette_stroudman, sprite_size_stroudman, 1);
	set_sprite_position(player_sprite, player_x, player_y);
	spr_index[player_sprite] = sprite_index_stroudman_first;
	int t = 0;
	bool d = 1;

	update_section(0, screen_width, 0, const_tilemap_index_y_max - y_off);
	tilemap_offset_x = 0;
	tilemap_offset_y = 0;

	unsigned char player_sprite_index = 0;

	while (1)
	{
		vblank = CHECK_BIT(input0, INPUT_VBLANK);

		if (VBLANK_RISING)
		{

			basic_input();
			// if (input_right)
			// 	tilemap_offset_x += scroll_speed;
			// if (input_left && tilemap_offset_x > 0)
			// 	tilemap_offset_x -= scroll_speed;
			// if (input_up && tilemap_offset_y > 0)
			// 	tilemap_offset_y -= scroll_speed;
			// if (input_down)
			// 	tilemap_offset_y += scroll_speed;

			if (tilemap_offset_x >= 16)
			{
				tilemap_offset_x -= 16;
				scroll_tilemap_left();
				x_off++;
				update_section(21, 21, 0, 16);
			}
			else if (tilemap_offset_x <= -16)
			{
				tilemap_offset_x += 16;
				scroll_tilemap_right();
				x_off--;
				update_section(0, 0, 0, 16);
			}
			else if (tilemap_offset_y >= 16)
			{
				tilemap_offset_y -= 16;
				scroll_tilemap_up();
				y_off++;
				update_section(0, 21, 16, 16);
			}
			else if (tilemap_offset_y <= -16)
			{
				tilemap_offset_y += 16;
				scroll_tilemap_down();
				y_off--;
				update_section(0, 21, 0, 0);
			}

			update_tilemap_offset();

			player_moving = 0;

			if (input_left || input_right)
			{
				player_moving = 1;
				player_x += input_left ? -1 : 1;
			}
			if (input_up || input_down)
			{
				player_moving = 1;
				player_y += input_up ? -1 : 1;
			}

			if (player_moving)
			{
				t++;
				if (t == 4)
				{
					t = 0;
					if (d == 1)
					{
						player_sprite_index++;
					}
					else
					{
						player_sprite_index--;
					}
					if (player_sprite_index == 2 || player_sprite_index == 0)
					{
						if (d == 1)
						{
							d = 0;
						}
						else
						{
							d = 1;
						}
					}
					spr_index[player_sprite] = player_sprite_index + sprite_index_stroudman_first;
				}
				unsigned char y = player_y;
				if (player_sprite_index == 1)
				{
					y--;
				}
				set_sprite_position(player_sprite, player_x, y);
			}
			update_sprites();
		}

		vblank_last = vblank;
	}
}
