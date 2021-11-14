#pragma once

#define const_sprite_max 32
unsigned char sprite_max = const_sprite_max;
unsigned short spr_x[const_sprite_max];
unsigned short spr_y[const_sprite_max];
bool spr_on[const_sprite_max];
unsigned char spr_index[const_sprite_max];

void update_sprites()
{
	unsigned char s = 0;
	for (unsigned char sprite = 0; sprite < sprite_max; sprite++)
	{
		if (spr_on[sprite])
		{
			spriteram[s++] = 1 << 7 | spr_y[sprite] >> 8; // Enabled + Position Y (upper 4 bits)
			spriteram[s++] = (unsigned char)spr_y[sprite];		  // Position Y (lower 8 bits)
			spriteram[s++] = spr_index[sprite] << 3 | spr_x[sprite] >> 7; // Sprite Index (5 bits) + Position X (upper 3 bits)
			spriteram[s++] = (unsigned char)spr_x[sprite];		  // Position X (lower 8 bits)
		}
		else
		{
			spriteram[s++] = 0; // Disabled
			s += 3;
		}
	}
}