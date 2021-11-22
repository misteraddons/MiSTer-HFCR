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