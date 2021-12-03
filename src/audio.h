/*============================================================================
	Aznable OS - Audio functions

	Author: Jim Gregory - https://github.com/JimmyStones/
	Version: 1.1
	Date: 2021-07-15

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
#ifndef AUDIO_H
#define AUDIO_H

extern unsigned char channel_on[];
extern unsigned char channel_high[];
extern unsigned char channel_low[];
extern unsigned char channel_pos[];
extern signed char channel_dir[];
extern unsigned char channel_speed[];

extern void ay_write(unsigned char addr, unsigned char data);

extern void ay_set_ch(unsigned char c, unsigned char i);

extern void init_audio();

#endif