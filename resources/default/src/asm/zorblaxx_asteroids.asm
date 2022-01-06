;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.8.0 #10562 (Linux)
;--------------------------------------------------------
	.module zorblaxx_asteroids
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _get_asteroid_timer
	.globl _enable_sprite
	.globl _set_sprite_position
	.globl _rand_schar
	.globl _rand_ushort
	.globl _rand_uchar
	.globl _asteroids_evaded
	.globl _asteroid_spawn_y
	.globl _asteroids_max
	.globl _asteroids_difficulty_speedspread
	.globl _asteroids_difficulty
	.globl _asteroids_active_max
	.globl _asteroids_active
	.globl _asteroids_y_max
	.globl _asteroids_timer
	.globl _asteroids_ys
	.globl _asteroids_xs
	.globl _asteroids_y
	.globl _asteroids_x
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
	.globl _setup_asteroids
	.globl _handle_asteroids
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
_asteroids_x::
	.ds 32
_asteroids_y::
	.ds 32
_asteroids_xs::
	.ds 16
_asteroids_ys::
	.ds 16
_asteroids_timer::
	.ds 16
_asteroids_y_max::
	.ds 2
_asteroids_active::
	.ds 1
_asteroids_active_max::
	.ds 1
_asteroids_difficulty::
	.ds 1
_asteroids_difficulty_speedspread::
	.ds 1
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
_asteroids_max::
	.ds 1
_asteroid_spawn_y::
	.ds 1
_asteroids_evaded::
	.ds 2
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
;zorblaxx_asteroids.c:44: unsigned char get_asteroid_timer()
;	---------------------------------
; Function get_asteroid_timer
; ---------------------------------
_get_asteroid_timer::
;zorblaxx_asteroids.c:46: unsigned char min_wait = asteroids_difficulty < 30 ? 30 - asteroids_difficulty : 0;
	ld	iy, #_asteroids_difficulty
	ld	c, 0 (iy)
	ld	a, 0 (iy)
	sub	a, #0x1e
	jr	NC,00103$
	ld	a, #0x1e
	sub	a, c
	ld	b, a
	rla
	sbc	a, a
	jr	00104$
00103$:
	ld	b, #0x00
00104$:
;zorblaxx_asteroids.c:47: unsigned char max_wait = asteroids_difficulty < 120 ? 120 - asteroids_difficulty : 0;
	ld	a,(#_asteroids_difficulty + 0)
	sub	a, #0x78
	jr	NC,00105$
	ld	a, #0x78
	sub	a, c
	ld	e, a
	rla
	sbc	a, a
	jr	00106$
00105$:
	ld	de, #0x0000
00106$:
	ld	d, e
;zorblaxx_asteroids.c:48: unsigned char random = rand_uchar(min_wait, max_wait);
	ld	e, b
	push	de
	call	_rand_uchar
	pop	af
;zorblaxx_asteroids.c:49: return random;
;zorblaxx_asteroids.c:50: }
	ret
;zorblaxx_asteroids.c:52: void setup_asteroids()
;	---------------------------------
; Function setup_asteroids
; ---------------------------------
_setup_asteroids::
	push	ix
	ld	ix,#0
	add	ix,sp
	push	af
	dec	sp
;zorblaxx_asteroids.c:54: asteroids_y_max = 272 * y_divisor;
	ld	hl,#_y_divisor + 0
	ld	c, (hl)
	ld	b, #0x00
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	ld	(_asteroids_y_max), hl
;zorblaxx_asteroids.c:56: for (unsigned char m = 0; m < asteroids_max; m++)
	ld	-1 (ix), #0x00
00103$:
	ld	hl, #_asteroids_max
	ld	a, -1 (ix)
	sub	a, (hl)
	jp	NC, 00105$
