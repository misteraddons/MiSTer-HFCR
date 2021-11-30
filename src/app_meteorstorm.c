/*============================================================================
	Aznable OS - Meteor Storm demo application

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

/*
	Sprite indexes:
	0-11	- Trails
	12		- Player
	13-15   - Explosions
	16-31	- Meteors
*/

#pragma once
#include "sprite.c"

// Meteor Storm

// Player
const unsigned char player_sprite = 11;
unsigned char player_sprite_palette = 1;
const signed char player_max_speed = 20;
const unsigned char player_accel = 3;
const unsigned char player_trail_frequency = 14;
const unsigned char player_trail_speed = 3;
const unsigned char player_trail_lifespan = 5;
unsigned short player_x;
unsigned short player_y;
signed char player_xs = 0;
signed char player_ys = 0;
unsigned short player_y_min;
unsigned short player_y_max;
unsigned char player_speed_min = 8;
unsigned char player_speed_max = 32;
unsigned char player_speed;
unsigned long player_score = 0;
unsigned char player_score_timer = 0;
unsigned char player_trail_timer = 1;
unsigned char player_invincible_timer = 0;
unsigned char player_invincible_flash = 0;
unsigned char player_invincible_timeout = 120;
unsigned char player_respawn_timer = 0;
unsigned char player_respawn_timeout = 120;
unsigned char player_explosion_timeout = 0;
bool player_hit = 0;

#define player_sprite_index_default meteor_sprite_index_count
#define player_sprite_index_left player_sprite_index_default + 2
#define player_sprite_index_right player_sprite_index_default + 3

// Trails
#define const_trail_max 11
unsigned char trail_max = const_trail_max;
unsigned char trail_sprite_first = 0;
unsigned char trail_sprite_palette = 1;
unsigned short trail_x[const_trail_max];
unsigned short trail_y[const_trail_max];
signed char trail_xs[const_trail_max];
signed char trail_ys[const_trail_max];
unsigned char trail_timer[const_trail_max];
unsigned short trail_y_max;
unsigned char trail_y_offset;
#define trail_sprite_index_first player_sprite_index_default + 4
#define trail_sprite_index_last trail_sprite_index_first + 3

// Explosions
#define const_explosion_max 4
unsigned char explosion_max = const_explosion_max;
unsigned char explosion_sprite_first = 29;
unsigned char explosion_sprite_palette = 1;
unsigned char explosion_timer[const_explosion_max];
#define explosion_sprite_index_first trail_sprite_index_last + 1
#define explosion_sprite_index_last explosion_sprite_index_first + 3
const unsigned char explosion_lifespan = 4;

// Meteors
#define const_meteor_max 16
unsigned char meteor_max = const_meteor_max;
unsigned char meteor_sprite_first = 13;
unsigned char meteor_sprite_palette = 0;
unsigned short meteor_x[const_meteor_max];
unsigned short meteor_y[const_meteor_max];
signed char meteor_xs[const_meteor_max];
signed char meteor_ys[const_meteor_max];
unsigned char meteor_timer[const_meteor_max];
unsigned short meteor_y_max;
#define meteor_sprite_index_first 0
#define meteor_sprite_index_count 6
unsigned char meteor_active_max;
unsigned char meteor_difficulty;
unsigned short meteor_difficulty_timer;
unsigned short meteor_difficulty_frequency;

// Area and units
const unsigned char x_divisor = 16;
const unsigned char y_divisor = 16;
unsigned short x_min = 2;
unsigned short x_max = 336;
unsigned short x_h_min;
unsigned short x_h_max;

void setup_area()
{
	x_h_min = (unsigned short)(x_min * x_divisor);
	x_h_max = (unsigned short)(x_max * x_divisor);
}

void setup_player()
{
	// Player bounds
	player_y_min = 20 * x_divisor;
	player_y_max = 216 * y_divisor;

	// Player initial position
	player_x = 160 * x_divisor;
	player_y = 216 * y_divisor;
	player_speed = player_speed_min;

	player_invincible_timer = 0;
	player_invincible_flash = 0;

	// Initialise player sprite
	spr_index[player_sprite] = 1;
	enable_sprite(player_sprite, player_sprite_palette, false);
	spr_x[player_sprite] = player_x / x_divisor;
	spr_y_l[player_sprite] = player_y;
	spr_y_h[player_sprite] = 0;

	// Trails
	player_trail_timer = player_trail_frequency;

	// Score
	player_score = 0;
	player_score_timer = 0;

	// Trigger invincibility
	player_invincible_timer = player_invincible_timeout;
}

void update_meteordifficulty()
{
	meteor_difficulty_timer = 0;
	meteor_difficulty++;
	meteor_active_max = 5 + meteor_difficulty;
	if (meteor_active_max > meteor_max)
	{
		meteor_active_max = meteor_max;
	}
}

