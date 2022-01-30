/*============================================================================
	Aznable OS - Pilot demo application - Projectiles routines

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
#include "pilot.h"
#include "projectiles.h"
#include "sprite_images.h"

bool projectile_on[const_projectile_max];
unsigned char projectile_timer[const_projectile_max];
unsigned short projectile_x[const_projectile_max];
unsigned short projectile_y[const_projectile_max];
signed short projectile_v_x[const_projectile_max];
signed short projectile_v_y[const_projectile_max];

void init_projectiles()
{
	for (unsigned char p = 0; p < const_projectile_max; p++)
	{
		unsigned char s = p + const_projectile_sprite_first;
		enable_sprite(s, sprite_palette_shots, sprite_size_shots, 1);
		spr_on[s] = 0;
	}
}

void kill_projectile(unsigned char p)
{
	spr_on[const_projectile_sprite_first + p] = 0;
	projectile_on[p] = 0;
}

void spawn_projectile(unsigned short x, unsigned short y)
{
	for (unsigned char pt = 0; pt < const_projectile_max; pt++)
	{
		if (!projectile_on[pt])
		{
			projectile_on[pt] = true;
			projectile_x[pt] = x;
			projectile_y[pt] = y;
			// projectile_v_x[pt] = (vector_x[player_a] * -player_thrust) >> 8;
			// projectile_v_y[pt] = (vector_y[player_a] * -player_thrust) >> 8;
			projectile_timer[pt] = projectile_timer_max;
			unsigned char ps = const_projectile_sprite_first + pt;
			spr_on[ps] = 1;
			spr_index[ps] = sprite_index_trails_first;
			break;
		}
	}
}

void handle_projectiles()
{
	for (unsigned char p = 0; p < const_projectile_max; p++)
	{
		if (projectile_on[p])
		{
			projectile_timer[p]--;
			if (projectile_timer[p] == 0)
			{
				kill_projectile(p);
				continue;
			}
			set_sprite_position(const_projectile_sprite_first + p, projectile_x[p] / scale, projectile_y[p] / scale);
			projectile_x[p] -= scroll_v_x;
			projectile_y[p] -= scroll_v_y;
			projectile_x[p] += projectile_v_x[p];
			projectile_y[p] += projectile_v_y[p];
		}
	}
}