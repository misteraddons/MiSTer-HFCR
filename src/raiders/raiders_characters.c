/*============================================================================
	Aznable OS - Raiders demo - Character controller

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
#include "raiders_characters.h"

unsigned char character_anim[const_character_max];
unsigned char character_frame[const_character_max];
unsigned short character_x[const_character_max];
unsigned short character_y[const_character_max];
unsigned char character_sprite_offset[const_character_max];
unsigned char character_anim_timer[const_character_max];
unsigned char character_anim_dir[const_character_max];
unsigned char character_anim_locked[const_character_max];

void update_characters(unsigned short scroll_x)
{
	for (unsigned char c = 0; c < const_character_max; c++)
	{
		if (character_anim[c] != 0)
		{
			character_anim_timer[c]++;
		}
		else
		{
			if (character_anim_timer[c] > 0)
			{
				character_anim_timer[c]--;
			}
		}
		switch (character_anim[c])
		{
		case const_character_idle:
			character_frame[c] = 1;
			break;
		case const_character_walk:
			if (character_frame[c] > 2)
			{
				character_frame[c] = 0;
			}
			if (character_anim_timer[c] >= const_character_walk_rate)
			{
				character_anim_timer[c] = 0;
				if (character_anim_dir[c] == 0)
				{
					character_frame[c]++;
					if (character_frame[c] == 2)
					{
						character_anim_dir[c] = 1;
					}
				}
				else
				{
					character_frame[c]--;
					if (character_frame[c] == 0)
					{
						character_anim_dir[c] = 0;
					}
				}
			}
			break;
		case const_character_run:
			if (character_anim_timer[c] >= const_character_run_rate)
			{
				character_anim_timer[c] = 0;
				character_frame[c] = character_frame[c] == 1 ? 3 : 1;
			}
			break;
		case const_character_punch:
			if (character_anim_timer[c] >= const_character_punch_rate)
			{
				character_frame[c]++;
				if (character_frame[c] == 8)
				{
					character_anim[c] = const_character_idle;
					character_anim_locked[c] = 0;
				}
				else
				{
					character_anim_timer[c] = 0;
				}
			}
		case const_character_kick:
			if (character_anim_timer[c] >= const_character_kick_rate)
			{
				character_frame[c]++;
				if (character_frame[c] == 11)
				{
					character_anim[c] = const_character_idle;
					character_anim_locked[c] = 0;
				}
				else
				{
					character_anim_timer[c] = 0;
				}
			}
			break;
		}

		// Draw character sprite
		unsigned char player_sprite = const_character_first_sprite_index + c;
		spr_index[player_sprite] = character_sprite_offset[c] + character_frame[c];
 		unsigned short x = (character_x[c] - scroll_x) + 32;
		unsigned short y = character_y[c];
		if (character_frame[c] == 2 || character_frame[c] == 3)
		{
			y--;
		}
		set_sprite_position(player_sprite, x, y + 32);
		write_stringf("%d", 0xFF, 0, c, spr_index[player_sprite]);
	}
}
