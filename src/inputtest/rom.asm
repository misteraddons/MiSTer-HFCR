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
	.globl _app_credits
	.globl _fadein
	.globl _fadeout
	.globl _snek_attract
	.globl _snek_gameplay
	.globl _start_snek_gameplay
	.globl _start_snek_attract
	.globl _app_zorblaxx
	.globl _menu
	.globl _start_menu
	.globl _btntest
	.globl _inputtester_advanced
	.globl _inputtester_analog
	.globl _inputtester_digital
	.globl _start_btntest
	.globl _start_inputtester_advanced
	.globl _start_inputtester_analog
	.globl _start_inputtester_digital
	.globl _loader
	.globl _set_default_char_palette
	.globl _set_char_palette
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
;os.c:39: void app_main()
;	---------------------------------
; Function app_main
; ---------------------------------
_app_main::
;os.c:41: chram_size = chram_cols * chram_rows;
	ld	hl,#_chram_rows + 0
	ld	e, (hl)
	ld	hl,#_chram_cols + 0
	ld	h, (hl)
	ld	l, #0x00
	ld	d, l
	ld	b, #0x08
00221$:
	add	hl, hl
	jr	NC,00222$
	add	hl, de
00222$:
	djnz	00221$
	ld	(_chram_size), hl
;os.c:43: set_default_char_palette();
	call	_set_default_char_palette
;os.c:46: set_char_palette(colour_header_light, 255, 0, 0);
	xor	a, a
	push	af
	inc	sp
	xor	a, a
	ld	d,a
	ld	e,#0xff
	push	de
	ld	a, #0x10
	push	af
	inc	sp
	call	_set_char_palette
	pop	af
	pop	af
;os.c:47: set_char_palette(colour_header_mid, 237, 0, 0);
	xor	a, a
	push	af
	inc	sp
	xor	a, a
	ld	d,a
	ld	e,#0xed
	push	de
	ld	a, #0x11
	push	af
	inc	sp
	call	_set_char_palette
	pop	af
	pop	af
;os.c:48: set_char_palette(colour_header_dark, 179, 0, 0);
	xor	a, a
	push	af
	inc	sp
	xor	a, a
	ld	d,a
	ld	e,#0xb3
	push	de
	ld	a, #0x12
	push	af
	inc	sp
	call	_set_char_palette
	pop	af
	pop	af
;os.c:49: set_char_palette(colour_frame_light, 180, 180, 200);
	ld	de, #0xc8b4
	push	de
	ld	de, #0xb413
	push	de
	call	_set_char_palette
	pop	af
	pop	af
;os.c:50: set_char_palette(colour_frame_mid, 156, 156, 185);
	ld	de, #0xb99c
	push	de
	ld	de, #0x9c14
	push	de
	call	_set_char_palette
	pop	af
	pop	af
;os.c:51: set_char_palette(colour_frame_dark, 70, 70, 80);
	ld	de, #0x5046
	push	de
	ld	de, #0x4615
	push	de
	call	_set_char_palette
	pop	af
;os.c:52: set_char_palette(colour_footer_light, 0, 0, 255);
	ld	h,#0xff
	ex	(sp),hl
	inc	sp
	xor	a, a
	push	af
	inc	sp
	xor	a, a
	ld	d,a
	ld	e,#0x16
	push	de
	call	_set_char_palette
	pop	af
;os.c:53: set_char_palette(colour_footer_mid, 0, 0, 237);
	ld	h,#0xed
	ex	(sp),hl
	inc	sp
	xor	a, a
	push	af
	inc	sp
	xor	a, a
	ld	d,a
	ld	e,#0x17
	push	de
	call	_set_char_palette
	pop	af
;os.c:54: set_char_palette(colour_footer_dark, 0, 0, 179);
	ld	h,#0xb3
	ex	(sp),hl
	inc	sp
	xor	a, a
	push	af
	inc	sp
	xor	a, a
	ld	d,a
	ld	e,#0x18
	push	de
	call	_set_char_palette
	pop	af
	pop	af
;os.c:55: set_char_palette(colour_footer_text, 113, 105, 255);
	ld	de, #0xff69
	push	de
	ld	de, #0x7119
	push	de
	call	_set_char_palette
	pop	af
	pop	af
