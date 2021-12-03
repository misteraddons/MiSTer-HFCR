;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.8.0 #10562 (Linux)
;--------------------------------------------------------
	.module sprite
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _sprite_max
	.globl _spr_highbits
	.globl _spr_index
	.globl _spr_palette_index
	.globl _spr_collide
	.globl _spr_on
	.globl _spr_y_h
	.globl _spr_y_l
	.globl _spr_x
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
	.globl _update_sprites
	.globl _enable_sprite
	.globl _clear_sprites
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
_spr_x::
	.ds 64
_spr_y_l::
	.ds 32
_spr_y_h::
	.ds 32
_spr_on::
	.ds 32
_spr_collide::
	.ds 32
_spr_palette_index::
	.ds 32
_spr_index::
	.ds 32
_spr_highbits::
	.ds 32
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
_sprite_max::
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
;sprite.c:37: void update_sprites()
;	---------------------------------
; Function update_sprites
; ---------------------------------
_update_sprites::
	push	ix
	ld	ix,#0
	add	ix,sp
	push	af
	push	af
	dec	sp
;sprite.c:39: unsigned char s = 0;
	ld	c, #0x00
;sprite.c:40: for (unsigned char sprite = 0; sprite < sprite_max; sprite++)
	ld	e, #0x00
00106$:
	ld	hl, #_sprite_max
	ld	a, e
	sub	a, (hl)
	jp	NC, 00108$
;sprite.c:42: if (spr_on[sprite])
	ld	hl, #_spr_on
	ld	d, #0x00
	add	hl, de
	bit	0, (hl)
	jp	Z, 00102$
;sprite.c:44: unsigned short x = spr_x[sprite];
	ld	l, e
	ld	h, #0x00
	add	hl, hl
	push	de
	ld	de, #_spr_x
	add	hl, de
	pop	de
	ld	a, (hl)
	ld	-2 (ix), a
	inc	hl
	ld	a, (hl)
	ld	-1 (ix), a
;sprite.c:46: spriteram[s++] = spr_highbits[sprite] | spr_y_h[sprite];	// Enabled (1 bit) + Collide (1 bit) + Palette Index (2 bits) + Position Y (upper 2 bits)
	ld	a, c
	ld	d, c
	inc	d
	add	a, #<(_spriteram)
	ld	c, a
	ld	a, #0x00
	adc	a, #>(_spriteram)
	ld	b, a
	ld	a, #<(_spr_highbits)
	add	a, e
	ld	l, a
	ld	a, #>(_spr_highbits)
	adc	a, #0x00
	ld	h, a
	ld	a, (hl)
	ld	-5 (ix), a
	ld	a, #<(_spr_y_h)
	add	a, e
	ld	l, a
	ld	a, #>(_spr_y_h)
	adc	a, #0x00
	ld	h, a
	ld	a, (hl)
	or	a, -5 (ix)
	ld	(bc), a
;sprite.c:47: spriteram[s++] = spr_y_l[sprite];							// Position Y (lower 8 bits)
	ld	a, d
	inc	d
	add	a, #<(_spriteram)
	ld	c, a
	ld	a, #0x00
	adc	a, #>(_spriteram)
	ld	b, a
	ld	a, #<(_spr_y_l)
	add	a, e
	ld	l, a
	ld	a, #>(_spr_y_l)
	adc	a, #0x00
	ld	h, a
	ld	a, (hl)
	ld	(bc), a
;sprite.c:48: spriteram[s++] = spr_index[sprite] << 2 | x >> 8;			// Sprite Index (6 bits) + Position X (upper 2 bits)
	ld	a, d
	inc	d
	add	a, #<(_spriteram)
	ld	c, a
	ld	a, #0x00
	adc	a, #>(_spriteram)
	ld	b, a
	ld	a, #<(_spr_index)
	add	a, e
	ld	l, a
	ld	a, #>(_spr_index)
	adc	a, #0x00
	ld	h, a
	ld	a, (hl)
	add	a, a
	add	a, a
	ld	l, a
	ld	a, -1 (ix)
	ld	-4 (ix), a
	ld	-3 (ix), #0x00
	ld	a, l
	rla
	sbc	a, a
	ld	h, a
	ld	a, l
	or	a, -4 (ix)
	ld	l, a
	ld	a, h
	or	a, -3 (ix)
	ld	a, l
	ld	(bc), a
