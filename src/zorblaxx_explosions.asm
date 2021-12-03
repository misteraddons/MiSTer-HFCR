;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.8.0 #10562 (Linux)
;--------------------------------------------------------
	.module zorblaxx_explosions
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _enable_sprite
	.globl _rand_schar
	.globl _rand_uchar
	.globl _explosion_sprite_palette
	.globl _explosion_sprite_first
	.globl _explosion_max
	.globl _explosion_type
	.globl _explosion_frame
	.globl _explosion_timer
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
	.globl _explosion_lifespan
	.globl _setup_explosions
	.globl _add_explosion
	.globl _handle_explosions
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
_explosion_timer::
	.ds 4
_explosion_frame::
	.ds 4
_explosion_type::
	.ds 4
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
_explosion_max::
	.ds 1
_explosion_sprite_first::
	.ds 1
_explosion_sprite_palette::
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
;zorblaxx_explosions.c:40: void setup_explosions()
;	---------------------------------
; Function setup_explosions
; ---------------------------------
_setup_explosions::
;zorblaxx_explosions.c:42: for (int e = explosion_sprite_first; e < explosion_sprite_first + explosion_max; e++)
	ld	hl,#_explosion_sprite_first + 0
	ld	c, (hl)
	ld	b, #0x00
00103$:
	ld	hl,#_explosion_sprite_first + 0
	ld	e, (hl)
	ld	d, #0x00
	ld	iy, #_explosion_max
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
;zorblaxx_explosions.c:44: enable_sprite(e, explosion_sprite_palette, false);
	ld	d, c
	push	bc
	xor	a, a
	push	af
	inc	sp
	ld	a, (_explosion_sprite_palette)
	push	af
	inc	sp
	push	de
	inc	sp
	call	_enable_sprite
	pop	af
	inc	sp
	pop	bc
;zorblaxx_explosions.c:45: spr_on[e] = false;
	ld	hl, #_spr_on
	add	hl, bc
	ld	(hl), #0x00
;zorblaxx_explosions.c:42: for (int e = explosion_sprite_first; e < explosion_sprite_first + explosion_max; e++)
	inc	bc
;zorblaxx_explosions.c:47: }
	jr	00103$
_explosion_lifespan:
	.db #0x04	; 4
;zorblaxx_explosions.c:49: void add_explosion(unsigned type, unsigned char count)
;	---------------------------------
; Function add_explosion
; ---------------------------------
_add_explosion::
	push	ix
	ld	ix,#0
	add	ix,sp
	push	af
	push	af
;zorblaxx_explosions.c:51: for (unsigned char e = 0; e < explosion_max; e++)
	ld	a, 6 (ix)
	ld	-4 (ix), a
	ld	c, #0x00
00107$:
	ld	hl, #_explosion_max
	ld	a, c
	sub	a, (hl)
	jp	NC, 00109$
;zorblaxx_explosions.c:53: if (explosion_timer[e] == 0)
	ld	hl, #_explosion_timer
	ld	b, #0x00
	add	hl, bc
	ld	a, (hl)
	or	a, a
	jp	NZ, 00108$
;zorblaxx_explosions.c:55: explosion_timer[e] = rand_uchar(2, 7);
	push	hl
	push	bc
	ld	de, #0x0702
	push	de
	call	_rand_uchar
	pop	af
	ld	a, l
	pop	bc
	pop	hl
	ld	(hl), a
;zorblaxx_explosions.c:56: explosion_frame[e] = 0;
	ld	hl, #_explosion_frame
	ld	b, #0x00
	add	hl, bc
	ld	(hl), #0x00
;zorblaxx_explosions.c:57: explosion_type[e] = type;
	ld	hl, #_explosion_type
	ld	b, #0x00
	add	hl, bc
	ld	e, 4 (ix)
	ld	(hl), e
