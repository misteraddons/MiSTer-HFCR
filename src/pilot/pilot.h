
#ifndef PILOT_H
#define PILOT_H

// Constants
#define direction_count 16
#define screen_center_x 176
#define screen_center_y 144
#define scale (unsigned short)128
#define scale_half 64

// Sprite indexes
#define const_particle_sprite_first 0
#define const_projectile_sprite_first 8
#define player_sprite 16
#define const_enemy_sprite_first 17

extern signed short scroll_v_x;
extern signed short scroll_v_y;

#endif