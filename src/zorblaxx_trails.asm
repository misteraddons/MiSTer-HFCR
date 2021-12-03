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
	.globl _rand_schar
	.globl _trail_sprite_palette
	.globl _trail_sprite_first
	.globl _trail_max
	.globl _trail_y_offset
	.globl _trail_y_max
	.globl _trail_timer
	.globl _trail_ys
	.globl _trail_xs
	.globl _trail_y
	.globl _trail_x
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
_sndram	=	0x8b00
_musicram	=	0x8b10
_chram	=	0x9800
_fgcolram	=	0xa000
_bgcolram	=	0xa800
_spriteram	=	0xb000
_spritecollisionram	=	0xb400
_trail_x::
	.ds 22
_trail_y::
	.ds 22
_trail_xs::
	.ds 11
_trail_ys::
	.ds 11
_trail_timer::
	.ds 11
_trail_y_max::
	.ds 2
_trail_y_offset::
	.ds 1
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
_trail_max::
	.ds 1
_trail_sprite_first::
	.ds 1
_trail_sprite_palette::
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
;zorblaxx_trails.c:43: trail_y_max = 248 * y_divisor;
	ld	hl,#_y_divisor + 0
	ld	c, (hl)
	ld	e, c
	ld	d, #0x00
	ld	l, e
	ld	h, d
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, hl
	add	hl, hl
	ld	(_trail_y_max), hl
;zorblaxx_trails.c:44: trail_y_offset = (8 * y_divisor);
	ld	a, c
	add	a, a
	add	a, a
	add	a, a
	ld	(#_trail_y_offset + 0),a
;zorblaxx_trails.c:45: for (int t = trail_sprite_first; t < trail_sprite_first + trail_max; t++)
	ld	hl,#_trail_sprite_first + 0
	ld	c, (hl)
	ld	b, #0x00
00103$:
	ld	hl,#_trail_sprite_first + 0
	ld	e, (hl)
	ld	d, #0x00
	ld	iy, #_trail_max
	ld	l, 0 (iy)
	ld	h, #0x00
	add	hl, de
	ld	a, c
	sub	a, l
	ld	a, b
	sbc	a, h
	jp	PO, 00118$
	xor	a, #0x80
00118$:
	ret	P
;zorblaxx_trails.c:47: enable_sprite(t, trail_sprite_palette, false);
	ld	d, c
	push	bc
	xor	a, a
	push	af
	inc	sp
	ld	a, (_trail_sprite_palette)
	push	af
	inc	sp
	push	de
	inc	sp
	call	_enable_sprite
	pop	af
	inc	sp
	pop	bc
;zorblaxx_trails.c:48: spr_on[t] = false;
	ld	hl, #_spr_on
	add	hl, bc
	ld	(hl), #0x00
;zorblaxx_trails.c:45: for (int t = trail_sprite_first; t < trail_sprite_first + trail_max; t++)
	inc	bc
;zorblaxx_trails.c:50: }
	jr	00103$
;zorblaxx_trails.c:52: void add_player_trail()
;	---------------------------------
; Function add_player_trail
; ---------------------------------
_add_player_trail::
	push	ix
	ld	ix,#0
	add	ix,sp
	push	af
;zorblaxx_trails.c:54: for (unsigned char t = 0; t < trail_max; t++)
	ld	c, #0x00
	ld	e, #0x00
00105$:
	ld	hl, #_trail_max
	ld	a, e
	sub	a, (hl)
	jp	NC, 00107$
;zorblaxx_trails.c:56: if (trail_timer[t] == 0)
	ld	hl, #_trail_timer
	ld	d, #0x00
	add	hl, de
	ld	a, (hl)
	or	a, a
	jp	NZ, 00106$
;zorblaxx_trails.c:58: trail_x[t] = player_x;
	ld	l, c
	ld	h, #0x00
	add	hl, hl
	ex	de,hl
	ld	hl, #_trail_x
	add	hl, de
	ld	iy, #_player_x
	ld	a, 0 (iy)
	ld	(hl), a
	inc	hl
	ld	a, 1 (iy)
	ld	(hl), a
;zorblaxx_trails.c:59: trail_y[t] = player_y + (trail_y_offset - player_trail_speed);
	ld	hl, #_trail_y
	add	hl, de
	ex	(sp), hl
	ld	iy, #_trail_y_offset
	ld	l, 0 (iy)
	ld	h, #0x00
	ld	iy, #_player_trail_speed
	ld	e, 0 (iy)
	ld	d, #0x00
	cp	a, a
	sbc	hl, de
	ex	de,hl
	ld	iy, #_player_y
	ld	a, 0 (iy)
	add	a, e
	ld	b, a
	ld	a, 1 (iy)
	adc	a, d
	ld	e, a
	pop	hl
	push	hl
	ld	(hl), b
	inc	hl
	ld	(hl), e
