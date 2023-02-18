/*============================================================================
	Input Test - Custom UI functions

	Author: Jim Gregory - https://github.com/JimmyStones/
	Version: 1.0
	Date: 2021-07-12

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
#ifndef INPUTTESTER_UI_H
#define INPUTTESTER_UI_H

// Colour palette indexes
#define colour_text_primary 15 // WHITE
#define colour_button_active 15 // WHITE
#define colour_button_inactive 7 // GREY

#define colour_header_light 16
#define colour_header_mid 17
#define colour_header_dark 18
#define colour_frame_light 19
#define colour_frame_mid 20
#define colour_frame_dark 21
#define colour_footer_light 22
#define colour_footer_mid 23
#define colour_footer_dark 24
#define colour_footer_text 25

#define colour_pad_outline 30
#define colour_analog_outline 31
#define colour_analog_grid 32
#define colour_analog_text_cycle 33

#define colour_buttontest_text_primary 40
#define colour_buttontest_text_secondary 41
#define colour_buttontest_purple 42

#define colour_menu_panel_outline_high 50
#define colour_menu_panel_outline_mid 51
#define colour_menu_panel_outline_low 52
#define colour_menu_panel_back 53

#define colour_menu_outline_high 54
#define colour_menu_outline_mid 55
#define colour_menu_outline_low 56
#define colour_menu_text 57
#define colour_menu_back 58

#define colour_menu_sel_outline_high 59
#define colour_menu_sel_outline_mid 60
#define colour_menu_sel_outline_low 61
#define colour_menu_sel_text 62
#define colour_menu_sel_back 63


extern void page_frame(bool showMenuButton, bool showContinueButton);

// Draw game pad outline
extern void draw_pad(char xo, char yo);

// Draw game pad outline
extern void draw_analog(char xo, char yo, char xs, char ys);

#endif