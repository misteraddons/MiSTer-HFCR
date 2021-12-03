/*============================================================================
	Aznable OS - PS/2 interface functions

	Author: Jim Gregory - https://github.com/JimmyStones/
	Version: 1.1
	Date: 2021-10-20

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
#ifndef PS2_H
#define PS2_H

#include "sys.h"

extern char kbd_shift_left;
extern char kbd_shift_right;
extern char kbd_scan;
extern char kbd_pressed;
extern char kbd_extend;
extern char kbd_ascii;

extern bool mse_changed;
extern signed char mse_x;
extern signed char mse_y;
extern signed char mse_w;
extern char mse_button1;
extern char mse_button2;

extern char kbd_buffer[128];
extern char kbd_buffer_len;
extern bool kbd_down[256];

extern void get_ascii();

extern void handle_ps2();

#endif