;os.c:57: set_char_palette(colour_pad_outline, 222, 255, 255);
	ld	de, #0xffff
	push	de
	ld	de, #0xde1e
	push	de
	call	_set_char_palette
	pop	af
	pop	af
;os.c:58: set_char_palette(colour_analog_outline, 255, 255, 255);
	ld	de, #0xffff
	push	de
	ld	de, #0xff1f
	push	de
	call	_set_char_palette
	pop	af
	pop	af
;os.c:59: set_char_palette(colour_analog_grid, 109, 161, 0);
	xor	a, a
	ld	d,a
	ld	e,#0xa1
	push	de
	ld	de, #0x6d20
	push	de
	call	_set_char_palette
	pop	af
	pop	af
;os.c:60: set_char_palette(colour_analog_text_cycle, 255, 255, 20);
	ld	de, #0x14ff
	push	de
	ld	de, #0xff21
	push	de
	call	_set_char_palette
	pop	af
	pop	af
;os.c:62: set_char_palette(colour_buttontest_text_primary, 50, 255, 255);
	ld	de, #0xffff
	push	de
	ld	de, #0x3228
	push	de
	call	_set_char_palette
	pop	af
	pop	af
;os.c:63: set_char_palette(colour_buttontest_text_secondary, 251, 196, 255);
	ld	de, #0xffc4
	push	de
	ld	de, #0xfb29
	push	de
	call	_set_char_palette
	pop	af
	pop	af
;os.c:64: set_char_palette(colour_buttontest_purple, 202, 105, 255);
	ld	de, #0xff69
	push	de
	ld	de, #0xca2a
	push	de
	call	_set_char_palette
	pop	af
	pop	af
;os.c:66: set_char_palette(colour_menu_panel_outline_high, 255, 255, 255);
	ld	de, #0xffff
	push	de
	ld	de, #0xff32
	push	de
	call	_set_char_palette
	pop	af
	pop	af
;os.c:67: set_char_palette(colour_menu_panel_outline_mid, 238, 238, 0);
	xor	a, a
	ld	d,a
	ld	e,#0xee
	push	de
	ld	de, #0xee33
	push	de
	call	_set_char_palette
	pop	af
	pop	af
;os.c:68: set_char_palette(colour_menu_panel_outline_low, 150, 161, 0);
	xor	a, a
	ld	d,a
	ld	e,#0xa1
	push	de
	ld	de, #0x9634
	push	de
	call	_set_char_palette
	pop	af
	pop	af
;os.c:69: set_char_palette(colour_menu_panel_back, 0, 0, 0);
	xor	a, a
	push	af
	inc	sp
	xor	a, a
	push	af
	inc	sp
	xor	a, a
	ld	d,a
	ld	e,#0x35
	push	de
	call	_set_char_palette
	pop	af
	pop	af
;os.c:71: set_char_palette(colour_menu_outline_high, 249, 249, 180);
	ld	de, #0xb4f9
	push	de
	ld	de, #0xf936
	push	de
	call	_set_char_palette
	pop	af
	pop	af
;os.c:72: set_char_palette(colour_menu_outline_mid, 239, 239, 170);
	ld	de, #0xaaef
	push	de
	ld	de, #0xef37
	push	de
	call	_set_char_palette
	pop	af
	pop	af
;os.c:73: set_char_palette(colour_menu_outline_low, 156, 156, 71);
	ld	de, #0x479c
	push	de
	ld	de, #0x9c38
	push	de
	call	_set_char_palette
	pop	af
	pop	af
;os.c:74: set_char_palette(colour_menu_text, 239, 239, 170);
	ld	de, #0xaaef
	push	de
	ld	de, #0xef39
	push	de
	call	_set_char_palette
	pop	af
	pop	af
;os.c:75: set_char_palette(colour_menu_back, 0, 0, 0);
	xor	a, a
	push	af
	inc	sp
	xor	a, a
	push	af
	inc	sp
	xor	a, a
	ld	d,a
	ld	e,#0x3a
	push	de
	call	_set_char_palette
	pop	af
	pop	af
;os.c:77: set_char_palette(colour_menu_sel_outline_high, 255, 104, 61);
	ld	de, #0x3d68
	push	de
	ld	de, #0xff3b
	push	de
	call	_set_char_palette
	pop	af
	pop	af
