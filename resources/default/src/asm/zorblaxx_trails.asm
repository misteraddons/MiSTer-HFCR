;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.8.0 #10562 (Linux)
;--------------------------------------------------------
	.module zorblaxx_trails
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _enable_sprite
	.globl _set_sprite_position
	.globl _rand_schar
	.globl _trail_max
	.globl _trail_y_offset
	.globl _trail_x_offset
	.globl _trail_y_max
	.globl _trail_timer
	.globl _trail_ys
	.globl _trail_xs
	.globl _trail_y
	.globl _trail_x
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
	.globl _setup_trails
	.globl _add_player_trail
	.globl _handle_trails
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
_trail_x::
	.ds 20
_trail_y::
	.ds 20
_trail_xs::
	.ds 10
_trail_ys::
	.ds 10
_trail_timer::
	.ds 10
_trail_y_max::
	.ds 2
_trail_x_offset::
	.ds 1
_trail_y_offset::
	.ds 1
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
_trail_max::
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
;zorblaxx_trails.c:41: void setup_trails()
;	---------------------------------
; Function setup_trails
; ---------------------------------
_setup_trails::
;zorblaxx_trails.c:43: trail_y_max = 272 * y_divisor;
	ld	hl,#_y_divisor + 0
	ld	c, (hl)
	ld	e, c
	ld	d, #0x00
	ld	l, e
	ld	h, d
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	ld	(_trail_y_max), hl
;zorblaxx_trails.c:44: trail_x_offset = (4 * x_divisor);
	ld	a,(#_x_divisor + 0)
	add	a, a
	add	a, a
	ld	(#_trail_x_offset + 0),a
;zorblaxx_trails.c:45: trail_y_offset = (12 * y_divisor);
	ld	a, c
	add	a, a
	add	a, c
	add	a, a
	add	a, a
	ld	(#_trail_y_offset + 0),a
;zorblaxx_trails.c:46: for (int t = trail_sprite_first; t < trail_sprite_first + trail_max; t++)
	ld	bc, #0x0000
00103$:
	ld	hl,#_trail_max + 0
	ld	e, (hl)
	ld	d, #0x00
	ld	a, c
	sub	a, e
	ld	a, b
	sbc	a, d
	jp	PO, 00118$
	xor	a, #0x80
00118$:
	ret	P
;zorblaxx_trails.c:48: enable_sprite(t, sprite_palette_trails, sprite_size_trails, false);
	ld	d, c
	push	bc
	xor	a, a
	ld	b,a
	ld	c,#0x02
	push	bc
	ld	a, #0x01
	push	af
	inc	sp
	push	de
	inc	sp
	call	_enable_sprite
	pop	af
	pop	af
	pop	bc
;zorblaxx_trails.c:49: spr_on[t] = false;
	ld	hl, #_spr_on
	add	hl, bc
	ld	(hl), #0x00
;zorblaxx_trails.c:46: for (int t = trail_sprite_first; t < trail_sprite_first + trail_max; t++)
	inc	bc
;zorblaxx_trails.c:51: }
	jr	00103$
;zorblaxx_trails.c:53: void add_player_trail()
;	---------------------------------
; Function add_player_trail
; ---------------------------------
_add_player_trail::
	push	ix
	ld	ix,#0
	add	ix,sp
	push	af
	push	af
;zorblaxx_trails.c:55: for (unsigned char t = 0; t < trail_max; t++)
	ld	e, #0x00
	ld	c, #0x00
00105$:
	ld	hl, #_trail_max
	ld	a, c
	sub	a, (hl)
	jp	NC, 00107$
;zorblaxx_trails.c:57: if (trail_timer[t] == 0)
	ld	hl, #_trail_timer
	ld	b, #0x00
	add	hl, bc
	ld	a, (hl)
	or	a, a
	jp	NZ, 00106$
;zorblaxx_trails.c:59: unsigned char spread = 3 + (player_speed / 8);
	ld	hl,#_player_speed + 0
	ld	c, (hl)
	ld	b, #0x00
	ld	l, c
	ld	h, b
	bit	7, b
	jr	Z,00109$
	ld	hl, #0x0007
	add	hl, bc
00109$:
	sra	h
	rr	l
	sra	h
	rr	l
	sra	h
	rr	l
	ld	c, l
	inc	c
	inc	c
	inc	c
;zorblaxx_trails.c:60: trail_xs[t] = rand_schar(-spread, spread);
	ld	hl, #_trail_xs
	ld	d, #0x00
	add	hl, de
	xor	a, a
	sub	a, c
	ld	b, a
	push	hl
	push	de
	ld	a, c
	push	af
	inc	sp
	push	bc
	inc	sp
	call	_rand_schar
	pop	af
	ld	a, l
	pop	de
	pop	hl
	ld	(hl), a
;zorblaxx_trails.c:61: trail_ys[t] = player_trail_speed;
	ld	hl, #_trail_ys
	ld	d, #0x00
	add	hl, de
	ld	iy, #_player_trail_speed
	ld	d, 0 (iy)
	ld	(hl), d
;zorblaxx_trails.c:63: trail_x[t] = (player_x + trail_x_offset);
	ld	l, e
	ld	h, #0x00
	add	hl, hl
	ld	-2 (ix), l
	ld	-1 (ix), h
	ld	a, #<(_trail_x)
	add	a, -2 (ix)
	ld	-4 (ix), a
	ld	a, #>(_trail_x)
	adc	a, -1 (ix)
	ld	-3 (ix), a
	ld	hl,#_trail_x_offset + 0
	ld	c, (hl)
	ld	b, #0x00
	ld	iy, #_player_x
	ld	a, 0 (iy)
	add	a, c
	ld	c, a
	ld	a, 1 (iy)
	adc	a, b
	ld	b, a
	pop	hl
	push	hl
	ld	(hl), c
	inc	hl
	ld	(hl), b
;zorblaxx_trails.c:64: trail_y[t] = (player_y + trail_y_offset) - (player_trail_speed + player_speed);
	ld	a, #<(_trail_y)
	add	a, -2 (ix)
	ld	-4 (ix), a
	ld	a, #>(_trail_y)
	adc	a, -1 (ix)
	ld	-3 (ix), a
	ld	hl,#_trail_y_offset + 0
	ld	c, (hl)
	ld	b, #0x00
	ld	iy, #_player_y
	ld	a, 0 (iy)
	add	a, c
	ld	-2 (ix), a
	ld	a, 1 (iy)
	adc	a, b
	ld	-1 (ix), a
	ld	c, d
	ld	b, #0x00
	ld	iy, #_player_speed
	ld	l, 0 (iy)
	ld	h, #0x00
	add	hl, bc
	ld	a, -2 (ix)
	sub	a, l
	ld	c, a
	ld	a, -1 (ix)
	sbc	a, h
	ld	b, a
	pop	hl
	push	hl
	ld	(hl), c
	inc	hl
	ld	(hl), b
;zorblaxx_trails.c:66: trail_timer[t] = player_trail_lifespan;
	ld	hl, #_trail_timer
	ld	d, #0x00
	add	hl, de
	ld	a,(#_player_trail_lifespan + 0)
	ld	(hl), a
;zorblaxx_trails.c:68: enable_sprite(sprite, sprite_palette_trails, sprite_size_trails, false);
	push	de
	xor	a, a
	ld	b,a
	ld	c,#0x02
	push	bc
	ld	d,#0x01
	push	de
	call	_enable_sprite
	pop	af
	pop	af
	pop	de
;zorblaxx_trails.c:69: spr_index[sprite] = sprite_index_trails_first;
	ld	hl, #_spr_index+0
	ld	d, #0x00
	add	hl, de
	ld	(hl), #0x00
;zorblaxx_trails.c:70: return;
	jr	00107$
00106$:
;zorblaxx_trails.c:55: for (unsigned char t = 0; t < trail_max; t++)
	inc	c
	ld	e, c
	jp	00105$
00107$:
;zorblaxx_trails.c:73: }
	ld	sp, ix
	pop	ix
	ret
;zorblaxx_trails.c:75: void handle_trails()
;	---------------------------------
; Function handle_trails
; ---------------------------------
_handle_trails::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	hl, #-10
	add	hl, sp
	ld	sp, hl
;zorblaxx_trails.c:77: for (unsigned char t = 0; t < trail_max; t++)
	ld	-1 (ix), #0x00
00113$:
	ld	hl, #_trail_max
	ld	a, -1 (ix)
	sub	a, (hl)
	jp	NC, 00114$
;zorblaxx_trails.c:79: if (trail_timer[t] > 0)
	ld	a, #<(_trail_timer)
	add	a, -1 (ix)
	ld	-5 (ix), a
	ld	a, #>(_trail_timer)
	adc	a, #0x00
	ld	-4 (ix), a
	ld	l, -5 (ix)
	ld	h, -4 (ix)
	ld	a, (hl)
	ld	-6 (ix), a
	or	a, a
	jp	Z, 00110$
;zorblaxx_trails.c:81: unsigned char sprite = trail_sprite_first + t;
	ld	a, -1 (ix)
	ld	-6 (ix), a
;zorblaxx_trails.c:82: trail_y[t] += trail_ys[t] + player_speed;
	ld	l, -1 (ix)
	ld	h, #0x00
	add	hl, hl
	ld	c, l
	ld	b, h
	ld	hl, #_trail_y
	add	hl, bc
	ld	-8 (ix), l
	ld	-7 (ix), h
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	ld	a, #<(_trail_ys)
	add	a, -1 (ix)
	ld	l, a
	ld	a, #>(_trail_ys)
	adc	a, #0x00
	ld	h, a
	ld	a, (hl)
	ld	-10 (ix), a
	rla
	sbc	a, a
	ld	-9 (ix), a
	ld	iy, #_player_speed
	ld	l, 0 (iy)
	ld	h, #0x00
	ld	a, -10 (ix)
	add	a, l
	ld	l, a
	ld	a, -9 (ix)
	adc	a, h
	ld	h, a
	add	hl, de
	ex	de, hl
	ld	l, -8 (ix)
	ld	h, -7 (ix)
	ld	(hl), e
	inc	hl
	ld	(hl), d
;zorblaxx_trails.c:83: if ((trail_y[t] > trail_y_max) > 0)
	ld	hl, #_trail_y_max
	ld	a, (hl)
	sub	a, e
	inc	hl
	ld	a, (hl)
	sbc	a, d
	jr	NC,00102$
;zorblaxx_trails.c:85: spr_on[sprite] = false;
	ld	a, #<(_spr_on)
	add	a, -1 (ix)
	ld	c, a
	ld	a, #>(_spr_on)
	adc	a, #0x00
	ld	b, a
	xor	a, a
	ld	(bc), a
;zorblaxx_trails.c:86: trail_timer[t] = 0;
	ld	l, -5 (ix)
	ld	h, -4 (ix)
	ld	(hl), #0x00
;zorblaxx_trails.c:87: continue;
	jp	00110$
00102$:
;zorblaxx_trails.c:89: trail_timer[t]--;
	ld	l, -5 (ix)
	ld	h, -4 (ix)
	ld	a, (hl)
	dec	a
	ld	l, -5 (ix)
	ld	h, -4 (ix)
	ld	(hl), a
;zorblaxx_trails.c:90: if (trail_timer[t] == 0)
	or	a, a
	jr	NZ,00107$
;zorblaxx_trails.c:92: spr_index[sprite]++;
	ld	a, #<(_spr_index)
	add	a, -1 (ix)
	ld	l, a
	ld	a, #>(_spr_index)
	adc	a, #0x00
	ld	h, a
	ld	e, (hl)
	inc	e
	ld	(hl), e
;zorblaxx_trails.c:93: if (spr_index[sprite] > sprite_index_trails_last)
	ld	a, #0x03
	sub	a, e
	jr	NC,00104$
;zorblaxx_trails.c:95: spr_on[sprite] = false;
	ld	a, #<(_spr_on)
	add	a, -1 (ix)
	ld	e, a
	ld	a, #>(_spr_on)
	adc	a, #0x00
	ld	d, a
	xor	a, a
	ld	(de), a
	jr	00107$
00104$:
;zorblaxx_trails.c:99: trail_timer[t] = player_trail_lifespan;
	ld	a,(#_player_trail_lifespan + 0)
	ld	l, -5 (ix)
	ld	h, -4 (ix)
	ld	(hl), a
00107$:
;zorblaxx_trails.c:102: trail_x[t] += trail_xs[t];
	ld	hl, #_trail_x
	add	hl, bc
	ex	(sp), hl
	pop	hl
	push	hl
	ld	a, (hl)
	ld	-5 (ix), a
	inc	hl
	ld	a, (hl)
	ld	-4 (ix), a
	ld	a, #<(_trail_xs)
	add	a, -1 (ix)
	ld	-3 (ix), a
	ld	a, #>(_trail_xs)
	adc	a, #0x00
	ld	-2 (ix), a
	ld	l, -3 (ix)
	ld	h, -2 (ix)
	ld	a, (hl)
	ld	-3 (ix), a
	ld	-3 (ix), a
	rla
	sbc	a, a
	ld	-2 (ix), a
	ld	a, -3 (ix)
	add	a, -5 (ix)
	ld	-3 (ix), a
	ld	a, -2 (ix)
	adc	a, -4 (ix)
	ld	-2 (ix), a
	pop	hl
	push	hl
	ld	a, -3 (ix)
	ld	(hl), a
	inc	hl
	ld	a, -2 (ix)
	ld	(hl), a
;zorblaxx_trails.c:104: set_sprite_position(sprite, trail_x[t] / x_divisor, trail_y[t] / y_divisor);
	ld	l, -8 (ix)
	ld	h, -7 (ix)
	ld	a, (hl)
	ld	-10 (ix), a
	inc	hl
	ld	a, (hl)
	ld	-9 (ix), a
	ld	a,(#_y_divisor + 0)
	ld	-8 (ix), a
	ld	-8 (ix), a
	ld	-7 (ix), #0x00
	pop	bc
	pop	hl
	push	hl
	push	bc
	ld	c, l
	ld	b, h
	pop	hl
	push	hl
	push	bc
	push	hl
	call	__divuint
	pop	af
	pop	af
	ld	-9 (ix), h
	ld	-10 (ix), l
	ld	a,(#_x_divisor + 0)
	ld	-8 (ix), a
	ld	-7 (ix), #0x00
	pop	bc
	pop	hl
	push	hl
	push	bc
	push	hl
	ld	l, -3 (ix)
	ld	h, -2 (ix)
	push	hl
	call	__divuint
	pop	af
	pop	af
	ld	-2 (ix), h
	ld	-3 (ix), l
	pop	hl
	push	hl
	push	hl
	ld	l, -3 (ix)
	ld	h, -2 (ix)
	push	hl
	ld	a, -6 (ix)
	push	af
	inc	sp
	call	_set_sprite_position
	pop	af
	pop	af
	inc	sp
00110$:
;zorblaxx_trails.c:77: for (unsigned char t = 0; t < trail_max; t++)
	inc	-1 (ix)
	jp	00113$
00114$:
;zorblaxx_trails.c:107: }
	ld	sp, ix
	pop	ix
	ret
	.area _CODE
	.area _INITIALIZER
__xinit__trail_max:
	.db #0x0a	; 10
	.area _CABS (ABS)
