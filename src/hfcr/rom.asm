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
	.globl _write_string
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
00111$:
	add	hl, hl
	jr	NC,00112$
	add	hl, de
00112$:
	djnz	00111$
	ld	(_chram_size), hl
;os.c:29: write_string("Hello wurld", 0xFF, 5, 10);
	ld	de, #0x0a05
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
;os.c:31: write_string("0", 0xFF, 0, 0);
	xor	a, a
	push	af
	inc	sp
	xor	a, a
	ld	d,a
	ld	e,#0xff
	push	de
	ld	hl, #___str_1
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;os.c:32: write_string("1", 0xFF, 39, 0);
	xor	a, a
	ld	d,a
	ld	e,#0x27
	push	de
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_2
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;os.c:33: write_string("2", 0xFF, 39, 29);
	ld	de, #0x1d27
	push	de
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_3
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;os.c:34: write_string("3", 0xFF, 0, 29);
	ld	a, #0x1d
	push	af
	inc	sp
	xor	a, a
	ld	d,a
	ld	e,#0xff
	push	de
	ld	hl, #___str_4
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;os.c:36: while (1)
00102$:
;os.c:38: hsync = input0 & 0x80;
	ld	iy, #_input0
	ld	a, 0 (iy)
	rlc	a
	and	a, #0x01
	ld	(_hsync+0), a
;os.c:39: vsync = input0 & 0x40;
	ld	a, 0 (iy)
	and	a, #0x40
	ld	c,a
	or	a,#0x00
	add	a, #0xff
	ld	a, #0x00
	rla
	ld	(_vsync+0), a
;os.c:40: hblank = input0 & 0x20;
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
;os.c:41: vblank = CHECK_BIT(input0, INPUT_VBLANK);
	ld	a, 0 (iy)
	and	a, #0x10
	ld	c, a
	xor	a, a
	cp	a, c
	rla
	ld	(_vblank+0), a
;os.c:43: hsync_last = hsync;
	ld	a,(#_hsync + 0)
	ld	iy, #_hsync_last
	ld	0 (iy), a
;os.c:44: vsync_last = vsync;
	ld	a,(#_vsync + 0)
	ld	iy, #_vsync_last
	ld	0 (iy), a
;os.c:45: hblank_last = hblank;
	ld	a,(#_hblank + 0)
	ld	iy, #_hblank_last
	ld	0 (iy), a
;os.c:46: vblank_last = vblank;
	ld	a,(#_vblank + 0)
	ld	iy, #_vblank_last
	ld	0 (iy), a
;os.c:48: }
	jr	00102$
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
;os.c:51: void main()
;	---------------------------------
; Function main
; ---------------------------------
_main::
;os.c:53: app_main();
;os.c:54: }
	jp	_app_main
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
