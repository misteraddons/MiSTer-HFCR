/*============================================================================
	Aznable OS - Main application

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

#include "sys.h"
#include "ui.h"
#include "sprite.h"

#include "zorblaxx_app.h"

void startup()
{
	// Set charmap area
	chram_size = chram_cols * chram_rows;
	// Clear charmap
	clear_bgcolor(0);
	clear_chars(0);
	// Reset sprites
	clear_sprites();
	update_sprites();
	// Reset starfields
	for (unsigned char s = 0; s < 6; s++)
	{
		starfield[s] = 0;
	}

	// Intro sequence
	unsigned char text_timer = 0;
	unsigned char text_length = 0;
	unsigned char text_timer_max = 10;
	unsigned char text_flash = 0;
	unsigned char text_flash_timer = 0;
	unsigned char text_flash_max = 2;

	unsigned char text_char[] = {
		'A',
		'Z',
		'N',
		'A',
		'B',
		'L',
		'E'};

	// OS Intro
	while (1)
	{
		vblank = CHECK_BIT(input0, INPUT_VBLANK);

		if (VBLANK_RISING)
		{
			text_timer++;
			if (text_timer == text_timer_max)
			{
				write_char(text_char[text_length - 1], 0xFF, text_length * 2, 2);
				text_length++;
				if (text_length > sizeof(text_char))
				{
					break;
				}
				text_timer = 0;
			}
			text_flash_timer++;
			if (text_flash_timer == text_flash_max)
			{
				text_flash++;
				if (text_flash == 2)
				{
					text_flash = 0;
				}
				if (text_flash == 1)
				{
					clear_char_area(0, text_length * 2, 2, text_length * 2, 2);
				}
				else
				{
					write_char(text_char[text_length - 1], 0xFF, text_length * 2, 2);
				}
				text_flash_timer = 0;
			}
		}
		vblank_last = vblank;
	}

	// Clear title characters
	clear_char_area(0, sizeof(text_char), 2, sizeof(text_char), 2);
}

// Main entry
void main()
{
	// Run startup routine
	startup();

	// Launch Zorblaxx!
	app_zorblaxx();
}
