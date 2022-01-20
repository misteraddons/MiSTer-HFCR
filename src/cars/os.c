/*============================================================================
	Aznable OS - Scrolling tilemap test

	Author: Jim Gregory - https://github.com/JimmyStones/
	Version: 1.1
	Date: 2022-01-07

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
#include "../shared/tilemap.h"
#include "tilemap_indexes.h"

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

// Main entry
void main()
{

	chram_size = chram_cols * chram_rows;
	update_section(0, 22, 0, 16);
	tilemap_offset_x = 0;
	tilemap_offset_y = 0;

	unsigned char scroll_speed = 4;
	unsigned char x_off_max = const_tilemap_index_x_max - 20;
	unsigned char y_off_max = const_tilemap_index_y_max - 15;

	while (1)
	{
		vblank = CHECK_BIT(input0, INPUT_VBLANK);

		if (VBLANK_RISING)
		{

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
		}

		if (VBLANK_FALLING)
		{
			basic_input();
			if (input_right && x_off < x_off_max)
				tilemap_offset_x += scroll_speed;
			if (input_left && x_off > 0)
				tilemap_offset_x -= scroll_speed;
			if (input_up && y_off > 0)
				tilemap_offset_y -= scroll_speed;
			if (input_down && y_off < y_off_max)
				tilemap_offset_y += scroll_speed;
		}
		vblank_last = vblank;
	}
}