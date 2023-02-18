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
	.globl _set_bgcolour
	.globl _write_string
	.globl _set_char_palette
	.globl _clear_bgcolor
	.globl _clear_chars
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
;os.c:25: void app_main()
;	---------------------------------
; Function app_main
; ---------------------------------
_app_main::
;os.c:27: chram_size = chram_cols * chram_rows;
	ld	hl,#_chram_rows + 0
	ld	e, (hl)
	ld	hl,#_chram_cols + 0
	ld	h, (hl)
	ld	l, #0x00
	ld	d, l
	ld	b, #0x08
00148$:
	add	hl, hl
	jr	NC,00149$
	add	hl, de
00149$:
	djnz	00148$
	ld	(_chram_size), hl
;os.c:29: clear_chars(0);
	xor	a, a
	push	af
	inc	sp
	call	_clear_chars
	inc	sp
;os.c:30: clear_bgcolor(6);
	ld	a, #0x06
	push	af
	inc	sp
	call	_clear_bgcolor
	inc	sp
;os.c:31: bool yes = true;
;os.c:32: for (unsigned char y = 0; y < 30; y++)
	ld	bc, #0x0001
00112$:
	ld	a, b
	sub	a, #0x1e
	jr	NC,00104$
;os.c:34: for (unsigned char x = 0; x < 40; x++)
	ld	d, #0x00
00109$:
;os.c:40: yes = !yes;
	ld	a, c
	xor	a, #0x01
	ld	e, a
;os.c:34: for (unsigned char x = 0; x < 40; x++)
	ld	a, d
	sub	a, #0x28
	jr	NC,00103$
;os.c:36: if (yes)
	bit	0, c
	jr	Z,00102$
;os.c:38: set_bgcolour(7, x, y);
	push	bc
	push	de
	ld	c, d
	push	bc
	ld	a, #0x07
	push	af
	inc	sp
	call	_set_bgcolour
	pop	af
	inc	sp
	pop	de
	pop	bc
00102$:
;os.c:40: yes = !yes;
	ld	c, e
;os.c:34: for (unsigned char x = 0; x < 40; x++)
	inc	d
	jr	00109$
00103$:
;os.c:42: yes = !yes;
	ld	c, e
;os.c:32: for (unsigned char y = 0; y < 30; y++)
	inc	b
	jr	00112$
00104$:
;os.c:45: set_char_palette(1, 255, 255, 255);
	ld	de, #0xffff
	push	de
	ld	de, #0xff01
	push	de
	call	_set_char_palette
	pop	af
	pop	af
;os.c:46: set_char_palette(2, 255, 0, 0);
	xor	a, a
	push	af
	inc	sp
	xor	a, a
	ld	d,a
	ld	e,#0xff
	push	de
	ld	a, #0x02
	push	af
	inc	sp
	call	_set_char_palette
	pop	af
	pop	af
;os.c:47: set_char_palette(3, 0, 255, 0);
	xor	a, a
	ld	d,a
	ld	e,#0xff
	push	de
	xor	a, a
	ld	d,a
	ld	e,#0x03
	push	de
	call	_set_char_palette
	pop	af
;os.c:48: set_char_palette(4, 0, 0, 255);
	ld	h,#0xff
	ex	(sp),hl
	inc	sp
	xor	a, a
	push	af
	inc	sp
	xor	a, a
	ld	d,a
	ld	e,#0x04
	push	de
	call	_set_char_palette
	pop	af
;os.c:49: set_char_palette(5, 255, 0, 255);
	ld	h,#0xff
	ex	(sp),hl
	inc	sp
	xor	a, a
	ld	d,a
	ld	e,#0xff
	push	de
	ld	a, #0x05
	push	af
	inc	sp
	call	_set_char_palette
	pop	af
	pop	af
;os.c:51: set_char_palette(6, 140, 128, 128);
	ld	de, #0x8080
	push	de
	ld	de, #0x8c06
	push	de
	call	_set_char_palette
	pop	af
	pop	af
;os.c:52: set_char_palette(7, 50, 50, 70);
	ld	de, #0x4632
	push	de
	ld	de, #0x3207
	push	de
	call	_set_char_palette
	pop	af
	pop	af
;os.c:54: write_string("Hello wurld", 1, 5, 10);
	ld	de, #0x0a05
	push	de
	ld	a, #0x01
	push	af
	inc	sp
	ld	hl, #___str_0
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;os.c:56: write_string("0", 2, 0, 0);
	xor	a, a
	push	af
	inc	sp
	xor	a, a
	ld	d,a
	ld	e,#0x02
	push	de
	ld	hl, #___str_1
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;os.c:57: write_string("1", 3, 39, 0);
	xor	a, a
	ld	d,a
	ld	e,#0x27
	push	de
	ld	a, #0x03
	push	af
	inc	sp
	ld	hl, #___str_2
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;os.c:58: write_string("2", 4, 39, 29);
	ld	de, #0x1d27
	push	de
	ld	a, #0x04
	push	af
	inc	sp
	ld	hl, #___str_3
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;os.c:59: write_string("3", 5, 0, 29);
	ld	a, #0x1d
	push	af
	inc	sp
	xor	a, a
	ld	d,a
	ld	e,#0x05
	push	de
	ld	hl, #___str_4
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;os.c:61: while (1)
00106$:
;os.c:63: hsync = input0 & 0x80;
	ld	iy, #_input0
	ld	a, 0 (iy)
	rlc	a
	and	a, #0x01
	ld	(_hsync+0), a
;os.c:64: vsync = input0 & 0x40;
	ld	a, 0 (iy)
	and	a, #0x40
	ld	c,a
	or	a,#0x00
	add	a, #0xff
	ld	a, #0x00
	rla
	ld	(_vsync+0), a
;os.c:65: hblank = input0 & 0x20;
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
;os.c:66: vblank = CHECK_BIT(input0, INPUT_VBLANK);
	ld	a, 0 (iy)
	and	a, #0x10
	ld	c, a
	xor	a, a
	cp	a, c
	rla
	ld	(_vblank+0), a
;os.c:68: hsync_last = hsync;
	ld	a,(#_hsync + 0)
	ld	iy, #_hsync_last
	ld	0 (iy), a
;os.c:69: vsync_last = vsync;
	ld	a,(#_vsync + 0)
	ld	iy, #_vsync_last
	ld	0 (iy), a
;os.c:70: hblank_last = hblank;
	ld	a,(#_hblank + 0)
	ld	iy, #_hblank_last
	ld	0 (iy), a
;os.c:71: vblank_last = vblank;
	ld	a,(#_vblank + 0)
	ld	iy, #_vblank_last
	ld	0 (iy), a
;os.c:73: }
	jr	00106$
___str_0:
	.ascii "Hello wurld"
	.db 0x00
___str_1:
	.ascii "0"
	.db 0x00
___str_2:
	.ascii "1"
	.db 0x00
___str_3:
	.ascii "2"
	.db 0x00
___str_4:
	.ascii "3"
	.db 0x00
;os.c:76: void main()
;	---------------------------------
; Function main
; ---------------------------------
_main::
;os.c:78: app_main();
;os.c:79: }
	jp	_app_main
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
