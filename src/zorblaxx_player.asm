;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.8.0 #10562 (Linux)
;--------------------------------------------------------
	.module zorblaxx_player
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _add_explosion
	.globl _add_player_trail
	.globl _enable_sprite
	.globl _player_hit
	.globl _player_explosion_timeout
	.globl _player_respawn_timeout
	.globl _player_respawn_timer
	.globl _player_invincible_timeout
	.globl _player_invincible_flash
	.globl _player_invincible_timer
	.globl _player_trail_timer
	.globl _player_score_timer
	.globl _player_score
	.globl _player_speed_max
	.globl _player_speed_min
	.globl _player_ys
	.globl _player_xs
	.globl _player_sprite_palette
	.globl _player_speed
	.globl _player_y_max
	.globl _player_y_min
	.globl _player_x_max
	.globl _player_x_min
	.globl _player_y
	.globl _player_x
	.globl _spritecollisionram
	.globl _spriteram
	.globl _bgcolram
	.globl _fgcolram
	.globl _chram
	.globl _musicram
	.globl _sndram
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
	.globl _player_trail_lifespan
	.globl _player_trail_speed
	.globl _player_trail_frequency
	.globl _player_accel
	.globl _player_max_speed
	.globl _player_sprite
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
_sndram	=	0x8b00
_musicram	=	0x8b10
_chram	=	0x9800
_fgcolram	=	0xa000
_bgcolram	=	0xa800
_spriteram	=	0xb000
_spritecollisionram	=	0xb400
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
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
_player_sprite_palette::
	.ds 1
_player_xs::
	.ds 1
_player_ys::
	.ds 1
_player_speed_min::
	.ds 1
_player_speed_max::
	.ds 1
_player_score::
	.ds 4
_player_score_timer::
	.ds 1
_player_trail_timer::
	.ds 1
_player_invincible_timer::
	.ds 1
_player_invincible_flash::
	.ds 1
_player_invincible_timeout::
	.ds 1
_player_respawn_timer::
	.ds 1
_player_respawn_timeout::
	.ds 1
_player_explosion_timeout::
	.ds 1
_player_hit::
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
;zorblaxx_player.c:61: void setup_player(unsigned short x, unsigned short y)
;	---------------------------------
; Function setup_player
; ---------------------------------
_setup_player::
	push	ix
	ld	ix,#0
	add	ix,sp
	push	af
;zorblaxx_player.c:64: player_x_min = 16 * x_divisor;
	ld	hl,#_x_divisor + 0
	ld	d, (hl)
	ld	c, d
	ld	b, #0x00
	ld	iy, #_player_x_min
	ld	0 (iy), c
	ld	1 (iy), b
	ld	a, #0x04+1
	jr	00104$
00103$:
	sla	0 (iy)
	rl	1 (iy)
00104$:
	dec	a
	jr	NZ,00103$
;zorblaxx_player.c:65: player_x_max = 320 * x_divisor;
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	ld	(_player_x_max), hl
;zorblaxx_player.c:66: player_y_min = 20 * y_divisor;
	ld	hl,#_y_divisor + 0
	ld	e, (hl)
	ld	c, e
	ld	b, #0x00
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl, hl
	ld	(_player_y_min), hl
;zorblaxx_player.c:67: player_y_max = 216 * y_divisor;
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl, hl
	add	hl, hl
	ld	(_player_y_max), hl
;zorblaxx_player.c:70: player_x = x * x_divisor;
	ld	c, d
	ld	b, #0x00
	push	de
	push	bc
	ld	l, 4 (ix)
	ld	h, 5 (ix)
	push	hl
	call	__mulint
	pop	af
	pop	af
	pop	de
	ld	(_player_x), hl
;zorblaxx_player.c:71: player_y = y * y_divisor;
	ld	d, #0x00
	push	de
	ld	l, 6 (ix)
	ld	h, 7 (ix)
	push	hl
	call	__mulint
	pop	af
	pop	af
	ld	(_player_y), hl
