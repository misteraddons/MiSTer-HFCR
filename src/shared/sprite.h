/*============================================================================
	Aznable OS - Casval (sprite engine)

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
#ifndef SPRITE_H
#define SPRITE_H

extern unsigned char sprite_max;
extern bool spr_on[];
extern bool spr_collide[];
extern bool spr_mirror[];
extern unsigned char spr_palette_index[];
extern unsigned char spr_index[];
extern unsigned char spr_size[];

extern void set_sprite_position(unsigned char sprite, unsigned short x, unsigned short y);

extern void set_sprite_position_x(unsigned char sprite, unsigned short x);

extern void set_sprite_position_y(unsigned char sprite, unsigned short y);

extern void init_sprites();

extern void sort_sprites();

extern void update_sprites();

extern void enable_sprite(unsigned char sprite, unsigned char palette_index, unsigned char size, unsigned char collide);

extern void set_sprite_mirror(unsigned char sprite, unsigned char value);

extern void clear_sprites();

extern void clear_sprites_range(unsigned char first, unsigned char last);

#endif