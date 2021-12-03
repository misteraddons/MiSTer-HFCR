;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.8.0 #10562 (Linux)
;--------------------------------------------------------
	.module zorblaxx_app
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _app_zorblaxx
	.globl _game_loop
	.globl _intro_loop
	.globl _setup_area
	.globl _handle_meteors
	.globl _setup_meteors
	.globl _handle_explosions
	.globl _setup_explosions
	.globl _handle_trails
	.globl _setup_trails
	.globl _handle_player
	.globl _setup_player
	.globl _play_music
	.globl _write_stringf_ushort
	.globl _write_string
	.globl _clear_bgcolor
	.globl _clear_chars
	.globl _clear_sprites
	.globl _enable_sprite
	.globl _update_sprites
	.globl _sf_speed1
	.globl _scroll_speed_last
	.globl _x_max
	.globl _x_min
	.globl _debug_t2
	.globl _debug_t1
	.globl _scroll_speed
	.globl _x_h_max
	.globl _x_h_min
	.globl _spritecollisionram
	.globl _spriteram
	.globl _bgcolram
	.globl _fgcolram
	.globl _chram
	.globl _musicram
	.globl _sndram
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
	.globl _y_divisor
	.globl _x_divisor
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
_sndram	=	0x8b00
_musicram	=	0x8b10
_chram	=	0x9800
_fgcolram	=	0xa000
_bgcolram	=	0xa800
_spriteram	=	0xb000
_spritecollisionram	=	0xb400
_x_h_min::
	.ds 2
_x_h_max::
	.ds 2
_scroll_speed::
	.ds 1
_debug_t1::
	.ds 2
_debug_t2::
	.ds 2
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
_x_min::
	.ds 2
_x_max::
	.ds 2
_scroll_speed_last::
	.ds 1
_sf_speed1::
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
;zorblaxx_app.c:49: void setup_area()
;	---------------------------------
; Function setup_area
; ---------------------------------
_setup_area::
;zorblaxx_app.c:51: x_h_min = (unsigned short)(x_min * x_divisor);
	ld	hl,#_x_divisor + 0
	ld	c, (hl)
	ld	b, #0x00
	push	bc
	push	bc
	ld	hl, (_x_min)
	push	hl
	call	__mulint
	pop	af
	pop	af
	pop	bc
	ld	(_x_h_min), hl
;zorblaxx_app.c:52: x_h_max = (unsigned short)(x_max * x_divisor);
	push	bc
	ld	hl, (_x_max)
	push	hl
	call	__mulint
	pop	af
	pop	af
	ld	(_x_h_max), hl
;zorblaxx_app.c:53: }
	ret
_x_divisor:
	.db #0x10	; 16
_y_divisor:
	.db #0x10	; 16
;zorblaxx_app.c:59: void intro_loop()
;	---------------------------------
; Function intro_loop
; ---------------------------------
_intro_loop::
	push	ix
	ld	ix,#0
	add	ix,sp
	push	af
	push	af
	dec	sp
;zorblaxx_app.c:62: clear_bgcolor(0);
	xor	a, a
	push	af
	inc	sp
	call	_clear_bgcolor
	inc	sp
;zorblaxx_app.c:64: starfield[0] = 2;
	ld	hl, #_starfield
	ld	(hl), #0x02
;zorblaxx_app.c:65: starfield[2] = 8;
	ld	hl, #(_starfield + 0x0002)
	ld	(hl), #0x08
;zorblaxx_app.c:66: starfield[4] = 32;
	ld	hl, #(_starfield + 0x0004)
	ld	(hl), #0x20
;zorblaxx_app.c:67: unsigned char s = 16;
	ld	-1 (ix), #0x10
;zorblaxx_app.c:70: unsigned char si = 0;
	ld	-4 (ix), #0x00
;zorblaxx_app.c:71: for (unsigned char y = 0; y < 2; y++)
	ld	-5 (ix), #0x00
00115$:
	ld	a, -5 (ix)
	sub	a, #0x02
	jp	NC, 00102$
