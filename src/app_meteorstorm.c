#pragma once
#include "sprite.c"

// Player
const unsigned char player_sprite = 0;
const signed char player_max_speed = 20;
const unsigned char player_accel = 3;
const unsigned char player_trail_frequency = 10;
const unsigned char player_trail_speed = 5;
const unsigned char player_trail_lifespan = 60;
unsigned short player_x;
unsigned short player_y;
signed char player_xs = 0;
signed char player_ys = 0;
unsigned short player_y_min;
unsigned short player_y_max;
unsigned int player_score = 0;
unsigned char player_trail_timer = 1;

// Trails
#define const_trail_max 16
unsigned char trail_max = const_trail_max;
unsigned char trail_sprite_first = 8;
unsigned short trail_x[const_trail_max];
unsigned short trail_y[const_trail_max];
signed char trail_xs[const_trail_max];
signed char trail_ys[const_trail_max];
unsigned char trail_timer[const_trail_max];

// Meteors
#define const_meteor_max 16
unsigned char meteor_max = const_meteor_max;
unsigned char meteor_sprite_first = 16;
unsigned short meteor_x[const_meteor_max];
unsigned short meteor_y[const_meteor_max];
signed char meteor_xs[const_meteor_max];
unsigned char meteor_timer[const_meteor_max];

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
	player_y_max = 200 * y_divisor;

	// Player initial position
	player_x = 160 * x_divisor;
	player_y = 216 * y_divisor;

	// Initialise player sprite
	spr_index[player_sprite] = 1;
	spr_on[player_sprite] = true;
	spr_x[player_sprite] = player_x / x_divisor;
	spr_y[player_sprite] = player_y;

	// Trails
	player_trail_timer = player_trail_frequency;
}

void setup_meteors()
{
	for (unsigned char m = 0; m < meteor_max; m++)
	{
		meteor_x[m] = ((unsigned char)rand() + 16) * x_divisor;
		meteor_y[m] = 0;
		meteor_xs[m] = (signed char)rand() / 16;
		meteor_timer[m] = (unsigned char)rand();

		unsigned char sprite = meteor_sprite_first + m;
		spr_index[sprite] = 0;
		spr_on[sprite] = false;
	}
}

void add_player_trail()
{
	for (int t = 0; t < trail_max; t++)
	{
		if (trail_timer[t] == 0)
		{
			trail_x[t] = player_x;
			trail_y[t] = player_y + (8 * y_divisor);
			trail_xs[t] = rand_schar(-3, 3);
			trail_ys[t] = player_trail_speed;
			trail_timer[t] = player_trail_lifespan;
			unsigned char sprite = trail_sprite_first + t;
			spr_on[sprite] = true;
			spr_index[sprite] = rand_uchar(4, 7);
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
	spr_index[player_sprite] = player_xs < -2 ? 2 : player_xs > 2 ? 3
																  : 1;
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
	if (player_y > player_y_max)
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
		player_trail_timer = player_trail_frequency;
		add_player_trail();
	}
}

void handle_trails()
{
	for (unsigned char t = 0; t < trail_max; t++)
	{
		if (trail_timer[t] > 0)
		{
			unsigned char sprite = trail_sprite_first + t;
			trail_x[t] += trail_xs[t];
			trail_y[t] += trail_ys[t];
			spr_x[sprite] = trail_x[t] / x_divisor;
			spr_y[sprite] = trail_y[t] / y_divisor;
			trail_timer[t]--;
			if (trail_timer[t] == 0)
			{
				spr_on[sprite] = false;
			}
		}
	}
}

void handle_meteors()
{
	for (unsigned char m = 0; m < meteor_max; m++)
	{
		unsigned char sprite = meteor_sprite_first + m;
		if (meteor_timer[m] > 0)
		{
			meteor_timer[m]--;
			if (meteor_timer[m] == 0)
			{
				spr_on[sprite] = 1;
				meteor_x[m] = ((unsigned char)rand() + 16) * x_divisor;
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
			if (meteor_x[m] > x_h_max)
			{
				meteor_x[m] = x_h_min;
			}
			if (meteor_y[m] == 256)
			{
				meteor_y[m] = 0;
				meteor_timer[m] = (unsigned char)rand();
				spr_on[sprite] = 0;
			}
			else
			{
				meteor_y[m]++;
			}

			spr_x[sprite] = meteor_x[m] / x_divisor;
			spr_y[sprite] = meteor_y[m];
		}
	}
}