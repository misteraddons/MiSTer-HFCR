/*============================================================================
	Aznable OS - Particle routines

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
#include "particles.h"
#include "sprite_images.h"
#include "raiders_scene.h"

bool particle_on[const_particle_max];
unsigned char particle_timer[const_particle_max];
unsigned char particle_type[const_particle_max];
unsigned char particle_first_frame[const_particle_max];
unsigned char particle_frame_count[const_particle_max];
unsigned short particle_x[const_particle_max];
unsigned short particle_y[const_particle_max];
signed short particle_v_x[const_particle_max];
signed short particle_v_y[const_particle_max];

void init_particles()
{
	for (unsigned char p = 0; p < const_particle_max; p++)
	{
		unsigned char s = p + const_particle_sprite_first;
		enable_sprite(s, sprite_palette_particles, sprite_size_particles, 0);
		spr_on[s] = 0;
	}
}

unsigned char spawn_particle(unsigned short x, unsigned short y, unsigned char type, unsigned char firstFrame, unsigned char frameCount)
{
	for (unsigned char pt = 0; pt < const_particle_max; pt++)
	{
		if (!particle_on[pt])
		{
			particle_on[pt] = true;
			particle_x[pt] = x;
			particle_y[pt] = y;
			particle_type[pt] = type;
			particle_timer[pt] = particle_timer_max;
			particle_first_frame[pt] = sprite_index_particles_first + firstFrame;
			particle_frame_count[pt] = frameCount;
			unsigned char ps = const_particle_sprite_first + pt;
			spr_on[ps] = 1;
			spr_index[ps] = particle_first_frame[pt];
			return pt;
		}
	}
	return 255;
}

void kill_particle(unsigned char p)
{
	unsigned char s = const_particle_sprite_first + p;
	spr_on[s] = false;
	particle_on[p] = false;
}

void update_particles()
{
	// Particles
	for (unsigned char p = 0; p < const_particle_max; p++)
	{
		if (particle_on[p])
		{
			unsigned char s = const_particle_sprite_first + p;
			particle_timer[p]--;
			if (particle_timer[p] == 0)
			{
				if (spr_index[s] == particle_first_frame[p] + (particle_frame_count[p] - 1))
				{
					switch (particle_type[p])
					{
					case 1: // loop!
						spr_index[s] = particle_first_frame[p];
						break;
					default:
						spr_on[s] = 0;
						particle_on[p] = 0;
						continue;
					}
				}
				else
				{
					spr_index[s]++;
				}
				particle_timer[p] = particle_timer_max;
			}
			set_sprite_position(s, (particle_x[p] / scene_scale) - scroll_x, particle_y[p] / scene_scale);
			particle_x[p] += particle_v_x[p];
			particle_y[p] += particle_v_y[p];
		}
	}
}