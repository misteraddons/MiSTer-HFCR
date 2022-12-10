/*============================================================================
	Aznable OS - Raiders demo

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
#include "../shared/ui.h"
#include "sprite_images.h"
#include "raiders_app.h"

int player_sprite = 0;
unsigned char player_x = 50;
unsigned char player_y = 50;

void app_main()
{
	chram_size = chram_cols * chram_rows;
	clear_chars(0);
	clear_sprites();

	enable_sprite(player_sprite, sprite_palette_stroudman, sprite_size_stroudman, 1);
	set_sprite_position(player_sprite, player_x, player_y);
	spr_index[player_sprite] = sprite_index_stroudman_first;
	int t = 0;
	bool d = 1;

	while (1)
	{
		vblank = CHECK_BIT(input0, INPUT_VBLANK);

		if (VBLANK_RISING)
		{

			t++;
			if (t == 4)
			{
				t = 0;
				if (d == 1)
				{
					spr_index[player_sprite]++;
				}
				else
				{
					spr_index[player_sprite]--;
				}
				if (spr_index[player_sprite] == 2 || spr_index[player_sprite] == 0)
				{
					if(d == 1) {d=0;}else{d=1;}
				}
			}

			write_stringf("%d", 0xFF, 0, 0, d);
			write_stringf("%d", 0xFF, 0, 1, t);
			write_stringf("%d", 0xFF, 0, 2, spr_index[player_sprite]);

			update_sprites();
		}

		vblank_last = vblank;
	}
}
