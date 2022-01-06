;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.8.0 #10562 (Linux)
;--------------------------------------------------------
	.module inputtester_ui
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _fill
	.globl _panel_shaded
	.globl _panel
	.globl _write_char_row
	.globl _write_char
	.globl _write_string
	.globl _clear_chars
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
	.globl _page_frame
	.globl _draw_pad
	.globl _draw_analog
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
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
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
;inputtester_ui.c:26: void page_frame(bool showMenuButton, bool showContinueButton)
;	---------------------------------
; Function page_frame
; ---------------------------------
_page_frame::
	push	ix
	ld	ix,#0
	add	ix,sp
;inputtester_ui.c:28: bool footer = showMenuButton || showContinueButton;
	bit	0, 4 (ix)
	jr	NZ,00112$
	bit	0, 5 (ix)
	jr	NZ,00112$
	xor	a, a
	jr	00113$
00112$:
	ld	a, #0x01
00113$:
	ld	c, a
;inputtester_ui.c:29: clear_chars(0);
	push	bc
	xor	a, a
	push	af
	inc	sp
	call	_clear_chars
	inc	sp
	ld	de, #0x010b
	push	de
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_0
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
	ld	de, #0x0406
	push	de
	ld	de, #0x0702
	push	de
	ld	a, #0x27
	push	af
	inc	sp
	xor	a, a
	push	af
	inc	sp
	xor	a, a
	push	af
	inc	sp
	call	_panel_shaded
	ld	hl, #7
	add	hl, sp
	ld	sp, hl
	pop	bc
;inputtester_ui.c:32: panel_shaded(0, 3, 39, footer ? 26 : 29, 0b10100100, 0b10100100, 0b01010010);
	bit	0, c
	jr	Z,00114$
	ld	de, #0x001a
	jr	00115$
00114$:
	ld	de, #0x001d
00115$:
	ld	b, e
	push	bc
	ld	de, #0x52a4
	push	de
	ld	a, #0xa4
	push	af
	inc	sp
	push	bc
	inc	sp
	ld	de, #0x2703
	push	de
	xor	a, a
	push	af
	inc	sp
	call	_panel_shaded
	ld	hl, #7
	add	hl, sp
	ld	sp, hl
	pop	bc
;inputtester_ui.c:33: if (footer)
	bit	0, c
	jp	Z, 00109$
;inputtester_ui.c:35: char buttons = showMenuButton && showContinueButton ? 2 : 1;
	bit	0, 4 (ix)
	jr	Z,00116$
	bit	0, 5 (ix)
	jr	Z,00116$
	ld	hl, #0x0002
	jr	00117$
00116$:
	ld	hl, #0x0001
00117$:
;inputtester_ui.c:36: char x1 = buttons == 1 ? 39 : 19;
	ld	a, l
	dec	a
	jr	NZ, 00179$
	ld	a, #0x01
	.db	#0x20
00179$:
	xor	a, a
00180$:
	ld	c,a
	or	a, a
	jr	Z,00121$
	ld	de, #0x0027
	jr	00122$
00121$:
	ld	de, #0x0013
00122$:
;inputtester_ui.c:37: char m1 = buttons == 1 ? 20 : 10;
	ld	a, c
	or	a, a
	jr	Z,00123$
	ld	bc, #0x0014
	jr	00124$
00123$:
	ld	bc, #0x000a
00124$:
;inputtester_ui.c:38: panel_shaded(0, 27, x1, 29, 0b11000000, 0b10000000, 0b01000000);
	push	hl
	push	bc
	push	de
	ld	bc, #0x4080
	push	bc
	ld	a, #0xc0
	push	af
	inc	sp
	ld	d,#0x1d
	push	de
	ld	a, #0x1b
	push	af
	inc	sp
	xor	a, a
	push	af
	inc	sp
	call	_panel_shaded
	ld	hl, #7
	add	hl, sp
	ld	sp, hl
	pop	de
	pop	bc
	pop	hl
;inputtester_ui.c:39: if (buttons == 2)
	ld	a, l
	sub	a, #0x02
	jr	NZ,00102$
