;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.8.0 #10562 (Linux)
;--------------------------------------------------------
	.module inputtester_sys
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _nextstate
	.globl _defaultstate
	.globl _state
	.globl _input_b_last
	.globl _input_a_last
	.globl _input_select_last
	.globl _input_start_last
	.globl _input_down_last
	.globl _input_down
	.globl _input_up_last
	.globl _input_up
	.globl _input_right_last
	.globl _input_right
	.globl _input_left_last
	.globl _input_left
	.globl _input_mouse_right_last
	.globl _input_mouse_right
	.globl _input_mouse_left_last
	.globl _input_mouse_left
	.globl _input_b
	.globl _input_a
	.globl _input_select
	.globl _input_start
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
	.globl _basic_input
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
_input_start::
	.ds 1
_input_select::
	.ds 1
_input_a::
	.ds 1
_input_b::
	.ds 1
_input_mouse_left::
	.ds 1
_input_mouse_left_last::
	.ds 1
_input_mouse_right::
	.ds 1
_input_mouse_right_last::
	.ds 1
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
_input_left::
	.ds 1
_input_left_last::
	.ds 1
_input_right::
	.ds 1
_input_right_last::
	.ds 1
_input_up::
	.ds 1
_input_up_last::
	.ds 1
_input_down::
	.ds 1
_input_down_last::
	.ds 1
_input_start_last::
	.ds 1
_input_select_last::
	.ds 1
_input_a_last::
	.ds 1
_input_b_last::
	.ds 1
_state::
	.ds 1
_defaultstate::
	.ds 1
