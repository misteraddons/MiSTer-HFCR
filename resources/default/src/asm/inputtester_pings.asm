;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.8.0 #10562 (Linux)
;--------------------------------------------------------
	.module inputtester_pings
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _enable_sprite
	.globl _set_sprite_position
	.globl _ping_sprite_first
	.globl _ping_max
	.globl _ping_type
	.globl _ping_frame
	.globl _ping_timer
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
	.globl _ping_lifespan
	.globl _setup_pings
	.globl _add_ping
	.globl _handle_pings
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
_ping_timer::
	.ds 8
_ping_frame::
	.ds 8
_ping_type::
	.ds 8
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
_ping_max::
	.ds 1
_ping_sprite_first::
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
;inputtester_pings.c:37: void setup_pings()
;	---------------------------------
; Function setup_pings
; ---------------------------------
_setup_pings::
;inputtester_pings.c:39: for (int e = ping_sprite_first; e < ping_sprite_first + ping_max; e++)
	ld	hl,#_ping_sprite_first + 0
	ld	c, (hl)
	ld	b, #0x00
00103$:
	ld	hl,#_ping_sprite_first + 0
	ld	e, (hl)
	ld	d, #0x00
	ld	iy, #_ping_max
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
;inputtester_pings.c:41: enable_sprite(e, sprite_palette_pings, sprite_size_pings, false);
	ld	d, c
	push	bc
	xor	a, a
	ld	b,a
	ld	c,#0x01
	push	bc
	ld	a, #0x02
	push	af
	inc	sp
	push	de
	inc	sp
	call	_enable_sprite
	pop	af
	pop	af
	pop	bc
;inputtester_pings.c:42: spr_on[e] = false;
	ld	hl, #_spr_on
	add	hl, bc
	ld	(hl), #0x00
;inputtester_pings.c:39: for (int e = ping_sprite_first; e < ping_sprite_first + ping_max; e++)
	inc	bc
;inputtester_pings.c:44: }
	jr	00103$
_ping_lifespan:
	.db #0x02	; 2
;inputtester_pings.c:46: void add_ping(unsigned type, unsigned short x, unsigned short y)
;	---------------------------------
; Function add_ping
; ---------------------------------
_add_ping::
	push	ix
	ld	ix,#0
	add	ix,sp
;inputtester_pings.c:48: for (unsigned char e = 0; e < ping_max; e++)
	ld	c, #0x00
	ld	e, #0x00
00105$:
	ld	hl, #_ping_max
	ld	a, e
	sub	a, (hl)
	jr	NC,00107$
;inputtester_pings.c:50: if (ping_timer[e] == 0)
	ld	hl, #_ping_timer+0
	ld	d, #0x00
	add	hl, de
	ld	a, (hl)
	or	a, a
	jr	NZ,00106$
;inputtester_pings.c:52: ping_timer[e] = ping_lifespan;
	ld	a,(#_ping_lifespan + 0)
	ld	(hl), a
;inputtester_pings.c:53: ping_frame[e] = 0;
	ld	hl, #_ping_frame
	ld	b, #0x00
	add	hl, bc
	ld	(hl), #0x00
;inputtester_pings.c:56: unsigned char sprite = ping_sprite_first + e;
	ld	a,(#_ping_sprite_first + 0)
	add	a, c
	ld	b, a
;inputtester_pings.c:57: enable_sprite(sprite, sprite_palette_pings, sprite_size_pings, 0);
	push	bc
	xor	a, a
	ld	d,a
	ld	e,#0x01
	push	de
	ld	a, #0x02
	push	af
	inc	sp
	push	bc
	inc	sp
	call	_enable_sprite
	pop	af
	pop	af
	pop	bc
;inputtester_pings.c:58: spr_index[sprite] = sprite_index_pings_first + (type * ping_frame_count);
	ld	de, #_spr_index+0
	ld	l, b
	ld	h, #0x00
	add	hl, de
	ld	(hl), #0x18
;inputtester_pings.c:59: set_sprite_position(sprite, x, y);
	ld	l, 8 (ix)
	ld	h, 9 (ix)
	push	hl
	ld	l, 6 (ix)
	ld	h, 7 (ix)
	push	hl
	push	bc
	inc	sp
	call	_set_sprite_position
	pop	af
	pop	af
	inc	sp
;inputtester_pings.c:60: return;
	jr	00107$
00106$:
;inputtester_pings.c:48: for (unsigned char e = 0; e < ping_max; e++)
	inc	e
	ld	c, e
	jr	00105$
00107$:
;inputtester_pings.c:63: }
	pop	ix
	ret
;inputtester_pings.c:65: void handle_pings()
;	---------------------------------
; Function handle_pings
; ---------------------------------
_handle_pings::
;inputtester_pings.c:67: for (unsigned char t = 0; t < ping_max; t++)
	ld	c, #0x00
00110$:
	ld	hl, #_ping_max
	ld	a, c
	sub	a, (hl)
	ret	NC
;inputtester_pings.c:69: if (ping_timer[t] > 0)
	ld	a, #<(_ping_timer)
	add	a, c
	ld	e, a
	ld	a, #>(_ping_timer)
	adc	a, #0x00
	ld	d, a
	ld	a, (de)
	or	a, a
	jr	Z,00111$
;inputtester_pings.c:71: ping_timer[t]--;
	dec	a
	ld	(de), a
;inputtester_pings.c:72: if (ping_timer[t] == 0)
	or	a, a
	jr	NZ,00111$
;inputtester_pings.c:74: unsigned char sprite = ping_sprite_first + t;
	ld	a,(#_ping_sprite_first + 0)
	add	a, c
;inputtester_pings.c:75: spr_index[sprite]++;
	ld	b, a
	add	a,#<(_spr_index)
	ld	l, a
	ld	a, #>(_spr_index)
	adc	a, #0x00
	ld	h, a
	inc	(hl)
;inputtester_pings.c:76: ping_frame[t]++;
	ld	a, #<(_ping_frame)
	add	a, c
	ld	l, a
	ld	a, #>(_ping_frame)
	adc	a, #0x00
	ld	h, a
	ld	a, (hl)
	inc	a
	ld	(hl), a
;inputtester_pings.c:77: if (ping_frame[t] == ping_frame_count)
	sub	a, #0x07
	jr	NZ,00102$
;inputtester_pings.c:79: spr_on[sprite] = false;
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
;inputtester_pings.c:83: ping_timer[t] = ping_lifespan;
	ld	a,(#_ping_lifespan + 0)
	ld	(de), a
00111$:
;inputtester_pings.c:67: for (unsigned char t = 0; t < ping_max; t++)
	inc	c
;inputtester_pings.c:88: }
	jr	00110$
	.area _CODE
	.area _INITIALIZER
__xinit__ping_max:
	.db #0x08	; 8
__xinit__ping_sprite_first:
	.db #0x00	; 0
	.area _CABS (ABS)
