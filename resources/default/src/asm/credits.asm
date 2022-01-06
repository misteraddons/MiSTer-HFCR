;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.8.0 #10562 (Linux)
;--------------------------------------------------------
	.module credits
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _basic_input
	.globl _clear_tilemap
	.globl _scroll_tilemap_up
	.globl _update_tilemap_offset
	.globl _stop_music
	.globl _clear_sprites
	.globl _clear_chars
	.globl _strlen
	.globl _credits_entry_pos
	.globl _credits_pos
	.globl _credits_text
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
	.globl _app_credits
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
_credits_text::
	.ds 2
_credits_pos::
	.ds 1
_credits_entry_pos::
	.ds 2
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
;credits.c:33: void app_credits()
;	---------------------------------
; Function app_credits
; ---------------------------------
_app_credits::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	hl, #-34
	add	hl, sp
	ld	sp, hl
;credits.c:35: clear_chars(0);
	xor	a, a
	push	af
	inc	sp
	call	_clear_chars
	inc	sp
;credits.c:36: clear_sprites();
	call	_clear_sprites
;credits.c:37: clear_tilemap();
	call	_clear_tilemap
;credits.c:38: stop_music();
	call	_stop_music
;credits.c:40: starfield[0] = 32;
	ld	hl, #_starfield
	ld	(hl), #0x20
;credits.c:41: starfield[1] = 1;
	ld	hl, #(_starfield + 0x0001)
	ld	(hl), #0x01
;credits.c:42: starfield[2] = 64;
	ld	hl, #(_starfield + 0x0002)
	ld	(hl), #0x40
;credits.c:43: starfield[3] = 1;
	ld	hl, #(_starfield + 0x0003)
	ld	(hl), #0x01
;credits.c:44: starfield[4] = 128;
	ld	hl, #(_starfield + 0x0004)
	ld	(hl), #0x80
;credits.c:45: starfield[5] = 1;
	ld	hl, #(_starfield + 0x0005)
	ld	(hl), #0x01
;credits.c:47: tilemap_offset_x = 0;
	ld	hl,#_tilemap_offset_x + 0
	ld	(hl), #0x00
;credits.c:48: tilemap_offset_y = 0;
	ld	hl,#_tilemap_offset_y + 0
	ld	(hl), #0x00
;credits.c:51: credits_pos = 0;
	ld	hl,#_credits_pos + 0
	ld	(hl), #0x00
;credits.c:53: while (1)
	ld	hl, #0x0000
	add	hl, sp
	ld	-8 (ix), l
	ld	-7 (ix), h
	ld	a, -8 (ix)
	ld	-11 (ix), a
	ld	a, -7 (ix)
	ld	-10 (ix), a
