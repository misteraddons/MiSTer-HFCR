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

// Console
unsigned char con_x;	  // Console cursor X position
unsigned char con_y;	  // Console cursor X position
unsigned char con_l = 1;  // Console left edge X
unsigned char con_t = 1;  // Console top edge Y
unsigned char con_r = 38; // Console right edge X
unsigned char con_b = 28; // Console bottom edge Y
bool con_cursor;
unsigned char con_cursortimer = 1;
unsigned char con_cursorfreq = 30;
unsigned char con_fgcol = 0b00000110;
unsigned char con_bgcol = 0;

// Initialise console
void init_console()
{
	// Clear screen
	clear_chars(0);
	clear_bgcolor(con_bgcol);

	// Write title
	write_string("SPRITE-TEST", con_fgcol, 1, 1);

	// Reset console cursor
	con_x = con_l + 1;
	con_y = con_t + 3;
}

// Console state
void console()
{

	// Handle PS/2 inputs whenever possible to improve latency
	handle_ps2();

	// As soon as vblank is detected start drawing screen updates
	if (VBLANK_RISING)
	{

		// Check keyboard buffer for console write
		if (kbd_buffer_len > 0)
		{
			// Clear existing cursor if visible
			if (con_cursor)
			{
				write_char(' ', con_fgcol, con_x, con_y);
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
						write_char(' ', con_fgcol, con_x, con_y);
					}
				}
				else
				{
					// Write character
					write_char(kbd_buffer[k], con_fgcol, con_x, con_y);
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
			write_char(con_cursor ? '|' : ' ', con_fgcol, con_x, con_y);
		}
	}
}

#define const_sprite_max 32
unsigned char sprite_max = const_sprite_max;
unsigned short x[const_sprite_max];
unsigned short x_h[const_sprite_max];
unsigned short y[const_sprite_max];
signed char xs[const_sprite_max];
bool active[const_sprite_max];
unsigned char i[const_sprite_max];

unsigned short x_h_min;
unsigned short x_h_max;

unsigned char image_count = 5;

void setup_sprites()
{
	unsigned char s = 0;
	for (unsigned char sprite = 0; sprite < sprite_max; sprite++)
	{
		spriteram[s++] = (active[sprite] ? 1 : 0) << 7 | y[sprite] >> 8; // Enabled + Position Y (upper 4 bits)
		spriteram[s++] = (unsigned char)y[sprite];						 // Position Y (lower 8 bits)
		spriteram[s++] = i[sprite] << 4 | x[sprite] >> 8;				 // Sprite Index (4 bits) + Position X (upper 4 bits)
		spriteram[s++] = (unsigned char)x[sprite];						 // Position X (lower 8 bits)
	}
}

const signed char player_max_speed = 20;
const unsigned char player_accel = 3;
const unsigned char x_divisor = 16;

// Main entry and state machine
void main()
{
	chram_size = chram_cols * chram_rows;

	// init_console();

	// panel(0, 0, 39, 2, 0b00000100);
	// panel(0, 3, 39, 29, 0b00000100);
	clear_bgcolor(0);
	clear_chars(0);

	// setup sprites
	x_h_min = (unsigned short)(2 * x_divisor);
	x_h_max = (unsigned short)(336 * x_divisor);
	for (unsigned char c = 0; c < sprite_max; c++)
	{
		x_h[c] = ((unsigned char)rand() + 16) * x_divisor;
		y[c] = (unsigned char)rand() + 16;
		xs[c] = (signed char)rand() / 16;
		i[c] = 0;
		active[c] = true;
	}

	//
	i[0] = 1;
	x_h[0] = 160 * x_divisor;
	y[0] = 216;

	unsigned short t1;
	unsigned short t2;

	while (1)
	{
		hsync = input0 & 0x80;
		vsync = input0 & 0x40;
		hblank = input0 & 0x20;
		vblank = input0 & 0x10;

		// console();

		if (VBLANK_RISING)
		{
			t1 = GET_TIMER;
			unsigned char s = 0;
			setup_sprites();
			t2 = GET_TIMER;
			write_stringf_ushort("s-upd: %4d us", 0xFF, 0, 28, t2 - t1);
		}

		if (VBLANK_FALLING)
		{
			if (xs[0] > 0)
			{
				xs[0]--;
			}
			if (xs[0] < 0)
			{
				xs[0]++;
			}
			if (CHECK_BIT(joystick[0], 1) && xs[0] > -player_max_speed)
			{
				xs[0] -= player_accel;
			}
			if (CHECK_BIT(joystick[0], 0) && xs[0] < player_max_speed)
			{
				xs[0] += player_accel;
			}
			i[0] = xs[0]<-2 ? 2 : xs[0]>2 ? 3 : 1;

			t1 = GET_TIMER;
			for (unsigned char sprite = 0; sprite < sprite_max; sprite++)
			{
				x_h[sprite] += xs[sprite];
				if (x_h[sprite] < x_h_min)
				{
					x_h[sprite] = x_h_max;
				}
				if (x_h[sprite] > x_h_max)
				{
					x_h[sprite] = x_h_min;
				}
				if (sprite > 0)
				{
					if (y[sprite] == 256)
					{
						y[sprite] = 0;
					}
					else
					{
						y[sprite]++;
					}
				}
				x[sprite] = x_h[sprite] / x_divisor;
			}
			t2 = GET_TIMER;
			write_stringf_ushort("s-set: %4d us", 0xFF, 0, 29, t2 - t1);
		}

		hsync_last = hsync;
		vsync_last = vsync;
		hblank_last = hblank;
		vblank_last = vblank;
	}
}