;inputtester_ui.c:41: panel_shaded(x1 + 1, 27, 39, 29, 0b11000000, 0b10000000, 0b01000000);
	ld	b, e
	inc	b
	push	bc
	ld	de, #0x4080
	push	de
	ld	de, #0xc01d
	push	de
	ld	de, #0x271b
	push	de
	push	bc
	inc	sp
	call	_panel_shaded
	ld	hl, #7
	add	hl, sp
	ld	sp, hl
	pop	bc
00102$:
;inputtester_ui.c:43: if (showMenuButton)
	bit	0, 4 (ix)
	jr	Z,00104$
;inputtester_ui.c:45: write_string("Hold Select: Menu", 0b11011011, m1 - 9, 28);
	ld	a, c
	add	a, #0xf7
	ld	b, a
	push	bc
	ld	a, #0x1c
	push	af
	inc	sp
	push	bc
	inc	sp
	ld	a, #0xdb
	push	af
	inc	sp
	ld	hl, #___str_1
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
	pop	bc
;inputtester_ui.c:46: m1 += 20;
	ld	a, c
	add	a, #0x14
	ld	c, a
00104$:
;inputtester_ui.c:48: if (showContinueButton)
	bit	0, 5 (ix)
	jr	Z,00109$
;inputtester_ui.c:50: write_string("Start: Continue", 0b11011011, m1 - 8, 28);
	ld	a, c
	add	a, #0xf8
	ld	b, a
	ld	a, #0x1c
	push	af
	inc	sp
	push	bc
	inc	sp
	ld	a, #0xdb
	push	af
	inc	sp
	ld	hl, #___str_2
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
00109$:
;inputtester_ui.c:53: }
	pop	ix
	ret
___str_0:
	.ascii "MiSTer Input Tester"
	.db 0x00
___str_1:
	.ascii "Hold Select: Menu"
	.db 0x00
___str_2:
	.ascii "Start: Continue"
	.db 0x00
;inputtester_ui.c:56: void draw_pad(char xo, char yo)
;	---------------------------------
; Function draw_pad
; ---------------------------------
_draw_pad::
	push	ix
	ld	ix,#0
	add	ix,sp
	push	af
	push	af
;inputtester_ui.c:59: write_char(char_corner_round_tl, color_pad_outline, xo, yo + 2);
	ld	a, 5 (ix)
	ld	-3 (ix), a
	add	a, #0x02
	ld	-4 (ix), a
	push	af
	inc	sp
	ld	d, 4 (ix)
	ld	e,#0xfe
	push	de
	ld	a, #0x95
	push	af
	inc	sp
	call	_write_char
	pop	af
	pop	af
;inputtester_ui.c:60: write_char_row(char_line_h, color_pad_outline, xo + 1, yo + 2, 25);
	ld	c, 4 (ix)
	ld	a, c
	inc	a
	ld	-1 (ix), a
	push	bc
	ld	a, #0x19
	push	af
	inc	sp
	ld	a, -4 (ix)
	push	af
	inc	sp
	ld	d, -1 (ix)
	ld	e,#0xfe
	push	de
	ld	a, #0x83
	push	af
	inc	sp
	call	_write_char_row
	pop	af
	pop	af
	inc	sp
	pop	bc
;inputtester_ui.c:61: write_char(char_corner_round_tr, color_pad_outline, xo + 26, yo + 2);
	ld	a, c
	add	a, #0x1a
	ld	e, a
	push	bc
	push	de
	ld	d, -4 (ix)
	push	de
	ld	de, #0xfe89
	push	de
	call	_write_char
	pop	af
	pop	af
	pop	de
	pop	bc
;inputtester_ui.c:62: for (char y = 3; y < 8; y++)
	ld	b, #0x03
00103$:
	ld	a, b
	sub	a, #0x08
	jr	NC,00101$
;inputtester_ui.c:64: write_char(char_line_v, color_pad_outline, xo, yo + y);
	ld	a, 5 (ix)
	add	a, b
	ld	d, a
	push	bc
	push	de
	push	de
	inc	sp
	ld	d, 4 (ix)
	ld	e,#0xfe
	push	de
	ld	a, #0x82
	push	af
	inc	sp
	call	_write_char
	pop	af
	pop	af
	pop	de
	push	de
	push	de
	inc	sp
	ld	d, e
	ld	e,#0xfe
	push	de
	ld	a, #0x82
	push	af
	inc	sp
	call	_write_char
	pop	af
	pop	af
	pop	de
	pop	bc
