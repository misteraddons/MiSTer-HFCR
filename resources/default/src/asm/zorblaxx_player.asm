;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.8.0 #10562 (Linux)
;--------------------------------------------------------
	.module zorblaxx_player
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _player_destroyed
	.globl _add_explosion
	.globl _add_player_trail
	.globl _play_sound
	.globl _enable_sprite
	.globl _set_sprite_position_x
	.globl _set_sprite_position
	.globl _rand_uchar
	.globl _player_target_maxspeed
	.globl _player_target_divider
	.globl _player_hit
	.globl _player_respawn_timer
	.globl _player_invincible_flash
	.globl _player_invincible_timer
	.globl _player_trail_timer
	.globl _player_ys
	.globl _player_xs
	.globl _player_y_diff
	.globl _player_x_diff
	.globl _player_y_target
	.globl _player_x_target
	.globl _player_ready_y
	.globl _player_ready_x
	.globl _player_ready
	.globl _player_lives_changed
	.globl _player_lives
	.globl _player_speed
	.globl _player_y_max
	.globl _player_y_min
	.globl _player_x_max
	.globl _player_x_min
	.globl _player_y
	.globl _player_x
	.globl _musicram
	.globl _sndram
	.globl _tilemapram
	.globl _tilemapctl
	.globl _spritecollisionram
	.globl _spriteram
	.globl _bgcolram
	.globl _fgcolram
	.globl _chram
	.globl _system_pause
	.globl _starfield
	.globl _timer
	.globl _timestamp
	.globl _ps2_mouse
	.globl _ps2_key
	.globl _spinner
	.globl _paddle
	.globl _analog_r
	.globl _analog_l
	.globl _joystick
	.globl _input0
	.globl _player_respawn_timeout
	.globl _player_invincible_timeout
	.globl _player_speed_warp
	.globl _player_speed_max
	.globl _player_speed_min
	.globl _player_trail_lifespan
	.globl _player_trail_speed
	.globl _player_trail_frequency
	.globl _player_accel
	.globl _player_max_speed
	.globl _set_player_target
	.globl _move_player_to_target
	.globl _setup_player
	.globl _handle_player
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
_input0	=	0x8000
_joystick	=	0x8100
_analog_l	=	0x8200
_analog_r	=	0x8300
_paddle	=	0x8400
_spinner	=	0x8500
_ps2_key	=	0x8600
_ps2_mouse	=	0x8700
_timestamp	=	0x8800
_timer	=	0x8900
_starfield	=	0x8a00
_system_pause	=	0x8a30
_chram	=	0x9800
_fgcolram	=	0xa000
_bgcolram	=	0xa800
_spriteram	=	0xb000
_spritecollisionram	=	0xb400
_tilemapctl	=	0x8c00
_tilemapram	=	0x8c10
_sndram	=	0x8b00
_musicram	=	0x8b10
_player_x::
	.ds 2
_player_y::
	.ds 2
_player_x_min::
	.ds 2
_player_x_max::
	.ds 2
_player_y_min::
	.ds 2
_player_y_max::
	.ds 2
_player_speed::
	.ds 1
_player_lives::
	.ds 1
_player_lives_changed::
	.ds 1
_player_ready::
	.ds 1
_player_ready_x::
	.ds 1
_player_ready_y::
	.ds 1
_player_x_target::
	.ds 2
_player_y_target::
	.ds 2
_player_x_diff::
	.ds 2
_player_y_diff::
	.ds 2
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
_player_xs::
	.ds 1
_player_ys::
	.ds 1
_player_trail_timer::
	.ds 1
_player_invincible_timer::
	.ds 1
_player_invincible_flash::
	.ds 1
_player_respawn_timer::
	.ds 1
_player_hit::
	.ds 1
_player_target_divider::
	.ds 1
_player_target_maxspeed::
	.ds 1
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area _DABS (ABS)
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area _HOME
	.area _GSINIT
	.area _GSFINAL
	.area _GSINIT
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area _HOME
	.area _HOME
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area _CODE
;zorblaxx_player.c:72: void set_player_target(unsigned short x, unsigned short y, unsigned char divider, unsigned char maxspeed)
;	---------------------------------
; Function set_player_target
; ---------------------------------
_set_player_target::
;zorblaxx_player.c:74: player_ready = 0;
	ld	hl,#_player_ready + 0
	ld	(hl), #0x00
;zorblaxx_player.c:75: player_ready_x = 0;
	ld	hl,#_player_ready_x + 0
	ld	(hl), #0x00
;zorblaxx_player.c:76: player_ready_y = 0;
	ld	hl,#_player_ready_y + 0
	ld	(hl), #0x00
