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
#include "sys.c"
#include "ui.c"
#include "ps2.c"

bool hsync;
bool hsync_last;
bool vsync;
bool vsync_last;

// Console
unsigned char con_x;	  // Console cursor X position
unsigned char con_y;	  // Console cursor X position
unsigned char con_l = 1;  // Console left edge X
unsigned char con_t = 1; // Console top edge Y
unsigned char con_r = 38; // Console right edge X
unsigned char con_b = 28; // Console bottom edge Y
bool con_cursor;
unsigned char con_cursortimer = 1;
unsigned char con_cursorfreq = 30;

// Initialise console
void init_console()
{
	// Clear screen
	clear_chars(0x00);

	// Reset console cursor
	con_x = con_l;
	con_y = con_t;
}

// Console state
void console()
{

	// Handle PS/2 inputs whenever possible to improve latency
	handle_ps2();

	// As soon as vsync is detected start drawing screen updates
	if (vsync && !vsync_last)
	{

		// Check keyboard buffer for console write
		if (kbd_buffer_len > 0)
		{
			// Clear existing cursor if visible
			if (con_cursor)
			{
				write_char(' ', 0xFF, con_x, con_y);
			}
			// Write characters in buffer
			for (char k = 0; k < kbd_buffer_len; k++)
			{
				if (kbd_buffer[k] == '\n')
				{
					// New line
					con_x = con_l;
					con_y++;
					if (con_y > con_b)
					{
						// Wrap to top
						con_y = con_t;
					}
				}
				else if (kbd_buffer[k] == '\b')
				{
					// Backspace - only if not at beginning of line
					if (con_x > con_l)
					{
						con_x--;
						// Clear existing character
						write_char(' ', 0xFF, con_x, con_y);
					}
				}
				else
				{
					// Write character
					write_char(kbd_buffer[k], 0xFF, con_x, con_y);
					// Move cursor right
					con_x++;
					if (con_x > con_r)
					{
						// New line
						con_x = con_l;
						con_y++;
						if (con_y > con_b)
						{
							// Wrap to top
							con_y = con_t;
						}
					}
				}
			}
			// Clear buffer and enable cursor
			kbd_buffer_len = 0;
			con_cursor = 0;
			con_cursortimer = 1;
		}

		// Cursor blink timer
		con_cursortimer--;
		if (con_cursortimer <= 0)
		{
			con_cursor = !con_cursor;
			con_cursortimer = con_cursorfreq;
			write_char(con_cursor ? '|' : ' ', 0xFF, con_x, con_y);
		}
	}
}

// Main entry and state machine
void main()
{
	chram_size = chram_cols * chram_rows;

	init_console();

	while (1)
	{
		hsync = input0 & 0x80;
		vsync = input0 & 0x40;

		console();

		hsync_last = hsync;
		vsync_last = vsync;
	}
}
