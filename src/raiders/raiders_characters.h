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

#define const_character_max 8

#define const_character_position_divider 4

extern bool character_active[];
extern unsigned char character_team[];
extern signed char character_dir[];
extern unsigned char character_anim[];
extern unsigned char character_frame[];
extern unsigned short character_x[];
extern unsigned short character_y[];
extern signed char character_z[];
extern bool character_onground[];
extern signed char character_move_x[];
extern signed char character_move_y[];
extern signed char character_move_z[];
extern unsigned char character_sprite_offset[];
extern unsigned char character_anim_timer[];
extern unsigned char character_anim_dir[];
extern unsigned char character_anim_locked[];

extern unsigned char character_health[];
extern unsigned char character_stun[];
extern unsigned char character_hit_combo[];
extern unsigned char character_hit_combo_timer[];

#define const_character_anim_idle 0
#define const_character_frame_idle 1

#define const_character_anim_walk 1
#define const_character_anim_walk_rate 4
#define const_character_frame_walk_first 0
#define const_character_frame_walk_last 2

#define const_character_anim_run 2
#define const_character_anim_run_rate 4
#define const_character_frame_run 3

#define const_character_anim_oneshot 3

#define const_character_anim_dead 4
#define const_character_anim_dead_rate 30
#define const_character_frame_dead 16
#define const_character_anim_dead_flashcount 4

#define const_character_anim_jump 5
#define const_character_anim_jump_rate 5
#define const_character_frame_jump_first 17

#define const_character_frame_land_first 18
#define const_character_frame_land_count 1
#define const_character_anim_land_rate 5

#define const_character_anim_prone 6

#define const_character_anim_punch_rate 8
#define const_character_anim_kick_rate 10
#define const_character_anim_uppercut_rate 7
#define const_character_anim_powerkick_rate 8
#define const_character_anim_hit_high_rate 7
#define const_character_frame_hit_high_first 14
#define const_character_frame_hit_high_count 1
#define const_character_anim_hit_mid_rate 7
#define const_character_frame_hit_mid_first 12
#define const_character_frame_hit_mid_count 2
#define const_character_anim_fall_rate 14
#define const_character_frame_fall_first 15
#define const_character_frame_fall_count 2

#define const_character_attack_punch 1
#define const_character_attack_punch_knockback 4
#define const_character_attack_punch_hittime 18
#define const_character_frame_punch_first 6
#define const_character_frame_punch_count 3
#define const_character_hitoffset_punch_x 14
#define const_character_hitoffset_punch_y 14
#define const_character_attack_kick 2
#define const_character_attack_kick_knockback 8
#define const_character_attack_kick_hittime 17
#define const_character_frame_kick_first 9
#define const_character_frame_kick_count 3
#define const_character_hitoffset_kick_x 16
#define const_character_hitoffset_kick_y 18
#define const_character_attack_uppercut 3
#define const_character_attack_uppercut_knockback 11
#define const_character_attack_uppercut_liftup 8
#define const_character_attack_uppercut_hittime 11
#define const_character_frame_uppercut_first 20
#define const_character_frame_uppercut_count 3
#define const_character_hitoffset_uppercut_x 14
#define const_character_hitoffset_uppercut_y 14
#define const_character_attack_powerkick 4
#define const_character_attack_powerkick_knockback 16
#define const_character_attack_powerkick_liftup 10
#define const_character_attack_powerkick_hittime 6
#define const_character_frame_powerkick_first 23
#define const_character_frame_powerkick_count 1
#define const_character_hitoffset_powerkick_x 16
#define const_character_hitoffset_powerkick_y 12

#define const_character_sprite_palette sprite_palette_rota
#define const_character_sprite_size sprite_size_rota
#define const_character_first_sprite_index 0


extern void activate_character(unsigned char c, unsigned char offset, unsigned char team, unsigned char health);
extern void deactivate_character(unsigned char c);

extern void set_character_screen_position(unsigned char c, unsigned short x, unsigned short y);

extern void update_characters();

extern void character_start_punch(unsigned char c);
extern void character_start_kick(unsigned char c);
extern void character_start_uppercut(unsigned char c);
extern void character_start_powerkick(unsigned char c);
extern void character_start_hit_high(unsigned char c);
extern void character_start_hit_mid(unsigned char c);
extern void character_start_jump(unsigned char c);

#endif