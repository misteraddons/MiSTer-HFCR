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
#include "sprite_images.h"
#include "sound.h"
#include "sound_samples.h"
#include "tilemap.h"
#include "inputtester_app.h"
#include "inputtester_sys.h"
#include "menu.h"
#include "zorblaxx_app.h"
#include "snek_app.h"
#include "fader.h"

void intro_text(const char *text, unsigned char start_x, unsigned char start_y, unsigned char space_x, unsigned char speed, unsigned char flash_speed)
{
	unsigned char text_timer = 0;
	unsigned char text_length = 1;
	unsigned char text_flash = 0;
	unsigned char text_flash_timer = 0;
	unsigned char text_char_count = strlen(text);

	// Speed things up in debug mode
	if (CHECK_BIT(input0, 0))
	{
		speed = 1;
		flash_speed = 1;
	}

	while (1)
	{
		vblank = CHECK_BIT(input0, INPUT_VBLANK);

		// Aznable title intro
		if (VBLANK_RISING)
		{
			unsigned char xpos = start_x + ((text_length - 1) * space_x);
			text_timer++;
			if (text_timer == speed)
			{
				write_char(text[text_length - 1], 0xFF, xpos, start_y);
				text_length++;
				if (text_length > text_char_count)
				{
					break;
				}
				text_timer = 0;
				text_flash_timer = 0;
			}
			else
			{
				text_flash_timer++;
				if (text_flash_timer == flash_speed)
				{
					text_flash++;
					if (text_flash == 2)
					{
						text_flash = 0;
					}
					if (text_flash == 1)
					{
						write_char(0, 0, xpos, start_y);
					}
					else
					{
						write_char(text[text_length - 1], 0xFF, xpos, start_y);
					}
					text_flash_timer = 0;
				}
			}
		}
		vblank_last = vblank;
	}
}

void loader(const char *title)
{
	// Play startup sound
	set_sound_volume(255);
	play_sound(const_sound_newtype);

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

	const char *system_title = "AZNABLE";

	// OS Intro
	write_char('>', 0xFF, 0, 1);
	intro_text(system_title, 2, 1, 2, 8, 1);
	write_char(' ', 0xFF, 0, 1);

	write_char('>', 0xFF, 0, 3);
	intro_text("LOAD ", 2, 3, 1, 4, 1);
	intro_text(title, 7, 3, 1, 4, 1);
	write_char(' ', 0xFF, 0, 3);

	write_char('>', 0xFF, 0, 5);
	intro_text("...", 2, 5, 1, 8, 1);

	// Clear characters
	clear_char_area(0, 1, 1, 40, 3);
}

// Main entry and state machine
void app_main()
{
	chram_size = chram_cols * chram_rows;
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
			 state = STATE_START_ZORBLAXX;
			//loader("INPUTTESTER.AZN")
			//start_inputtester_digital();
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

	// // LOAD TILEMAP RAM
	// unsigned char ti = 0;
	// for (unsigned char y = 0; y < 17; y++)
	// {
	// 	ti = y % 2;
	// 	for (unsigned char x = 0; x < 22; x++)
	// 	{
	// 		unsigned short p = (y * 32) + x;
	// 		tilemapram[p] = ti;
	// 		ti++;
	// 		if (ti == 6)
	// 		{
	// 			ti = 0;
	// 		}
	// 	}
	// }
	// unsigned char tsi = 0;
	// unsigned char vsi = 0;

	// signed char hscroll_dir = 0;
	// signed char vscroll_dir = 0;

	// while (1)
	// {
	// 	vblank = CHECK_BIT(input0, INPUT_VBLANK);
	// 	if (VBLANK_RISING)
	// 	{
	// 		basic_input();

	// 		if (input_left && !input_left_last && hscroll_dir > -4)
	// 		{
	// 			hscroll_dir--;
	// 		}
	// 		if (input_right && !input_right_last && hscroll_dir < 4)
	// 		{
	// 			hscroll_dir++;
	// 		}
	// 		if (input_up && !input_up_last && vscroll_dir > -4)
	// 		{
	// 			vscroll_dir--;
	// 		}
	// 		if (input_down && !input_down_last && vscroll_dir < 4)
	// 		{
	// 			vscroll_dir++;
	// 		}

	// 		if (hscroll_dir > 0)
	// 		{
	// 			tilemap_offset_x -= hscroll_dir;
	// 			if (tilemap_offset_x <= -16)
	// 			{
	// 				tilemap_offset_x += 16;
	// 				tilemapctl[2] = 1;
	// 				// Scroll right?
	// 				while (tilemapctl[2] != 0)
	// 				{
	// 				}
	// 				for (unsigned char y = 0; y < 17; y++)
	// 				{
	// 					unsigned short p = (y * 32);
	// 					tilemapram[p] = tsi;
	// 				}
	// 				tsi++;
	// 				if (tsi == 6)
	// 				{
	// 					tsi = 0;
	// 				}
	// 			}
	// 		}
	// 		if (hscroll_dir < 0)
	// 		{
	// 			tilemap_offset_x += -hscroll_dir;
	// 			if (tilemap_offset_x >= 16)
	// 			{
	// 				tilemap_offset_x -= 16;
	// 				tilemapctl[2] = -1;
	// 				// Scroll left?
	// 				while (tilemapctl[2] != 0)
	// 				{
	// 				}
	// 				for (unsigned char y = 0; y < 17; y++)
	// 				{
	// 					unsigned short p = (y * 32) + 21;
	// 					tilemapram[p] = tsi;
	// 				}
	// 				tsi++;
	// 				if (tsi == 6)
	// 				{
	// 					tsi = 0;
	// 				}
	// 			}
	// 		}

	// 		if (vscroll_dir > 0)
	// 		{
	// 			tilemap_offset_y -= vscroll_dir;
	// 			if (tilemap_offset_y <= -16)
	// 			{
	// 				tilemap_offset_y += 16;
	// 				tilemapctl[3] = 1;
	// 				// Scroll right?
	// 				while (tilemapctl[3] != 0)
	// 				{
	// 				}
	// 				for (unsigned char x = 0; x < 22; x++)
	// 				{
	// 					unsigned short p = x;
	// 					tilemapram[p] = vsi;
	// 				}
	// 				vsi++;
	// 				if (vsi == 6)
	// 				{
	// 					vsi = 0;
	// 				}
	// 			}
	// 		}
	// 		if (vscroll_dir < 0)
	// 		{
	// 			tilemap_offset_y += -vscroll_dir;
	// 			if (tilemap_offset_y >= 16)
	// 			{
	// 				tilemap_offset_y -= 16;
	// 				tilemapctl[3] = -1;
	// 				// Scroll left?
	// 				while (tilemapctl[3] != 0)
	// 				{
	// 				}
	// 				for (unsigned char x = 0; x < 22; x++)
	// 				{
	// 					unsigned short p = (17 * 32) + 21;
	// 					tilemapram[p] = vsi;
	// 				}
	// 				vsi++;
	// 				if (vsi == 6)
	// 				{
	// 					vsi = 0;
	// 				}
	// 			}
	// 		}

	// 		update_tilemap_offset();
	// 	}

	// 	vblank_last = vblank;
	// }

	app_main();
}
