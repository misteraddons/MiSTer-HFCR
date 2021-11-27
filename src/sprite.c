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
unsigned short spr_y[const_sprite_max];
bool spr_on[const_sprite_max];
bool spr_collide[const_sprite_max];
unsigned char spr_index[const_sprite_max];

void update_sprites()
{
	unsigned char s = 0;
	for (unsigned char sprite = 0; sprite < sprite_max; sprite++)
	{
		if (spr_on[sprite])
		{
			spriteram[s++] = 1 << 7 | spr_collide[sprite] << 6 | spr_y[sprite] >> 8; // Enabled + Collide + Position Y (upper 4 bits)
			spriteram[s++] = (unsigned char)spr_y[sprite];		  // Position Y (lower 8 bits)
			spriteram[s++] = spr_index[sprite] << 2 | spr_x[sprite] >> 8; // Sprite Index (6 bits) + Position X (upper 2 bits)
			spriteram[s++] = (unsigned char)spr_x[sprite];		  // Position X (lower 8 bits)
		}
		else
		{
			spriteram[s++] = 0; // Disabled
			s += 3;
		}
	}
}