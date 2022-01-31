/*============================================================================
	Aznable OS - Sound test

	Author: Jim Gregory - https://github.com/JimmyStones/
	Version: 1.0
	Date: 2022-01-31

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
#include "../shared/ps2.h"
#include "../shared/sprite.h"
#include "../shared/sound.h"
#include "../shared/music.h"
#include "../shared/tilemap.h"
#include "../shared/starfield.h"
#include "sprite_images.h"
#include "sound_samples.h"
#include "music_tracks.h"
#include <math.h>
#include <float.h>

float time;

void app_main()
{
	chram_size = chram_cols * chram_rows;
	clear_chars(0);
	enable_starfield();

	for (unsigned char s = 0; s < const_sound_sample_used; s++)
	{
		write_stringf("%d: Play ", 0xFF, 5, 5 + (s * 2), s + 1);
	}

	unsigned short frame = 0;

	unsigned char play_wait = 0;

	// play_music(const_music_gameover, 1);

	bool star_x = 1;

	while (1)
	{
		vblank = CHECK_BIT(input0, INPUT_VBLANK);

		if (VBLANK_RISING)
		{
			write_stringf("frame %3d", 0xFF, 0, 29, frame);
			frame++;

			if (play_wait > 0)
			{
				play_wait--;
			}
			else
			{
				handle_ps2();
				if (kbd_pressed)
				{
					unsigned char s = kbd_ascii - 49;
					if (s < const_sound_sample_used)
					{
						write_stringf("playing %2d", 0xFF, 5, 20, s);
						play_sound(s);
						play_wait = 15;
					}
				}
			}

			if (star_x)
			{
				signed short x = sinf(time) * 100;
				set_starfield_speed_x(x);
			}
			else
			{
				signed short y = cosf(time) * 100;
				set_starfield_speed_y(y);
				time += 0.05f;
			}

			star_x = !star_x;
		}

		vblank_last = vblank;
	}
}

// Main entry
void main()
{
	app_main();
}
