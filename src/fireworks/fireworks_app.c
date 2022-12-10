/*============================================================================
	Aznable OS - Fireworks demo application

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
#include "../shared/sprite.h"
#include "../shared/tilemap.h"
#include "../shared/ui.h"
#include "../shared/music.h"
#include "../shared/sound.h"
#include "../shared/starfield.h"
#include "sprite_images.h"
#include "sound_samples.h"
#include "music_tracks.h"
#include "fireworks_app.h"
#include "fireworks_sparks.h"
#include <math.h>
#include <float.h>

// Area and units
const unsigned char x_divisor = 16;
const unsigned char y_divisor = 16;

const char *credits_text = "8-BITS WORTH OF FOLLOWERS MEANS AN 8-BIT DEMO!!!  CHEERS :)                            ";
unsigned char credits_index[100];
unsigned char credits_pos = 0;
unsigned char credits_len;

unsigned char max_spark_type = (sprite_index_sparks_count / 4) - 1;

void app_main()
{
	chram_size = chram_cols * chram_rows;
	clear_chars(0);
	clear_tilemap();
	clear_sprites();

	enable_starfield();
	set_starfield_speed_x(20.0f);

	unsigned char fire_timer = 16;
	setup_sparks();

	tilemap_offset_x = 0;
	tilemap_offset_y = 0;

	unsigned char cy = 12;
	unsigned short credits_entry_point = (cy * 32) + 21;
	credits_len = strlen(credits_text);
	for (unsigned char c = 0; c < credits_len; c++)
	{
		credits_index[c] = credits_text[c] - 32;
	}

	while (1)
	{
		vblank = CHECK_BIT(input0, INPUT_VBLANK);

		if (VBLANK_RISING)
		{
			fire_timer--;
			if (fire_timer == 0)
			{
				unsigned short x = rand_ushort(1200, 5500);
				unsigned short y = rand_ushort(1000, 2000);
			
				unsigned char t = rand_uchar(0, max_spark_type);
				for (int s = 0; s < 16; s++)
				{
					add_spark(x, y, t);
				}
				fire_timer = rand_uchar(20, 40);
			}

			tilemap_offset_x += 2;
			if (tilemap_offset_x >= 16)
			{
				tilemap_offset_x -= 16;
				scroll_tilemap_left();

				tilemapram[credits_entry_point] = credits_index[credits_pos];
				credits_pos++;
				if (credits_pos >= credits_len)
				{
					credits_pos = 0;
				}
			}
			update_tilemap_offset();

			handle_sparks();
			update_sprites();
		}

		vblank_last = vblank;
	}
}
