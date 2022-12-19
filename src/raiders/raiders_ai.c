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

#define const_ai_first 1
#define const_ai_max const_character_max - 1

unsigned char ai_mode[const_ai_max];
unsigned char ai_last = const_ai_max + const_ai_first;
unsigned char ai_active = 0;

void update_ai()
{
	unsigned ai_char = ai_active + const_ai_first;
	signed char move_x = 0;
	signed char move_y = 0;

	if (!character_anim_locked[ai_char])
	{
		unsigned char min_dist_x = 30;
		unsigned char min_dist_y = 30;
		unsigned char run_dist_x = 60;
		unsigned char run_dist_y = 60;
		if (ai_mode[ai_active] == 1)
		{
			min_dist_x = 15;
			run_dist_x = 30;
			min_dist_y = 4;
			run_dist_y = 25;
		}

		bool walk = false;
		bool run = false;

		signed short player_cpu_off_x = character_x[0] - character_x[ai_char];
		signed char player_cpu_off_y = character_y[0] - character_y[ai_char];
		unsigned short dx = abs(player_cpu_off_x);
		unsigned short dy = abs(player_cpu_off_y);

		if (player_cpu_off_x != 0)
		{
			signed char sx = sign_short_as_char(player_cpu_off_x);
			character_dir[ai_char] = sx;
			set_sprite_mirror(const_character_first_sprite_index + ai_char, sx == 1 ? 0 : 1);
			if (dx > min_dist_x)
			{
				if (dx > run_dist_x)
				{
					run = true;
					move_x = sx * 2;
				}
				else
				{
					walk = true;
					move_x = sx;
				}
			}
		}

		if (!run)
		{
			if (player_cpu_off_y != 0)
			{
				signed char sy = sign_short_as_char(player_cpu_off_y);
				if (dy > min_dist_y)
				{
					if (dy > run_dist_y)
					{
						run = true;
						move_y = sy * 2;
					}
					else
					{
						walk = true;
						move_y = sy;
					}
				}
			}
		}

		if (character_anim_timer[ai_char] == 0)
		{
			character_anim[ai_char] = run ? const_character_anim_run : walk ? const_character_anim_walk
																	   : const_character_idle;

			if (dx < 16 && dy < 16)
			{
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
		}
	}
	character_move_x[ai_char] = move_x;
	character_move_y[ai_char] = move_y;

	ai_active++;
	if (ai_active == const_ai_max)
	{
		ai_active = 0;
	}
}