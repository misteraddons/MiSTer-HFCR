;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.8.0 #10562 (Linux)
;--------------------------------------------------------
	.module sound
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _sound_sample_max
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
	.globl _play_sound
	.globl _set_sound_volume
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
_sound_sample_max::
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
;sound.c:29: void play_sound(unsigned char sample)
;	---------------------------------
; Function play_sound
; ---------------------------------
_play_sound::
	push	ix
	ld	ix,#0
	add	ix,sp
;sound.c:32: sndram[1] = sound_sample_address[sample] >> 8;
	ld	l, 4 (ix)
	ld	h, #0x00
	add	hl, hl
	add	hl, hl
	ld	c, l
	ld	b, h
	ld	hl, #_sound_sample_address
	add	hl, bc
	ex	de, hl
	ld	l, e
	ld	h, d
	ld	a, (hl)
	inc	hl
	ld	a, (hl)
	ld	(#(_sndram + 0x0001)),a
;sound.c:33: sndram[0] = sound_sample_address[sample];
	ld	a, (de)
	ld	(#_sndram),a
;sound.c:35: unsigned short end = sound_sample_address[sample] + sound_sample_length[sample];
	ex	de,hl
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	ld	hl, #_sound_sample_length+0
	add	hl, bc
	ld	a, (hl)
	inc	hl
	ld	h, (hl)
	ld	l, a
	add	hl, de
	ex	de, hl
;sound.c:36: sndram[5] = end >> 8;
	ld	hl, #_sndram+5
	ld	(hl), d
;sound.c:37: sndram[4] = end;
	ld	hl, #_sndram+4
	ld	(hl), e
;sound.c:39: sndram[8] = 1;
	ld	hl, #(_sndram + 0x0008)
	ld	(hl), #0x01
;sound.c:40: }
	pop	ix
	ret
;sound.c:42: void set_sound_volume(unsigned char volume)
;	---------------------------------
; Function set_sound_volume
; ---------------------------------
_set_sound_volume::
;sound.c:45: sndram[12] = volume;
	ld	hl, #(_sndram + 0x000c)
	ld	iy, #2
	add	iy, sp
	ld	a, 0 (iy)
	ld	(hl), a
;sound.c:46: }
	ret
	.area _CODE
	.area _INITIALIZER
__xinit__sound_sample_max:
	.db #0x20	; 32
	.area _CABS (ABS)
