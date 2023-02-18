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
#include "hfcr_data.h"

// DPAD tracker
bool input_left = 0;
bool input_left_last = 0;
bool input_right = 0;
bool input_right_last = 0;
bool input_up = 0;
bool input_up_last = 0;
bool input_down = 0;
bool input_down_last = 0;
bool input_a;
bool input_a_last = 0;

// Track joypad 1 directions and start for menu control
void basic_input()
{
	input_up_last = input_up;
	input_down_last = input_down;
	input_left_last = input_left;
	input_right_last = input_right;
	input_a_last = input_a;
	input_up = CHECK_BIT(joystick[0], 3);
	input_down = CHECK_BIT(joystick[0], 2);
	input_left = CHECK_BIT(joystick[0], 1);
	input_right = CHECK_BIT(joystick[0], 0);
	input_a = CHECK_BIT(joystick[0], 4);
}

unsigned char selected_type = 0;
unsigned char selected_colour = 0;

unsigned char tlx = 9;
unsigned char tly = 4;
unsigned char brx = 30;
unsigned char bry = 25;

void draw_colour()
{
	unsigned char c = 0;
	set_char_palette(
		16,
		hfcr_colour_r[selected_type][selected_colour],
		hfcr_colour_g[selected_type][selected_colour],
		hfcr_colour_b[selected_type][selected_colour]);

	panel_shaded(tlx, tly, brx, bry, 17, 18, 19);
	fill_bgcol(tlx + 1, tly + 1, brx, bry - 1, 16);
	clear_char_area(0, tlx, bry + 1, brx, bry + 2);
	write_string(hfcr_type[selected_type], 18, tlx, bry + 1);
	write_string(hfcr_colour_name[selected_type][selected_colour], 18, tlx, bry + 2);
}

unsigned char timer_interval = 0;
void timer_off()
{
	timer_interval = 0;
	write_string("", colour_cga_darkred, brx, tly - 1);
}
void timer_on()
{
	timer_interval = 60;
	write_string("*", colour_cga_darkred, brx, tly - 1);
}

// Main entry and state machine
void app_main()
{
	chram_size = chram_cols * chram_rows;

	clear_chars(0);
	set_default_char_palette();

	set_char_palette(16, 50, 50, 50);
	clear_bgcolor(0);

	set_char_palette(17, 255, 255, 255);
	set_char_palette(18, 160, 160, 160);
	set_char_palette(19, 80, 80, 80);

	draw_colour();

	while (1)
	{
		hsync = input0 & 0x80;
		vsync = input0 & 0x40;
		hblank = input0 & 0x20;
		vblank = CHECK_BIT(input0, INPUT_VBLANK);

		if (VBLANK_RISING)
		{
			basic_input();

			if (input_up && !input_up_last)
			{
				selected_type = (selected_type == 0) ? hfcr_type_max - 1 : selected_type - 1;
				draw_colour();
				timer_off();
			}
			if (input_down && !input_down_last)
			{
				selected_type = (selected_type == hfcr_type_max - 1) ? 0 : selected_type + 1;
				draw_colour();
				timer_off();
			}
			if (input_left && !input_left_last)
			{
				selected_colour = (selected_colour == 0) ? hfcr_colour_max - 1 : selected_colour - 1;
				draw_colour();
				timer_off();
			}
			if (input_right && !input_right_last)
			{
				selected_colour = (selected_colour == hfcr_colour_max - 1) ? 0 : selected_colour + 1;
				draw_colour();
				timer_off();
			}

			if (timer_interval > 0)
			{
				timer_interval--;
				if (timer_interval == 0)
				{
					selected_colour = (selected_colour == hfcr_colour_max - 1) ? 0 : selected_colour + 1;
					draw_colour();
				}
				if (input_a && !input_a_last)
				{
					timer_off();
				}
			}
			else
			{
				if (input_a && !input_a_last)
				{
					timer_on();
				}
			}
		}

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
