;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.8.0 #10562 (Linux)
;--------------------------------------------------------
	.module sys
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _rand
	.globl _vblank_last
	.globl _vblank
	.globl _hblank_last
	.globl _hblank
	.globl _vsync_last
	.globl _vsync
	.globl _hsync_last
	.globl _hsync
	.globl _chram_size
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
	.globl _chram_rows
	.globl _chram_cols
	.globl _rand_uchar
	.globl _rand_ushort
	.globl _rand_schar
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
_chram_size::
	.ds 2
_hsync::
	.ds 1
_hsync_last::
	.ds 1
_vsync::
	.ds 1
_vsync_last::
	.ds 1
_hblank::
	.ds 1
_hblank_last::
	.ds 1
_vblank::
	.ds 1
_vblank_last::
	.ds 1
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
;sys.c:44: unsigned char rand_uchar(unsigned char lower, unsigned char upper)
;	---------------------------------
; Function rand_uchar
; ---------------------------------
_rand_uchar::
	push	ix
	ld	ix,#0
	add	ix,sp
;sys.c:46: return (rand() % (upper - lower + 1)) + lower;
	call	_rand
	ld	c, l
	ld	b, h
	ld	l, 5 (ix)
	ld	h, #0x00
	ld	e, 4 (ix)
	ld	d, #0x00
	cp	a, a
	sbc	hl, de
	inc	hl
	push	hl
	push	bc
	call	__modsint
	pop	af
	pop	af
	ld	c, 4 (ix)
	add	hl, bc
;sys.c:47: }
	pop	ix
	ret
_chram_cols:
	.db #0x40	; 64
_chram_rows:
	.db #0x20	; 32
;sys.c:49: unsigned short rand_ushort(unsigned short lower, unsigned short upper)
;	---------------------------------
; Function rand_ushort
; ---------------------------------
_rand_ushort::
	push	ix
	ld	ix,#0
	add	ix,sp
;sys.c:51: return (rand() % (upper - lower + 1)) + lower;
	call	_rand
	ld	a, 6 (ix)
	sub	a, 4 (ix)
	ld	c, a
	ld	a, 7 (ix)
	sbc	a, 5 (ix)
	ld	b, a
	inc	bc
	push	bc
	push	hl
	call	__moduint
	pop	af
	pop	af
	ld	c, l
	ld	b, h
	ld	l, 4 (ix)
	ld	h, 5 (ix)
	add	hl, bc
;sys.c:52: }
	pop	ix
	ret
;sys.c:54: signed char rand_schar(signed char lower, signed char upper)
;	---------------------------------
; Function rand_schar
; ---------------------------------
_rand_schar::
	push	ix
	ld	ix,#0
	add	ix,sp
;sys.c:56: return (rand() % (upper - lower + 1)) + lower;
	call	_rand
	ld	c, l
	ld	b, h
	ld	a, 5 (ix)
	ld	l, a
	rla
	sbc	a, a
	ld	h, a
	ld	a, 4 (ix)
	ld	e, a
	rla
	sbc	a, a
	ld	d, a
	cp	a, a
	sbc	hl, de
	inc	hl
	push	hl
	push	bc
	call	__modsint
	pop	af
	pop	af
	ld	a, l
	add	a, 4 (ix)
	ld	l, a
;sys.c:57: }
	pop	ix
	ret
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