;os.c:78: set_char_palette(colour_menu_sel_outline_mid, 254, 64, 0);
	xor	a, a
	ld	d,a
	ld	e,#0x40
	push	de
	ld	de, #0xfe3c
	push	de
	call	_set_char_palette
	pop	af
	pop	af
;os.c:79: set_char_palette(colour_menu_sel_outline_low, 165, 72, 0);
	xor	a, a
	ld	d,a
	ld	e,#0x48
	push	de
	ld	de, #0xa53d
	push	de
	call	_set_char_palette
	pop	af
	pop	af
;os.c:80: set_char_palette(colour_menu_sel_text, 255, 255, 255);
	ld	de, #0xffff
	push	de
	ld	de, #0xff3e
	push	de
	call	_set_char_palette
	pop	af
	pop	af
;os.c:81: set_char_palette(colour_menu_sel_back, 0, 0, 0);
	xor	a, a
	push	af
	inc	sp
	xor	a, a
	push	af
	inc	sp
	xor	a, a
	ld	d,a
	ld	e,#0x3f
	push	de
	call	_set_char_palette
	pop	af
	pop	af
;os.c:83: while (1)
00122$:
;os.c:85: hsync = input0 & 0x80;
	ld	iy, #_input0
	ld	a, 0 (iy)
	rlc	a
	and	a, #0x01
	ld	(_hsync+0), a
;os.c:86: vsync = input0 & 0x40;
	ld	a, 0 (iy)
	and	a, #0x40
	ld	c,a
	or	a,#0x00
	add	a, #0xff
	ld	a, #0x00
	rla
	ld	(_vsync+0), a
;os.c:87: hblank = input0 & 0x20;
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
;os.c:88: vblank = CHECK_BIT(input0, INPUT_VBLANK);
	ld	a, 0 (iy)
	and	a, #0x10
	ld	c, a
	xor	a, a
	cp	a, c
	rla
	ld	(_vblank+0), a
;os.c:89: switch (state)
	ld	iy, #_state
	ld	a, 0 (iy)
	dec	a
	jp	Z,00101$
	ld	a, 0 (iy)
	sub	a, #0x02
	jp	Z,00102$
	ld	a, 0 (iy)
	sub	a, #0x03
	jp	Z,00103$
	ld	a, 0 (iy)
	sub	a, #0x04
	jp	Z,00104$
	ld	a, 0 (iy)
	sub	a, #0x05
	jp	Z,00105$
	ld	a, 0 (iy)
	sub	a, #0x06
	jp	Z,00106$
	ld	a, 0 (iy)
	sub	a, #0x07
	jr	Z,00107$
	ld	a, 0 (iy)
	sub	a, #0x08
	jr	Z,00108$
	ld	a, 0 (iy)
	sub	a, #0x09
	jr	Z,00109$
	ld	a, 0 (iy)
	sub	a, #0x0a
	jr	Z,00110$
	ld	a, 0 (iy)
	sub	a, #0x14
	jr	Z,00111$
	ld	a, 0 (iy)
	sub	a, #0x16
	jr	Z,00112$
	ld	a, 0 (iy)
	sub	a, #0x1e
	jr	Z,00113$
	ld	a, 0 (iy)
	sub	a, #0x1f
	jr	Z,00114$
	ld	a, 0 (iy)
	sub	a, #0x28
	jr	Z,00116$
	ld	a, 0 (iy)
	sub	a, #0x29
	jr	Z,00117$
	ld	a, 0 (iy)
	sub	a, #0x2a
	jr	Z,00115$
	ld	a, 0 (iy)
	sub	a, #0x2b
	jr	Z,00118$
	jp	00119$
;os.c:91: case STATE_START_INPUTTESTER:
00101$:
;os.c:92: start_inputtester_digital();
	call	_start_inputtester_digital
;os.c:93: break;
	jp	00120$
;os.c:94: case STATE_INPUTTESTER:
00102$:
;os.c:95: inputtester_digital();
	call	_inputtester_digital
;os.c:96: break;
	jp	00120$
;os.c:98: case STATE_START_INPUTTESTERADVANCED:
00103$:
;os.c:99: start_inputtester_advanced();
	call	_start_inputtester_advanced
;os.c:100: break;
	jp	00120$
;os.c:101: case STATE_INPUTTESTERADVANCED:
00104$:
;os.c:102: inputtester_advanced();
	call	_inputtester_advanced
;os.c:103: break;
	jr	00120$
