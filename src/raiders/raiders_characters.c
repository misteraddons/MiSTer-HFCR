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
#include "collision_boxes.h"
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
unsigned char character_z[const_character_max];
signed char character_move_x[const_character_max];
signed char character_move_y[const_character_max];
signed char character_move_z[const_character_max];
unsigned char character_sprite_offset[const_character_max];
unsigned char character_anim_timer[const_character_max];
unsigned char character_anim_dir[const_character_max];
unsigned char character_anim_locked[const_character_max];

unsigned char character_health[const_character_max];
unsigned char character_scheduled_attack[const_character_max];
unsigned char character_scheduled_attack_in[const_character_max];
unsigned char character_hit_combo[const_character_max];
unsigned char character_hit_combo_timer[const_character_max];

#define const_character_sprite_palette sprite_palette_alex
#define const_character_sprite_size sprite_size_alex

void activate_character(unsigned char c, unsigned char offset, unsigned char team, unsigned char health)
{
	character_active[c] = true;
	enable_sprite(const_character_first_sprite_index + c, const_character_sprite_palette, const_character_sprite_size, 0);
	character_sprite_offset[c] = offset;
	character_team[c] = team;
	character_health[c] = health;
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
		if (character_frame[c] < character_frame_target[c])
		{
			character_frame[c]++;
		}
		if (character_frame[c] == character_frame_target[c])
		{
			if (character_health[c] > 0)
			{
				character_anim[c] = const_character_anim_idle;
				character_anim_timer[c] = character_anim_rate[c];
			}
			else
			{
				character_anim[c] = const_character_anim_dead;
				character_anim_timer[c] = const_character_anim_dead_rate;
				character_anim_dir[c] = const_character_anim_dead_flashcount; // Re-use anim direction for number of flashes before character is culled
			}
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

unsigned char collisionbox_aabb_check(unsigned short x, unsigned short y)
{
	unsigned short l = (x / const_character_position_divider) + 6;
	unsigned short r = l + 18;
	unsigned short t = (y / const_character_position_divider) + 26;
	unsigned short b = t + 6;

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

void character_start_punch(unsigned char c)
{
	character_anim[c] = const_character_anim_oneshot;
	character_anim_rate[c] = const_character_anim_punch_rate;
	character_frame[c] = const_character_frame_punch_first;
	character_frame_target[c] = const_character_frame_punch_first + const_character_frame_punch_count - 1;
	character_anim_locked[c] = 1;
	character_anim_timer[c] = character_anim_rate[c];
	character_scheduled_attack[c] = const_character_attack_punch;
	character_scheduled_attack_in[c] = const_character_attack_punch_hittime;
}
void character_start_kick(unsigned char c)
{
	character_anim[c] = const_character_anim_oneshot;
	character_anim_rate[c] = const_character_anim_kick_rate;
	character_frame[c] = const_character_frame_kick_first;
	character_frame_target[c] = const_character_frame_kick_first + const_character_frame_kick_count - 1;
	character_anim_locked[c] = 1;
	character_anim_timer[c] = character_anim_rate[c];
	character_scheduled_attack[c] = const_character_attack_kick;
	character_scheduled_attack_in[c] = const_character_attack_kick_hittime;
}
void character_start_uppercut(unsigned char c)
{
	character_anim[c] = const_character_anim_oneshot;
	character_anim_rate[c] = const_character_anim_uppercut_rate;
	character_frame[c] = const_character_frame_uppercut_first;
	character_frame_target[c] = const_character_frame_uppercut_first + const_character_frame_uppercut_count - 1;
	character_anim_locked[c] = 1;
	character_anim_timer[c] = character_anim_rate[c];
	character_scheduled_attack[c] = const_character_attack_uppercut;
	character_scheduled_attack_in[c] = const_character_attack_uppercut_hittime;
}
void character_start_powerkick(unsigned char c)
{
	character_anim[c] = const_character_anim_oneshot;
	character_anim_rate[c] = const_character_anim_powerkick_rate;
	character_frame[c] = const_character_frame_powerkick_first;
	character_frame_target[c] = const_character_frame_powerkick_first + const_character_frame_powerkick_count - 1;
	character_anim_locked[c] = 1;
	character_anim_timer[c] = character_anim_rate[c];
	character_scheduled_attack[c] = const_character_attack_powerkick;
	character_scheduled_attack_in[c] = const_character_attack_powerkick_hittime;
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

void character_start_fall(unsigned char c)
{
	character_anim[c] = const_character_anim_oneshot;
	character_anim_rate[c] = const_character_anim_fall_rate;
	character_frame[c] = 15;
	character_frame_target[c] = const_character_frame_dead;
	character_anim_locked[c] = 1;
	character_anim_timer[c] = character_anim_rate[c];
}

void update_characters()
{
	for (unsigned char c = 0; c < const_character_max; c++)
	{
		if (!character_active[c])
		{
			continue;
		}

		unsigned char player_sprite = const_character_first_sprite_index + c;

		// Handle character movement
		unsigned char xc = collisionbox_aabb_check(character_x[c] + character_move_x[c], character_y[c]);
		unsigned char yc = collisionbox_aabb_check(character_x[c], character_y[c] + character_move_y[c]);
		if (xc == 255)
		{
			character_x[c] += character_move_x[c];
		}
		if (yc == 255)
		{
			character_y[c] += character_move_y[c];
		}

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

		// Combo timers
		if (character_hit_combo_timer[c] > 0)
		{
			character_hit_combo_timer[c]--;
			if (character_hit_combo_timer[c] == 0)
			{
				character_hit_combo[c] = 0;
			}
		}

		// Handle character animations
		if (character_anim_timer[c] > 0)
		{
			character_anim_timer[c]--;
			if (character_anim_timer[c] == 0 && character_anim[c] == const_character_anim_idle)
			{
				character_anim_locked[c] = 0;
			}
		}

		if (character_anim_timer[c] == 0)
		{
			switch (character_anim[c])
			{
			case const_character_anim_idle:
				character_frame[c] = const_character_frame_idle;
				break;
			case const_character_anim_walk:
				if (character_frame[c] > const_character_frame_walk_last)
				{
					character_frame[c] = const_character_frame_walk_first;
					character_anim_dir[c] = 0;
				}
				if (character_anim_timer[c] == 0)
				{
					character_anim_timer[c] = const_character_anim_walk_rate;
					if (character_anim_dir[c] == 0)
					{
						character_frame[c]++;
						if (character_frame[c] == const_character_frame_walk_last)
						{
							character_anim_dir[c] = 1;
						}
					}
					else
					{
						character_frame[c]--;
						if (character_frame[c] == const_character_frame_walk_first)
						{
							character_anim_dir[c] = 0;
						}
					}
				}
				break;
			case const_character_anim_run:
				character_anim_timer[c] = const_character_anim_run_rate;
				character_frame[c] = character_frame[c] == const_character_frame_idle ? const_character_frame_run : const_character_frame_idle;
				break;
			case const_character_anim_oneshot:
				character_anim_oneshot(c);
				break;
			case const_character_anim_dead:
				character_anim_timer[c] = const_character_anim_dead_rate;
				character_anim_dir[c]--;
				if (character_anim_dir[c] == 0)
				{
					deactivate_character(c);
				}
				else
				{
					spr_on[player_sprite] = !spr_on[player_sprite];
				}
				break;
			}
		}

		// Draw character sprite
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
				unsigned char d = character_dir[c];

				unsigned short hit_mid_x = (character_x[c] / const_character_position_divider) + 16;
				unsigned short hit_mid_y = (character_y[c] / const_character_position_divider) + 32;

				unsigned char hit_rad_x = 4;
				unsigned char hit_rad_y = 2;
				switch (character_scheduled_attack[c])
				{
				case const_character_attack_punch:
					hit_mid_x += d == 1 ? 11 : -11;
					break;
				case const_character_attack_kick:
					hit_mid_x += d == 1 ? 12 : -12;
					hit_rad_y = 3;
					break;
				case const_character_attack_uppercut:
					hit_mid_x += d == 1 ? 11 : -11;
					hit_rad_x = 5;
					hit_rad_y = 3;
					break;
				case const_character_attack_powerkick:
					hit_mid_x += d == 1 ? 12 : -12;
					hit_rad_x = 5;
					hit_rad_y = 3;
					break;
				}

				unsigned short hit_x_min = hit_mid_x - hit_rad_x;
				unsigned short hit_y_min = hit_mid_y - hit_rad_y;
				unsigned short hit_x_max = hit_mid_x + hit_rad_x;
				unsigned short hit_y_max = hit_mid_y + hit_rad_y;

				bool add_combo = false;
				for (unsigned char tc = 0; tc < const_character_max; tc++)
				{
					if (tc == c || character_team[c] == character_team[tc] || character_health[tc] == 0)
					{
						continue;
					}

					unsigned short mid_x = (character_x[tc] / const_character_position_divider) + 16;
					unsigned short mid_y = (character_y[tc] / const_character_position_divider) + 32;

					unsigned short l = mid_x - 5;
					unsigned short r = mid_x + 5;
					unsigned short t = mid_y - 5;
					unsigned short b = mid_y + 5;
					if (r < hit_x_min || l > hit_x_max)
					{
						continue;
					}
					if (b < hit_y_min || t > hit_y_max)
					{
						continue;
					}

					signed hit_direction = character_x[c] < character_x[tc] ? 1 : -1;
					unsigned char hit_power = 0;

					switch (character_scheduled_attack[c])
					{
					case const_character_attack_punch:
						character_start_hit_high(tc);
						hit_power = const_character_attack_punch_knockback;
						add_combo = true;
						break;
					case const_character_attack_kick:
						character_start_hit_mid(tc);
						hit_power = const_character_attack_kick_knockback;
						add_combo = true;
						break;
					case const_character_attack_uppercut:
						character_start_hit_high(tc);
						hit_power = const_character_attack_uppercut_knockback;
						break;
					case const_character_attack_powerkick:
						character_start_hit_high(tc);
						hit_power = const_character_attack_powerkick_knockback;
						break;
					}

					character_move_x[tc] = hit_direction * hit_power;

					// Reduce health
					if (character_health[tc] > hit_power)
					{
						character_health[tc] -= hit_power;
					}
					else
					{
						character_start_fall(tc);
						character_health[tc] = 0;
					}

					// Cancel any pending attack on character
					character_scheduled_attack[tc] = 0;
					character_scheduled_attack_in[tc] = 0;
				}

				if (add_combo)
				{
					character_hit_combo[c]++;
					character_hit_combo_timer[c] = 45;
				}
			}
		}
		// write_stringf_ushort("x: %4d", 0xFF, 0, c, character_x[c]);
		// write_stringf_ushort("y: %4d", 0xFF, 10, c, character_y[c]);
		// write_stringf("hc: %3d", 0xFF, 0, c, character_hit_combo[c]);
		// write_stringf("hct: %3d", 0xFF, 10, c, character_hit_combo_timer[c]);
		// write_stringf("a: %3d", 0xFF, 0, c, character_anim[c]);
		// write_stringf("l: %3d", 0xFF, 7, c, character_anim_locked[c]);
		// write_stringf("t: %3d", 0xFF, 14, c, character_anim_timer[c]);
		// write_stringf("a: %3d", 0xFF, 21, c, character_scheduled_attack_in[c]);
	}
}
