/*============================================================================
	Aznable OS - System interface functions

	Author: Jim Gregory - https://github.com/JimmyStones/
	Version: 1.2
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
#ifndef SYS_H
	#define SYS_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// Memory mapped IO
// - Inputs
unsigned char __at(0x8000) input0;
unsigned char __at(0x8100) joystick[24];
unsigned char __at(0x8200) analog_l[12];
unsigned char __at(0x8300) analog_r[12];
unsigned char __at(0x8400) paddle[6];
unsigned char __at(0x8500) spinner[12];
unsigned char __at(0x8600) ps2_key[2];
unsigned char __at(0x8700) ps2_mouse[6];
unsigned char __at(0x8800) timestamp[5];
unsigned char __at(0x8900) timer[2];
unsigned char __at(0x8A00) starfield[6];
unsigned char __at(0x8B00) sndram[17];
unsigned char __at(0x8B10) musicram[4];

// - Casval (character map)
unsigned char __at(0x9800) chram[2048];
unsigned char __at(0xA000) fgcolram[2048];
unsigned char __at(0xA800) bgcolram[2048];
// - Comet (sprite engine)
unsigned char __at(0xB000) spriteram[512];
unsigned char __at(0xB400) spritecollisionram[32];

// Character map
extern const unsigned char chram_cols;
extern const unsigned char chram_rows;
extern unsigned short chram_size;

// Hardware inputs
extern bool hsync;
extern extern bool hsync_last;
extern bool vsync;
extern bool vsync_last;
extern bool hblank;
extern bool hblank_last;
extern bool vblank;
extern bool vblank_last;

// Macros
#define CHECK_BIT(var, pos) ((var) & (1 << (pos)))
#define SET_BIT(var, pos) ((var) |= (1 << (pos)))
#define CLEAR_BIT(var, pos) ((var) &= ~(1 << (pos)))
#define VBLANK_RISING (vblank && !vblank_last)
#define VSYNC_RISING (vsync && !vsync_last)
#define HBLANK_RISING (hblank && !hblank_last)
#define HSYNC_RISING (hsync && !hsync_last)
#define VBLANK_FALLING (!vblank && vblank_last)
#define VSYNC_FALLING (!vsync && vsync_last)
#define HBLANK_FALLING (!hblank && hblank_last)
#define HSYNC_FALLING (!hsync && hsync_last)

#define GET_TIMER ((unsigned short)timer[1] << 8) | (unsigned char)timer[0]

// Helper functions
extern unsigned char rand_uchar(unsigned char lower, unsigned char upper);

extern unsigned short rand_ushort(unsigned short lower, unsigned short upper);

extern signed char rand_schar(signed char lower, signed char upper);

#endif