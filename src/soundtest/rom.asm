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
	.globl _cosf
	.globl _sinf
	.globl _set_starfield_speed_y
	.globl _set_starfield_speed_x
	.globl _enable_starfield
	.globl _play_sound
	.globl _handle_ps2
	.globl _write_stringf
	.globl _clear_chars
	.globl _time
	.globl _musicram
	.globl _sndram
	.globl _tilemapram
	.globl _tilemapctl
	.globl _spritecollisionram
	.globl _spriteram
	.globl _bgcolram
	.globl _fgcolram
	.globl _chram
	.globl _system_menu
	.globl _system_pause
	.globl _starfield3
	.globl _starfield2
	.globl _starfield1
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
_starfield1	=	0x8a00
_starfield2	=	0x8a10
_starfield3	=	0x8a20
_system_pause	=	0x8a30
_system_menu	=	0x8a31
_chram	=	0x9800
_fgcolram	=	0xa000
_bgcolram	=	0xa800
_spriteram	=	0xb000
_spritecollisionram	=	0xb400
_tilemapctl	=	0x8c00
_tilemapram	=	0x8c10
_sndram	=	0x8b00
_musicram	=	0x8b10
_time::
	.ds 4
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
;os.c:37: void app_main()
;	---------------------------------
; Function app_main
; ---------------------------------
_app_main::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	hl, #-7
	add	hl, sp
	ld	sp, hl
;os.c:39: chram_size = chram_cols * chram_rows;
	ld	hl,#_chram_rows + 0
	ld	e, (hl)
	ld	hl,#_chram_cols + 0
	ld	h, (hl)
	ld	l, #0x00
	ld	d, l
	ld	b, #0x08
00169$:
	add	hl, hl
	jr	NC,00170$
	add	hl, de
00170$:
	djnz	00169$
	ld	(_chram_size), hl
;os.c:40: clear_chars(0);
	xor	a, a
	push	af
	inc	sp
	call	_clear_chars
	inc	sp
;os.c:41: enable_starfield();
	call	_enable_starfield
;os.c:43: for (unsigned char s = 0; s < const_sound_sample_used; s++)
	ld	l, #0x00
00119$:
	ld	a, l
	sub	a, #0x04
	jr	NC,00101$
;os.c:45: write_stringf("%d: Play ", 0xFF, 5, 5 + (s * 2), s + 1);
	ld	e, l
	inc	e
	ld	a, l
	add	a, a
	add	a, #0x05
	ld	c, a
	push	hl
	ld	a, e
	push	af
	inc	sp
	ld	d, c
	ld	e,#0x05
	push	de
	ld	a, #0xff
	push	af
	inc	sp
	ld	bc, #___str_0
	push	bc
	call	_write_stringf
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
	pop	hl
;os.c:43: for (unsigned char s = 0; s < const_sound_sample_used; s++)
	inc	l
	jr	00119$
00101$:
;os.c:50: unsigned char play_wait = 0;
	ld	c, #0x00
;os.c:54: bool star_x = 1;
	ld	-3 (ix), #0x01
;os.c:56: while (1)
	xor	a, a
	ld	-2 (ix), a
	ld	-1 (ix), a