;sprite.c:49: spriteram[s++] = (unsigned char)x;							// Position X (lower 8 bits)
	ld	a, d
	ld	c, d
	inc	c
	add	a, #<(_spriteram)
	ld	l, a
	ld	a, #0x00
	adc	a, #>(_spriteram)
	ld	h, a
	ld	a, -2 (ix)
	ld	(hl), a
	jr	00107$
00102$:
;sprite.c:54: spriteram[s] = 0;
	ld	hl, #_spriteram+0
	ld	b, #0x00
	add	hl, bc
	ld	(hl), #0x00
;sprite.c:55: s += 4;
	inc	c
	inc	c
	inc	c
	inc	c
00107$:
;sprite.c:40: for (unsigned char sprite = 0; sprite < sprite_max; sprite++)
	inc	e
	jp	00106$
00108$:
;sprite.c:58: }
	ld	sp, ix
	pop	ix
	ret
;sprite.c:60: void enable_sprite(unsigned char sprite, unsigned char palette_index, unsigned char collide)
;	---------------------------------
; Function enable_sprite
; ---------------------------------
_enable_sprite::
	push	ix
	ld	ix,#0
	add	ix,sp
;sprite.c:62: spr_on[sprite] = 1;
	ld	bc, #_spr_on+0
	ld	l, 4 (ix)
	ld	h, #0x00
	add	hl, bc
	ld	(hl), #0x01
;sprite.c:63: spr_collide[sprite] = collide;
	ld	bc, #_spr_collide+0
	ld	l, 4 (ix)
	ld	h, #0x00
	add	hl, bc
	xor	a, a
	cp	a, 6 (ix)
	rla
	ld	c, a
	ld	(hl), c
;sprite.c:64: spr_palette_index[sprite] = palette_index;
	ld	de, #_spr_palette_index+0
	ld	l, 4 (ix)
	ld	h, #0x00
	add	hl, de
	ld	a, 5 (ix)
	ld	(hl), a
;sprite.c:65: spr_highbits[sprite] = 1 << 7 | spr_collide[sprite] << 6 | spr_palette_index[sprite] << 4;
	ld	de, #_spr_highbits+0
	ld	l, 4 (ix)
	ld	h, #0x00
	add	hl, de
	ld	a, c
	rrca
	rrca
	and	a, #0xc0
	ld	c, a
	set	7, c
	ld	a, 5 (ix)
	rlca
	rlca
	rlca
	rlca
	and	a, #0xf0
	or	a, c
	ld	(hl), a
;sprite.c:66: }
	pop	ix
	ret
;sprite.c:68: void clear_sprites()
;	---------------------------------
; Function clear_sprites
; ---------------------------------
_clear_sprites::
;sprite.c:70: for (unsigned char sprite = 0; sprite < sprite_max; sprite++)
	ld	bc, #_spr_on+0
	ld	e, #0x00
00103$:
	ld	hl, #_sprite_max
	ld	a, e
	sub	a, (hl)
	ret	NC
;sprite.c:72: spr_on[sprite] = 0;
	ld	l, e
	ld	h, #0x00
	add	hl, bc
	ld	(hl), #0x00
;sprite.c:70: for (unsigned char sprite = 0; sprite < sprite_max; sprite++)
	inc	e
;sprite.c:74: }
	jr	00103$
	.area _CODE
	.area _INITIALIZER
__xinit__sprite_max:
	.db #0x20	; 32
	.area _CABS (ABS)
