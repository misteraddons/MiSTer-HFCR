/*============================================================================
	Aznable OS - Zorblaxx demo application - Player routines

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

#include "sys.h"
#include "sprite.h"
#include "zorblaxx_app.h"
#include "zorblaxx_player.h"
#include "zorblaxx_trails.h"
#include "zorblaxx_asteroids.h"
#include "zorblaxx_explosions.h"

// Player
const unsigned char player_sprite = 11;
unsigned char player_sprite_palette = 1;
const signed char player_max_speed = 20;
const unsigned char player_accel = 3;
const unsigned char player_trail_frequency = 12;
const unsigned char player_trail_speed = 3;
const unsigned char player_trail_lifespan = 5;
unsigned short player_x;
unsigned short player_y;
signed char player_xs = 0;
signed char player_ys = 0;
unsigned short player_x_min;
unsigned short player_x_max;
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
unsigned char player_hit = 0;

// Player
void setup_player(unsigned short x, unsigned short y)
{
	// Player bounds
	player_x_min = 16 * x_divisor;
	player_x_max = 320 * x_divisor;
	player_y_min = 20 * y_divisor;
	player_y_max = 216 * y_divisor;

	// Player initial position
	player_x = x * x_divisor;
	player_y = y * y_divisor;
	player_speed = player_speed_min;
	player_xs = 0;
	player_ys = 0;

	player_invincible_timer = 0;
	player_invincible_flash = 0;

	// Initialise player sprite
	spr_index[player_sprite] = player_sprite_index_default;
	enable_sprite(player_sprite, player_sprite_palette, false);
	spr_x[player_sprite] = player_x / x_divisor;
	spr_y_h[player_sprite] = y >> 8;
	spr_y_l[player_sprite] = (unsigned char)y;

	// Trails
	player_trail_timer = player_trail_frequency;

	// Score
	player_score = 0;
	player_score_timer = 0;

	// Trigger invincibility
	player_invincible_timer = player_invincible_timeout;
}

void handle_player()
{
	if (player_respawn_timer > 0)
	{
		if (player_speed > player_speed_min)
		{
			player_speed--;
		}
		player_respawn_timer--;
		if (player_respawn_timer == 0)
		{
			setup_player(176, 216);
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
			add_explosion(0, 1);
			add_explosion(1, 3);
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
	if (player_x < player_x_min)
	{
		player_x = player_x_min;
		if (player_xs < 0)
		{
			player_xs = 0;
		}
	}
	else if (player_x > player_x_max)
	{
		player_x = player_x_max;
		if (player_xs > 0)
		{
			player_xs = 0;
		}
	}

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