;zorblaxx_player.c:77: player_x_target = x;
	ld	hl, #2+0
	add	hl, sp
	ld	a, (hl)
	ld	(#_player_x_target + 0),a
	ld	hl, #2+1
	add	hl, sp
	ld	a, (hl)
	ld	(#_player_x_target + 1),a
;zorblaxx_player.c:78: player_y_target = y;
	ld	hl, #4+0
	add	hl, sp
	ld	a, (hl)
	ld	(#_player_y_target + 0),a
	ld	hl, #4+1
	add	hl, sp
	ld	a, (hl)
	ld	(#_player_y_target + 1),a
;zorblaxx_player.c:79: player_target_divider = divider;
	ld	hl, #6+0
	add	hl, sp
	ld	a, (hl)
	ld	(#_player_target_divider + 0),a
;zorblaxx_player.c:80: player_target_maxspeed = maxspeed;
	ld	hl, #7+0
	add	hl, sp
	ld	a, (hl)
	ld	(#_player_target_maxspeed + 0),a
;zorblaxx_player.c:81: }
	ret
_player_max_speed:
	.db #0x14	;  20
_player_accel:
	.db #0x03	; 3
_player_trail_frequency:
	.db #0x0a	; 10
_player_trail_speed:
	.db #0x03	; 3
_player_trail_lifespan:
	.db #0x05	; 5
_player_speed_min:
	.db #0x0c	; 12
_player_speed_max:
	.db #0x20	; 32
_player_speed_warp:
	.db #0x40	; 64
_player_invincible_timeout:
	.db #0x78	; 120	'x'
_player_respawn_timeout:
	.db #0x78	; 120	'x'
;zorblaxx_player.c:83: void move_player_to_target()
;	---------------------------------
; Function move_player_to_target
; ---------------------------------
_move_player_to_target::
;zorblaxx_player.c:85: if (player_y != player_y_target)
	ld	a,(#_player_y + 0)
	ld	iy, #_player_y_target
	sub	a, 0 (iy)
	jr	NZ,00173$
	ld	a,(#_player_y + 1)
	ld	iy, #_player_y_target
	sub	a, 1 (iy)
	jp	Z,00110$
00173$:
;zorblaxx_player.c:87: player_y_diff = (((signed short)player_y_target - (signed short)player_y)) / (signed char)player_target_divider;
	ld	bc, (_player_y_target)
	ld	hl, (_player_y)
	ld	a, c
	sub	a, l
	ld	c, a
	ld	a, b
	sbc	a, h
	ld	b, a
	ld	a,(#_player_target_divider + 0)
	ld	e, a
	rla
	sbc	a, a
	ld	d, a
	push	de
	push	bc
	call	__divsint
	pop	af
	pop	af
	ld	(_player_y_diff), hl
;zorblaxx_player.c:88: if (player_y_diff == 0)
	ld	iy, #_player_y_diff
	ld	a, 1 (iy)
	or	a, 0 (iy)
	jr	NZ,00107$
;zorblaxx_player.c:90: player_y = player_y_target;
	ld	hl, (_player_y_target)
	ld	(_player_y), hl
	jr	00108$
00107$:
;zorblaxx_player.c:94: if (player_y_diff > player_target_maxspeed)
	ld	iy, #_player_target_maxspeed
	ld	c, 0 (iy)
	ld	b, #0x00
	ld	a, c
	ld	iy, #_player_y_diff
	sub	a, 0 (iy)
	ld	a, b
	sbc	a, 1 (iy)
	jp	PO, 00174$
	xor	a, #0x80
00174$:
	jp	P, 00104$
;zorblaxx_player.c:96: player_y_diff = player_target_maxspeed;
	ld	(_player_y_diff), bc
	jr	00105$
00104$:
;zorblaxx_player.c:100: if (player_y_diff < -player_target_maxspeed)
	xor	a, a
	sub	a, c
	ld	c, a
	ld	a, #0x00
	sbc	a, b
	ld	b, a
	ld	iy, #_player_y_diff
	ld	a, 0 (iy)
	sub	a, c
	ld	a, 1 (iy)
	sbc	a, b
	jp	PO, 00175$
	xor	a, #0x80
00175$:
	jp	P, 00105$
;zorblaxx_player.c:102: player_y_diff = -player_target_maxspeed;
	ld	(_player_y_diff), bc
00105$:
;zorblaxx_player.c:105: player_y += player_y_diff;
	ld	bc, (_player_y_diff)
	ld	hl, #_player_y
	ld	a, (hl)
	add	a, c
	ld	(hl), a
	inc	hl
	ld	a, (hl)
	adc	a, b
	ld	(hl), a
00108$:
;zorblaxx_player.c:107: unsigned short y = player_y / y_divisor;
	ld	hl,#_y_divisor + 0
	ld	c, (hl)
	ld	b, #0x00
	push	bc
	ld	hl, (_player_y)
	push	hl
	call	__divuint
	pop	af
	pop	af
	ld	c, l
	ld	b, h
;zorblaxx_player.c:108: spr_y_h[player_sprite] = y >> 8;
	ld	hl, #_spr_y_h+11
	ld	(hl), b
;zorblaxx_player.c:109: spr_y_l[player_sprite] = (unsigned char)y;
	ld	hl, #_spr_y_l+11
	ld	(hl), c
	jr	00111$
00110$:
;zorblaxx_player.c:113: player_ready_y = 1;
	ld	hl,#_player_ready_y + 0
	ld	(hl), #0x01
00111$:
;zorblaxx_player.c:115: if (player_x != player_x_target)
	ld	a,(#_player_x + 0)
	ld	iy, #_player_x_target
	sub	a, 0 (iy)
	jr	NZ,00176$
	ld	a,(#_player_x + 1)
	ld	iy, #_player_x_target
	sub	a, 1 (iy)
	jp	Z,00121$
00176$:
;zorblaxx_player.c:117: player_x_diff = (((signed short)player_x_target - (signed short)player_x)) / (signed short)player_target_divider;
	ld	bc, (_player_x_target)
	ld	hl, (_player_x)
	ld	a, c
	sub	a, l
	ld	c, a
	ld	a, b
	sbc	a, h
	ld	b, a
	ld	hl,#_player_target_divider + 0
	ld	e, (hl)
	ld	d, #0x00
	push	de
	push	bc
	call	__divsint
	pop	af
	pop	af
	ld	(_player_x_diff), hl
;zorblaxx_player.c:118: if (player_x_diff == 0)
	ld	iy, #_player_x_diff
	ld	a, 1 (iy)
	or	a, 0 (iy)
	jr	NZ,00118$
;zorblaxx_player.c:120: player_x = player_x_target;
	ld	hl, (_player_x_target)
	ld	(_player_x), hl
	jr	00119$
00118$:
;zorblaxx_player.c:124: if (player_x_diff > player_target_maxspeed)
	ld	iy, #_player_target_maxspeed
	ld	c, 0 (iy)
	ld	b, #0x00
	ld	a, c
	ld	iy, #_player_x_diff
	sub	a, 0 (iy)
	ld	a, b
	sbc	a, 1 (iy)
	jp	PO, 00177$
	xor	a, #0x80
00177$:
	jp	P, 00115$
;zorblaxx_player.c:126: player_x_diff = player_target_maxspeed;
	ld	(_player_x_diff), bc
	jr	00116$
00115$:
;zorblaxx_player.c:130: if (player_x_diff < -player_target_maxspeed)
	xor	a, a
	sub	a, c
	ld	c, a
	ld	a, #0x00
	sbc	a, b
	ld	b, a
	ld	iy, #_player_x_diff
	ld	a, 0 (iy)
	sub	a, c
	ld	a, 1 (iy)
	sbc	a, b
	jp	PO, 00178$
	xor	a, #0x80
00178$:
	jp	P, 00116$
;zorblaxx_player.c:132: player_x_diff = -player_target_maxspeed;
	ld	(_player_x_diff), bc
00116$:
;zorblaxx_player.c:135: player_x += player_x_diff;
	ld	bc, (_player_x_diff)
	ld	hl, #_player_x
	ld	a, (hl)
	add	a, c
	ld	(hl), a
	inc	hl
	ld	a, (hl)
	adc	a, b
	ld	(hl), a
00119$:
;zorblaxx_player.c:137: set_sprite_position_x(player_sprite, player_x / x_divisor);
	ld	hl,#_x_divisor + 0
	ld	c, (hl)
	ld	b, #0x00
	push	bc
	ld	hl, (_player_x)
	push	hl
	call	__divuint
	pop	af
	ex	(sp),hl
	ld	a, #0x0b
	push	af
	inc	sp
	call	_set_sprite_position_x
	pop	af
	inc	sp
	jr	00122$
00121$:
;zorblaxx_player.c:141: player_ready_x = 1;
	ld	hl,#_player_ready_x + 0
	ld	(hl), #0x01
00122$:
;zorblaxx_player.c:143: player_ready = player_ready_x && player_ready_y;
	ld	a,(#_player_ready_x + 0)
	or	a, a
	jr	Z,00125$
	ld	a,(#_player_ready_y + 0)
	or	a, a
	jr	NZ,00126$
00125$:
	xor	a, a
	jr	00127$
00126$:
	ld	a, #0x01
00127$:
	ld	(#_player_ready + 0),a
;zorblaxx_player.c:144: }
	ret
;zorblaxx_player.c:147: void setup_player(unsigned short x, unsigned short y, unsigned char lives)
;	---------------------------------
; Function setup_player
; ---------------------------------
_setup_player::
;zorblaxx_player.c:150: player_x_min = 32 * x_divisor;
	ld	hl,#_x_divisor + 0
	ld	b, (hl)
	ld	e, b
	ld	d, #0x00
	ld	iy, #_player_x_min
	ld	0 (iy), e
	ld	1 (iy), d
	ld	a, #0x05+1
	jr	00104$
00103$:
	sla	0 (iy)
	rl	1 (iy)
00104$:
	dec	a
	jr	NZ,00103$
;zorblaxx_player.c:151: player_x_max = 336 * x_divisor;
	ld	l, e
	ld	h, d
	add	hl, hl
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	ld	(_player_x_max), hl
;zorblaxx_player.c:152: player_y_min = 32 * y_divisor;
	ld	hl,#_y_divisor + 0
	ld	c, (hl)
	ld	e, c
	ld	d, #0x00
	ld	iy, #_player_y_min
	ld	0 (iy), e
	ld	1 (iy), d
	ld	a, #0x05+1
	jr	00106$
00105$:
	sla	0 (iy)
	rl	1 (iy)
00106$:
	dec	a
	jr	NZ,00105$
;zorblaxx_player.c:153: player_y_max = 244 * y_divisor;
	ld	l, e
	ld	h, d
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, hl
	ld	(_player_y_max), hl
;zorblaxx_player.c:156: player_x = x * x_divisor;
	ld	h, #0x00
	push	bc
	ld	l, b
	push	hl
	ld	hl, #6
	add	hl, sp
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	push	bc
	call	__mulint
	pop	af
	pop	af
	pop	bc
	ld	(_player_x), hl
;zorblaxx_player.c:157: player_y = y * y_divisor;
	ld	b, #0x00
	push	bc
	ld	hl, #6
	add	hl, sp
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	push	bc
	call	__mulint
	pop	af
	pop	af
	ld	(_player_y), hl
;zorblaxx_player.c:158: player_speed = player_speed_min;
	ld	a,(#_player_speed_min + 0)
	ld	(#_player_speed + 0),a
;zorblaxx_player.c:159: player_xs = 0;
	ld	hl,#_player_xs + 0
	ld	(hl), #0x00
;zorblaxx_player.c:160: player_ys = 0;
	ld	hl,#_player_ys + 0
	ld	(hl), #0x00
;zorblaxx_player.c:162: player_hit = false;
	ld	hl,#_player_hit + 0
	ld	(hl), #0x00
;zorblaxx_player.c:163: player_lives = lives;
	ld	hl, #6+0
	add	hl, sp
	ld	a, (hl)
	ld	(#_player_lives + 0),a
;zorblaxx_player.c:164: player_lives_changed = true;
	ld	hl,#_player_lives_changed + 0
	ld	(hl), #0x01
;zorblaxx_player.c:165: player_respawn_timer = 0;
	ld	hl,#_player_respawn_timer + 0
	ld	(hl), #0x00
;zorblaxx_player.c:166: player_invincible_timer = 0;
	ld	hl,#_player_invincible_timer + 0
	ld	(hl), #0x00
;zorblaxx_player.c:167: player_invincible_flash = 0;
	ld	hl,#_player_invincible_flash + 0
	ld	(hl), #0x00
;zorblaxx_player.c:170: spr_index[player_sprite] = sprite_index_player_first;
	ld	hl, #(_spr_index + 0x000b)
	ld	(hl), #0x20
;zorblaxx_player.c:171: enable_sprite(player_sprite, sprite_palette_player, sprite_size_player, true);
	ld	de, #0x0101
	push	de
	ld	de, #0x010b
	push	de
	call	_enable_sprite
	pop	af
	pop	af
;zorblaxx_player.c:173: set_sprite_position(player_sprite, x, y);
	ld	hl, #4
	add	hl, sp
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	push	bc
	ld	hl, #4
	add	hl, sp
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	push	bc
	ld	a, #0x0b
	push	af
	inc	sp
	call	_set_sprite_position
	pop	af
	pop	af
	inc	sp
;zorblaxx_player.c:176: player_trail_timer = player_trail_frequency;
	ld	a,(#_player_trail_frequency + 0)
	ld	(#_player_trail_timer + 0),a
;zorblaxx_player.c:177: }
	ret
;zorblaxx_player.c:179: void player_destroyed()
;	---------------------------------
; Function player_destroyed
; ---------------------------------
_player_destroyed::
;zorblaxx_player.c:181: play_sound(const_sound_player_explode);
	xor	a, a
	push	af
	inc	sp
	call	_play_sound
	inc	sp
;zorblaxx_player.c:182: add_explosion(0, 1);
	ld	a, #0x01
	push	af
	inc	sp
	ld	hl, #0x0000
	push	hl
	call	_add_explosion
	pop	af
	inc	sp
;zorblaxx_player.c:183: add_explosion(1, 2);
	ld	a, #0x02
	push	af
	inc	sp
	ld	hl, #0x0001
	push	hl
	call	_add_explosion
	pop	af
	inc	sp
;zorblaxx_player.c:184: spr_on[player_sprite] = false;
	ld	hl, #(_spr_on + 0x000b)
	ld	(hl), #0x00
;zorblaxx_player.c:185: player_lives_changed = true;
	ld	hl,#_player_lives_changed + 0
	ld	(hl), #0x01
;zorblaxx_player.c:186: if (player_lives > 0)
	ld	iy, #_player_lives
	ld	a, 0 (iy)
	or	a, a
	ret	Z
;zorblaxx_player.c:188: player_lives--;
	dec	0 (iy)
;zorblaxx_player.c:189: player_respawn_timer = player_respawn_timeout;
	ld	a,(#_player_respawn_timeout + 0)
	ld	(#_player_respawn_timer + 0),a
;zorblaxx_player.c:191: }
	ret
;zorblaxx_player.c:193: void handle_player(bool allow_control)
;	---------------------------------
; Function handle_player
; ---------------------------------
_handle_player::
	push	ix
	ld	ix,#0
	add	ix,sp
;zorblaxx_player.c:196: if (player_respawn_timer > 0)
	ld	a,(#_player_respawn_timer + 0)
	or	a, a
	jr	Z,00106$
;zorblaxx_player.c:198: player_hit = false;
	ld	hl,#_player_hit + 0
	ld	(hl), #0x00
;zorblaxx_player.c:201: if (player_speed > player_speed_min)
	ld	a,(#_player_speed_min + 0)
	ld	iy, #_player_speed
	sub	a, 0 (iy)
	jr	NC,00102$
;zorblaxx_player.c:203: player_speed--;
	dec	0 (iy)
00102$:
;zorblaxx_player.c:206: player_respawn_timer--;
	ld	iy, #_player_respawn_timer
	dec	0 (iy)
;zorblaxx_player.c:208: if (player_respawn_timer == 0)
	ld	a, 0 (iy)
	or	a, a
	jp	NZ,00172$
;zorblaxx_player.c:211: setup_player(player_spawn_x, player_spawn_y, player_lives);
	ld	a, (_player_lives)
	push	af
	inc	sp
	ld	hl, (_player_spawn_y)
	push	hl
	ld	hl, (_player_spawn_x)
	push	hl
	call	_setup_player
	pop	af
	pop	af
	inc	sp
;zorblaxx_player.c:213: enable_sprite(player_sprite, sprite_palette_player, sprite_size_player, false);
	xor	a, a
	ld	d,a
	ld	e,#0x01
	push	de
	ld	de, #0x010b
	push	de
	call	_enable_sprite
	pop	af
	pop	af
;zorblaxx_player.c:214: player_invincible_timer = player_invincible_timeout;
	ld	a,(#_player_invincible_timeout + 0)
	ld	(#_player_invincible_timer + 0),a
;zorblaxx_player.c:216: return;
	jp	00172$
00106$:
;zorblaxx_player.c:220: if (player_invincible_timer > 0)
	ld	a,(#_player_invincible_timer + 0)
	or	a, a
	jr	Z,00115$
;zorblaxx_player.c:223: player_hit = false;
	ld	hl,#_player_hit + 0
	ld	(hl), #0x00
;zorblaxx_player.c:225: player_invincible_timer--;
	ld	iy, #_player_invincible_timer
	dec	0 (iy)
;zorblaxx_player.c:227: if (player_invincible_timer == 0)
	ld	a, 0 (iy)
	or	a, a
	jr	NZ,00110$
;zorblaxx_player.c:230: enable_sprite(player_sprite, sprite_palette_player, sprite_size_player, true);
	ld	de, #0x0101
	push	de
	ld	de, #0x010b
	push	de
	call	_enable_sprite
	pop	af
	pop	af
	jr	00116$
00110$:
;zorblaxx_player.c:235: player_invincible_flash++;
	ld	iy, #_player_invincible_flash
	inc	0 (iy)
;zorblaxx_player.c:237: if (player_invincible_flash == 4)
	ld	a, 0 (iy)
	sub	a, #0x04
	jr	NZ,00116$
;zorblaxx_player.c:240: player_invincible_flash = 0;
	ld	0 (iy), #0x00
;zorblaxx_player.c:242: spr_on[player_sprite] = !spr_on[player_sprite];
	ld	bc, #_spr_on+11
	ld	a, (bc)
	xor	a, #0x01
	ld	(bc), a
	jr	00116$
00115$:
;zorblaxx_player.c:249: if (player_hit)
	ld	iy, #_player_hit
	ld	a, 0 (iy)
	or	a, a
	jr	Z,00116$
;zorblaxx_player.c:251: player_hit = false;
	ld	0 (iy), #0x00
;zorblaxx_player.c:252: player_destroyed();
	call	_player_destroyed
00116$:
;zorblaxx_player.c:257: if (player_xs > 0)
	xor	a, a
	ld	iy, #_player_xs
	sub	a, 0 (iy)
	jp	PO, 00366$
	xor	a, #0x80
00366$:
	jp	P, 00120$
;zorblaxx_player.c:259: player_xs--;
	ld	hl, #_player_xs+0
	dec	(hl)
	jr	00121$
00120$:
;zorblaxx_player.c:261: else if (player_xs < 0)
	ld	iy, #_player_xs
	bit	7,0 (iy)
	jr	Z,00121$
;zorblaxx_player.c:263: player_xs++;
	inc	0 (iy)
00121$:
;zorblaxx_player.c:265: if (player_ys > 0)
	xor	a, a
	ld	iy, #_player_ys
	sub	a, 0 (iy)
	jp	PO, 00367$
	xor	a, #0x80
00367$:
	jp	P, 00125$
;zorblaxx_player.c:267: player_ys--;
	ld	hl, #_player_ys+0
	dec	(hl)
	jr	00126$
00125$:
;zorblaxx_player.c:269: else if (player_ys < 0)
	ld	iy, #_player_ys
	bit	7,0 (iy)
	jr	Z,00126$
;zorblaxx_player.c:271: player_ys++;
	inc	0 (iy)
00126$:
;zorblaxx_player.c:275: if (allow_control)
	bit	0, 4 (ix)
	jp	Z, 00147$
;zorblaxx_player.c:278: if (CHECK_BIT(joystick[0], 0) && player_xs < player_max_speed)
	ld	a, (#_joystick + 0)
	rrca
	jr	NC,00128$
	ld	hl,#_player_max_speed + 0
	ld	c, (hl)
	ld	a,(#_player_xs + 0)
	sub	a, c
	jp	PO, 00369$
	xor	a, #0x80
00369$:
	jp	P, 00128$
;zorblaxx_player.c:280: player_xs += player_accel;
	ld	a,(#_player_accel + 0)
	ld	hl, #_player_xs
	add	a, (hl)
	ld	(hl), a
00128$:
;zorblaxx_player.c:282: if (CHECK_BIT(joystick[0], 1) && player_xs > -player_max_speed)
	ld	a, (#_joystick + 0)
	bit	1, a
	jr	Z,00131$
	ld	a,(#_player_max_speed + 0)
	ld	c, a
	rla
	sbc	a, a
	ld	b, a
	xor	a, a
	sub	a, c
	ld	c, a
	ld	a, #0x00
	sbc	a, b
	ld	b, a
	ld	a,(#_player_xs + 0)
	ld	e, a
	rla
	sbc	a, a
	ld	d, a
	ld	a, c
	sub	a, e
	ld	a, b
	sbc	a, d
	jp	PO, 00371$
	xor	a, #0x80
00371$:
	jp	P, 00131$
;zorblaxx_player.c:284: player_xs -= player_accel;
	ld	hl,#_player_accel + 0
	ld	c, (hl)
	ld	hl, #_player_xs
	ld	a, (hl)
	sub	a, c
	ld	(hl), a
00131$:
;zorblaxx_player.c:286: if (CHECK_BIT(joystick[0], 2) && player_ys < player_max_speed)
	ld	a, (#_joystick + 0)
	bit	2, a
	jr	Z,00134$
	ld	hl,#_player_max_speed + 0
	ld	c, (hl)
	ld	a,(#_player_ys + 0)
	sub	a, c
	jp	PO, 00373$
	xor	a, #0x80
00373$:
	jp	P, 00134$
;zorblaxx_player.c:288: player_ys += player_accel;
	ld	a,(#_player_accel + 0)
	ld	hl, #_player_ys
	add	a, (hl)
	ld	(hl), a
00134$:
;zorblaxx_player.c:290: if (CHECK_BIT(joystick[0], 3) && player_ys > -player_max_speed)
	ld	a, (#_joystick + 0)
	bit	3, a
	jr	Z,00137$
	ld	a,(#_player_max_speed + 0)
	ld	c, a
	rla
	sbc	a, a
	ld	b, a
	xor	a, a
	sub	a, c
	ld	c, a
	ld	a, #0x00
	sbc	a, b
	ld	b, a
	ld	a,(#_player_ys + 0)
	ld	e, a
	rla
	sbc	a, a
	ld	d, a
	ld	a, c
	sub	a, e
	ld	a, b
	sbc	a, d
	jp	PO, 00375$
	xor	a, #0x80
00375$:
	jp	P, 00137$
;zorblaxx_player.c:292: player_ys -= player_accel;
	ld	hl,#_player_accel + 0
	ld	c, (hl)
	ld	hl, #_player_ys
	ld	a, (hl)
	sub	a, c
	ld	(hl), a
00137$:
;zorblaxx_player.c:296: if (CHECK_BIT(joystick[0], 4))
	ld	a, (#_joystick + 0)
	bit	4, a
	jr	Z,00144$
;zorblaxx_player.c:298: if (player_speed < player_speed_max)
	ld	hl,#_player_speed_max + 0
	ld	c, (hl)
	ld	iy, #_player_speed
	ld	a, 0 (iy)
	sub	a, c
	jr	NC,00147$
;zorblaxx_player.c:300: player_speed++;
	inc	0 (iy)
	jr	00147$
00144$:
;zorblaxx_player.c:305: if (player_speed > player_speed_min)
	ld	a,(#_player_speed_min + 0)
	ld	iy, #_player_speed
	sub	a, 0 (iy)
	jr	NC,00147$
;zorblaxx_player.c:307: player_speed--;
	dec	0 (iy)
00147$:
;zorblaxx_player.c:313: spr_index[player_sprite] = (player_xs < -2 ? sprite_index_player_first + 2 : player_xs > 2 ? sprite_index_player_first + 3
	ld	a,(#_player_xs + 0)
	xor	a, #0x80
	sub	a, #0x7e
	jr	NC,00174$
	ld	bc, #0x0022
	jr	00175$
00174$:
	ld	a, #0x02
	ld	iy, #_player_xs
	sub	a, 0 (iy)
	jp	PO, 00377$
	xor	a, #0x80
00377$:
	jp	P, 00176$
;zorblaxx_player.c:314: : sprite_index_player_first);
	ld	bc, #0x0023
	jr	00177$
00176$:
	ld	bc, #0x0020
00177$:
00175$:
	ld	hl, #(_spr_index + 0x000b)
	ld	(hl), c
;zorblaxx_player.c:317: player_x += player_xs;
	ld	a,(#_player_xs + 0)
	ld	c, a
	rla
	sbc	a, a
	ld	b, a
	ld	hl, #_player_x
	ld	a, (hl)
	add	a, c
	ld	(hl), a
	inc	hl
	ld	a, (hl)
	adc	a, b
	ld	(hl), a
;zorblaxx_player.c:318: player_y += player_ys;
	ld	a,(#_player_ys + 0)
	ld	c, a
	rla
	sbc	a, a
	ld	b, a
	ld	hl, #_player_y
	ld	a, (hl)
	add	a, c
	ld	(hl), a
	inc	hl
	ld	a, (hl)
	adc	a, b
	ld	(hl), a
;zorblaxx_player.c:321: if (allow_control)
	bit	0, 4 (ix)
	jp	Z, 00167$
;zorblaxx_player.c:324: if (player_x < player_x_min)
	ld	hl, #_player_x_min
	ld	iy, #_player_x
	ld	a, 0 (iy)
	sub	a, (hl)
	ld	a, 1 (iy)
	inc	hl
	sbc	a, (hl)
	jr	NC,00155$
;zorblaxx_player.c:326: player_x = player_x_min;
	ld	hl, (_player_x_min)
	ld	(_player_x), hl
;zorblaxx_player.c:327: if (player_xs < 0)
	ld	iy, #_player_xs
	bit	7,0 (iy)
	jr	Z,00156$
;zorblaxx_player.c:329: player_xs = 0;
	ld	0 (iy), #0x00
	jr	00156$
00155$:
;zorblaxx_player.c:333: else if (player_x > player_x_max)
	ld	hl, #_player_x_max
	ld	a, (hl)
	ld	iy, #_player_x
	sub	a, 0 (iy)
	inc	hl
	ld	a, (hl)
	sbc	a, 1 (iy)
	jr	NC,00156$
;zorblaxx_player.c:335: player_x = player_x_max;
	ld	hl, (_player_x_max)
	ld	(_player_x), hl
;zorblaxx_player.c:336: if (player_xs > 0)
	xor	a, a
	ld	iy, #_player_xs
	sub	a, 0 (iy)
	jp	PO, 00378$
	xor	a, #0x80
00378$:
	jp	P, 00156$
;zorblaxx_player.c:338: player_xs = 0;
	ld	hl,#_player_xs + 0
	ld	(hl), #0x00
00156$:
;zorblaxx_player.c:343: if (player_y < player_y_min)
	ld	hl, #_player_y_min
	ld	iy, #_player_y
	ld	a, 0 (iy)
	sub	a, (hl)
	ld	a, 1 (iy)
	inc	hl
	sbc	a, (hl)
	jr	NC,00164$
;zorblaxx_player.c:345: player_y = player_y_min;
	ld	hl, (_player_y_min)
	ld	(_player_y), hl
;zorblaxx_player.c:346: if (player_ys < 0)
	ld	iy, #_player_ys
	bit	7,0 (iy)
	jr	Z,00167$
;zorblaxx_player.c:348: player_ys = 0;
	ld	0 (iy), #0x00
	jr	00167$
00164$:
;zorblaxx_player.c:352: else if (player_y > player_y_max)
	ld	hl, #_player_y_max
	ld	a, (hl)
	ld	iy, #_player_y
	sub	a, 0 (iy)
	inc	hl
	ld	a, (hl)
	sbc	a, 1 (iy)
	jr	NC,00167$
;zorblaxx_player.c:354: player_y = player_y_max;
	ld	hl, (_player_y_max)
	ld	(_player_y), hl
;zorblaxx_player.c:355: if (player_ys > 0)
	xor	a, a
	ld	iy, #_player_ys
	sub	a, 0 (iy)
	jp	PO, 00379$
	xor	a, #0x80
00379$:
	jp	P, 00167$
;zorblaxx_player.c:357: player_ys = 0;
	ld	hl,#_player_ys + 0
	ld	(hl), #0x00
00167$:
;zorblaxx_player.c:363: set_sprite_position(player_sprite, player_x / x_divisor, player_y / y_divisor);
	ld	hl,#_y_divisor + 0
	ld	c, (hl)
	ld	b, #0x00
	push	bc
	ld	hl, (_player_y)
	push	hl
	call	__divuint
	pop	af
	pop	af
	ld	c, l
	ld	b, h
	ld	hl,#_x_divisor + 0
	ld	e, (hl)
	ld	d, #0x00
	push	bc
	push	de
	ld	hl, (_player_x)
	push	hl
	call	__divuint
	pop	af
	ex	(sp),hl
	ld	a, #0x0b
	push	af
	inc	sp
	call	_set_sprite_position
	pop	af
	pop	af
	inc	sp
;zorblaxx_player.c:366: player_trail_timer--;
	ld	iy, #_player_trail_timer
	dec	0 (iy)
;zorblaxx_player.c:368: if (player_trail_timer <= 0)
	xor	a, a
	sub	a, 0 (iy)
	jp	PO, 00380$
	xor	a, #0x80
00380$:
	jp	M, 00172$
;zorblaxx_player.c:371: unsigned char reduce = (player_speed / 8) + rand_uchar(0, 6);
	ld	hl,#_player_speed + 0
	ld	c, (hl)
	ld	b, #0x00
	ld	e, c
	ld	d, b
	bit	7, b
	jr	Z,00178$
	ld	hl, #0x0007
	add	hl, bc
	ex	de, hl
00178$:
	sra	d
	rr	e
	sra	d
	rr	e
	sra	d
	rr	e
	push	de
	ld	a, #0x06
	push	af
	inc	sp
	xor	a, a
	push	af
	inc	sp
	call	_rand_uchar
	pop	af
	pop	de
	add	hl, de
	ld	c, l
;zorblaxx_player.c:372: player_trail_timer = player_trail_frequency - reduce;
	ld	a,(#_player_trail_frequency + 0)
	ld	hl, #_player_trail_timer
	sub	a, c
	ld	(hl), a
;zorblaxx_player.c:373: if (player_trail_timer <= 0)
	xor	a, a
	ld	iy, #_player_trail_timer
	sub	a, 0 (iy)
	jp	PO, 00381$
	xor	a, #0x80
00381$:
	jp	M, 00169$
;zorblaxx_player.c:375: player_trail_timer = 0;
	ld	hl,#_player_trail_timer + 0
	ld	(hl), #0x00
00169$:
;zorblaxx_player.c:378: add_player_trail();
	call	_add_player_trail
00172$:
;zorblaxx_player.c:380: }
	pop	ix
	ret
	.area _CODE
	.area _INITIALIZER
__xinit__player_xs:
	.db #0x00	;  0
__xinit__player_ys:
	.db #0x00	;  0
__xinit__player_trail_timer:
	.db #0x01	;  1
__xinit__player_invincible_timer:
	.db #0x00	; 0
__xinit__player_invincible_flash:
	.db #0x00	; 0
__xinit__player_respawn_timer:
	.db #0x00	; 0
__xinit__player_hit:
	.db #0x00	; 0
__xinit__player_target_divider:
	.db #0x06	; 6
__xinit__player_target_maxspeed:
	.db #0x1c	; 28
	.area _CABS (ABS)
