;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.8.0 #10562 (Linux)
;--------------------------------------------------------
	.module menu
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _basic_input
	.globl _handle_ps2
	.globl _fill_bgcol
	.globl _fill
	.globl _panel_shaded
	.globl _write_string
	.globl _menu_string
	.globl _menu_ready
	.globl _menu_dirty
	.globl _menu_timer
	.globl _menu_index
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
	.globl _start_menu
	.globl _menu
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
_menu_index::
	.ds 1
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
_menu_timer::
	.ds 1
_menu_dirty::
	.ds 1
_menu_ready::
	.ds 1
_menu_string::
	.ds 10
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
;menu.c:40: void start_menu()
;	---------------------------------
; Function start_menu
; ---------------------------------
_start_menu::
;menu.c:42: state = STATE_MENU;
	ld	hl,#_state + 0
	ld	(hl), #0x0a
;menu.c:43: menu_timer = 0;
	ld	hl,#_menu_timer + 0
	ld	(hl), #0x00
;menu.c:44: menu_ready = 0;
	ld	hl,#_menu_ready + 0
	ld	(hl), #0x00
;menu.c:45: }
	ret
;menu.c:48: void menu()
;	---------------------------------
; Function menu
; ---------------------------------
_menu::
	push	ix
	ld	ix,#0
	add	ix,sp
	push	af
	push	af
	dec	sp
;menu.c:51: handle_ps2();
	call	_handle_ps2
;menu.c:54: if (HBLANK_RISING)
	ld	hl,#_hblank+0
	bit	0, (hl)
	jp	Z, 00125$
	ld	hl,#_hblank_last+0
	bit	0, (hl)
	jp	NZ, 00125$
;menu.c:56: basic_input();
	call	_basic_input
;menu.c:57: if (input_up && !input_up_last) // up
	ld	hl,#_input_up+0
	bit	0, (hl)
	jr	Z,00104$
	ld	hl,#_input_up_last+0
	bit	0, (hl)
	jr	NZ,00104$
;menu.c:59: menu_index--;
	ld	iy, #_menu_index
	dec	0 (iy)
;menu.c:60: if (menu_index > 128)
	ld	a, #0x80
	sub	a, 0 (iy)
	jr	NC,00102$
;menu.c:62: menu_index = menu_count - 1;
	ld	0 (iy), #0x04
00102$:
;menu.c:64: menu_dirty = true;
	ld	hl,#_menu_dirty + 0
	ld	(hl), #0x01
00104$:
;menu.c:66: if (input_down && !input_down_last) // down
	ld	hl,#_input_down+0
	bit	0, (hl)
	jr	Z,00109$
	ld	hl,#_input_down_last+0
	bit	0, (hl)
	jr	NZ,00109$
;menu.c:68: menu_index++;
	ld	iy, #_menu_index
	inc	0 (iy)
;menu.c:69: if (menu_index == menu_count)
	ld	a, 0 (iy)
	sub	a, #0x05
	jr	NZ,00107$
;menu.c:71: menu_index = 0;
	ld	0 (iy), #0x00
00107$:
;menu.c:73: menu_dirty = true;
	ld	hl,#_menu_dirty + 0
	ld	(hl), #0x01
00109$:
;menu.c:75: if ((!input_start && input_start_last) || (!input_a && input_a_last) || (!input_b && input_b_last))
	ld	hl,#_input_start+0
	bit	0, (hl)
	jr	NZ,00121$
	ld	hl,#_input_start_last+0
	bit	0, (hl)
	jr	NZ,00117$
00121$:
	ld	hl,#_input_a+0
	bit	0, (hl)
	jr	NZ,00123$
	ld	hl,#_input_a_last+0
	bit	0, (hl)
	jr	NZ,00117$
00123$:
	ld	hl,#_input_b+0
	bit	0, (hl)
	jr	NZ,00125$
	ld	hl,#_input_b_last+0
	bit	0, (hl)
	jr	Z,00125$
00117$:
;menu.c:77: switch (menu_index)
	ld	a, #0x04
	ld	iy, #_menu_index
	sub	a, 0 (iy)
	jr	C,00125$
	ld	c, 0 (iy)
	ld	b, #0x00
	ld	hl, #00262$
	add	hl, bc
	add	hl, bc
	add	hl, bc
	jp	(hl)
00262$:
	jp	00111$
	jp	00112$
	jp	00113$
	jp	00114$
	jp	00115$
;menu.c:79: case 0:
00111$:
;menu.c:80: state = STATE_START_INPUTTESTER;
	ld	hl,#_state + 0
	ld	(hl), #0x01
;menu.c:81: break;
	jr	00125$
