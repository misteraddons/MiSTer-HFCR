;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.8.0 #10562 (Linux)
;--------------------------------------------------------
	.module os
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _app_main
	.globl _loader
	.globl _intro_text
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
	.globl _set_sound_volume
	.globl _play_sound
	.globl _clear_sprites
	.globl _update_sprites
	.globl _write_char
	.globl _clear_bgcolor
	.globl _clear_char_area
	.globl _clear_chars
	.globl _strlen
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
;os.c:37: void intro_text(const char *text, unsigned char start_x, unsigned char start_y, unsigned char space_x, unsigned char speed, unsigned char flash_speed)
;	---------------------------------
; Function intro_text
; ---------------------------------
_intro_text::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	hl, #-6
	add	hl, sp
	ld	sp, hl
;os.c:39: unsigned char text_timer = 0;
	ld	c, #0x00
;os.c:41: unsigned char text_flash = 0;
	ld	e, #0x00
;os.c:42: unsigned char text_flash_timer = 0;
	ld	-2 (ix), #0x00
;os.c:43: unsigned char text_char_count = strlen(text);
	push	bc
	ld	l, 4 (ix)
	ld	h, 5 (ix)
	push	hl
	call	_strlen
	pop	af
	pop	bc
	ld	-3 (ix), l
;os.c:46: if (CHECK_BIT(input0, 0))
	ld	hl,#_input0+0
	bit	0, (hl)
	jr	Z,00131$
;os.c:48: speed = 1;
	ld	9 (ix), #0x01
;os.c:49: flash_speed = 1;
	ld	10 (ix), #0x01
;os.c:52: while (1)
00131$:
	ld	-1 (ix), #0x01