00125$:
;credits.c:55: vblank = CHECK_BIT(input0, INPUT_VBLANK);
	ld	a,(#_input0 + 0)
	and	a, #0x10
	ld	c, a
	xor	a, a
	cp	a, c
	rla
	ld	iy, #_vblank
	ld	0 (iy), a
;credits.c:57: if (VBLANK_RISING)
	bit	0, 0 (iy)
	jp	Z, 00114$
	ld	hl,#_vblank_last+0
	bit	0, (hl)
	jp	NZ, 00114$
;credits.c:59: tilemap_offset_y += 2;
	ld	iy, #_tilemap_offset_y
	inc	0 (iy)
	inc	0 (iy)
;credits.c:60: if (tilemap_offset_y >= 16)
	ld	a, 0 (iy)
	xor	a, #0x80
	sub	a, #0x90
	jp	C, 00112$
;credits.c:62: tilemap_offset_y -= 16;
	ld	hl, #_tilemap_offset_y
	ld	a, (hl)
	add	a, #0xf0
	ld	(hl), a
;credits.c:64: scroll_tilemap_up();
	call	_scroll_tilemap_up
;credits.c:68: unsigned char credits_line_len = 0;
	ld	-12 (ix), #0x00
;credits.c:69: for (d = 0; d < 22; d++)
	ld	-3 (ix), #0x00
	ld	-1 (ix), #0x00
00127$:
;credits.c:71: c = credits_text[credits_pos];
	ld	iy, (_credits_text)
	ld	de, (_credits_pos)
	ld	d, #0x00
	add	iy, de
	ld	a, 0 (iy)
	ld	-9 (ix), a
;credits.c:72: credits_pos++;
	ld	hl, #_credits_pos+0
	inc	(hl)
;credits.c:73: if (c == '_')
	ld	a, -9 (ix)
	sub	a, #0x5f
	jr	Z,00106$
;credits.c:79: credits_line[d] = c;
	ld	a, -8 (ix)
	add	a, -1 (ix)
	ld	-6 (ix), a
	ld	a, -7 (ix)
	adc	a, #0x00
	ld	-5 (ix), a
	ld	l, -6 (ix)
	ld	h, -5 (ix)
	ld	a, -9 (ix)
	ld	(hl), a
;credits.c:80: credits_line_len++;
	inc	-3 (ix)
	ld	a, -3 (ix)
	ld	-12 (ix), a
;credits.c:82: if (credits_pos == strlen(credits_text))
	ld	hl, (_credits_text)
	push	hl
	call	_strlen
	pop	af
	ld	c, l
	ld	b, h
	ld	iy, #_credits_pos
	ld	e, 0 (iy)
	ld	d, #0x00
	ld	a, c
	sub	a, e
	jr	NZ,00128$
	ld	a, b
	sub	a, d
	jr	NZ,00128$
;credits.c:84: credits_pos = 0;
	ld	0 (iy), #0x00
;credits.c:85: break;
	jr	00106$
00128$:
;credits.c:69: for (d = 0; d < 22; d++)
	inc	-1 (ix)
	ld	a, -1 (ix)
	sub	a, #0x16
	jr	C,00127$
00106$:
;credits.c:88: signed char credits_line_pre = (22 - credits_line_len) / 2;
	ld	c, -12 (ix)
	ld	b, #0x00
	ld	hl, #0x0016
	cp	a, a
	sbc	hl, bc
	ld	e, l
	ld	d, h
	bit	7, h
	jr	Z,00133$
	ex	de,hl
	inc	de
00133$:
	sra	d
	rr	e
	ld	-4 (ix), e
;credits.c:89: for (d = 0; d < 22; d++)
	ld	-1 (ix), #0x00
00129$:
;credits.c:91: c = 0;
	ld	-2 (ix), #0x00
;credits.c:92: signed char i = d - credits_line_pre;
	ld	a, -1 (ix)
	sub	a, -4 (ix)
	ld	e, a
;credits.c:93: if (i >= 0 && i < credits_line_len)
	bit	7, e
	jr	NZ,00108$
	ld	a, e
	rla
	sbc	a, a
	ld	d, a
	ld	a, e
	sub	a, c
	ld	a, d
	sbc	a, b
	jp	PO, 00225$
	xor	a, #0x80
00225$:
	jp	P, 00108$
;credits.c:95: c = (credits_line[i] != '-') ? (credits_line[i] - 45) : 1;
	ld	l, -11 (ix)
	ld	h, -10 (ix)
	add	hl, de
	ld	a, (hl)
	cp	a, #0x2d
	jr	Z,00134$
	add	a, #0xd3
	ld	e, a
	rla
	sbc	a, a
	jr	00135$
00134$:
	ld	de, #0x0001
00135$:
	ld	-2 (ix), e
00108$:
;credits.c:97: tilemapram[credits_entry_pos + d] = c;
	ld	e, -1 (ix)
	ld	d, #0x00
	ld	iy, #_credits_entry_pos
	ld	a, 0 (iy)
	add	a, e
	ld	e, a
	ld	a, 1 (iy)
	adc	a, d
	ld	d, a
	ld	hl, #_tilemapram
	add	hl, de
	ld	a, -2 (ix)
	ld	(hl), a
;credits.c:89: for (d = 0; d < 22; d++)
	inc	-1 (ix)
	ld	a, -1 (ix)
	sub	a, #0x16
	jr	C,00129$
00112$:
;credits.c:100: update_tilemap_offset();
	call	_update_tilemap_offset
00114$:
;credits.c:103: if (VBLANK_FALLING)
	ld	hl,#_vblank+0
	bit	0, (hl)
	jr	NZ,00122$
	ld	hl,#_vblank_last+0
	bit	0, (hl)
	jr	Z,00122$
;credits.c:105: basic_input();
	call	_basic_input
;credits.c:106: if (input_a || input_b || input_select || input_start)
	ld	hl,#_input_a+0
	bit	0, (hl)
	jr	NZ,00126$
	ld	hl,#_input_b+0
	bit	0, (hl)
	jr	NZ,00126$
	ld	hl,#_input_select+0
	bit	0, (hl)
	jr	NZ,00126$
	ld	hl,#_input_start+0
	bit	0, (hl)
	jr	NZ,00126$
;credits.c:108: break;
00122$:
;credits.c:112: vblank_last = vblank;
	ld	a,(#_vblank + 0)
	ld	(#_vblank_last + 0),a
	jp	00125$
00126$:
;credits.c:115: clear_chars(0);
	xor	a, a
	push	af
	inc	sp
	call	_clear_chars
	inc	sp
;credits.c:116: clear_sprites();
	call	_clear_sprites
;credits.c:117: clear_tilemap();
	call	_clear_tilemap
;credits.c:118: stop_music();
	call	_stop_music
;credits.c:120: starfield[1] = 0;
	ld	hl, #(_starfield + 0x0001)
	ld	(hl), #0x00
;credits.c:121: starfield[3] = 0;
	ld	hl, #(_starfield + 0x0003)
	ld	(hl), #0x00
;credits.c:122: starfield[5] = 0;
	ld	hl, #(_starfield + 0x0005)
	ld	(hl), #0x00
;credits.c:124: state = defaultstate;
	ld	a,(#_defaultstate + 0)
	ld	(#_state + 0),a
;credits.c:125: }
	ld	sp, ix
	pop	ix
	ret
	.area _CODE
___str_0:
	.ascii "CODE AND GFX_-_JIMMYSTONES___MUSIC_-_DARRIN CARDANI___TESTIN"
	.ascii "G_-_PORKCHOP EXPRESS_SORGELIG_M. WALRUS___EXTRA THANKS_-_ALA"
	.ascii "NSWX_SORGELIG___"
	.db 0x00
	.area _INITIALIZER
__xinit__credits_text:
	.dw ___str_0
__xinit__credits_pos:
	.db #0x00	; 0
__xinit__credits_entry_pos:
	.dw #0x0200
	.area _CABS (ABS)
