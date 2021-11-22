#pragma once
#include "sprite.c"

// Player
const unsigned char player_sprite = 12;
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

#define player_sprite_index_default meteor_sprite_index_count
#define player_sprite_index_left player_sprite_index_default + 2
#define player_sprite_index_right player_sprite_index_default + 3

// Trails
#define const_trail_max 12
unsigned char trail_max = const_trail_max;
unsigned char trail_sprite_first = 0;
unsigned short trail_x[const_trail_max];
unsigned short trail_y[const_trail_max];
signed char trail_xs[const_trail_max];
signed char trail_ys[const_trail_max];
unsigned char trail_timer[const_trail_max];
unsigned short trail_y_max;
unsigned char trail_y_offset;
#define trail_sprite_index_first player_sprite_index_default + 4
#define trail_sprite_index_last trail_sprite_index_first + 3

// Meteors
#define const_meteor_max 16
unsigned char meteor_max = const_meteor_max;
unsigned char meteor_sprite_first = 16;
unsigned short meteor_x[const_meteor_max];
unsigned short meteor_y[const_meteor_max];
signed char meteor_xs[const_meteor_max];
signed char meteor_ys[const_meteor_max];
unsigned short meteor_timer[const_meteor_max];
unsigned short meteor_y_max;
#define meteor_sprite_index_first 0
#define meteor_sprite_index_count 4
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

	// Initialise player sprite
	spr_index[player_sprite] = 1;
	spr_on[player_sprite] = true;
	spr_x[player_sprite] = player_x / x_divisor;
	spr_y[player_sprite] = player_y;

	// Trails
	player_trail_timer = player_trail_frequency;

	// Score
	player_score = 0;
	player_score_timer = 0;
}

void update_meteordifficulty()
{
	meteor_difficulty_timer = 0;
	meteor_difficulty++;
	meteor_active_max = 3 + meteor_difficulty;
	if (meteor_active_max > meteor_max)
	{
		meteor_active_max = meteor_max;
	}
}

unsigned short get_meteortimer()
{
	unsigned char always_wait = meteor_difficulty < 10 ? 50 - (meteor_difficulty * 5) : 0;
	unsigned char random = (unsigned char)rand() + ((unsigned char)rand() / meteor_difficulty);
	return always_wait + random;
}

void setup_meteors()
{
	meteor_y_max = 256 * y_divisor;
	meteor_difficulty = 0;
	meteor_difficulty_frequency = 10 * 60;
	update_meteordifficulty();

	for (unsigned char m = 0; m < meteor_max; m++)
	{
		meteor_x[m] = ((unsigned char)rand() + x_divisor) * x_divisor;
		meteor_y[m] = 0;
		meteor_xs[m] = rand_schar(-8, 8);
		meteor_ys[m] = rand_uchar(4, 32);
		meteor_timer[m] = get_meteortimer();

		unsigned char sprite = meteor_sprite_first + m;
		spr_index[sprite] = meteor_sprite_index_first + rand_uchar(0, meteor_sprite_index_count - 1);
		spr_on[sprite] = false;
	}
}
void setup_trails()
{
	trail_y_max = 248 * y_divisor;
	trail_y_offset = (8 * y_divisor);
}

void add_player_trail()
{
	for (unsigned char t = 0; t < trail_max; t++)
	{
		if (trail_timer[t] == 0)
		{
			trail_x[t] = player_x + rand_schar(-1, 1);
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

void handle_player()
{
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
	spr_y[player_sprite] = player_y / y_divisor;

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
			spr_y[sprite] = trail_y[t] / y_divisor;
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
					spr_y[sprite] = meteor_y[m] / y_divisor;
				}
			}
		}
		else
		{
			spr_on[sprite] = 0;
		}
	}

	meteor_difficulty_timer++;
	if (meteor_difficulty_timer > meteor_difficulty_frequency)
	{
		update_meteordifficulty();
	}
}