;menu.c:82: case 1:
00112$:
;menu.c:83: state = STATE_START_INPUTTESTERANALOG;
	ld	hl,#_state + 0
	ld	(hl), #0x05
;menu.c:84: break;
	jr	00125$
;menu.c:85: case 2:
00113$:
;menu.c:86: state = STATE_START_INPUTTESTERADVANCED;
	ld	hl,#_state + 0
	ld	(hl), #0x03
;menu.c:87: break;
	jr	00125$
;menu.c:88: case 3:
00114$:
;menu.c:89: state = STATE_START_BTNTEST;
	ld	hl,#_state + 0
	ld	(hl), #0x07
;menu.c:90: break;
	jr	00125$
;menu.c:91: case 4:
00115$:
;menu.c:92: state = STATE_START_CREDITS;
	ld	hl,#_state + 0
	ld	(hl), #0x2a
;menu.c:94: }
00125$:
;menu.c:99: if (VBLANK_RISING)
	ld	hl,#_vblank+0
	bit	0, (hl)
	jp	Z, 00146$
	ld	hl,#_vblank_last+0
	bit	0, (hl)
	jp	NZ, 00146$
;menu.c:103: if (menu_timer < maxsize)
	ld	iy, #_menu_timer
	ld	a, 0 (iy)
	sub	a, #0x11
	jp	NC, 00138$
;menu.c:105: char oy1 = ((menu_timer) / 2);
	ld	l, 0 (iy)
	ld	h, #0x00
	ld	c, l
	ld	e, h
	bit	7, h
	jr	Z,00148$
	inc	hl
	ld	c, l
	ld	e, h
00148$:
	sra	e
	rr	c
;menu.c:108: panel_shaded(menu_tx, my - oy1, menu_bx, my + oy2, menu_panel_outline_high, menu_panel_outline_mid, menu_panel_outline_low);
	ld	a, c
	add	a, #0x0f
	ld	d, a
	ld	a, #0x0f
	sub	a, c
	ld	b, a
	push	bc
	ld	a, #0x24
	push	af
	inc	sp
	ld	a, #0x36
	push	af
	inc	sp
	ld	a, #0xff
	push	af
	inc	sp
	push	de
	inc	sp
	ld	a, #0x1c
	push	af
	inc	sp
	push	bc
	inc	sp
	ld	a, #0x0c
	push	af
	inc	sp
	call	_panel_shaded
	ld	hl, #7
	add	hl, sp
	ld	sp, hl
	pop	bc
;menu.c:109: if (oy1 > 1)
	ld	a, #0x01
	sub	a, c
	jr	NC,00128$
;menu.c:111: fill(menu_tx + 1, my - (oy1 - 1), menu_bx - 1, my + (oy2 - 1), 0, 0);
	dec	c
	ld	a, c
	add	a, #0x0f
	ld	d, a
	ld	a, #0x0f
	sub	a, c
	ld	b, a
	push	bc
	push	de
	xor	a, a
	push	af
	inc	sp
	xor	a, a
	push	af
	inc	sp
	push	de
	inc	sp
	ld	a, #0x1b
	push	af
	inc	sp
	push	bc
	inc	sp
	ld	a, #0x0d
	push	af
	inc	sp
	call	_fill
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
	pop	de
	pop	bc
;menu.c:112: fill_bgcol(menu_tx + 1, my - (oy1 - 1), menu_bx - 1, my + (oy2 - 1), menu_panel_back);
	xor	a, a
	push	af
	inc	sp
	push	de
	inc	sp
	ld	a, #0x1b
	push	af
	inc	sp
	push	bc
	inc	sp
	ld	a, #0x0d
	push	af
	inc	sp
	call	_fill_bgcol
	pop	af
	pop	af
	inc	sp
00128$:
;menu.c:114: menu_timer++;
	ld	iy, #_menu_timer
	inc	0 (iy)
;menu.c:115: if (menu_timer == maxsize)
	ld	a, 0 (iy)
	sub	a, #0x11
	jp	NZ,00146$
;menu.c:117: menu_dirty = true;
	ld	hl,#_menu_dirty + 0
	ld	(hl), #0x01
	jp	00146$
