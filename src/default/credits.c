/*============================================================================
	Aznable OS - Credits

	Author: Jim Gregory - https://github.com/JimmyStones/
	Version: 1.0
	Date: 2022-01-05

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
#include "../shared/music.h"
#include "../shared/tilemap.h"
#include "credits.h"
#include "inputtester_sys.h"

const char *credits_text = "CODE AND GFX_-_JIMMYSTONES___MUSIC_-_DARRIN CARDANI___TESTING_-_PORKCHOP EXPRESS_SORGELIG_M. WALRUS___EXTRA THANKS_-_ALANSWX_SORGELIG___";
unsigned char credits_pos = 0;
unsigned short credits_entry_pos = (16 * 32);

void app_credits()
{
	clear_chars(0);
	clear_sprites();
	clear_tilemap();
	stop_music();

	starfield1[0] = 1;
	starfield1[2] = 4;
	
	starfield2[0] = 1;
	starfield2[2] = 8;
	
	starfield3[0] = 1;
	starfield3[2] = 16;
	
	tilemap_offset_x = 0;
	tilemap_offset_y = 0;

	char credits_line[22];
	credits_pos = 0;

	while (1)
	{
		vblank = CHECK_BIT(input0, INPUT_VBLANK);

		if (VBLANK_RISING)
		{
			tilemap_offset_y += 2;
			if (tilemap_offset_y >= 16)
			{
				tilemap_offset_y -= 16;

				scroll_tilemap_up();

				unsigned char d;
				unsigned char c;
				unsigned char credits_line_len = 0;
				for (d = 0; d < 22; d++)
				{
					c = credits_text[credits_pos];
					credits_pos++;
					if (c == '_')
					{
						break;
					}
					else
					{
						credits_line[d] = c;
						credits_line_len++;
					}
					if (credits_pos == strlen(credits_text))
					{
						credits_pos = 0;
						break;
					}
				}
				signed char credits_line_pre = (22 - credits_line_len) / 2;
				for (d = 0; d < 22; d++)
				{
					c = 0;
					signed char i = d - credits_line_pre;
					if (i >= 0 && i < credits_line_len)
					{
						c = (credits_line[i] != '-') ? (credits_line[i] - 45) : 1;
					}
					tilemapram[credits_entry_pos + d] = c;
				}
			}
			update_tilemap_offset();
		}

		if (VBLANK_FALLING)
		{
			basic_input();
			if (input_a || input_b || input_select || input_start)
			{
				break;
			}
		}

		vblank_last = vblank;
	}

	clear_chars(0);
	clear_sprites();
	clear_tilemap();
	stop_music();

	starfield1[0] = 0;
	starfield2[0] = 0;
	starfield3[0] = 0;

	state = defaultstate;
}