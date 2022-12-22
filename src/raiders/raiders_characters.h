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

#ifndef RAIDERS_CHARACTERS_H
#define RAIDERS_CHARACTERS_H

#define const_character_max 3

#define const_character_position_divider 4

extern bool character_active[];
extern unsigned char character_team[];
extern signed char character_dir[];
extern unsigned char character_anim[];
extern unsigned char character_frame[];
extern unsigned short character_x[];
extern unsigned short character_y[];
extern signed char character_move_x[];
extern signed char character_move_y[];
extern unsigned char character_sprite_offset[];
extern unsigned char character_anim_timer[];
extern unsigned char character_anim_dir[];
extern unsigned char character_anim_locked[];

extern unsigned char character_health[];
extern unsigned char character_hit_combo[];
extern unsigned char character_hit_combo_timer[];

#define const_character_anim_idle 0

#define const_character_anim_walk 1
#define const_character_anim_walk_rate 4
#define const_character_anim_run 2
#define const_character_anim_run_rate 4
#define const_character_anim_oneshot 3

#define const_character_anim_dead 4
#define const_character_anim_dead_rate 30

#define const_character_anim_punch_rate 6
#define const_character_anim_kick_rate 9
#define const_character_anim_uppercut_rate 7
#define const_character_anim_hit_high_rate 6
#define const_character_anim_hit_mid_rate 6
#define const_character_anim_fall_rate 14

#define const_character_attack_punch 1
#define const_character_attack_punch_knockback 4
#define const_character_attack_kick 2
#define const_character_attack_kick_knockback 8
#define const_character_attack_uppercut 3
#define const_character_attack_uppercut_knockback 20

#define const_character_first_sprite_index 0

extern void activate_character(unsigned char c, unsigned char offset, unsigned char team, unsigned char health);
extern void deactivate_character(unsigned char c);

extern void set_character_screen_position(unsigned char c, unsigned short x, unsigned short y);

extern void update_characters();

extern void character_start_punch(unsigned char c);
extern void character_start_kick(unsigned char c);
extern void character_start_uppercut(unsigned char c);
extern void character_start_hit_high(unsigned char c);
extern void character_start_hit_mid(unsigned char c);

#endif