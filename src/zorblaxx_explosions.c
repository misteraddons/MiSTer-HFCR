/*============================================================================
	Aznable OS - Zorblaxx demo application - Explosion routines

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

#include "sys.h"
#include "sprite.h"
#include "zorblaxx_app.h"
#include "zorblaxx_player.h"
#include "zorblaxx_explosions.h"

// Explosions
#define const_explosion_max 4
unsigned char explosion_max = const_explosion_max;
unsigned char explosion_sprite_first = 28;
unsigned char explosion_sprite_palette = 1;
unsigned char explosion_timer[const_explosion_max];
unsigned char explosion_frame[const_explosion_max];
unsigned char explosion_type[const_explosion_max];
const unsigned char explosion_lifespan = 4;
#define explosion_frame_count 4
#define explosion_type_count 2

void setup_explosions()
{
	for (int e = explosion_sprite_first; e < explosion_sprite_first + explosion_max; e++)
	{
		enable_sprite(e, explosion_sprite_palette, false);
		spr_on[e] = false;
	}
}

void add_explosion(unsigned type, unsigned char count)
{
	for (unsigned char e = 0; e < explosion_max; e++)
	{
		if (explosion_timer[e] == 0)
		{
			explosion_timer[e] = rand_uchar(2, 7);
			explosion_frame[e] = 0;
			explosion_type[e] = type;
			unsigned char sprite = explosion_sprite_first + e;
			spr_on[sprite] = true;
			spr_index[sprite] = explosion_sprite_index_first + (type * explosion_frame_count);
			spr_x[sprite] = (player_x + (signed short)rand_schar(-32, 64)) / x_divisor;
			unsigned short y = (player_y + (signed short)rand_schar(-32, 64)) / y_divisor;
			spr_y_h[sprite] = y >> 8;
			spr_y_l[sprite] = (unsigned char)y;
			count--;
			if (count == 0)
			{
				return;
			}
		}
	}
}

void handle_explosions()
{
	for (unsigned char t = 0; t < explosion_max; t++)
	{
		if (explosion_timer[t] > 0)
		{
			explosion_timer[t]--;
			if (explosion_timer[t] == 0)
			{
				unsigned char sprite = explosion_sprite_first + t;
				spr_index[sprite]++;
				explosion_frame[t]++;
				if (explosion_frame[t] == explosion_frame_count)
				{
					spr_on[sprite] = false;
				}
				else
				{
					explosion_timer[t] = explosion_lifespan;
				}
			}
		}
	}
}