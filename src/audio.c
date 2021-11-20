#pragma once

int tp[] = {
	// Frequencies related to MIDI note numbers
	15289, 14431, 13621, 12856, 12135, 11454, 10811, 10204, // 0-o7
	9631, 9091, 8581, 8099, 7645, 7215, 6810, 6428,			// 8-15
	6067, 5727, 5405, 5102, 4816, 4545, 4290, 4050,			// 16-23
	3822, 3608, 3405, 3214, 3034, 2863, 2703, 2551,			// 24-31
	2408, 2273, 2145, 2025, 1911, 1804, 1703, 1607,			// 32-39
	1517, 1432, 1351, 1276, 1204, 1136, 1073, 1012,			// 40-47
	956, 902, 851, 804, 758, 716, 676, 638,					// 48-55
	602, 568, 536, 506, 478, 451, 426, 402,					// 56-63
	379, 358, 338, 319, 301, 284, 268, 253,					// 64-71
	239, 225, 213, 201, 190, 179, 169, 159,					// 72-79
	150, 142, 134, 127, 119, 113, 106, 100,					// 80-87
	95, 89, 84, 80, 75, 71, 67, 63,							// 88-95
	60, 56, 53, 50, 47, 45, 42, 40,							// 96-103
	38, 36, 34, 32, 30, 28, 27, 25,							// 104-111
	24, 22, 21, 20, 19, 18, 17, 16,							// 112-119
	15, 14, 13, 13, 12, 11, 11, 10,							// 120-127
	0														// off
};

unsigned char channel_on[2];
unsigned char channel_high[2];
unsigned char channel_low[2];
unsigned char channel_pos[2];
signed char channel_dir[2];
unsigned char channel_speed[2];
unsigned char channel_tick[2];

void ay_write(unsigned char addr, unsigned char data)
{
	sndram[addr] = data;
}

void ay_set_ch(unsigned char c, int i)
{
	ay_write(c * 2, tp[i] & 0xff);
	ay_write((c * 2) + 1, (tp[i] >> 8) & 0x0f);
}

void init_audio()
{
	
	channel_high[0] = 60;
	channel_low[0] = 50;
	channel_dir[0] = 1;
	channel_speed[0] = 30;
	channel_pos[0] = channel_low[0];

	channel_high[1] = 78;
	channel_low[1] = 74;
	channel_dir[1] = 1;
	channel_speed[1] = 15;
	channel_pos[1] = channel_low[1];

	ay_write(0x10, 0xFF);
	for (char a = 0; a < 16; a++)
	{
		ay_write(a, 0xFF);
	}
	ay_write(0x07, 0b11111000);
	ay_write(0x08, 0b00000111);
	ay_write(0x09, 0b00000111);
	ay_write(0x0A, 0b00000111);
}