;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.8.0 #10562 (Linux)
;--------------------------------------------------------
	.module zorblaxx_asteroids
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _get_meteortimer
	.globl _enable_sprite
	.globl _rand_schar
	.globl _rand_ushort
	.globl _rand_uchar
	.globl _meteor_sprite_palette
	.globl _meteor_sprite_first
	.globl _meteor_max
	.globl _meteor_difficulty_frequency
	.globl _meteor_difficulty_timer
	.globl _meteor_difficulty
	.globl _meteor_active_max
	.globl _meteor_y_max
	.globl _meteor_timer
	.globl _meteor_ys
	.globl _meteor_xs
	.globl _meteor_y
	.globl _meteor_x
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
	.globl _update_meteordifficulty
	.globl _setup_meteors
	.globl _handle_meteors
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
_meteor_x::
	.ds 32
_meteor_y::
	.ds 32
_meteor_xs::
	.ds 16
_meteor_ys::
	.ds 16
_meteor_timer::
	.ds 16
_meteor_y_max::
	.ds 2
_meteor_active_max::
	.ds 1
_meteor_difficulty::
	.ds 1
_meteor_difficulty_timer::
	.ds 2
_meteor_difficulty_frequency::
	.ds 2
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
_meteor_max::
	.ds 1
_meteor_sprite_first::
	.ds 1
_meteor_sprite_palette::
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
;zorblaxx_asteroids.c:43: void update_meteordifficulty()
;	---------------------------------
; Function update_meteordifficulty
; ---------------------------------
_update_meteordifficulty::
;zorblaxx_asteroids.c:45: meteor_difficulty_timer = 0;
	ld	hl, #0x0000
	ld	(_meteor_difficulty_timer), hl
;zorblaxx_asteroids.c:46: meteor_difficulty++;
	ld	iy, #_meteor_difficulty
	inc	0 (iy)
;zorblaxx_asteroids.c:47: meteor_active_max = 5 + meteor_difficulty;
	ld	a, 0 (iy)
	add	a, #0x05
	ld	iy, #_meteor_active_max
	ld	0 (iy), a
