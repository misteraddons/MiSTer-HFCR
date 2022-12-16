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
#include "collision_boxes.h"

int logo_sprite = 0;
int player_sprite = 1;
unsigned short player_x = 32;
unsigned short player_y = 180;
unsigned char player_moving = 0;
unsigned char player_sprite_index = 1;
unsigned char player_sprite_anim_timer = 0;
unsigned char player_sprite_anim_dir = 1;

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
unsigned short scroll_x;
unsigned short scroll_x_max;
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

unsigned char point_in_box(unsigned short x, unsigned short y)
{
	for (unsigned char c = 0; c < const_collision_boxes_max; c++)
	{
		if (x >= collision_box_l[c] && x <= collision_box_r[c])
		{
			write_stringf("COLx %d", 0xFF, 0, 3, c);
			if (y >= collision_box_t[c] && y <= collision_box_b[c])
			{
				write_stringf("COLy %d", 0xFF, 0, 4, c);
				return c;
			}
		}
	}
	return 255;
}

unsigned char player_aabb_check(unsigned short x, unsigned short y)
{
	unsigned short l = x + 6;
	unsigned short r = x + 24;
	unsigned short t = y + 26;
	unsigned short b = y + 32;

	for (unsigned char c = 0; c < const_collision_boxes_max; c++)
	{
		if (r < collision_box_l[c] || l > collision_box_r[c])
		{
			continue;
		}
		if (b < collision_box_t[c] || t > collision_box_b[c])
		{
			continue;
		}
		// write_stringf("COL %d", 0xFF, 0, 3, c);
		return c;
	}
	return 255;
}

void draw_player_sprite()
{
	spr_index[player_sprite] = player_sprite_index + sprite_index_stroudman_first;
	unsigned short x = (player_x - scroll_x) + 32;
	unsigned short y = player_y;
	if (player_sprite_index == 2 || player_sprite_index == 3)
	{
		y--;
	}
	set_sprite_position(player_sprite, x, y + 32);
}

void update_tilemap()
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
	player_sprite_index = 1;
	draw_player_sprite();

	update_section(0, screen_width, 0, const_tilemap_index_y_max - y_off);
	tilemap_offset_x = 0;
	tilemap_offset_y = 0;
	scroll_x_max = (const_tilemap_index_x_max * 16) - 320;

	// Shift collision boxes to match scene offset
	for (unsigned char c = 0; c < const_collision_boxes_max; c++)
	{
		collision_box_t[c] -= y_off * 16;
		collision_box_b[c] -= y_off * 16;
	}

	while (1)
	{
		vblank = CHECK_BIT(input0, INPUT_VBLANK);

		if (VBLANK_RISING)
		{
			// Reset timer
			timer[0] = 0;

			basic_input();

			player_moving = 0;
			unsigned player_speed = input_a ? 3 : 1;
			if (input_left)
			{
				set_sprite_mirror(player_sprite, 1);
				unsigned short new_player_x = player_x - player_speed;
				if (player_aabb_check(new_player_x, player_y) == 255)
				{
					player_moving = 1;
					player_x = new_player_x;
				}
			}
			if (input_right)
			{
				set_sprite_mirror(player_sprite, 0);
				unsigned short new_player_x = player_x + player_speed;
				if (player_aabb_check(new_player_x, player_y) == 255)
				{
					player_moving = 1;
					player_x = new_player_x;
				}
			}

			if (input_up)
			{
				unsigned short new_player_y = player_y - player_speed;
				if (player_aabb_check(player_x, new_player_y) == 255)
				{
					player_moving = 1;

					player_y = new_player_y;
				}
			}
			if (input_down)
			{
				unsigned short new_player_y = player_y + player_speed;
				if (player_aabb_check(player_x, new_player_y) == 255)
				{
					player_moving = 1;

					player_y = new_player_y;
				}
			}

			if (player_moving)
			{
				player_sprite_anim_timer++;
				if (player_sprite_anim_timer == 4)
				{
					player_sprite_anim_timer = 0;
					if (player_speed == 1)
					{
						if (player_sprite_index > 2)
						{
							player_sprite_index = 1;
						}
						if (player_sprite_anim_dir == 1)
						{
							player_sprite_index++;
						}
						else
						{
							player_sprite_index--;
						}
						if (player_sprite_index == 2 || player_sprite_index == 0)
						{
							if (player_sprite_anim_dir == 1)
							{
								player_sprite_anim_dir = 0;
							}
							else
							{
								player_sprite_anim_dir = 1;
							}
						}
					}
					else
					{
						player_sprite_index = (player_sprite_index == 3) ? 1 : 3;
					}
				}

				// Handle scrolling
				scroll_x = ((x_off * 16) + tilemap_offset_x);
				signed short scroll_offset = player_x - scroll_x;

				if (scroll_offset > 180 && scroll_x < scroll_x_max)
				{
					unsigned short scroll_avail = scroll_x_max - scroll_x;
					tilemap_offset_x += scroll_avail > player_speed ? player_speed : scroll_avail;
					update_tilemap();
				}
				if (scroll_x > 0 && scroll_offset < 140)
				{
					tilemap_offset_x -= scroll_x > player_speed ? player_speed : scroll_x;
					update_tilemap();
				}
			}
			else
			{
				player_sprite_index = 1;
			}
			draw_player_sprite();
			update_sprites();

			unsigned short t = GET_TIMER;
			write_stringf_ushort("%4d", 0xFF, 2, 10, t);
		}

		vblank_last = vblank;
	}
}
