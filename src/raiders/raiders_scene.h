/*============================================================================
	Aznable OS - Raiders demo - Scene controller

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

#ifndef RAIDERS_SCENE_H
#define RAIDERS_SCENE_H

extern signed char scene_offset_x;
extern signed char scene_offset_y;
extern unsigned short scroll_x;
extern unsigned short scroll_x_max;
extern unsigned char scroll_move_max;

extern void init_scene();

extern void update_tilemap();

#endif