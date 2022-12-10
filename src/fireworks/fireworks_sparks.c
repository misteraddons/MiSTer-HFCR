/*============================================================================
	Aznable OS - Fireworks demo - Sparks

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

#include "../shared/sys.h"
#include "../shared/ui.h"
#include "../shared/sprite.h"
#include "sprite_images.h"
#include "fireworks_app.h"
#include "fireworks_sparks.h"

#define const_spark_max 32
unsigned char spark_max = const_spark_max;
unsigned short spark_x[const_spark_max];
unsigned short spark_y[const_spark_max];
signed char spark_xs[const_spark_max];
signed char spark_ys[const_spark_max];
unsigned char spark_timer[const_spark_max];
unsigned char spark_frame[const_spark_max];
unsigned char spark_life[const_spark_max];
unsigned short spark_y_max;
unsigned char spark_x_offset;
unsigned char spark_y_offset;

unsigned char spark_lifespan_min = 8;
unsigned char spark_lifespan_rand = 20;

void setup_sparks()
{
	spark_y_max = 272 * y_divisor;
	spark_x_offset = (4 * x_divisor);
	spark_y_offset = (12 * y_divisor);
	for (int t = spark_sprite_first; t < spark_sprite_first + spark_max; t++)
	{
		enable_sprite(t, sprite_palette_sparks, sprite_size_sparks, false);
		spr_on[t] = false;
	}
}

void add_spark(unsigned short x, unsigned short y, unsigned char type)
{
	for (unsigned char s = 0; s < spark_max; s++)
	{
		if (spark_timer[s] == 0)
		{
			unsigned char spread = 30;
			spark_xs[s] = rand_schar(-spread, spread);
			spark_ys[s] = rand_schar(-spread, spread);

			spark_x[s] = x;
			spark_y[s] = y;

			spark_frame[s] = 0;

			spark_life[s] = rand_uchar(spark_lifespan_min, spark_lifespan_rand);
			spark_timer[s] = spark_life[s];
			unsigned char sprite = spark_sprite_first + s;
			enable_sprite(sprite, sprite_palette_sparks, sprite_size_sparks, false);
			spr_index[sprite] = sprite_index_sparks_first + (type * 4);
			return;
		}
	}
}

void handle_sparks()
{
	for (unsigned char s = 0; s < spark_max; s++)
	{
		if (spark_timer[s] > 0)
		{
			unsigned char sprite = spark_sprite_first + s;
			spark_ys[s] += 1;
			spark_y[s] += spark_ys[s];
			spark_x[s] -= 8;
			spark_timer[s]--;
			if (spark_timer[s] == 0)
			{
				spr_index[sprite]++;
				spark_frame[s]++;
				if (spark_frame[s] == 4)
				{
					spr_on[sprite] = false;
				}
				else
				{
					spark_timer[s] = spark_life[s];
				}
			}
			spark_x[s] += spark_xs[s];

			set_sprite_position(sprite, spark_x[s] / x_divisor, spark_y[s] / y_divisor);
		}
	}
}