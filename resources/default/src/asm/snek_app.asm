;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.8.0 #10562 (Linux)
;--------------------------------------------------------
	.module snek_app
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _start_fadeout
	.globl _page_border
	.globl _write_char
	.globl _write_string
	.globl _clear_chars
	.globl _sprintf
	.globl _attractstate
	.globl _length
	.globl _nyd
	.globl _nxd
	.globl _yd
	.globl _xd
	.globl _y
	.globl _x
	.globl _movetimer
	.globl _movefreq
	.globl _movefreqdectimer
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
	.globl _start_snek_attract
	.globl _start_snek_gameplay
	.globl _snek_gameplay
	.globl _snek_attract
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
_movefreqdectimer::
	.ds 1
_movefreq::
	.ds 1
_movetimer::
	.ds 1
_x::
	.ds 2
_y::
	.ds 2
_xd::
	.ds 1
_yd::
	.ds 1
_nxd::
	.ds 1
_nyd::
	.ds 1
_length::
	.ds 2
_attractstate::
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
;snek_app.c:44: void start_snek_attract()
;	---------------------------------
; Function start_snek_attract
; ---------------------------------
_start_snek_attract::
;snek_app.c:46: state = STATE_ATTRACT;
	ld	hl,#_state + 0
	ld	(hl), #0x1f
;snek_app.c:47: attractstate = 0;
	ld	hl,#_attractstate + 0
	ld	(hl), #0x00
;snek_app.c:48: clear_chars(0);
	xor	a, a
	push	af
	inc	sp
	call	_clear_chars
	inc	sp
;snek_app.c:49: page_border(0b00000111);
	ld	a, #0x07
	push	af
	inc	sp
	call	_page_border
	inc	sp
;snek_app.c:50: write_string("SNEK", 0b00000111, 18, 0);
	xor	a, a
	ld	d,a
	ld	e,#0x12
	push	de
	ld	a, #0x07
	push	af
	inc	sp
	ld	hl, #___str_0
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;snek_app.c:51: movefreq = 5;
	ld	hl,#_movefreq + 0
	ld	(hl), #0x05
;snek_app.c:52: movetimer = 1;
	ld	hl,#_movetimer + 0
	ld	(hl), #0x01
;snek_app.c:53: }
	ret
___str_0:
	.ascii "SNEK"
	.db 0x00
;snek_app.c:56: void start_snek_gameplay()
;	---------------------------------
; Function start_snek_gameplay
; ---------------------------------
_start_snek_gameplay::
;snek_app.c:58: state = STATE_GAME_SNEK;
	ld	hl,#_state + 0
	ld	(hl), #0x29
;snek_app.c:59: length = 0;
	ld	hl, #0x0000
	ld	(_length), hl
;snek_app.c:60: x = 20;
	ld	l, #0x14
	ld	(_x), hl
;snek_app.c:61: y = 15;
	ld	l, #0x0f
	ld	(_y), hl
;snek_app.c:62: xd = 0;
	ld	hl,#_xd + 0
	ld	(hl), #0x00
;snek_app.c:63: yd = 1;
	ld	hl,#_yd + 0
	ld	(hl), #0x01
;snek_app.c:64: nxd = 0;
	ld	hl,#_nxd + 0
	ld	(hl), #0x00
;snek_app.c:65: nyd = 1;
	ld	hl,#_nyd + 0
	ld	(hl), #0x01
;snek_app.c:66: clear_chars(0);
	xor	a, a
	push	af
	inc	sp
	call	_clear_chars
	inc	sp
;snek_app.c:67: page_border(0b00000111);
	ld	a, #0x07
	push	af
	inc	sp
	call	_page_border
	inc	sp
;snek_app.c:68: write_string("SNEK", 0b00000111, 18, 0);
	xor	a, a
	ld	d,a
	ld	e,#0x12
	push	de
	ld	a, #0x07
	push	af
	inc	sp
	ld	hl, #___str_1
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;snek_app.c:69: write_char(playerchar, 0xFF, x, y);
	ld	hl,#_y + 0
	ld	b, (hl)
	ld	hl,#_x + 0
	ld	c, (hl)
	push	bc
	ld	de, #0xff53
	push	de
	call	_write_char
	pop	af
	pop	af
