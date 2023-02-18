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
	.globl _app_main
	.globl _timer_on
	.globl _timer_off
	.globl _draw_colour
	.globl _basic_input
	.globl _fill_bgcol
	.globl _panel_shaded
	.globl _write_string
	.globl _set_default_char_palette
	.globl _set_char_palette
	.globl _clear_bgcolor
	.globl _clear_char_area
	.globl _clear_chars
	.globl _timer_interval
	.globl _bry
	.globl _brx
	.globl _tly
	.globl _tlx
	.globl _selected_colour
	.globl _selected_type
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
	.globl _spritecollisionram
	.globl _spriteram
	.globl _charpaletteram
	.globl _bgcolram
	.globl _fgcolram
	.globl _chram
	.globl _tilemapram
	.globl _tilemapctl
	.globl _musicram
	.globl _sndram
	.globl _system_menu
	.globl _system_pause
	.globl _starfield3
	.globl _starfield2
	.globl _starfield1
	.globl _ps2_mouse
	.globl _ps2_key
	.globl _spinner
	.globl _paddle
	.globl _analog_r
	.globl _analog_l
	.globl _joystick
	.globl _timer
	.globl _timestamp
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
_timestamp	=	0x8080
_timer	=	0x80c0
_joystick	=	0x8100
_analog_l	=	0x8200
_analog_r	=	0x8280
_paddle	=	0x8300
_spinner	=	0x8380
_ps2_key	=	0x8400
_ps2_mouse	=	0x8480
_starfield1	=	0x8500
_starfield2	=	0x8510
_starfield3	=	0x8520
_system_pause	=	0x8530
_system_menu	=	0x8531
_sndram	=	0x8580
_musicram	=	0x8590
_tilemapctl	=	0x8600
_tilemapram	=	0x8610
_chram	=	0x9200
_fgcolram	=	0x9a00
_bgcolram	=	0xa200
_charpaletteram	=	0xaa00
_spriteram	=	0xb000
_spritecollisionram	=	0xb400
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
_selected_type::
	.ds 1
_selected_colour::
	.ds 1
_tlx::
	.ds 1
_tly::
	.ds 1
_brx::
	.ds 1
_bry::
	.ds 1
