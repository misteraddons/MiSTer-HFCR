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
#include "raiders_scene.h"
#include "raiders_characters.h"

bool character_active[const_character_max];
signed char character_dir[const_character_max];
unsigned char character_anim[const_character_max];
unsigned char character_anim_rate[const_character_max];
unsigned char character_frame[const_character_max];
unsigned char character_frame_target[const_character_max];
unsigned short character_x[const_character_max];
unsigned short character_y[const_character_max];
signed char character_move_x[const_character_max];
signed char character_move_y[const_character_max];
unsigned char character_sprite_offset[const_character_max];
unsigned char character_anim_timer[const_character_max];
unsigned char character_anim_dir[const_character_max];
unsigned char character_anim_locked[const_character_max];

unsigned char character_scheduled_attack[const_character_max];
unsigned char character_scheduled_attack_in[const_character_max];

#define const_character_sprite_palette sprite_palette_alex
#define const_character_sprite_size sprite_size_alex

void activate_character(unsigned char c, unsigned char offset)
{
	character_active[c] = true;
	enable_sprite(const_character_first_sprite_index + c, const_character_sprite_palette, const_character_sprite_size, 0);
	character_sprite_offset[c] = offset;
}

void deactivate_character(unsigned char c)
{
	character_active[c] = false;
	spr_on[const_character_first_sprite_index + c] = false;
}

void character_anim_oneshot(unsigned char c)
{
	if (character_anim_timer[c] >= character_anim_rate[c])
	{
		character_frame[c]++;
		if (character_frame[c] == character_frame_target[c])
		{
			character_anim[c] = const_character_idle;
			character_anim_locked[c] = 0;
		}
		else
		{
			character_anim_timer[c] = 0;
		}
	}
}

void update_characters()
{
	for (unsigned char c = 0; c < const_character_max; c++)
	{
		if (!character_active[c])
		{
			continue;
		}

		// Handle character movement
		character_x[c] += character_move_x[c];
		character_y[c] += character_move_y[c];

		// Handle character animations
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
		case const_character_anim_walk:
			if (character_frame[c] > 2)
			{
				character_frame[c] = 0;
				character_anim_dir[c] = 0;
			}
			if (character_anim_timer[c] >= const_character_anim_walk_rate)
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
		case const_character_anim_run:
			if (character_anim_timer[c] >= const_character_anim_run_rate)
			{
				character_anim_timer[c] = 0;
				character_frame[c] = character_frame[c] == 1 ? 3 : 1;
			}
			break;
		case const_character_anim_oneshot:
			character_anim_oneshot(c);
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

		// Handle attacks

		if (character_scheduled_attack_in[c] > 0)
		{
			character_scheduled_attack_in[c]--;
			if (character_scheduled_attack_in[c] == 0)
			{
				// find characters to hit

				unsigned char s = c + 10;
				enable_sprite(s, sprite_palette_hit, sprite_size_hit, 0);

				unsigned short hit_x = (character_x[c] - scroll_x);
				unsigned short hit_y = character_y[c];
				unsigned char d = character_dir[c];
				switch (character_scheduled_attack[c])
				{
				case const_character_attack_punch:
					hit_x += d == 1 ? 18 : -2;
					hit_y += 4;
					break;
				case const_character_attack_kick:
					hit_x += d == 1 ? 20 : -4;
					hit_y += 12;
					break;
				}

				set_sprite_position(s, hit_x + 32, hit_y + 32);
				spr_index[s] = sprite_index_hit_first;

				// unsigned short cl = character_x[c] + 6;
				// unsigned short cr = x + 24;
				// unsigned short ct = y + 26;
				// unsigned short cb = y + 32;

				// for (int t = 0; t < const_character_max; t++)
				// {
				// 	if (t == c)
				// 	{
				// 		continue;
				// 	}

				// 	// for (unsigned char c = 0; c < const_collision_boxes_max; c++)
				// 	// {
				// 	// 	if (r < collision_box_l[c] || l > collision_box_r[c])
				// 	// 	{
				// 	// 		continue;
				// 	// 	}
				// 	// 	if (b < collision_box_t[c] || t > collision_box_b[c])
				// 	// 	{
				// 	// 		continue;
				// 	// 	}
				// 	// 	return c;
				// 	// }

				// }
			}
		}

		// write_stringf("a: %d", 0xFF, 0, c, character_anim[c]);
		// write_stringf("l: %d", 0xFF, 10, c, character_anim_locked[c]);
		// write_stringf("t: %d", 0xFF, 20, c, character_anim_timer[c]);
	}
}

void character_start_punch(unsigned char c)
{
	character_anim[c] = const_character_anim_oneshot;
	character_anim_rate[c] = const_character_anim_punch_rate;
	character_frame[c] = 6;
	character_frame_target[c] = 8;
	character_anim_locked[c] = 1;
	character_anim_timer[c] = 0;
	character_scheduled_attack[c] = const_character_attack_punch;
	character_scheduled_attack_in[c] = 2 * const_character_anim_punch_rate;
}
void character_start_kick(unsigned char c)
{
	character_anim[c] = const_character_anim_oneshot;
	character_anim_rate[c] = const_character_anim_kick_rate;
	character_frame[c] = 9;
	character_frame_target[c] = 11;
	character_anim_locked[c] = 1;
	character_anim_timer[c] = 0;
	character_scheduled_attack[c] = const_character_attack_kick;
	character_scheduled_attack_in[c] = 2 * const_character_anim_kick_rate;
}
void character_start_hit_high(unsigned char c)
{
	character_anim[c] = const_character_anim_oneshot;
	character_anim_rate[c] = const_character_anim_hit_high_rate;
	character_frame[c] = 12;
	character_frame_target[c] = 13;
	character_anim_locked[c] = 1;
	character_anim_timer[c] = 0;
}
void character_start_hit_mid(unsigned char c)
{
	character_anim[c] = const_character_anim_oneshot;
	character_anim_rate[c] = const_character_anim_hit_mid_rate;
	character_frame[c] = 14;
	character_frame_target[c] = 15;
	character_anim_locked[c] = 1;
	character_anim_timer[c] = 0;
}