;inputtester_ui.c:62: for (char y = 3; y < 8; y++)
	inc	b
	jr	00103$
00101$:
;inputtester_ui.c:67: write_char(char_corner_round_bl, color_pad_outline, xo, yo + 8);
	ld	a, -3 (ix)
	add	a, #0x08
	ld	b, a
	push	bc
	push	de
	push	bc
	inc	sp
	ld	d, 4 (ix)
	ld	e,#0xfe
	push	de
	ld	a, #0x8a
	push	af
	inc	sp
	call	_write_char
	pop	af
	pop	af
	pop	de
	pop	bc
;inputtester_ui.c:68: write_char(char_corner_round_br, color_pad_outline, xo + 26, yo + 8);
	push	bc
	push	bc
	inc	sp
	ld	d, e
	ld	e,#0xfe
	push	de
	ld	a, #0x8b
	push	af
	inc	sp
	call	_write_char
	pop	af
	pop	af
	pop	bc
;inputtester_ui.c:70: write_char(char_corner_round_br, color_pad_outline, xo + 8, yo + 8);
	ld	a, c
	add	a, #0x08
	ld	-2 (ix), a
	push	bc
	push	bc
	inc	sp
	ld	d, -2 (ix)
	ld	e,#0xfe
	push	de
	ld	a, #0x8b
	push	af
	inc	sp
	call	_write_char
	pop	af
	pop	af
	pop	bc
;inputtester_ui.c:71: write_char(char_corner_round_bl, color_pad_outline, xo + 18, yo + 8);
	ld	a, c
	add	a, #0x12
	ld	e, a
	push	bc
	push	de
	push	bc
	inc	sp
	ld	d, e
	ld	e,#0xfe
	push	de
	ld	a, #0x8a
	push	af
	inc	sp
	call	_write_char
	pop	af
	pop	af
	pop	de
	pop	bc
;inputtester_ui.c:72: write_char(char_corner_round_tl, color_pad_outline, xo + 8, yo + 7);
	ld	a, -3 (ix)
	add	a, #0x07
	ld	d, a
	push	bc
	push	de
	push	de
	inc	sp
	ld	d, -2 (ix)
	ld	e,#0xfe
	push	de
	ld	a, #0x95
	push	af
	inc	sp
	call	_write_char
	pop	af
	pop	af
	pop	de
	push	de
	push	de
	inc	sp
	ld	d, e
	ld	e,#0xfe
	push	de
	ld	a, #0x89
	push	af
	inc	sp
	call	_write_char
	pop	af
	pop	af
	pop	de
	pop	bc
;inputtester_ui.c:75: write_char_row(char_line_h, color_pad_outline, xo + 1, yo + 8, 7);
	push	bc
	push	de
	ld	a, #0x07
	push	af
	inc	sp
	push	bc
	inc	sp
	ld	d, -1 (ix)
	ld	e,#0xfe
	push	de
	ld	a, #0x83
	push	af
	inc	sp
	call	_write_char_row
	pop	af
	pop	af
	inc	sp
	pop	de
	pop	bc
;inputtester_ui.c:76: write_char_row(char_line_h, color_pad_outline, xo + 9, yo + 7, 9);
	ld	a, c
	add	a, #0x09
	ld	e, a
	push	bc
	ld	a, #0x09
	push	af
	inc	sp
	push	de
	inc	sp
	ld	d, e
	ld	e,#0xfe
	push	de
	ld	a, #0x83
	push	af
	inc	sp
	call	_write_char_row
	pop	af
	pop	af
	inc	sp
	pop	bc
;inputtester_ui.c:77: write_char_row(char_line_h, color_pad_outline, xo + 19, yo + 8, 7);
	ld	a, c
	add	a, #0x13
	ld	d, a
	push	bc
	ld	a, #0x07
	push	af
	inc	sp
	ld	c, d
	push	bc
	ld	de, #0xfe83
	push	de
	call	_write_char_row
	pop	af
	pop	af
	inc	sp
	pop	bc
