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

#ifndef PILOT_PARTICLES_H
#define PILOT_PARTICLES_H

#define const_particle_max 8
#define particle_timer_max 4
#define const_particle_sprite_first 16

extern bool particle_on[];
extern unsigned char particle_timer[];
extern unsigned short particle_x[];
extern unsigned short particle_y[];
extern signed short particle_v_x[];
extern signed short particle_v_y[];

extern void init_particles();
extern void kill_particle(unsigned char p);
extern unsigned char spawn_particle(unsigned short x, unsigned short y, unsigned char type, unsigned char firstFrame, unsigned char frameCount);
extern void update_particles();

#endif