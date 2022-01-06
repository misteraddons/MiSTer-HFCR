;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.8.0 #10562 (Linux)
;--------------------------------------------------------
	.module ps2
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _kbd_buffer_len
	.globl _mse_changed
	.globl _mse_lastclock
	.globl _kbd_ascii
	.globl _kbd_scan
	.globl _kbd_shift_right
	.globl _kbd_shift_left
	.globl _kbd_lastclock
	.globl _kbd_UK
	.globl _kbd_down
	.globl _kbd_buffer
	.globl _mse_button2
	.globl _mse_button1
	.globl _mse_w
	.globl _mse_y
	.globl _mse_x
	.globl _kbd_extend
	.globl _kbd_pressed
	.globl _kbd_in
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
	.globl _KEY_DOWN
	.globl _KEY_RIGHT
	.globl _KEY_LEFT
	.globl _KEY_UP
	.globl _KEY_SPACE
	.globl _KEY_1
	.globl _KEY_CTRL
	.globl _KEY_ALT
	.globl _KEY_RIGHTSHIFT
	.globl _KEY_LEFTSHIFT
	.globl _KEY_ESC
	.globl _KEY_BACKSPACE
	.globl _KEY_ENTER
	.globl _KEY_CAPSLOCK
	.globl _KEY_TAB
	.globl _get_ascii
	.globl _handle_ps2
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
_kbd_in::
	.ds 2
_kbd_pressed::
	.ds 1
_kbd_extend::
	.ds 1
_mse_x::
	.ds 1
_mse_y::
	.ds 1
_mse_w::
	.ds 1
_mse_button1::
	.ds 1
_mse_button2::
	.ds 1
_kbd_buffer::
	.ds 128
_kbd_down::
	.ds 256
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
_kbd_UK::
	.ds 256
_kbd_lastclock::
	.ds 1
_kbd_shift_left::
	.ds 1
_kbd_shift_right::
	.ds 1
_kbd_scan::
	.ds 1
_kbd_ascii::
	.ds 1
_mse_lastclock::
	.ds 1
_mse_changed::
	.ds 1
