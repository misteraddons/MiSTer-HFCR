;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.8.0 #10562 (Linux)
;--------------------------------------------------------
	.module fader
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _box
	.globl _fadetimer
	.globl _fade
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
	.globl _start_fadeout
	.globl _start_fadein
	.globl _fadeout
	.globl _fadein
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
_fade::
	.ds 1
_fadetimer::
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
;fader.c:32: void start_fadeout()
;	---------------------------------
; Function start_fadeout
; ---------------------------------
_start_fadeout::
;fader.c:34: state = STATE_FADEOUT;
	ld	hl,#_state + 0
	ld	(hl), #0x14
;fader.c:35: fadetimer = fadefreq;
	ld	hl,#_fadetimer + 0
	ld	(hl), #0x04
;fader.c:36: fade = 0;
	ld	hl,#_fade + 0
	ld	(hl), #0x00
;fader.c:37: }
	ret
;fader.c:40: void start_fadein()
;	---------------------------------
; Function start_fadein
; ---------------------------------
_start_fadein::
;fader.c:42: state = STATE_FADEIN;
	ld	hl,#_state + 0
	ld	(hl), #0x16
;fader.c:43: fadetimer = fadefreq;
	ld	hl,#_fadetimer + 0
	ld	(hl), #0x04
;fader.c:44: fade = 15;
	ld	hl,#_fade + 0
	ld	(hl), #0x0f
;fader.c:45: }
	ret
;fader.c:48: void fadeout()
;	---------------------------------
; Function fadeout
; ---------------------------------
_fadeout::
;fader.c:50: if (VBLANK_RISING)
	ld	hl,#_vblank+0
	bit	0, (hl)
	ret	Z
	ld	hl,#_vblank_last+0
	bit	0, (hl)
	ret	NZ
;fader.c:52: fadetimer--;
	ld	iy, #_fadetimer
	dec	0 (iy)
;fader.c:53: if (fadetimer == 0)
	ld	a, 0 (iy)
	or	a, a
	ret	NZ
;fader.c:55: box(fade, fade, 39 - fade, 29 - fade, 127, 0b0000111);
	ld	hl,#_fade + 0
	ld	c, (hl)
	ld	a, #0x1d
	sub	a, c
	ld	d, a
	ld	a, #0x27
	sub	a, c
	ld	b, a
	ld	a, #0x07
	push	af
	inc	sp
	ld	a, #0x7f
	push	af
	inc	sp
	ld	e, b
	push	de
	ld	a, (_fade)
	push	af
	inc	sp
	ld	a, (_fade)
	push	af
	inc	sp
	call	_box
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
;fader.c:56: fadetimer = fadefreq;
	ld	hl,#_fadetimer + 0
	ld	(hl), #0x04
;fader.c:57: fade++;
	ld	iy, #_fade
	inc	0 (iy)
;fader.c:58: if (fade == 16)
	ld	a, 0 (iy)
	sub	a, #0x10
	ret	NZ
;fader.c:60: start_fadein();
;fader.c:64: }
	jp  _start_fadein
;fader.c:67: void fadein()
;	---------------------------------
; Function fadein
; ---------------------------------
_fadein::
;fader.c:69: if (VBLANK_RISING)
	ld	hl,#_vblank+0
	bit	0, (hl)
	ret	Z
	ld	hl,#_vblank_last+0
	bit	0, (hl)
	ret	NZ
;fader.c:71: fadetimer--;
	ld	iy, #_fadetimer
	dec	0 (iy)
;fader.c:72: if (fadetimer == 0)
	ld	a, 0 (iy)
	or	a, a
	ret	NZ
;fader.c:74: box(fade, fade, 39 - fade, 29 - fade, 0, 0b0000000);
	ld	hl,#_fade + 0
	ld	c, (hl)
	ld	a, #0x1d
	sub	a, c
	ld	d, a
	ld	a, #0x27
	sub	a, c
	ld	b, a
	xor	a, a
	push	af
	inc	sp
	xor	a, a
	push	af
	inc	sp
	ld	e, b
	push	de
	ld	a, (_fade)
	push	af
	inc	sp
	ld	a, (_fade)
	push	af
	inc	sp
	call	_box
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
;fader.c:75: fadetimer = fadefreq;
	ld	hl,#_fadetimer + 0
	ld	(hl), #0x04
;fader.c:76: fade--;
	ld	iy, #_fade
	dec	0 (iy)
;fader.c:77: if (fade == 0)
	ld	a, 0 (iy)
	or	a, a
	ret	NZ
;fader.c:79: state = nextstate;
	ld	a,(#_nextstate + 0)
	ld	(#_state + 0),a
;fader.c:83: }
	ret
	.area _CODE
	.area _INITIALIZER
__xinit__fade:
	.db #0x00	; 0
__xinit__fadetimer:
	.db #0x00	; 0
	.area _CABS (ABS)