;zorblaxx_trails.c:60: unsigned char spread = 3 + (player_speed / 8);
	ld	hl,#_player_speed + 0
	ld	e, (hl)
	ld	d, #0x00
	ld	l, e
	ld	h, d
	bit	7, d
	jr	Z,00109$
	ld	hl, #0x0007
	add	hl, de
00109$:
	sra	h
	rr	l
	sra	h
	rr	l
	sra	h
	rr	l
	ld	e, l
	inc	e
	inc	e
	inc	e
;zorblaxx_trails.c:61: trail_xs[t] = rand_schar(-spread, spread);
	ld	hl, #_trail_xs
	ld	b, #0x00
	add	hl, bc
	xor	a, a
	sub	a, e
	ld	b, a
	push	hl
	push	bc
	ld	a, e
	push	af
	inc	sp
	push	bc
	inc	sp
	call	_rand_schar
	pop	af
	ld	a, l
	pop	bc
	pop	hl
	ld	(hl), a
;zorblaxx_trails.c:62: trail_ys[t] = player_trail_speed;
	ld	hl, #_trail_ys
	ld	b, #0x00
	add	hl, bc
	ld	a,(#_player_trail_speed + 0)
	ld	(hl), a
;zorblaxx_trails.c:63: trail_timer[t] = player_trail_lifespan;
	ld	hl, #_trail_timer
	ld	b, #0x00
	add	hl, bc
	ld	a,(#_player_trail_lifespan + 0)
	ld	(hl), a
;zorblaxx_trails.c:64: unsigned char sprite = trail_sprite_first + t;
	ld	a,(#_trail_sprite_first + 0)
	add	a, c
	ld	e, a
;zorblaxx_trails.c:65: spr_on[sprite] = true;
	ld	hl, #_spr_on
	ld	d, #0x00
	add	hl, de
	ld	(hl), #0x01
;zorblaxx_trails.c:66: spr_index[sprite] = trail_sprite_index_first;
	ld	hl, #_spr_index+0
	ld	d, #0x00
	add	hl, de
	ld	(hl), #0x0a
;zorblaxx_trails.c:67: return;
	jr	00107$
00106$:
;zorblaxx_trails.c:54: for (unsigned char t = 0; t < trail_max; t++)
	inc	e
	ld	c, e
	jp	00105$
00107$:
;zorblaxx_trails.c:70: }
	ld	sp, ix
	pop	ix
	ret
;zorblaxx_trails.c:72: void handle_trails()
;	---------------------------------
; Function handle_trails
; ---------------------------------
_handle_trails::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	hl, #-9
	add	hl, sp
	ld	sp, hl
;zorblaxx_trails.c:74: for (unsigned char t = 0; t < trail_max; t++)
	ld	c, #0x00
00113$:
	ld	hl, #_trail_max
	ld	a, c
	sub	a, (hl)
	jp	NC, 00114$
;zorblaxx_trails.c:76: if (trail_timer[t] > 0)
	ld	a, #<(_trail_timer)
	add	a, c
	ld	-3 (ix), a
	ld	a, #>(_trail_timer)
	adc	a, #0x00
	ld	-2 (ix), a
	ld	l, -3 (ix)
	ld	h, -2 (ix)
	ld	a, (hl)
	or	a, a
	jp	Z, 00110$
;zorblaxx_trails.c:78: unsigned char sprite = trail_sprite_first + t;
	ld	a,(#_trail_sprite_first + 0)
	add	a, c
	ld	-1 (ix), a
;zorblaxx_trails.c:79: trail_y[t] += trail_ys[t] + player_speed;
	ld	l, c
	ld	h, #0x00
	add	hl, hl
	ex	de,hl
	ld	hl, #_trail_y
	add	hl, de
	ld	-5 (ix), l
	ld	-4 (ix), h
	ld	a, (hl)
	ld	-9 (ix), a
	inc	hl
	ld	a, (hl)
	ld	-8 (ix), a
	ld	hl, #_trail_ys
	ld	b, #0x00
	add	hl, bc
	ld	a, (hl)
	ld	-7 (ix), a
	rla
	sbc	a, a
	ld	-6 (ix), a
	ld	hl,#_player_speed + 0
	ld	b, (hl)
	ld	l, #0x00
	ld	a, -7 (ix)
	add	a, b
	ld	b, a
	ld	a, -6 (ix)
	adc	a, l
	ld	l, a
	ld	a, b
	add	a, -9 (ix)
	ld	-7 (ix), a
	ld	a, l
	adc	a, -8 (ix)
	ld	-6 (ix), a
	ld	l, -5 (ix)
	ld	h, -4 (ix)
	ld	a, -7 (ix)
	ld	(hl), a
	inc	hl
	ld	a, -6 (ix)
	ld	(hl), a
;zorblaxx_trails.c:80: if ((trail_y[t] > trail_y_max) > 0)
	ld	hl, #_trail_y_max
	ld	a, (hl)
	sub	a, -7 (ix)
	inc	hl
	ld	a, (hl)
	sbc	a, -6 (ix)
	jr	NC,00102$
;zorblaxx_trails.c:82: spr_on[sprite] = false;
	ld	a, #<(_spr_on)
	add	a, -1 (ix)
	ld	e, a
	ld	a, #>(_spr_on)
	adc	a, #0x00
	ld	d, a
	xor	a, a
	ld	(de), a
;zorblaxx_trails.c:83: trail_timer[t] = 0;
	ld	l, -3 (ix)
	ld	h, -2 (ix)
	ld	(hl), #0x00
;zorblaxx_trails.c:84: continue;
	jp	00110$
00102$:
;zorblaxx_trails.c:86: trail_timer[t]--;
	ld	l, -3 (ix)
	ld	h, -2 (ix)
	ld	a, (hl)
	dec	a
	ld	l, -3 (ix)
	ld	h, -2 (ix)
	ld	(hl), a
;zorblaxx_trails.c:87: if (trail_timer[t] == 0)
	or	a, a
	jr	NZ,00107$
;zorblaxx_trails.c:89: spr_index[sprite]++;
	ld	a, #<(_spr_index)
	add	a, -1 (ix)
	ld	l, a
	ld	a, #>(_spr_index)
	adc	a, #0x00
	ld	h, a
	ld	b, (hl)
	inc	b
	ld	(hl), b
;zorblaxx_trails.c:90: if (spr_index[sprite] > trail_sprite_index_last)
	ld	a, #0x0d
	sub	a, b
	jr	NC,00104$
;zorblaxx_trails.c:92: spr_on[sprite] = false;
	ld	a, #<(_spr_on)
	add	a, -1 (ix)
	ld	l, a
	ld	a, #>(_spr_on)
	adc	a, #0x00
	ld	h, a
	ld	(hl), #0x00
	jr	00107$
00104$:
;zorblaxx_trails.c:96: trail_timer[t] = player_trail_lifespan;
	ld	a,(#_player_trail_lifespan + 0)
	ld	l, -3 (ix)
	ld	h, -2 (ix)
	ld	(hl), a
00107$:
;zorblaxx_trails.c:99: trail_x[t] += trail_xs[t];
	ld	hl, #_trail_x
	add	hl, de
	ld	-7 (ix), l
	ld	-6 (ix), h
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	ld	hl, #_trail_xs
	ld	b, #0x00
	add	hl, bc
	ld	a, (hl)
	ld	l, a
	rla
	sbc	a, a
	ld	h, a
	add	hl, de
	ex	de, hl
	ld	l, -7 (ix)
	ld	h, -6 (ix)
	ld	(hl), e
	inc	hl
	ld	(hl), d
;zorblaxx_trails.c:100: spr_x[sprite] = trail_x[t] / x_divisor;
	ld	l, -1 (ix)
	ld	h, #0x00
	add	hl, hl
	ld	a, l
	add	a, #<(_spr_x)
	ld	-7 (ix), a
	ld	a, h
	adc	a, #>(_spr_x)
	ld	-6 (ix), a
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
	ld	l, -7 (ix)
	ld	h, -6 (ix)
	ld	(hl), e
	inc	hl
	ld	(hl), d
;zorblaxx_trails.c:102: unsigned short y = trail_y[t] / y_divisor;
	ld	l, -5 (ix)
	ld	h, -4 (ix)
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	ld	iy, #_y_divisor
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
;zorblaxx_trails.c:103: spr_y_h[sprite] = y >> 8;
	ld	a, #<(_spr_y_h)
	add	a, -1 (ix)
	ld	l, a
	ld	a, #>(_spr_y_h)
	adc	a, #0x00
	ld	h, a
	ld	-7 (ix), d
	ld	-6 (ix), #0x00
	ld	a, -7 (ix)
	ld	(hl), a
;zorblaxx_trails.c:104: spr_y_l[sprite] = (unsigned char)y;
	ld	a, -1 (ix)
	add	a, #<(_spr_y_l)
	ld	l, a
	ld	a, #0x00
	adc	a, #>(_spr_y_l)
	ld	h, a
	ld	(hl), e
00110$:
;zorblaxx_trails.c:74: for (unsigned char t = 0; t < trail_max; t++)
	inc	c
	jp	00113$
00114$:
;zorblaxx_trails.c:107: }
	ld	sp, ix
	pop	ix
	ret
	.area _CODE
	.area _INITIALIZER
__xinit__trail_max:
	.db #0x0b	; 11
__xinit__trail_sprite_first:
	.db #0x00	; 0
__xinit__trail_sprite_palette:
	.db #0x01	; 1
	.area _CABS (ABS)