00116$:
;os.c:58: vblank = CHECK_BIT(input0, INPUT_VBLANK);
	ld	a,(#_input0 + 0)
	and	a, #0x10
	ld	b, a
	xor	a, a
	cp	a, b
	rla
	ld	(_vblank+0), a
;os.c:60: if (VBLANK_RISING)
	ld	iy, #_vblank
	bit	0, 0 (iy)
	jp	Z, 00113$
	ld	iy, #_vblank_last
	bit	0, 0 (iy)
	jp	NZ, 00113$
;os.c:62: write_stringf("frame %3d", 0xFF, 0, 29, frame);
	ld	b, -2 (ix)
	push	bc
	push	bc
	inc	sp
	ld	a, #0x1d
	push	af
	inc	sp
	xor	a, a
	ld	d,a
	ld	e,#0xff
	push	de
	ld	hl, #___str_1
	push	hl
	call	_write_stringf
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
	pop	bc
;os.c:63: frame++;
	inc	-2 (ix)
	jr	NZ,00171$
	inc	-1 (ix)
00171$:
;os.c:65: if (play_wait > 0)
	ld	a, c
	or	a, a
	jr	Z,00107$
;os.c:67: play_wait--;
	dec	c
	jr	00108$
00107$:
;os.c:71: handle_ps2();
	push	bc
	call	_handle_ps2
	pop	bc
;os.c:72: if (kbd_pressed)
	ld	a,(#_kbd_pressed + 0)
	or	a, a
	jr	Z,00108$
;os.c:74: unsigned char s = kbd_ascii - 49;
	ld	a,(#_kbd_ascii + 0)
	add	a, #0xcf
;os.c:75: if (s < const_sound_sample_used)
	ld	b, a
	sub	a, #0x04
	jr	NC,00108$
;os.c:77: write_stringf("playing %2d", 0xFF, 5, 20, s);
	push	bc
	push	bc
	inc	sp
	ld	de, #0x1405
	push	de
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_2
	push	hl
	call	_write_stringf
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
	inc	sp
	call	_play_sound
	inc	sp
;os.c:79: play_wait = 15;
	ld	c, #0x0f
00108$:
;os.c:84: if (star_x)
	bit	0, -3 (ix)
	jr	Z,00110$
;os.c:86: signed short x = sinf(time) * 100;
	push	bc
	ld	hl, (_time + 2)
	push	hl
	ld	hl, (_time)
	push	hl
	call	_sinf
	pop	af
	pop	af
	push	de
	push	hl
	ld	hl, #0x42c8
	push	hl
	ld	hl, #0x0000
	push	hl
	call	___fsmul
	pop	af
	pop	af
	pop	af
	pop	af
	push	de
	push	hl
	call	___fs2sint
	pop	af
	ex	(sp),hl
	call	_set_starfield_speed_x
	pop	af
	pop	bc
	jr	00111$
00110$:
;os.c:91: signed short y = cosf(time) * 100;
	push	bc
	ld	hl, (_time + 2)
	push	hl
	ld	hl, (_time)
	push	hl
	call	_cosf
	pop	af
	pop	af
	push	de
	push	hl
	ld	hl, #0x42c8
	push	hl
	ld	hl, #0x0000
	push	hl
	call	___fsmul
	pop	af
	pop	af
	pop	af
	pop	af
	push	de
	push	hl
	call	___fs2sint
	pop	af
	ex	(sp),hl
	call	_set_starfield_speed_y
	ld	hl, #0x3d4c
	ex	(sp),hl
	ld	hl, #0xcccd
	push	hl
	ld	hl, (_time + 2)
	push	hl
	ld	hl, (_time)
	push	hl
	call	___fsadd
	pop	af
	pop	af
	pop	af
	pop	af
	ld	-7 (ix), l
	ld	-6 (ix), h
	ld	-5 (ix), e
	ld	-4 (ix), d
	ld	de, #_time
	ld	hl, #2
	add	hl, sp
	ld	bc, #4
	ldir
	pop	bc
00111$:
;os.c:96: star_x = !star_x;
	ld	a, -3 (ix)
	xor	a, #0x01
	ld	-3 (ix), a
00113$:
;os.c:99: vblank_last = vblank;
	ld	a,(#_vblank + 0)
	ld	iy, #_vblank_last
	ld	0 (iy), a
;os.c:101: }
	jp	00116$
___str_0:
	.ascii "%d: Play "
	.db 0x00
___str_1:
	.ascii "frame %3d"
	.db 0x00
___str_2:
	.ascii "playing %2d"
	.db 0x00
;os.c:104: void main()
;	---------------------------------
; Function main
; ---------------------------------
_main::
;os.c:106: app_main();
;os.c:107: }
	jp	_app_main
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
