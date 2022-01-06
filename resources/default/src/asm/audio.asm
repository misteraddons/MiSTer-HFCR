;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.8.0 #10562 (Linux)
;--------------------------------------------------------
	.module audio
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _tp
	.globl _channel_speed
	.globl _channel_dir
	.globl _channel_pos
	.globl _channel_low
	.globl _channel_high
	.globl _channel_on
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
	.globl _ay_write
	.globl _ay_set_ch
	.globl _init_audio
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
_channel_on::
	.ds 2
_channel_high::
	.ds 2
_channel_low::
	.ds 2
_channel_pos::
	.ds 2
_channel_dir::
	.ds 2
_channel_speed::
	.ds 2
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
_tp::
	.ds 258
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
;audio.c:53: void ay_write(unsigned char addr, unsigned char data)
;	---------------------------------
; Function ay_write
; ---------------------------------
_ay_write::
;audio.c:55: sndram[addr] = data;
	ld	bc, #_sndram+0
	ld	a, c
	ld	hl, #2
	add	hl, sp
	add	a, (hl)
	ld	c, a
	jr	NC,00103$
	inc	b
00103$:
	ld	hl, #3+0
	add	hl, sp
	ld	a, (hl)
	ld	(bc), a
;audio.c:56: }
	ret
;audio.c:58: void ay_set_ch(unsigned char c, unsigned char i)
;	---------------------------------
; Function ay_set_ch
; ---------------------------------
_ay_set_ch::
	push	ix
	ld	ix,#0
	add	ix,sp
;audio.c:60: ay_write(c * 2, tp[i] & 0xff);
	ld	l, 5 (ix)
	ld	h, #0x00
	add	hl, hl
	ld	de, #_tp
	add	hl, de
	ld	c, (hl)
	ld	e, 4 (ix)
	ld	a, e
	add	a, a
	ld	b, a
	push	hl
	push	de
	ld	a, c
	push	af
	inc	sp
	push	bc
	inc	sp
	call	_ay_write
	pop	af
	pop	de
	pop	hl
;audio.c:61: ay_write((c * 2) + 1, (tp[i] >> 8) & 0x0f);
	ld	c, (hl)
	inc	hl
	ld	c, (hl)
	ld	a, c
	and	a, #0x0f
	ld	b, a
	ld	a, e
	add	a, a
	inc	a
	push	bc
	inc	sp
	push	af
	inc	sp
	call	_ay_write
	pop	af
;audio.c:62: }
	pop	ix
	ret
;audio.c:64: void init_audio()
;	---------------------------------
; Function init_audio
; ---------------------------------
_init_audio::
;audio.c:67: channel_high[0] = 60;
	ld	hl, #_channel_high
	ld	(hl), #0x3c
;audio.c:68: channel_low[0] = 50;
	ld	bc, #_channel_low+0
	ld	a, #0x32
	ld	(bc), a
;audio.c:69: channel_dir[0] = 1;
	ld	hl, #_channel_dir
	ld	(hl), #0x01
;audio.c:70: channel_speed[0] = 30;
	ld	hl, #_channel_speed
	ld	(hl), #0x1e
;audio.c:71: channel_pos[0] = channel_low[0];
	ld	de, #_channel_pos+0
	ld	a, (bc)
	ld	(de), a
;audio.c:73: channel_high[1] = 78;
	ld	hl, #(_channel_high + 0x0001)
	ld	(hl), #0x4e
;audio.c:74: channel_low[1] = 74;
	inc	bc
	ld	a, #0x4a
	ld	(bc), a
;audio.c:75: channel_dir[1] = 1;
	ld	hl, #(_channel_dir + 0x0001)
	ld	(hl), #0x01
;audio.c:76: channel_speed[1] = 15;
	ld	hl, #(_channel_speed + 0x0001)
	ld	(hl), #0x0f
;audio.c:77: channel_pos[1] = channel_low[1];
	inc	de
	ld	a, (bc)
	ld	(de), a
;audio.c:79: ay_write(0x10, 0xFF);
	ld	de, #0xff10
	push	de
	call	_ay_write
	pop	af
;audio.c:80: for (char a = 0; a < 16; a++)
	ld	b, #0x00
00103$:
	ld	a, b
	sub	a, #0x10
	jr	NC,00101$