_timer_interval::
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
;os.c:38: void basic_input()
;	---------------------------------
; Function basic_input
; ---------------------------------
_basic_input::
;os.c:40: input_up_last = input_up;
	ld	a,(#_input_up + 0)
	ld	iy, #_input_up_last
	ld	0 (iy), a
;os.c:41: input_down_last = input_down;
	ld	a,(#_input_down + 0)
	ld	iy, #_input_down_last
	ld	0 (iy), a
;os.c:42: input_left_last = input_left;
	ld	a,(#_input_left + 0)
	ld	iy, #_input_left_last
	ld	0 (iy), a
;os.c:43: input_right_last = input_right;
	ld	a,(#_input_right + 0)
	ld	iy, #_input_right_last
	ld	0 (iy), a
;os.c:44: input_a_last = input_a;
	ld	a,(#_input_a + 0)
	ld	iy, #_input_a_last
	ld	0 (iy), a
;os.c:45: input_up = CHECK_BIT(joystick[0], 3);
	ld	a, (#_joystick + 0)
	and	a, #0x08
	ld	c, a
	xor	a, a
	cp	a, c
	rla
	ld	(_input_up+0), a
;os.c:46: input_down = CHECK_BIT(joystick[0], 2);
	ld	a, (#_joystick + 0)
	and	a, #0x04
	ld	c, a
	xor	a, a
	cp	a, c
	rla
	ld	(_input_down+0), a
;os.c:47: input_left = CHECK_BIT(joystick[0], 1);
	ld	a, (#_joystick + 0)
	and	a, #0x02
	ld	c, a
	xor	a, a
	cp	a, c
	rla
	ld	(_input_left+0), a
;os.c:48: input_right = CHECK_BIT(joystick[0], 0);
	ld	a, (#_joystick + 0)
	and	a, #0x01
	ld	(_input_right+0), a
;os.c:49: input_a = CHECK_BIT(joystick[0], 4);
	ld	a, (#_joystick + 0)
	and	a, #0x10
	ld	c, a
	xor	a, a
	cp	a, c
	rla
	ld	(_input_a+0), a
;os.c:50: }
	ret
;os.c:60: void draw_colour()
;	---------------------------------
; Function draw_colour
; ---------------------------------
_draw_colour::
	push	ix
	ld	ix,#0
	add	ix,sp
	dec	sp
;os.c:67: hfcr_colour_b[selected_type][selected_colour]);
	ld	iy, #_selected_type
	ld	l, 0 (iy)
	ld	h, #0x00
	add	hl, hl
	ld	c, l
	ld	b, h
	ld	hl, #_hfcr_colour_b
	add	hl, bc
	ex	de, hl
	ld	a,(#_selected_colour + 0)
	ld	-1 (ix), a
	ld	l, a
	ld	h, #0x00
	add	hl, de
	ld	d, (hl)
;os.c:66: hfcr_colour_g[selected_type][selected_colour],
	ld	hl, #_hfcr_colour_g+0
	add	hl, bc
	ld	a, l
	add	a, -1 (ix)
	ld	l, a
	jr	NC,00103$
	inc	h
00103$:
	ld	e, (hl)
;os.c:65: hfcr_colour_r[selected_type][selected_colour],
	ld	hl, #_hfcr_colour_r+0
	add	hl, bc
	ld	c, -1 (ix)
	ld	b, #0x00
	add	hl, bc
	ld	b, (hl)
;os.c:64: 16,
	push	de
	push	bc
	inc	sp
	ld	a, #0x10
	push	af
	inc	sp
	call	_set_char_palette
	pop	af
	pop	af
;os.c:69: panel_shaded(tlx, tly, brx, bry, 17, 18, 19);
	ld	de, #0x1312
	push	de
	ld	a, #0x11
	push	af
	inc	sp
	ld	a, (_bry)
	push	af
	inc	sp
	ld	a, (_brx)
	push	af
	inc	sp
	ld	a, (_tly)
	push	af
	inc	sp
	ld	a, (_tlx)
	push	af
	inc	sp
	call	_panel_shaded
	ld	hl, #7
	add	hl, sp
	ld	sp, hl
;os.c:70: fill_bgcol(tlx + 1, tly + 1, brx, bry - 1, 16);
	ld	hl,#_bry + 0
	ld	d, (hl)
	dec	d
	ld	hl,#_tly + 0
	ld	b, (hl)
	inc	b
	ld	hl,#_tlx + 0
	ld	c, (hl)
	inc	c
	ld	a, #0x10
	push	af
	inc	sp
	push	de
	inc	sp
	ld	a, (_brx)
	push	af
	inc	sp
	push	bc
	inc	sp
	ld	a, c
	push	af
	inc	sp
	call	_fill_bgcol
	pop	af
	pop	af
	inc	sp
;os.c:71: clear_char_area(0, tlx, bry + 1, brx, bry + 2);
	ld	hl,#_bry + 0
	ld	b, (hl)
	ld	a, b
	inc	a
	inc	a
	inc	b
	push	af
	inc	sp
	ld	a, (_brx)
	push	af
	inc	sp
	push	bc
	inc	sp
	ld	a, (_tlx)
	push	af
	inc	sp
	xor	a, a
	push	af
	inc	sp
	call	_clear_char_area
	pop	af
	pop	af
	inc	sp
;os.c:72: write_string(hfcr_type[selected_type], 18, tlx, bry + 1);
	ld	hl,#_bry + 0
	ld	d, (hl)
	inc	d
	ld	bc, #_hfcr_type+0
	ld	iy, #_selected_type
	ld	l, 0 (iy)
	ld	h, #0x00
	add	hl, hl
	add	hl, bc
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	push	de
	inc	sp
	ld	a, (_tlx)
	ld	d,a
	ld	e,#0x12
	push	de
	push	bc
	call	_write_string
	pop	af
	pop	af
	inc	sp
;os.c:73: write_string(hfcr_colour_name[selected_type][selected_colour], 18, tlx, bry + 2);
	ld	hl,#_bry + 0
	ld	d, (hl)
	inc	d
	inc	d
	ld	bc, #_hfcr_colour_name+0
	ld	iy, #_selected_type
	ld	l, 0 (iy)
	ld	h, #0x00
	add	hl, hl
	add	hl, hl
	add	hl, bc
	ld	a,(#_selected_colour + 0)
	add	a, a
	ld	c, a
	ld	b, #0x00
	add	hl, bc
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	push	de
	inc	sp
	ld	a, (_tlx)
	ld	d,a
	ld	e,#0x12
	push	de
	push	bc
	call	_write_string
	pop	af
	pop	af
	inc	sp
;os.c:74: }
	inc	sp
	pop	ix
	ret
;os.c:77: void timer_off()
;	---------------------------------
; Function timer_off
; ---------------------------------
_timer_off::
;os.c:79: timer_interval = 0;
	ld	hl,#_timer_interval + 0
	ld	(hl), #0x00
;os.c:80: write_string("", colour_cga_darkred, brx, tly - 1);
	ld	hl,#_tly + 0
	ld	b, (hl)
	dec	b
	push	bc
	inc	sp
	ld	a, (_brx)
	ld	d,a
	ld	e,#0x04
	push	de
	ld	hl, #___str_0
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;os.c:81: }
	ret
___str_0:
	.db 0x00
;os.c:82: void timer_on()
;	---------------------------------
; Function timer_on
; ---------------------------------
_timer_on::
;os.c:84: timer_interval = 60;
	ld	hl,#_timer_interval + 0
	ld	(hl), #0x3c
;os.c:85: write_string("*", colour_cga_darkred, brx, tly - 1);
	ld	hl,#_tly + 0
	ld	b, (hl)
	dec	b
	push	bc
	inc	sp
	ld	a, (_brx)
	ld	d,a
	ld	e,#0x04
	push	de
	ld	hl, #___str_1
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;os.c:86: }
	ret
___str_1:
	.ascii "*"
	.db 0x00
;os.c:89: void app_main()
;	---------------------------------
; Function app_main
; ---------------------------------
_app_main::
;os.c:91: chram_size = chram_cols * chram_rows;
	ld	hl,#_chram_rows + 0
	ld	e, (hl)
	ld	hl,#_chram_cols + 0
	ld	h, (hl)
	ld	l, #0x00
	ld	d, l
	ld	b, #0x08
00252$:
	add	hl, hl
	jr	NC,00253$
	add	hl, de
00253$:
	djnz	00252$
	ld	(_chram_size), hl
;os.c:93: clear_chars(0);
	xor	a, a
	push	af
	inc	sp
	call	_clear_chars
	inc	sp
;os.c:94: set_default_char_palette();
	call	_set_default_char_palette
;os.c:96: set_char_palette(16, 50, 50, 50);
	ld	de, #0x3232
	push	de
	ld	de, #0x3210
	push	de
	call	_set_char_palette
	pop	af
	pop	af
;os.c:97: clear_bgcolor(0);
	xor	a, a
	push	af
	inc	sp
	call	_clear_bgcolor
	inc	sp
;os.c:99: set_char_palette(17, 255, 255, 255);
	ld	de, #0xffff
	push	de
	ld	de, #0xff11
	push	de
	call	_set_char_palette
	pop	af
	pop	af
;os.c:100: set_char_palette(18, 160, 160, 160);
	ld	de, #0xa0a0
	push	de
	ld	de, #0xa012
	push	de
	call	_set_char_palette
	pop	af
	pop	af
;os.c:101: set_char_palette(19, 80, 80, 80);
	ld	de, #0x5050
	push	de
	ld	de, #0x5013
	push	de
	call	_set_char_palette
	pop	af
	pop	af
;os.c:103: draw_colour();
	call	_draw_colour
;os.c:105: while (1)
00128$:
;os.c:107: hsync = input0 & 0x80;
	ld	iy, #_input0
	ld	a, 0 (iy)
	rlc	a
	and	a, #0x01
	ld	(_hsync+0), a
;os.c:108: vsync = input0 & 0x40;
	ld	a, 0 (iy)
	and	a, #0x40
	ld	c,a
	or	a,#0x00
	add	a, #0xff
	ld	a, #0x00
	rla
	ld	(_vsync+0), a
;os.c:109: hblank = input0 & 0x20;
	ld	a, 0 (iy)
	and	a, #0x20
	ld	c, a
	ld	b, #0x00
	ld	a, b
	or	a, c
	add	a, #0xff
	ld	a, #0x00
	rla
	ld	(_hblank+0), a
;os.c:110: vblank = CHECK_BIT(input0, INPUT_VBLANK);
	ld	a, 0 (iy)
	and	a, #0x10
	ld	c, a
	xor	a, a
	cp	a, c
	rla
	ld	(_vblank+0), a
;os.c:112: if (VBLANK_RISING)
	ld	iy, #_vblank
	bit	0, 0 (iy)
	jp	Z, 00125$
	ld	iy, #_vblank_last
	bit	0, 0 (iy)
	jp	NZ, 00125$
;os.c:114: basic_input();
	call	_basic_input
;os.c:116: if (input_up && !input_up_last)
	ld	iy, #_input_up
	bit	0, 0 (iy)
	jr	Z,00102$
	ld	iy, #_input_up_last
	bit	0, 0 (iy)
	jr	NZ,00102$
;os.c:118: selected_type = (selected_type == 0) ? hfcr_type_max - 1 : selected_type - 1;
	ld	a,(#_selected_type + 0)
	or	a,a
	jr	Z,00133$
	ld	a,(#_selected_type + 0)
	dec	a
00133$:
	ld	(_selected_type+0), a
;os.c:119: draw_colour();
	call	_draw_colour
;os.c:120: timer_off();
	call	_timer_off
00102$:
;os.c:122: if (input_down && !input_down_last)
	ld	iy, #_input_down
	bit	0, 0 (iy)
	jr	Z,00105$
	ld	iy, #_input_down_last
	bit	0, 0 (iy)
	jr	NZ,00105$
;os.c:124: selected_type = (selected_type == hfcr_type_max - 1) ? 0 : selected_type + 1;
	ld	a,(#_selected_type + 0)
	or	a, a
	jr	NZ,00134$
	ld	bc, #0x0000
	jr	00135$
00134$:
	ld	a,(#_selected_type + 0)
	inc	a
	ld	c, a
	rla
	sbc	a, a
00135$:
	ld	hl,#_selected_type + 0
	ld	(hl), c
;os.c:125: draw_colour();
	call	_draw_colour
;os.c:126: timer_off();
	call	_timer_off
00105$:
;os.c:128: if (input_left && !input_left_last)
	ld	iy, #_input_left
	bit	0, 0 (iy)
	jr	Z,00108$
	ld	iy, #_input_left_last
	bit	0, 0 (iy)
	jr	NZ,00108$
;os.c:130: selected_colour = (selected_colour == 0) ? hfcr_colour_max - 1 : selected_colour - 1;
	ld	a,(#_selected_colour + 0)
	or	a, a
	jr	NZ,00136$
	ld	a, #0x01
	jr	00137$
00136$:
	ld	a,(#_selected_colour + 0)
	dec	a
00137$:
	ld	(_selected_colour+0), a
;os.c:131: draw_colour();
	call	_draw_colour
;os.c:132: timer_off();
	call	_timer_off
00108$:
;os.c:134: if (input_right && !input_right_last)
	ld	iy, #_input_right
	bit	0, 0 (iy)
	jr	Z,00111$
	ld	iy, #_input_right_last
	bit	0, 0 (iy)
	jr	NZ,00111$
;os.c:136: selected_colour = (selected_colour == hfcr_colour_max - 1) ? 0 : selected_colour + 1;
	ld	a,(#_selected_colour + 0)
	cp	a, #0x01
	jr	NZ,00138$
	ld	bc, #0x0000
	jr	00139$
00138$:
	inc	a
	ld	c, a
	rla
	sbc	a, a
00139$:
	ld	hl,#_selected_colour + 0
	ld	(hl), c
;os.c:137: draw_colour();
	call	_draw_colour
;os.c:138: timer_off();
	call	_timer_off
00111$:
;os.c:141: if (timer_interval > 0)
	ld	iy, #_timer_interval
	ld	a, 0 (iy)
	or	a, a
	jr	Z,00122$
;os.c:143: timer_interval--;
	dec	0 (iy)
;os.c:144: if (timer_interval == 0)
	ld	a, 0 (iy)
	or	a, a
	jr	NZ,00114$
;os.c:146: selected_colour = (selected_colour == hfcr_colour_max - 1) ? 0 : selected_colour + 1;
	ld	a,(#_selected_colour + 0)
	cp	a, #0x01
	jr	NZ,00140$
	ld	bc, #0x0000
	jr	00141$
00140$:
	inc	a
	ld	c, a
	rla
	sbc	a, a
00141$:
	ld	hl,#_selected_colour + 0
	ld	(hl), c
;os.c:147: draw_colour();
	call	_draw_colour
00114$:
;os.c:149: if (input_a && !input_a_last)
	ld	iy, #_input_a
	bit	0, 0 (iy)
	jr	Z,00125$
	ld	iy, #_input_a_last
	bit	0, 0 (iy)
	jr	NZ,00125$
;os.c:151: timer_off();
	call	_timer_off
	jr	00125$
00122$:
;os.c:156: if (input_a && !input_a_last)
	ld	iy, #_input_a
	bit	0, 0 (iy)
	jr	Z,00125$
	ld	iy, #_input_a_last
	bit	0, 0 (iy)
	jr	NZ,00125$
;os.c:158: timer_on();
	call	_timer_on
00125$:
;os.c:163: hsync_last = hsync;
	ld	a,(#_hsync + 0)
	ld	iy, #_hsync_last
	ld	0 (iy), a
;os.c:164: vsync_last = vsync;
	ld	a,(#_vsync + 0)
	ld	iy, #_vsync_last
	ld	0 (iy), a
;os.c:165: hblank_last = hblank;
	ld	a,(#_hblank + 0)
	ld	iy, #_hblank_last
	ld	0 (iy), a
;os.c:166: vblank_last = vblank;
	ld	a,(#_vblank + 0)
	ld	iy, #_vblank_last
	ld	0 (iy), a
;os.c:168: }
	jp	00128$
;os.c:171: void main()
;	---------------------------------
; Function main
; ---------------------------------
_main::
;os.c:173: app_main();
;os.c:174: }
	jp	_app_main
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
__xinit__selected_type:
	.db #0x00	; 0
__xinit__selected_colour:
	.db #0x00	; 0
__xinit__tlx:
	.db #0x09	; 9
__xinit__tly:
	.db #0x04	; 4
__xinit__brx:
	.db #0x1e	; 30
__xinit__bry:
	.db #0x19	; 25
__xinit__timer_interval:
	.db #0x00	; 0
	.area _CABS (ABS)
