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
	.globl _mode_show
	.globl _mode_menu
	.globl _start_mode_show
	.globl _start_mode_menu
	.globl _draw_menu
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
	.globl _strlen
	.globl _sprintf
	.globl _menu_bry
	.globl _menu_brx
	.globl _menu_tly
	.globl _menu_tlx
	.globl _timer_interval
	.globl _mode
	.globl _bry
	.globl _brx
	.globl _tly
	.globl _tlx
	.globl _selected_colour
	.globl _selected_type
	.globl _input_b_last
	.globl _input_a_last
	.globl _input_down_last
	.globl _input_down
	.globl _input_up_last
	.globl _input_up
	.globl _input_right_last
	.globl _input_right
	.globl _input_left_last
	.globl _input_left
	.globl _input_b
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
_input_b::
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
_input_b_last::
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
_mode::
	.ds 1
_timer_interval::
	.ds 1
_menu_tlx::
	.ds 1
_menu_tly::
	.ds 1
_menu_brx::
	.ds 1
_menu_bry::
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
;os.c:40: void basic_input()
;	---------------------------------
; Function basic_input
; ---------------------------------
_basic_input::
;os.c:42: input_up_last = input_up;
	ld	a,(#_input_up + 0)
	ld	iy, #_input_up_last
	ld	0 (iy), a
;os.c:43: input_down_last = input_down;
	ld	a,(#_input_down + 0)
	ld	iy, #_input_down_last
	ld	0 (iy), a
;os.c:44: input_left_last = input_left;
	ld	a,(#_input_left + 0)
	ld	iy, #_input_left_last
	ld	0 (iy), a
;os.c:45: input_right_last = input_right;
	ld	a,(#_input_right + 0)
	ld	iy, #_input_right_last
	ld	0 (iy), a
;os.c:46: input_a_last = input_a;
	ld	a,(#_input_a + 0)
	ld	iy, #_input_a_last
	ld	0 (iy), a
;os.c:47: input_b_last = input_b;
	ld	a,(#_input_b + 0)
	ld	iy, #_input_b_last
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
;os.c:53: input_b = CHECK_BIT(joystick[0], 5);
	ld	a, (#_joystick + 0)
	and	a, #0x20
	ld	c, a
	xor	a, a
	cp	a, c
	rla
	ld	(_input_b+0), a
;os.c:54: }
	ret
;os.c:64: void draw_colour()
;	---------------------------------
; Function draw_colour
; ---------------------------------
_draw_colour::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	hl, #-34
	add	hl, sp
	ld	sp, hl
;os.c:71: hcfr_colour_b[selected_type][selected_colour]);
	ld	bc, (_selected_type)
	ld	b, #0x00
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl, bc
	ex	de, hl
	ld	hl, #_hcfr_colour_b
	add	hl, de
	ld	-2 (ix), l
	ld	-1 (ix), h
	ld	hl,#_selected_colour + 0
	ld	c, (hl)
	ld	l, -2 (ix)
	ld	h, -1 (ix)
	ld	b, #0x00
	add	hl, bc
	ld	a, (hl)
	ld	-1 (ix), a
;os.c:70: hcfr_colour_g[selected_type][selected_colour],
	ld	hl, #_hcfr_colour_g
	add	hl, de
	ld	b, #0x00
	add	hl, bc
	ld	b, (hl)
;os.c:69: hcfr_colour_r[selected_type][selected_colour],
	ld	hl, #_hcfr_colour_r
	add	hl, de
	ld	e, c
	ld	d, #0x00
	add	hl, de
	ld	d, (hl)
;os.c:68: 16,
	ld	a, -1 (ix)
	push	af
	inc	sp
	ld	c, d
	push	bc
	ld	a, #0x10
	push	af
	inc	sp
	call	_set_char_palette
	pop	af
	pop	af
;os.c:73: panel_shaded(tlx, tly, brx, bry, 17, 18, 19);
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
;os.c:74: fill_bgcol(tlx + 1, tly + 1, brx, bry - 1, 16);
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
;os.c:75: clear_char_area(0, tlx, bry + 1, brx, bry + 3);
	ld	hl,#_bry + 0
	ld	b, (hl)
	ld	a, b
	inc	a
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
;os.c:76: write_string(hcfr_type[selected_type], 18, tlx, bry + 1);
	ld	hl,#_bry + 0
	ld	d, (hl)
	inc	d
	ld	bc, #_hcfr_type+0
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
;os.c:77: write_string(hcfr_colour_name[selected_type][selected_colour], 18, tlx, bry + 2);
	ld	hl,#_bry + 0
	ld	d, (hl)
	inc	d
	inc	d
	ld	bc, (_selected_type)
	ld	b, #0x00
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl, bc
	add	hl, hl
	ld	bc, #_hcfr_colour_name
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
;os.c:80: sprintf(temp, "%03d, %03d, %03d", hcfr_colour_r[selected_type][selected_colour], hcfr_colour_g[selected_type][selected_colour], hcfr_colour_b[selected_type][selected_colour]);
	ld	bc, (_selected_type)
	ld	b, #0x00
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl, bc
	ex	de, hl
	ld	hl, #_hcfr_colour_b
	add	hl, de
	ld	c, l
	ld	b, h
;os.c:71: hcfr_colour_b[selected_type][selected_colour]);
	ld	a,(#_selected_colour + 0)
;os.c:80: sprintf(temp, "%03d, %03d, %03d", hcfr_colour_r[selected_type][selected_colour], hcfr_colour_g[selected_type][selected_colour], hcfr_colour_b[selected_type][selected_colour]);
	ld	-1 (ix), a
	ld	l, a
	ld	h, #0x00
	add	hl, bc
	ld	c, (hl)
	ld	b, #0x00
	ld	hl, #_hcfr_colour_g
	add	hl, de
	ld	a, l
	add	a, -1 (ix)
	ld	l, a
	jr	NC,00103$
	inc	h
00103$:
	ld	a, (hl)
	ld	-4 (ix), a
	xor	a, a
	ld	-3 (ix), a
	ld	hl, #_hcfr_colour_r
	add	hl, de
	ld	e, -1 (ix)
	ld	d, #0x00
	add	hl, de
	ld	a, (hl)
	ld	-2 (ix), a
	xor	a, a
	ld	-1 (ix), a
	ld	hl, #0
	add	hl, sp
	ex	de, hl
	ld	l, e
	ld	h, d
	push	de
	push	bc
	ld	c, -4 (ix)
	ld	b, -3 (ix)
	push	bc
	ld	c, -2 (ix)
	ld	b, -1 (ix)
	push	bc
	ld	bc, #___str_0
	push	bc
	push	hl
	call	_sprintf
	ld	hl, #10
	add	hl, sp
	ld	sp, hl
	pop	de
;os.c:81: write_string(temp, 18, tlx, bry + 3);
	ld	a,(#_bry + 0)
	add	a, #0x03
	push	af
	inc	sp
	ld	a, (_tlx)
	ld	b,a
	ld	c,#0x12
	push	bc
	push	de
	call	_write_string
;os.c:82: }
	ld	sp,ix
	pop	ix
	ret
___str_0:
	.ascii "%03d, %03d, %03d"
	.db 0x00
;os.c:91: void timer_off()
;	---------------------------------
; Function timer_off
; ---------------------------------
_timer_off::
;os.c:93: timer_interval = 0;
	ld	hl,#_timer_interval + 0
	ld	(hl), #0x00
;os.c:94: write_string(" ", colour_cga_darkred, brx, tly - 1);
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
;os.c:95: }
	ret
___str_1:
	.ascii " "
	.db 0x00
;os.c:96: void timer_on()
;	---------------------------------
; Function timer_on
; ---------------------------------
_timer_on::
;os.c:98: timer_interval = timer_interval_max;
	ld	hl,#_timer_interval + 0
	ld	(hl), #0x3c
;os.c:99: write_string("*", colour_cga_darkred, brx, tly - 1);
	ld	hl,#_tly + 0
	ld	b, (hl)
	dec	b
	push	bc
	inc	sp
	ld	a, (_brx)
	ld	d,a
	ld	e,#0x04
	push	de
	ld	hl, #___str_2
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;os.c:100: }
	ret
___str_2:
	.ascii "*"
	.db 0x00
;os.c:107: void draw_menu()
;	---------------------------------
; Function draw_menu
; ---------------------------------
_draw_menu::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	hl, #-6
	add	hl, sp
	ld	sp, hl
;os.c:109: panel_shaded(menu_tlx, menu_tly, menu_brx, menu_tly + 2, 20, 21, 22);
	ld	hl,#_menu_tly + 0
	ld	b, (hl)
	inc	b
	inc	b
	ld	de, #0x1615
	push	de
	ld	a, #0x14
	push	af
	inc	sp
	push	bc
	inc	sp
	ld	a, (_menu_brx)
	push	af
	inc	sp
	ld	a, (_menu_tly)
	push	af
	inc	sp
	ld	a, (_menu_tlx)
	push	af
	inc	sp
	call	_panel_shaded
	ld	hl, #7
	add	hl, sp
	ld	sp, hl
;os.c:110: write_string("Select standard", colour_cga_lightcyan, menu_tlx + 3, menu_tly + 1);
	ld	hl,#_menu_tly + 0
	ld	b, (hl)
	inc	b
	ld	a,(#_menu_tlx + 0)
	add	a, #0x03
	ld	c, a
	push	bc
	inc	sp
	ld	d, c
	ld	e,#0x0b
	push	de
	ld	hl, #___str_3
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;os.c:111: panel_shaded(menu_tlx, menu_tly + 3, menu_brx, menu_bry, 20, 21, 22);
	ld	a,(#_menu_tly + 0)
	add	a, #0x03
	ld	b, a
	ld	de, #0x1615
	push	de
	ld	a, #0x14
	push	af
	inc	sp
	ld	a, (_menu_bry)
	push	af
	inc	sp
	ld	a, (_menu_brx)
	push	af
	inc	sp
	push	bc
	inc	sp
	ld	a, (_menu_tlx)
	push	af
	inc	sp
	call	_panel_shaded
	ld	hl, #7
	add	hl, sp
	ld	sp, hl
;os.c:112: unsigned char y = menu_tly + 5;
	ld	a,(#_menu_tly + 0)
	add	a, #0x05
	ld	-6 (ix), a
;os.c:113: for (int t = 0; t < hcfr_type_max; t++)
	ld	bc, #0x0000
00103$:
	ld	a, c
	sub	a, #0x08
	ld	a, b
	rla
	ccf
	rra
	sbc	a, #0x80
	jp	NC, 00105$
;os.c:115: unsigned char c = selected_type == t ? colour_cga_lightred : colour_cga_white;
	ld	iy, #_selected_type
	ld	l, 0 (iy)
	ld	h, #0x00
	cp	a, a
	sbc	hl, bc
	jr	NZ,00107$
	ld	de, #0x000c
	jr	00108$
00107$:
	ld	de, #0x000f
00108$:
	ld	-5 (ix), e
;os.c:116: unsigned char l = strlen(hcfr_wp[t]);
	ld	e, c
	ld	d, b
	sla	e
	rl	d
	ld	hl, #_hcfr_wp
	add	hl, de
	ld	-4 (ix), l
	ld	-3 (ix), h
	ld	a, (hl)
	inc	hl
	ld	h, (hl)
	ld	l, a
	push	bc
	push	hl
	call	_strlen
	pop	af
	pop	bc
	ld	-2 (ix), l
;os.c:117: write_string(hcfr_type[t], c, menu_tlx + 2, y);
	ld	a,(#_menu_tlx + 0)
	add	a, #0x02
	ld	-1 (ix), a
	ld	hl, #_hcfr_type
	add	hl, de
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	push	bc
	ld	h, -6 (ix)
	ld	l, -1 (ix)
	push	hl
	ld	a, -5 (ix)
	push	af
	inc	sp
	push	de
	call	_write_string
	pop	af
	pop	af
	inc	sp
	pop	bc
;os.c:118: write_string(hcfr_wp[t], c, (menu_brx - 2) - l, y);
	ld	a,(#_menu_brx + 0)
	dec	a
	dec	a
	ld	e, -2 (ix)
	sub	a, e
	ld	-1 (ix), a
	ld	l, -4 (ix)
	ld	h, -3 (ix)
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	push	bc
	ld	h, -6 (ix)
	ld	l, -1 (ix)
	push	hl
	ld	a, -5 (ix)
	push	af
	inc	sp
	push	de
	call	_write_string
	pop	af
	pop	af
	inc	sp
	pop	bc
;os.c:119: y += 2;
	ld	a, -6 (ix)
	add	a, #0x02
	ld	-6 (ix), a
;os.c:113: for (int t = 0; t < hcfr_type_max; t++)
	inc	bc
	jp	00103$
00105$:
;os.c:121: }
	ld	sp, ix
	pop	ix
	ret
___str_3:
	.ascii "Select standard"
	.db 0x00
;os.c:123: void start_mode_menu()
;	---------------------------------
; Function start_mode_menu
; ---------------------------------
_start_mode_menu::
;os.c:125: clear_chars(0);
	xor	a, a
	push	af
	inc	sp
	call	_clear_chars
	inc	sp
;os.c:126: clear_bgcolor(0);
	xor	a, a
	push	af
	inc	sp
	call	_clear_bgcolor
	inc	sp
;os.c:127: draw_menu();
	call	_draw_menu
;os.c:128: mode = const_mode_menu;
	ld	hl,#_mode + 0
	ld	(hl), #0x00
;os.c:129: }
	ret
;os.c:131: void start_mode_show()
;	---------------------------------
; Function start_mode_show
; ---------------------------------
_start_mode_show::
;os.c:133: clear_chars(0);
	xor	a, a
	push	af
	inc	sp
	call	_clear_chars
	inc	sp
;os.c:134: clear_bgcolor(0);
	xor	a, a
	push	af
	inc	sp
	call	_clear_bgcolor
	inc	sp
;os.c:135: draw_colour();
	call	_draw_colour
;os.c:136: selected_colour = 0;
	ld	hl,#_selected_colour + 0
	ld	(hl), #0x00
;os.c:137: mode = const_mode_show;
	ld	hl,#_mode + 0
	ld	(hl), #0x01
;os.c:138: }
	ret
;os.c:140: void mode_menu()
;	---------------------------------
; Function mode_menu
; ---------------------------------
_mode_menu::
;os.c:142: if (VBLANK_RISING)
	ld	hl,#_vblank+0
	bit	0, (hl)
	ret	Z
	ld	hl,#_vblank_last+0
	bit	0, (hl)
	ret	NZ
;os.c:144: basic_input();
	call	_basic_input
;os.c:146: if (input_up && !input_up_last)
	ld	iy, #_input_up
	bit	0, 0 (iy)
	jr	Z,00102$
	ld	iy, #_input_up_last
	bit	0, 0 (iy)
	jr	NZ,00102$
;os.c:148: selected_type = (selected_type == 0) ? hcfr_type_max - 1 : selected_type - 1;
	ld	a,(#_selected_type + 0)
	or	a, a
	jr	NZ,00115$
	ld	a, #0x07
	jr	00116$
00115$:
	ld	a,(#_selected_type + 0)
	dec	a
00116$:
	ld	(_selected_type+0), a
;os.c:149: draw_menu();
	call	_draw_menu
00102$:
;os.c:151: if (input_down && !input_down_last)
	ld	iy, #_input_down
	bit	0, 0 (iy)
	jr	Z,00105$
	ld	iy, #_input_down_last
	bit	0, 0 (iy)
	jr	NZ,00105$
;os.c:153: selected_type = (selected_type == hcfr_type_max - 1) ? 0 : selected_type + 1;
	ld	a,(#_selected_type + 0)
	sub	a, #0x07
	jr	NZ,00117$
	ld	bc, #0x0000
	jr	00118$
00117$:
	ld	a,(#_selected_type + 0)
	inc	a
	ld	c, a
	rla
	sbc	a, a
00118$:
	ld	hl,#_selected_type + 0
	ld	(hl), c
;os.c:154: draw_menu();
	call	_draw_menu
00105$:
;os.c:156: if (input_a && !input_a_last)
	ld	iy, #_input_a
	bit	0, 0 (iy)
	ret	Z
	ld	iy, #_input_a_last
	bit	0, 0 (iy)
;os.c:158: start_mode_show();
	jp	Z,_start_mode_show
;os.c:161: }
	ret
;os.c:163: void mode_show()
;	---------------------------------
; Function mode_show
; ---------------------------------
_mode_show::
;os.c:166: if (VBLANK_RISING)
	ld	hl,#_vblank+0
	bit	0, (hl)
	ret	Z
	ld	hl,#_vblank_last+0
	bit	0, (hl)
	ret	NZ
;os.c:168: basic_input();
	call	_basic_input
;os.c:170: if (input_up && !input_up_last)
	ld	iy, #_input_up
	bit	0, 0 (iy)
	jr	Z,00102$
	ld	iy, #_input_up_last
	bit	0, 0 (iy)
	jr	NZ,00102$
;os.c:172: selected_type = (selected_type == 0) ? hcfr_type_max - 1 : selected_type - 1;
	ld	a,(#_selected_type + 0)
	or	a, a
	jr	NZ,00132$
	ld	a, #0x07
	jr	00133$
00132$:
	ld	a,(#_selected_type + 0)
	dec	a
00133$:
	ld	(_selected_type+0), a
;os.c:173: draw_colour();
	call	_draw_colour
;os.c:174: timer_off();
	call	_timer_off
00102$:
;os.c:176: if (input_down && !input_down_last)
	ld	iy, #_input_down
	bit	0, 0 (iy)
	jr	Z,00105$
	ld	iy, #_input_down_last
	bit	0, 0 (iy)
	jr	NZ,00105$
;os.c:178: selected_type = (selected_type == hcfr_type_max - 1) ? 0 : selected_type + 1;
	ld	a,(#_selected_type + 0)
	sub	a, #0x07
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
;os.c:179: draw_colour();
	call	_draw_colour
;os.c:180: timer_off();
	call	_timer_off
00105$:
;os.c:182: if (input_left && !input_left_last)
	ld	iy, #_input_left
	bit	0, 0 (iy)
	jr	Z,00108$
	ld	iy, #_input_left_last
	bit	0, 0 (iy)
	jr	NZ,00108$
;os.c:184: selected_colour = (selected_colour == 0) ? hcfr_colour_max - 1 : selected_colour - 1;
	ld	a,(#_selected_colour + 0)
	or	a, a
	jr	NZ,00136$
	ld	a, #0x52
	jr	00137$
00136$:
	ld	a,(#_selected_colour + 0)
	dec	a
00137$:
	ld	(_selected_colour+0), a
;os.c:185: draw_colour();
	call	_draw_colour
;os.c:186: timer_off();
	call	_timer_off
00108$:
;os.c:188: if (input_right && !input_right_last)
	ld	iy, #_input_right
	bit	0, 0 (iy)
	jr	Z,00111$
	ld	iy, #_input_right_last
	bit	0, 0 (iy)
	jr	NZ,00111$
;os.c:190: selected_colour = (selected_colour == hcfr_colour_max - 1) ? 0 : selected_colour + 1;
	ld	a,(#_selected_colour + 0)
	sub	a, #0x52
	jr	NZ,00138$
	ld	bc, #0x0000
	jr	00139$
00138$:
	ld	a,(#_selected_colour + 0)
	inc	a
	ld	c, a
	rla
	sbc	a, a
00139$:
	ld	hl,#_selected_colour + 0
	ld	(hl), c
;os.c:191: draw_colour();
	call	_draw_colour
;os.c:192: timer_off();
	call	_timer_off
00111$:
;os.c:195: if (timer_interval > 0)
	ld	iy, #_timer_interval
	ld	a, 0 (iy)
	or	a, a
	jr	Z,00122$
;os.c:197: timer_interval--;
	dec	0 (iy)
;os.c:198: if (timer_interval == 0)
	ld	a, 0 (iy)
	or	a, a
	jr	NZ,00114$
;os.c:200: selected_colour = (selected_colour == hcfr_colour_max - 1) ? 0 : selected_colour + 1;
	ld	a,(#_selected_colour + 0)
	sub	a, #0x52
	jr	NZ,00140$
	ld	bc, #0x0000
	jr	00141$
00140$:
	ld	a,(#_selected_colour + 0)
	inc	a
	ld	c, a
	rla
	sbc	a, a
00141$:
	ld	hl,#_selected_colour + 0
	ld	(hl), c
;os.c:201: draw_colour();
	call	_draw_colour
;os.c:202: timer_interval = timer_interval_max;
	ld	iy, #_timer_interval
	ld	0 (iy), #0x3c
00114$:
;os.c:204: if (input_a && !input_a_last)
	ld	iy, #_input_a
	bit	0, 0 (iy)
	jr	Z,00123$
	ld	iy, #_input_a_last
	bit	0, 0 (iy)
	jr	NZ,00123$
;os.c:206: timer_off();
	call	_timer_off
	jr	00123$
00122$:
;os.c:211: if (input_a && !input_a_last)
	ld	iy, #_input_a
	bit	0, 0 (iy)
	jr	Z,00123$
	ld	iy, #_input_a_last
	bit	0, 0 (iy)
	jr	NZ,00123$
;os.c:213: timer_on();
	call	_timer_on
00123$:
;os.c:216: if (input_b && !input_b_last)
	ld	iy, #_input_b
	bit	0, 0 (iy)
	ret	Z
	ld	iy, #_input_b_last
	bit	0, 0 (iy)
;os.c:218: start_mode_menu();
	jp	Z,_start_mode_menu
;os.c:221: }
	ret
;os.c:224: void app_main()
;	---------------------------------
; Function app_main
; ---------------------------------
_app_main::
;os.c:226: chram_size = chram_cols * chram_rows;
	ld	hl,#_chram_rows + 0
	ld	e, (hl)
	ld	hl,#_chram_cols + 0
	ld	h, (hl)
	ld	l, #0x00
	ld	d, l
	ld	b, #0x08
00124$:
	add	hl, hl
	jr	NC,00125$
	add	hl, de
00125$:
	djnz	00124$
	ld	(_chram_size), hl
;os.c:228: clear_chars(0);
	xor	a, a
	push	af
	inc	sp
	call	_clear_chars
	inc	sp
;os.c:229: clear_bgcolor(transparent_char);
	ld	a, #0xff
	push	af
	inc	sp
	call	_clear_bgcolor
	inc	sp
;os.c:231: set_default_char_palette();
	call	_set_default_char_palette
;os.c:233: set_char_palette(16, 50, 50, 50);
	ld	de, #0x3232
	push	de
	ld	de, #0x3210
	push	de
	call	_set_char_palette
	pop	af
	pop	af
;os.c:235: set_char_palette(17, 255, 255, 255); // White?
	ld	de, #0xffff
	push	de
	ld	de, #0xff11
	push	de
	call	_set_char_palette
	pop	af
	pop	af
;os.c:236: set_char_palette(18, 160, 160, 160); // Grey
	ld	de, #0xa0a0
	push	de
	ld	de, #0xa012
	push	de
	call	_set_char_palette
	pop	af
	pop	af
;os.c:237: set_char_palette(19, 80, 80, 80);	 // Dark grey
	ld	de, #0x5050
	push	de
	ld	de, #0x5013
	push	de
	call	_set_char_palette
	pop	af
	pop	af
;os.c:239: set_char_palette(20, 90, 179, 255); // Light blue
	ld	de, #0xffb3
	push	de
	ld	de, #0x5a14
	push	de
	call	_set_char_palette
	pop	af
	pop	af
;os.c:240: set_char_palette(21, 54, 139, 255); // Blue
	ld	de, #0xff8b
	push	de
	ld	de, #0x3615
	push	de
	call	_set_char_palette
	pop	af
	pop	af
;os.c:241: set_char_palette(22, 0, 67, 252);	// Dark blue
	ld	de, #0xfc43
	push	de
	xor	a, a
	ld	d,a
	ld	e,#0x16
	push	de
	call	_set_char_palette
	pop	af
	pop	af
;os.c:243: start_mode_menu();
	call	_start_mode_menu
;os.c:245: while (1)
00105$:
;os.c:247: hsync = input0 & 0x80;
	ld	iy, #_input0
	ld	a, 0 (iy)
	rlc	a
	and	a, #0x01
	ld	(_hsync+0), a
;os.c:248: vsync = input0 & 0x40;
	ld	a, 0 (iy)
	and	a, #0x40
	ld	c,a
	or	a,#0x00
	add	a, #0xff
	ld	a, #0x00
	rla
	ld	(_vsync+0), a
;os.c:249: hblank = input0 & 0x20;
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
;os.c:250: vblank = CHECK_BIT(input0, INPUT_VBLANK);
	ld	a, 0 (iy)
	and	a, #0x10
	ld	c, a
	xor	a, a
	cp	a, c
	rla
	ld	(_vblank+0), a
;os.c:252: switch (mode)
	ld	iy, #_mode
	ld	a, 0 (iy)
	or	a, a
	jr	Z,00101$
	ld	a, 0 (iy)
	dec	a
	jr	Z,00102$
	jr	00103$
;os.c:254: case const_mode_menu:
00101$:
;os.c:255: mode_menu();
	call	_mode_menu
;os.c:256: break;
	jr	00103$
;os.c:257: case const_mode_show:
00102$:
;os.c:258: mode_show();
	call	_mode_show
;os.c:260: }
00103$:
;os.c:262: hsync_last = hsync;
	ld	a,(#_hsync + 0)
	ld	iy, #_hsync_last
	ld	0 (iy), a
;os.c:263: vsync_last = vsync;
	ld	a,(#_vsync + 0)
	ld	iy, #_vsync_last
	ld	0 (iy), a
;os.c:264: hblank_last = hblank;
	ld	a,(#_hblank + 0)
	ld	iy, #_hblank_last
	ld	0 (iy), a
;os.c:265: vblank_last = vblank;
	ld	a,(#_vblank + 0)
	ld	iy, #_vblank_last
	ld	0 (iy), a
;os.c:267: }
	jp	00105$
;os.c:270: void main()
;	---------------------------------
; Function main
; ---------------------------------
_main::
;os.c:272: app_main();
;os.c:273: }
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
__xinit__input_b_last:
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
__xinit__mode:
	.db #0x00	; 0
__xinit__timer_interval:
	.db #0x00	; 0
__xinit__menu_tlx:
	.db #0x0a	; 10
__xinit__menu_tly:
	.db #0x04	; 4
__xinit__menu_brx:
	.db #0x1e	; 30
__xinit__menu_bry:
	.db #0x19	; 25
	.area _CABS (ABS)
