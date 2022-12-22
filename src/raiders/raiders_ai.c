/*============================================================================
	Aznable OS - Raiders demo - AI controller

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
#include "../shared/ui.h"
#include "../shared/sprite.h"
#include "sprite_images.h"
#include "raiders_scene.h"
#include "raiders_ai.h"
#include "raiders_characters.h"

unsigned char ai_active[const_ai_max];
unsigned char ai_mode[const_ai_max];
unsigned char ai_attack_timer[const_ai_max];

unsigned char ai_first_free = 0;
unsigned char ai_active_count = 0;
unsigned char ai_spawn_timer = 15;

#define ai_active_max 3

#define const_ai_walk_speed 4
#define const_ai_run_speed 8

#define const_ai_dist_far_x 240
#define const_ai_dist_mid_x 120
#define const_ai_dist_close_x 60

#define const_ai_dist_far_y 90
#define const_ai_dist_mid_y 30
#define const_ai_dist_close_y 10

#define const_ai_range_attack_x 80
#define const_ai_range_attack_y 16

#define const_team_ai 1

void update_ai()
{

	// write_stringf("ai_active_count %d", 0xFF, 0, 0, ai_active_count);
	// write_stringf("ai_first_free %d", 0xFF, 0, 1, ai_first_free);
	// write_stringf("ai_spawn_timer %d", 0xFF, 0, 2, ai_spawn_timer);
	if (ai_first_free != 255)
	{
		if (ai_spawn_timer > 0)
		{
			ai_spawn_timer--;
		}
		else
		{
			if (ai_active_count < ai_active_max)
			{
				// Set enemy positions randomly
				unsigned char c = ai_first_free + const_ai_first_character;
				unsigned short ax = (rand_uchar(0, 1) == 0) ? scroll_x : scroll_x + (screen_width + 32);
				unsigned short ay = rand_ushort(130, 190);
				set_character_screen_position(c, ax, ay);
				activate_character(c, rand_uchar(0, 1) == 0 ? sprite_index_ninjared_first : sprite_index_ninjablack_first, const_team_ai, 20);
				character_anim[c] = const_character_anim_idle;
				character_anim_timer[c] = rand_uchar(0, 5);
				ai_mode[ai_first_free] = 0;
				ai_active[ai_first_free] = 1;
				ai_spawn_timer = 30 + (ai_active_count * 60);
			}
		}
	}

	ai_first_free = 255;
	ai_active_count = 0;
	bool first_up = true;
	for (unsigned char a = 0; a < const_ai_max; a++)
	{
		if (!ai_active[a])
		{
			if (a < ai_first_free)
			{
				ai_first_free = a;
			}
			continue;
		}

		ai_active_count++;

		unsigned ai_char = a + const_ai_first_character;
		if (character_health[ai_char] == 0 && character_active[ai_char] == 0)
		{
			ai_active[a] = 0;
			continue;
		}

		if (first_up && ai_mode[a] == 0)
		{
			ai_mode[a] = rand_uchar(1, 2);
		}
		first_up = false;

		signed char move_x = 0;
		signed char move_y = 0;

		if (ai_attack_timer[a] > 0)
		{
			ai_attack_timer[a]--;
		}

		if (character_anim_locked[ai_char] == 0)
		{
			unsigned char min_dist_x = const_ai_dist_mid_x;
			unsigned char min_dist_y = const_ai_dist_mid_y;
			unsigned char run_dist_x = const_ai_dist_far_x;
			unsigned char run_dist_y = const_ai_dist_far_y;
			if (ai_mode[a] == 1)
			{
				min_dist_x = const_ai_dist_close_x;
				run_dist_x = const_ai_dist_mid_x;
				min_dist_y = const_ai_dist_close_y;
				run_dist_y = const_ai_dist_mid_y;
			}
			if (ai_mode[a] == 2)
			{
				min_dist_x = const_ai_dist_close_x;
				run_dist_x = const_ai_dist_close_x;
				min_dist_y = const_ai_dist_close_y;
				run_dist_y = const_ai_dist_close_y;
			}

			bool walk = false;
			bool run = false;

			signed short player_cpu_off_x = character_x[0] - character_x[ai_char];
			signed short player_cpu_off_y = character_y[0] - character_y[ai_char];
			unsigned short dx = abs(player_cpu_off_x);
			unsigned short dy = abs(player_cpu_off_y);

			if (player_cpu_off_x != 0)
			{
				signed char sx = sign_short_as_char(player_cpu_off_x);
				character_dir[ai_char] = sx;
				set_sprite_mirror(const_character_first_sprite_index + ai_char, sx == 1 ? 0 : 1);
				if (dx > run_dist_x)
				{
					run = true;
					move_x = sx * const_ai_run_speed;
				}
				else if (dx > (min_dist_x + 4))
				{
					walk = true;
					move_x = sx * const_ai_walk_speed;
				}
				else if (dx < (min_dist_x - 4))
				{
					walk = true;
					move_x = -sx * const_ai_walk_speed;
				}
			}

			if (!run)
			{
				if (player_cpu_off_y != 0)
				{
					signed char sy = sign_short_as_char(player_cpu_off_y);

					if (dy > run_dist_y)
					{
						run = true;
						move_y = sy * const_ai_run_speed;
					}
					else if (dy > (min_dist_y + 4))
					{
						walk = true;
						move_y = sy * const_ai_walk_speed;
					}
					else if (dy < (min_dist_y - 4))
					{
						walk = true;
						move_y = -sy * const_ai_walk_speed;
					}
				}
			}

			if (character_anim_locked[ai_char] == 0)
			{
				character_anim[ai_char] = run ? const_character_anim_run : walk ? const_character_anim_walk
																				: const_character_anim_idle;
				if (character_anim_timer[ai_char] == 0)
				{
					if (ai_attack_timer[a] == 0)
					{
						if (dx < const_ai_range_attack_x && dy < const_ai_range_attack_y)
						{
							character_move_x[ai_char] = 0;
							character_move_y[ai_char] = 0;
							unsigned char attack = rand_uchar(0, 1);
							switch (attack)
							{
							case 0:
								character_start_punch(ai_char);
								break;
							case 1:
								character_start_kick(ai_char);
								break;
							}
						}
						ai_attack_timer[a] = rand_uchar(6, 25);
					}
				}
			}
		}
		if (!character_anim_locked[ai_char])
		{
			character_move_x[ai_char] = move_x;
			character_move_y[ai_char] = move_y;
		}
	}
}