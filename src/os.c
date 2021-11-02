/*============================================================================
	Aznable OS - Main application

	Author: Jim Gregory - https://github.com/JimmyStones/
	Version: 1.0
	Date: 2021-07-03

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

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "sys.c"
//#include "sys_custom.c"
#include "ps2.c"
#include "ui.c"
//#include "ui_custom.c"
#include "sprite.c"
//#include "app_console.c"
#include "app_meteorstorm.c"

// Main entry and state machine
void main()
{
	// Setup charmap
	chram_size = chram_cols * chram_rows;
	clear_bgcolor(0);
	clear_chars(0);

	setup_area();
	setup_meteors();
	setup_player();

	unsigned short t1;
	unsigned short t2;

	while (1)
	{
		//hsync = input0 & 0x80;
		//vsync = input0 & 0x40;
		//hblank = input0 & 0x20;
		vblank = input0 & 0x10;

		// console();


		if (VBLANK_RISING)
		{
			unsigned char debug_y = 25;
			t1 = GET_TIMER;
			unsigned char s = 0;
			update_sprites();
			t2 = GET_TIMER;
			write_stringf_ushort("spr: %4d us", 0b01011011, 0, debug_y++, t2 - t1);
		}

		if (VBLANK_FALLING)
		{
			unsigned char debug_y = 26;
			
			t1 = GET_TIMER;
			handle_player();
			t2 = GET_TIMER;
			write_stringf_ushort("ply: %4d us", 0b01011011, 0, debug_y++, t2 - t1);

			t1 = GET_TIMER;
			handle_trails();
			t2 = GET_TIMER;
			write_stringf_ushort("trl: %4d us", 0b01011011, 0, debug_y++, t2 - t1);

			t1 = GET_TIMER;
			handle_meteors();
			t2 = GET_TIMER;
			write_stringf_ushort("met: %4d us", 0b01011011, 0, debug_y++, t2 - t1);
		}

		//hsync_last = hsync;
		//vsync_last = vsync;
		//hblank_last = hblank;
		vblank_last = vblank;
	}
}
