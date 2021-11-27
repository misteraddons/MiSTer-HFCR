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
#include "sprite.c"
#include "audio.c"
#include "music.c"
//#include "app_console.c"
#include "app_meteorstorm.c"

//#define DEBUG_PRINT

void test_loop()
{

	clear_bgcolor(0b01000000);

	starfield[0] = 2;
	starfield[2] = 8;
	starfield[4] = 32;
	char s = 0;
	for (char y = 0; y < 4; y++)
	{
		for (char x = 0; x < 8; x++)
		{
			spr_index[s] = 12 + s;
			s++;
		}
	}

	signed short logoX = 120;
	signed short logoY = 100;

	while (1)
	{
		// hsync = input0 & 0x80;
		// vsync = input0 & 0x40;
		// hblank = input0 & 0x20;
		vblank = input0 & 0x10;

		if (VBLANK_RISING)
		{
			update_sprites();
		}
		if (VBLANK_FALLING)
		{
			char s = 0;

			logoX += 1;
			if (logoX > 336)
			{
				logoX = -112;
			}

			for (char y = 0; y < 4; y++)
			{
				for (char x = 0; x < 8; x++)
				{
					unsigned short lx = logoX + (x * 16);
					spr_on[s] = lx > 0;
					spr_x[s] = lx;
					spr_y[s] = logoY + (y * 16);
					s++;
				}
			}
		}

		// hsync_last = hsync;
		// vsync_last = vsync;
		// hblank_last = hblank;
		vblank_last = vblank;
	}
}

void coltest_loop()
{

	clear_bgcolor(0b01000000);

	unsigned char scf = 0;
	unsigned char sc = 20;

	unsigned short sx = 100;
	unsigned short sy = 80;

	unsigned char is = 0;
	unsigned char ic = 0;
	unsigned char icm = 16;

	for (char s = scf; s < sc; s++)
	{
		spr_on[s] = 1;
		spr_index[s] = is + ic;
		ic++;
		if (ic == icm)
		{
			ic = 0;
		}
		spr_x[s] = sx;
		spr_y[s] = sy;
		sx += 10;
		sy+=1;
		if (sx > 200)
		{
			sx = 100;
			sy += 20;
		}
	}

	// char x1 = 80;
	// char x2 = 94;
	// char y1 = 80;
	// char y2 = 94;

	while (1)
	{
		vblank = input0 & 0x10;

		if (VBLANK_RISING)
		{
			update_sprites();
		}
		if (VBLANK_FALLING)
		{

			// if (CHECK_BIT(joystick[0], 0))
			// {
			// 	x1--;
			// 	x2++;
			// }
			// if (CHECK_BIT(joystick[0], 1))
			// {
			// 	x1++;
			// 	x2--;
			// }
			// if (CHECK_BIT(joystick[0], 2))
			// {
			// 	y1--;
			// }
			// if (CHECK_BIT(joystick[0], 3))
			// {
			// 	y2++;
			// }
			// if (CHECK_BIT(joystick[0], 4))
			// {
			// 	y1++;
			// }
			// if (CHECK_BIT(joystick[0], 5))
			// {
			// 	y2--;
			// }
			// spr_x[0] = x1;
			// spr_x[1] = x2;
			// spr_y[0] = y1;
			// spr_y[1] = y2;

			for (char c = 0; c < sc; c++)
			{
				write_char(spritecollisionram[c] ? 'X' : '.', 0xFF, c, 2);
			}

			// if (CHECK_BIT(joystick[0], 6))
			// {
			for (char c = 0; c < sc; c++)
			{
				spritecollisionram[c] = 0;
			}
			// }
		}

		vblank_last = vblank;
	}
}

unsigned char player_speed_last = 0;

unsigned char sf_speed1 = 4;

// unsigned char sound_timer = 0;

