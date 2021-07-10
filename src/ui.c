/*============================================================================
	Aznable OS - User interface functions

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

#pragma once
#include "sys.c"

char asc_0 = 48;
char asc_1 = 49;

// Set all character RAM to specified character
void clear_chars(char c)
{
	for (unsigned int p = 0; p < chram_size; p++)
	{
		chram[p] = c;
	}
}

// Set all character background colours to specified
void clear_bgcolor(char color)
{
	for (unsigned int p = 0; p < chram_size; p++)
	{
		bgcolram[p] = color;
	}
}


// Write string to character RAM
void write_string(const char *string, char color, unsigned int x, unsigned int y)
{
	unsigned int p = (y * chram_cols) + x;
	unsigned char l = strlen(string);
	for (char c = 0; c < l; c++)
	{
		chram[p] = string[c];
		fgcolram[p] = color;
		p++;
	}
}

// Write formatted string to character RAM (signed char data)
void write_stringfs(const char *format, char color, unsigned int x, unsigned int y, signed char data)
{
	unsigned int p = (y * chram_cols) + x;
	char temp[30];
	sprintf(temp, format, data);
	unsigned char l = strlen(temp);
	for (char c = 0; c < l; c++)
	{
		if (temp[c] == 0)
		{
			return;
		}
		chram[p] = temp[c];
		fgcolram[p] = color;
		p++;
	}
}

// Write formatted string to character RAM (unsigned char data)
void write_stringf(const char *format, char color, unsigned int x, unsigned int y, char data)
{
	unsigned int p = (y * chram_cols) + x;
	char temp[30];
	sprintf(temp, format, data);
	unsigned char l = strlen(temp);
	for (char c = 0; c < l; c++)
	{
		if (temp[c] == 0)
		{
			return;
		}
		chram[p] = temp[c];
		fgcolram[p] = color;
		p++;
	}
}

// Write single char to character RAM and colour RAM
void write_char(unsigned char c, char color, unsigned int x, unsigned int y)
{
	unsigned int p = (y * chram_cols) + x;
	chram[p] = c;
	fgcolram[p] = color;
}

// Write row of consecutive chars to character RAM and colour RAM
void write_char_row(unsigned char c, char color, unsigned int x, unsigned int y, unsigned int count)
{
	unsigned int p = (y * chram_cols) + x;
	for (char b = 0; b < count; b++)
	{
		chram[p] = c;
		fgcolram[p] = color;
		p++;
	}
}

// Set colour of single char
void set_fgcolour(char color, unsigned int x, unsigned int y)
{
	unsigned int p = (y * chram_cols) + x;
	fgcolram[p] = color;
}

// Write row of consecutive chars to character RAM and colour RAM
void write_bgcol_row(char color, unsigned int x, unsigned int y, unsigned int count)
{
	unsigned int p = (y * chram_cols) + x;
	for (char b = 0; b < count; b++)
	{
		bgcolram[p] = color;
		p++;
	}
}

// Write grouped bits to character RAM
void write_bits(char bits[], char multi, unsigned char first, unsigned char length, char color, unsigned int x, unsigned int y)
{
	for (char b = first; b < first + length; b++)
	{
		write_char((b) ? asc_1 : asc_0, color, x, y - 1);
		char m = 0b00000001;
		for (char i = 0; i < 8; i++)
		{
			write_char((bits[b * multi] & m) ? asc_1 : asc_0, color, x, y);
			x++;
			m <<= 1;
		}
		x++;
	}
}

// Draw box outline with specified character
void box(unsigned int tx, unsigned int ty, unsigned int bx, unsigned int by, char c, char color)
{
	for (unsigned int x = tx; x <= bx; x++)
	{
		write_char(c, color, x, ty);
		write_char(c, color, x, by);
	}
	for (unsigned int y = ty + 1; y < by; y++)
	{
		write_char(c, color, tx, y);
		write_char(c, color, bx, y);
	}
}

// Draw UI panel
void panel(char tx, char ty, char bx, char by, char color)
{
	write_char(128, color, tx, ty);
	write_char(130, color, bx, ty);
	write_char(133, color, tx, by);
	write_char(132, color, bx, by);
	for (char x = tx + 1; x < bx; x++)
	{
		write_char(129, color, x, ty);
		write_char(129, color, x, by);
	}
	for (char y = ty + 1; y < by; y++)
	{
		write_char(131, color, tx, y);
		write_char(131, color, bx, y);
	}
}

void fill(char tx, char ty, char bx, char by, char c, char color)
{
	for (char y = ty; y <= by; y++)
	{
		write_char_row(c, color, tx, y, bx-tx);
	}
}
void fill_bgcol(char tx, char ty, char bx, char by, char color)
{
	for (char y = ty; y <= by; y++)
	{
		write_bgcol_row(color, tx, y, bx-tx);
	}
}

// Draw page border
void page_border(char color)
{
	panel(0, 0, 39, 29, color);
}

char color_pad_outline = 0xFE;

// Draw game pad outline
void draw_pad(char xo, char yo)
{
	// Outline
	write_char(134, color_pad_outline, xo, yo + 1);
	for (char x = 1; x < 26; x++)
	{
		write_char(135, color_pad_outline, xo + x, yo + 1);
	}
	write_char(136, color_pad_outline, xo + 26, yo + 1);
	for (char y = 2; y < 5; y++)
	{
		write_char(137, color_pad_outline, xo, yo + y);
		write_char(137, color_pad_outline, xo + 26, yo + y);
	}
	write_char(139, color_pad_outline, xo, yo + 5);
	write_char(138, color_pad_outline, xo + 26, yo + 5);

	write_char(138, color_pad_outline, xo + 8, yo + 5);
	write_char(139, color_pad_outline, xo + 18, yo + 5);
	write_char(134, color_pad_outline, xo + 8, yo + 4);
	write_char(136, color_pad_outline, xo + 18, yo + 4);
	for (char x = 1; x < 8; x++)
	{
		write_char(135, color_pad_outline, xo + x, yo + 5);
	}
	for (char x = 9; x < 18; x++)
	{
		write_char(135, color_pad_outline, xo + x, yo + 4);
	}
	for (char x = 19; x < 26; x++)
	{
		write_char(135, color_pad_outline, xo + x, yo + 5);
	}
	// Shoulders
	write_char(134, color_pad_outline, xo + 1, yo);
	write_char(136, color_pad_outline, xo + 5, yo);
	write_char(134, color_pad_outline, xo + 21, yo);
	write_char(136, color_pad_outline, xo + 25, yo);
}

char color_analog_grid = 0x23;

// Draw game pad outline
void draw_analog(char xo, char yo, char xs, char ys)
{
	panel(xo, yo, xo + xs, yo + ys, 0xFF);
	fill(xo + 1, yo + 1, xo + xs - 1, yo + ys - 1, 27, color_analog_grid);
	char mx = xo + (xs / 2);
	char my = yo + (ys / 2);
	for (char x = xo + 1; x < xo + xs; x++)
	{
		write_char(129, color_analog_grid, x, my);
	}
	for (char y = yo + 1; y < yo + ys; y++)
	{
		write_char(131, color_analog_grid, mx, y);
	}
	write_char('+', color_analog_grid, mx, my);
}
