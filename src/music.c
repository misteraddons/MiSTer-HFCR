/*============================================================================
	Aznable OS - Music engine (YM player)

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

#pragma once
#include "sys.c"

#define const_music_track_max 32
unsigned char music_track_max = const_music_track_max;
#include "music_tracks.c" // Include auto generated track array

void play_music(unsigned char track)
{
	// Write track start address (3 bytes)
	musicram[1] = (unsigned char)(music_track_address[track] >> 16);
	musicram[2] = music_track_address[track] >> 8;
	musicram[3] = music_track_address[track];
	// Write start track instruction
	musicram[0] = 1;
}