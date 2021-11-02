#pragma once
#include <stdbool.h>
#include "sys.c"
#include "ps2.c"

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
