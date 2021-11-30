/*============================================================================
	Aznable OS - Caval (sprite engine)

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

#define const_sprite_max 32
unsigned char sprite_max = const_sprite_max;
unsigned short spr_x[const_sprite_max];
unsigned char spr_y_l[const_sprite_max];
unsigned char spr_y_h[const_sprite_max];
bool spr_on[const_sprite_max];
bool spr_collide[const_sprite_max];
unsigned char spr_palette_index[const_sprite_max];
unsigned char spr_index[const_sprite_max];

unsigned char spr_highbits[const_sprite_max]; // Temp cache of high bits excluding upper 2 Y bits
// bool spr_highbits_dirty[const_sprite_max];

void update_sprites()
{
	unsigned char s = 0;
	for (unsigned char sprite = 0; sprite < sprite_max; sprite++)
	{
		if (spr_on[sprite])
		{
			unsigned short x = spr_x[sprite];
			// Set sprite properties
			spriteram[s++] = spr_highbits[sprite] | spr_y_h[sprite];	// Enabled (1 bit) + Collide (1 bit) + Palette Index (2 bits) + Position Y (upper 2 bits)
			spriteram[s++] = spr_y_l[sprite];							// Position Y (lower 8 bits)
			spriteram[s++] = spr_index[sprite] << 2 | x >> 8;			// Sprite Index (6 bits) + Position X (upper 2 bits)
			spriteram[s++] = (unsigned char)x;							// Position X (lower 8 bits)
		}
		else
		{
			// Clear first sprite byte to disable
			spriteram[s] = 0;
			s += 4;
		}
	}
}

void enable_sprite(unsigned char sprite, unsigned char palette_index, unsigned char collide)
{
	spr_on[sprite] = 1;
	spr_collide[sprite] = collide;
	spr_palette_index[sprite] = palette_index;
	spr_highbits[sprite] = 1 << 7 | spr_collide[sprite] << 6 | spr_palette_index[sprite] << 4;
}

void clear_sprites()
{
	for (unsigned char sprite = 0; sprite < sprite_max; sprite++)
	{
		spr_on[sprite] = 0;
	}
}