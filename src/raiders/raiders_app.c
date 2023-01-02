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
#include "particles.h"
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
bool input_y;
bool input_y_last = 0;

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
	input_y_last = input_y;
	input_up = CHECK_BIT(joystick[0], 3);
	input_down = CHECK_BIT(joystick[0], 2);
	input_left = CHECK_BIT(joystick[0], 1);
	input_right = CHECK_BIT(joystick[0], 0);
	input_a = CHECK_BIT(joystick[0], 4);
	input_b = CHECK_BIT(joystick[0], 5);
	input_x = CHECK_BIT(joystick[0], 6);
	input_y = CHECK_BIT(joystick[0], 7);
}

#define const_player_walk_speed 5
#define const_player_run_speed 12

unsigned char player_hit_combo_timer;

#define const_player_character 0
#define const_team_player 0

// #define DEBUG_TIMING

void sprite_test()
{
	clear_bgcolor(0b00011001);
	SET_BIT(video_ctl, 0); // Enable sprite priority over charmap
	unsigned char first_sprite = sprite_index_aaaa_first;

	unsigned redraw = true;
	while (1)
	{
		vblank = CHECK_BIT(input0, INPUT_VBLANK);
		if (VBLANK_RISING)
		{

			// Collect player inputs
			basic_input();

			if (input_up)
			{
				if (first_sprite > 7)
				{
					first_sprite -= 8;
					redraw = true;
				}
			}
			if (input_down)
			{
				first_sprite += 8;
				redraw = true;
			}

			write_stringf("first: %3d", 0xFF, 0, 0, first_sprite);
			write_stringf("last: %3d", 0xFF, 12, 0, first_sprite + 32);

			if (redraw)
			{
				unsigned char s = 0;
				unsigned char f = sprite_index_aaaa_first;
				unsigned char y = 0;

				bool m = false;
				for (unsigned char x = 0; x < 8; x++)
				{
					write_stringf("%2d", 0xFF, (x * 4), 1 + (y * 6), f);
					enable_sprite(s, sprite_palette_test16, sprite_size_aaaa, 0);
					set_sprite_position(s, 32 + (x * 34), 52 + (y * 48));
					if (m)
					{
						set_sprite_mirror(s, 1);
					}
					spr_index[s] = f;
					s++;
					f++;
					m = !m;
					if (s == 16)
					{
						break;
					}
				}
				if (s == 16)
				{
					break;
				}

				y = 2;
				f = sprite_index_test16_first;
				m = false;
				for (unsigned char x = 0; x < 8; x++)
				{
					write_stringf("%2d", 0xFF, (x * 4), 1 + (y * 6), f);
					enable_sprite(s, sprite_palette_test16, sprite_size_test16, 0);
					set_sprite_position(s, 32 + (x * 34), 52 + (y * 48));
					if (m)
					{
						set_sprite_mirror(s, 1);
					}
					spr_index[s] = f;
					s++;
					f++;
					m = !m;
					if (s == 32)
					{
						break;
					}
				}

				y = 3;
				f = sprite_index_test8_first;
				for (unsigned char x = 0; x < 8; x++)
				{
					write_stringf("%2d", 0xFF, (x * 4), 1 + (y * 6), f);
					enable_sprite(s, sprite_palette_test16, sprite_size_test8, 0);
					set_sprite_position(s, 32 + (x * 34), 52 + (y * 48));
					spr_index[s] = f;
					if (m)
					{
						set_sprite_mirror(s, 1);
					}
					s++;
					f++;
					m = !m;
					if (s == 32)
					{
						break;
					}
				}

				update_sprites();
				redraw = false;
			}
		}
	}
}

