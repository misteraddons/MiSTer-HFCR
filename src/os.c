/*============================================================================
	Aznable OS - Main application

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

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "sys.h"
#include "ps2.h"
#include "ui.h"
#include "sprite.h"
#include "audio.h"
#include "music.h"

#include "zorblaxx_app.h"

// Main entry
void main()
{
	// Setup charmap
	chram_size = chram_cols * chram_rows;
	clear_bgcolor(0);
	clear_chars(0);

	// init_audio();

	channel_on[0] = 0;
	// ay_write(0x08, 0x00);
	// ay_set_ch(0, channel_pos[0]);

	channel_on[1] = 0;
	// ay_write(0x09, 0x00);
	// ay_set_ch(1, channel_pos[1]);

	app_zorblaxx();
}