00138$:
;menu.c:122: if (menu_dirty)
	ld	a,(#_menu_dirty + 0)
	or	a, a
	jp	Z, 00146$
;menu.c:124: char ty = menu_my - ((menu_count * 3) / 2);
	ld	c, #0x08
;menu.c:125: for (char m = 0; m < menu_count; m++)
	ld	e, #0x00
00144$:
	ld	a, e
	sub	a, #0x05
	jp	NC, 00134$
;menu.c:129: panel_shaded(menu_tx + 1, ty, menu_bx - 1, ty + 2, menu_sel_outline_high, menu_sel_outline_mid, menu_sel_outline_low);
	ld	-3 (ix), c
;menu.c:130: write_string(menu_string[m], menu_sel_text, menu_tx + 2, ty + 1);
	ld	l, e
	ld	h, #0x00
;menu.c:129: panel_shaded(menu_tx + 1, ty, menu_bx - 1, ty + 2, menu_sel_outline_high, menu_sel_outline_mid, menu_sel_outline_low);
	ld	a, -3 (ix)
	add	a, #0x02
	ld	-5 (ix), a
;menu.c:130: write_string(menu_string[m], menu_sel_text, menu_tx + 2, ty + 1);
	ld	a, -3 (ix)
	inc	a
	ld	-4 (ix), a
	add	hl, hl
	ld	-2 (ix), l
	ld	-1 (ix), h
;menu.c:127: if (menu_index == m)
	ld	a,(#_menu_index + 0)
	sub	a, e
	jr	NZ,00132$
;menu.c:129: panel_shaded(menu_tx + 1, ty, menu_bx - 1, ty + 2, menu_sel_outline_high, menu_sel_outline_mid, menu_sel_outline_low);
	push	de
	ld	de, #0x1416
	push	de
	ld	a, #0x5f
	push	af
	inc	sp
	ld	d, -5 (ix)
	ld	e,#0x1b
	push	de
	ld	d, c
	ld	e,#0x0d
	push	de
	call	_panel_shaded
	ld	hl, #7
	add	hl, sp
	ld	sp, hl
	pop	de
;menu.c:130: write_string(menu_string[m], menu_sel_text, menu_tx + 2, ty + 1);
	ld	a, #<(_menu_string)
	add	a, -2 (ix)
	ld	l, a
	ld	a, #>(_menu_string)
	adc	a, -1 (ix)
	ld	h, a
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	push	de
	ld	d, -4 (ix)
	ld	e,#0x0e
	push	de
	ld	a, #0xff
	push	af
	inc	sp
	push	bc
	call	_write_string
	pop	af
	pop	af
	inc	sp
	pop	de
	jr	00133$
00132$:
;menu.c:135: panel_shaded(menu_tx + 1, ty, menu_bx - 1, ty + 2, menu_outline_high, menu_outline_mid, menu_outline_low);
	push	de
	ld	de, #0x64b6
	push	de
	ld	a, #0xbf
	push	af
	inc	sp
	ld	d, -5 (ix)
	ld	e,#0x1b
	push	de
	ld	d, c
	ld	e,#0x0d
	push	de
	call	_panel_shaded
	ld	hl, #7
	add	hl, sp
	ld	sp, hl
	pop	de
;menu.c:136: write_string(menu_string[m], menu_text, menu_tx + 2, ty + 1);
	ld	a, #<(_menu_string)
	add	a, -2 (ix)
	ld	l, a
	ld	a, #>(_menu_string)
	adc	a, -1 (ix)
	ld	h, a
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	push	de
	ld	d, -4 (ix)
	ld	e,#0x0e
	push	de
	ld	a, #0xb6
	push	af
	inc	sp
	push	bc
	call	_write_string
	pop	af
	pop	af
	inc	sp
	pop	de
00133$:
;menu.c:139: ty += 3;
	ld	c, -3 (ix)
	inc	c
	inc	c
	inc	c
;menu.c:125: for (char m = 0; m < menu_count; m++)
	inc	e
	jp	00144$
00134$:
;menu.c:141: menu_dirty = false;
	ld	hl,#_menu_dirty + 0
	ld	(hl), #0x00
;menu.c:142: menu_ready = true;
	ld	hl,#_menu_ready + 0
	ld	(hl), #0x01
00146$:
;menu.c:146: }
	ld	sp, ix
	pop	ix
	ret
	.area _CODE
___str_0:
	.ascii "Digital"
	.db 0x00
___str_1:
	.ascii "Analog"
	.db 0x00
___str_2:
	.ascii "Advanced"
	.db 0x00
___str_3:
	.ascii "Button test"
	.db 0x00
___str_4:
	.ascii "Credits"
	.db 0x00
	.area _INITIALIZER
__xinit__menu_timer:
	.db #0x00	; 0
__xinit__menu_dirty:
	.db #0x00	; 0
__xinit__menu_ready:
	.db #0x00	; 0
__xinit__menu_string:
	.dw ___str_0
	.dw ___str_1
	.dw ___str_2
	.dw ___str_3
	.dw ___str_4
	.area _CABS (ABS)
