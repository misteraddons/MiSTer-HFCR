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
	.globl _set_sprite_position
	.globl _rand_schar
	.globl _rand_uchar
	.globl _explosion_max
	.globl _explosion_type
	.globl _explosion_frame
	.globl _explosion_timer
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
_explosion_timer::
	.ds 3
_explosion_frame::
	.ds 3
_explosion_type::
	.ds 3
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
_explosion_max::
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
;zorblaxx_explosions.c:39: void setup_explosions()
;	---------------------------------
; Function setup_explosions
; ---------------------------------
_setup_explosions::
;zorblaxx_explosions.c:41: for (int e = explosion_sprite_first; e < explosion_sprite_first + explosion_max; e++)
	ld	bc, #0x001d
00103$:
	ld	hl,#_explosion_max + 0
	ld	e, (hl)
	ld	d, #0x00
	ld	hl, #0x001d
	add	hl, de
	ld	a, c
	sub	a, l
	ld	a, b
	sbc	a, h
	jp	PO, 00118$
	xor	a, #0x80
00118$:
	ret	P
;zorblaxx_explosions.c:43: enable_sprite(e, sprite_palette_explosions, sprite_size_explosions, 0);
	ld	d, c
	push	bc
	xor	a, a
	ld	b,a
	ld	c,#0x01
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
;zorblaxx_explosions.c:44: spr_on[e] = false;
	ld	hl, #_spr_on
	add	hl, bc
	ld	(hl), #0x00
;zorblaxx_explosions.c:41: for (int e = explosion_sprite_first; e < explosion_sprite_first + explosion_max; e++)
	inc	bc
;zorblaxx_explosions.c:46: }
	jr	00103$
_explosion_lifespan:
	.db #0x04	; 4
;zorblaxx_explosions.c:48: void add_explosion(unsigned type, unsigned char count)
;	---------------------------------
; Function add_explosion
; ---------------------------------
_add_explosion::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	hl, #-9
	add	hl, sp
	ld	sp, hl
;zorblaxx_explosions.c:50: for (unsigned char e = 0; e < explosion_max; e++)
	ld	a, 6 (ix)
	ld	-7 (ix), a
	ld	-1 (ix), #0x00
00107$:
	ld	hl, #_explosion_max
	ld	a, -1 (ix)
	sub	a, (hl)
	jp	NC, 00109$
;zorblaxx_explosions.c:52: if (explosion_timer[e] == 0)
	ld	a, #<(_explosion_timer)
	add	a, -1 (ix)
	ld	c, a
	ld	a, #>(_explosion_timer)
	adc	a, #0x00
	ld	b, a
	ld	a, (bc)
	or	a, a
	jp	NZ, 00108$
;zorblaxx_explosions.c:54: explosion_timer[e] = rand_uchar(2, 7);
	push	bc
	ld	de, #0x0702
	push	de
	call	_rand_uchar
	pop	af
	ld	a, l
	pop	bc
	ld	(bc), a
;zorblaxx_explosions.c:55: explosion_frame[e] = 0;
	ld	a, #<(_explosion_frame)
	add	a, -1 (ix)
	ld	c, a
	ld	a, #>(_explosion_frame)
	adc	a, #0x00
	ld	b, a
	xor	a, a
	ld	(bc), a
;zorblaxx_explosions.c:56: explosion_type[e] = type;
	ld	a, #<(_explosion_type)
	add	a, -1 (ix)
	ld	l, a
	ld	a, #>(_explosion_type)
	adc	a, #0x00
	ld	h, a
	ld	c, 4 (ix)
	ld	(hl), c
;zorblaxx_explosions.c:57: unsigned char sprite = explosion_sprite_first + e;
	ld	a, -1 (ix)
	add	a, #0x1d
	ld	-2 (ix), a
;zorblaxx_explosions.c:58: spr_on[sprite] = 1;
	ld	a, #<(_spr_on)
	add	a, -2 (ix)
	ld	l, a
	ld	a, #>(_spr_on)
	adc	a, #0x00
	ld	h, a
	ld	(hl), #0x01
;zorblaxx_explosions.c:59: spr_index[sprite] = sprite_index_explosions_first + (type * explosion_frame_count);
	ld	a, #<(_spr_index)
	add	a, -2 (ix)
	ld	e, a
	ld	a, #>(_spr_index)
	adc	a, #0x00
	ld	d, a
	ld	a, c
	add	a, a
	add	a, a
	add	a, #0x08
	ld	(de), a