;snek_app.c:71: movefreq = movefreqinit;
	ld	hl,#_movefreq + 0
	ld	(hl), #0x0e
;snek_app.c:72: movefreqdectimer = movefreqdecfreq;
	ld	hl,#_movefreqdectimer + 0
	ld	(hl), #0xc8
;snek_app.c:73: movetimer = movefreq;
	ld	hl,#_movetimer + 0
	ld	(hl), #0x0e
;snek_app.c:74: }
	ret
___str_1:
	.ascii "SNEK"
	.db 0x00
;snek_app.c:77: void snek_gameplay()
;	---------------------------------
; Function snek_gameplay
; ---------------------------------
_snek_gameplay::
	push	ix
	ld	ix,#0
	add	ix,sp
	push	af
	push	af
	dec	sp
;snek_app.c:80: if (HBLANK_RISING)
	ld	hl,#_hblank+0
	bit	0, (hl)
	jr	Z,00116$
	ld	hl,#_hblank_last+0
	bit	0, (hl)
	jr	NZ,00116$
;snek_app.c:82: if (yd != 1 && joystick[0] & 0b00001000) // up
	ld	a,(#_yd + 0)
	dec	a
	jr	Z,00102$
	ld	a, (#_joystick + 0)
	bit	3, a
	jr	Z,00102$
;snek_app.c:84: nyd = -1;
	ld	hl,#_nyd + 0
	ld	(hl), #0xff
;snek_app.c:85: nxd = 0;
	ld	hl,#_nxd + 0
	ld	(hl), #0x00
00102$:
;snek_app.c:87: if (yd != -1 && joystick[0] & 0b00000100) // down
	ld	a,(#_yd + 0)
	inc	a
	jr	Z,00105$
	ld	a, (#_joystick + 0)
	bit	2, a
	jr	Z,00105$
;snek_app.c:89: nyd = 1;
	ld	hl,#_nyd + 0
	ld	(hl), #0x01
;snek_app.c:90: nxd = 0;
	ld	hl,#_nxd + 0
	ld	(hl), #0x00
00105$:
;snek_app.c:92: if (xd != 1 && joystick[0] & 0b00000010) // left
	ld	a,(#_xd + 0)
	dec	a
	jr	Z,00108$
	ld	a, (#_joystick + 0)
	bit	1, a
	jr	Z,00108$
;snek_app.c:94: nxd = -1;
	ld	hl,#_nxd + 0
	ld	(hl), #0xff
;snek_app.c:95: nyd = 0;
	ld	hl,#_nyd + 0
	ld	(hl), #0x00
00108$:
;snek_app.c:97: if (xd != -1 && joystick[0] & 0b00000001) //right
	ld	a,(#_xd + 0)
	inc	a
	jr	Z,00111$
	ld	a, (#_joystick + 0)
	rrca
	jr	NC,00111$
;snek_app.c:99: nxd = 1;
	ld	hl,#_nxd + 0
	ld	(hl), #0x01
;snek_app.c:100: nyd = 0;
	ld	hl,#_nyd + 0
	ld	(hl), #0x00
00111$:
;snek_app.c:103: if (CHECK_BIT(joystick[1], 2)) // select to quit
	ld	a, (#(_joystick + 0x0001) + 0)
	bit	2, a
	jr	Z,00116$
;snek_app.c:105: state = 0;
	ld	hl,#_state + 0
	ld	(hl), #0x00
;snek_app.c:106: return;
	jp	00129$
00116$:
;snek_app.c:110: if (VBLANK_RISING)
	ld	hl,#_vblank+0
	bit	0, (hl)
	jp	Z, 00129$
	ld	hl,#_vblank_last+0
	bit	0, (hl)
	jp	NZ, 00129$
;snek_app.c:112: movetimer--;
	ld	iy, #_movetimer
	dec	0 (iy)
;snek_app.c:113: if (movetimer == 0)
	ld	a, 0 (iy)
	or	a, a
	jp	NZ, 00121$
;snek_app.c:115: write_char(127, 0x66, x, y);
	ld	hl,#_y + 0
	ld	b, (hl)
	ld	hl,#_x + 0
	ld	c, (hl)
	push	bc
	ld	de, #0x667f
	push	de
	call	_write_char
	pop	af
	pop	af
;snek_app.c:116: xd = nxd;
	ld	a,(#_nxd + 0)
	ld	(#_xd + 0),a
;snek_app.c:117: yd = nyd;
	ld	a,(#_nyd + 0)
	ld	(#_yd + 0),a
;snek_app.c:118: x += xd;
	ld	a,(#_xd + 0)
	ld	c, a
	rla
	sbc	a, a
	ld	b, a
	ld	hl, #_x
	ld	a, (hl)
	add	a, c
	ld	(hl), a
	inc	hl
	ld	a, (hl)
	adc	a, b
	ld	(hl), a
;snek_app.c:119: y += yd;
	ld	a,(#_yd + 0)
	ld	c, a
	rla
	sbc	a, a
	ld	b, a
	ld	hl, #_y
	ld	a, (hl)
	add	a, c
	ld	(hl), a
	inc	hl
	ld	a, (hl)
	adc	a, b
	ld	(hl), a
;snek_app.c:120: unsigned int p = (y * chram_cols) + x;
	ld	hl,#_chram_cols + 0
	ld	c, (hl)
	ld	b, #0x00
	push	bc
	ld	hl, (_y)
	push	hl
	call	__mulint
	pop	af
	pop	af
	ld	c, l
	ld	b, h
	ld	hl, (_x)
	add	hl, bc
;snek_app.c:121: if (chram[p] > 0)
	ld	bc,#_chram
	add	hl,bc
	ld	a, (hl)
	or	a, a
	jr	Z,00119$
;snek_app.c:123: nextstate = STATE_START_ATTRACT;
	ld	hl,#_nextstate + 0
	ld	(hl), #0x1e
;snek_app.c:124: start_fadeout();
	call	_start_fadeout
;snek_app.c:125: return;
	jp	00129$
00119$:
;snek_app.c:127: length++;
	ld	iy, #_length
	inc	0 (iy)
	jr	NZ,00225$
	inc	1 (iy)
00225$:
;snek_app.c:128: write_char(playerchar, 0xFF, x, y);
	ld	hl,#_y + 0
	ld	b, (hl)
	ld	hl,#_x + 0
	ld	c, (hl)
	push	bc
	ld	de, #0xff53
	push	de
	call	_write_char
	pop	af
	pop	af
;snek_app.c:129: movetimer = movefreq;
	ld	a,(#_movefreq + 0)
	ld	(#_movetimer + 0),a
;snek_app.c:131: sprintf(score, "%4d", length);
	ld	hl, #0x0000
	add	hl, sp
	ex	de, hl
	ld	c, e
	ld	b, d
	push	de
	ld	hl, (_length)
	push	hl
	ld	hl, #___str_2
	push	hl
	push	bc
	call	_sprintf
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
	pop	de
;snek_app.c:132: write_string(score, 0xFF, 35, 0);
	xor	a, a
	ld	b,a
	ld	c,#0x23
	push	bc
	ld	a, #0xff
	push	af
	inc	sp
	push	de
	call	_write_string
	pop	af
	pop	af
	inc	sp
00121$:
;snek_app.c:135: movefreqdectimer--;
	ld	iy, #_movefreqdectimer
	dec	0 (iy)
;snek_app.c:136: if (movefreqdectimer == 0)
	ld	a, 0 (iy)
	or	a, a
	jr	NZ,00129$
;snek_app.c:138: movefreqdectimer = movefreqdecfreq;
	ld	0 (iy), #0xc8
;snek_app.c:139: if (movefreq > 3)
	ld	a, #0x03
	ld	iy, #_movefreq
	sub	a, 0 (iy)
	jr	NC,00123$
;snek_app.c:141: movefreq--;
	dec	0 (iy)
00123$:
;snek_app.c:144: sprintf(str_movefreq, "%4d", movefreq);
	ld	hl,#_movefreq + 0
	ld	c, (hl)
	ld	b, #0x00
	ld	hl, #0x0002
	add	hl, sp
	ld	e, l
	ld	d, h
	push	hl
	push	bc
	ld	bc, #___str_2
	push	bc
	push	de
	call	_sprintf
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
	pop	hl
;snek_app.c:145: write_string(str_movefreq, 0xFF, 35, 29);
	ld	de, #0x1d23
	push	de
	ld	a, #0xff
	push	af
	inc	sp
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
00129$:
;snek_app.c:148: }
	ld	sp, ix
	pop	ix
	ret
___str_2:
	.ascii "%4d"
	.db 0x00
;snek_app.c:151: void snek_attract()
;	---------------------------------
; Function snek_attract
; ---------------------------------
_snek_attract::
;snek_app.c:154: if (HBLANK_RISING)
	ld	hl,#_hblank+0
	bit	0, (hl)
	jr	Z,00106$
	ld	hl,#_hblank_last+0
	bit	0, (hl)
	jr	NZ,00106$
;snek_app.c:156: if (CHECK_BIT(joystick[1], 3)) // start to start
	ld	a, (#(_joystick + 0x0001) + 0)
	bit	3, a
;snek_app.c:158: start_snek_gameplay();
;snek_app.c:159: return;
	jp	NZ,_start_snek_gameplay
;snek_app.c:161: if (CHECK_BIT(joystick[1], 2)) // select to quit
	ld	a, (#(_joystick + 0x0001) + 0)
	bit	2, a
	jr	Z,00106$
;snek_app.c:163: state = 0;
	ld	hl,#_state + 0
	ld	(hl), #0x00
;snek_app.c:164: return;
	ret
00106$:
;snek_app.c:168: if (VBLANK_RISING)
	ld	hl,#_vblank+0
	bit	0, (hl)
	ret	Z
	ld	hl,#_vblank_last+0
	bit	0, (hl)
	ret	NZ
;snek_app.c:170: movetimer--;
	ld	iy, #_movetimer
	dec	0 (iy)
;snek_app.c:171: if (movetimer == 0)
	ld	a, 0 (iy)
	or	a, a
	ret	NZ
;snek_app.c:173: attractstate = !attractstate;
	ld	iy, #_attractstate
	ld	a, 0 (iy)
	sub	a,#0x01
	ld	a, #0x00
	rla
	ld	0 (iy), a
;snek_app.c:174: write_string("PRESS START", attractstate == 0 ? 0x00 : 0xFF, 14, 15);
	ld	a, 0 (iy)
	or	a, a
	jr	NZ,00115$
	ld	bc, #0x0000
	jr	00116$
00115$:
	ld	bc, #0x00ff
00116$:
	ld	b, c
	ld	de, #0x0f0e
	push	de
	push	bc
	inc	sp
	ld	hl, #___str_3
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;snek_app.c:175: movetimer = movefreq;
	ld	a,(#_movefreq + 0)
	ld	(#_movetimer + 0),a
;snek_app.c:178: }
	ret
___str_3:
	.ascii "PRESS START"
	.db 0x00
	.area _CODE
	.area _INITIALIZER
__xinit__movefreqdectimer:
	.db #0x00	; 0
__xinit__movefreq:
	.db #0x00	; 0
__xinit__movetimer:
	.db #0x00	; 0
__xinit__x:
	.dw #0x0014
__xinit__y:
	.dw #0x000f
__xinit__xd:
	.db #0x00	;  0
__xinit__yd:
	.db #0x01	;  1
__xinit__nxd:
	.db #0x00	;  0
__xinit__nyd:
	.db #0x01	;  1
__xinit__length:
	.dw #0x0000
__xinit__attractstate:
	.db #0x00	; 0
	.area _CABS (ABS)
