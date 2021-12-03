;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.8.0 #10562 (Linux)
;--------------------------------------------------------
	.module music
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _music_track_max
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
	.globl _play_music
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
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
_music_track_max::
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
;music.c:29: void play_music(unsigned char track)
;	---------------------------------
; Function play_music
; ---------------------------------
_play_music::
	push	ix
	ld	ix,#0
	add	ix,sp
;music.c:32: musicram[1] = (unsigned char)(music_track_address[track] >> 16);
	ld	bc, #_music_track_address+0
	ld	l, 4 (ix)
	ld	h, #0x00
	add	hl, hl
	add	hl, hl
	add	hl, bc
	ex	de, hl
	ld	l, e
	ld	h, d
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	inc	hl
	inc	hl
	ld	a, (hl)
	dec	hl
	ld	a, (hl)
	ld	(#(_musicram + 0x0001)),a
;music.c:33: musicram[2] = music_track_address[track] >> 8;
	ld	l, e
	ld	h, d
	ld	b, (hl)
	inc	hl
	ld	c, (hl)
	ld	hl, #(_musicram + 0x0002)
	ld	(hl), c
;music.c:34: musicram[3] = music_track_address[track];
	ld	bc, #_musicram+3
	ld	a, (de)
	ld	(bc), a
;music.c:36: musicram[0] = 1;
	ld	hl, #_musicram
	ld	(hl), #0x01
;music.c:37: }
	pop	ix
	ret
	.area _CODE
	.area _INITIALIZER
__xinit__music_track_max:
	.db #0x20	; 32
	.area _CABS (ABS)