;zorblaxx_app.c:73: for (unsigned char x = 0; x < 8; x++)
	ld	e, -4 (ix)
	ld	c, -1 (ix)
	ld	d, #0x00
00112$:
	ld	a, d
	sub	a, #0x08
	jr	NC,00127$
;zorblaxx_app.c:75: enable_sprite(s, 2, 0);
	push	bc
	push	de
	xor	a, a
	ld	d,a
	ld	e,#0x02
	push	de
	ld	a, c
	push	af
	inc	sp
	call	_enable_sprite
	pop	af
	inc	sp
	pop	de
	pop	bc
;zorblaxx_app.c:76: spr_index[s] = 22 + si;
	ld	hl, #_spr_index
	ld	b, #0x00
	add	hl, bc
	ld	a, e
	add	a, #0x16
	ld	(hl), a
;zorblaxx_app.c:77: spr_x[s] = logoX + (x * 16);
	ld	l, c
	ld	h, #0x00
	add	hl, hl
	ld	iy, #_spr_x
	push	bc
	ld	c, l
	ld	b, h
	add	iy, bc
	pop	bc
	ld	l, d
	ld	h, #0x00
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	push	de
	ld	de, #0x0073
	add	hl, de
	pop	de
	ld	0 (iy), l
	ld	1 (iy), h
;zorblaxx_app.c:78: unsigned short sy = logoY + (y * 16);
	ld	l, -5 (ix)
	ld	h, #0x00
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	ld	a, l
	add	a, #0x64
	ld	-3 (ix), a
	ld	a, h
	adc	a, #0x00
	ld	-2 (ix), a
;zorblaxx_app.c:79: spr_y_h[s] = sy >> 8;
	ld	iy, #_spr_y_h
	push	bc
	ld	b, #0x00
	add	iy, bc
	pop	bc
	ld	l, -2 (ix)
	ld	0 (iy), l
;zorblaxx_app.c:80: spr_y_l[s] = (unsigned char)sy;
	ld	hl, #_spr_y_l
	ld	b, #0x00
	add	hl, bc
	ld	a, -3 (ix)
	ld	(hl), a
;zorblaxx_app.c:81: si++;
	inc	e
;zorblaxx_app.c:82: s++;
	inc	c
;zorblaxx_app.c:73: for (unsigned char x = 0; x < 8; x++)
	inc	d
	jr	00112$
00127$:
	ld	-4 (ix), e
	ld	-1 (ix), c
;zorblaxx_app.c:71: for (unsigned char y = 0; y < 2; y++)
	inc	-5 (ix)
	jp	00115$
00102$:
;zorblaxx_app.c:87: starfield[0] = 8;
	ld	hl, #_starfield
	ld	(hl), #0x08
;zorblaxx_app.c:88: starfield[1] = 16;
	ld	hl, #(_starfield + 0x0001)
	ld	(hl), #0x10
;zorblaxx_app.c:89: starfield[2] = 32;
	ld	hl, #(_starfield + 0x0002)
	ld	(hl), #0x20
