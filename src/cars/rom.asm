;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 4.0.0 #11528 (Linux)
;--------------------------------------------------------
	.module os
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _update_section
	.globl _basic_input
	.globl _scroll_tilemap_down
	.globl _scroll_tilemap_up
	.globl _scroll_tilemap_right
	.globl _scroll_tilemap_left
	.globl _update_tilemap_offset
	.globl _y_off
	.globl _x_off
	.globl _input_a_last
	.globl _input_down_last
	.globl _input_down
	.globl _input_up_last
	.globl _input_up
	.globl _input_right_last
	.globl _input_right
	.globl _input_left_last
	.globl _input_left
	.globl _input_a
	.globl _musicram
	.globl _sndram
	.globl _tilemapram
	.globl _tilemapctl
	.globl _spritecollisionram
	.globl _spriteram
	.globl _bgcolram
	.globl _fgcolram
	.globl _chram
	.globl _system_menu
	.globl _system_pause
	.globl _starfield3
	.globl _starfield2
	.globl _starfield1
	.globl _timer
	.globl _timestamp
	.globl _ps2_mouse
	.globl _ps2_key
	.globl _spinner
	.globl _paddle
	.globl _analog_r
	.globl _analog_l
	.globl _joystick
	.globl _video_ctl
	.globl _input0
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
_input0	=	0x8000
_video_ctl	=	0x8001
_joystick	=	0x8100
_analog_l	=	0x8200
_analog_r	=	0x8300
_paddle	=	0x8400
_spinner	=	0x8500
_ps2_key	=	0x8600
_ps2_mouse	=	0x8700
_timestamp	=	0x8800
_timer	=	0x8900
_starfield1	=	0x8a00
_starfield2	=	0x8a10
_starfield3	=	0x8a20
_system_pause	=	0x8a30
_system_menu	=	0x8a31
_chram	=	0x9800
_fgcolram	=	0xa000
_bgcolram	=	0xa800
_spriteram	=	0xb000
_spritecollisionram	=	0xb400
_tilemapctl	=	0x8c00
_tilemapram	=	0x8c10
_sndram	=	0x8b00
_musicram	=	0x8b10
_input_a::
	.ds 1
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
_input_left::
	.ds 1
_input_left_last::
	.ds 1
_input_right::
	.ds 1
_input_right_last::
	.ds 1
_input_up::
	.ds 1
_input_up_last::
	.ds 1
_input_down::
	.ds 1
_input_down_last::
	.ds 1
_input_a_last::
	.ds 1
_x_off::
	.ds 1