;inputtester_ui.c:80: write_char(char_line_v, color_pad_outline, xo + 1, yo + 1);
	ld	b, -3 (ix)
	inc	b
	push	bc
	push	bc
	inc	sp
	ld	d, -1 (ix)
	ld	e,#0xfe
	push	de
	ld	a, #0x82
	push	af
	inc	sp
	call	_write_char
	pop	af
	pop	af
	ld	a, -4 (ix)
	push	af
	inc	sp
	ld	d, -1 (ix)
	ld	e,#0xfe
	push	de
	ld	a, #0xb1
	push	af
	inc	sp
	call	_write_char
	pop	af
	pop	af
	ld	a, 5 (ix)
	push	af
	inc	sp
	ld	d, -1 (ix)
	ld	e,#0xfe
	push	de
	ld	a, #0x95
	push	af
	inc	sp
	call	_write_char
	pop	af
	pop	af
	pop	bc
;inputtester_ui.c:83: write_char_row(char_line_h, color_pad_outline, xo + 2, yo, 3);
	ld	d, c
	inc	d
	inc	d
	push	bc
	ld	a, #0x03
	push	af
	inc	sp
	ld	a, 5 (ix)
	push	af
	inc	sp
	push	de
	inc	sp
	ld	de, #0xfe83
	push	de
	call	_write_char_row
	pop	af
	pop	af
	inc	sp
	pop	bc
;inputtester_ui.c:84: write_char(char_line_v, color_pad_outline, xo + 5, yo + 1);
	ld	a, c
	add	a, #0x05
	ld	d, a
	push	bc
	push	de
	ld	c, d
	push	bc
	ld	de, #0xfe82
	push	de
	call	_write_char
	pop	af
	pop	af
	pop	de
	push	de
	ld	a, -4 (ix)
	push	af
	inc	sp
	push	de
	inc	sp
	ld	de, #0xfeb1
	push	de
	call	_write_char
	pop	af
	pop	af
	pop	de
	ld	a, 5 (ix)
	push	af
	inc	sp
	push	de
	inc	sp
	ld	de, #0xfe89
	push	de
	call	_write_char
	pop	af
	pop	af
	pop	bc
;inputtester_ui.c:87: write_char(char_line_v, color_pad_outline, xo + 21, yo + 1);
	ld	a, c
	add	a, #0x15
	ld	d, a
	push	bc
	push	de
	ld	c, d
	push	bc
	ld	de, #0xfe82
	push	de
	call	_write_char
	pop	af
	pop	af
	pop	de
	push	de
	ld	a, -4 (ix)
	push	af
	inc	sp
	push	de
	inc	sp
	ld	de, #0xfeb1
	push	de
	call	_write_char
	pop	af
	pop	af
	pop	de
	ld	a, 5 (ix)
	push	af
	inc	sp
	push	de
	inc	sp
	ld	de, #0xfe95
	push	de
	call	_write_char
	pop	af
	pop	af
	pop	bc
;inputtester_ui.c:90: write_char_row(char_line_h, color_pad_outline, xo + 22, yo, 3);
	ld	a, c
	add	a, #0x16
	ld	d, a
	push	bc
	ld	a, #0x03
	push	af
	inc	sp
	ld	a, 5 (ix)
	push	af
	inc	sp
	push	de
	inc	sp
	ld	de, #0xfe83
	push	de
	call	_write_char_row
	pop	af
	pop	af
	inc	sp
	pop	bc
;inputtester_ui.c:91: write_char(char_line_v, color_pad_outline, xo + 25, yo + 1);
	ld	a, c
	add	a, #0x19
	ld	d, a
	push	de
	ld	c, d
	push	bc
	ld	de, #0xfe82
	push	de
	call	_write_char
	pop	af
	pop	af
	pop	de
;inputtester_ui.c:92: write_char(char_t_up, color_pad_outline, xo + 25, yo + 2);
	push	de
	ld	a, -4 (ix)
	push	af
	inc	sp
	push	de
	inc	sp
	ld	de, #0xfeb1
	push	de
	call	_write_char
	pop	af
	pop	af
	pop	de
;inputtester_ui.c:93: write_char(char_corner_round_tr, color_pad_outline, xo + 25, yo);
	ld	a, 5 (ix)
	push	af
	inc	sp
	push	de
	inc	sp
	ld	de, #0xfe89
	push	de
	call	_write_char
;inputtester_ui.c:94: }
	ld	sp,ix
	pop	ix
	ret