;os.c:105: case STATE_START_INPUTTESTERANALOG:
00105$:
;os.c:106: start_inputtester_analog();
	call	_start_inputtester_analog
;os.c:107: break;
	jr	00120$
;os.c:108: case STATE_INPUTTESTERANALOG:
00106$:
;os.c:109: inputtester_analog();
	call	_inputtester_analog
;os.c:110: break;
	jr	00120$
;os.c:112: case STATE_START_BTNTEST:
00107$:
;os.c:113: start_btntest();
	call	_start_btntest
;os.c:114: break;
	jr	00120$
;os.c:115: case STATE_BTNTEST:
00108$:
;os.c:116: btntest();
	call	_btntest
;os.c:117: break;
	jr	00120$
;os.c:119: case STATE_START_MENU:
00109$:
;os.c:120: start_menu();
	call	_start_menu
;os.c:121: break;
	jr	00120$
;os.c:122: case STATE_MENU:
00110$:
;os.c:123: menu();
	call	_menu
;os.c:124: break;
	jr	00120$
;os.c:126: case STATE_FADEOUT:
00111$:
;os.c:127: fadeout();
	call	_fadeout
;os.c:128: break;
	jr	00120$
;os.c:129: case STATE_FADEIN:
00112$:
;os.c:130: fadein();
	call	_fadein
;os.c:131: break;
	jr	00120$
;os.c:133: case STATE_START_ATTRACT:
00113$:
;os.c:134: state = 0;
	ld	hl,#_state + 0
	ld	(hl), #0x00
;os.c:135: loader("SNEK.AZN");
	ld	hl, #___str_0
	push	hl
	call	_loader
	pop	af
;os.c:136: start_snek_attract();
	call	_start_snek_attract
;os.c:137: break;
	jr	00120$
;os.c:138: case STATE_ATTRACT:
00114$:
;os.c:139: snek_attract();
	call	_snek_attract
;os.c:140: break;
	jr	00120$
;os.c:141: case STATE_START_CREDITS:
00115$:
;os.c:142: app_credits();
	call	_app_credits
;os.c:143: break;
	jr	00120$
;os.c:145: case STATE_START_GAME_SNEK:
00116$:
;os.c:146: start_snek_gameplay();
	call	_start_snek_gameplay
;os.c:147: break;
	jr	00120$
;os.c:148: case STATE_GAME_SNEK:
00117$:
;os.c:149: snek_gameplay();
	call	_snek_gameplay
;os.c:150: break;
	jr	00120$
;os.c:151: case STATE_START_ZORBLAXX:
00118$:
;os.c:152: state = 0;
	ld	hl,#_state + 0
	ld	(hl), #0x00
;os.c:153: loader("ZORBLAXX.AZN");
	ld	hl, #___str_1
	push	hl
	call	_loader
	pop	af
;os.c:154: app_zorblaxx();
	call	_app_zorblaxx
;os.c:155: break;
	jr	00120$
;os.c:157: default:
00119$:
;os.c:162: loader("INPUTTESTER.AZN");
	ld	hl, #___str_2
	push	hl
	call	_loader
	pop	af
;os.c:163: start_inputtester_digital();
	call	_start_inputtester_digital
;os.c:168: }
00120$:
;os.c:170: hsync_last = hsync;
	ld	a,(#_hsync + 0)
	ld	iy, #_hsync_last
	ld	0 (iy), a
;os.c:171: vsync_last = vsync;
	ld	a,(#_vsync + 0)
	ld	iy, #_vsync_last
	ld	0 (iy), a
;os.c:172: hblank_last = hblank;
	ld	a,(#_hblank + 0)
	ld	iy, #_hblank_last
	ld	0 (iy), a
;os.c:173: vblank_last = vblank;
	ld	a,(#_vblank + 0)
	ld	iy, #_vblank_last
	ld	0 (iy), a
;os.c:175: }
	jp	00122$
___str_0:
	.ascii "SNEK.AZN"
	.db 0x00
___str_1:
	.ascii "ZORBLAXX.AZN"
	.db 0x00
___str_2:
	.ascii "INPUTTESTER.AZN"
	.db 0x00
;os.c:178: void main()
;	---------------------------------
; Function main
; ---------------------------------
_main::
;os.c:180: app_main();
;os.c:181: }
	jp	_app_main
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