;zorblaxx_player.c:72: player_speed = player_speed_min;
	ld	a,(#_player_speed_min + 0)
	ld	(#_player_speed + 0),a
;zorblaxx_player.c:73: player_xs = 0;
	ld	hl,#_player_xs + 0
	ld	(hl), #0x00
;zorblaxx_player.c:74: player_ys = 0;
	ld	hl,#_player_ys + 0
	ld	(hl), #0x00
;zorblaxx_player.c:76: player_invincible_timer = 0;
	ld	hl,#_player_invincible_timer + 0
	ld	(hl), #0x00
;zorblaxx_player.c:77: player_invincible_flash = 0;
	ld	hl,#_player_invincible_flash + 0
	ld	(hl), #0x00
;zorblaxx_player.c:80: spr_index[player_sprite] = player_sprite_index_default;
	ld	de, #_spr_index+0
	ld	hl,#_player_sprite + 0
	ld	b, (hl)
	ld	l, b
	ld	h, #0x00
	add	hl, de
	ld	(hl), #0x06
;zorblaxx_player.c:81: enable_sprite(player_sprite, player_sprite_palette, false);
	xor	a, a
	push	af
	inc	sp
	ld	a, (_player_sprite_palette)
	push	af
	inc	sp
	push	bc
	inc	sp
	call	_enable_sprite
	pop	af
	inc	sp
;zorblaxx_player.c:82: spr_x[player_sprite] = player_x / x_divisor;
	ld	bc, #_spr_x+0
	ld	hl,#_player_sprite + 0
	ld	e, (hl)
	ld	l, e
	ld	h, #0x00
	add	hl, hl
	add	hl, bc
	ex	(sp), hl
	ld	hl,#_x_divisor + 0
	ld	c, (hl)
	ld	b, #0x00
	push	de
	push	bc
	ld	hl, (_player_x)
	push	hl
	call	__divuint
	pop	af
	pop	af
	ld	c, l
	ld	b, h
	pop	de
	pop	hl
	push	hl
	ld	(hl), c
	inc	hl
	ld	(hl), b
;zorblaxx_player.c:83: spr_y_h[player_sprite] = y >> 8;
	ld	bc, #_spr_y_h+0
	ld	l, e
	ld	h, #0x00
	add	hl, bc
	ld	c, 7 (ix)
	ld	(hl), c
;zorblaxx_player.c:84: spr_y_l[player_sprite] = (unsigned char)y;
	ld	hl, #_spr_y_l+0
	ld	d, #0x00
	add	hl, de
	ld	a, 6 (ix)
	ld	(hl), a
;zorblaxx_player.c:87: player_trail_timer = player_trail_frequency;
	ld	a,(#_player_trail_frequency + 0)
	ld	(#_player_trail_timer + 0),a
;zorblaxx_player.c:90: player_score = 0;
	xor	a, a
	ld	iy, #_player_score
	ld	0 (iy), a
	ld	1 (iy), a
	ld	2 (iy), a
	ld	3 (iy), a
;zorblaxx_player.c:91: player_score_timer = 0;
	ld	hl,#_player_score_timer + 0
	ld	(hl), #0x00
;zorblaxx_player.c:94: player_invincible_timer = player_invincible_timeout;
	ld	a,(#_player_invincible_timeout + 0)
	ld	(#_player_invincible_timer + 0),a
;zorblaxx_player.c:95: }
	ld	sp, ix
	pop	ix
	ret
_player_sprite:
	.db #0x0b	; 11
_player_max_speed:
	.db #0x14	;  20
_player_accel:
	.db #0x03	; 3
_player_trail_frequency:
	.db #0x0c	; 12
_player_trail_speed:
	.db #0x03	; 3
_player_trail_lifespan:
	.db #0x05	; 5
;zorblaxx_player.c:97: void handle_player()
;	---------------------------------
; Function handle_player
; ---------------------------------
_handle_player::
	push	ix
	ld	ix,#0
	add	ix,sp
	push	af
;zorblaxx_player.c:99: if (player_respawn_timer > 0)
	ld	a,(#_player_respawn_timer + 0)
	or	a, a
	jr	Z,00106$
;zorblaxx_player.c:101: if (player_speed > player_speed_min)
	ld	a, (#_player_speed_min)
	ld	iy, #_player_speed
	sub	a, 0 (iy)
	jr	NC,00102$
;zorblaxx_player.c:103: player_speed--;
	dec	0 (iy)
00102$:
;zorblaxx_player.c:105: player_respawn_timer--;
	ld	iy, #_player_respawn_timer
	dec	0 (iy)
;zorblaxx_player.c:106: if (player_respawn_timer == 0)
	ld	a, 0 (iy)
	or	a, a
	jp	NZ,00170$
;zorblaxx_player.c:108: setup_player(176, 216);
	ld	hl, #0x00d8
	push	hl
	ld	l, #0xb0
	push	hl
	call	_setup_player
	pop	af
	pop	af
;zorblaxx_player.c:110: return;
	jp	00170$
00106$:
;zorblaxx_player.c:113: if (player_invincible_timer > 0)
	ld	a,(#_player_invincible_timer + 0)
	or	a, a
	jr	Z,00115$
;zorblaxx_player.c:115: player_hit = false;
	ld	hl,#_player_hit + 0
	ld	(hl), #0x00
;zorblaxx_player.c:116: player_invincible_timer--;
	ld	hl, #_player_invincible_timer+0
	dec	(hl)
;zorblaxx_player.c:117: player_invincible_flash++;
	ld	hl, #_player_invincible_flash+0
	inc	(hl)
;zorblaxx_player.c:121: enable_sprite(player_sprite, player_sprite_palette, true);
	ld	hl,#_player_sprite + 0
	ld	b, (hl)
;zorblaxx_player.c:119: if (player_invincible_timer == 0)
	ld	a,(#_player_invincible_timer + 0)
	or	a, a
	jr	NZ,00110$
;zorblaxx_player.c:121: enable_sprite(player_sprite, player_sprite_palette, true);
	ld	a, #0x01
	push	af
	inc	sp
	ld	a, (_player_sprite_palette)
	push	af
	inc	sp
	push	bc
	inc	sp
	call	_enable_sprite
	pop	af
	inc	sp
	jr	00116$
00110$:
;zorblaxx_player.c:125: if (player_invincible_flash == 4)
	ld	iy, #_player_invincible_flash
	ld	a, 0 (iy)
	sub	a, #0x04
	jr	NZ,00116$
;zorblaxx_player.c:127: player_invincible_flash = 0;
	ld	0 (iy), #0x00
;zorblaxx_player.c:128: spr_on[player_sprite] = !spr_on[player_sprite];
	ld	a, b
	add	a, #<(_spr_on)
	ld	c, a
	ld	a, #0x00
	adc	a, #>(_spr_on)
	ld	b, a
	ld	a, (bc)
	xor	a, #0x01
	ld	(bc), a
	jr	00116$
00115$:
;zorblaxx_player.c:134: if (player_hit)
	ld	iy, #_player_hit
	ld	a, 0 (iy)
	or	a, a
	jr	Z,00116$
;zorblaxx_player.c:136: player_hit = false;
	ld	0 (iy), #0x00
;zorblaxx_player.c:137: add_explosion(0, 1);
	ld	a, #0x01
	push	af
	inc	sp
	ld	hl, #0x0000
	push	hl
	call	_add_explosion
	pop	af
	inc	sp
;zorblaxx_player.c:138: add_explosion(1, 3);
	ld	a, #0x03
	push	af
	inc	sp
	ld	hl, #0x0001
	push	hl
	call	_add_explosion
	pop	af
	inc	sp
;zorblaxx_player.c:139: player_respawn_timer = player_respawn_timeout;
	ld	a,(#_player_respawn_timeout + 0)
	ld	(#_player_respawn_timer + 0),a
;zorblaxx_player.c:140: spr_on[player_sprite] = false;
	ld	bc, #_spr_on+0
	ld	iy, #_player_sprite
	ld	l, 0 (iy)
	ld	h, #0x00
	add	hl, bc
	ld	(hl), #0x00
00116$:
;zorblaxx_player.c:144: if (player_xs > 0)
	xor	a, a
	ld	iy, #_player_xs
	sub	a, 0 (iy)
	jp	PO, 00353$
	xor	a, #0x80
00353$:
	jp	P, 00120$
;zorblaxx_player.c:146: player_xs--;
	ld	hl, #_player_xs+0
	dec	(hl)
	jr	00121$
00120$:
;zorblaxx_player.c:148: else if (player_xs < 0)
	ld	iy, #_player_xs
	bit	7,0 (iy)
	jr	Z,00121$
;zorblaxx_player.c:150: player_xs++;
	inc	0 (iy)
00121$:
;zorblaxx_player.c:152: if (player_ys > 0)
	xor	a, a
	ld	iy, #_player_ys
	sub	a, 0 (iy)
	jp	PO, 00354$
	xor	a, #0x80
00354$:
	jp	P, 00125$
;zorblaxx_player.c:154: player_ys--;
	ld	hl, #_player_ys+0
	dec	(hl)
	jr	00126$
00125$:
;zorblaxx_player.c:156: else if (player_ys < 0)
	ld	iy, #_player_ys
	bit	7,0 (iy)
	jr	Z,00126$
;zorblaxx_player.c:158: player_ys++;
	inc	0 (iy)
00126$:
;zorblaxx_player.c:160: if (CHECK_BIT(joystick[0], 0) && player_xs < player_max_speed)
	ld	a, (#_joystick + 0)
	rrca
	jr	NC,00128$
	ld	hl,#_player_max_speed + 0
	ld	c, (hl)
	ld	a,(#_player_xs + 0)
	sub	a, c
	jp	PO, 00356$
	xor	a, #0x80
00356$:
	jp	P, 00128$
;zorblaxx_player.c:162: player_xs += player_accel;
	ld	a,(#_player_accel + 0)
	ld	hl, #_player_xs
	add	a, (hl)
	ld	(hl), a
00128$:
;zorblaxx_player.c:164: if (CHECK_BIT(joystick[0], 1) && player_xs > -player_max_speed)
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
	jp	PO, 00358$
	xor	a, #0x80
00358$:
	jp	P, 00131$
;zorblaxx_player.c:166: player_xs -= player_accel;
	ld	hl,#_player_accel + 0
	ld	c, (hl)
	ld	hl, #_player_xs
	ld	a, (hl)
	sub	a, c
	ld	(hl), a
00131$:
;zorblaxx_player.c:168: if (CHECK_BIT(joystick[0], 2) && player_ys < player_max_speed)
	ld	a, (#_joystick + 0)
	bit	2, a
	jr	Z,00134$
	ld	hl,#_player_max_speed + 0
	ld	c, (hl)
	ld	a,(#_player_ys + 0)
	sub	a, c
	jp	PO, 00360$
	xor	a, #0x80
00360$:
	jp	P, 00134$
;zorblaxx_player.c:170: player_ys += player_accel;
	ld	a,(#_player_accel + 0)
	ld	hl, #_player_ys
	add	a, (hl)
	ld	(hl), a
00134$:
;zorblaxx_player.c:172: if (CHECK_BIT(joystick[0], 3) && player_ys > -player_max_speed)
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
	jp	PO, 00362$
	xor	a, #0x80
00362$:
	jp	P, 00137$
;zorblaxx_player.c:174: player_ys -= player_accel;
	ld	hl,#_player_accel + 0
	ld	c, (hl)
	ld	hl, #_player_ys
	ld	a, (hl)
	sub	a, c
	ld	(hl), a
00137$:
;zorblaxx_player.c:177: if (CHECK_BIT(joystick[0], 4))
	ld	a, (#_joystick + 0)
	bit	4, a
	jr	Z,00144$
;zorblaxx_player.c:179: if (player_speed < player_speed_max)
	ld	hl, #_player_speed_max
	ld	iy, #_player_speed
	ld	a, 0 (iy)
	sub	a, (hl)
	jr	NC,00145$
;zorblaxx_player.c:181: player_speed++;
	inc	0 (iy)
	jr	00145$
00144$:
;zorblaxx_player.c:186: if (player_speed > player_speed_min)
	ld	a, (#_player_speed_min)
	ld	iy, #_player_speed
	sub	a, 0 (iy)
	jr	NC,00145$
;zorblaxx_player.c:188: player_speed--;
	dec	0 (iy)
00145$:
;zorblaxx_player.c:192: spr_index[player_sprite] = player_xs < -2 ? player_sprite_index_left : player_xs > 2 ? player_sprite_index_right
	ld	hl,#_player_sprite + 0
	ld	c, (hl)
	ld	a, #<(_spr_index)
	add	a, c
	ld	b, a
	ld	a, #>(_spr_index)
	adc	a, #0x00
	ld	e, a
	ld	a,(#_player_xs + 0)
	xor	a, #0x80
	sub	a, #0x7e
	jr	NC,00172$
	ld	hl, #0x0008
	jr	00173$
00172$:
	ld	a, #0x02
	ld	iy, #_player_xs
	sub	a, 0 (iy)
	jp	PO, 00364$
	xor	a, #0x80
00364$:
	jp	P, 00174$
;zorblaxx_player.c:193: : player_sprite_index_default;
	ld	hl, #0x0009
	jr	00175$
00174$:
	ld	hl, #0x0006
00175$:
00173$:
	ld	a, l
	ld	l, b
	ld	h, e
	ld	(hl), a
;zorblaxx_player.c:195: player_x += player_xs;
	ld	a,(#_player_xs + 0)
	ld	b, a
	rla
	sbc	a, a
	ld	e, a
	ld	hl, #_player_x
	ld	a, (hl)
	add	a, b
	ld	(hl), a
	inc	hl
	ld	a, (hl)
	adc	a, e
	ld	(hl), a
;zorblaxx_player.c:196: if (player_x < player_x_min)
	ld	hl, #_player_x_min
	ld	iy, #_player_x
	ld	a, 0 (iy)
	sub	a, (hl)
	ld	a, 1 (iy)
	inc	hl
	sbc	a, (hl)
	jr	NC,00153$
;zorblaxx_player.c:198: player_x = player_x_min;
	ld	hl, (_player_x_min)
	ld	(_player_x), hl
;zorblaxx_player.c:199: if (player_xs < 0)
	ld	iy, #_player_xs
	bit	7,0 (iy)
	jr	Z,00154$
;zorblaxx_player.c:201: player_xs = 0;
	ld	0 (iy), #0x00
	jr	00154$
00153$:
;zorblaxx_player.c:204: else if (player_x > player_x_max)
	ld	hl, #_player_x_max
	ld	a, (hl)
	ld	iy, #_player_x
	sub	a, 0 (iy)
	inc	hl
	ld	a, (hl)
	sbc	a, 1 (iy)
	jr	NC,00154$
;zorblaxx_player.c:206: player_x = player_x_max;
	ld	hl, (_player_x_max)
	ld	(_player_x), hl
;zorblaxx_player.c:207: if (player_xs > 0)
	xor	a, a
	ld	iy, #_player_xs
	sub	a, 0 (iy)
	jp	PO, 00365$
	xor	a, #0x80
00365$:
	jp	P, 00154$
;zorblaxx_player.c:209: player_xs = 0;
	ld	hl,#_player_xs + 0
	ld	(hl), #0x00
00154$:
;zorblaxx_player.c:213: player_y += player_ys;
	ld	a,(#_player_ys + 0)
	ld	b, a
	rla
	sbc	a, a
	ld	e, a
	ld	hl, #_player_y
	ld	a, (hl)
	add	a, b
	ld	(hl), a
	inc	hl
	ld	a, (hl)
	adc	a, e
	ld	(hl), a
;zorblaxx_player.c:214: if (player_y < player_y_min)
	ld	hl, #_player_y_min
	ld	iy, #_player_y
	ld	a, 0 (iy)
	sub	a, (hl)
	ld	a, 1 (iy)
	inc	hl
	sbc	a, (hl)
	jr	NC,00162$
;zorblaxx_player.c:216: player_y = player_y_min;
	ld	hl, (_player_y_min)
	ld	(_player_y), hl
;zorblaxx_player.c:217: if (player_ys < 0)
	ld	iy, #_player_ys
	bit	7,0 (iy)
	jr	Z,00163$
;zorblaxx_player.c:219: player_ys = 0;
	ld	0 (iy), #0x00
	jr	00163$
00162$:
;zorblaxx_player.c:222: else if (player_y > player_y_max)
	ld	hl, #_player_y_max
	ld	a, (hl)
	ld	iy, #_player_y
	sub	a, 0 (iy)
	inc	hl
	ld	a, (hl)
	sbc	a, 1 (iy)
	jr	NC,00163$
;zorblaxx_player.c:224: player_y = player_y_max;
	ld	hl, (_player_y_max)
	ld	(_player_y), hl
;zorblaxx_player.c:225: if (player_ys > 0)
	xor	a, a
	ld	iy, #_player_ys
	sub	a, 0 (iy)
	jp	PO, 00366$
	xor	a, #0x80
00366$:
	jp	P, 00163$
;zorblaxx_player.c:227: player_ys = 0;
	ld	hl,#_player_ys + 0
	ld	(hl), #0x00
00163$:
;zorblaxx_player.c:230: spr_x[player_sprite] = player_x / x_divisor;
	ld	de, #_spr_x+0
	ld	l, c
	ld	h, #0x00
	add	hl, hl
	add	hl, de
	ex	(sp), hl
	ld	hl,#_x_divisor + 0
	ld	e, (hl)
	ld	d, #0x00
	push	bc
	push	de
	ld	hl, (_player_x)
	push	hl
	call	__divuint
	pop	af
	pop	af
	ex	de,hl
	pop	bc
	pop	hl
	push	hl
	ld	(hl), e
	inc	hl
	ld	(hl), d
;zorblaxx_player.c:232: unsigned short y = player_y / y_divisor;
	ld	hl,#_y_divisor + 0
	ld	e, (hl)
	ld	d, #0x00
	push	bc
	push	de
	ld	hl, (_player_y)
	push	hl
	call	__divuint
	pop	af
	pop	af
	ex	de,hl
	pop	bc
;zorblaxx_player.c:233: spr_y_h[player_sprite] = y >> 8;
	ld	iy, #_spr_y_h
	push	bc
	ld	b, #0x00
	add	iy, bc
	pop	bc
	ld	0 (iy), d
;zorblaxx_player.c:234: spr_y_l[player_sprite] = (unsigned char)y;
	ld	hl, #_spr_y_l+0
	ld	b, #0x00
	add	hl, bc
	ld	(hl), e
;zorblaxx_player.c:237: player_trail_timer--;
	ld	iy, #_player_trail_timer
	dec	0 (iy)
;zorblaxx_player.c:238: if (player_trail_timer <= 0)
	ld	a, 0 (iy)
	or	a, a
	jr	NZ,00167$
;zorblaxx_player.c:240: player_trail_timer = player_trail_frequency - ((player_speed * 10) / 50);
	ld	hl,#_player_speed + 0
	ld	c, (hl)
	ld	b, #0x00
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, hl
	add	hl, bc
	add	hl, hl
	ld	bc, #0x0032
	push	bc
	push	hl
	call	__divsint
	pop	af
	pop	af
	ld	c, l
	ld	a,(#_player_trail_frequency + 0)
	ld	hl, #_player_trail_timer
	sub	a, c
	ld	(hl), a
;zorblaxx_player.c:241: if (player_trail_timer <= 0)
	ld	iy, #_player_trail_timer
	ld	a, 0 (iy)
	or	a, a
	jr	NZ,00165$
;zorblaxx_player.c:243: player_trail_timer = 1;
	ld	0 (iy), #0x01
00165$:
;zorblaxx_player.c:245: add_player_trail();
	call	_add_player_trail
00167$:
;zorblaxx_player.c:249: player_score_timer += player_speed;
	ld	hl, #_player_score_timer
	ld	a, (hl)
	ld	iy, #_player_speed
	add	a, 0 (iy)
	ld	(hl), a
;zorblaxx_player.c:250: if (player_score_timer >= 100)
	ld	iy, #_player_score_timer
	ld	a, 0 (iy)
	sub	a, #0x64
	jr	C,00170$
;zorblaxx_player.c:252: player_score_timer -= 100;
	ld	a, 0 (iy)
	ld	hl, #_player_score_timer
	add	a, #0x9c
	ld	(hl), a
;zorblaxx_player.c:253: player_score++;
	ld	iy, #_player_score
	inc	0 (iy)
	jr	NZ,00367$
	inc	1 (iy)
	jr	NZ,00367$
	inc	2 (iy)
	jr	NZ,00367$
	inc	3 (iy)
00367$:
00170$:
;zorblaxx_player.c:255: }
	ld	sp, ix
	pop	ix
	ret
	.area _CODE
	.area _INITIALIZER
__xinit__player_sprite_palette:
	.db #0x01	; 1
__xinit__player_xs:
	.db #0x00	;  0
__xinit__player_ys:
	.db #0x00	;  0
__xinit__player_speed_min:
	.db #0x08	; 8
__xinit__player_speed_max:
	.db #0x20	; 32
__xinit__player_score:
	.byte #0x00,#0x00,#0x00,#0x00	; 0
__xinit__player_score_timer:
	.db #0x00	; 0
__xinit__player_trail_timer:
	.db #0x01	; 1
__xinit__player_invincible_timer:
	.db #0x00	; 0
__xinit__player_invincible_flash:
	.db #0x00	; 0
__xinit__player_invincible_timeout:
	.db #0x78	; 120	'x'
__xinit__player_respawn_timer:
	.db #0x00	; 0
__xinit__player_respawn_timeout:
	.db #0x78	; 120	'x'
__xinit__player_explosion_timeout:
	.db #0x00	; 0
__xinit__player_hit:
	.db #0x00	; 0
	.area _CABS (ABS)