unsigned char get_meteortimer()
{
	// unsigned char always_wait = meteor_difficulty < 10 ? 50 - (meteor_difficulty * 5) : 0;
	unsigned char always_wait = 0;
	unsigned char max_wait = 120 / meteor_difficulty;
	unsigned char random = rand_uchar(always_wait, max_wait);
	return random;
}

void setup_meteors()
{
	meteor_y_max = 256 * y_divisor;
	meteor_difficulty = 0;
	meteor_difficulty_frequency = 10 * 60;
	update_meteordifficulty();

	for (unsigned char m = 0; m < meteor_max; m++)
	{
		meteor_x[m] = rand_uchar(24, 296);
		meteor_y[m] = 0;
		meteor_xs[m] = rand_schar(-8, 8);
		meteor_ys[m] = rand_uchar(4, 16 + meteor_difficulty);
		meteor_timer[m] = get_meteortimer();

		unsigned char sprite = meteor_sprite_first + m;
		spr_index[sprite] = meteor_sprite_index_first + rand_uchar(0, meteor_sprite_index_count - 1);
		enable_sprite(sprite, meteor_sprite_palette, true);
		spr_on[sprite] = false;
	}
}
void setup_trails()
{
	trail_y_max = 248 * y_divisor;
	trail_y_offset = (8 * y_divisor);
	for (int t = trail_sprite_first; t < trail_sprite_first + trail_max; t++)
	{
		enable_sprite(t, trail_sprite_palette, false);
		spr_on[t] = false;
	}
}
void setup_explosions()
{
	for (int e = explosion_sprite_first; e < explosion_sprite_first + explosion_max; e++)
	{
		enable_sprite(e, explosion_sprite_palette, false);
		spr_on[e] = false;
	}
}

void add_player_trail()
{
	for (unsigned char t = 0; t < trail_max; t++)
	{
		if (trail_timer[t] == 0)
		{
			trail_x[t] = player_x;
			trail_y[t] = player_y + (trail_y_offset - player_trail_speed);
			unsigned char spread = 3 + (player_speed / 8);
			trail_xs[t] = rand_schar(-spread, spread);
			trail_ys[t] = player_trail_speed;
			trail_timer[t] = player_trail_lifespan;
			unsigned char sprite = trail_sprite_first + t;
			spr_on[sprite] = true;
			spr_index[sprite] = trail_sprite_index_first;
			return;
		}
	}
}

void add_explosion(unsigned char count)
{
	for (unsigned char e = 0; e < explosion_max; e++)
	{
		if (explosion_timer[e] == 0)
		{
			explosion_timer[e] = rand_uchar(2, 7);
			unsigned char sprite = explosion_sprite_first + e;
			spr_on[sprite] = true;
			spr_index[sprite] = explosion_sprite_index_first;
			spr_x[sprite] = (player_x + (signed short)rand_schar(-32, 64)) / x_divisor;
			unsigned short y = (player_y + (signed short)rand_schar(-32, 64)) / y_divisor;
			spr_y_h[sprite] = y >> 8;
			spr_y_l[sprite] = (unsigned char)y;
			count--;
			if (count == 0)
			{
				return;
			}
		}
	}
}