_kbd_buffer_len::
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
;ps2.c:174: void get_ascii()
;	---------------------------------
; Function get_ascii
; ---------------------------------
_get_ascii::
;ps2.c:176: char p = (kbd_scan * 2);
	ld	a,(#_kbd_scan + 0)
	add	a, a
	ld	e, a
;ps2.c:177: if (!(kbd_shift_left || kbd_shift_right))
	ld	a,(#_kbd_shift_left + 0)
	or	a, a
	jr	NZ,00102$
	ld	a,(#_kbd_shift_right + 0)
	or	a, a
	jr	NZ,00102$
;ps2.c:179: p++;
	inc	e
00102$:
;ps2.c:181: kbd_ascii = kbd_UK[p];
	ld	hl, #_kbd_UK+0
	ld	d, #0x00
	add	hl, de
	ld	a, (hl)
	ld	iy, #_kbd_ascii
	ld	0 (iy), a
;ps2.c:182: if (kbd_ascii > 0)
	ld	a, 0 (iy)
	or	a, a
	ret	Z
;ps2.c:184: kbd_buffer[kbd_buffer_len] = kbd_ascii;
	ld	bc, #_kbd_buffer+0
	ld	hl, (_kbd_buffer_len)
	ld	h, #0x00
	add	hl, bc
	ld	a, 0 (iy)
	ld	(hl), a
;ps2.c:185: kbd_buffer_len++;
	ld	hl, #_kbd_buffer_len+0
	inc	(hl)
;ps2.c:187: }
	ret
_KEY_TAB:
	.db #0x0d	; 13
_KEY_CAPSLOCK:
	.db #0x58	; 88	'X'
_KEY_ENTER:
	.db #0x5a	; 90	'Z'
_KEY_BACKSPACE:
	.db #0x66	; 102	'f'
_KEY_ESC:
	.db #0x76	; 118	'v'
_KEY_LEFTSHIFT:
	.db #0x12	; 18
_KEY_RIGHTSHIFT:
	.db #0x59	; 89	'Y'
_KEY_ALT:
	.db #0x11	; 17
_KEY_CTRL:
	.db #0x63	; 99	'c'
_KEY_1:
	.db #0x16	; 22
_KEY_SPACE:
	.db #0x29	; 41
_KEY_UP:
	.db #0x75	; 117	'u'
_KEY_LEFT:
	.db #0x6b	; 107	'k'
_KEY_RIGHT:
	.db #0x74	; 116	't'
_KEY_DOWN:
	.db #0x72	; 114	'r'
;ps2.c:189: void handle_ps2()
;	---------------------------------
; Function handle_ps2
; ---------------------------------
_handle_ps2::
	push	ix
	ld	ix,#0
	add	ix,sp
	dec	sp
;ps2.c:191: bool kbd_clock = CHECK_BIT(ps2_key[1], 2);
	ld	a, (#(_ps2_key + 0x0001) + 0)
	and	a, #0x04
	ld	c, a
	xor	a, a
	cp	a, c
	rla
;ps2.c:192: if (kbd_clock != kbd_lastclock)
	ld	-1 (ix), a
	ld	c, a
	ld	a,(#_kbd_lastclock + 0)
	sub	a, c
	jp	Z,00118$
;ps2.c:194: for (char k = 0; k < 2; k++)
	ld	c, #0x00
00122$:
	ld	a, c
	sub	a, #0x02
	jr	NC,00101$
;ps2.c:196: kbd_in[k] = ps2_key[k];
	ld	a, #<(_kbd_in)
	add	a, c
	ld	e, a
	ld	a, #>(_kbd_in)
	adc	a, #0x00
	ld	d, a
	ld	hl, #_ps2_key
	ld	b, #0x00
	add	hl, bc
	ld	a, (hl)
	ld	(de), a
;ps2.c:194: for (char k = 0; k < 2; k++)
	inc	c
	jr	00122$
00101$:
;ps2.c:198: kbd_extend = CHECK_BIT(kbd_in[1], 0) > 0;
	ld	hl, #_kbd_in + 1
	ld	c, (hl)
	bit	0, c
	jr	Z,00126$
	ld	de, #0x0001
	jr	00127$
00126$:
	ld	de, #0x0000
00127$:
	ld	hl,#_kbd_extend + 0
	ld	(hl), e
;ps2.c:199: kbd_pressed = CHECK_BIT(kbd_in[1], 1) > 0;
	bit	1, c
	jr	Z,00128$
	ld	bc, #0x0001
	jr	00129$
00128$:
	ld	bc, #0x0000
00129$:
	ld	hl,#_kbd_pressed + 0
	ld	(hl), c
;ps2.c:200: kbd_scan = kbd_in[0];
	ld	a,(#_kbd_in + 0)
	ld	(#_kbd_scan + 0),a
;ps2.c:201: kbd_ascii = 0;
	ld	hl,#_kbd_ascii + 0
	ld	(hl), #0x00
;ps2.c:202: if (kbd_pressed)
	ld	a,(#_kbd_pressed + 0)
	or	a, a
	jr	Z,00115$
;ps2.c:204: kbd_down[kbd_scan] = 1;
	ld	bc, #_kbd_down+0
	ld	hl, (_kbd_scan)
	ld	h, #0x00
	add	hl, bc
	ld	(hl), #0x01
;ps2.c:205: if (kbd_scan == KEY_LEFTSHIFT)
	ld	hl,#_KEY_LEFTSHIFT + 0
	ld	c, (hl)
	ld	a,(#_kbd_scan + 0)
	sub	a, c
	jr	NZ,00106$
;ps2.c:207: kbd_shift_left = 1;
	ld	hl,#_kbd_shift_left + 0
	ld	(hl), #0x01
	jr	00118$
00106$:
;ps2.c:209: else if (kbd_scan == KEY_RIGHTSHIFT)
	ld	hl,#_KEY_RIGHTSHIFT + 0
	ld	c, (hl)
	ld	a,(#_kbd_scan + 0)
	sub	a, c
	jr	NZ,00103$
;ps2.c:211: kbd_shift_right = 1;
	ld	hl,#_kbd_shift_right + 0
	ld	(hl), #0x01
	jr	00118$
00103$:
;ps2.c:215: get_ascii();
	call	_get_ascii
	jr	00118$
00115$:
;ps2.c:220: kbd_down[kbd_scan] = 0;
	ld	bc, #_kbd_down+0
	ld	hl, (_kbd_scan)
	ld	h, #0x00
	add	hl, bc
	ld	(hl), #0x00
;ps2.c:221: if (kbd_scan == KEY_LEFTSHIFT)
	ld	hl,#_KEY_LEFTSHIFT + 0
	ld	c, (hl)
	ld	a,(#_kbd_scan + 0)
	sub	a, c
	jr	NZ,00112$
;ps2.c:223: kbd_shift_left = 0;
	ld	hl,#_kbd_shift_left + 0
	ld	(hl), #0x00
	jr	00118$
00112$:
;ps2.c:225: else if (kbd_scan == KEY_RIGHTSHIFT)
	ld	hl,#_KEY_RIGHTSHIFT + 0
	ld	c, (hl)
	ld	a,(#_kbd_scan + 0)
	sub	a, c
	jr	NZ,00109$
;ps2.c:227: kbd_shift_right = 0;
	ld	hl,#_kbd_shift_right + 0
	ld	(hl), #0x00
	jr	00118$
00109$:
;ps2.c:231: get_ascii();
	call	_get_ascii
00118$:
;ps2.c:235: kbd_lastclock = kbd_clock;
	ld	a, -1 (ix)
	ld	(#_kbd_lastclock + 0),a
;ps2.c:237: bool mse_clock = CHECK_BIT(ps2_mouse[3], 0);
	ld	a, (#(_ps2_mouse + 0x0003) + 0)
	and	a, #0x01
	ld	c, a
;ps2.c:238: if (mse_clock != mse_lastclock)
	ld	b, c
	ld	hl,#_mse_lastclock + 0
	ld	e, (hl)
	ld	a, b
	sub	a, e
	jr	Z,00120$
;ps2.c:240: mse_changed = 1;
	ld	hl,#_mse_changed + 0
	ld	(hl), #0x01
;ps2.c:241: mse_button1 = ps2_mouse[0];
	ld	a, (#_ps2_mouse+0)
	ld	(#_mse_button1 + 0),a
;ps2.c:242: mse_button2 = ps2_mouse[5];
	ld	a, (#_ps2_mouse+5)
	ld	(#_mse_button2 + 0),a
;ps2.c:243: mse_x = ps2_mouse[1];
	ld	a, (#_ps2_mouse+1)
	ld	(#_mse_x + 0),a
;ps2.c:244: mse_y = ps2_mouse[2];
	ld	a, (#_ps2_mouse+2)
	ld	(#_mse_y + 0),a
;ps2.c:245: mse_w = ps2_mouse[4];
	ld	a, (#_ps2_mouse+4)
	ld	(#_mse_w + 0),a
00120$:
;ps2.c:247: mse_lastclock = mse_clock;
	ld	hl,#_mse_lastclock + 0
	ld	(hl), c
;ps2.c:248: }
	inc	sp
	pop	ix
	ret
	.area _CODE
	.area _INITIALIZER
__xinit__kbd_UK:
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0xc2	; 194
	.db #0x60	; 96
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x51	; 81	'Q'
	.db #0x71	; 113	'q'
	.db #0x21	; 33
	.db #0x31	; 49	'1'
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x5a	; 90	'Z'
	.db #0x7a	; 122	'z'
	.db #0x53	; 83	'S'
	.db #0x73	; 115	's'
	.db #0x41	; 65	'A'
	.db #0x61	; 97	'a'
	.db #0x57	; 87	'W'
	.db #0x77	; 119	'w'
	.db #0x22	; 34
	.db #0x32	; 50	'2'
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x43	; 67	'C'
	.db #0x63	; 99	'c'
	.db #0x58	; 88	'X'
	.db #0x78	; 120	'x'
	.db #0x44	; 68	'D'
	.db #0x64	; 100	'd'
	.db #0x45	; 69	'E'
	.db #0x65	; 101	'e'
	.db #0x24	; 36
	.db #0x34	; 52	'4'
	.db #0xc2	; 194
	.db #0x33	; 51	'3'
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x20	; 32
	.db #0x20	; 32
	.db #0x56	; 86	'V'
	.db #0x76	; 118	'v'
	.db #0x46	; 70	'F'
	.db #0x66	; 102	'f'
	.db #0x54	; 84	'T'
	.db #0x74	; 116	't'
	.db #0x52	; 82	'R'
	.db #0x72	; 114	'r'
	.db #0x25	; 37
	.db #0x35	; 53	'5'
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x4e	; 78	'N'
	.db #0x6e	; 110	'n'
	.db #0x42	; 66	'B'
	.db #0x62	; 98	'b'
	.db #0x48	; 72	'H'
	.db #0x68	; 104	'h'
	.db #0x47	; 71	'G'
	.db #0x67	; 103	'g'
	.db #0x59	; 89	'Y'
	.db #0x79	; 121	'y'
	.db #0x5e	; 94
	.db #0x36	; 54	'6'
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x4d	; 77	'M'
	.db #0x6d	; 109	'm'
	.db #0x4a	; 74	'J'
	.db #0x6a	; 106	'j'
	.db #0x55	; 85	'U'
	.db #0x75	; 117	'u'
	.db #0x26	; 38
	.db #0x37	; 55	'7'
	.db #0x2a	; 42
	.db #0x38	; 56	'8'
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x3c	; 60
	.db #0x2c	; 44
	.db #0x4b	; 75	'K'
	.db #0x6b	; 107	'k'
	.db #0x49	; 73	'I'
	.db #0x69	; 105	'i'
	.db #0x4f	; 79	'O'
	.db #0x6f	; 111	'o'
	.db #0x29	; 41
	.db #0x30	; 48	'0'
	.db #0x28	; 40
	.db #0x39	; 57	'9'
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x3e	; 62
	.db #0x2e	; 46
	.db #0x3f	; 63
	.db #0x2f	; 47
	.db #0x4c	; 76	'L'
	.db #0x6c	; 108	'l'
	.db #0x3a	; 58
	.db #0x3b	; 59
	.db #0x50	; 80	'P'
	.db #0x70	; 112	'p'
	.db #0x5f	; 95
	.db #0x2d	; 45
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x40	; 64
	.db #0x27	; 39
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x7b	; 123
	.db #0x5b	; 91
	.db #0x2b	; 43
	.db #0x3d	; 61
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x2b	; 43
	.db #0x3d	; 61
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x0a	; 10
	.db #0x0a	; 10
	.db #0x7d	; 125
	.db #0x5d	; 93
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x7c	; 124
	.db #0x5c	; 92
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x00	; 0
	.db #0x08	; 8
	.db #0x08	; 8
	.db #0x00	; 0
	.db #0x00	; 0
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
__xinit__kbd_lastclock:
	.db #0x00	; 0
__xinit__kbd_shift_left:
	.db #0x00	; 0
__xinit__kbd_shift_right:
	.db #0x00	; 0
__xinit__kbd_scan:
	.db #0x00	; 0
__xinit__kbd_ascii:
	.db #0x00	; 0
__xinit__mse_lastclock:
	.db #0x00	; 0
__xinit__mse_changed:
	.db #0x01	;  1
__xinit__kbd_buffer_len:
	.db #0x00	; 0
	.area _CABS (ABS)