_y_off::
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
;os.c:41: void basic_input()
;	---------------------------------
; Function basic_input
; ---------------------------------
_basic_input::
;os.c:43: input_up_last = input_up;
	ld	a,(#_input_up + 0)
	ld	iy, #_input_up_last
	ld	0 (iy), a
;os.c:44: input_down_last = input_down;
	ld	a,(#_input_down + 0)
	ld	iy, #_input_down_last
	ld	0 (iy), a
;os.c:45: input_left_last = input_left;
	ld	a,(#_input_left + 0)
	ld	iy, #_input_left_last
	ld	0 (iy), a
;os.c:46: input_right_last = input_right;
	ld	a,(#_input_right + 0)
	ld	iy, #_input_right_last
	ld	0 (iy), a
;os.c:47: input_a_last = input_a;
	ld	a,(#_input_a + 0)
	ld	iy, #_input_a_last
	ld	0 (iy), a
;os.c:48: input_up = CHECK_BIT(joystick[0], 3);
	ld	a, (#_joystick + 0)
	and	a, #0x08
	ld	c, a
	xor	a, a
	cp	a, c
	rla
	ld	(_input_up+0), a
;os.c:49: input_down = CHECK_BIT(joystick[0], 2);
	ld	a, (#_joystick + 0)
	and	a, #0x04
	ld	c, a
	xor	a, a
	cp	a, c
	rla
	ld	(_input_down+0), a
;os.c:50: input_left = CHECK_BIT(joystick[0], 1);
	ld	a, (#_joystick + 0)
	and	a, #0x02
	ld	c, a
	xor	a, a
	cp	a, c
	rla
	ld	(_input_left+0), a
;os.c:51: input_right = CHECK_BIT(joystick[0], 0);
	ld	a, (#_joystick + 0)
	and	a, #0x01
	ld	(_input_right+0), a
;os.c:52: input_a = CHECK_BIT(joystick[0], 4);
	ld	a, (#_joystick + 0)
	and	a, #0x10
	ld	c, a
	xor	a, a
	cp	a, c
	rla
	ld	(_input_a+0), a
;os.c:53: }
	ret
;os.c:55: void update_section(unsigned char lx, unsigned char rx, unsigned char ty, unsigned char by)
;	---------------------------------
; Function update_section
; ---------------------------------
_update_section::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	hl, #-7
	add	hl, sp
	ld	sp, hl
;os.c:57: for (unsigned char y = ty; y <= by; y++)
	ld	c, 6 (ix)
00107$:
	ld	a, 7 (ix)
	sub	a, c
	jr	C,00109$
;os.c:59: unsigned short p = (y * 32) + lx;
	ld	l, c
	ld	h, #0x00
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	ld	e, 4 (ix)
	ld	d, #0x00
	add	hl, de
	ld	-3 (ix), l
	ld	-2 (ix), h
;os.c:60: unsigned char yi = (y + y_off - 1);
	ld	hl, #_y_off
	ld	a, c
	add	a, (hl)
	ld	e, a
	dec	e
;os.c:61: for (unsigned char x = lx; x <= rx; x++)
	ld	a, 4 (ix)
	ld	-1 (ix), a
	ld	d, #0x00
	ld	l, e
	ld	h, d
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, hl
	add	hl, hl
	ld	de, #_tilemap_index
	add	hl, de
	ex	(sp), hl
00104$:
	ld	a, 5 (ix)
	sub	a, -1 (ix)
	jr	C,00108$
;os.c:63: tilemapram[p] = tilemap_index[yi][x + x_off - 1];
	ld	a, #<(_tilemapram)
	add	a, -3 (ix)
	ld	-5 (ix), a
	ld	a, #>(_tilemapram)
	adc	a, -2 (ix)
	ld	-4 (ix), a
	ld	e, -1 (ix)
	ld	d, #0x00
	ld	iy, #_x_off
	ld	l, 0 (iy)
	ld	h, #0x00
	add	hl, de
	dec	hl
	add	hl, hl
	add	hl, hl
	pop	de
	push	de
	add	hl, de
	ld	a, (hl)
	pop	de
	pop	hl
	push	hl
	push	de
	ld	(hl), a
;os.c:64: p++;
	inc	-3 (ix)
	jr	NZ,00133$
	inc	-2 (ix)
00133$:
;os.c:61: for (unsigned char x = lx; x <= rx; x++)
	inc	-1 (ix)
	jr	00104$
00108$:
;os.c:57: for (unsigned char y = ty; y <= by; y++)
	inc	c
	jp	00107$
00109$:
;os.c:67: }
	ld	sp, ix
	pop	ix
	ret
;os.c:70: void main()
;	---------------------------------
; Function main
; ---------------------------------
_main::
;os.c:73: chram_size = chram_cols * chram_rows;
	ld	hl,#_chram_rows + 0
	ld	e, (hl)
	ld	hl,#_chram_cols + 0
	ld	h, (hl)
	ld	l, #0x00
	ld	d, l
	ld	b, #0x08
00220$:
	add	hl, hl
	jr	NC,00221$
	add	hl, de
00221$:
	djnz	00220$
	ld	(_chram_size), hl
;os.c:74: update_section(0, 22, 0, 16);
	ld	a, #0x10
	push	af
	inc	sp
	xor	a, a
	ld	d,a
	ld	e,#0x16
	push	de
	xor	a, a
	push	af
	inc	sp
	call	_update_section
	pop	af
;os.c:75: tilemap_offset_x = 0;
;os.c:76: tilemap_offset_y = 0;
	ld	a,#0x00
	ld	(#_tilemap_offset_x + 0),a
	pop	af
	ld	iy,#_tilemap_offset_y
	ld	0 (iy), #0x00
;os.c:82: while (1)
00131$:
;os.c:84: vblank = CHECK_BIT(input0, INPUT_VBLANK);
	ld	a,(#_input0 + 0)
	and	a, #0x10
	ld	c, a
	xor	a, a
	cp	a, c
	rla
	ld	(_vblank+0), a
;os.c:86: if (VBLANK_RISING)
	ld	iy, #_vblank
	bit	0, 0 (iy)
	jp	Z, 00113$
	ld	iy, #_vblank_last
	bit	0, 0 (iy)
	jp	NZ, 00113$
;os.c:89: if (tilemap_offset_x >= 16)
	ld	a,(#_tilemap_offset_x + 0)
	xor	a, #0x80
	sub	a, #0x90
	jr	C,00110$
;os.c:91: tilemap_offset_x -= 16;
	ld	hl, #_tilemap_offset_x
	ld	a, (hl)
	add	a, #0xf0
	ld	(hl), a
;os.c:92: scroll_tilemap_left();
	call	_scroll_tilemap_left
;os.c:93: x_off++;
	ld	hl, #_x_off+0
	inc	(hl)
;os.c:94: update_section(21, 21, 0, 16);
	ld	a, #0x10
	push	af
	inc	sp
	xor	a, a
	ld	d,a
	ld	e,#0x15
	push	de
	ld	a, #0x15
	push	af
	inc	sp
	call	_update_section
	pop	af
	pop	af
	jp	00111$
00110$:
;os.c:96: else if (tilemap_offset_x <= -16)
	ld	a, #0xf0
	ld	iy, #_tilemap_offset_x
	sub	a, 0 (iy)
	jp	PO, 00222$
	xor	a, #0x80
00222$:
	jp	M, 00107$
;os.c:98: tilemap_offset_x += 16;
	ld	hl, #_tilemap_offset_x
	ld	a, (hl)
	add	a, #0x10
	ld	(hl), a
;os.c:99: scroll_tilemap_right();
	call	_scroll_tilemap_right
;os.c:100: x_off--;
	ld	hl, #_x_off+0
	dec	(hl)
;os.c:101: update_section(0, 0, 0, 16);
	ld	a, #0x10
	push	af
	inc	sp
	xor	a, a
	push	af
	inc	sp
	xor	a, a
	push	af
	inc	sp
	xor	a, a
	push	af
	inc	sp
	call	_update_section
	pop	af
	pop	af
	jr	00111$
00107$:
;os.c:103: else if (tilemap_offset_y >= 16)
	ld	a,(#_tilemap_offset_y + 0)
	xor	a, #0x80
	sub	a, #0x90
	jr	C,00104$
;os.c:105: tilemap_offset_y -= 16;
	ld	hl, #_tilemap_offset_y
	ld	a, (hl)
	add	a, #0xf0
	ld	(hl), a
;os.c:106: scroll_tilemap_up();
	call	_scroll_tilemap_up
;os.c:107: y_off++;
	ld	hl, #_y_off+0
	inc	(hl)
;os.c:108: update_section(0, 21, 16, 16);
	ld	de, #0x1010
	push	de
	ld	a, #0x15
	push	af
	inc	sp
	xor	a, a
	push	af
	inc	sp
	call	_update_section
	pop	af
	pop	af
	jr	00111$
00104$:
;os.c:110: else if (tilemap_offset_y <= -16)
	ld	a, #0xf0
	ld	iy, #_tilemap_offset_y
	sub	a, 0 (iy)
	jp	PO, 00223$
	xor	a, #0x80
00223$:
	jp	M, 00111$
;os.c:112: tilemap_offset_y += 16;
	ld	hl, #_tilemap_offset_y
	ld	a, (hl)
	add	a, #0x10
	ld	(hl), a
;os.c:113: scroll_tilemap_down();
	call	_scroll_tilemap_down
;os.c:114: y_off--;
	ld	hl, #_y_off+0
	dec	(hl)
;os.c:115: update_section(0, 21, 0, 0);
	xor	a, a
	push	af
	inc	sp
	xor	a, a
	ld	d,a
	ld	e,#0x15
	push	de
	xor	a, a
	push	af
	inc	sp
	call	_update_section
	pop	af
	pop	af
00111$:
;os.c:118: update_tilemap_offset();
	call	_update_tilemap_offset
00113$:
;os.c:121: if (VBLANK_FALLING)
	ld	iy, #_vblank
	bit	0, 0 (iy)
	jp	NZ, 00128$
	ld	iy, #_vblank_last
	bit	0, 0 (iy)
	jr	Z,00128$
;os.c:123: basic_input();
	call	_basic_input
;os.c:124: if (input_right && x_off < x_off_max)
	ld	iy, #_input_right
	bit	0, 0 (iy)
	jr	Z,00116$
	ld	a,(#_x_off + 0)
	sub	a, #0x12
	jr	NC,00116$
;os.c:125: tilemap_offset_x += scroll_speed;
	ld	iy, #_tilemap_offset_x
	inc	0 (iy)
	inc	0 (iy)
	inc	0 (iy)
	inc	0 (iy)
00116$:
;os.c:126: if (input_left && x_off > 0)
	ld	iy, #_input_left
	bit	0, 0 (iy)
	jr	Z,00119$
	ld	a,(#_x_off + 0)
	or	a, a
	jr	Z,00119$
;os.c:127: tilemap_offset_x -= scroll_speed;
	ld	hl, #_tilemap_offset_x
	ld	a, (hl)
	add	a, #0xfc
	ld	(hl), a
00119$:
;os.c:128: if (input_up && y_off > 0)
	ld	iy, #_input_up
	bit	0, 0 (iy)
	jr	Z,00122$
	ld	a,(#_y_off + 0)
	or	a, a
	jr	Z,00122$
;os.c:129: tilemap_offset_y -= scroll_speed;
	ld	hl, #_tilemap_offset_y
	ld	a, (hl)
	add	a, #0xfc
	ld	(hl), a
00122$:
;os.c:130: if (input_down && y_off < y_off_max)
	ld	iy, #_input_down
	bit	0, 0 (iy)
	jr	Z,00128$
	ld	a,(#_y_off + 0)
	sub	a, #0x08
	jr	NC,00128$
;os.c:131: tilemap_offset_y += scroll_speed;
	ld	iy, #_tilemap_offset_y
	inc	0 (iy)
	inc	0 (iy)
	inc	0 (iy)
	inc	0 (iy)
00128$:
;os.c:133: vblank_last = vblank;
	ld	a,(#_vblank + 0)
	ld	iy, #_vblank_last
	ld	0 (iy), a
;os.c:135: }
	jp	00131$
	.area _CODE
	.area _INITIALIZER
__xinit__input_left:
	.db #0x00	;  0
__xinit__input_left_last:
	.db #0x00	;  0
__xinit__input_right:
	.db #0x00	;  0
__xinit__input_right_last:
	.db #0x00	;  0
__xinit__input_up:
	.db #0x00	;  0
__xinit__input_up_last:
	.db #0x00	;  0
__xinit__input_down:
	.db #0x00	;  0
__xinit__input_down_last:
	.db #0x00	;  0
__xinit__input_a_last:
	.db #0x00	;  0
__xinit__x_off:
	.db #0x00	; 0
__xinit__y_off:
	.db #0x00	; 0
	.area _CABS (ABS)