void game_loop()
{

	play_music(0);

	while (1)
	{
		// hsync = input0 & 0x80;
		// vsync = input0 & 0x40;
		// hblank = input0 & 0x20;
		vblank = input0 & 0x10;

		// console();

		if (VBLANK_RISING)
		{
			unsigned char debug_y = 16;
#ifdef DEBUG_PRINT
			debug_t1 = GET_TIMER;
#endif
			update_sprites();
#ifdef DEBUG_PRINT
			debug_t2 = GET_TIMER;
			write_stringf_ushort("spr: %4d us", 0b01011011, 0, debug_y++, debug_t2 - debug_t1);
#endif
			// Update starfield
#ifdef DEBUG_PRINT
			debug_t1 = GET_TIMER;
#endif
			if (player_speed != player_speed_last)
			{
				player_speed_last = player_speed;
				unsigned char s = player_speed / sf_speed1;
				starfield[0] = s;
				s = s / 2;
				starfield[2] = s;
				s = s / 2;
				starfield[4] = s;
			}
#ifdef DEBUG_PRINT
			debug_t2 = GET_TIMER;
			write_stringf_ushort(" sf: %4d us", 0b01011011, 0, debug_y++, debug_t2 - debug_t1);
#endif

			// Handle collision

		}

		if (VBLANK_FALLING)
		{
			unsigned char debug_y = 26;

#ifdef DEBUG_PRINT
			debug_t1 = GET_TIMER;
#endif
			handle_player();
#ifdef DEBUG_PRINT
			debug_t2 = GET_TIMER;
			write_stringf_ushort("ply: %4d us", 0b01011011, 0, debug_y++, debug_t2 - debug_t1);
#endif

#ifdef DEBUG_PRINT
			debug_t1 = GET_TIMER;
#endif
			handle_trails();
#ifdef DEBUG_PRINT
			debug_t2 = GET_TIMER;
			write_stringf_ushort("trl: %4d us", 0b01011011, 0, debug_y++, debug_t2 - debug_t1);
#endif

#ifdef DEBUG_PRINT
			debug_t1 = GET_TIMER;
#endif
			handle_meteors();
#ifdef DEBUG_PRINT
			debug_t2 = GET_TIMER;
			write_stringf_ushort("met: %4d us", 0b01011011, 0, debug_y++, debug_t2 - debug_t1);
#endif

			// Draw player score last
			write_stringf_ushort("%10d", 0xFF, 30, 0, player_score);

			// Meteor difficulty debug
			write_stringf_ushort("%4d", 0xFF, 0, 0, meteor_difficulty);
			// write_stringf_ushort("%4d", 0xFF, 0, 1, meteor_difficulty_timer);
		}

		// hsync_last = hsync;
		// vsync_last = vsync;
		// hblank_last = hblank;
		vblank_last = vblank;
	}
}

// Main entry and state machine
void main()
{
	// Setup charmap
	chram_size = chram_cols * chram_rows;
	clear_bgcolor(0);
	clear_chars(0);

	// init_audio();

	channel_on[0] = 0;
	// ay_write(0x08, 0x00);
	// ay_set_ch(0, channel_pos[0]);

	channel_on[1] = 0;
	// ay_write(0x09, 0x00);
	// ay_set_ch(1, channel_pos[1]);

	setup_area();
	setup_meteors();
	setup_trails();
	setup_player();

#ifdef DEBUG_PRINT
	unsigned short debug_t1;
	unsigned short debug_t2;
#endif

	// test_loop();

	// coltest_loop();

	for (unsigned char m = 0; m < meteor_max; m++)
	{
		meteor_x[m] = ((unsigned char)rand() + x_divisor) * x_divisor;
		meteor_y[m] = ((unsigned char)rand() + y_divisor) * y_divisor;
		meteor_xs[m] = rand_schar(-8, 8);
		meteor_ys[m] = rand_uchar(4, 32);
		meteor_timer[m] = 0;
		unsigned char sprite = meteor_sprite_first + m;
		spr_on[sprite] = true;
	}



	game_loop();
}
