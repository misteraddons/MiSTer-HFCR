/*============================================================================
	Aznable OS - Zorblaxx demo application - Pickup routines

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
#include "zorblaxx_pickups.h"
#include "zorblaxx_asteroids.h"
#include "zorblaxx_player.h"

#define const_pickup_max 1
#define const_type_count 2
unsigned char pickup_max = const_pickup_max;
unsigned char pickup_type_count = const_type_count;
unsigned char pickup_sprite_first = 31;
unsigned char pickup_sprite_palette = 1;
unsigned char pickup_spawn_y = 0;
unsigned short pickup_x[const_pickup_max];
unsigned short pickup_y[const_pickup_max];
unsigned char pickup_state[const_pickup_max];
unsigned char pickup_value[const_pickup_max];
unsigned char pickup_timer[const_pickup_max];
unsigned short pickup_y_max;
unsigned char pickup_y_offset;

void spawn_pickup()
{
	for (unsigned char t = 0; t < pickup_max; t++)
	{
		if (pickup_state[t] == 0)
		{
			unsigned char sprite = pickup_sprite_first + t;
			pickup_x[t] = rand_ushort(48, 272) * x_divisor;
			pickup_y[t] = pickup_spawn_y * y_divisor;
			pickup_state[t] = 1;
			unsigned char type = rand_uchar(0, const_type_count - 1);
			pickup_value[t] = 50 * (type + 1);
			enable_sprite(sprite, pickup_sprite_palette, 1);
			spr_index[sprite] = pickup_sprite_index_first + type;
			spr_x[sprite] = pickup_x[t] / x_divisor;
			spr_y_h[sprite] = 0; // Y is never that high
			spr_y_l[sprite] = (unsigned char)pickup_spawn_y;
			return;
		}
	}
}

void setup_pickups()
{
	pickup_y_max = 248 * y_divisor;
	pickup_y_offset = (8 * y_divisor);
	for (int t = pickup_sprite_first; t < pickup_sprite_first + pickup_max; t++)
	{
		enable_sprite(t, pickup_sprite_palette, false);
		spr_on[t] = false;
	}
}

void handle_pickups()
{
	for (unsigned char t = 0; t < pickup_max; t++)
	{
		if (pickup_state[t] > 0)
		{
			unsigned char sprite = pickup_sprite_first + t;
			pickup_y[t] += player_speed;
			if ((pickup_y[t] > pickup_y_max) > 0)
			{
				spr_on[sprite] = false;
				pickup_state[t] = 0;
				continue;
			}

			if (pickup_state[t] == 2)
			{
				pickup_timer[t]--;
				if (pickup_timer[t] == 0)
				{
					spr_on[sprite] = false;
					pickup_state[t] = 0;
					continue;
				}
			}

			spr_x[sprite] = pickup_x[t] / x_divisor;
			unsigned short y = pickup_y[t] / y_divisor;
			spr_y_h[sprite] = y >> 8;
			spr_y_l[sprite] = (unsigned char)y;
		}
	}
}