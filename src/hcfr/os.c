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
#include "hcfr_data.h"

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
bool input_b;
bool input_b_last = 0;

// Track joypad 1 directions and start for menu control
void basic_input()
{
	input_up_last = input_up;
	input_down_last = input_down;
	input_left_last = input_left;
	input_right_last = input_right;
	input_a_last = input_a;
	input_b_last = input_b;
	input_up = CHECK_BIT(joystick[0], 3);
	input_down = CHECK_BIT(joystick[0], 2);
	input_left = CHECK_BIT(joystick[0], 1);
	input_right = CHECK_BIT(joystick[0], 0);
	input_a = CHECK_BIT(joystick[0], 4);
	input_b = CHECK_BIT(joystick[0], 5);
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
		hcfr_colour_r[selected_type][selected_colour],
		hcfr_colour_g[selected_type][selected_colour],
		hcfr_colour_b[selected_type][selected_colour]);

	panel_shaded(tlx, tly, brx, bry, 17, 18, 19);
	fill_bgcol(tlx + 1, tly + 1, brx, bry - 1, 16);
	clear_char_area(0, tlx, bry + 1, brx, bry + 3);
	write_string(hcfr_type[selected_type], 18, tlx, bry + 1);
	write_string(hcfr_colour_name[selected_type][selected_colour], 18, tlx, bry + 2);

	char temp[30];
	sprintf(temp, "%03d, %03d, %03d", hcfr_colour_r[selected_type][selected_colour], hcfr_colour_g[selected_type][selected_colour], hcfr_colour_b[selected_type][selected_colour]);
	write_string(temp, 18, tlx, bry + 3);
}

#define const_mode_menu 0
#define const_mode_show 1

unsigned char mode = const_mode_menu;
unsigned char timer_interval = 0;
#define timer_interval_max 60

void timer_off()
{
	timer_interval = 0;
	write_string(" ", colour_cga_darkred, brx, tly - 1);
}
void timer_on()
{
	timer_interval = timer_interval_max;
	write_string("*", colour_cga_darkred, brx, tly - 1);
}

unsigned char menu_tlx = 10;
unsigned char menu_tly = 4;
unsigned char menu_brx = 30;
unsigned char menu_bry = 25;

void draw_menu()
{
	panel_shaded(menu_tlx, menu_tly, menu_brx, menu_tly + 2, 20, 21, 22);
	write_string("Select standard", colour_cga_lightcyan, menu_tlx + 3, menu_tly + 1);
	panel_shaded(menu_tlx, menu_tly + 3, menu_brx, menu_bry, 20, 21, 22);
	unsigned char y = menu_tly + 5;
	for (int t = 0; t < hcfr_type_max; t++)
	{
		unsigned char c = selected_type == t ? colour_cga_lightred : colour_cga_white;
		unsigned char l = strlen(hcfr_wp[t]);
		write_string(hcfr_type[t], c, menu_tlx + 2, y);
		write_string(hcfr_wp[t], c, (menu_brx - 2) - l, y);
		y += 2;
	}
}

void start_mode_menu()
{
	clear_chars(0);
	clear_bgcolor(0);
	draw_menu();
	mode = const_mode_menu;
}

void start_mode_show()
{
	clear_chars(0);
	clear_bgcolor(0);
	draw_colour();
	selected_colour = 0;
	mode = const_mode_show;
}

void mode_menu()
{
	if (VBLANK_RISING)
	{
		basic_input();

		if (input_up && !input_up_last)
		{
			selected_type = (selected_type == 0) ? hcfr_type_max - 1 : selected_type - 1;
			draw_menu();
		}
		if (input_down && !input_down_last)
		{
			selected_type = (selected_type == hcfr_type_max - 1) ? 0 : selected_type + 1;
			draw_menu();
		}
		if (input_a && !input_a_last)
		{
			start_mode_show();
		}
	}
}

void mode_show()
{

	if (VBLANK_RISING)
	{
		basic_input();

		if (input_up && !input_up_last)
		{
			selected_type = (selected_type == 0) ? hcfr_type_max - 1 : selected_type - 1;
			draw_colour();
			timer_off();
		}
		if (input_down && !input_down_last)
		{
			selected_type = (selected_type == hcfr_type_max - 1) ? 0 : selected_type + 1;
			draw_colour();
			timer_off();
		}
		if (input_left && !input_left_last)
		{
			selected_colour = (selected_colour == 0) ? hcfr_colour_max - 1 : selected_colour - 1;
			draw_colour();
			timer_off();
		}
		if (input_right && !input_right_last)
		{
			selected_colour = (selected_colour == hcfr_colour_max - 1) ? 0 : selected_colour + 1;
			draw_colour();
			timer_off();
		}

		if (timer_interval > 0)
		{
			timer_interval--;
			if (timer_interval == 0)
			{
				selected_colour = (selected_colour == hcfr_colour_max - 1) ? 0 : selected_colour + 1;
				draw_colour();
				timer_interval = timer_interval_max;
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
		if (input_b && !input_b_last)
		{
			start_mode_menu();
		}
	}
}

// Main entry and state machine
void app_main()
{
	chram_size = chram_cols * chram_rows;

	clear_chars(0);
	set_default_char_palette();

	set_char_palette(16, 50, 50, 50);

	set_char_palette(17, 255, 255, 255); // White?
	set_char_palette(18, 160, 160, 160); // Grey
	set_char_palette(19, 80, 80, 80);	 // Dark grey

	set_char_palette(20, 90, 179, 255); // Light blue
	set_char_palette(21, 54, 139, 255); // Blue
	set_char_palette(22, 0, 67, 252);	// Dark blue

	start_mode_menu();

	while (1)
	{
		hsync = input0 & 0x80;
		vsync = input0 & 0x40;
		hblank = input0 & 0x20;
		vblank = CHECK_BIT(input0, INPUT_VBLANK);

		switch (mode)
		{
		case const_mode_menu:
			mode_menu();
			break;
		case const_mode_show:
			mode_show();
			break;
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