;zorblaxx_explosions.c:58: unsigned char sprite = explosion_sprite_first + e;
	ld	a,(#_explosion_sprite_first + 0)
	add	a, c
	ld	-1 (ix), a
;zorblaxx_explosions.c:59: spr_on[sprite] = true;
	ld	a, #<(_spr_on)
	add	a, -1 (ix)
	ld	l, a
	ld	a, #>(_spr_on)
	adc	a, #0x00
	ld	h, a
	ld	(hl), #0x01
;zorblaxx_explosions.c:60: spr_index[sprite] = explosion_sprite_index_first + (type * explosion_frame_count);
	ld	a, #<(_spr_index)
	add	a, -1 (ix)
	ld	l, a
	ld	a, #>(_spr_index)
	adc	a, #0x00
	ld	h, a
	ld	a, e
	add	a, a
	add	a, a
	add	a, #0x0e
	ld	(hl), a
;zorblaxx_explosions.c:61: spr_x[sprite] = (player_x + (signed short)rand_schar(-32, 64)) / x_divisor;
	ld	l, -1 (ix)
	ld	h, #0x00
	add	hl, hl
	ld	de, #_spr_x
	add	hl, de
	ld	-3 (ix), l
	ld	-2 (ix), h
	push	bc
	ld	de, #0x40e0
	push	de
	call	_rand_schar
	pop	af
	ld	a, l
	pop	bc
	ld	e, a
	rla
	sbc	a, a
	ld	d, a
	ld	iy, #_player_x
	ld	a, 0 (iy)
	add	a, e
	ld	e, a
	ld	a, 1 (iy)
	adc	a, d
	ld	d, a
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
;zorblaxx_explosions.c:62: unsigned short y = (player_y + (signed short)rand_schar(-32, 64)) / y_divisor;
	push	bc
	ld	de, #0x40e0
	push	de
	call	_rand_schar
	pop	af
	ld	a, l
	pop	bc
	ld	e, a
	rla
	sbc	a, a
	ld	d, a
	ld	iy, #_player_y
	ld	a, 0 (iy)
	add	a, e
	ld	e, a
	ld	a, 1 (iy)
	adc	a, d
	ld	d, a
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
;zorblaxx_explosions.c:63: spr_y_h[sprite] = y >> 8;
	ld	a, #<(_spr_y_h)
	add	a, -1 (ix)
	ld	l, a
	ld	a, #>(_spr_y_h)
	adc	a, #0x00
	ld	h, a
	ld	-3 (ix), d
	ld	-2 (ix), #0x00
	ld	a, -3 (ix)
	ld	(hl), a
;zorblaxx_explosions.c:64: spr_y_l[sprite] = (unsigned char)y;
	ld	a, -1 (ix)
	add	a, #<(_spr_y_l)
	ld	l, a
	ld	a, #0x00
	adc	a, #>(_spr_y_l)
	ld	h, a
	ld	(hl), e
;zorblaxx_explosions.c:65: count--;
	dec	-4 (ix)
;zorblaxx_explosions.c:66: if (count == 0)
	ld	a, -4 (ix)
	or	a, a
;zorblaxx_explosions.c:68: return;
	jr	Z,00109$
00108$:
;zorblaxx_explosions.c:51: for (unsigned char e = 0; e < explosion_max; e++)
	inc	c
	jp	00107$
00109$:
;zorblaxx_explosions.c:72: }
	ld	sp, ix
	pop	ix
	ret
;zorblaxx_explosions.c:74: void handle_explosions()
;	---------------------------------
; Function handle_explosions
; ---------------------------------
_handle_explosions::
;zorblaxx_explosions.c:76: for (unsigned char t = 0; t < explosion_max; t++)
	ld	c, #0x00
00110$:
	ld	hl, #_explosion_max
	ld	a, c
	sub	a, (hl)
	ret	NC
;zorblaxx_explosions.c:78: if (explosion_timer[t] > 0)
	ld	a, #<(_explosion_timer)
	add	a, c
	ld	e, a
	ld	a, #>(_explosion_timer)
	adc	a, #0x00
	ld	d, a
	ld	a, (de)
	or	a, a
	jr	Z,00111$
;zorblaxx_explosions.c:80: explosion_timer[t]--;
	dec	a
	ld	(de), a
;zorblaxx_explosions.c:81: if (explosion_timer[t] == 0)
	or	a, a
	jr	NZ,00111$
;zorblaxx_explosions.c:83: unsigned char sprite = explosion_sprite_first + t;
	ld	a,(#_explosion_sprite_first + 0)
	add	a, c
;zorblaxx_explosions.c:84: spr_index[sprite]++;
	ld	b, a
	add	a,#<(_spr_index)
	ld	l, a
	ld	a, #>(_spr_index)
	adc	a, #0x00
	ld	h, a
	inc	(hl)
;zorblaxx_explosions.c:85: explosion_frame[t]++;
	ld	a, #<(_explosion_frame)
	add	a, c
	ld	l, a
	ld	a, #>(_explosion_frame)
	adc	a, #0x00
	ld	h, a
	ld	a, (hl)
	inc	a
	ld	(hl), a
;zorblaxx_explosions.c:86: if (explosion_frame[t] == explosion_frame_count)
	sub	a, #0x04
	jr	NZ,00102$
;zorblaxx_explosions.c:88: spr_on[sprite] = false;
	ld	a, b
	add	a, #<(_spr_on)
	ld	e, a
	ld	a, #0x00
	adc	a, #>(_spr_on)
	ld	d, a
	xor	a, a
	ld	(de), a
	jr	00111$
00102$:
;zorblaxx_explosions.c:92: explosion_timer[t] = explosion_lifespan;
	ld	a,(#_explosion_lifespan + 0)
	ld	(de), a
00111$:
;zorblaxx_explosions.c:76: for (unsigned char t = 0; t < explosion_max; t++)
	inc	c
;zorblaxx_explosions.c:97: }
	jr	00110$
	.area _CODE
	.area _INITIALIZER
__xinit__explosion_max:
	.db #0x04	; 4
__xinit__explosion_sprite_first:
	.db #0x1d	; 29
__xinit__explosion_sprite_palette:
	.db #0x01	; 1
	.area _CABS (ABS)
