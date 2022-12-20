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
unsigned char character_team[const_character_max];
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

void activate_character(unsigned char c, unsigned char offset, unsigned char team)
{
	character_active[c] = true;
	enable_sprite(const_character_first_sprite_index + c, const_character_sprite_palette, const_character_sprite_size, 0);
	character_sprite_offset[c] = offset;
	character_team[c] = team;
}

void deactivate_character(unsigned char c)
{
	character_active[c] = false;
	spr_on[const_character_first_sprite_index + c] = false;
}

void character_anim_oneshot(unsigned char c)
{
	if (character_anim_timer[c] == 0)
	{
		character_frame[c]++;
		if (character_frame[c] >= character_frame_target[c])
		{
			character_anim[c] = const_character_anim_idle;
			character_anim_timer[c] = character_anim_rate[c];
		}
		else
		{
			character_anim_timer[c] = character_anim_rate[c];
		}
	}
}

void set_character_screen_position(unsigned char c, unsigned short x, unsigned short y)
{
	character_x[c] = 32 + (x * const_character_position_divider);
	character_y[c] = 32 + (y * const_character_position_divider);
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

		// Decrement speed
		if (character_move_x[c] > 0)
		{
			character_move_x[c]--;
		}
		if (character_move_x[c] < 0)
		{
			character_move_x[c]++;
		}
		if (character_move_y[c] > 0)
		{
			character_move_y[c]--;
		}
		if (character_move_y[c] < 0)
		{
			character_move_y[c]++;
		}

		// Handle character animations
		if (character_anim_timer[c] > 0)
		{
			character_anim_timer[c]--;
			if (character_anim[c] == const_character_anim_idle)
			{
				character_anim_locked[c] = 0;
			}
		}

		switch (character_anim[c])
		{
		case const_character_anim_idle:
			character_frame[c] = 1;
			break;
		case const_character_anim_walk:
			if (character_frame[c] > 2)
			{
				character_frame[c] = 0;
				character_anim_dir[c] = 0;
			}
			if (character_anim_timer[c] == 0)
			{
				character_anim_timer[c] = const_character_anim_walk_rate;
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
			if (character_anim_timer[c] == 0)
			{
				character_anim_timer[c] = const_character_anim_run_rate;
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
		unsigned short x = (character_x[c] / const_character_position_divider) - scroll_x;
		unsigned short y = (character_y[c] / const_character_position_divider);
		if (character_frame[c] == 0 || character_frame[c] == 2 || character_frame[c] == 3)
		{
			y--;
		}
		set_sprite_position(player_sprite, x, y);

		// Handle attacks

		if (character_scheduled_attack_in[c] > 0)
		{
			character_scheduled_attack_in[c]--;
			if (character_scheduled_attack_in[c] == 0)
			{
				// find characters to hit

				unsigned short hit_x = character_x[c] / const_character_position_divider;
				unsigned short hit_y = character_y[c] / const_character_position_divider;
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

				unsigned short hit_x_max = hit_x + 16;
				unsigned short hit_y_max = hit_y + 16;

				for (unsigned char tc = 0; tc < const_character_max; tc++)
				{
					if (tc == c || character_team[c] == character_team[tc])
					{
						continue;
					}

					unsigned short l = (character_x[tc] / const_character_position_divider) + 10;
					unsigned short r = l + 10;
					unsigned short t = (character_y[tc] / const_character_position_divider) + 8;
					unsigned short b = t + 16;
					if (r < hit_x || l > hit_x_max)
					{
						continue;
					}
					if (b < hit_y || t > hit_y_max)
					{
						continue;
					}

					signed hit_direction = character_x[c] < character_x[tc] ? 1 : -1;

					switch (character_scheduled_attack[c])
					{
					case const_character_attack_punch:
						character_start_hit_high(tc);
						character_move_x[tc] = hit_direction * const_character_attack_punch_knockback;
						break;
					case const_character_attack_kick:
						character_start_hit_mid(tc);
						character_move_x[tc] = hit_direction * const_character_attack_kick_knockback;
						break;
					}
					character_scheduled_attack[tc] = 0;
					character_scheduled_attack_in[tc] = 0;

					// write_stringf("HIT %d", 0xFf, 0, c, tc);
					// unsigned char s = tc + 10;
					// enable_sprite(s, sprite_palette_hit, sprite_size_hit, 0);
					// set_sprite_position(s, hit_x, hit_y);
					// spr_index[s] = sprite_index_hit_first;
				}
			}
		}
		// write_stringf("a: %3d", 0xFF, 0, c, character_anim[c]);
		// write_stringf("l: %3d", 0xFF, 7, c, character_anim_locked[c]);
		// write_stringf("t: %3d", 0xFF, 14, c, character_anim_timer[c]);
		// write_stringf("a: %3d", 0xFF, 21, c, character_scheduled_attack_in[c]);
	}
}

void character_start_punch(unsigned char c)
{
	character_anim[c] = const_character_anim_oneshot;
	character_anim_rate[c] = const_character_anim_punch_rate;
	character_frame[c] = 6;
	character_frame_target[c] = 8;
	character_anim_locked[c] = 1;
	character_anim_timer[c] = character_anim_rate[c];
	character_scheduled_attack[c] = const_character_attack_punch;
	character_scheduled_attack_in[c] = 2 * character_anim_rate[c];
}
void character_start_kick(unsigned char c)
{
	character_anim[c] = const_character_anim_oneshot;
	character_anim_rate[c] = const_character_anim_kick_rate;
	character_frame[c] = 9;
	character_frame_target[c] = 11;
	character_anim_locked[c] = 1;
	character_anim_timer[c] = character_anim_rate[c];
	character_scheduled_attack[c] = const_character_attack_kick;
	character_scheduled_attack_in[c] = 2 * character_anim_rate[c];
}
void character_start_hit_high(unsigned char c)
{
	character_anim[c] = const_character_anim_oneshot;
	character_anim_rate[c] = const_character_anim_hit_high_rate;
	character_frame[c] = 14;
	character_frame_target[c] = 14;
	character_anim_locked[c] = 1;
	character_anim_timer[c] = character_anim_rate[c];
}
void character_start_hit_mid(unsigned char c)
{
	character_anim[c] = const_character_anim_oneshot;
	character_anim_rate[c] = const_character_anim_hit_mid_rate;
	character_frame[c] = 12;
	character_frame_target[c] = 12;
	character_anim_locked[c] = 1;
	character_anim_timer[c] = character_anim_rate[c];
}