;zorblaxx_asteroids.c:58: asteroids_x[m] = rand_ushort(32, 320) * x_divisor;
	ld	l, -1 (ix)
	ld	h, #0x00
	add	hl, hl
	ld	c, l
	ld	b, h
	ld	hl, #_asteroids_x
	add	hl, bc
	ex	(sp), hl
	push	bc
	ld	hl, #0x0140
	push	hl
	ld	hl, #0x0020
	push	hl
	call	_rand_ushort
	pop	af
	pop	af
	pop	bc
	ld	iy, #_x_divisor
	ld	e, 0 (iy)
	ld	d, #0x00
	push	bc
	push	de
	push	hl
	call	__mulint
	pop	af
	pop	af
	ex	de,hl
	pop	bc
	pop	hl
	push	hl
	ld	(hl), e
	inc	hl
	ld	(hl), d
;zorblaxx_asteroids.c:59: asteroids_y[m] = asteroid_spawn_y;
	ld	hl, #_asteroids_y
	add	hl, bc
	ex	de, hl
	ld	a,(#_asteroid_spawn_y + 0)
	ld	b, #0x00
	ld	(de), a
	inc	de
	ld	a, b
	ld	(de), a
;zorblaxx_asteroids.c:60: asteroids_xs[m] = rand_schar(-asteroids_difficulty_speedspread, asteroids_difficulty_speedspread);
	ld	a, #<(_asteroids_xs)
	add	a, -1 (ix)
	ld	c, a
	ld	a, #>(_asteroids_xs)
	adc	a, #0x00
	ld	b, a
	ld	hl, #_asteroids_difficulty_speedspread
	xor	a, a
	sub	a, (hl)
	ld	d, a
	push	bc
	ld	a, (_asteroids_difficulty_speedspread)
	push	af
	inc	sp
	push	de
	inc	sp
	call	_rand_schar
	pop	af
	ld	a, l
	pop	bc
	ld	(bc), a
;zorblaxx_asteroids.c:61: asteroids_ys[m] = rand_uchar(4, 16 + asteroids_difficulty);
	ld	a, #<(_asteroids_ys)
	add	a, -1 (ix)
	ld	c, a
	ld	a, #>(_asteroids_ys)
	adc	a, #0x00
	ld	b, a
	ld	a,(#_asteroids_difficulty + 0)
	add	a, #0x10
	push	bc
	ld	d,a
	ld	e,#0x04
	push	de
	call	_rand_uchar
	pop	af
	ld	a, l
	pop	bc
	ld	(bc), a
;zorblaxx_asteroids.c:62: asteroids_timer[m] = get_asteroid_timer();
	ld	a, #<(_asteroids_timer)
	add	a, -1 (ix)
	ld	c, a
	ld	a, #>(_asteroids_timer)
	adc	a, #0x00
	ld	b, a
	push	bc
	call	_get_asteroid_timer
	ld	a, l
	pop	bc
	ld	(bc), a
;zorblaxx_asteroids.c:64: unsigned char sprite = asteroids_sprite_first + m;
	ld	a, -1 (ix)
	add	a, #0x0c
	ld	c, a
;zorblaxx_asteroids.c:65: spr_index[sprite] = sprite_index_asteroids_first + rand_uchar(0, sprite_index_asteroids_count - 1);
	ld	hl, #_spr_index
	ld	b, #0x00
	add	hl, bc
	push	hl
	push	bc
	ld	a, #0x07
	push	af
	inc	sp
	xor	a, a
	push	af
	inc	sp
	call	_rand_uchar
	pop	af
	ld	a, l
	pop	bc
	pop	hl
	ld	(hl), a
;zorblaxx_asteroids.c:66: enable_sprite(sprite, sprite_palette_asteroids, sprite_size_asteroids, true);
	push	bc
	ld	de, #0x0101
	push	de
	xor	a, a
	ld	b, a
	push	bc
	call	_enable_sprite
	pop	af
	pop	af
	pop	bc
;zorblaxx_asteroids.c:67: spr_on[sprite] = false;
	ld	hl, #_spr_on
	ld	b, #0x00
	add	hl, bc
	ld	(hl), #0x00
;zorblaxx_asteroids.c:68: set_sprite_position(sprite, asteroids_x[m] / x_divisor, 0);
	pop	hl
	push	hl
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	ld	iy, #_x_divisor
	ld	l, 0 (iy)
	ld	h, #0x00
	push	bc
	push	hl
	push	de
	call	__divuint
	pop	af
	pop	af
	pop	bc
	ld	de, #0x0000
	push	de
	push	hl
	ld	a, c
	push	af
	inc	sp
	call	_set_sprite_position
	pop	af
	pop	af
	inc	sp
;zorblaxx_asteroids.c:56: for (unsigned char m = 0; m < asteroids_max; m++)
	inc	-1 (ix)
	jp	00103$
00105$:
;zorblaxx_asteroids.c:70: }
	ld	sp, ix
	pop	ix
	ret
;zorblaxx_asteroids.c:72: void handle_asteroids(unsigned char spawn_enabled)
;	---------------------------------
; Function handle_asteroids
; ---------------------------------
_handle_asteroids::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	hl, #-14
	add	hl, sp
	ld	sp, hl
;zorblaxx_asteroids.c:74: asteroids_active = 0;
	ld	hl,#_asteroids_active + 0
	ld	(hl), #0x00
;zorblaxx_asteroids.c:75: for (unsigned char m = 0; m < asteroids_max; m++)
	ld	a, 4 (ix)
	dec	a
	jr	NZ, 00170$
	ld	a, #0x01
	.db	#0x20
00170$:
	xor	a, a
00171$:
	ld	-12 (ix), a
	ld	-1 (ix), #0x00
00120$:
	ld	hl, #_asteroids_max
	ld	a, -1 (ix)
	sub	a, (hl)
	jp	NC, 00122$
;zorblaxx_asteroids.c:77: unsigned char sprite = asteroids_sprite_first + m;
	ld	a, -1 (ix)
	ld	-11 (ix), a
	add	a, #0x0c
	ld	-2 (ix), a
;zorblaxx_asteroids.c:78: if (m < asteroids_active_max)
	ld	hl, #_asteroids_active_max
	ld	a, -1 (ix)
	sub	a, (hl)
	jp	NC, 00121$
;zorblaxx_asteroids.c:80: if (asteroids_timer[m] > 0)
	ld	a, #<(_asteroids_timer)
	add	a, -1 (ix)
	ld	-14 (ix), a
	ld	a, #>(_asteroids_timer)
	adc	a, #0x00
	ld	-13 (ix), a
	pop	hl
	push	hl
	ld	c, (hl)
	ld	a, c
	or	a, a
	jr	Z,00114$
;zorblaxx_asteroids.c:82: if (spawn_enabled == 1)
	ld	a, -12 (ix)
	or	a, a
	jp	Z, 00121$
;zorblaxx_asteroids.c:84: asteroids_timer[m]--;
	ld	a, c
	dec	a
	pop	hl
	push	hl
	ld	(hl), a
;zorblaxx_asteroids.c:85: if (asteroids_timer[m] == 0)
	or	a, a
	jp	NZ, 00121$
;zorblaxx_asteroids.c:87: spr_index[sprite] = rand_uchar(sprite_index_asteroids_first, sprite_index_asteroids_last);
	ld	a, #<(_spr_index)
	add	a, -2 (ix)
	ld	c, a
	ld	a, #>(_spr_index)
	adc	a, #0x00
	ld	b, a
	push	bc
	ld	a, #0x07
	push	af
	inc	sp
	xor	a, a
	push	af
	inc	sp
	call	_rand_uchar
	pop	af
	ld	a, l
	pop	bc
	ld	(bc), a
;zorblaxx_asteroids.c:88: spr_on[sprite] = 1;
	ld	a, #<(_spr_on)
	add	a, -2 (ix)
	ld	l, a
	ld	a, #>(_spr_on)
	adc	a, #0x00
	ld	h, a
	ld	(hl), #0x01
	jp	00121$
00114$:
;zorblaxx_asteroids.c:94: asteroids_active++;
	ld	hl, #_asteroids_active+0
	inc	(hl)
;zorblaxx_asteroids.c:95: asteroids_x[m] += asteroids_xs[m];
	ld	l, -1 (ix)
	ld	h, #0x00
	add	hl, hl
	ld	c, l
	ld	b, h
	ld	hl, #_asteroids_x
	add	hl, bc
	ld	-4 (ix), l
	ld	-3 (ix), h
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	ld	a, #<(_asteroids_xs)
	add	a, -1 (ix)
	ld	-8 (ix), a
	ld	a, #>(_asteroids_xs)
	adc	a, #0x00
	ld	-7 (ix), a
	ld	l, -8 (ix)
	ld	h, -7 (ix)
	ld	l, (hl)
	ld	a, l
	rla
	sbc	a, a
	ld	h, a
	add	hl, de
	ex	de, hl
	ld	l, -4 (ix)
	ld	h, -3 (ix)
	ld	(hl), e
	inc	hl
	ld	(hl), d
;zorblaxx_asteroids.c:96: if (asteroids_x[m] < x_h_min)
	ld	l, -4 (ix)
	ld	h, -3 (ix)
	ld	a, (hl)
	ld	-10 (ix), a
	inc	hl
	ld	a, (hl)
	ld	-9 (ix), a
	ld	hl, #_x_h_min
	ld	a, e
	sub	a, (hl)
	ld	a, d
	inc	hl
	sbc	a, (hl)
	jr	NC,00108$
;zorblaxx_asteroids.c:98: asteroids_x[m] = x_h_max;
	ld	l, -4 (ix)
	ld	h, -3 (ix)
	ld	iy, #_x_h_max
	ld	a, 0 (iy)
	ld	(hl), a
	inc	hl
	ld	a, 1 (iy)
	ld	(hl), a
	jr	00109$
00108$:
;zorblaxx_asteroids.c:100: else if (asteroids_x[m] > x_h_max)
	ld	hl, #_x_h_max
	ld	a, (hl)
	sub	a, -10 (ix)
	inc	hl
	ld	a, (hl)
	sbc	a, -9 (ix)
	jr	NC,00109$
;zorblaxx_asteroids.c:102: asteroids_x[m] = x_h_min;
	ld	l, -4 (ix)
	ld	h, -3 (ix)
	ld	iy, #_x_h_min
	ld	a, 0 (iy)
	ld	(hl), a
	inc	hl
	ld	a, 1 (iy)
	ld	(hl), a
00109$:
;zorblaxx_asteroids.c:104: if (asteroids_y[m] >= asteroids_y_max)
	ld	hl, #_asteroids_y
	add	hl, bc
	ld	-10 (ix), l
	ld	-9 (ix), h
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	ld	hl, #_asteroids_y_max
	ld	a, c
	sub	a, (hl)
	ld	a, b
	inc	hl
	sbc	a, (hl)
	jp	C, 00111$
;zorblaxx_asteroids.c:106: spr_on[sprite] = 0;
	ld	a, #<(_spr_on)
	add	a, -2 (ix)
	ld	c, a
	ld	a, #>(_spr_on)
	adc	a, #0x00
	ld	b, a
	xor	a, a
	ld	(bc), a
;zorblaxx_asteroids.c:107: asteroids_x[m] = rand_ushort(32, 320) * x_divisor;
	ld	hl, #0x0140
	push	hl
	ld	hl, #0x0020
	push	hl
	call	_rand_ushort
	pop	af
	pop	af
	ld	a,(#_x_divisor + 0)
	ld	-6 (ix), a
	ld	-5 (ix), #0x00
	ld	c, a
	ld	b, #0x00
	push	bc
	push	hl
	call	__mulint
	pop	af
	pop	af
	ld	c, l
	ld	b, h
	ld	l, -4 (ix)
	ld	h, -3 (ix)
	ld	(hl), c
	inc	hl
	ld	(hl), b
;zorblaxx_asteroids.c:108: asteroids_y[m] = asteroid_spawn_y * y_divisor;
	ld	hl,#_y_divisor + 0
	ld	e, (hl)
	push	bc
	ld	iy, #_asteroid_spawn_y
	ld	h, 0 (iy)
	ld	l, #0x00
	ld	d, l
	ld	b, #0x08
00172$:
	add	hl, hl
	jr	NC,00173$
	add	hl, de
00173$:
	djnz	00172$
	pop	bc
	ex	de, hl
	ld	l, -10 (ix)
	ld	h, -9 (ix)
	ld	(hl), e
	inc	hl
	ld	(hl), d
;zorblaxx_asteroids.c:109: set_sprite_position(sprite, asteroids_x[m] / x_divisor, asteroid_spawn_y);
	ld	e, 0 (iy)
	ld	d, #0x00
	push	de
	ld	l, -6 (ix)
	ld	h, -5 (ix)
	push	hl
	push	bc
	call	__divuint
	pop	af
	ex	(sp),hl
	ld	a, -2 (ix)
	push	af
	inc	sp
	call	_set_sprite_position
	pop	af
	pop	af
	inc	sp
;zorblaxx_asteroids.c:110: asteroids_xs[m] = rand_schar(-asteroids_difficulty_speedspread, asteroids_difficulty_speedspread);
	ld	hl, #_asteroids_difficulty_speedspread
	xor	a, a
	sub	a, (hl)
	ld	b, a
	ld	a, (_asteroids_difficulty_speedspread)
	push	af
	inc	sp
	push	bc
	inc	sp
	call	_rand_schar
	pop	af
	ld	a, l
	ld	l, -8 (ix)
	ld	h, -7 (ix)
	ld	(hl), a
;zorblaxx_asteroids.c:111: asteroids_ys[m] = rand_uchar(4, 16 + asteroids_difficulty);
	ld	a, #<(_asteroids_ys)
	add	a, -1 (ix)
	ld	c, a
	ld	a, #>(_asteroids_ys)
	adc	a, #0x00
	ld	b, a
	ld	a,(#_asteroids_difficulty + 0)
	add	a, #0x10
	push	bc
	ld	d,a
	ld	e,#0x04
	push	de
	call	_rand_uchar
	pop	af
	ld	a, l
	pop	bc
	ld	(bc), a
;zorblaxx_asteroids.c:112: asteroids_timer[m] = get_asteroid_timer();
	call	_get_asteroid_timer
	ld	a, l
	pop	hl
	push	hl
	ld	(hl), a
;zorblaxx_asteroids.c:113: asteroids_evaded++;
	ld	iy, #_asteroids_evaded
	inc	0 (iy)
	jr	NZ,00121$
	inc	1 (iy)
	jr	00121$
00111$:
;zorblaxx_asteroids.c:117: asteroids_y[m] += asteroids_ys[m] + scroll_speed;
	ld	a, #<(_asteroids_ys)
	add	a, -1 (ix)
	ld	e, a
	ld	a, #>(_asteroids_ys)
	adc	a, #0x00
	ld	d, a
	ld	a, (de)
	ld	e, a
	rla
	sbc	a, a
	ld	d, a
	ld	iy, #_scroll_speed
	ld	l, 0 (iy)
	ld	h, #0x00
	add	hl, de
	add	hl, bc
	ex	de, hl
	ld	l, -10 (ix)
	ld	h, -9 (ix)
	ld	(hl), e
	inc	hl
	ld	(hl), d
;zorblaxx_asteroids.c:118: set_sprite_position(sprite, asteroids_x[m] / x_divisor, asteroids_y[m] / y_divisor);
	ld	hl,#_y_divisor + 0
	ld	c, (hl)
	ld	b, #0x00
	push	bc
	push	de
	call	__divuint
	pop	af
	pop	af
	ld	c, l
	ld	b, h
	ld	l, -4 (ix)
	ld	h, -3 (ix)
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	ld	iy, #_x_divisor
	ld	l, 0 (iy)
	ld	h, #0x00
	push	bc
	push	hl
	push	de
	call	__divuint
	pop	af
	ex	(sp),hl
	ld	a, -2 (ix)
	push	af
	inc	sp
	call	_set_sprite_position
	pop	af
	pop	af
	inc	sp
00121$:
;zorblaxx_asteroids.c:75: for (unsigned char m = 0; m < asteroids_max; m++)
	inc	-1 (ix)
	jp	00120$
00122$:
;zorblaxx_asteroids.c:123: }
	ld	sp, ix
	pop	ix
	ret
	.area _CODE
	.area _INITIALIZER
__xinit__asteroids_max:
	.db #0x10	; 16
__xinit__asteroid_spawn_y:
	.db #0x00	; 0
__xinit__asteroids_evaded:
	.dw #0x0000
	.area _CABS (ABS)
