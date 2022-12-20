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
#include "raiders_ai.h"

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

#define const_player_walk_speed 4
#define const_player_run_speed 8

#define const_team_player 0
#define const_team_ai 1

void app_main()
{
	chram_size = chram_cols * chram_rows;
	clear_chars(0);
	init_sprites();
	clear_sprites();

	// Set player position
	set_character_screen_position(0, 40, 160);
	activate_character(0, sprite_index_alex_first, const_team_player);

	// Set enemy position
	set_character_screen_position(1, 340, 145);
	activate_character(1, sprite_index_ninjablack_first, const_team_ai);
	ai_mode[0] = 1;

	// Set enemy position
	set_character_screen_position(2, 360, 175);
	activate_character(2, sprite_index_ninjared_first, const_team_ai);
	ai_mode[1] = 2;

	// // Set enemy position
	// set_character_screen_position(3, 300, 180);
	// activate_character(3, sprite_index_stroudman_first);
	// ai_mode[2] = 0;

	// AI modes
	// 0 - run to far point, walk to near point and hang back
	// 1 - run in near, walk to closed
	// 2 - run in close!

	scene_offset_x = 0;
	scene_offset_y = -2;
	init_scene();

	update_characters();
	
	while (1)
	{
		vblank = CHECK_BIT(input0, INPUT_VBLANK);

		if (VBLANK_RISING)
		{
			// Update sprites with changes from last frame
			update_sprites();

			// Update tilemap with changes from last frame
			update_tilemap();

			// Reset timer
			timer[0] = 0;

			// Collect player inputs
			basic_input();

			// Player control
			bool player_moving = 0;
			bool run = input_a;
			unsigned player_speed = run ? const_player_run_speed : const_player_walk_speed;
			signed char player_move_x = 0;
			signed char player_move_y = 0;
			if (character_anim_locked[0] == 0)
			{
				if (input_b && character_anim_timer[0] == 0)
				{
					character_start_punch(0);
				}
				else if (input_x && character_anim_timer[0] == 0)
				{
					character_start_kick(0);
				}
				else
				{
					unsigned char player_sprite = const_character_first_sprite_index;
					if (input_left)
					{
						character_dir[0] = -1;
						set_sprite_mirror(player_sprite, 1);
						unsigned short new_player_x = character_x[0] - player_speed;
						if (player_aabb_check(new_player_x, character_y[0]) == 255)
						{
							player_moving = 1;
							player_move_x = -player_speed;
						}
					}
					if (input_right)
					{
						character_dir[0] = 1;
						set_sprite_mirror(player_sprite, 0);
						unsigned short new_player_x = character_x[0] + player_speed;
						if (player_aabb_check(new_player_x, character_y[0]) == 255)
						{
							player_moving = 1;
							player_move_x = player_speed;
						}
					}

					if (input_up)
					{
						unsigned short new_player_y = character_y[0] - player_speed;
						if (player_aabb_check(character_x[0], new_player_y) == 255)
						{
							player_moving = 1;
							player_move_y = -player_speed;
						}
					}
					if (input_down)
					{
						unsigned short new_player_y = character_y[0] + player_speed;
						if (player_aabb_check(character_x[0], new_player_y) == 255)
						{
							player_moving = 1;
							player_move_y = player_speed;
						}
					}
					if (player_moving)
					{
						character_anim[0] = run ? const_character_anim_run : const_character_anim_walk;
					}
					else
					{
						character_anim[0] = const_character_anim_idle;
					}
				}
			}
			if (!character_anim_locked[0])
			{
				character_move_x[0] = player_move_x;
				character_move_y[0] = player_move_y;
			}

			// Handle scrolling
			scroll_x = ((scene_offset_x * 16) + tilemap_offset_x);
			unsigned short focus_x = ((character_x[0] / const_character_position_divider));
			signed short scroll_offset = focus_x - scroll_x;

			if (scroll_offset > 200 && scroll_x < scroll_x_max)
			{
				signed short scroll_amount = scroll_offset - 200;
				if (scroll_amount > scroll_move_max)
				{
					scroll_amount = scroll_move_max;
				}
				tilemap_offset_x += scroll_amount;
			}

			if (scroll_x > 0 && scroll_offset < 140)
			{
				signed short scroll_amount = scroll_offset - 140;
				if (scroll_amount < -scroll_move_max)
				{
					scroll_amount = -scroll_move_max;
				}
				tilemap_offset_x += scroll_amount;
				// update_tilemap();
			}

			// unsigned short tp1 = GET_TIMER;

			update_ai();
			// unsigned short tai = GET_TIMER;

			update_characters();
			// unsigned short tc = GET_TIMER;

			sort_sprites();
			// unsigned short tss = GET_TIMER;

			// unsigned short tsu = GET_TIMER;
			// write_stringf_ushort("player         %4d", 0xFF, 0, 0, tp1);
			// write_stringf_ushort("ai             %4d", 0xFF, 0, 10, tai - tp1);
			// write_stringf_ushort("characters     %4d", 0xFF, 0, 2, tc - tai);
			// write_stringf_ushort("sort sprites   %4d", 0xFF, 0, 3, tss - tc);
			// write_stringf_ushort("update sprites %4d", 0, 0, 4, tsu - tss);
		}

		vblank_last = vblank;
	}
}