void app_main()
{
	chram_size = chram_cols * chram_rows;
	clear_chars(0);
	init_sprites();
	clear_sprites();
	//sprite_test();

	init_particles();

	// Set player position
	set_character_screen_position(0, 60, 160);
	//activate_character(0, sprite_index_rota_first, const_team_player, 30);
	activate_character(0, sprite_index_alex_first, const_team_player, 30);

	scene_offset_x = 0;
	scene_offset_y = 0;
	init_scene();

	update_characters();

	while (1)
	{
		vblank = CHECK_BIT(input0, INPUT_VBLANK);

		if (VBLANK_RISING)
		{
			// Update sprites with changes from last frame
#ifdef DEBUG_TIMING
			unsigned short time_before_update_sprites = GET_TIMER;
#endif
			update_sprites();
#ifdef DEBUG_TIMING
			unsigned short time_after_update_sprites = GET_TIMER;
#endif
			// Update tilemap with changes from last frame
#ifdef DEBUG_TIMING
			unsigned short time_before_update_tiles = GET_TIMER;
#endif
			update_tilemap();
#ifdef DEBUG_TIMING
			unsigned short time_after_update_tiles = GET_TIMER;
#endif

#ifdef DEBUG_TIMING
			// Reset timer
			timer[0] = 0;
			unsigned short time_before_player_input = GET_TIMER;
#endif
			// Collect player inputs
			basic_input();

			// Player control
			bool player_moving = 0;
			bool run = input_a;
			unsigned player_speed = run ? const_player_run_speed : const_player_walk_speed;
			signed char player_move_x = 0;
			signed char player_move_y = 0;

			if (character_anim_locked[const_player_character] == 0)
			{
				if (input_y && character_z[const_player_character] == 0)
				{
					character_start_jump(const_player_character);
				}
				if (input_b)
				{
					if (character_hit_combo[const_player_character] >= 2)
					{
						character_start_uppercut(const_player_character);
						character_hit_combo[const_player_character] = 0;
						character_hit_combo_timer[const_player_character] = 0;
					}
					else
					{
						character_start_punch(const_player_character);
					}
				}
				else if (input_x)
				{
					if (character_hit_combo[const_player_character] >= 2)
					{
						character_start_powerkick(const_player_character);
						character_hit_combo[const_player_character] = 0;
						character_hit_combo_timer[const_player_character] = 0;
					}
					else
					{
						character_start_kick(const_player_character);
					}
				}
				else
				{
					if (character_onground[const_player_character])
					{
						unsigned char player_sprite = const_character_first_sprite_index;
						if (input_left)
						{
							character_dir[const_player_character] = -1;
							set_sprite_mirror(player_sprite, 1);
							player_moving = 1;
							player_move_x = -player_speed;
						}
						if (input_right)
						{
							character_dir[const_player_character] = 1;
							set_sprite_mirror(player_sprite, 0);
							player_moving = 1;
							player_move_x = player_speed;
						}

						if (input_up)
						{
							player_moving = 1;
							player_move_y = -player_speed;
						}
						if (input_down)
						{
							player_moving = 1;
							player_move_y = player_speed;
						}

						if (player_moving)
						{
							character_anim[const_player_character] = run ? const_character_anim_run : const_character_anim_walk;
						}
						else
						{
							if (character_anim[const_player_character] == const_character_anim_run || character_anim[const_player_character] == const_character_anim_walk)
							{
								character_anim[const_player_character] = const_character_anim_idle;
							}
						}
					}
				}
			}
			if (!character_anim_locked[const_player_character] && character_onground[const_player_character])
			{
				character_move_x[const_player_character] = player_move_x;
				character_move_y[const_player_character] = player_move_y;
			}
#ifdef DEBUG_TIMING
			unsigned short time_after_player_input = GET_TIMER;
#endif

#ifdef DEBUG_TIMING
			unsigned short time_before_scroll = GET_TIMER;
#endif
			// Handle scrolling
			unsigned short last_scroll_x = scroll_x;
			scroll_x = ((scene_offset_x * 16) + tilemap_offset_x);
			scroll_v_x = scroll_x - last_scroll_x;

			unsigned short focus_x = (character_x[const_player_character] / const_character_position_divider);
			if (focus_x > scroll_x_max)
			{
				focus_x = scroll_x_max;
			}
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
			}

#ifdef DEBUG_TIMING
			unsigned short time_after_scroll = GET_TIMER;
#endif

#ifdef DEBUG_TIMING
			unsigned short time_before_ai = GET_TIMER;
#endif
			update_ai();
#ifdef DEBUG_TIMING
			unsigned short time_after_ai = GET_TIMER;
#endif

#ifdef DEBUG_TIMING
			unsigned short time_before_characters = GET_TIMER;
#endif
			update_characters();
#ifdef DEBUG_TIMING
			unsigned short time_after_characters = GET_TIMER;
#endif

#ifdef DEBUG_TIMING
			unsigned short time_before_particles = GET_TIMER;
#endif
			update_particles();
#ifdef DEBUG_TIMING
			unsigned short time_after_particles = GET_TIMER;
#endif

#ifdef DEBUG_TIMING
			unsigned short time_before_sortsprites = GET_TIMER;
#endif
			sort_sprites();
#ifdef DEBUG_TIMING
			unsigned short time_after_sortsprites = GET_TIMER;
			// Reset timer
			timer[0] = 0;
#endif

#ifdef DEBUG_TIMING
			write_stringf_ushort("update sprites      %6d", 0xFF, 0, 23, time_after_update_sprites - time_before_update_sprites);
			write_stringf_ushort("update tiles        %6d", 0xFF, 0, 24, time_after_update_tiles - time_before_update_tiles);
			write_stringf_ushort("player input        %6d", 0xFF, 0, 25, time_after_player_input - time_before_player_input);
			write_stringf_ushort("scrolling           %6d", 0xFF, 0, 26, time_after_scroll - time_before_scroll);
			write_stringf_ushort("update ai           %6d", 0xFF, 0, 27, time_after_ai - time_before_ai);
			write_stringf_ushort("update characters   %6d", 0xFF, 0, 28, time_after_characters - time_before_characters);
			write_stringf_ushort("sort sprites        %6d", 0xFF, 0, 29, time_after_sortsprites - time_before_sortsprites);
#endif
		}

		vblank_last = vblank;
	}
}