;zorblaxx_app.c:91: write_string("Press A to start", 0xFF, 12, 20);
	ld	de, #0x140c
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
;zorblaxx_app.c:93: while (1)
00109$:
;zorblaxx_app.c:98: vblank = input0 & 0x10;
	ld	a,(#_input0 + 0)
	and	a, #0x10
	or	a,#0x00
	add	a, #0xff
	ld	a, #0x00
	rla
	ld	iy, #_vblank
	ld	0 (iy), a
;zorblaxx_app.c:100: if (VBLANK_RISING)
	bit	0, 0 (iy)
	jr	Z,00106$
	ld	hl,#_vblank_last+0
	bit	0, (hl)
	jr	NZ,00106$
;zorblaxx_app.c:103: if (CHECK_BIT(joystick[0], 4))
	ld	a, (#_joystick + 0)
	bit	4, a
;zorblaxx_app.c:105: return;
	jr	NZ,00117$
;zorblaxx_app.c:111: update_sprites();
	call	_update_sprites
00106$:
;zorblaxx_app.c:121: vblank_last = vblank;
	ld	a,(#_vblank + 0)
	ld	(#_vblank_last + 0),a
	jr	00109$
00117$:
;zorblaxx_app.c:123: }
	ld	sp, ix
	pop	ix
	ret
___str_0:
	.ascii "Press A to start"
	.db 0x00
;zorblaxx_app.c:130: void game_loop()
;	---------------------------------
; Function game_loop
; ---------------------------------
_game_loop::
;zorblaxx_app.c:132: clear_sprites();
	call	_clear_sprites
;zorblaxx_app.c:133: clear_bgcolor(0);
	xor	a, a
	push	af
	inc	sp
	call	_clear_bgcolor
	inc	sp
;zorblaxx_app.c:134: clear_chars(0);
	xor	a, a
	push	af
	inc	sp
	call	_clear_chars
	inc	sp
;zorblaxx_app.c:136: play_music(0);
	xor	a, a
	push	af
	inc	sp
	call	_play_music
	inc	sp
;zorblaxx_app.c:138: while (1)
00112$:
;zorblaxx_app.c:143: vblank = input0 & 0x10;
	ld	a,(#_input0 + 0)
	and	a, #0x10
	or	a,#0x00
	add	a, #0xff
	ld	a, #0x00
	rla
	ld	iy, #_vblank
	ld	0 (iy), a
;zorblaxx_app.c:145: if (VBLANK_RISING)
	bit	0, 0 (iy)
	jp	Z, 00106$
	ld	hl,#_vblank_last+0
	bit	0, (hl)
	jr	NZ,00106$
;zorblaxx_app.c:152: update_sprites();
	call	_update_sprites
;zorblaxx_app.c:161: scroll_speed = player_speed;
	ld	a,(#_player_speed + 0)
	ld	iy, #_scroll_speed
	ld	0 (iy), a
;zorblaxx_app.c:162: if (scroll_speed != scroll_speed_last)
	ld	a, 0 (iy)
	ld	iy, #_scroll_speed_last
	sub	a, 0 (iy)
	jr	Z,00102$
;zorblaxx_app.c:164: scroll_speed_last = scroll_speed;
	ld	a,(#_scroll_speed + 0)
	ld	(#_scroll_speed_last + 0),a
;zorblaxx_app.c:165: unsigned char s = scroll_speed / sf_speed1;
	ld	a, (_sf_speed1)
	push	af
	inc	sp
	ld	a, (_scroll_speed)
	push	af
	inc	sp
	call	__divuchar
	pop	af
	ld	c, l
;zorblaxx_app.c:166: starfield[0] = s;
	ld	hl, #_starfield
	ld	(hl), c
;zorblaxx_app.c:167: s = s / 2;
	ld	b, #0x00
	ld	e, c
	ld	l, b
	bit	7, b
	jr	Z,00116$
	inc	bc
	ld	e, c
	ld	l, b
00116$:
	sra	l
	rr	e
;zorblaxx_app.c:168: starfield[2] = s;
	ld	hl, #(_starfield + 0x0002)
	ld	(hl), e
;zorblaxx_app.c:169: s = s / 2;
	ld	d, #0x00
	ld	c, e
	ld	l, d
	bit	7, d
	jr	Z,00117$
	inc	de
	ld	c, e
	ld	l, d
00117$:
	sra	l
	rr	c
;zorblaxx_app.c:170: starfield[4] = s;
	ld	hl, #(_starfield + 0x0004)
	ld	(hl), c
00102$:
;zorblaxx_app.c:178: if (spritecollisionram[player_sprite])
	ld	bc, #_spritecollisionram+0
	ld	hl,#_player_sprite + 0
	ld	e, (hl)
	ld	l, e
	ld	h, #0x00
	add	hl, bc
	ld	a, (hl)
	or	a, a
	jr	Z,00106$
;zorblaxx_app.c:180: player_hit = true;
	ld	hl,#_player_hit + 0
	ld	(hl), #0x01
;zorblaxx_app.c:181: spritecollisionram[player_sprite] = 0;
	ld	hl, #_spritecollisionram+0
	ld	d, #0x00
	add	hl, de
	ld	(hl), #0x00
00106$:
;zorblaxx_app.c:189: if (VBLANK_FALLING)
	ld	hl,#_vblank+0
	bit	0, (hl)
	jr	NZ,00109$
	ld	hl,#_vblank_last+0
	bit	0, (hl)
	jr	Z,00109$
;zorblaxx_app.c:196: handle_player();
	call	_handle_player
;zorblaxx_app.c:205: handle_trails();
	call	_handle_trails
;zorblaxx_app.c:214: handle_explosions();
	call	_handle_explosions
;zorblaxx_app.c:223: handle_meteors();
	call	_handle_meteors
;zorblaxx_app.c:230: write_stringf_ushort("%10d", 0xFF, 30, 0, player_score);
	ld	hl, (_player_score)
	ld	bc, #___str_1+0
	push	hl
	xor	a, a
	ld	d,a
	ld	e,#0x1e
	push	de
	ld	a, #0xff
	push	af
	inc	sp
	push	bc
	call	_write_stringf_ushort
	ld	hl, #7
	add	hl, sp
	ld	sp, hl
;zorblaxx_app.c:233: write_stringf_ushort("%4d", 0xFF, 0, 0, meteor_difficulty);
	ld	hl,#_meteor_difficulty + 0
	ld	c, (hl)
	ld	b, #0x00
	push	bc
	xor	a, a
	push	af
	inc	sp
	xor	a, a
	ld	d,a
	ld	e,#0xff
	push	de
	ld	hl, #___str_2
	push	hl
	call	_write_stringf_ushort
	ld	hl, #7
	add	hl, sp
	ld	sp, hl
00109$:
;zorblaxx_app.c:239: vblank_last = vblank;
	ld	a,(#_vblank + 0)
	ld	(#_vblank_last + 0),a
;zorblaxx_app.c:241: }
	jp	00112$
___str_1:
	.ascii "%10d"
	.db 0x00
___str_2:
	.ascii "%4d"
	.db 0x00
;zorblaxx_app.c:243: void app_zorblaxx()
;	---------------------------------
; Function app_zorblaxx
; ---------------------------------
_app_zorblaxx::
;zorblaxx_app.c:245: setup_area();
	call	_setup_area
;zorblaxx_app.c:246: setup_player(176, 216);
	ld	hl, #0x00d8
	push	hl
	ld	l, #0xb0
	push	hl
	call	_setup_player
	pop	af
	pop	af
;zorblaxx_app.c:247: setup_trails();
	call	_setup_trails
;zorblaxx_app.c:248: intro_loop();
	call	_intro_loop
;zorblaxx_app.c:249: clear_chars(0);
	xor	a, a
	push	af
	inc	sp
	call	_clear_chars
	inc	sp
;zorblaxx_app.c:250: clear_sprites();
	call	_clear_sprites
;zorblaxx_app.c:252: setup_area();
	call	_setup_area
;zorblaxx_app.c:253: setup_meteors();
	call	_setup_meteors
;zorblaxx_app.c:254: setup_trails();
	call	_setup_trails
;zorblaxx_app.c:255: setup_explosions();
	call	_setup_explosions
;zorblaxx_app.c:256: setup_player(176, 216);
	ld	hl, #0x00d8
	push	hl
	ld	l, #0xb0
	push	hl
	call	_setup_player
	pop	af
	pop	af
;zorblaxx_app.c:258: game_loop();
;zorblaxx_app.c:259: }
	jp  _game_loop
	.area _CODE
	.area _INITIALIZER
__xinit__x_min:
	.dw #0x0002
__xinit__x_max:
	.dw #0x0150
__xinit__scroll_speed_last:
	.db #0x00	; 0
__xinit__sf_speed1:
	.db #0x04	; 4
	.area _CABS (ABS)
