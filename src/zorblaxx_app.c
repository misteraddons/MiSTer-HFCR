/*============================================================================
	Aznable OS - Zorblaxx demo application

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

/*
	Sprite indexes:
	0-11	- Trails
	12		- Player
	13-15   - Explosions
	16-31	- Meteors
*/


#include "sys.h"
#include "sprite.h"
#include "ui.h"
#include "music.h"
#include "zorblaxx_player.h"
#include "zorblaxx_trails.h"
#include "zorblaxx_explosions.h"
#include "zorblaxx_asteroids.h"

// Area and units
const unsigned char x_divisor = 16;
const unsigned char y_divisor = 16;
unsigned short x_min = 2;
unsigned short x_max = 336;
unsigned short x_h_min;
unsigned short x_h_max;
unsigned char scroll_speed;

void setup_area()
{
	x_h_min = (unsigned short)(x_min * x_divisor);
	x_h_max = (unsigned short)(x_max * x_divisor);
}

//#define DEBUG_PRINT
unsigned short debug_t1;
unsigned short debug_t2;

void intro_loop()
{

	clear_bgcolor(0);

	starfield[0] = 2;
	starfield[2] = 8;
	starfield[4] = 32;
	unsigned char s = 16;
	unsigned short logoX = 115;
	unsigned char logoY = 100;
	unsigned char si = 0;
	for (unsigned char y = 0; y < 2; y++)
	{
		for (unsigned char x = 0; x < 8; x++)
		{
			enable_sprite(s, 2, 0);
			spr_index[s] = 22 + si;
			spr_x[s] = logoX + (x * 16);
			unsigned short sy = logoY + (y * 16);
			spr_y_h[s] = sy >> 8;
			spr_y_l[s] = (unsigned char)sy;
			si++;
			s++;
		}
	}
	logoY += 32;

	starfield[0] = 8;
	starfield[1] = 16;
	starfield[2] = 32;

	write_string("Press A to start", 0xFF, 12, 20);

	while (1)
	{
		// hsync = input0 & 0x80;
		// vsync = input0 & 0x40;
		// hblank = input0 & 0x20;
		vblank = input0 & 0x10;

		if (VBLANK_RISING)
		{
			// If button pressed, leave intro and start game
			if (CHECK_BIT(joystick[0], 4))
			{
				return;
			}
#ifdef DEBUG_PRINT
			unsigned char debug_y = 16;
			debug_t1 = GET_TIMER;
#endif
			update_sprites();
#ifdef DEBUG_PRINT
			debug_t2 = GET_TIMER;
			write_stringf_ushort("spr: %4d us", 0b01011011, 0, debug_y++, debug_t2 - debug_t1);
#endif
		}

		// hsync_last = hsync;
		// vsync_last = vsync;
		// hblank_last = hblank;
		vblank_last = vblank;
	}
}

// Starfield variables
unsigned char scroll_speed_last = 0;
unsigned char sf_speed1 = 4;
// unsigned char sound_timer = 0;

void game_loop()
{
	clear_sprites();
	clear_bgcolor(0);
	clear_chars(0);

	play_music(0);

	while (1)
	{
		// hsync = input0 & 0x80;
		// vsync = input0 & 0x40;
		// hblank = input0 & 0x20;
		vblank = input0 & 0x10;

		if (VBLANK_RISING)
		{

#ifdef DEBUG_PRINT
			unsigned char debug_y = 16;
			debug_t1 = GET_TIMER;
#endif
			update_sprites();
			// #ifdef DEBUG_PRINT
			// 			debug_t2 = GET_TIMER;
			// 			write_stringf_ushort("spr: %4d us", 0b01011011, 0, debug_y++, debug_t2 - debug_t1);
			// #endif
			// Update starfield
			// #ifdef DEBUG_PRINT
			// 			debug_t1 = GET_TIMER;
			// #endif
			scroll_speed = player_speed;
			if (scroll_speed != scroll_speed_last)
			{
				scroll_speed_last = scroll_speed;
				unsigned char s = scroll_speed / sf_speed1;
				starfield[0] = s;
				s = s / 2;
				starfield[2] = s;
				s = s / 2;
				starfield[4] = s;
			}
			// #ifdef DEBUG_PRINT
			// 			debug_t2 = GET_TIMER;
			// 			write_stringf_ushort(" sf: %4d us", 0b01011011, 0, debug_y++, debug_t2 - debug_t1);
			// #endif

			// Handle player collision
			if (spritecollisionram[player_sprite])
			{
				player_hit = true;
				spritecollisionram[player_sprite] = 0;
			}
#ifdef DEBUG_PRINT
			debug_t2 = GET_TIMER;
			write_stringf_ushort("vbl: %4d us", 0b01011011, 0, debug_y++, debug_t2 - debug_t1);
#endif
		}

		if (VBLANK_FALLING)
		{

#ifdef DEBUG_PRINT
			unsigned char debug_y = 23;
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
			handle_explosions();
#ifdef DEBUG_PRINT
			debug_t2 = GET_TIMER;
			write_stringf_ushort("exp: %4d us", 0b01011011, 0, debug_y++, debug_t2 - debug_t1);
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
		}

		// hsync_last = hsync;
		// vsync_last = vsync;
		// hblank_last = hblank;
		vblank_last = vblank;
	}
}

void app_zorblaxx()
{
	setup_area();
	setup_player(176, 216);
	setup_trails();
	intro_loop();
	clear_chars(0);
	clear_sprites();

	setup_area();
	setup_meteors();
	setup_trails();
	setup_explosions();
	setup_player(176, 216);

	game_loop();
}