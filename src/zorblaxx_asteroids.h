
/*============================================================================
	Aznable OS - Zorblaxx demo application - Asteroid routines

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

#ifndef ZORBLAXX_ASTEROIDS_H
#define ZORBLAXX_ASTEROIDS_H

extern unsigned char meteor_max;
extern unsigned char meteor_sprite_first;
extern unsigned char meteor_sprite_palette;
extern unsigned short meteor_x[];
extern unsigned short meteor_y[];
extern signed char meteor_xs[];
extern signed char meteor_ys[];
extern unsigned char meteor_timer[];
extern unsigned short meteor_y_max;
extern unsigned char meteor_active_max;
extern unsigned char meteor_difficulty;
extern unsigned short meteor_difficulty_timer;
extern unsigned short meteor_difficulty_frequency;

extern void update_meteordifficulty();

extern void setup_meteors();

extern void handle_meteors();

#endif