;audio.c:82: ay_write(a, 0xFF);
	push	bc
	ld	a, #0xff
	push	af
	inc	sp
	push	bc
	inc	sp
	call	_ay_write
	pop	af
	pop	bc
;audio.c:80: for (char a = 0; a < 16; a++)
	inc	b
	jr	00103$
00101$:
;audio.c:84: ay_write(0x07, 0b11111000);
	ld	de, #0xf807
	push	de
	call	_ay_write
	pop	af
;audio.c:85: ay_write(0x08, 0b00000111);
	ld	de, #0x0708
	push	de
	call	_ay_write
	pop	af
;audio.c:86: ay_write(0x09, 0b00000111);
	ld	de, #0x0709
	push	de
	call	_ay_write
	pop	af
;audio.c:87: ay_write(0x0A, 0b00000111);
	ld	de, #0x070a
	push	de
	call	_ay_write
	pop	af
;audio.c:88: }
	ret
	.area _CODE
	.area _INITIALIZER
__xinit__tp:
	.dw #0x3bb9
	.dw #0x385f
	.dw #0x3535
	.dw #0x3238
	.dw #0x2f67
	.dw #0x2cbe
	.dw #0x2a3b
	.dw #0x27dc
	.dw #0x259f
	.dw #0x2383
	.dw #0x2185
	.dw #0x1fa3
	.dw #0x1ddd
	.dw #0x1c2f
	.dw #0x1a9a
	.dw #0x191c
	.dw #0x17b3
	.dw #0x165f
	.dw #0x151d
	.dw #0x13ee
	.dw #0x12d0
	.dw #0x11c1
	.dw #0x10c2
	.dw #0x0fd2
	.dw #0x0eee
	.dw #0x0e18
	.dw #0x0d4d
	.dw #0x0c8e
	.dw #0x0bda
	.dw #0x0b2f
	.dw #0x0a8f
	.dw #0x09f7
	.dw #0x0968
	.dw #0x08e1
	.dw #0x0861
	.dw #0x07e9
	.dw #0x0777
	.dw #0x070c
	.dw #0x06a7
	.dw #0x0647
	.dw #0x05ed
	.dw #0x0598
	.dw #0x0547
	.dw #0x04fc
	.dw #0x04b4
	.dw #0x0470
	.dw #0x0431
	.dw #0x03f4
	.dw #0x03bc
	.dw #0x0386
	.dw #0x0353
	.dw #0x0324
	.dw #0x02f6
	.dw #0x02cc
	.dw #0x02a4
	.dw #0x027e
	.dw #0x025a
	.dw #0x0238
	.dw #0x0218
	.dw #0x01fa
	.dw #0x01de
	.dw #0x01c3
	.dw #0x01aa
	.dw #0x0192
	.dw #0x017b
	.dw #0x0166
	.dw #0x0152
	.dw #0x013f
	.dw #0x012d
	.dw #0x011c
	.dw #0x010c
	.dw #0x00fd
	.dw #0x00ef
	.dw #0x00e1
	.dw #0x00d5
	.dw #0x00c9
	.dw #0x00be
	.dw #0x00b3
	.dw #0x00a9
	.dw #0x009f
	.dw #0x0096
	.dw #0x008e
	.dw #0x0086
	.dw #0x007f
	.dw #0x0077
	.dw #0x0071
	.dw #0x006a
	.dw #0x0064
	.dw #0x005f
	.dw #0x0059
	.dw #0x0054
	.dw #0x0050
	.dw #0x004b
	.dw #0x0047
	.dw #0x0043
	.dw #0x003f
	.dw #0x003c
	.dw #0x0038
	.dw #0x0035
	.dw #0x0032
	.dw #0x002f
	.dw #0x002d
	.dw #0x002a
	.dw #0x0028
	.dw #0x0026
	.dw #0x0024
	.dw #0x0022
	.dw #0x0020
	.dw #0x001e
	.dw #0x001c
	.dw #0x001b
	.dw #0x0019
	.dw #0x0018
	.dw #0x0016
	.dw #0x0015
	.dw #0x0014
	.dw #0x0013
	.dw #0x0012
	.dw #0x0011
	.dw #0x0010
	.dw #0x000f
	.dw #0x000e
	.dw #0x000d
	.dw #0x000d
	.dw #0x000c
	.dw #0x000b
	.dw #0x000b
	.dw #0x000a
	.dw #0x0000
	.area _CABS (ABS)