;zorblaxx_asteroids.c:48: if (meteor_active_max > meteor_max)
	ld	a, (#_meteor_max)
	sub	a, 0 (iy)
	ret	NC
;zorblaxx_asteroids.c:50: meteor_active_max = meteor_max;
	ld	a,(#_meteor_max + 0)
	ld	(#_meteor_active_max + 0),a
;zorblaxx_asteroids.c:52: }
	ret
;zorblaxx_asteroids.c:54: unsigned char get_meteortimer()
;	---------------------------------
; Function get_meteortimer
; ---------------------------------
_get_meteortimer::
;zorblaxx_asteroids.c:58: unsigned char max_wait = 120 / meteor_difficulty;
	ld	hl,#_meteor_difficulty + 0
	ld	c, (hl)
	ld	b, #0x00
	push	bc
	ld	hl, #0x0078
	push	hl
	call	__divsint
	pop	af
	pop	af
	ld	b, l
;zorblaxx_asteroids.c:59: unsigned char random = rand_uchar(always_wait, max_wait);
	push	bc
	inc	sp
	xor	a, a
	push	af
	inc	sp
	call	_rand_uchar
	pop	af
;zorblaxx_asteroids.c:60: return random;
;zorblaxx_asteroids.c:61: }
	ret
;zorblaxx_asteroids.c:63: void setup_meteors()
;	---------------------------------
; Function setup_meteors
; ---------------------------------
_setup_meteors::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	hl, #-6
	add	hl, sp
	ld	sp, hl
;zorblaxx_asteroids.c:65: meteor_y_max = 256 * y_divisor;
	ld	hl,#_y_divisor + 0
	ld	c, (hl)
	ld	iy, #_meteor_y_max
	ld	1 (iy), c
	ld	0 (iy), #0x00
;zorblaxx_asteroids.c:66: meteor_difficulty = 0;
	ld	hl,#_meteor_difficulty + 0
	ld	(hl), #0x00
;zorblaxx_asteroids.c:67: meteor_difficulty_frequency = 10 * 60;
	ld	hl, #0x0258
	ld	(_meteor_difficulty_frequency), hl
;zorblaxx_asteroids.c:68: update_meteordifficulty();
	call	_update_meteordifficulty
;zorblaxx_asteroids.c:70: for (unsigned char m = 0; m < meteor_max; m++)
	ld	-1 (ix), #0x00
00103$:
	ld	hl, #_meteor_max
	ld	a, -1 (ix)
	sub	a, (hl)
	jp	NC, 00105$
;zorblaxx_asteroids.c:72: meteor_x[m] = rand_ushort(24, 296) * x_divisor;
	ld	l, -1 (ix)
	ld	h, #0x00
	add	hl, hl
	ld	c, l
	ld	b, h
	ld	hl, #_meteor_x
	add	hl, bc
	ld	-5 (ix), l
	ld	-4 (ix), h
	push	bc
	ld	hl, #0x0128
	push	hl
	ld	hl, #0x0018
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
	ld	l, -5 (ix)
	ld	h, -4 (ix)
	ld	(hl), e
	inc	hl
	ld	(hl), d
;zorblaxx_asteroids.c:73: meteor_y[m] = 0;
	ld	hl, #_meteor_y
	add	hl, bc
	xor	a, a
	ld	(hl), a
	inc	hl
	ld	(hl), a
;zorblaxx_asteroids.c:74: meteor_xs[m] = rand_schar(-(2 + (meteor_difficulty / 4)), 2 + (meteor_difficulty / 4));
	ld	a, #<(_meteor_xs)
	add	a, -1 (ix)
	ld	c, a
	ld	a, #>(_meteor_xs)
	adc	a, #0x00
	ld	b, a
	ld	iy, #_meteor_difficulty
	ld	l, 0 (iy)
	ld	h, #0x00
	ld	e, l
	ld	a,h
	ld	d,a
	rlca
	and	a,#0x01
	ld	-6 (ix), a
	ld	a, l
	add	a, #0x03
	ld	-3 (ix), a
	ld	a, h
	adc	a, #0x00
	ld	-2 (ix), a
	ld	a, -6 (ix)
	or	a, a
	jr	Z,00107$
	ld	e, -3 (ix)
	ld	d, -2 (ix)
00107$:
	sra	d
	rr	e
	sra	d
	rr	e
	ld	d, e
	inc	d
	inc	d
	ld	a, -6 (ix)
	or	a, a
	jr	Z,00108$
	ld	l, -3 (ix)
	ld	h, -2 (ix)
00108$:
	sra	h
	rr	l
	sra	h
	rr	l
	inc	l
	inc	l
	xor	a, a
	sub	a, l
	push	bc
	ld	e, a
	push	de
	call	_rand_schar
	pop	af
	ld	a, l
	pop	bc
	ld	(bc), a
;zorblaxx_asteroids.c:75: meteor_ys[m] = rand_uchar(4, 16 + meteor_difficulty);
	ld	a, #<(_meteor_ys)
	add	a, -1 (ix)
	ld	c, a
	ld	a, #>(_meteor_ys)
	adc	a, #0x00
	ld	b, a
	ld	a,(#_meteor_difficulty + 0)
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
;zorblaxx_asteroids.c:76: meteor_timer[m] = get_meteortimer();
	ld	a, #<(_meteor_timer)
	add	a, -1 (ix)
	ld	c, a
	ld	a, #>(_meteor_timer)
	adc	a, #0x00
	ld	b, a
	push	bc
	call	_get_meteortimer
	ld	a, l
	pop	bc
	ld	(bc), a
;zorblaxx_asteroids.c:78: unsigned char sprite = meteor_sprite_first + m;
	ld	a,(#_meteor_sprite_first + 0)
	add	a, -1 (ix)
	ld	c, a
;zorblaxx_asteroids.c:79: spr_index[sprite] = meteor_sprite_index_first + rand_uchar(0, meteor_sprite_index_count - 1);
	ld	hl, #_spr_index
	ld	b, #0x00
	add	hl, bc
	push	hl
	push	bc
	ld	a, #0x05
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
;zorblaxx_asteroids.c:80: enable_sprite(sprite, meteor_sprite_palette, true);
	push	bc
	ld	a, #0x01
	push	af
	inc	sp
	ld	a, (_meteor_sprite_palette)
	ld	b, a
	push	bc
	call	_enable_sprite
	pop	af
	inc	sp
	pop	bc
;zorblaxx_asteroids.c:81: spr_on[sprite] = false;
	ld	hl, #_spr_on
	ld	b, #0x00
	add	hl, bc
	ld	(hl), #0x00
;zorblaxx_asteroids.c:82: spr_x[sprite] = meteor_x[m] / x_divisor;
	ld	l, c
	ld	h, #0x00
	add	hl, hl
	ld	de, #_spr_x
	add	hl, de
	ld	-3 (ix), l
	ld	-2 (ix), h
	ld	l, -5 (ix)
	ld	h, -4 (ix)
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
	ex	de,hl
	pop	bc
	ld	l, -3 (ix)
	ld	h, -2 (ix)
	ld	(hl), e
	inc	hl
	ld	(hl), d
;zorblaxx_asteroids.c:83: spr_y_h[sprite] = 0;
	ld	hl, #_spr_y_h
	ld	b, #0x00
	add	hl, bc
	ld	(hl), #0x00
;zorblaxx_asteroids.c:84: spr_y_l[sprite] = 0;
	ld	hl, #_spr_y_l
	ld	b, #0x00
	add	hl, bc
	ld	(hl), #0x00
;zorblaxx_asteroids.c:70: for (unsigned char m = 0; m < meteor_max; m++)
	inc	-1 (ix)
	jp	00103$
00105$:
;zorblaxx_asteroids.c:86: }
	ld	sp, ix
	pop	ix
	ret
;zorblaxx_asteroids.c:88: void handle_meteors()
;	---------------------------------
; Function handle_meteors
; ---------------------------------
_handle_meteors::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	hl, #-12
	add	hl, sp
	ld	sp, hl
;zorblaxx_asteroids.c:90: for (unsigned char m = 0; m < meteor_max; m++)
	ld	-2 (ix), #0x00
00120$:
	ld	hl, #_meteor_max
	ld	a, -2 (ix)
	sub	a, (hl)
	jp	NC, 00116$
;zorblaxx_asteroids.c:92: unsigned char sprite = meteor_sprite_first + m;
	ld	a,(#_meteor_sprite_first + 0)
	add	a, -2 (ix)
	ld	-1 (ix), a
;zorblaxx_asteroids.c:93: if (m < meteor_active_max)
	ld	hl, #_meteor_active_max
	ld	a, -2 (ix)
	sub	a, (hl)
	jp	NC, 00121$
;zorblaxx_asteroids.c:95: if (meteor_timer[m] > 0)
	ld	a, #<(_meteor_timer)
	add	a, -2 (ix)
	ld	-10 (ix), a
	ld	a, #>(_meteor_timer)
	adc	a, #0x00
	ld	-9 (ix), a
	ld	l, -10 (ix)
	ld	h, -9 (ix)
	ld	a, (hl)
	or	a, a
	jr	Z,00112$
;zorblaxx_asteroids.c:97: meteor_timer[m]--;
	dec	a
	pop	bc
	pop	hl
	push	hl
	push	bc
	ld	(hl), a
;zorblaxx_asteroids.c:98: if (meteor_timer[m] == 0)
	or	a, a
	jp	NZ, 00121$
;zorblaxx_asteroids.c:100: spr_on[sprite] = 1;
	ld	a, #<(_spr_on)
	add	a, -1 (ix)
	ld	l, a
	ld	a, #>(_spr_on)
	adc	a, #0x00
	ld	h, a
	ld	(hl), #0x01
;zorblaxx_asteroids.c:101: spr_index[sprite] = rand_uchar(meteor_sprite_index_first, meteor_sprite_index_first + meteor_sprite_index_count - 1);
	ld	a, #<(_spr_index)
	add	a, -1 (ix)
	ld	c, a
	ld	a, #>(_spr_index)
	adc	a, #0x00
	ld	b, a
	push	bc
	ld	a, #0x05
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
	jp	00121$
00112$:
;zorblaxx_asteroids.c:106: meteor_x[m] += meteor_xs[m];
	ld	l, -2 (ix)
	ld	h, #0x00
	add	hl, hl
	ld	-8 (ix), l
	ld	-7 (ix), h
	ld	a, #<(_meteor_x)
	add	a, -8 (ix)
	ld	-6 (ix), a
	ld	a, #>(_meteor_x)
	adc	a, -7 (ix)
	ld	-5 (ix), a
	ld	l, -6 (ix)
	ld	h, -5 (ix)
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	ld	a, #<(_meteor_xs)
	add	a, -2 (ix)
	ld	-12 (ix), a
	ld	a, #>(_meteor_xs)
	adc	a, #0x00
	ld	-11 (ix), a
	pop	hl
	push	hl
	ld	l, (hl)
	ld	a, l
	rla
	sbc	a, a
	ld	h, a
	add	hl, bc
	ex	de, hl
	ld	l, -6 (ix)
	ld	h, -5 (ix)
	ld	(hl), e
	inc	hl
	ld	(hl), d
;zorblaxx_asteroids.c:107: if (meteor_x[m] < x_h_min)
	ld	l, -6 (ix)
	ld	h, -5 (ix)
	ld	a, (hl)
	ld	-4 (ix), a
	inc	hl
	ld	a, (hl)
	ld	-3 (ix), a
	ld	hl, #_x_h_min
	ld	a, e
	sub	a, (hl)
	ld	a, d
	inc	hl
	sbc	a, (hl)
	jr	NC,00106$
;zorblaxx_asteroids.c:109: meteor_x[m] = x_h_max;
	ld	l, -6 (ix)
	ld	h, -5 (ix)
	ld	iy, #_x_h_max
	ld	a, 0 (iy)
	ld	(hl), a
	inc	hl
	ld	a, 1 (iy)
	ld	(hl), a
	jr	00107$
00106$:
;zorblaxx_asteroids.c:111: else if (meteor_x[m] > x_h_max)
	ld	hl, #_x_h_max
	ld	a, (hl)
	sub	a, -4 (ix)
	inc	hl
	ld	a, (hl)
	sbc	a, -3 (ix)
	jr	NC,00107$
;zorblaxx_asteroids.c:113: meteor_x[m] = x_h_min;
	ld	l, -6 (ix)
	ld	h, -5 (ix)
	ld	iy, #_x_h_min
	ld	a, 0 (iy)
	ld	(hl), a
	inc	hl
	ld	a, 1 (iy)
	ld	(hl), a
00107$:
;zorblaxx_asteroids.c:115: if (meteor_y[m] >= meteor_y_max)
	ld	a, #<(_meteor_y)
	add	a, -8 (ix)
	ld	c, a
	ld	a, #>(_meteor_y)
	adc	a, -7 (ix)
	ld	b, a
	ld	l, c
	ld	h, b
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	ld	hl, #_meteor_y_max
	ld	a, e
	sub	a, (hl)
	ld	a, d
	inc	hl
	sbc	a, (hl)
	jp	C, 00109$
;zorblaxx_asteroids.c:117: meteor_x[m] = rand_ushort(24, 296) * x_divisor;
	push	bc
	ld	hl, #0x0128
	push	hl
	ld	hl, #0x0018
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
	ld	l, -6 (ix)
	ld	h, -5 (ix)
	ld	(hl), e
	inc	hl
	ld	(hl), d
;zorblaxx_asteroids.c:118: meteor_y[m] = 0;
	ld	a, #0x00
	ld	(bc), a
	inc	bc
	ld	a, #0x00
	ld	(bc), a
;zorblaxx_asteroids.c:119: meteor_xs[m] = rand_schar(-(2 + (meteor_difficulty / 4)), 2 + (meteor_difficulty / 4));
	pop	bc
	push	bc
	ld	hl,#_meteor_difficulty + 0
	ld	e, (hl)
	ld	d, #0x00
	ld	l, e
	ld	a,d
	ld	h,a
	rlca
	and	a,#0x01
	ld	-4 (ix), a
	ld	a, e
	add	a, #0x03
	ld	-12 (ix), a
	ld	a, d
	adc	a, #0x00
	ld	-11 (ix), a
	ld	a, -4 (ix)
	or	a, a
	jr	Z,00124$
	pop	hl
	push	hl
00124$:
	sra	h
	rr	l
	sra	h
	rr	l
	ld	h, l
	inc	h
	inc	h
	ld	-8 (ix), e
	ld	-7 (ix), d
	ld	a, -4 (ix)
	or	a, a
	jr	Z,00125$
	ld	a, -12 (ix)
	ld	-8 (ix), a
	ld	a, -11 (ix)
	ld	-7 (ix), a
00125$:
	ld	e, -8 (ix)
	ld	d, -7 (ix)
	sra	d
	rr	e
	sra	d
	rr	e
	inc	e
	inc	e
	xor	a, a
	sub	a, e
	push	bc
	push	hl
	inc	sp
	push	af
	inc	sp
	call	_rand_schar
	pop	af
	ld	a, l
	pop	bc
	ld	(bc), a
;zorblaxx_asteroids.c:120: meteor_ys[m] = rand_uchar(4, 16 + meteor_difficulty);
	ld	a, #<(_meteor_ys)
	add	a, -2 (ix)
	ld	c, a
	ld	a, #>(_meteor_ys)
	adc	a, #0x00
	ld	b, a
	ld	a,(#_meteor_difficulty + 0)
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
;zorblaxx_asteroids.c:121: meteor_timer[m] = get_meteortimer();
	call	_get_meteortimer
	ld	a, l
	pop	bc
	pop	hl
	push	hl
	push	bc
	ld	(hl), a
;zorblaxx_asteroids.c:122: spr_on[sprite] = 0;
	ld	a, #<(_spr_on)
	add	a, -1 (ix)
	ld	c, a
	ld	a, #>(_spr_on)
	adc	a, #0x00
	ld	b, a
	xor	a, a
	ld	(bc), a
	jp	00121$
00109$:
;zorblaxx_asteroids.c:126: meteor_y[m] += meteor_ys[m] + scroll_speed;
	ld	a, #<(_meteor_ys)
	add	a, -2 (ix)
	ld	l, a
	ld	a, #>(_meteor_ys)
	adc	a, #0x00
	ld	h, a
	ld	a, (hl)
	ld	-4 (ix), a
	rla
	sbc	a, a
	ld	-3 (ix), a
	ld	iy, #_scroll_speed
	ld	l, 0 (iy)
	ld	h, #0x00
	ld	a, -4 (ix)
	add	a, l
	ld	l, a
	ld	a, -3 (ix)
	adc	a, h
	ld	h, a
	add	hl, de
	ex	de, hl
	ld	a, e
	ld	(bc), a
	inc	bc
	ld	a, d
	ld	(bc), a
;zorblaxx_asteroids.c:127: spr_x[sprite] = meteor_x[m] / x_divisor;
	ld	l, -1 (ix)
	ld	h, #0x00
	add	hl, hl
	ld	bc,#_spr_x
	add	hl,bc
	ld	-4 (ix), l
	ld	-3 (ix), h
	ld	l, -6 (ix)
	ld	h, -5 (ix)
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	ld	iy, #_x_divisor
	ld	l, 0 (iy)
	ld	h, #0x00
	push	de
	push	hl
	push	bc
	call	__divuint
	pop	af
	pop	af
	ld	c, l
	ld	b, h
	pop	de
	ld	l, -4 (ix)
	ld	h, -3 (ix)
	ld	(hl), c
	inc	hl
	ld	(hl), b
;zorblaxx_asteroids.c:128: unsigned short y = meteor_y[m] / y_divisor;
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
;zorblaxx_asteroids.c:129: spr_y_h[sprite] = y >> 8;
	ld	a, #<(_spr_y_h)
	add	a, -1 (ix)
	ld	l, a
	ld	a, #>(_spr_y_h)
	adc	a, #0x00
	ld	h, a
	ld	e, b
	ld	d, #0x00
	ld	(hl), e
;zorblaxx_asteroids.c:130: spr_y_l[sprite] = (unsigned char)y;
	ld	a, #<(_spr_y_l)
	add	a, -1 (ix)
	ld	l, a
	ld	a, #>(_spr_y_l)
	adc	a, #0x00
	ld	h, a
	ld	(hl), c
00121$:
;zorblaxx_asteroids.c:90: for (unsigned char m = 0; m < meteor_max; m++)
	inc	-2 (ix)
	jp	00120$
00116$:
;zorblaxx_asteroids.c:136: meteor_difficulty_timer++;
	ld	iy, #_meteor_difficulty_timer
	inc	0 (iy)
	jr	NZ,00182$
	inc	1 (iy)
00182$:
;zorblaxx_asteroids.c:137: if (meteor_difficulty_timer > meteor_difficulty_frequency)
	ld	hl, #_meteor_difficulty_frequency
	ld	a, (hl)
	sub	a, 0 (iy)
	inc	hl
	ld	a, (hl)
	sbc	a, 1 (iy)
	jr	NC,00122$
;zorblaxx_asteroids.c:139: update_meteordifficulty();
	call	_update_meteordifficulty
00122$:
;zorblaxx_asteroids.c:141: }
	ld	sp, ix
	pop	ix
	ret
	.area _CODE
	.area _INITIALIZER
__xinit__meteor_max:
	.db #0x10	; 16
__xinit__meteor_sprite_first:
	.db #0x0d	; 13
__xinit__meteor_sprite_palette:
	.db #0x00	; 0
	.area _CABS (ABS)