void handle_player()
{
	if (player_respawn_timer > 0)
	{
		player_respawn_timer--;
		if (player_respawn_timer == 0)
		{
			setup_player();
		}
		return;
	}

	if (player_invincible_timer > 0)
	{
		player_hit = false;
		player_invincible_timer--;
		player_invincible_flash++;

		if (player_invincible_timer == 0)
		{
			enable_sprite(player_sprite, player_sprite_palette, true);
		}
		else
		{
			if (player_invincible_flash == 4)
			{
				player_invincible_flash = 0;
				spr_on[player_sprite] = !spr_on[player_sprite];
			}
		}
	}
	else
	{
		if (player_hit)
		{
			player_hit = false;
			add_explosion(4);
			player_respawn_timer = player_respawn_timeout;
			spr_on[player_sprite] = false;
		}
	}

	if (player_xs > 0)
	{
		player_xs--;
	}
	else if (player_xs < 0)
	{
		player_xs++;
	}
	if (player_ys > 0)
	{
		player_ys--;
	}
	else if (player_ys < 0)
	{
		player_ys++;
	}
	if (CHECK_BIT(joystick[0], 0) && player_xs < player_max_speed)
	{
		player_xs += player_accel;
	}
	if (CHECK_BIT(joystick[0], 1) && player_xs > -player_max_speed)
	{
		player_xs -= player_accel;
	}
	if (CHECK_BIT(joystick[0], 2) && player_ys < player_max_speed)
	{
		player_ys += player_accel;
	}
	if (CHECK_BIT(joystick[0], 3) && player_ys > -player_max_speed)
	{
		player_ys -= player_accel;
	}

	if (CHECK_BIT(joystick[0], 4))
	{
		if (player_speed < player_speed_max)
		{
			player_speed++;
		}
	}
	else
	{
		if (player_speed > player_speed_min)
		{
			player_speed--;
		}
	}

	spr_index[player_sprite] = player_xs < -2 ? player_sprite_index_left : player_xs > 2 ? player_sprite_index_right
																						 : player_sprite_index_default;

	player_x += player_xs;
	player_y += player_ys;
	if (player_y < player_y_min)
	{
		player_y = player_y_min;
		if (player_ys < 0)
		{
			player_ys = 0;
		}
	}
	else if (player_y > player_y_max)
	{
		player_y = player_y_max;
		if (player_ys > 0)
		{
			player_ys = 0;
		}
	}
	spr_x[player_sprite] = player_x / x_divisor;
	
	unsigned short y = player_y / y_divisor;
	spr_y_h[player_sprite] = y >> 8;
	spr_y_l[player_sprite] = (unsigned char)y;

	// Trail
	player_trail_timer--;
	if (player_trail_timer <= 0)
	{
		player_trail_timer = player_trail_frequency - ((player_speed * 10) / 50);
		if (player_trail_timer <= 0)
		{
			player_trail_timer = 1;
		}
		add_player_trail();
	}

	// Score
	player_score_timer += player_speed;
	if (player_score_timer >= 100)
	{
		player_score_timer -= 100;
		player_score++;
	}
}

void handle_trails()
{
	for (unsigned char t = 0; t < trail_max; t++)
	{
		if (trail_timer[t] > 0)
		{
			unsigned char sprite = trail_sprite_first + t;
			trail_y[t] += trail_ys[t] + player_speed;
			if ((trail_y[t] > trail_y_max) > 0)
			{
				spr_on[sprite] = false;
				trail_timer[t] = 0;
				continue;
			}
			trail_timer[t]--;
			if (trail_timer[t] == 0)
			{
				spr_index[sprite]++;
				if (spr_index[sprite] > trail_sprite_index_last)
				{
					spr_on[sprite] = false;
				}
				else
				{
					trail_timer[t] = player_trail_lifespan;
				}
			}
			trail_x[t] += trail_xs[t];
			spr_x[sprite] = trail_x[t] / x_divisor;
			
			unsigned short y = trail_y[t] / y_divisor;
			spr_y_h[sprite] = y >> 8;
			spr_y_l[sprite] = (unsigned char)y;
		}
	}
}

void handle_explosions()
{
	for (unsigned char t = 0; t < explosion_max; t++)
	{
		if (explosion_timer[t] > 0)
		{
			explosion_timer[t]--;
			if (explosion_timer[t] == 0)
			{
				unsigned char sprite = explosion_sprite_first + t;
				spr_index[sprite]++;
				if (spr_index[sprite] > explosion_sprite_index_last)
				{
					spr_on[sprite] = false;
				}
				else
				{
					explosion_timer[t] = explosion_lifespan;
				}
			}
		}
	}
}

void handle_meteors()
{
	for (unsigned char m = 0; m < meteor_max; m++)
	{
		unsigned char sprite = meteor_sprite_first + m;
		if (m < meteor_active_max)
		{
			if (meteor_timer[m] > 0)
			{
				meteor_timer[m]--;
				if (meteor_timer[m] == 0)
				{
					spr_on[sprite] = 1;
					meteor_x[m] = ((unsigned char)rand() + x_divisor) * x_divisor;
					meteor_y[m] = 0;
				}
			}
			else
			{
				meteor_x[m] += meteor_xs[m];
				if (meteor_x[m] < x_h_min)
				{
					meteor_x[m] = x_h_max;
				}
				else if (meteor_x[m] > x_h_max)
				{
					meteor_x[m] = x_h_min;
				}
				if (meteor_y[m] >= meteor_y_max)
				{
					meteor_y[m] = 0;
					meteor_timer[m] = get_meteortimer();
					spr_on[sprite] = 0;
				}
				else
				{
					meteor_y[m] += meteor_ys[m] + player_speed;
					spr_x[sprite] = meteor_x[m] / x_divisor;
					unsigned short y = meteor_y[m] / y_divisor;
					spr_y_h[sprite] = y >> 8;
					spr_y_l[sprite] = (unsigned char)y;
				}
			}
		}
	}

	meteor_difficulty_timer++;
	if (meteor_difficulty_timer > meteor_difficulty_frequency)
	{
		update_meteordifficulty();
	}
}