_nextstate::
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
;inputtester_sys.c:56: void basic_input()
;	---------------------------------
; Function basic_input
; ---------------------------------
_basic_input::
;inputtester_sys.c:58: input_up_last = input_up;
	ld	a,(#_input_up + 0)
	ld	(#_input_up_last + 0),a
;inputtester_sys.c:59: input_down_last = input_down;
	ld	a,(#_input_down + 0)
	ld	(#_input_down_last + 0),a
;inputtester_sys.c:60: input_left_last = input_left;
	ld	a,(#_input_left + 0)
	ld	(#_input_left_last + 0),a
;inputtester_sys.c:61: input_right_last = input_right;
	ld	a,(#_input_right + 0)
	ld	(#_input_right_last + 0),a
;inputtester_sys.c:62: input_start_last = input_start;
	ld	a,(#_input_start + 0)
	ld	(#_input_start_last + 0),a
;inputtester_sys.c:63: input_select_last = input_select;
	ld	a,(#_input_select + 0)
	ld	(#_input_select_last + 0),a
;inputtester_sys.c:64: input_a_last = input_a;
	ld	a,(#_input_a + 0)
	ld	(#_input_a_last + 0),a
;inputtester_sys.c:65: input_b_last = input_b;
	ld	a,(#_input_b + 0)
	ld	(#_input_b_last + 0),a
;inputtester_sys.c:66: input_mouse_left_last = input_mouse_left;
	ld	a,(#_input_mouse_left + 0)
	ld	(#_input_mouse_left_last + 0),a
;inputtester_sys.c:67: input_mouse_right_last = input_mouse_right;
	ld	a,(#_input_mouse_right + 0)
	ld	(#_input_mouse_right_last + 0),a
;inputtester_sys.c:68: input_up = CHECK_BIT(joystick[0], 3) || kbd_down[KEY_UP];
	ld	a, (#_joystick + 0)
	bit	3, a
	jr	NZ,00104$
	ld	bc, #_kbd_down+0
	ld	iy, #_KEY_UP
	ld	l, 0 (iy)
	ld	h, #0x00
	add	hl, bc
	bit	0, (hl)
	jr	NZ,00104$
	xor	a, a
	jr	00105$
00104$:
	ld	a, #0x01
00105$:
	ld	(#_input_up + 0),a
;inputtester_sys.c:69: input_down = CHECK_BIT(joystick[0], 2) || kbd_down[KEY_DOWN];
	ld	a, (#_joystick + 0)
	bit	2, a
	jr	NZ,00107$
	ld	bc, #_kbd_down+0
	ld	iy, #_KEY_DOWN
	ld	l, 0 (iy)
	ld	h, #0x00
	add	hl, bc
	bit	0, (hl)
	jr	NZ,00107$
	xor	a, a
	jr	00108$
00107$:
	ld	a, #0x01
00108$:
	ld	(#_input_down + 0),a
;inputtester_sys.c:70: input_left = CHECK_BIT(joystick[0], 1) || kbd_down[KEY_LEFT];
	ld	a, (#_joystick + 0)
	bit	1, a
	jr	NZ,00110$
	ld	bc, #_kbd_down+0
	ld	iy, #_KEY_LEFT
	ld	l, 0 (iy)
	ld	h, #0x00
	add	hl, bc
	bit	0, (hl)
	jr	NZ,00110$
	xor	a, a
	jr	00111$
00110$:
	ld	a, #0x01
00111$:
	ld	(#_input_left + 0),a
;inputtester_sys.c:71: input_right = CHECK_BIT(joystick[0], 0) || kbd_down[KEY_RIGHT];
	ld	a, (#_joystick + 0)
	rrca
	jr	C,00113$
	ld	bc, #_kbd_down+0
	ld	iy, #_KEY_RIGHT
	ld	l, 0 (iy)
	ld	h, #0x00
	add	hl, bc
	bit	0, (hl)
	jr	NZ,00113$
	xor	a, a
	jr	00114$
00113$:
	ld	a, #0x01
00114$:
	ld	(#_input_right + 0),a
;inputtester_sys.c:72: input_start = CHECK_BIT(joystick[1], 3) || kbd_down[KEY_1]|| mse_button1;
	ld	a, (#(_joystick + 0x0001) + 0)
	bit	3, a
	jr	NZ,00116$
	ld	bc, #_kbd_down+0
	ld	iy, #_KEY_1
	ld	l, 0 (iy)
	ld	h, #0x00
	add	hl, bc
	bit	0, (hl)
	jr	NZ,00116$
	ld	a,(#_mse_button1 + 0)
	or	a,a
	jr	Z,00117$
00116$:
	ld	a, #0x01
00117$:
	ld	(#_input_start + 0),a
;inputtester_sys.c:73: input_select = CHECK_BIT(joystick[1], 2) || kbd_down[KEY_ESC] || mse_button2;
	ld	a, (#(_joystick + 0x0001) + 0)
	bit	2, a
	jr	NZ,00122$
	ld	bc, #_kbd_down+0
	ld	iy, #_KEY_ESC
	ld	l, 0 (iy)
	ld	h, #0x00
	add	hl, bc
	bit	0, (hl)
	jr	NZ,00122$
	ld	a,(#_mse_button2 + 0)
	or	a,a
	jr	Z,00123$
00122$:
	ld	a, #0x01
00123$:
	ld	(#_input_select + 0),a
;inputtester_sys.c:74: input_a = CHECK_BIT(joystick[0], 4) || kbd_down[KEY_ENTER];
	ld	a, (#_joystick + 0)
	bit	4, a
	jr	NZ,00128$
	ld	bc, #_kbd_down+0
	ld	iy, #_KEY_ENTER
	ld	l, 0 (iy)
	ld	h, #0x00
	add	hl, bc
	bit	0, (hl)
	jr	NZ,00128$
	xor	a, a
	jr	00129$
00128$:
	ld	a, #0x01
00129$:
	ld	(#_input_a + 0),a
;inputtester_sys.c:75: input_b = CHECK_BIT(joystick[0], 5) || kbd_down[KEY_SPACE];
	ld	a, (#_joystick + 0)
	bit	5, a
	jr	NZ,00131$
	ld	bc, #_kbd_down+0
	ld	iy, #_KEY_SPACE
	ld	l, 0 (iy)
	ld	h, #0x00
	add	hl, bc
	bit	0, (hl)
	jr	NZ,00131$
	xor	a, a
	jr	00132$
00131$:
	ld	a, #0x01
00132$:
	ld	(#_input_b + 0),a
;inputtester_sys.c:76: }
	ret
	.area _CODE
	.area _INITIALIZER
__xinit__input_left:
	.db #0x00	;  0
__xinit__input_left_last:
	.db #0x00	;  0
__xinit__input_right:
	.db #0x00	;  0
__xinit__input_right_last:
	.db #0x00	;  0
__xinit__input_up:
	.db #0x00	;  0
__xinit__input_up_last:
	.db #0x00	;  0
__xinit__input_down:
	.db #0x00	;  0
__xinit__input_down_last:
	.db #0x00	;  0
__xinit__input_start_last:
	.db #0x00	;  0
__xinit__input_select_last:
	.db #0x00	;  0
__xinit__input_a_last:
	.db #0x00	;  0
__xinit__input_b_last:
	.db #0x00	;  0
__xinit__state:
	.db #0x00	; 0
__xinit__defaultstate:
	.db #0x01	; 1
__xinit__nextstate:
	.db #0x00	; 0
	.area _CABS (ABS)
