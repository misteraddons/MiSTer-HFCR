/*============================================================================
	Aznable OS - Input Tester main application

	Author: Jim Gregory - https://github.com/JimmyStones/
	Version: 1.1
	Date: 2022-01-07

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

// Main entry and state machine
void app_main()
{
	chram_size = chram_cols * chram_rows;

	clear_chars(0);
	clear_bgcolor(6);
	bool yes = true;
	for (unsigned char y = 0; y < 30; y++)
	{
		for (unsigned char x = 0; x < 40; x++)
		{
			if (yes)
			{
				set_bgcolour(7, x, y);
			}
			yes = !yes;
		}
		yes = !yes;
	}

	set_char_palette(1, 255, 255, 255);
	set_char_palette(2, 255, 0, 0);
	set_char_palette(3, 0, 255, 0);
	set_char_palette(4, 0, 0, 255);
	set_char_palette(5, 255, 0, 255);

	set_char_palette(6, 140, 128, 128);
	set_char_palette(7, 50, 50, 70);

	write_string("Hello wurld", 1, 5, 10);

	write_string("0", 2, 0, 0);
	write_string("1", 3, 39, 0);
	write_string("2", 4, 39, 29);
	write_string("3", 5, 0, 29);

	while (1)
	{
		hsync = input0 & 0x80;
		vsync = input0 & 0x40;
		hblank = input0 & 0x20;
		vblank = CHECK_BIT(input0, INPUT_VBLANK);

		hsync_last = hsync;
		vsync_last = vsync;
		hblank_last = hblank;
		vblank_last = vblank;
	}
}

// Main entry
void main()
{
	app_main();
}
