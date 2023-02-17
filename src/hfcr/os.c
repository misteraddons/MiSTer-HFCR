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

	write_string("Hello wurld", 0xFF, 5, 10);

	write_string("0", 0xFF, 0, 0);
	write_string("1", 0xFF, 39, 0);
	write_string("2", 0xFF, 39, 29);
	write_string("3", 0xFF, 0, 29);

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
