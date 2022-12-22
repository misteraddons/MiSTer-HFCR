/*============================================================================
	Aznable OS - Raiders demo - Scene controller

	Copyright 2022 - Jim Gregory - https://github.com/JimmyStones/

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
#include "../shared/tilemap.h"
#include "tilemap_indexes.h"
#include "collision_boxes.h"

signed char scene_offset_x = 0;
signed char scene_offset_y = 0;
unsigned short scroll_x;
unsigned short scroll_x_max;
unsigned char screen_width = 21;
unsigned char scroll_move_max = 5;

void update_section(unsigned char lx, unsigned char rx, unsigned char ty, unsigned char by)
{
	for (unsigned char y = ty; y <= by; y++)
	{
		unsigned short p = (y * 32) + lx;
		unsigned char yi = (y + scene_offset_y - 1);
		for (unsigned char x = lx; x <= rx; x++)
		{
			tilemapram[p] = tilemap_index[yi][x + scene_offset_x - 1];
			p++;
		}
	}
}

void init_scene()
{
	update_section(0, screen_width, 0, const_tilemap_index_y_max - scene_offset_y);
	tilemap_offset_x = 0;
	tilemap_offset_y = 0;
	scroll_x_max = (const_tilemap_index_x_max * 16) - 320;

	// Shift collision boxes to match scene offset
	for (unsigned char b = 0; b < const_collision_boxes_max; b++)
	{
		collision_box_l[b] += 32;
		collision_box_r[b] += 32;
		collision_box_t[b] += (scene_offset_y * -16) + 32;
		collision_box_b[b] += (scene_offset_y * -16) + 32;
	}
}

void update_tilemap()
{

	if (tilemap_offset_x >= 16)
	{
		tilemap_offset_x -= 16;
		scroll_tilemap_left();
		scene_offset_x++;
		update_section(screen_width, screen_width, 0, 16);
	}
	else if (tilemap_offset_x <= -16)
	{
		tilemap_offset_x += 16;
		scroll_tilemap_right();
		scene_offset_x--;
		update_section(0, 0, 0, 16);
	}
	else if (tilemap_offset_y >= 16)
	{
		tilemap_offset_y -= 16;
		scroll_tilemap_up();
		scene_offset_y++;
		update_section(0, screen_width, 16, 16);
	}
	else if (tilemap_offset_y <= -16)
	{
		tilemap_offset_y += 16;
		scroll_tilemap_down();
		scene_offset_y--;
		update_section(0, screen_width, 0, 0);
	}

	update_tilemap_offset();
}