;zorblaxx_explosions.c:60: set_sprite_position(sprite, (player_x / x_divisor) + rand_schar(-4, 8), (player_y / y_divisor) + rand_schar(-4, 8));
	ld	hl,#_y_divisor + 0
	ld	c, (hl)
	ld	b, #0x00
	push	bc
	ld	hl, (_player_y)
	push	hl
	call	__divuint
	pop	af
	ex	(sp),hl
	ld	de, #0x08fc
	push	de
	call	_rand_schar
	pop	af
	ld	a, l
	pop	hl
	ld	c, a
	rla
	sbc	a, a
	ld	b, a
	add	hl, bc
	ld	-6 (ix), l
	ld	-5 (ix), h
	ld	hl,#_x_divisor + 0
	ld	c, (hl)
	ld	b, #0x00
	push	bc
	ld	hl, (_player_x)
	push	hl
	call	__divuint
	pop	af
	pop	af
	ld	-8 (ix), h
	ld	-9 (ix), l
	ld	de, #0x08fc
	push	de
	call	_rand_schar
	pop	af
	ld	a, l
	ld	-4 (ix), a
	rla
	sbc	a, a
	ld	-3 (ix), a
	ld	a, -4 (ix)
	add	a, -9 (ix)
	ld	-4 (ix), a
	ld	a, -3 (ix)
	adc	a, -8 (ix)
	ld	-3 (ix), a
	ld	l, -6 (ix)
	ld	h, -5 (ix)
	push	hl
	ld	l, -4 (ix)
	ld	h, -3 (ix)
	push	hl
	ld	a, -2 (ix)
	push	af
	inc	sp
	call	_set_sprite_position
	pop	af
	pop	af
	inc	sp
;zorblaxx_explosions.c:61: count--;
	dec	-7 (ix)
;zorblaxx_explosions.c:62: if (count == 0)
	ld	a, -7 (ix)
	or	a, a
;zorblaxx_explosions.c:64: return;
	jr	Z,00109$
00108$:
;zorblaxx_explosions.c:50: for (unsigned char e = 0; e < explosion_max; e++)
	inc	-1 (ix)
	jp	00107$
00109$:
;zorblaxx_explosions.c:68: }
	ld	sp, ix
	pop	ix
	ret
;zorblaxx_explosions.c:70: void handle_explosions()
;	---------------------------------
; Function handle_explosions
; ---------------------------------
_handle_explosions::
;zorblaxx_explosions.c:72: for (unsigned char t = 0; t < explosion_max; t++)
	ld	c, #0x00
00110$:
	ld	hl, #_explosion_max
	ld	a, c
	sub	a, (hl)
	ret	NC
;zorblaxx_explosions.c:74: if (explosion_timer[t] > 0)
	ld	a, #<(_explosion_timer)
	add	a, c
	ld	e, a
	ld	a, #>(_explosion_timer)
	adc	a, #0x00
	ld	d, a
	ld	a, (de)
	or	a, a
	jr	Z,00111$
;zorblaxx_explosions.c:76: explosion_timer[t]--;
	dec	a
	ld	(de), a
;zorblaxx_explosions.c:77: if (explosion_timer[t] == 0)
	or	a, a
	jr	NZ,00111$
;zorblaxx_explosions.c:79: unsigned char sprite = explosion_sprite_first + t;
	ld	a, c
	add	a, #0x1d
;zorblaxx_explosions.c:80: spr_index[sprite]++;
	ld	b, a
	add	a,#<(_spr_index)
	ld	l, a
	ld	a, #>(_spr_index)
	adc	a, #0x00
	ld	h, a
	inc	(hl)
;zorblaxx_explosions.c:81: explosion_frame[t]++;
	ld	a, #<(_explosion_frame)
	add	a, c
	ld	l, a
	ld	a, #>(_explosion_frame)
	adc	a, #0x00
	ld	h, a
	ld	a, (hl)
	inc	a
	ld	(hl), a
;zorblaxx_explosions.c:82: if (explosion_frame[t] == explosion_frame_count)
	sub	a, #0x04
	jr	NZ,00102$
;zorblaxx_explosions.c:84: spr_on[sprite] = false;
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
;zorblaxx_explosions.c:88: explosion_timer[t] = explosion_lifespan;
	ld	a,(#_explosion_lifespan + 0)
	ld	(de), a
00111$:
;zorblaxx_explosions.c:72: for (unsigned char t = 0; t < explosion_max; t++)
	inc	c
;zorblaxx_explosions.c:93: }
	jr	00110$
	.area _CODE
	.area _INITIALIZER
__xinit__explosion_max:
	.db #0x03	; 3
	.area _CABS (ABS)
