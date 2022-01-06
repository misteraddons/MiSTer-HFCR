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
	.globl _spr_size
	.globl _spr_index
	.globl _spr_palette_index
	.globl _spr_collide
	.globl _spr_on
	.globl _spr_y_h
	.globl _spr_y_l
	.globl _spr_x_h
	.globl _spr_x_l
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
	.globl _set_sprite_position
	.globl _set_sprite_position_x
	.globl _update_sprites
	.globl _enable_sprite
	.globl _clear_sprites
	.globl _clear_sprites_range
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
_spr_x_l::
	.ds 32
_spr_x_h::
	.ds 32
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
_spr_size::
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
;sprite.c:39: void set_sprite_position(unsigned char sprite, unsigned short x, unsigned short y)
;	---------------------------------
; Function set_sprite_position
; ---------------------------------
_set_sprite_position::
	push	ix
	ld	ix,#0
	add	ix,sp
;sprite.c:41: spr_x_h[sprite] = x >> 8;
	ld	bc, #_spr_x_h+0
	ld	l, 4 (ix)
	ld	h, #0x00
	add	hl, bc
	ld	c, 6 (ix)
	ld	(hl), c
;sprite.c:42: spr_x_l[sprite] = (unsigned char)x;
	ld	bc, #_spr_x_l+0
	ld	l, 4 (ix)
	ld	h, #0x00
	add	hl, bc
	ld	a, 5 (ix)
	ld	(hl), a
;sprite.c:43: spr_y_h[sprite] = y >> 8;
	ld	bc, #_spr_y_h+0
	ld	l, 4 (ix)
	ld	h, #0x00
	add	hl, bc
	ld	c, 8 (ix)
	ld	(hl), c
;sprite.c:44: spr_y_l[sprite] = (unsigned char)y;
	ld	bc, #_spr_y_l+0
	ld	l, 4 (ix)
	ld	h, #0x00
	add	hl, bc
	ld	a, 7 (ix)
	ld	(hl), a
;sprite.c:45: }
	pop	ix
	ret
;sprite.c:46: void set_sprite_position_x(unsigned char sprite, unsigned short x)
;	---------------------------------
; Function set_sprite_position_x
; ---------------------------------
_set_sprite_position_x::
;sprite.c:48: spr_x_h[sprite] = x >> 8;
	ld	bc, #_spr_x_h+0
	ld	a, c
	ld	hl, #2
	add	hl, sp
	add	a, (hl)
	ld	c, a
	jr	NC,00103$
	inc	b
00103$:
	ld	iy, #3
	add	iy, sp
	ld	a, 1 (iy)
	ld	(bc), a
;sprite.c:49: spr_x_l[sprite] = (unsigned char)x;
	ld	bc, #_spr_x_l+0
	ld	a, c
	ld	hl, #2
	add	hl, sp
	add	a, (hl)
	ld	c, a
	jr	NC,00104$
	inc	b
00104$:
	ld	a, 0 (iy)
	ld	(bc), a
;sprite.c:50: }
	ret
;sprite.c:52: void update_sprites()
;	---------------------------------
; Function update_sprites
; ---------------------------------
_update_sprites::
	push	ix
	ld	ix,#0
	add	ix,sp
	dec	sp
;sprite.c:54: unsigned char s = 0;
	ld	c, #0x00
;sprite.c:55: for (unsigned char sprite = 0; sprite < sprite_max; sprite++)
	ld	e, #0x00
00106$:
	ld	hl, #_sprite_max
	ld	a, e
	sub	a, (hl)
	jp	NC, 00108$
;sprite.c:57: if (spr_on[sprite])
	ld	hl, #_spr_on
	ld	d, #0x00
	add	hl, de
	bit	0, (hl)
	jp	Z, 00102$
;sprite.c:60: spriteram[s++] = spr_highbits[sprite] | spr_y_h[sprite];   // Enabled (1 bit) + Collide (1 bit) + Size (2 bits) + Palette Index (2 bits) + Position Y (upper 2 bits)
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
	ld	-1 (ix), a
	ld	a, #<(_spr_y_h)
	add	a, e
	ld	l, a
	ld	a, #>(_spr_y_h)
	adc	a, #0x00
	ld	h, a
	ld	a, (hl)
	or	a, -1 (ix)
	ld	(bc), a
;sprite.c:61: spriteram[s++] = spr_y_l[sprite];						   // Position Y (lower 8 bits)
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
;sprite.c:62: spriteram[s++] = spr_index[sprite] << 2 | spr_x_h[sprite]; // Sprite Index (6 bits) + Position X (upper 2 bits)
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
	ld	-1 (ix), a
	ld	a, #<(_spr_x_h)
	add	a, e
	ld	l, a
	ld	a, #>(_spr_x_h)
	adc	a, #0x00
	ld	h, a
	ld	l, (hl)
	ld	a, -1 (ix)
	or	a, l
	ld	(bc), a