00119$:
;os.c:54: vblank = CHECK_BIT(input0, INPUT_VBLANK);
	ld	a,(#_input0 + 0)
	and	a, #0x10
	ld	b, a
	xor	a, a
	cp	a, b
	rla
	ld	iy, #_vblank
	ld	0 (iy), a
;os.c:57: if (VBLANK_RISING)
	bit	0, 0 (iy)
	jp	Z, 00116$
	ld	hl,#_vblank_last+0
	bit	0, (hl)
	jp	NZ, 00116$
;os.c:59: unsigned char xpos = start_x + ((text_length - 1) * space_x);
	ld	h, -1 (ix)
	dec	h
	push	de
	ld	e, 8 (ix)
	ld	l, #0x00
	ld	d, l
	ld	b, #0x08
00170$:
	add	hl, hl
	jr	NC,00171$
	add	hl, de
00171$:
	djnz	00170$
	pop	de
	ld	a, 6 (ix)
	add	a, l
	ld	-4 (ix), a
;os.c:60: text_timer++;
	inc	c
;os.c:63: write_char(text[text_length - 1], 0xFF, xpos, start_y);
	ld	b, -1 (ix)
	ld	h, #0x00
	ld	l, b
	dec	hl
	ld	b, l
	ld	d, h
	ld	a, 4 (ix)
	add	a, b
	ld	-6 (ix), a
	ld	a, 5 (ix)
	adc	a, d
	ld	-5 (ix), a
;os.c:61: if (text_timer == speed)
	ld	a, 9 (ix)
	sub	a, c
	jr	NZ,00113$
;os.c:63: write_char(text[text_length - 1], 0xFF, xpos, start_y);
	pop	hl
	push	hl
	ld	b, (hl)
	push	de
	ld	a, 7 (ix)
	push	af
	inc	sp
	ld	d, -4 (ix)
	ld	e,#0xff
	push	de
	push	bc
	inc	sp
	call	_write_char
	pop	af
	pop	af
	pop	de
;os.c:64: text_length++;
	inc	-1 (ix)
;os.c:65: if (text_length > text_char_count)
	ld	a, -3 (ix)
	sub	a, -1 (ix)
	jr	C,00121$
;os.c:69: text_timer = 0;
	ld	c, #0x00
;os.c:70: text_flash_timer = 0;
	ld	-2 (ix), #0x00
	jr	00116$
00113$:
;os.c:74: text_flash_timer++;
	inc	-2 (ix)
;os.c:75: if (text_flash_timer == flash_speed)
	ld	a, 10 (ix)
	sub	a, -2 (ix)
	jr	NZ,00116$
;os.c:77: text_flash++;
	inc	e
;os.c:78: if (text_flash == 2)
	ld	a, e
;os.c:80: text_flash = 0;
	sub	a,#0x02
	jr	NZ,00106$
	ld	e,a
00106$:
;os.c:82: if (text_flash == 1)
	ld	a, e
	dec	a
	jr	NZ,00108$
;os.c:84: write_char(0, 0, xpos, start_y);
	push	bc
	push	de
	ld	h, 7 (ix)
	ld	l, -4 (ix)
	push	hl
	xor	a, a
	push	af
	inc	sp
	xor	a, a
	push	af
	inc	sp
	call	_write_char
	pop	af
	pop	af
	pop	de
	pop	bc
	jr	00109$
00108$:
;os.c:88: write_char(text[text_length - 1], 0xFF, xpos, start_y);
	pop	hl
	push	hl
	ld	b, (hl)
	push	bc
	push	de
	ld	a, 7 (ix)
	push	af
	inc	sp
	ld	d, -4 (ix)
	ld	e,#0xff
	push	de
	push	bc
	inc	sp
	call	_write_char
	pop	af
	pop	af
	pop	de
	pop	bc
00109$:
;os.c:90: text_flash_timer = 0;
	ld	-2 (ix), #0x00
00116$:
;os.c:94: vblank_last = vblank;
	ld	a,(#_vblank + 0)
	ld	(#_vblank_last + 0),a
	jp	00119$
00121$:
;os.c:96: }
	ld	sp, ix
	pop	ix
	ret
;os.c:98: void loader(const char *title)
;	---------------------------------
; Function loader
; ---------------------------------
_loader::
;os.c:101: set_sound_volume(255);
	ld	a, #0xff
	push	af
	inc	sp
	call	_set_sound_volume
	inc	sp
;os.c:102: play_sound(const_sound_newtype);
	ld	a, #0x03
	push	af
	inc	sp
	call	_play_sound
	inc	sp
;os.c:105: chram_size = chram_cols * chram_rows;
	ld	hl,#_chram_rows + 0
	ld	e, (hl)
	ld	hl,#_chram_cols + 0
	ld	h, (hl)
	ld	l, #0x00
	ld	d, l
	ld	b, #0x08
00118$:
	add	hl, hl
	jr	NC,00119$
	add	hl, de
00119$:
	djnz	00118$
	ld	(_chram_size), hl
;os.c:107: clear_bgcolor(0);
	xor	a, a
	push	af
	inc	sp
	call	_clear_bgcolor
	inc	sp
;os.c:108: clear_chars(0);
	xor	a, a
	push	af
	inc	sp
	call	_clear_chars
	inc	sp
;os.c:110: clear_sprites();
	call	_clear_sprites
;os.c:111: update_sprites();
	call	_update_sprites
;os.c:113: for (unsigned char s = 0; s < 6; s++)
	ld	c, #0x00
00103$:
	ld	a, c
	sub	a, #0x06
	jr	NC,00101$
;os.c:115: starfield[s] = 0;
	ld	de, #_starfield+0
	ld	l, c
	ld	h, #0x00
	add	hl, de
	ld	(hl), #0x00
;os.c:113: for (unsigned char s = 0; s < 6; s++)
	inc	c
	jr	00103$
00101$:
;os.c:118: const char *system_title = "AZNABLE";
;os.c:121: write_char('>', 0xFF, 0, 1);
	ld	a, #0x01
	push	af
	inc	sp
	xor	a, a
	ld	d,a
	ld	e,#0xff
	push	de
	ld	a, #0x3e
	push	af
	inc	sp
	call	_write_char
	pop	af
	pop	af
;os.c:122: intro_text(system_title, 2, 1, 2, 8, 1);
	ld	de, #0x0108
	push	de
	ld	de, #0x0201
	push	de
	ld	a, #0x02
	push	af
	inc	sp
	ld	hl, #___str_0
	push	hl
	call	_intro_text
	ld	hl, #7
	add	hl, sp
	ld	sp, hl
;os.c:123: write_char(' ', 0xFF, 0, 1);
	ld	a, #0x01
	push	af
	inc	sp
	xor	a, a
	ld	d,a
	ld	e,#0xff
	push	de
	ld	a, #0x20
	push	af
	inc	sp
	call	_write_char
	pop	af
;os.c:125: write_char('>', 0xFF, 0, 3);
	ld	h,#0x03
	ex	(sp),hl
	inc	sp
	xor	a, a
	ld	d,a
	ld	e,#0xff
	push	de
	ld	a, #0x3e
	push	af
	inc	sp
	call	_write_char
	pop	af
	pop	af
;os.c:126: intro_text("LOAD ", 2, 3, 1, 4, 1);
	ld	de, #0x0104
	push	de
	ld	de, #0x0103
	push	de
	ld	a, #0x02
	push	af
	inc	sp
	ld	hl, #___str_1
	push	hl
	call	_intro_text
	ld	hl, #7
	add	hl, sp
	ld	sp, hl
;os.c:127: intro_text(title, 7, 3, 1, 4, 1);
	ld	de, #0x0104
	push	de
	ld	de, #0x0103
	push	de
	ld	a, #0x07
	push	af
	inc	sp
	ld	hl, #7
	add	hl, sp
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	push	bc
	call	_intro_text
	ld	hl, #7
	add	hl, sp
	ld	sp, hl
;os.c:128: write_char(' ', 0xFF, 0, 3);
	ld	a, #0x03
	push	af
	inc	sp
	xor	a, a
	ld	d,a
	ld	e,#0xff
	push	de
	ld	a, #0x20
	push	af
	inc	sp
	call	_write_char
	pop	af
;os.c:130: write_char('>', 0xFF, 0, 5);
	ld	h,#0x05
	ex	(sp),hl
	inc	sp
	xor	a, a
	ld	d,a
	ld	e,#0xff
	push	de
	ld	a, #0x3e
	push	af
	inc	sp
	call	_write_char
	pop	af
	pop	af
;os.c:131: intro_text("...", 2, 5, 1, 8, 1);
	ld	de, #0x0108
	push	de
	ld	de, #0x0105
	push	de
	ld	a, #0x02
	push	af
	inc	sp
	ld	hl, #___str_2
	push	hl
	call	_intro_text
	ld	hl, #7
	add	hl, sp
	ld	sp, hl
;os.c:134: clear_char_area(0, 1, 1, 40, 3);
	ld	de, #0x0328
	push	de
	ld	de, #0x0101
	push	de
	xor	a, a
	push	af
	inc	sp
	call	_clear_char_area
	pop	af
	pop	af
	inc	sp
;os.c:135: }
	ret
___str_0:
	.ascii "AZNABLE"
	.db 0x00
___str_1:
	.ascii "LOAD "
	.db 0x00
___str_2:
	.ascii "..."
	.db 0x00
;os.c:138: void app_main()
;	---------------------------------
; Function app_main
; ---------------------------------
_app_main::
;os.c:140: chram_size = chram_cols * chram_rows;
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
;os.c:141: state = defaultstate;
	ld	a,(#_defaultstate + 0)
	ld	(#_state + 0),a
;os.c:142: while (1)
00122$:
;os.c:144: hsync = input0 & 0x80;
	ld	a,(#_input0 + 0)
	rlc	a
	and	a, #0x01
	ld	(#_hsync + 0),a
;os.c:145: vsync = input0 & 0x40;
	ld	a,(#_input0 + 0)
	and	a, #0x40
	or	a,#0x00
	add	a, #0xff
	ld	a, #0x00
	rla
	ld	(#_vsync + 0),a
;os.c:146: hblank = input0 & 0x20;
	ld	a,(#_input0 + 0)
	and	a, #0x20
	or	a,#0x00
	add	a, #0xff
	ld	a, #0x00
	rla
	ld	(#_hblank + 0),a
;os.c:147: vblank = CHECK_BIT(input0, INPUT_VBLANK);
	ld	a,(#_input0 + 0)
	and	a, #0x10
	ld	c, a
	xor	a, a
	cp	a, c
	rla
	ld	(#_vblank + 0),a
;os.c:148: switch (state)
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
;os.c:150: case STATE_START_INPUTTESTER:
00101$:
;os.c:151: start_inputtester_digital();
	call	_start_inputtester_digital
;os.c:152: break;
	jp	00120$
;os.c:153: case STATE_INPUTTESTER:
00102$:
;os.c:154: inputtester_digital();
	call	_inputtester_digital
;os.c:155: break;
	jp	00120$
;os.c:157: case STATE_START_INPUTTESTERADVANCED:
00103$:
;os.c:158: start_inputtester_advanced();
	call	_start_inputtester_advanced
;os.c:159: break;
	jp	00120$
;os.c:160: case STATE_INPUTTESTERADVANCED:
00104$:
;os.c:161: inputtester_advanced();
	call	_inputtester_advanced
;os.c:162: break;
	jr	00120$
;os.c:164: case STATE_START_INPUTTESTERANALOG:
00105$:
;os.c:165: start_inputtester_analog();
	call	_start_inputtester_analog
;os.c:166: break;
	jr	00120$
;os.c:167: case STATE_INPUTTESTERANALOG:
00106$:
;os.c:168: inputtester_analog();
	call	_inputtester_analog
;os.c:169: break;
	jr	00120$
;os.c:171: case STATE_START_BTNTEST:
00107$:
;os.c:172: start_btntest();
	call	_start_btntest
;os.c:173: break;
	jr	00120$
;os.c:174: case STATE_BTNTEST:
00108$:
;os.c:175: btntest();
	call	_btntest
;os.c:176: break;
	jr	00120$
;os.c:178: case STATE_START_MENU:
00109$:
;os.c:179: start_menu();
	call	_start_menu
;os.c:180: break;
	jr	00120$
;os.c:181: case STATE_MENU:
00110$:
;os.c:182: menu();
	call	_menu
;os.c:183: break;
	jr	00120$
;os.c:185: case STATE_FADEOUT:
00111$:
;os.c:186: fadeout();
	call	_fadeout
;os.c:187: break;
	jr	00120$
;os.c:188: case STATE_FADEIN:
00112$:
;os.c:189: fadein();
	call	_fadein
;os.c:190: break;
	jr	00120$
;os.c:192: case STATE_START_ATTRACT:
00113$:
;os.c:193: state = 0;
	ld	hl,#_state + 0
	ld	(hl), #0x00
;os.c:194: loader("SNEK.AZN");
	ld	hl, #___str_3
	push	hl
	call	_loader
	pop	af
;os.c:195: start_snek_attract();
	call	_start_snek_attract
;os.c:196: break;
	jr	00120$
;os.c:197: case STATE_ATTRACT:
00114$:
;os.c:198: snek_attract();
	call	_snek_attract
;os.c:199: break;
	jr	00120$
;os.c:200: case STATE_START_CREDITS:
00115$:
;os.c:201: app_credits();
	call	_app_credits
;os.c:202: break;
	jr	00120$
;os.c:204: case STATE_START_GAME_SNEK:
00116$:
;os.c:205: start_snek_gameplay();
	call	_start_snek_gameplay
;os.c:206: break;
	jr	00120$
;os.c:207: case STATE_GAME_SNEK:
00117$:
;os.c:208: snek_gameplay();
	call	_snek_gameplay
;os.c:209: break;
	jr	00120$
;os.c:210: case STATE_START_ZORBLAXX:
00118$:
;os.c:211: state = 0;
	ld	hl,#_state + 0
	ld	(hl), #0x00
;os.c:212: loader("ZORBLAXX.AZN");
	ld	hl, #___str_4
	push	hl
	call	_loader
	pop	af
;os.c:213: app_zorblaxx();
	call	_app_zorblaxx
;os.c:214: break;
	jr	00120$
;os.c:216: default:
00119$:
;os.c:219: loader("INPUTTESTER.AZN");
	ld	hl, #___str_5
	push	hl
	call	_loader
	pop	af
;os.c:220: start_inputtester_digital();
	call	_start_inputtester_digital
;os.c:225: }
00120$:
;os.c:227: hsync_last = hsync;
	ld	a,(#_hsync + 0)
	ld	(#_hsync_last + 0),a
;os.c:228: vsync_last = vsync;
	ld	a,(#_vsync + 0)
	ld	(#_vsync_last + 0),a
;os.c:229: hblank_last = hblank;
	ld	a,(#_hblank + 0)
	ld	(#_hblank_last + 0),a
;os.c:230: vblank_last = vblank;
	ld	a,(#_vblank + 0)
	ld	(#_vblank_last + 0),a
;os.c:232: }
	jp	00122$
___str_3:
	.ascii "SNEK.AZN"
	.db 0x00
___str_4:
	.ascii "ZORBLAXX.AZN"
	.db 0x00
___str_5:
	.ascii "INPUTTESTER.AZN"
	.db 0x00
;os.c:235: void main()
;	---------------------------------
; Function main
; ---------------------------------
_main::
;os.c:237: app_main();
;os.c:238: }
	jp  _app_main
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
