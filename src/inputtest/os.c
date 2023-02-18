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
#include "../shared/sprite.h"
#include "../shared/sound.h"
#include "../shared/tilemap.h"
#include "loader.h"
#include "sprite_images.h"
#include "sound_samples.h"
#include "inputtester_app.h"
#include "inputtester_sys.h"
#include "inputtester_ui.h"
#include "menu.h"
#include "zorblaxx_app.h"
#include "snek_app.h"
#include "fader.h"
#include "credits.h"

// Main entry and state machine
void app_main()
{
	chram_size = chram_cols * chram_rows;

	set_default_char_palette();

	// Add extended colours
	set_char_palette(colour_header_light, 255, 0, 0);
	set_char_palette(colour_header_mid, 237, 0, 0);
	set_char_palette(colour_header_dark, 179, 0, 0);
	set_char_palette(colour_frame_light, 180, 180, 200);
	set_char_palette(colour_frame_mid, 156, 156, 185);
	set_char_palette(colour_frame_dark, 70, 70, 80);
	set_char_palette(colour_footer_light, 0, 0, 255);
	set_char_palette(colour_footer_mid, 0, 0, 237);
	set_char_palette(colour_footer_dark, 0, 0, 179);
	set_char_palette(colour_footer_text, 113, 105, 255);

	set_char_palette(colour_pad_outline, 222, 255, 255);
	set_char_palette(colour_analog_outline, 255, 255, 255);
	set_char_palette(colour_analog_grid, 109, 161, 0);
	set_char_palette(colour_analog_text_cycle, 255, 255, 20);

	set_char_palette(colour_buttontest_text_primary, 50, 255, 255);
	set_char_palette(colour_buttontest_text_secondary, 251, 196, 255);
	set_char_palette(colour_buttontest_purple, 202, 105, 255);

	set_char_palette(colour_menu_panel_outline_high, 255, 255, 255);
	set_char_palette(colour_menu_panel_outline_mid, 238, 238, 0);
	set_char_palette(colour_menu_panel_outline_low, 150, 161, 0);
	set_char_palette(colour_menu_panel_back, 0, 0, 0);

	set_char_palette(colour_menu_outline_high, 249, 249, 180);
	set_char_palette(colour_menu_outline_mid, 239, 239, 170);
	set_char_palette(colour_menu_outline_low, 156, 156, 71);
	set_char_palette(colour_menu_text, 239, 239, 170);
	set_char_palette(colour_menu_back, 0, 0, 0);

	set_char_palette(colour_menu_sel_outline_high, 255, 104, 61);
	set_char_palette(colour_menu_sel_outline_mid, 254, 64, 0);
	set_char_palette(colour_menu_sel_outline_low, 165, 72, 0);
	set_char_palette(colour_menu_sel_text, 255, 255, 255);
	set_char_palette(colour_menu_sel_back, 0, 0, 0);

	while (1)
	{
		hsync = input0 & 0x80;
		vsync = input0 & 0x40;
		hblank = input0 & 0x20;
		vblank = CHECK_BIT(input0, INPUT_VBLANK);
		switch (state)
		{
		case STATE_START_INPUTTESTER:
			start_inputtester_digital();
			break;
		case STATE_INPUTTESTER:
			inputtester_digital();
			break;

		case STATE_START_INPUTTESTERADVANCED:
			start_inputtester_advanced();
			break;
		case STATE_INPUTTESTERADVANCED:
			inputtester_advanced();
			break;

		case STATE_START_INPUTTESTERANALOG:
			start_inputtester_analog();
			break;
		case STATE_INPUTTESTERANALOG:
			inputtester_analog();
			break;

		case STATE_START_BTNTEST:
			start_btntest();
			break;
		case STATE_BTNTEST:
			btntest();
			break;

		case STATE_START_MENU:
			start_menu();
			break;
		case STATE_MENU:
			menu();
			break;

		case STATE_FADEOUT:
			fadeout();
			break;
		case STATE_FADEIN:
			fadein();
			break;

		case STATE_START_ATTRACT:
			state = 0;
			loader("SNEK.AZN");
			start_snek_attract();
			break;
		case STATE_ATTRACT:
			snek_attract();
			break;
		case STATE_START_CREDITS:
			app_credits();
			break;

		case STATE_START_GAME_SNEK:
			start_snek_gameplay();
			break;
		case STATE_GAME_SNEK:
			snek_gameplay();
			break;
		case STATE_START_ZORBLAXX:
			state = 0;
			loader("ZORBLAXX.AZN");
			app_zorblaxx();
			break;

		default:
			// Start default state
			// state = STATE_START_ZORBLAXX;
			// app_zorblaxx();
			// state = STATE_START_CREDITS;
			loader("INPUTTESTER.AZN");
			start_inputtester_digital();
			//	start_inputtester_advanced();
			// start_inputtester_analog();
			// start_btntest();
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
