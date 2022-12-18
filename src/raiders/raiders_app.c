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
#include "../shared/tilemap.h"
#include "sprite_images.h"
#include "raiders_app.h"
#include "tilemap_indexes.h"
#include "collision_boxes.h"
#include "raiders_scene.h"
#include "raiders_characters.h"

int logo_sprite = 0;

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
bool input_b;
bool input_b_last = 0;
bool input_x;
bool input_x_last = 0;

signed char x_off = 0;
signed char y_off = -2;

// Track joypad 1 directions and start for menu control
void basic_input()
{
	input_up_last = input_up;
	input_down_last = input_down;
	input_left_last = input_left;
	input_right_last = input_right;
	input_a_last = input_a;
	input_b_last = input_b;
	input_x_last = input_x;
	input_up = CHECK_BIT(joystick[0], 3);
	input_down = CHECK_BIT(joystick[0], 2);
	input_left = CHECK_BIT(joystick[0], 1);
	input_right = CHECK_BIT(joystick[0], 0);
	input_a = CHECK_BIT(joystick[0], 4);
	input_b = CHECK_BIT(joystick[0], 5);
	input_x = CHECK_BIT(joystick[0], 6);
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

// unsigned char point_in_box(unsigned short x, unsigned short y)
// {
// 	for (unsigned char c = 0; c < const_collision_boxes_max; c++)
// 	{
// 		if (x >= collision_box_l[c] && x <= collision_box_r[c])
// 		{
// 			write_stringf("COLx %d", 0xFF, 0, 3, c);
// 			if (y >= collision_box_t[c] && y <= collision_box_b[c])
// 			{
// 				write_stringf("COLy %d", 0xFF, 0, 4, c);
// 				return c;
// 			}
// 		}
// 	}
// 	return 255;
// }

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
		return c;
	}
	return 255;
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

#define const_character_sprite_palette sprite_palette_alex
#define const_character_sprite_size sprite_size_alex

void app_main()
{
	chram_size = chram_cols * chram_rows;
	clear_chars(0);
	init_sprites();
	clear_sprites();

	enable_sprite(logo_sprite, sprite_palette_logos, sprite_size_logos, 0);
	set_sprite_position(logo_sprite, 30, 32);
	spr_index[logo_sprite] = sprite_index_logos_first;

	// Set player position
	character_x[0] = 40;
	character_y[0] = 140;
	enable_sprite(const_character_first_sprite_index, const_character_sprite_palette, const_character_sprite_size, 0);
	character_sprite_offset[0] = sprite_index_alex_first;

	// Set enemy position
	character_x[1] = 200;
	character_y[1] = 130;
	enable_sprite(const_character_first_sprite_index + 1, const_character_sprite_palette, const_character_sprite_size, 0);
	character_sprite_offset[1] = sprite_index_ninja_first;

	// Set enemy position
	character_x[2] = 250;
	character_y[2] = 170;
	enable_sprite(const_character_first_sprite_index + 2, const_character_sprite_palette, const_character_sprite_size, 0);
	character_sprite_offset[2] = sprite_index_ninja_first;

	for (unsigned char c = 0; c < const_character_max; c++)
	{
		unsigned char player_sprite = const_character_first_sprite_index + c;
		set_sprite_position(player_sprite, character_x[c], character_y[c]);
		character_frame[c] = 1;
	}

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

			// Player control
			bool player_moving = 0;
			unsigned player_speed = input_a ? 3 : 1;
			if (!character_anim_locked[0])
			{
				if (input_b && character_anim_timer[0] == 0)
				{
					character_anim[0] = const_character_punch;
					character_frame[0] = 6;
					character_anim_locked[0] = 1;
					character_anim_timer[0] = 0;
				}
				else if (input_x && character_anim_timer[0] == 0)
				{
					character_anim[0] = const_character_kick;
					character_frame[0] = 9;
					character_anim_locked[0] = 1;
					character_anim_timer[0] = 0;
				}
				else
				{

					unsigned char player_sprite = const_character_first_sprite_index;
					if (input_left)
					{
						set_sprite_mirror(player_sprite, 1);
						unsigned short new_player_x = character_x[0] - player_speed;
						if (player_aabb_check(new_player_x, character_y[0]) == 255)
						{
							player_moving = 1;
							character_x[0] = new_player_x;
						}
					}
					if (input_right)
					{
						set_sprite_mirror(player_sprite, 0);
						unsigned short new_player_x = character_x[0] + player_speed;
						if (player_aabb_check(new_player_x, character_y[0]) == 255)
						{
							player_moving = 1;
							character_x[0] = new_player_x;
						}
					}

					if (input_up)
					{
						unsigned short new_player_y = character_y[0] - player_speed;
						if (player_aabb_check(character_x[0], new_player_y) == 255)
						{
							player_moving = 1;
							character_y[0] = new_player_y;
						}
					}
					if (input_down)
					{
						unsigned short new_player_y = character_y[0] + player_speed;
						if (player_aabb_check(character_x[0], new_player_y) == 255)
						{
							player_moving = 1;
							character_y[0] = new_player_y;
						}
					}
					if (player_moving)
					{
						character_anim[0] = player_speed == 1 ? const_character_walk : const_character_run;

						// Handle scrolling
						scroll_x = ((x_off * 16) + tilemap_offset_x);
						signed short scroll_offset = character_x[0] - scroll_x;

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
						character_anim[0] = const_character_idle;
					}
				}
			}

			for (unsigned char c = 1; c < const_character_max; c++)
			{
				signed short player_cpu_off = character_x[0] - character_x[c];
				unsigned char anim = const_character_idle;
				if (player_cpu_off != 0)
				{
					unsigned short d = abs(player_cpu_off);
					if (d > 16)
					{
						signed char s = sign_short_as_char(player_cpu_off);
						set_sprite_mirror(const_character_first_sprite_index + c, s == 1 ? 0 : 1);
						if (d > 64)
						{
							anim = const_character_run;
							character_x[c] += s * 3;
						}
						else
						{
							anim = const_character_walk;
							character_x[c] += s;
						}
					}
				}
				character_anim[c] = anim;
			}

			update_characters();

			update_sprites();

			unsigned short t = GET_TIMER;
			write_stringf_ushort("%4d", 0b00111000, 0, 0, t);
		}

		vblank_last = vblank;
	}
}
