
/*============================================================================
	Aznable OS - Zorblaxx demo application - Asteroid routines

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
#include "zorblaxx_asteroids.h"

#define const_meteor_max 16
unsigned char meteor_max = const_meteor_max;
unsigned char meteor_sprite_first = 12;
unsigned char meteor_sprite_palette = 0;
unsigned short meteor_x[const_meteor_max];
unsigned short meteor_y[const_meteor_max];
signed char meteor_xs[const_meteor_max];
signed char meteor_ys[const_meteor_max];
unsigned char meteor_timer[const_meteor_max];
unsigned short meteor_y_max;
unsigned char meteor_active_max;
unsigned char meteor_difficulty;
unsigned short meteor_difficulty_timer;
unsigned short meteor_difficulty_frequency;

void update_meteordifficulty()
{
	meteor_difficulty_timer = 0;
	meteor_difficulty++;
	meteor_active_max = 5 + meteor_difficulty;
	if (meteor_active_max > meteor_max)
	{
		meteor_active_max = meteor_max;
	}
}

unsigned char get_meteortimer()
{
	// unsigned char always_wait = meteor_difficulty < 10 ? 50 - (meteor_difficulty * 5) : 0;
	unsigned char always_wait = 0;
	unsigned char max_wait = 120 / meteor_difficulty;
	unsigned char random = rand_uchar(always_wait, max_wait);
	return random;
}

void setup_meteors()
{
	meteor_y_max = 256 * y_divisor;
	meteor_difficulty = 0;
	meteor_difficulty_frequency = 10 * 60;
	update_meteordifficulty();

	for (unsigned char m = 0; m < meteor_max; m++)
	{
		meteor_x[m] = rand_ushort(24, 296) * x_divisor;
		meteor_y[m] = 0;
		meteor_xs[m] = rand_schar(-(2 + (meteor_difficulty / 4)), 2 + (meteor_difficulty / 4));
		meteor_ys[m] = rand_uchar(4, 16 + meteor_difficulty);
		meteor_timer[m] = get_meteortimer();

		unsigned char sprite = meteor_sprite_first + m;
		spr_index[sprite] = meteor_sprite_index_first + rand_uchar(0, meteor_sprite_index_count - 1);
		enable_sprite(sprite, meteor_sprite_palette, true);
		spr_on[sprite] = false;
		spr_x[sprite] = meteor_x[m] / x_divisor;
		spr_y_h[sprite] = 0;
		spr_y_l[sprite] = 0;
	}
}

void handle_meteors()
{
	for (unsigned char m = 0; m < meteor_max; m++)
	{
		unsigned char sprite = meteor_sprite_first + m;
		if (m < meteor_active_max)
		{
			if (meteor_timer[m] > 0)
			{
				meteor_timer[m]--;
				if (meteor_timer[m] == 0)
				{
					spr_on[sprite] = 1;
					spr_index[sprite] = rand_uchar(meteor_sprite_index_first, meteor_sprite_index_first + meteor_sprite_index_count - 1);
				}
			}
			else
			{
				meteor_x[m] += meteor_xs[m];
				if (meteor_x[m] < x_h_min)
				{
					meteor_x[m] = x_h_max;
				}
				else if (meteor_x[m] > x_h_max)
				{
					meteor_x[m] = x_h_min;
				}
				if (meteor_y[m] >= meteor_y_max)
				{
					meteor_x[m] = rand_ushort(24, 296) * x_divisor;
					meteor_y[m] = 0;
					meteor_xs[m] = rand_schar(-(2 + (meteor_difficulty / 4)), 2 + (meteor_difficulty / 4));
					meteor_ys[m] = rand_uchar(4, 16 + meteor_difficulty);
					meteor_timer[m] = get_meteortimer();
					spr_on[sprite] = 0;
				}
				else
				{
					meteor_y[m] += meteor_ys[m] + scroll_speed;
					spr_x[sprite] = meteor_x[m] / x_divisor;
					unsigned short y = meteor_y[m] / y_divisor;
					spr_y_h[sprite] = y >> 8;
					spr_y_l[sprite] = (unsigned char)y;
				}
			}
		}
	}

	meteor_difficulty_timer++;
	if (meteor_difficulty_timer > meteor_difficulty_frequency)
	{
		update_meteordifficulty();
	}
}