;inputtester_ui.c:97: void draw_analog(char xo, char yo, char xs, char ys)
;	---------------------------------
; Function draw_analog
; ---------------------------------
_draw_analog::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	hl, #-6
	add	hl, sp
	ld	sp, hl
;inputtester_ui.c:99: panel(xo, yo, xo + xs, yo + ys, 0xFF);
	ld	a, 5 (ix)
	add	a, 7 (ix)
	ld	b, a
	ld	a, 4 (ix)
	add	a, 6 (ix)
	ld	c, a
	push	bc
	ld	a, #0xff
	push	af
	inc	sp
	push	bc
	inc	sp
	ld	a, c
	push	af
	inc	sp
	ld	h, 5 (ix)
	ld	l, 4 (ix)
	push	hl
	call	_panel
	pop	af
	pop	af
	inc	sp
	pop	bc
;inputtester_ui.c:100: fill(xo + 1, yo + 1, xo + xs - 1, yo + ys - 1, char_dot, color_analog_grid);
	ld	e, b
	dec	e
	dec	c
	ld	a, 5 (ix)
	ld	-2 (ix), a
	inc	a
	ld	-3 (ix), a
	ld	a, 4 (ix)
	ld	-4 (ix), a
	ld	b, a
	inc	b
	push	bc
	ld	a, #0x23
	push	af
	inc	sp
	ld	d,#0x1b
	push	de
	ld	a, c
	push	af
	inc	sp
	ld	a, -3 (ix)
	push	af
	inc	sp
	push	bc
	inc	sp
	call	_fill
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
	pop	bc
;inputtester_ui.c:101: char mx = xo + (xs / 2);
	ld	l, 6 (ix)
	ld	h, #0x00
	ld	e, l
	ld	d, h
	bit	7, h
	jr	Z,00107$
	ex	de,hl
	inc	de
00107$:
	sra	d
	rr	e
	ld	a, e
	add	a, -4 (ix)
	ld	c, a
;inputtester_ui.c:102: char my = yo + (ys / 2);
	ld	e, 7 (ix)
	ld	d, #0x00
	ld	l, e
	ld	h, d
	bit	7, d
	jr	Z,00108$
	ld	l, e
	ld	h, d
	inc	hl
00108$:
	sra	h
	rr	l
	ld	a, l
	add	a, -2 (ix)
	ld	-1 (ix), a
;inputtester_ui.c:103: write_char_row(char_line_h, color_analog_grid, xo + 1, my, xs - 1);
	ld	h, 6 (ix)
	dec	h
	push	bc
	push	de
	push	hl
	inc	sp
	ld	a, -1 (ix)
	push	af
	inc	sp
	push	bc
	inc	sp
	ld	de, #0x2383
	push	de
	call	_write_char_row
	pop	af
	pop	af
	inc	sp
	pop	de
	pop	bc
;inputtester_ui.c:104: for (char y = yo + 1; y < yo + ys; y++)
	ld	b, -3 (ix)
00103$:
	ld	l, 5 (ix)
	ld	h, #0x00
	add	hl, de
	ld	-6 (ix), b
	ld	-5 (ix), #0x00
	ld	a, -6 (ix)
	sub	a, l
	ld	a, -5 (ix)
	sbc	a, h
	jp	PO, 00130$
	xor	a, #0x80
00130$:
	jp	P, 00101$
;inputtester_ui.c:106: write_char(char_line_v, color_analog_grid, mx, y);
	push	bc
	push	de
	push	bc
	inc	sp
	ld	d, c
	ld	e,#0x23
	push	de
	ld	a, #0x82
	push	af
	inc	sp
	call	_write_char
	pop	af
	pop	af
	pop	de
	pop	bc
;inputtester_ui.c:104: for (char y = yo + 1; y < yo + ys; y++)
	inc	b
	jr	00103$
00101$:
;inputtester_ui.c:108: write_char(char_cross, color_analog_grid, mx, my);
	ld	a, -1 (ix)
	push	af
	inc	sp
	ld	d, c
	ld	e,#0x23
	push	de
	ld	a, #0x9b
	push	af
	inc	sp
	call	_write_char
;inputtester_ui.c:109: }
	ld	sp,ix
	pop	ix
	ret
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