;sprite.c:63: spriteram[s++] = spr_x_l[sprite];						   // Position X (lower 8 bits)
	ld	a, d
	ld	c, d
	inc	c
	ld	iy, #_spriteram
	push	bc
	ld	c, a
	ld	b, #0x00
	add	iy, bc
	pop	bc
	ld	hl, #_spr_x_l
	ld	d, #0x00
	add	hl, de
	ld	a, (hl)
	ld	0 (iy), a
	jr	00107$
00102$:
;sprite.c:68: spriteram[s] = 0;
	ld	hl, #_spriteram+0
	ld	b, #0x00
	add	hl, bc
	ld	(hl), #0x00
;sprite.c:69: s += 4;
	inc	c
	inc	c
	inc	c
	inc	c
00107$:
;sprite.c:55: for (unsigned char sprite = 0; sprite < sprite_max; sprite++)
	inc	e
	jp	00106$
00108$:
;sprite.c:72: }
	inc	sp
	pop	ix
	ret
;sprite.c:74: void enable_sprite(unsigned char sprite, unsigned char palette_index, unsigned char size, unsigned char collide)
;	---------------------------------
; Function enable_sprite
; ---------------------------------
_enable_sprite::
	push	ix
	ld	ix,#0
	add	ix,sp
;sprite.c:76: spr_on[sprite] = 1;
	ld	bc, #_spr_on+0
	ld	l, 4 (ix)
	ld	h, #0x00
	add	hl, bc
	ld	(hl), #0x01
;sprite.c:77: spr_collide[sprite] = collide;
	ld	bc, #_spr_collide+0
	ld	l, 4 (ix)
	ld	h, #0x00
	add	hl, bc
	xor	a, a
	cp	a, 7 (ix)
	rla
	ld	(hl), a
;sprite.c:78: spr_palette_index[sprite] = palette_index;
	ld	bc, #_spr_palette_index+0
	ld	l, 4 (ix)
	ld	h, #0x00
	add	hl, bc
	ld	a, 5 (ix)
	ld	(hl), a
;sprite.c:79: spr_size[sprite] = size;
	ld	bc, #_spr_size+0
	ld	l, 4 (ix)
	ld	h, #0x00
	add	hl, bc
	ld	a, 6 (ix)
	ld	(hl), a
;sprite.c:80: spr_highbits[sprite] = 1 << 7 | collide << 6 | palette_index << 4 | size << 2;
	ld	bc, #_spr_highbits+0
	ld	l, 4 (ix)
	ld	h, #0x00
	add	hl, bc
	ld	a, 7 (ix)
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
	ld	c, a
	ld	a, 6 (ix)
	add	a, a
	add	a, a
	or	a, c
	ld	(hl), a
;sprite.c:81: }
	pop	ix
	ret
;sprite.c:83: void clear_sprites()
;	---------------------------------
; Function clear_sprites
; ---------------------------------
_clear_sprites::
;sprite.c:85: for (unsigned char sprite = 0; sprite < sprite_max; sprite++)
	ld	bc, #_spr_on+0
	ld	e, #0x00
00103$:
	ld	hl, #_sprite_max
	ld	a, e
	sub	a, (hl)
	ret	NC
;sprite.c:87: spr_on[sprite] = 0;
	ld	l, e
	ld	h, #0x00
	add	hl, bc
	ld	(hl), #0x00
;sprite.c:85: for (unsigned char sprite = 0; sprite < sprite_max; sprite++)
	inc	e
;sprite.c:89: }
	jr	00103$
;sprite.c:90: void clear_sprites_range(unsigned char first, unsigned char last)
;	---------------------------------
; Function clear_sprites_range
; ---------------------------------
_clear_sprites_range::
;sprite.c:92: for (unsigned char sprite = first; sprite <= last; sprite++)
	ld	hl, #2+0
	add	hl, sp
	ld	c, (hl)
	ld	de, #_spr_on+0
00103$:
	ld	hl, #3
	add	hl, sp
	ld	a, (hl)
	sub	a, c
	ret	C
;sprite.c:94: spr_on[sprite] = 0;
	ld	l, c
	ld	h, #0x00
	add	hl, de
	ld	(hl), #0x00
;sprite.c:92: for (unsigned char sprite = first; sprite <= last; sprite++)
	inc	c
;sprite.c:96: }
	jr	00103$
	.area _CODE
	.area _INITIALIZER
__xinit__sprite_max:
	.db #0x20	; 32
	.area _CABS (ABS)
