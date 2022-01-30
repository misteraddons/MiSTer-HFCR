/*============================================================================
	Aznable OS - Pilot demo application - Projectile routines

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

#ifndef PILOT_PROJECTILES_H
#define PILOT_PROJECTILES_H

#define const_projectile_max 8
#define projectile_timer_max 40
extern bool projectile_on[];
extern unsigned char projectile_timer[];
extern unsigned short projectile_x[];
extern unsigned short projectile_y[];
extern signed short projectile_v_x[];
extern signed short projectile_v_y[];

extern void init_projectiles();
extern void kill_projectile(unsigned char p);
extern void spawn_projectile(unsigned short x, unsigned short y);
extern void handle_projectiles();

#endif