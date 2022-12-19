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

extern bool character_active[];
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

#define const_character_idle 0

#define const_character_walk 1
#define const_character_walk_rate 4

#define const_character_run 2
#define const_character_run_rate 4

#define const_character_punch 3
#define const_character_punch_rate 5

#define const_character_kick 4
#define const_character_kick_rate 6

#define const_character_first_sprite_index 0

extern void activate_character(unsigned char c, unsigned char offset);
extern void deactivate_character(unsigned char c);

extern void update_characters();

extern void character_start_punch(unsigned char c);
extern void character_start_kick(unsigned char c);

#endif