;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.8.0 #10562 (Linux)
;--------------------------------------------------------
	.module tilemap
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _tilemap_offset_y
	.globl _tilemap_offset_x
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
	.globl _update_tilemap_offset
	.globl _scroll_tilemap_left
	.globl _scroll_tilemap_right
	.globl _scroll_tilemap_up
	.globl _scroll_tilemap_down
	.globl _clear_tilemap
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
_tilemap_offset_x::
	.ds 1
_tilemap_offset_y::
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
;tilemap.c:28: void update_tilemap_offset()
;	---------------------------------
; Function update_tilemap_offset
; ---------------------------------
_update_tilemap_offset::
;tilemap.c:30: tilemapctl[0] = tilemap_offset_x;
	ld	hl, #_tilemapctl
	ld	a,(#_tilemap_offset_x + 0)
	ld	(hl), a
;tilemap.c:31: tilemapctl[1] = tilemap_offset_y;
	ld	hl, #(_tilemapctl + 0x0001)
	ld	a,(#_tilemap_offset_y + 0)
	ld	(hl), a
;tilemap.c:32: }
	ret
;tilemap.c:34: void scroll_tilemap_left()
;	---------------------------------
; Function scroll_tilemap_left
; ---------------------------------
_scroll_tilemap_left::
;tilemap.c:36: tilemapctl[2] = 1;
	ld	hl, #(_tilemapctl + 0x0002)
	ld	(hl), #0x01
;tilemap.c:37: while (tilemapctl[2] != 0)
00101$:
	ld	a, (#(_tilemapctl + 0x0002) + 0)
	or	a, a
	jr	NZ,00101$
;tilemap.c:40: }
	ret
;tilemap.c:41: void scroll_tilemap_right()
;	---------------------------------
; Function scroll_tilemap_right
; ---------------------------------
_scroll_tilemap_right::
;tilemap.c:43: tilemapctl[2] = 2;
	ld	hl, #(_tilemapctl + 0x0002)
	ld	(hl), #0x02
;tilemap.c:44: while (tilemapctl[2] != 0)
00101$:
	ld	a, (#(_tilemapctl + 0x0002) + 0)
	or	a, a
	jr	NZ,00101$
;tilemap.c:47: }
	ret
;tilemap.c:48: void scroll_tilemap_up()
;	---------------------------------
; Function scroll_tilemap_up
; ---------------------------------
_scroll_tilemap_up::
;tilemap.c:50: tilemapctl[2] = 3;
	ld	hl, #(_tilemapctl + 0x0002)
	ld	(hl), #0x03
;tilemap.c:51: while (tilemapctl[2] != 0)
00101$:
	ld	a, (#(_tilemapctl + 0x0002) + 0)
	or	a, a
	jr	NZ,00101$
;tilemap.c:54: }
	ret
;tilemap.c:55: void scroll_tilemap_down()
;	---------------------------------
; Function scroll_tilemap_down
; ---------------------------------
_scroll_tilemap_down::
;tilemap.c:57: tilemapctl[2] = 4;
	ld	hl, #(_tilemapctl + 0x0002)
	ld	(hl), #0x04
;tilemap.c:58: while (tilemapctl[2] != 0)
00101$:
	ld	a, (#(_tilemapctl + 0x0002) + 0)
	or	a, a
	jr	NZ,00101$
;tilemap.c:61: }
	ret
;tilemap.c:62: void clear_tilemap()
;	---------------------------------
; Function clear_tilemap
; ---------------------------------
_clear_tilemap::
;tilemap.c:64: tilemapctl[2] = 5;
	ld	hl, #(_tilemapctl + 0x0002)
	ld	(hl), #0x05
;tilemap.c:65: while (tilemapctl[2] != 0)
00101$:
	ld	a, (#(_tilemapctl + 0x0002) + 0)
	or	a, a
	jr	NZ,00101$
;tilemap.c:68: }
	ret
	.area _CODE
	.area _INITIALIZER
__xinit__tilemap_offset_x:
	.db #0x00	;  0
__xinit__tilemap_offset_y:
	.db #0x00	;  0
	.area _CABS (ABS)
