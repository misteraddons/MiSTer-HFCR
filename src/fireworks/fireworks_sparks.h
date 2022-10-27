/*============================================================================
	Aznable OS - Fireworks demo - Sparks

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

#ifndef FIREWORKS_SPARKS_H
#define FIREWORKS_SPARKS_H

// Sparks
extern unsigned char spark_max;
extern unsigned short spark_x[];
extern unsigned short spark_y[];
extern signed char spark_xs[];
extern signed char spark_ys[];
extern unsigned char spark_timer[];
extern unsigned short spark_y_max;

extern void setup_sparks();

extern void add_spark(unsigned short x, unsigned short y, unsigned char t);

extern void handle_sparks();

#endif