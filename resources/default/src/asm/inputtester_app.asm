;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.8.0 #10562 (Linux)
;--------------------------------------------------------
	.module inputtester_app
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _btntest_results
	.globl _btntest_test
	.globl _btntest_ready
	.globl _btntest_select
	.globl _btntest_starttest
	.globl _modeswitcher
	.globl _handle_codes
	.globl _pushhistory
	.globl _reset_inputstates
	.globl _page_btntest
	.globl _page_inputtester_advanced
	.globl _page_inputtester_analog
	.globl _page_inputtester_digital
	.globl _handle_pings
	.globl _add_ping
	.globl _draw_analog
	.globl _draw_pad
	.globl _page_frame
	.globl _basic_input
	.globl _clear_sprites
	.globl _enable_sprite
	.globl _update_sprites
	.globl _set_sprite_position
	.globl _handle_ps2
	.globl _set_bgcolour
	.globl _set_fgcolour
	.globl _write_char
	.globl _write_stringf_short
	.globl _write_stringf_ushort
	.globl _write_stringf
	.globl _write_stringfs
	.globl _write_string
	.globl _start_menu
	.globl _abs
	.globl _sprintf
	.globl _btntest_aftertimer
	.globl _btntest_highlight
	.globl _btntest_results_offset
	.globl _btntest_results_refresh
	.globl _btntest_buttondownlast
	.globl _btntest_pos
	.globl _btntest_counter
	.globl _btntest_timer
	.globl _btntest_buttonlast
	.globl _btntest_buttonindex
	.globl _btntest_buttonbank
	.globl _btntest_mode
	.globl _analog_pad
	.globl _last_timestamp_clock
	.globl _analog_offset_y
	.globl _analog_offset_x
	.globl _button_y
	.globl _button_x
	.globl _button_name
	.globl _button_symbol
	.globl _pad_offset_y
	.globl _pad_offset_x
	.globl _modeswitchtimer_start
	.globl _modeswitchtimer_select
	.globl _mse_w_last
	.globl _mse_y_last
	.globl _mse_x_last
	.globl _mse_button2_last
	.globl _mse_button1_last
	.globl _kbd_ascii_last
	.globl _kbd_scan_last
	.globl _btntest_prompts
	.globl _btntest_presses
	.globl _analog_y
	.globl _analog_x
	.globl _history
	.globl _mse_w_acc
	.globl _mse_y_acc
	.globl _mse_x_acc
	.globl _sx_pos
	.globl _sx_last
	.globl _sx_toggle_last
	.globl _px_last
	.globl _ay_r_last
	.globl _ax_r_last
	.globl _ay_l_last
	.globl _ax_l_last
	.globl _joystick_last
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
	.globl _start_inputtester_digital
	.globl _start_inputtester_analog
	.globl _start_inputtester_advanced
	.globl _start_btntest
	.globl _inputtester_digital
	.globl _inputtester_analog
	.globl _inputtester_advanced
	.globl _btntest
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
_joystick_last::
	.ds 12
_ax_l_last::
	.ds 6
_ay_l_last::
	.ds 6
_ax_r_last::
	.ds 6
_ay_r_last::
	.ds 6
_px_last::
	.ds 6
_sx_toggle_last::
	.ds 6
_sx_last::
	.ds 6
_sx_pos::
	.ds 24
_mse_x_acc::
	.ds 2
_mse_y_acc::
	.ds 2
_mse_w_acc::
	.ds 2
_history::
	.ds 7
_analog_x::
	.ds 2
_analog_y::
	.ds 2
_btntest_presses::
	.ds 510
_btntest_prompts::
	.ds 10
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
_kbd_scan_last::
	.ds 1
_kbd_ascii_last::
	.ds 1
_mse_button1_last::
	.ds 1
_mse_button2_last::
	.ds 1
_mse_x_last::
	.ds 1
_mse_y_last::
	.ds 1
_mse_w_last::
	.ds 1
_modeswitchtimer_select::
	.ds 1
_modeswitchtimer_start::
	.ds 1
_pad_offset_x::
	.ds 2
_pad_offset_y::
	.ds 2
_button_symbol::
	.ds 72
_button_name::
	.ds 144
_button_x::
	.ds 12
_button_y::
	.ds 12
_analog_offset_x::
	.ds 2
_analog_offset_y::
	.ds 2
_last_timestamp_clock::
	.ds 1
_analog_pad::
	.ds 1
_btntest_mode::
	.ds 1
_btntest_buttonbank::
	.ds 1
_btntest_buttonindex::
	.ds 1
_btntest_buttonlast::
	.ds 1
_btntest_timer::
	.ds 1
_btntest_counter::
	.ds 1
_btntest_pos::
	.ds 1
_btntest_buttondownlast::
	.ds 1
_btntest_results_refresh::
	.ds 1
_btntest_results_offset::
	.ds 1
_btntest_highlight::
	.ds 1
_btntest_aftertimer::
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
;inputtester_app.c:145: void page_inputtester_digital()
;	---------------------------------
; Function page_inputtester_digital
; ---------------------------------
_page_inputtester_digital::
	push	ix
	ld	ix,#0
	add	ix,sp
	push	af
	push	af
;inputtester_app.c:147: page_frame(true, false);
	xor	a, a
	ld	d,a
	ld	e,#0x01
	push	de
	call	_page_frame
	pop	af
;inputtester_app.c:149: for (char j = 0; j < PAD_COUNT; j++)
	ld	c, #0x00
00103$:
	ld	a, c
	sub	a, #0x02
	jr	NC,00105$
;inputtester_app.c:151: write_stringf("JOY %d", 0xFF, pad_offset_x[j] - 5, pad_offset_y[j] + 5, j + 1);
	ld	b, c
	inc	b
	ld	a, #<(_pad_offset_y)
	add	a, c
	ld	-4 (ix), a
	ld	a, #>(_pad_offset_y)
	adc	a, #0x00
	ld	-3 (ix), a
	pop	hl
	push	hl
	ld	a, (hl)
	add	a, #0x05
	ld	-2 (ix), a
	ld	a, #<(_pad_offset_x)
	add	a, c
	ld	e, a
	ld	a, #>(_pad_offset_x)
	adc	a, #0x00
	ld	d, a
	ld	a, (de)
	add	a, #0xfb
	ld	-1 (ix), a
	push	bc
	push	de
	push	bc
	inc	sp
	ld	a, -2 (ix)
	push	af
	inc	sp
	ld	d, -1 (ix)
	ld	e,#0xff
	push	de
	ld	hl, #___str_0
	push	hl
	call	_write_stringf
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
	pop	de
	pop	bc
;inputtester_app.c:152: draw_pad(pad_offset_x[j], pad_offset_y[j]);
	pop	hl
	push	hl
	ld	b, (hl)
	ld	a, (de)
	push	bc
	push	bc
	inc	sp
	push	af
	inc	sp
	call	_draw_pad
	pop	af
	pop	bc
;inputtester_app.c:149: for (char j = 0; j < PAD_COUNT; j++)
	inc	c
	jr	00103$
00105$:
;inputtester_app.c:154: }
	ld	sp, ix
	pop	ix
	ret
___str_0:
	.ascii "JOY %d"
	.db 0x00
;inputtester_app.c:157: void page_inputtester_analog()
;	---------------------------------
; Function page_inputtester_analog
; ---------------------------------
_page_inputtester_analog::
;inputtester_app.c:159: page_frame(true, false);
	xor	a, a
	ld	d,a
	ld	e,#0x01
	push	de
	call	_page_frame
	pop	af
;inputtester_app.c:162: write_string("ANALOG LEFT", 0xFF, analog_offset_x[j], analog_offset_y[j] - 1);
	ld	a, (#_analog_offset_y + 0)
	ld	b, a
	dec	b
	ld	hl, #_analog_offset_x + 0
	ld	c, (hl)
	push	bc
	inc	sp
	ld	d, c
	ld	e,#0xff
	push	de
	ld	hl, #___str_1
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;inputtester_app.c:163: draw_analog(analog_offset_x[j], analog_offset_y[j], analog_size, analog_size);
	ld	hl, #_analog_offset_y + 0
	ld	d, (hl)
	ld	hl, #_analog_offset_x + 0
	ld	b, (hl)
	ld	a, #0x12
	push	af
	inc	sp
	ld	a, #0x12
	push	af
	inc	sp
	ld	e, b
	push	de
	call	_draw_analog
	pop	af
	pop	af
;inputtester_app.c:164: write_string("X:", 0xFF, analog_offset_x[j] + 1, analog_offset_y[j] + analog_size + 1);
	ld	a, (#_analog_offset_y + 0)
	add	a, #0x13
	ld	e, a
	ld	a, (#_analog_offset_x + 0)
	ld	c, a
	inc	c
	ld	a, e
	push	af
	inc	sp
	ld	d, c
	ld	e,#0xff
	push	de
	ld	hl, #___str_2
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;inputtester_app.c:165: write_string("Y:", 0xFF, analog_offset_x[j] + 10, analog_offset_y[j] + analog_size + 1);
	ld	a, (#_analog_offset_y + 0)
	add	a, #0x13
	ld	b, a
	ld	a, (#_analog_offset_x + 0)
	add	a, #0x0a
	ld	c, a
	push	bc
	inc	sp
	ld	d, c
	ld	e,#0xff
	push	de
	ld	hl, #___str_3
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;inputtester_app.c:167: write_stringf("PAD %d", 0xFF, 18, analog_offset_y[j] - 1, analog_pad + 1);
	ld	hl,#_analog_pad + 0
	ld	b, (hl)
	inc	b
	ld	a, (#_analog_offset_y + 0)
	ld	c, a
	dec	c
	push	bc
	inc	sp
	ld	d, c
	ld	e,#0x12
	push	de
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_4
	push	hl
	call	_write_stringf
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
;inputtester_app.c:170: write_string("ANALOG RIGHT", 0xFF, analog_offset_x[j] + analog_size - 11, analog_offset_y[j] - 1);
	ld	a, (#(_analog_offset_y + 0x0001) + 0)
	ld	e, a
	dec	e
	ld	a, (#(_analog_offset_x + 0x0001) + 0)
	add	a, #0x07
	ld	c, a
	ld	a, e
	push	af
	inc	sp
	ld	d, c
	ld	e,#0xff
	push	de
	ld	hl, #___str_5
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;inputtester_app.c:171: draw_analog(analog_offset_x[j], analog_offset_y[j], analog_size, analog_size);
	ld	hl, #(_analog_offset_y + 0x0001) + 0
	ld	d, (hl)
	ld	hl, #(_analog_offset_x + 0x0001) + 0
	ld	b, (hl)
	ld	a, #0x12
	push	af
	inc	sp
	ld	a, #0x12
	push	af
	inc	sp
	ld	e, b
	push	de
	call	_draw_analog
	pop	af
	pop	af
;inputtester_app.c:172: write_string("X:", 0xFF, analog_offset_x[j] + 1, analog_offset_y[j] + analog_size + 1);
	ld	a, (#(_analog_offset_y + 0x0001) + 0)
	add	a, #0x13
	ld	b, a
	ld	a, (#(_analog_offset_x + 0x0001) + 0)
	ld	c, a
	inc	c
	push	bc
	inc	sp
	ld	d, c
	ld	e,#0xff
	push	de
	ld	hl, #___str_2
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;inputtester_app.c:173: write_string("Y:", 0xFF, analog_offset_x[j] + 10, analog_offset_y[j] + analog_size + 1);
	ld	a, (#(_analog_offset_y + 0x0001) + 0)
	add	a, #0x13
	ld	b, a
	ld	a, (#(_analog_offset_x + 0x0001) + 0)
	add	a, #0x0a
	ld	c, a
	push	bc
	inc	sp
	ld	d, c
	ld	e,#0xff
	push	de
	ld	hl, #___str_3
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;inputtester_app.c:175: write_string("Cycle selected pad with A / B", 0x3F, 5, analog_offset_y[j] + analog_size + 2);
	ld	a, (#(_analog_offset_y + 0x0001) + 0)
	add	a, #0x14
	ld	b, a
	push	bc
	inc	sp
	ld	de, #0x053f
	push	de
	ld	hl, #___str_6
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;inputtester_app.c:176: }
	ret
___str_1:
	.ascii "ANALOG LEFT"
	.db 0x00
___str_2:
	.ascii "X:"
	.db 0x00
___str_3:
	.ascii "Y:"
	.db 0x00
___str_4:
	.ascii "PAD %d"
	.db 0x00
___str_5:
	.ascii "ANALOG RIGHT"
	.db 0x00
___str_6:
	.ascii "Cycle selected pad with A / B"
	.db 0x00
;inputtester_app.c:179: void page_inputtester_advanced()
;	---------------------------------
; Function page_inputtester_advanced
; ---------------------------------
_page_inputtester_advanced::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	hl, #-20
	add	hl, sp
	ld	sp, hl
;inputtester_app.c:181: page_frame(true, false);
	xor	a, a
	ld	d,a
	ld	e,#0x01
	push	de
	call	_page_frame
	pop	af
;inputtester_app.c:183: write_string("RLDUABXYLRsS", 0xFF, 7, 5);
	ld	de, #0x0507
	push	de
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_7
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;inputtester_app.c:184: write_string("ALX", 0xFF, 21, 5);
	ld	de, #0x0515
	push	de
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_8
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;inputtester_app.c:185: write_string("ALY", 0xFF, 25, 5);
	ld	de, #0x0519
	push	de
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_9
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;inputtester_app.c:186: write_string("ARX", 0xFF, 30, 5);
	ld	de, #0x051e
	push	de
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_10
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;inputtester_app.c:187: write_string("ARY", 0xFF, 34, 5);
	ld	de, #0x0522
	push	de
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_11
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;inputtester_app.c:189: write_string("POS", 0xFF, 7, 13);
	ld	de, #0x0d07
	push	de
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_12
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;inputtester_app.c:190: write_string("SPD  POS", 0xFF, 20, 13);
	ld	de, #0x0d14
	push	de
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_13
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;inputtester_app.c:193: for (unsigned char j = 0; j < 6; j++)
	ld	hl, #0x0000
	add	hl, sp
	ex	de, hl
	ld	-9 (ix), e
	ld	-8 (ix), d
	ld	-3 (ix), e
	ld	-2 (ix), d
	ld	-13 (ix), e
	ld	-12 (ix), d
	ld	-11 (ix), e
	ld	-10 (ix), d
	ld	-5 (ix), e
	ld	-4 (ix), d
	ld	-1 (ix), #0x00
00103$:
	ld	a, -1 (ix)
	sub	a, #0x06
	jp	NC, 00101$
;inputtester_app.c:195: sprintf(label, "JOY%d", j + 1);
	ld	c, -1 (ix)
	ld	b, #0x00
	inc	bc
	ld	-7 (ix), c
	ld	-6 (ix), b
	ld	c, e
	ld	b, d
	push	de
	ld	l, -7 (ix)
	ld	h, -6 (ix)
	push	hl
	ld	hl, #___str_14
	push	hl
	push	bc
	call	_sprintf
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
	pop	de
;inputtester_app.c:196: write_string(label, 0xFF - (j * 2), 2, 6 + j);
	ld	a, -1 (ix)
	ld	-14 (ix), a
	add	a, #0x06
	ld	h, a
	ld	a, -1 (ix)
	add	a, a
	ld	c, a
	ld	a, #0xff
	sub	a, c
	ld	-15 (ix), a
	ld	c, -9 (ix)
	ld	b, -8 (ix)
	push	de
	push	hl
	inc	sp
	ld	a, #0x02
	push	af
	inc	sp
	ld	a, -15 (ix)
	push	af
	inc	sp
	push	bc
	call	_write_string
	pop	af
	pop	af
	inc	sp
	pop	de
;inputtester_app.c:198: sprintf(label, "PAD%d", j + 1);
	ld	c, -3 (ix)
	ld	b, -2 (ix)
	push	de
	ld	l, -7 (ix)
	ld	h, -6 (ix)
	push	hl
	ld	hl, #___str_15
	push	hl
	push	bc
	call	_sprintf
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
	pop	de
;inputtester_app.c:199: write_string(label, 0xFF - (j * 2), 2, 14 + j);
	ld	a, -14 (ix)
	add	a, #0x0e
	ld	-14 (ix), a
	ld	c, -13 (ix)
	ld	b, -12 (ix)
	push	de
	ld	d, -14 (ix)
	ld	e,#0x02
	push	de
	ld	a, -15 (ix)
	push	af
	inc	sp
	push	bc
	call	_write_string
	pop	af
	pop	af
	inc	sp
	pop	de
;inputtester_app.c:201: sprintf(label, "SPN%d", j + 1);
	ld	c, -11 (ix)
	ld	b, -10 (ix)
	push	de
	ld	l, -7 (ix)
	ld	h, -6 (ix)
	push	hl
	ld	hl, #___str_16
	push	hl
	push	bc
	call	_sprintf
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
	pop	de
;inputtester_app.c:202: write_string(label, 0xFF - (j * 2), 14, 14 + j);
	ld	c, -5 (ix)
	ld	b, -4 (ix)
	push	de
	ld	d, -14 (ix)
	ld	e,#0x0e
	push	de
	ld	a, -15 (ix)
	push	af
	inc	sp
	push	bc
	call	_write_string
	pop	af
	pop	af
	inc	sp
	pop	de
;inputtester_app.c:193: for (unsigned char j = 0; j < 6; j++)
	inc	-1 (ix)
	jp	00103$
00101$:
;inputtester_app.c:205: write_string("KEYBOARD", 0xFF, 2, 21);
	ld	de, #0x1502
	push	de
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_17
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;inputtester_app.c:207: write_string("MOUSE", 0xFF, 2, 23);
	ld	de, #0x1702
	push	de
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_18
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;inputtester_app.c:208: write_string("WHL", 0xFF, 16, 23);
	ld	de, #0x1710
	push	de
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_19
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;inputtester_app.c:209: write_string("BTNS", 0xFF, 24, 23);
	ld	de, #0x1718
	push	de
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_20
	push	hl
	call	_write_string
;inputtester_app.c:210: }
	ld	sp,ix
	pop	ix
	ret
___str_7:
	.ascii "RLDUABXYLRsS"
	.db 0x00
___str_8:
	.ascii "ALX"
	.db 0x00
___str_9:
	.ascii "ALY"
	.db 0x00
___str_10:
	.ascii "ARX"
	.db 0x00
___str_11:
	.ascii "ARY"
	.db 0x00
___str_12:
	.ascii "POS"
	.db 0x00
___str_13:
	.ascii "SPD  POS"
	.db 0x00
___str_14:
	.ascii "JOY%d"
	.db 0x00
___str_15:
	.ascii "PAD%d"
	.db 0x00
___str_16:
	.ascii "SPN%d"
	.db 0x00
___str_17:
	.ascii "KEYBOARD"
	.db 0x00
___str_18:
	.ascii "MOUSE"
	.db 0x00
___str_19:
	.ascii "WHL"
	.db 0x00
___str_20:
	.ascii "BTNS"
	.db 0x00
;inputtester_app.c:213: void page_btntest(bool showMenuButton, bool showContinueButton)
;	---------------------------------
; Function page_btntest
; ---------------------------------
_page_btntest::
;inputtester_app.c:215: page_frame(showMenuButton, showContinueButton);
	ld	hl, #3+0
	add	hl, sp
	ld	a, (hl)
	push	af
	inc	sp
	ld	hl, #3+0
	add	hl, sp
	ld	a, (hl)
	push	af
	inc	sp
	call	_page_frame
	pop	af
;inputtester_app.c:216: write_string("BUTTON TEST", 0xAA, 15, 4);
	ld	de, #0x040f
	push	de
	ld	a, #0xaa
	push	af
	inc	sp
	ld	hl, #___str_21
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;inputtester_app.c:217: }
	ret
___str_21:
	.ascii "BUTTON TEST"
	.db 0x00
;inputtester_app.c:219: void reset_inputstates()
;	---------------------------------
; Function reset_inputstates
; ---------------------------------
_reset_inputstates::
;inputtester_app.c:221: modeswitchtimer_select = 0;
	ld	hl,#_modeswitchtimer_select + 0
	ld	(hl), #0x00
;inputtester_app.c:222: modeswitchtimer_start = 0;
	ld	hl,#_modeswitchtimer_start + 0
	ld	(hl), #0x00
;inputtester_app.c:223: for (char i = 0; i < 12; i++)
	ld	bc, #_joystick_last+0
	ld	e, #0x00
00104$:
	ld	a, e
	sub	a, #0x0c
	jr	NC,00101$
;inputtester_app.c:225: joystick_last[i] = 1;
	ld	l, e
	ld	h, #0x00
	add	hl, bc
	ld	(hl), #0x01
;inputtester_app.c:223: for (char i = 0; i < 12; i++)
	inc	e
	jr	00104$
00101$:
;inputtester_app.c:227: for (char i = 0; i < 6; i++)
	ld	c, #0x00
00107$:
	ld	a, c
	sub	a, #0x06
	ret	NC
;inputtester_app.c:229: ax_l_last[i] = 1;
	ld	hl, #_ax_l_last
	ld	b, #0x00
	add	hl, bc
	ld	(hl), #0x01
;inputtester_app.c:230: ay_l_last[i] = -1;
	ld	hl, #_ay_l_last
	ld	b, #0x00
	add	hl, bc
	ld	(hl), #0xff
;inputtester_app.c:231: ax_r_last[i] = 1;
	ld	hl, #_ax_r_last
	ld	b, #0x00
	add	hl, bc
	ld	(hl), #0x01
;inputtester_app.c:232: ay_r_last[i] = -1;
	ld	hl, #_ay_r_last
	ld	b, #0x00
	add	hl, bc
	ld	(hl), #0xff
;inputtester_app.c:233: px_last[i] = 1;
	ld	hl, #_px_last
	ld	b, #0x00
	add	hl, bc
	ld	(hl), #0x01
;inputtester_app.c:234: sx_toggle_last[i] = 1;
	ld	hl, #_sx_toggle_last
	ld	b, #0x00
	add	hl, bc
	ld	(hl), #0x01
;inputtester_app.c:235: sx_last[i] = 1;
	ld	hl, #_sx_last
	ld	b, #0x00
	add	hl, bc
	ld	(hl), #0x01
;inputtester_app.c:236: sx_pos[i] = 0;
	ld	l, c
	ld	h, #0x00
	add	hl, hl
	add	hl, hl
	ld	de, #_sx_pos
	add	hl, de
	xor	a, a
	ld	(hl), a
	inc	hl
	ld	(hl), a
	inc	hl
	ld	(hl), a
	inc	hl
	ld	(hl), #0x00
;inputtester_app.c:227: for (char i = 0; i < 6; i++)
	inc	c
;inputtester_app.c:238: }
	jr	00107$
;inputtester_app.c:241: void start_inputtester_digital()
;	---------------------------------
; Function start_inputtester_digital
; ---------------------------------
_start_inputtester_digital::
;inputtester_app.c:243: state = STATE_INPUTTESTER;
	ld	hl,#_state + 0
	ld	(hl), #0x02
;inputtester_app.c:246: page_inputtester_digital();
	call	_page_inputtester_digital
;inputtester_app.c:249: reset_inputstates();
;inputtester_app.c:250: }
	jp  _reset_inputstates
;inputtester_app.c:253: void start_inputtester_analog()
;	---------------------------------
; Function start_inputtester_analog
; ---------------------------------
_start_inputtester_analog::
;inputtester_app.c:255: state = STATE_INPUTTESTERANALOG;
	ld	hl,#_state + 0
	ld	(hl), #0x06
;inputtester_app.c:258: page_inputtester_analog();
	call	_page_inputtester_analog
;inputtester_app.c:261: reset_inputstates();
;inputtester_app.c:262: }
	jp  _reset_inputstates
;inputtester_app.c:265: void start_inputtester_advanced()
;	---------------------------------
; Function start_inputtester_advanced
; ---------------------------------
_start_inputtester_advanced::
;inputtester_app.c:267: state = STATE_INPUTTESTERADVANCED;
	ld	hl,#_state + 0
	ld	(hl), #0x04
;inputtester_app.c:270: page_inputtester_advanced();
	call	_page_inputtester_advanced
;inputtester_app.c:273: enable_sprite(MOUSE_POINTER_SPRITE, sprite_palette_pointer, sprite_size_pointer, 0);
	xor	a, a
	ld	d,a
	ld	e,#0x01
	push	de
	ld	de, #0x0209
	push	de
	call	_enable_sprite
	pop	af
	pop	af
;inputtester_app.c:274: spr_index[MOUSE_POINTER_SPRITE] = sprite_index_pointer_first;
	ld	hl, #(_spr_index + 0x0009)
	ld	(hl), #0x24
;inputtester_app.c:275: spr_on[MOUSE_POINTER_SPRITE] = 0;
	ld	hl, #(_spr_on + 0x0009)
	ld	(hl), #0x00
;inputtester_app.c:276: mse_x_acc = 336;
	ld	hl, #0x0150
	ld	(_mse_x_acc), hl
;inputtester_app.c:277: mse_y_acc = 256;
	ld	l, #0x00
	ld	(_mse_y_acc), hl
;inputtester_app.c:280: reset_inputstates();
;inputtester_app.c:281: }
	jp  _reset_inputstates
;inputtester_app.c:284: void start_btntest()
;	---------------------------------
; Function start_btntest
; ---------------------------------
_start_btntest::
;inputtester_app.c:286: state = STATE_BTNTEST;
	ld	hl,#_state + 0
	ld	(hl), #0x08
;inputtester_app.c:287: btntest_mode = btntest_mode_select;
	ld	hl,#_btntest_mode + 0
	ld	(hl), #0x00
;inputtester_app.c:288: btntest_buttonbank = 0;
	ld	hl,#_btntest_buttonbank + 0
	ld	(hl), #0x00
;inputtester_app.c:289: btntest_buttonindex = 0;
	ld	hl,#_btntest_buttonindex + 0
	ld	(hl), #0x00
;inputtester_app.c:290: btntest_buttonlast = 1;
	ld	hl,#_btntest_buttonlast + 0
	ld	(hl), #0x01
;inputtester_app.c:291: btntest_timer = 0;
	ld	hl,#_btntest_timer + 0
	ld	(hl), #0x00
;inputtester_app.c:292: btntest_counter = 0;
	ld	hl,#_btntest_counter + 0
	ld	(hl), #0x00
;inputtester_app.c:293: btntest_pos = 0;
	ld	hl,#_btntest_pos + 0
	ld	(hl), #0x00
;inputtester_app.c:296: page_btntest(true, false);
	xor	a, a
	ld	d,a
	ld	e,#0x01
	push	de
	call	_page_btntest
	pop	af
;inputtester_app.c:297: write_string("Press the button you want to test", 0xFF, 3, 14);
	ld	de, #0x0e03
	push	de
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_22
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;inputtester_app.c:298: write_string("Remember to enable fast USB polling!", 0xEE, 2, 25);
	ld	de, #0x1902
	push	de
	ld	a, #0xee
	push	af
	inc	sp
	ld	hl, #___str_23
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;inputtester_app.c:299: }
	ret
___str_22:
	.ascii "Press the button you want to test"
	.db 0x00
___str_23:
	.ascii "Remember to enable fast USB polling!"
	.db 0x00
;inputtester_app.c:302: void pushhistory(char new)
;	---------------------------------
; Function pushhistory
; ---------------------------------
_pushhistory::
	push	ix
	ld	ix,#0
	add	ix,sp
;inputtester_app.c:304: for (char h = 1; h < HISTORY_LENGTH; h++)
	ld	c, #0x01
00103$:
;inputtester_app.c:306: history[h - 1] = history[h];
	ld	a,c
	cp	a,#0x07
	jr	NC,00101$
	dec	a
	ld	e, a
	rla
	sbc	a, a
	ld	d, a
	ld	hl, #_history
	add	hl, de
	ex	de, hl
	ld	hl, #_history
	ld	b, #0x00
	add	hl, bc
	ld	a, (hl)
	ld	(de), a
;inputtester_app.c:304: for (char h = 1; h < HISTORY_LENGTH; h++)
	inc	c
	jr	00103$
00101$:
;inputtester_app.c:308: history[HISTORY_LENGTH - 1] = new;
	ld	hl, #(_history + 0x0006)
	ld	a, 4 (ix)
	ld	(hl), a
;inputtester_app.c:309: }
	pop	ix
	ret
;inputtester_app.c:312: void handle_codes()
;	---------------------------------
; Function handle_codes
; ---------------------------------
_handle_codes::
;inputtester_app.c:314: if (!input_up && input_up_last)
	ld	hl,#_input_up+0
	bit	0, (hl)
	jr	NZ,00102$
	ld	hl,#_input_up_last+0
	bit	0, (hl)
	jr	Z,00102$
;inputtester_app.c:316: pushhistory(1);
	ld	a, #0x01
	push	af
	inc	sp
	call	_pushhistory
	inc	sp
00102$:
;inputtester_app.c:318: if (!input_down && input_down_last)
	ld	hl,#_input_down+0
	bit	0, (hl)
	jr	NZ,00105$
	ld	hl,#_input_down_last+0
	bit	0, (hl)
	jr	Z,00105$
;inputtester_app.c:320: pushhistory(2);
	ld	a, #0x02
	push	af
	inc	sp
	call	_pushhistory
	inc	sp
00105$:
;inputtester_app.c:322: if (!input_left && input_left_last)
	ld	hl,#_input_left+0
	bit	0, (hl)
	jr	NZ,00108$
	ld	hl,#_input_left_last+0
	bit	0, (hl)
	jr	Z,00108$
;inputtester_app.c:324: pushhistory(3);
	ld	a, #0x03
	push	af
	inc	sp
	call	_pushhistory
	inc	sp
00108$:
;inputtester_app.c:326: if (!input_right && input_right_last)
	ld	hl,#_input_right+0
	bit	0, (hl)
	jr	NZ,00111$
	ld	hl,#_input_right_last+0
	bit	0, (hl)
	jr	Z,00111$
;inputtester_app.c:328: pushhistory(4);
	ld	a, #0x04
	push	af
	inc	sp
	call	_pushhistory
	inc	sp
00111$:
;inputtester_app.c:330: if (!input_a && input_a_last)
	ld	hl,#_input_a+0
	bit	0, (hl)
	jr	NZ,00114$
	ld	hl,#_input_a_last+0
	bit	0, (hl)
	jr	Z,00114$
;inputtester_app.c:332: pushhistory(5);
	ld	a, #0x05
	push	af
	inc	sp
	call	_pushhistory
	inc	sp
00114$:
;inputtester_app.c:334: if (!input_b && input_b_last)
	ld	hl,#_input_b+0
	bit	0, (hl)
	jr	NZ,00117$
	ld	hl,#_input_b_last+0
	bit	0, (hl)
	jr	Z,00117$
;inputtester_app.c:336: pushhistory(6);
	ld	a, #0x06
	push	af
	inc	sp
	call	_pushhistory
	inc	sp
00117$:
;inputtester_app.c:339: if (history[0] == 1 && history[1] == 1 && history[2] == 2 && history[3] == 2 && history[4] == 3 && history[5] == 4 && history[6] == 5)
	ld	a, (#_history + 0)
	dec	a
	jr	NZ, 00267$
	ld	a, #0x01
	.db	#0x20
00267$:
	xor	a, a
00268$:
	ld	c, a
	ld	de, #_history + 1
	ld	a, c
	or	a, a
	jr	Z,00120$
	ld	a, (de)
	dec	a
	jr	NZ,00120$
	ld	a, (#(_history + 0x0002) + 0)
	sub	a, #0x02
	jr	NZ,00120$
	ld	a, (#(_history + 0x0003) + 0)
	sub	a, #0x02
	jr	NZ,00120$
	ld	a, (#(_history + 0x0004) + 0)
	sub	a, #0x03
	jr	NZ,00120$
	ld	a, (#(_history + 0x0005) + 0)
	sub	a, #0x04
	jr	NZ,00120$
	ld	a, (#(_history + 0x0006) + 0)
	sub	a, #0x05
	jr	NZ,00120$
;inputtester_app.c:341: pushhistory(0);
	xor	a, a
	push	af
	inc	sp
	call	_pushhistory
	inc	sp
;inputtester_app.c:342: state = STATE_START_ATTRACT;
	ld	hl,#_state + 0
	ld	(hl), #0x1e
;inputtester_app.c:343: return;
	ret
00120$:
;inputtester_app.c:346: if (history[0] == 1 && history[1] == 1 && history[2] == 2 && history[3] == 2 && history[4] == 3 && history[5] == 4 && history[6] == 6)
	ld	a, c
	or	a, a
	ret	Z
	ld	a, (de)
	dec	a
	ret	NZ
	ld	a, (#(_history + 0x0002) + 0)
	sub	a, #0x02
	ret	NZ
	ld	a, (#(_history + 0x0003) + 0)
	sub	a, #0x02
	ret	NZ
	ld	a, (#(_history + 0x0004) + 0)
	sub	a, #0x03
	ret	NZ
	ld	a, (#(_history + 0x0005) + 0)
	sub	a, #0x04
	ret	NZ
	ld	a, (#(_history + 0x0006) + 0)
	sub	a, #0x06
	ret	NZ
;inputtester_app.c:348: pushhistory(0);
	xor	a, a
	push	af
	inc	sp
	call	_pushhistory
	inc	sp
;inputtester_app.c:349: state = STATE_START_ZORBLAXX;
	ld	hl,#_state + 0
	ld	(hl), #0x2b
;inputtester_app.c:350: return;
;inputtester_app.c:352: }
	ret
;inputtester_app.c:355: bool modeswitcher()
;	---------------------------------
; Function modeswitcher
; ---------------------------------
_modeswitcher::
;inputtester_app.c:358: if (input_select)
	ld	hl,#_input_select+0
	bit	0, (hl)
	jr	Z,00104$
;inputtester_app.c:360: modeswitchtimer_select++;
	ld	iy, #_modeswitchtimer_select
	inc	0 (iy)
;inputtester_app.c:361: if (modeswitchtimer_select == menu_openholdtime)
	ld	a, 0 (iy)
	sub	a, #0x3c
	jr	NZ,00105$
;inputtester_app.c:363: modeswitchtimer_select = 0;
	ld	0 (iy), #0x00
;inputtester_app.c:364: start_menu();
	call	_start_menu
;inputtester_app.c:365: return 1;
	ld	l, #0x01
	ret
00104$:
;inputtester_app.c:370: modeswitchtimer_select = 0;
	ld	hl,#_modeswitchtimer_select + 0
	ld	(hl), #0x00
00105$:
;inputtester_app.c:372: return 0;
	ld	l, #0x00
;inputtester_app.c:373: }
	ret
;inputtester_app.c:376: void inputtester_digital()
;	---------------------------------
; Function inputtester_digital
; ---------------------------------
_inputtester_digital::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	hl, #-9
	add	hl, sp
	ld	sp, hl
;inputtester_app.c:380: handle_ps2();
	call	_handle_ps2
;inputtester_app.c:383: if (HBLANK_RISING)
	ld	hl,#_hblank+0
	bit	0, (hl)
	jr	Z,00102$
	ld	hl,#_hblank_last+0
	bit	0, (hl)
	jr	NZ,00102$
;inputtester_app.c:385: basic_input();
	call	_basic_input
;inputtester_app.c:386: handle_codes();
	call	_handle_codes
00102$:
;inputtester_app.c:390: if (VBLANK_RISING)
	ld	hl,#_vblank+0
	bit	0, (hl)
	jp	Z, 00117$
	ld	hl,#_vblank_last+0
	bit	0, (hl)
	jp	NZ, 00117$
;inputtester_app.c:393: if (modeswitcher())
	call	_modeswitcher
	bit	0, l
;inputtester_app.c:395: return;
;inputtester_app.c:399: for (char joy = 0; joy < PAD_COUNT; joy++)
	jp	NZ,00117$
	ld	-1 (ix), #0x00
00115$:
	ld	a, -1 (ix)
	sub	a, #0x02
	jp	NC, 00117$
;inputtester_app.c:401: char index = joy * 4;
	ld	a, -1 (ix)
	add	a, a
	add	a, a
	ld	-2 (ix), a
;inputtester_app.c:402: for (char button = 0; button < BUTTON_COUNT; button++)
	ld	a, #<(_pad_offset_y)
	add	a, -1 (ix)
	ld	-9 (ix), a
	ld	a, #>(_pad_offset_y)
	adc	a, #0x00
	ld	-8 (ix), a
	ld	a, #<(_pad_offset_x)
	add	a, -1 (ix)
	ld	-7 (ix), a
	ld	a, #>(_pad_offset_x)
	adc	a, #0x00
	ld	-6 (ix), a
	ld	-3 (ix), #0x00
00112$:
	ld	a, -3 (ix)
	sub	a, #0x0c
	jp	NC, 00116$
;inputtester_app.c:404: char color = (button < 8 ? CHECK_BIT(joystick[index], button) : CHECK_BIT(joystick[index + 1], button - 8)) ? color_button_active : color_button_inactive;
	ld	a, -3 (ix)
	sub	a, #0x08
	jr	NC,00121$
	ld	bc, #_joystick+0
	ld	l, -2 (ix)
	ld	h, #0x00
	add	hl, bc
	ld	c, (hl)
	ld	b, -3 (ix)
	ld	hl, #0x0001
	inc	b
	jr	00181$
00180$:
	add	hl, hl
00181$:
	djnz	00180$
	ld	b, #0x00
	ld	a, l
	and	a, c
	ld	c, a
	ld	a, h
	and	a, b
	jr	00122$
00121$:
	ld	bc, #_joystick+0
	ld	a, -2 (ix)
	inc	a
	ld	l, a
	rla
	sbc	a, a
	ld	h, a
	add	hl, bc
	ld	c, (hl)
	ld	a, -3 (ix)
	add	a, #0xf8
	ld	b, a
	ld	hl, #0x0001
	inc	b
	jr	00183$
00182$:
	add	hl, hl
00183$:
	djnz	00182$
	ld	b, #0x00
	ld	a, l
	and	a, c
	ld	c, a
	ld	a, h
	and	a, b
00122$:
	ld	a, c
	or	a, a
	jr	Z,00119$
	ld	-5 (ix), #0xff
	ld	-4 (ix), #0x00
	jr	00120$
00119$:
	ld	-5 (ix), #0x52
	ld	-4 (ix), #0x00
00120$:
	ld	c, -5 (ix)
;inputtester_app.c:405: write_string(button_symbol[button], color, pad_offset_x[joy] + button_x[button], pad_offset_y[joy] + button_y[button]);
	pop	hl
	push	hl
	ld	e, (hl)
	ld	a, #<(_button_y)
	add	a, -3 (ix)
	ld	l, a
	ld	a, #>(_button_y)
	adc	a, #0x00
	ld	h, a
	ld	a, (hl)
	add	a, e
	ld	-5 (ix), a
	ld	l, -7 (ix)
	ld	h, -6 (ix)
	ld	e, (hl)
	ld	a, #<(_button_x)
	add	a, -3 (ix)
	ld	l, a
	ld	a, #>(_button_x)
	adc	a, #0x00
	ld	h, a
	ld	a, (hl)
	add	a, e
	ld	b, a
	ld	e, -3 (ix)
	ld	d, #0x00
	ld	l, e
	ld	h, d
	add	hl, hl
	add	hl, de
	add	hl, hl
	ex	de, hl
	ld	hl, #_button_symbol
	add	hl, de
	ex	de, hl
	ld	a, -5 (ix)
	push	af
	inc	sp
	push	bc
	inc	sp
	ld	a, c
	push	af
	inc	sp
	push	de
	call	_write_string
	pop	af
	pop	af
	inc	sp
;inputtester_app.c:402: for (char button = 0; button < BUTTON_COUNT; button++)
	inc	-3 (ix)
	jp	00112$
00116$:
;inputtester_app.c:399: for (char joy = 0; joy < PAD_COUNT; joy++)
	inc	-1 (ix)
	jp	00115$
00117$:
;inputtester_app.c:409: }
	ld	sp, ix
	pop	ix
	ret
;inputtester_app.c:412: void inputtester_analog()
;	---------------------------------
; Function inputtester_analog
; ---------------------------------
_inputtester_analog::
	push	ix
	ld	ix,#0
	add	ix,sp
	push	af
	push	af
	dec	sp
;inputtester_app.c:416: handle_ps2();
	call	_handle_ps2
;inputtester_app.c:418: if (HBLANK_RISING)
	ld	hl,#_hblank+0
	bit	0, (hl)
	jr	Z,00114$
	ld	hl,#_hblank_last+0
	bit	0, (hl)
	jr	NZ,00114$
;inputtester_app.c:420: basic_input();
	call	_basic_input
;inputtester_app.c:421: handle_codes();
	call	_handle_codes
;inputtester_app.c:424: if (!input_a && input_a_last)
	ld	hl,#_input_a+0
	bit	0, (hl)
	jr	NZ,00105$
	ld	hl,#_input_a_last+0
	bit	0, (hl)
	jr	Z,00105$
;inputtester_app.c:426: if (analog_pad == 5)
	ld	iy, #_analog_pad
	ld	a, 0 (iy)
	sub	a, #0x05
	jr	NZ,00102$
;inputtester_app.c:428: analog_pad = 0;
	ld	0 (iy), #0x00
	jr	00103$
00102$:
;inputtester_app.c:432: analog_pad += 1;
	ld	hl, #_analog_pad+0
	inc	(hl)
00103$:
;inputtester_app.c:434: page_inputtester_analog();
	call	_page_inputtester_analog
00105$:
;inputtester_app.c:436: if (!input_b && input_b_last)
	ld	hl,#_input_b+0
	bit	0, (hl)
	jr	NZ,00114$
	ld	hl,#_input_b_last+0
	bit	0, (hl)
	jr	Z,00114$
;inputtester_app.c:438: if (analog_pad == 0)
	ld	iy, #_analog_pad
	ld	a, 0 (iy)
	or	a, a
	jr	NZ,00108$
;inputtester_app.c:440: analog_pad = 5;
	ld	0 (iy), #0x05
	jr	00109$
00108$:
;inputtester_app.c:444: analog_pad -= 1;
	ld	a,(#_analog_pad + 0)
	ld	hl, #_analog_pad
	add	a, #0xff
	ld	(hl), a
00109$:
;inputtester_app.c:446: page_inputtester_analog();
	call	_page_inputtester_analog
00114$:
;inputtester_app.c:451: if (VBLANK_RISING)
	ld	hl,#_vblank+0
	bit	0, (hl)
	jp	Z, 00121$
	ld	hl,#_vblank_last+0
	bit	0, (hl)
	jp	NZ, 00121$
;inputtester_app.c:454: if (modeswitcher())
	call	_modeswitcher
	bit	0, l
;inputtester_app.c:456: return;
	jp	NZ,00121$
;inputtester_app.c:461: char mx = analog_offset_x[side] + (analog_size / 2);
	ld	a, (#_analog_offset_x + 0)
	add	a, #0x09
	ld	c, a
;inputtester_app.c:462: char my = analog_offset_y[side] + (analog_size / 2);
	ld	a, (#_analog_offset_y + 0)
	add	a, #0x09
	ld	e, a
;inputtester_app.c:465: set_fgcolour(color_analog_grid, analog_x[side] + mx, analog_y[side] + my);
	ld	a, (#_analog_y + 0)
	add	a, e
	ld	b, a
	ld	hl, #_analog_x + 0
	ld	l, (hl)
	ld	-4 (ix), c
	ld	a, l
	add	a, -4 (ix)
	push	de
	push	bc
	inc	sp
	ld	d,a
	ld	e,#0x23
	push	de
	call	_set_fgcolour
	pop	af
	inc	sp
	pop	de
;inputtester_app.c:467: signed char ax = analog_l[(analog_pad * 2)];
	ld	bc, #_analog_l+0
	ld	iy, #_analog_pad
	ld	l, 0 (iy)
	ld	h, #0x00
	add	hl, hl
	add	hl, bc
	ld	a, (hl)
	ld	-3 (ix), a
;inputtester_app.c:468: signed char ay = analog_l[(analog_pad * 2) + 1];
	ld	bc, #_analog_l+0
	ld	a, 0 (iy)
	add	a, a
	inc	a
	ld	l, a
	rla
	sbc	a, a
	ld	h, a
	add	hl, bc
	ld	a, (hl)
	ld	-5 (ix), a
;inputtester_app.c:470: analog_x[side] = ax / analog_ratio;
	ld	a, -3 (ix)
	ld	c, a
	rla
	sbc	a, a
	ld	b, a
	push	de
	ld	hl, #0x000f
	push	hl
	push	bc
	call	__divsint
	pop	af
	pop	af
	pop	de
	ld	d, l
	ld	hl, #_analog_x
	ld	(hl), d
;inputtester_app.c:471: analog_y[side] = ay / analog_ratio;
	ld	a, -5 (ix)
	ld	c, a
	rla
	sbc	a, a
	ld	b, a
	push	de
	ld	hl, #0x000f
	push	hl
	push	bc
	call	__divsint
	pop	af
	pop	af
	pop	de
	ld	a, l
	ld	(#_analog_y),a
;inputtester_app.c:474: set_fgcolour(0xFF, analog_x[side] + mx, analog_y[side] + my);
	add	a, e
	ld	b, a
	ld	a, d
	add	a, -4 (ix)
	push	bc
	inc	sp
	ld	d,a
	ld	e,#0xff
	push	de
	call	_set_fgcolour
	pop	af
	inc	sp
;inputtester_app.c:476: write_stringfs("%4d", 0xFF, analog_offset_x[side] + 3, analog_offset_y[side] + analog_size + 1, ax);
	ld	a, (#_analog_offset_y + 0)
	add	a, #0x13
	ld	b, a
	ld	a, (#_analog_offset_x + 0)
	ld	c, a
	inc	c
	inc	c
	inc	c
	ld	a, -3 (ix)
	push	af
	inc	sp
	push	bc
	inc	sp
	ld	d, c
	ld	e,#0xff
	push	de
	ld	hl, #___str_24
	push	hl
	call	_write_stringfs
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
;inputtester_app.c:477: write_stringfs("%4d", 0xFF, analog_offset_x[side] + 12, analog_offset_y[side] + analog_size + 1, ay);
	ld	a, (#_analog_offset_y + 0)
	add	a, #0x13
	ld	b, a
	ld	a, (#_analog_offset_x + 0)
	add	a, #0x0c
	ld	c, a
	ld	a, -5 (ix)
	push	af
	inc	sp
	push	bc
	inc	sp
	ld	d, c
	ld	e,#0xff
	push	de
	ld	hl, #___str_24
	push	hl
	call	_write_stringfs
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
;inputtester_app.c:481: mx = analog_offset_x[side] + (analog_size / 2);
	ld	a, (#(_analog_offset_x + 0x0001) + 0)
	add	a, #0x09
	ld	e, a
;inputtester_app.c:482: my = analog_offset_y[side] + (analog_size / 2);
	ld	a, (#(_analog_offset_y + 0x0001) + 0)
	add	a, #0x09
	ld	c, a
;inputtester_app.c:485: set_fgcolour(color_analog_grid, analog_x[side] + mx, analog_y[side] + my);
	ld	hl, #(_analog_y + 0x0001) + 0
	ld	l, (hl)
	ld	-5 (ix), c
	ld	a, l
	add	a, -5 (ix)
	ld	c, a
	ld	a, (#(_analog_x + 0x0001) + 0)
	add	a, e
	ld	b, a
	push	de
	ld	a, c
	push	af
	inc	sp
	push	bc
	inc	sp
	ld	a, #0x23
	push	af
	inc	sp
	call	_set_fgcolour
	pop	af
	inc	sp
	pop	de
;inputtester_app.c:487: ax = analog_r[(analog_pad * 2)];
	ld	bc, #_analog_r+0
	ld	iy, #_analog_pad
	ld	l, 0 (iy)
	ld	h, #0x00
	add	hl, hl
	add	hl, bc
	ld	a, (hl)
	ld	-1 (ix), a
;inputtester_app.c:488: ay = analog_r[(analog_pad * 2) + 1];
	ld	bc, #_analog_r+0
	ld	a, 0 (iy)
	add	a, a
	inc	a
	ld	l, a
	rla
	sbc	a, a
	ld	h, a
	add	hl, bc
	ld	a, (hl)
	ld	-2 (ix), a
;inputtester_app.c:490: analog_x[side] = ax / analog_ratio;
	ld	a, -1 (ix)
	ld	c, a
	rla
	sbc	a, a
	ld	b, a
	push	de
	ld	hl, #0x000f
	push	hl
	push	bc
	call	__divsint
	pop	af
	pop	af
	pop	de
	ld	d, l
	ld	hl, #(_analog_x + 0x0001)
	ld	(hl), d
;inputtester_app.c:491: analog_y[side] = ay / analog_ratio;
	ld	a, -2 (ix)
	ld	c, a
	rla
	sbc	a, a
	ld	b, a
	push	de
	ld	hl, #0x000f
	push	hl
	push	bc
	call	__divsint
	pop	af
	pop	af
	pop	de
	ld	a, l
	ld	(#(_analog_y + 0x0001)),a
;inputtester_app.c:494: set_fgcolour(0xFF, analog_x[side] + mx, analog_y[side] + my);
	add	a, -5 (ix)
	ld	c, a
	ld	a, d
	add	a, e
	ld	b, a
	ld	a, c
	push	af
	inc	sp
	push	bc
	inc	sp
	ld	a, #0xff
	push	af
	inc	sp
	call	_set_fgcolour
	pop	af
	inc	sp
;inputtester_app.c:496: write_stringfs("%4d", 0xFF, analog_offset_x[side] + 3, analog_offset_y[side] + analog_size + 1, ax);
	ld	a, (#(_analog_offset_y + 0x0001) + 0)
	add	a, #0x13
	ld	e, a
	ld	a, (#(_analog_offset_x + 0x0001) + 0)
	ld	c, a
	inc	c
	inc	c
	inc	c
	ld	d, -1 (ix)
	push	de
	ld	d, c
	ld	e,#0xff
	push	de
	ld	hl, #___str_24
	push	hl
	call	_write_stringfs
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
;inputtester_app.c:497: write_stringfs("%4d", 0xFF, analog_offset_x[side] + 12, analog_offset_y[side] + analog_size + 1, ay);
	ld	a, (#(_analog_offset_y + 0x0001) + 0)
	add	a, #0x13
	ld	b, a
	ld	a, (#(_analog_offset_x + 0x0001) + 0)
	add	a, #0x0c
	ld	c, a
	ld	a, -2 (ix)
	push	af
	inc	sp
	push	bc
	inc	sp
	ld	d, c
	ld	e,#0xff
	push	de
	ld	hl, #___str_24
	push	hl
	call	_write_stringfs
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
00121$:
;inputtester_app.c:499: }
	ld	sp, ix
	pop	ix
	ret
___str_24:
	.ascii "%4d"
	.db 0x00
;inputtester_app.c:502: void inputtester_advanced()
;	---------------------------------
; Function inputtester_advanced
; ---------------------------------
_inputtester_advanced::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	hl, #-63
	add	hl, sp
	ld	sp, hl
;inputtester_app.c:506: handle_ps2();
	call	_handle_ps2
;inputtester_app.c:509: if (HBLANK_RISING)
	ld	hl,#_hblank+0
	bit	0, (hl)
	jr	Z,00102$
	ld	hl,#_hblank_last+0
	bit	0, (hl)
	jr	NZ,00102$
;inputtester_app.c:511: basic_input();
	call	_basic_input
;inputtester_app.c:512: handle_codes();
	call	_handle_codes
00102$:
;inputtester_app.c:516: if (VBLANK_RISING)
	ld	hl,#_vblank+0
	bit	0, (hl)
	jp	Z, 00176$
	ld	hl,#_vblank_last+0
	bit	0, (hl)
	jp	NZ, 00176$
;inputtester_app.c:519: if (modeswitcher())
	call	_modeswitcher
	bit	0, l
	jr	Z,00207$
;inputtester_app.c:521: clear_sprites();
	call	_clear_sprites
;inputtester_app.c:522: update_sprites();
	call	_update_sprites
;inputtester_app.c:523: return;
	jp	00176$
;inputtester_app.c:527: for (char inputindex = 0; inputindex < 6; inputindex++)
00207$:
	ld	hl, #0x0005
	add	hl, sp
	ld	-48 (ix), l
	ld	-47 (ix), h
	ld	a, -48 (ix)
	ld	-42 (ix), a
	ld	a, -47 (ix)
	ld	-41 (ix), a
	ld	a, -48 (ix)
	ld	-39 (ix), a
	ld	a, -47 (ix)
	ld	-38 (ix), a
	ld	a, -48 (ix)
	ld	-32 (ix), a
	ld	a, -47 (ix)
	ld	-31 (ix), a
	ld	hl, #0x0000
	add	hl, sp
	ld	-24 (ix), l
	ld	-23 (ix), h
	ld	a, -24 (ix)
	ld	-22 (ix), a
	ld	a, -23 (ix)
	ld	-21 (ix), a
	ld	-6 (ix), #0x00
00168$:
	ld	a, -6 (ix)
	sub	a, #0x06
	jp	NC, 00127$
;inputtester_app.c:530: char cx = 6;
	ld	-8 (ix), #0x06
;inputtester_app.c:531: char y = 6 + inputindex;
	ld	a, -6 (ix)
	add	a, #0x06
	ld	-9 (ix), a
;inputtester_app.c:532: char inputoffset = (inputindex * 4);
	ld	a, -6 (ix)
	add	a, a
	add	a, a
	ld	-1 (ix), a
;inputtester_app.c:533: char lastoffset = (inputindex * 2);
	ld	a, -6 (ix)
	add	a, a
	ld	-2 (ix), a
;inputtester_app.c:534: for (char b = 0; b < 2; b++)
	ld	c, #0x00
00165$:
;inputtester_app.c:536: char index = b + inputoffset;
	ld	a,c
	cp	a,#0x02
	jp	NC,00110$
	add	a, -1 (ix)
	ld	e, a
;inputtester_app.c:537: char lastindex = b + lastoffset;
	ld	a, c
	add	a, -2 (ix)
	ld	b, a
;inputtester_app.c:538: char joy = joystick[index];
	ld	hl, #_joystick+0
	ld	d, #0x00
	add	hl, de
	ld	a, (hl)
	ld	-10 (ix), a
;inputtester_app.c:539: if (joy != joystick_last[lastindex])
	ld	a, #<(_joystick_last)
	add	a, b
	ld	e, a
	ld	a, #>(_joystick_last)
	adc	a, #0x00
	ld	d, a
	ld	a, (de)
	ld	b, a
	ld	a, -10 (ix)
	sub	a, b
	jr	Z,00108$
;inputtester_app.c:541: mask = 0b00000001;
	ld	-7 (ix), #0x01
;inputtester_app.c:542: char bytes = (b == 0 ? 8 : 4);
	ld	a, c
	or	a, a
	jr	NZ,00178$
	ld	-46 (ix), #0x08
	ld	-45 (ix), #0x00
	jr	00179$
00178$:
	ld	-46 (ix), #0x04
	ld	-45 (ix), #0x00
00179$:
	ld	a, -46 (ix)
	ld	-11 (ix), a
;inputtester_app.c:543: for (char i = 0; i < bytes; i++)
	ld	b, -8 (ix)
	ld	-12 (ix), #0x00
00162$:
	ld	a, -12 (ix)
	sub	a, -11 (ix)
	jr	NC,00229$
;inputtester_app.c:545: cx++;
	inc	b
;inputtester_app.c:546: write_char((joy & mask) ? asc_1 : asc_0, 0xFF, cx, y);
	ld	a, -10 (ix)
	and	a, -7 (ix)
	or	a, a
	jr	Z,00180$
	ld	a,(#_asc_1 + 0)
	ld	-46 (ix), a
	jr	00181$
00180$:
	ld	a,(#_asc_0 + 0)
	ld	-46 (ix), a
00181$:
	push	bc
	push	de
	ld	a, -9 (ix)
	push	af
	inc	sp
	push	bc
	inc	sp
	ld	a, #0xff
	push	af
	inc	sp
	ld	a, -46 (ix)
	push	af
	inc	sp
	call	_write_char
	pop	af
	pop	af
	pop	de
	pop	bc
;inputtester_app.c:547: mask <<= 1;
	ld	a, -7 (ix)
	add	a, a
	ld	-7 (ix), a
;inputtester_app.c:543: for (char i = 0; i < bytes; i++)
	inc	-12 (ix)
	jr	00162$
00108$:
;inputtester_app.c:552: cx += 8;
	ld	a, -8 (ix)
	add	a, #0x08
	ld	-8 (ix), a
;inputtester_app.c:698: update_sprites();
	jr	00109$
;inputtester_app.c:552: cx += 8;
00229$:
	ld	-8 (ix), b
00109$:
;inputtester_app.c:554: joystick_last[lastindex] = joy;
	ld	a, -10 (ix)
	ld	(de), a
;inputtester_app.c:534: for (char b = 0; b < 2; b++)
	inc	c
	jp	00165$
00110$:
;inputtester_app.c:559: signed char ax_l = analog_l[(inputindex * 2)];
	ld	l, -6 (ix)
	ld	h, #0x00
	add	hl, hl
	ld	de, #_analog_l
	add	hl, de
	ld	a, (hl)
	ld	-13 (ix), a
;inputtester_app.c:560: signed char ay_l = analog_l[(inputindex * 2) + 1];
	ld	a, -6 (ix)
	add	a, a
	inc	a
	ld	c, a
	rla
	sbc	a, a
	ld	b, a
	ld	hl, #_analog_l
	add	hl, bc
	ld	b, (hl)
;inputtester_app.c:561: if (ax_l != ax_l_last[inputindex] || ay_l != ay_l_last[inputindex])
	ld	a, #<(_ax_l_last)
	add	a, -6 (ix)
	ld	e, a
	ld	a, #>(_ax_l_last)
	adc	a, #0x00
	ld	d, a
	ld	a, (de)
	ld	c, a
	ld	a, -13 (ix)
	sub	a, c
	jr	NZ,00111$
	ld	a, #<(_ay_l_last)
	add	a, -6 (ix)
	ld	l, a
	ld	a, #>(_ay_l_last)
	adc	a, #0x00
	ld	h, a
	ld	a, (hl)
	sub	a, b
	jr	Z,00112$
00111$:
;inputtester_app.c:563: sprintf(stra, "%4d%4d", ax_l, ay_l);
	ld	a, b
	ld	l, a
	rla
	sbc	a, a
	ld	h, a
	ld	a, -13 (ix)
	ld	-46 (ix), a
	rla
	sbc	a, a
	ld	-45 (ix), a
	push	hl
	ld	l, -48 (ix)
	ld	h, -47 (ix)
	push	hl
	pop	iy
	pop	hl
	push	bc
	push	de
	push	hl
	ld	l, -46 (ix)
	ld	h, -45 (ix)
	push	hl
	ld	hl, #___str_25
	push	hl
	push	iy
	call	_sprintf
	ld	hl, #8
	add	hl, sp
	ld	sp, hl
	pop	de
	pop	bc
;inputtester_app.c:564: write_string(stra, 0xFF, 20, 6 + inputindex);
	ld	a, -6 (ix)
	add	a, #0x06
	ld	h, a
	ld	l, -42 (ix)
	ld	c, -41 (ix)
	push	bc
	push	de
	push	hl
	inc	sp
	ld	de, #0x14ff
	push	de
	ld	h, c
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
	pop	de
	pop	bc
00112$:
;inputtester_app.c:566: ax_l_last[inputindex] = ax_l;
	ld	a, -13 (ix)
	ld	(de), a
;inputtester_app.c:567: ay_l_last[inputindex] = ay_l;
	ld	a, #<(_ay_l_last)
	add	a, -6 (ix)
	ld	l, a
	ld	a, #>(_ay_l_last)
	adc	a, #0x00
	ld	h, a
	ld	(hl), b
;inputtester_app.c:570: signed char ax_r = analog_r[(inputindex * 2)];
	ld	l, -6 (ix)
	ld	h, #0x00
	add	hl, hl
	ld	de, #_analog_r
	add	hl, de
	ld	a, (hl)
	ld	-19 (ix), a
;inputtester_app.c:571: signed char ay_r = analog_r[(inputindex * 2) + 1];
	ld	a, -6 (ix)
	add	a, a
	inc	a
	ld	c, a
	rla
	sbc	a, a
	ld	b, a
	ld	hl, #_analog_r
	add	hl, bc
	ld	b, (hl)
;inputtester_app.c:572: if (ax_r != ax_r_last[inputindex] || ay_r != ay_r_last[inputindex])
	ld	a, #<(_ax_r_last)
	add	a, -6 (ix)
	ld	e, a
	ld	a, #>(_ax_r_last)
	adc	a, #0x00
	ld	d, a
	ld	a, (de)
	ld	c, a
	ld	a, -19 (ix)
	sub	a, c
	jr	NZ,00114$
	ld	a, #<(_ay_r_last)
	add	a, -6 (ix)
	ld	l, a
	ld	a, #>(_ay_r_last)
	adc	a, #0x00
	ld	h, a
	ld	a, (hl)
	sub	a, b
	jr	Z,00115$
00114$:
;inputtester_app.c:574: sprintf(stra, "%4d%4d", ax_r, ay_r);
	ld	a, b
	ld	l, a
	rla
	sbc	a, a
	ld	h, a
	ld	a, -19 (ix)
	ld	-46 (ix), a
	rla
	sbc	a, a
	ld	-45 (ix), a
	push	hl
	ld	l, -39 (ix)
	ld	h, -38 (ix)
	push	hl
	pop	iy
	pop	hl
	push	bc
	push	de
	push	hl
	ld	l, -46 (ix)
	ld	h, -45 (ix)
	push	hl
	ld	hl, #___str_25
	push	hl
	push	iy
	call	_sprintf
	ld	hl, #8
	add	hl, sp
	ld	sp, hl
	pop	de
	pop	bc
;inputtester_app.c:575: write_string(stra, 0xFF, 29, 6 + inputindex);
	ld	a, -6 (ix)
	add	a, #0x06
	ld	h, a
	ld	l, -32 (ix)
	ld	c, -31 (ix)
	push	bc
	push	de
	push	hl
	inc	sp
	ld	de, #0x1dff
	push	de
	ld	h, c
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
	pop	de
	pop	bc
00115$:
;inputtester_app.c:577: ax_r_last[inputindex] = ax_r;
	ld	a, -19 (ix)
	ld	(de), a
;inputtester_app.c:578: ay_r_last[inputindex] = ay_r;
	ld	a, #<(_ay_r_last)
	add	a, -6 (ix)
	ld	l, a
	ld	a, #>(_ay_r_last)
	adc	a, #0x00
	ld	h, a
	ld	(hl), b
;inputtester_app.c:581: unsigned char px = paddle[(inputindex)];
	ld	bc, #_paddle+0
	ld	l, -6 (ix)
	ld	h, #0x00
	add	hl, bc
	ld	a, (hl)
	ld	-20 (ix), a
;inputtester_app.c:582: if (px != px_last[inputindex])
	ld	a, #<(_px_last)
	add	a, -6 (ix)
	ld	e, a
	ld	a, #>(_px_last)
	adc	a, #0x00
	ld	d, a
	ld	a, (de)
	ld	c, a
	ld	a, -20 (ix)
	sub	a, c
	jr	Z,00118$
;inputtester_app.c:585: sprintf(strp, "%4d", px);
	ld	l, -20 (ix)
	ld	h, #0x00
	ld	c, -24 (ix)
	ld	b, -23 (ix)
	push	de
	push	hl
	ld	hl, #___str_26
	push	hl
	push	bc
	call	_sprintf
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
	pop	de
;inputtester_app.c:586: write_string(strp, 0xFF, 6, 14 + inputindex);
	ld	a, -6 (ix)
	add	a, #0x0e
	ld	c, a
	ld	l, -22 (ix)
	ld	h, -21 (ix)
	push	de
	ld	d, c
	ld	e,#0x06
	push	de
	ld	a, #0xff
	push	af
	inc	sp
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
	pop	de
00118$:
;inputtester_app.c:588: px_last[inputindex] = px;
	ld	a, -20 (ix)
	ld	(de), a
;inputtester_app.c:591: bool sx_toggle = CHECK_BIT(spinner[(inputindex * 2) + 1], 0);
	ld	a, -6 (ix)
	add	a, a
	inc	a
	ld	c, a
	rla
	sbc	a, a
	ld	b, a
	ld	hl, #_spinner
	add	hl, bc
	ld	a, (hl)
	and	a, #0x01
	ld	c, a
;inputtester_app.c:592: signed char sx = spinner[(inputindex * 2)];
	ld	a, -6 (ix)
	ld	-46 (ix), a
	ld	-45 (ix), #0x00
	ld	l, a
	ld	h, #0x00
	add	hl, hl
	ld	de, #_spinner
	add	hl, de
	ld	a, (hl)
	ld	-18 (ix), a
;inputtester_app.c:593: if (sx_toggle != sx_toggle_last[inputindex])
	ld	a, #<(_sx_toggle_last)
	add	a, -6 (ix)
	ld	-44 (ix), a
	ld	a, #>(_sx_toggle_last)
	adc	a, #0x00
	ld	-43 (ix), a
	ld	l, -44 (ix)
	ld	h, -43 (ix)
	ld	b, (hl)
	ld	-40 (ix), c
;inputtester_app.c:531: char y = 6 + inputindex;
	ld	a, -6 (ix)
;inputtester_app.c:596: write_stringf("%4d", 0xFF, 24, 14 + inputindex, sx_pos[inputindex]);
	add	a, #0x0e
	ld	-37 (ix), a
;inputtester_app.c:593: if (sx_toggle != sx_toggle_last[inputindex])
	ld	a, -40 (ix)
	sub	a, b
	jp	Z,00123$
;inputtester_app.c:595: sx_pos[inputindex] += sx;
	ld	a, #0x02+1
	jr	00408$
00407$:
	sla	-46 (ix)
	rl	-45 (ix)
00408$:
	dec	a
	jr	NZ,00407$
	ld	a, #<(_sx_pos)
	add	a, -46 (ix)
	ld	-46 (ix), a
	ld	a, #>(_sx_pos)
	adc	a, -45 (ix)
	ld	-45 (ix), a
	ld	e, -46 (ix)
	ld	d, -45 (ix)
	ld	hl, #0x001b
	add	hl, sp
	ex	de, hl
	ld	bc, #0x0004
	ldir
	ld	a, -18 (ix)
	ld	-30 (ix), a
	rla
	sbc	a, a
	ld	-29 (ix), a
	ld	a, -30 (ix)
	ld	-28 (ix), a
	ld	a, -29 (ix)
	ld	-27 (ix), a
	rla
	sbc	a, a
	ld	-26 (ix), a
	ld	-25 (ix), a
	ld	a, -36 (ix)
	add	a, -28 (ix)
	ld	-28 (ix), a
	ld	a, -35 (ix)
	adc	a, -27 (ix)
	ld	-27 (ix), a
	ld	a, -34 (ix)
	adc	a, -26 (ix)
	ld	-26 (ix), a
	ld	a, -33 (ix)
	adc	a, -25 (ix)
	ld	-25 (ix), a
	ld	e, -46 (ix)
	ld	d, -45 (ix)
	ld	hl, #0x0023
	add	hl, sp
	ld	bc, #0x0004
	ldir
;inputtester_app.c:596: write_stringf("%4d", 0xFF, 24, 14 + inputindex, sx_pos[inputindex]);
	ld	b, -28 (ix)
	push	bc
	inc	sp
	ld	d, -37 (ix)
	ld	e,#0x18
	push	de
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_26
	push	hl
	call	_write_stringf
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
	jr	00124$
00123$:
;inputtester_app.c:600: if (sx == 1 || sx == -1)
	ld	a, -18 (ix)
	dec	a
	jr	Z,00119$
	ld	a, -18 (ix)
	inc	a
	jr	NZ,00124$
00119$:
;inputtester_app.c:602: sx = 0;
	ld	-18 (ix), #0x00
00124$:
;inputtester_app.c:605: if (sx_last[inputindex] != sx)
	ld	a, #<(_sx_last)
	add	a, -6 (ix)
	ld	-28 (ix), a
	ld	a, #>(_sx_last)
	adc	a, #0x00
	ld	-27 (ix), a
	ld	l, -28 (ix)
	ld	h, -27 (ix)
	ld	a,-18 (ix)
	sub	a,(hl)
	jr	Z,00126$
;inputtester_app.c:607: write_stringfs("%4d", 0xFF, 19, 14 + inputindex, sx);
	ld	a, -18 (ix)
	push	af
	inc	sp
	ld	d, -37 (ix)
	ld	e,#0x13
	push	de
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_26
	push	hl
	call	_write_stringfs
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
00126$:
;inputtester_app.c:609: sx_last[inputindex] = sx;
	ld	l, -28 (ix)
	ld	h, -27 (ix)
	ld	a, -18 (ix)
	ld	(hl), a
;inputtester_app.c:610: sx_toggle_last[inputindex] = sx_toggle;
	ld	l, -44 (ix)
	ld	h, -43 (ix)
	ld	a, -40 (ix)
	ld	(hl), a
;inputtester_app.c:527: for (char inputindex = 0; inputindex < 6; inputindex++)
	inc	-6 (ix)
	jp	00168$
00127$:
;inputtester_app.c:614: if (kbd_scan != kbd_scan_last || kbd_ascii != kbd_ascii_last)
	ld	a,(#_kbd_scan + 0)
	ld	iy, #_kbd_scan_last
	sub	a, 0 (iy)
	jr	NZ,00128$
	ld	a,(#_kbd_ascii + 0)
	ld	iy, #_kbd_ascii_last
	sub	a, 0 (iy)
	jr	Z,00129$
00128$:
;inputtester_app.c:616: write_stringf("%02x", 0xFF, 11, 21, kbd_scan);
	ld	a, (_kbd_scan)
	ld	d,a
	ld	e,#0x15
	push	de
	ld	de, #0x0bff
	push	de
	ld	hl, #___str_27
	push	hl
	call	_write_stringf
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
;inputtester_app.c:617: write_char(kbd_ascii, 0xFF, 14, 21);
	ld	de, #0x150e
	push	de
	ld	a, #0xff
	push	af
	inc	sp
	ld	a, (_kbd_ascii)
	push	af
	inc	sp
	call	_write_char
	pop	af
	pop	af
;inputtester_app.c:619: kbd_scan_last = kbd_scan;
	ld	a,(#_kbd_scan + 0)
	ld	(#_kbd_scan_last + 0),a
;inputtester_app.c:620: kbd_ascii_last = kbd_ascii;
	ld	a,(#_kbd_ascii + 0)
	ld	(#_kbd_ascii_last + 0),a
00129$:
;inputtester_app.c:623: if (mse_changed)
	ld	hl,#_mse_changed+0
	bit	0, (hl)
	jp	Z, 00157$
;inputtester_app.c:626: mse_x_acc += mse_x;
	ld	a,(#_mse_x + 0)
	ld	c, a
	rla
	sbc	a, a
	ld	b, a
	ld	hl, #_mse_x_acc
	ld	a, (hl)
	add	a, c
	ld	(hl), a
	inc	hl
	ld	a, (hl)
	adc	a, b
	ld	(hl), a
;inputtester_app.c:627: mse_y_acc -= mse_y;
	ld	a,(#_mse_y + 0)
	ld	c, a
	rla
	sbc	a, a
	ld	b, a
	ld	hl, #_mse_y_acc
	ld	a, (hl)
	sub	a, c
	ld	(hl), a
	inc	hl
	ld	a, (hl)
	sbc	a, b
	ld	(hl), a
;inputtester_app.c:628: mse_w_acc += mse_w;
	ld	a,(#_mse_w + 0)
	ld	c, a
	rla
	sbc	a, a
	ld	b, a
	ld	hl, #_mse_w_acc
	ld	a, (hl)
	add	a, c
	ld	(hl), a
	inc	hl
	ld	a, (hl)
	adc	a, b
	ld	(hl), a
;inputtester_app.c:631: if (mse_x_acc < 32)
	ld	iy, #_mse_x_acc
	ld	a, 0 (iy)
	sub	a, #0x20
	ld	a, 1 (iy)
	rla
	ccf
	rra
	sbc	a, #0x80
	jr	NC,00134$
;inputtester_app.c:633: mse_x_acc = 32;
	ld	hl, #0x0020
	ld	(_mse_x_acc), hl
	jr	00135$
00134$:
;inputtester_app.c:635: else if (mse_x_acc >= 671)
	ld	iy, #_mse_x_acc
	ld	a, 0 (iy)
	sub	a, #0x9f
	ld	a, 1 (iy)
	rla
	ccf
	rra
	sbc	a, #0x82
	jr	C,00135$
;inputtester_app.c:637: mse_x_acc = 671;
	ld	hl, #0x029f
	ld	(_mse_x_acc), hl
00135$:
;inputtester_app.c:639: if (mse_y_acc < 32)
	ld	iy, #_mse_y_acc
	ld	a, 0 (iy)
	sub	a, #0x20
	ld	a, 1 (iy)
	rla
	ccf
	rra
	sbc	a, #0x80
	jr	NC,00139$
;inputtester_app.c:641: mse_y_acc = 32;
	ld	hl, #0x0020
	ld	(_mse_y_acc), hl
	jr	00140$
00139$:
;inputtester_app.c:643: else if (mse_y_acc >= 511)
	ld	iy, #_mse_y_acc
	ld	a, 0 (iy)
	sub	a, #0xff
	ld	a, 1 (iy)
	rla
	ccf
	rra
	sbc	a, #0x81
	jr	C,00140$
;inputtester_app.c:645: mse_y_acc = 511;
	ld	hl, #0x01ff
	ld	(_mse_y_acc), hl
00140$:
;inputtester_app.c:647: unsigned short mx = (mse_x_acc / 2);
	ld	hl, (_mse_x_acc)
	bit	7, h
	jr	Z,00182$
	inc	hl
00182$:
	ld	-15 (ix), l
	ld	-14 (ix), h
	srl	-14 (ix)
	rr	-15 (ix)
;inputtester_app.c:648: unsigned short my = (mse_y_acc / 2);
	ld	hl, (_mse_y_acc)
	bit	7, h
	jr	Z,00183$
	inc	hl
00183$:
	ld	-17 (ix), l
	ld	-16 (ix), h
	srl	-16 (ix)
	rr	-17 (ix)
;inputtester_app.c:649: if (mse_x != 0 || mse_y != 0)
	ld	a,(#_mse_x + 0)
	or	a, a
	jr	NZ,00141$
	ld	a,(#_mse_y + 0)
	or	a, a
	jr	Z,00142$
00141$:
;inputtester_app.c:651: spr_on[MOUSE_POINTER_SPRITE] = 1;
	ld	hl, #(_spr_on + 0x0009)
	ld	(hl), #0x01
;inputtester_app.c:652: set_sprite_position(MOUSE_POINTER_SPRITE, mx, my);
	ld	l, -17 (ix)
	ld	h, -16 (ix)
	push	hl
	ld	l, -15 (ix)
	ld	h, -14 (ix)
	push	hl
	ld	a, #0x09
	push	af
	inc	sp
	call	_set_sprite_position
	pop	af
	pop	af
	inc	sp
00142$:
;inputtester_app.c:654: write_stringf_ushort("%3d", 0xFF, 8, 23, mx - 16);
	ld	a, -15 (ix)
	add	a, #0xf0
	ld	c, a
	ld	a, -14 (ix)
	adc	a, #0xff
	ld	b, a
	push	bc
	ld	de, #0x1708
	push	de
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_28
	push	hl
	call	_write_stringf_ushort
	ld	hl, #7
	add	hl, sp
	ld	sp, hl
;inputtester_app.c:655: write_stringf_ushort("%3d", 0xFF, 12, 23, my - 16);
	ld	a, -17 (ix)
	add	a, #0xf0
	ld	c, a
	ld	a, -16 (ix)
	adc	a, #0xff
	ld	b, a
	push	bc
	ld	de, #0x170c
	push	de
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_28
	push	hl
	call	_write_stringf_ushort
	ld	hl, #7
	add	hl, sp
	ld	sp, hl
;inputtester_app.c:656: write_stringf("%3d", 0xFF, 20, 23, mse_w_acc);
	ld	a,(#_mse_w_acc + 0)
	ld	d,a
	ld	e,#0x17
	push	de
	ld	de, #0x14ff
	push	de
	ld	hl, #___str_28
	push	hl
	call	_write_stringf
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
;inputtester_app.c:658: if (mse_button1_last != mse_button1)
	ld	a,(#_mse_button1_last + 0)
	ld	iy, #_mse_button1
	sub	a, 0 (iy)
	jr	Z,00146$
;inputtester_app.c:661: char m = 0b00000001;
	ld	-4 (ix), #0x01
;inputtester_app.c:662: for (char i = 0; i < 3; i++)
	ld	-3 (ix), #0x1c
	ld	-5 (ix), #0x00
00171$:
	ld	a, -5 (ix)
	sub	a, #0x03
	jr	NC,00144$
;inputtester_app.c:664: x++;
	inc	-3 (ix)
;inputtester_app.c:665: write_char((mse_button1 & m) ? asc_1 : asc_0, 0xFF, x, 23);
	ld	a,(#_mse_button1 + 0)
	and	a, -4 (ix)
	or	a, a
	jr	Z,00184$
	ld	hl,#_asc_1 + 0
	ld	b, (hl)
	jr	00185$
00184$:
	ld	hl,#_asc_0 + 0
	ld	b, (hl)
00185$:
	ld	a, #0x17
	push	af
	inc	sp
	ld	d, -3 (ix)
	ld	e,#0xff
	push	de
	push	bc
	inc	sp
	call	_write_char
	pop	af
	pop	af
;inputtester_app.c:666: m <<= 1;
	ld	a, -4 (ix)
	add	a, a
	ld	-4 (ix), a
;inputtester_app.c:662: for (char i = 0; i < 3; i++)
	inc	-5 (ix)
	jr	00171$
00144$:
;inputtester_app.c:668: input_mouse_left = CHECK_BIT(mse_button1, 0);
	ld	a,(#_mse_button1 + 0)
	and	a, #0x01
	ld	(#_input_mouse_left + 0),a
;inputtester_app.c:669: input_mouse_right = CHECK_BIT(mse_button1, 1);
	ld	a,(#_mse_button1 + 0)
	and	a, #0x02
	ld	c, a
	xor	a, a
	cp	a, c
	rla
	ld	(#_input_mouse_right + 0),a
00146$:
;inputtester_app.c:671: mse_button1_last = mse_button1;
	ld	a,(#_mse_button1 + 0)
	ld	(#_mse_button1_last + 0),a
;inputtester_app.c:672: if (mse_button2_last != mse_button2)
	ld	a,(#_mse_button2_last + 0)
	ld	iy, #_mse_button2
	sub	a, 0 (iy)
	jr	Z,00149$
;inputtester_app.c:675: char m = 0b00000001;
;inputtester_app.c:676: for (char i = 0; i < 5; i++)
	ld	bc, #0x1f01
	ld	e, #0x00
00174$:
	ld	a, e
	sub	a, #0x05
	jr	NC,00149$
;inputtester_app.c:678: x++;
	inc	b
;inputtester_app.c:679: write_char((mse_button2 & m) ? asc_1 : asc_0, 0xFF, x, 23);
	ld	a,(#_mse_button2 + 0)
	and	a,c
	jr	Z,00186$
	ld	hl,#_asc_1 + 0
	ld	d, (hl)
	jr	00187$
00186$:
	ld	hl,#_asc_0 + 0
	ld	d, (hl)
00187$:
	push	bc
	push	de
	ld	a, #0x17
	push	af
	inc	sp
	push	bc
	inc	sp
	ld	a, #0xff
	push	af
	inc	sp
	push	de
	inc	sp
	call	_write_char
	pop	af
	pop	af
	pop	de
	pop	bc
;inputtester_app.c:680: m <<= 1;
	sla	c
;inputtester_app.c:676: for (char i = 0; i < 5; i++)
	inc	e
	jr	00174$
00149$:
;inputtester_app.c:683: mse_button2_last = mse_button2;
	ld	a,(#_mse_button2 + 0)
	ld	(#_mse_button2_last + 0),a
;inputtester_app.c:687: add_ping(0, mx - 8, my - 8);
	ld	a, -17 (ix)
	add	a, #0xf8
	ld	c, a
	ld	a, -16 (ix)
	adc	a, #0xff
	ld	b, a
	ld	a, -15 (ix)
	add	a, #0xf8
	ld	e, a
	ld	a, -14 (ix)
	adc	a, #0xff
	ld	d, a
;inputtester_app.c:685: if (input_mouse_left && !input_mouse_left_last)
	ld	hl,#_input_mouse_left+0
	bit	0, (hl)
	jr	Z,00151$
	ld	hl,#_input_mouse_left_last+0
	bit	0, (hl)
	jr	NZ,00151$
;inputtester_app.c:687: add_ping(0, mx - 8, my - 8);
	push	bc
	push	de
	push	bc
	push	de
	ld	hl, #0x0000
	push	hl
	call	_add_ping
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
	pop	de
	pop	bc
00151$:
;inputtester_app.c:689: if (input_mouse_right && !input_mouse_right_last)
	ld	hl,#_input_mouse_right+0
	bit	0, (hl)
	jr	Z,00154$
	ld	hl,#_input_mouse_right_last+0
	bit	0, (hl)
	jr	NZ,00154$
;inputtester_app.c:691: add_ping(1, mx - 8, my - 8);
	push	bc
	push	de
	ld	hl, #0x0001
	push	hl
	call	_add_ping
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
00154$:
;inputtester_app.c:694: mse_changed = 0;
	ld	hl,#_mse_changed + 0
	ld	(hl), #0x00
00157$:
;inputtester_app.c:697: handle_pings();
	call	_handle_pings
;inputtester_app.c:698: update_sprites();
	call	_update_sprites
00176$:
;inputtester_app.c:700: }
	ld	sp, ix
	pop	ix
	ret
___str_25:
	.ascii "%4d%4d"
	.db 0x00
___str_26:
	.ascii "%4d"
	.db 0x00
___str_27:
	.ascii "%02x"
	.db 0x00
___str_28:
	.ascii "%3d"
	.db 0x00
;inputtester_app.c:702: void btntest_starttest()
;	---------------------------------
; Function btntest_starttest
; ---------------------------------
_btntest_starttest::
;inputtester_app.c:704: btntest_mode = btntest_mode_test;
	ld	hl,#_btntest_mode + 0
	ld	(hl), #0x02
;inputtester_app.c:705: page_btntest(false, false); // reset screen
	xor	a, a
	push	af
	inc	sp
	xor	a, a
	push	af
	inc	sp
	call	_page_btntest
	pop	af
;inputtester_app.c:708: btntest_timer = btntest_timer_start;
	ld	hl,#_btntest_timer + 0
	ld	(hl), #0x3c
;inputtester_app.c:711: timer[0] = 0;
	ld	hl, #_timer
	ld	(hl), #0x00
;inputtester_app.c:713: write_string("Press here", 0xDD, 14, 14);
	ld	de, #0x0e0e
	push	de
	ld	a, #0xdd
	push	af
	inc	sp
	ld	hl, #___str_29
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;inputtester_app.c:714: write_char(19, 0xDD, 19, 15);
	ld	de, #0x0f13
	push	de
	ld	de, #0xdd13
	push	de
	call	_write_char
	pop	af
	pop	af
;inputtester_app.c:715: write_string("---\x3\x3\x3\x2\x2\x2\x1\x1\x1\xA6\xA6\xA6\x7f\x7f\x7f\xA6\xA6\xA6\x1\x1\x1\x2\x2\x2\x3\x3\x3---", 0xDD, 3, 16);
	ld	de, #0x1003
	push	de
	ld	a, #0xdd
	push	af
	inc	sp
	ld	hl, #___str_30
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;inputtester_app.c:716: }
	ret
___str_29:
	.ascii "Press here"
	.db 0x00
___str_30:
	.ascii "---"
	.db 0x03
	.db 0x03
	.db 0x03
	.db 0x02
	.db 0x02
	.db 0x02
	.db 0x01
	.db 0x01
	.db 0x01
	.db 0xa6
	.db 0xa6
	.db 0xa6
	.db 0x7f
	.db 0x7f
	.db 0x7f
	.db 0xa6
	.db 0xa6
	.db 0xa6
	.db 0x01
	.db 0x01
	.db 0x01
	.db 0x02
	.db 0x02
	.db 0x02
	.db 0x03
	.db 0x03
	.db 0x03
	.ascii "---"
	.db 0x00
;inputtester_app.c:719: void btntest_select()
;	---------------------------------
; Function btntest_select
; ---------------------------------
_btntest_select::
	push	ix
	ld	ix,#0
	add	ix,sp
	dec	sp
;inputtester_app.c:721: if (HBLANK_RISING)
	ld	hl,#_hblank+0
	bit	0, (hl)
	jp	Z, 00107$
	ld	hl,#_hblank_last+0
	bit	0, (hl)
	jp	NZ, 00107$
;inputtester_app.c:725: if (joystick[0] != 0)
	ld	a, (#_joystick + 0)
	or	a, a
	jp	Z, 00107$
;inputtester_app.c:728: for (char b = 0; b < 8; b++)
	ld	-1 (ix), #0x00
	ld	c, #0x00
00113$:
	ld	a, c
	sub	a, #0x08
	jr	NC,00103$
;inputtester_app.c:730: if (CHECK_BIT(joystick[0], b))
	ld	hl, #_joystick+0
	ld	e, (hl)
	ld	b, c
	ld	hl, #0x0001
	inc	b
	jr	00158$
00157$:
	add	hl, hl
00158$:
	djnz	00157$
	ld	b, #0x00
	ld	a, l
	and	a, e
	ld	e, a
	ld	a, h
	and	a, b
	or	a, e
	jr	Z,00114$
;inputtester_app.c:732: btntest_buttonindex = b;
	ld	a, -1 (ix)
	ld	(#_btntest_buttonindex + 0),a
;inputtester_app.c:733: break;
	jr	00103$
00114$:
;inputtester_app.c:728: for (char b = 0; b < 8; b++)
	inc	c
	ld	-1 (ix), c
	jr	00113$
00103$:
;inputtester_app.c:736: btntest_mode = btntest_mode_ready;
	ld	hl,#_btntest_mode + 0
	ld	(hl), #0x01
;inputtester_app.c:737: page_btntest(false, false); // reset screen
	xor	a, a
	push	af
	inc	sp
	xor	a, a
	push	af
	inc	sp
	call	_page_btntest
	pop	af
;inputtester_app.c:738: write_string("Hit the button at each prompt", 0b11111000, 5, 14);
	ld	de, #0x0e05
	push	de
	ld	a, #0xf8
	push	af
	inc	sp
	ld	hl, #___str_31
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;inputtester_app.c:739: write_string("Selected button is: ", 0xFF, 6, 16);
	ld	de, #0x1006
	push	de
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_32
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;inputtester_app.c:740: char i = btntest_buttonindex;
	ld	hl,#_btntest_buttonindex + 0
	ld	c, (hl)
;inputtester_app.c:741: write_string(button_name[i], 0b00000111, 26, 16);
	ld	b, #0x00
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl, hl
	ld	de, #_button_name
	add	hl, de
	ld	de, #0x101a
	push	de
	ld	a, #0x07
	push	af
	inc	sp
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;inputtester_app.c:742: write_string("Press again to start test", 0b00111000, 7, 18);
	ld	de, #0x1207
	push	de
	ld	a, #0x38
	push	af
	inc	sp
	ld	hl, #___str_33
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;inputtester_app.c:743: btntest_timer = 10;
	ld	hl,#_btntest_timer + 0
	ld	(hl), #0x0a
;inputtester_app.c:744: return;
	jr	00115$
00107$:
;inputtester_app.c:747: if (VBLANK_RISING)
	ld	hl,#_vblank+0
	bit	0, (hl)
	jr	Z,00115$
	ld	hl,#_vblank_last+0
	bit	0, (hl)
	jr	NZ,00115$
;inputtester_app.c:750: basic_input();
	call	_basic_input
;inputtester_app.c:751: modeswitcher();
	call	_modeswitcher
00115$:
;inputtester_app.c:753: }
	inc	sp
	pop	ix
	ret
___str_31:
	.ascii "Hit the button at each prompt"
	.db 0x00
___str_32:
	.ascii "Selected button is: "
	.db 0x00
___str_33:
	.ascii "Press again to start test"
	.db 0x00
;inputtester_app.c:756: void btntest_ready()
;	---------------------------------
; Function btntest_ready
; ---------------------------------
_btntest_ready::
;inputtester_app.c:758: if (HBLANK_RISING)
	ld	hl,#_hblank+0
	bit	0, (hl)
	ret	Z
	ld	hl,#_hblank_last+0
	bit	0, (hl)
	ret	NZ
;inputtester_app.c:760: char button = CHECK_BIT(joystick[0], btntest_buttonindex);
	ld	hl, #_joystick+0
	ld	e, (hl)
	ld	hl,#_btntest_buttonindex + 0
	ld	b, (hl)
	ld	c, #0x01
	inc	b
	jr	00145$
00144$:
	sla	c
00145$:
	djnz	00144$
	ld	a, e
	and	a, c
	ld	c, a
;inputtester_app.c:761: if (btntest_timer > 0)
	ld	iy, #_btntest_timer
	ld	a, 0 (iy)
	or	a, a
	jr	Z,00107$
;inputtester_app.c:763: if (joystick[0] == 0)
	ld	a, (#_joystick + 0)
	or	a, a
	jr	NZ,00108$
;inputtester_app.c:765: btntest_timer--;
	dec	0 (iy)
	jr	00108$
00107$:
;inputtester_app.c:771: if (!button && btntest_buttonlast)
	ld	a, c
	or	a, a
	jr	NZ,00108$
	ld	a,(#_btntest_buttonlast + 0)
	or	a, a
	jr	Z,00108$
;inputtester_app.c:773: btntest_starttest();
	push	bc
	call	_btntest_starttest
	pop	bc
00108$:
;inputtester_app.c:776: btntest_buttonlast = button;
	ld	hl,#_btntest_buttonlast + 0
	ld	(hl), c
;inputtester_app.c:778: }
	ret
;inputtester_app.c:781: void btntest_test()
;	---------------------------------
; Function btntest_test
; ---------------------------------
_btntest_test::
	push	ix
	ld	ix,#0
	add	ix,sp
	dec	sp
;inputtester_app.c:785: bool down = CHECK_BIT(joystick[0], btntest_buttonindex);
	ld	hl, #_joystick+0
	ld	c, (hl)
	ld	hl,#_btntest_buttonindex + 0
	ld	b, (hl)
	ld	hl, #0x0001
	inc	b
	jr	00193$
00192$:
	add	hl, hl
00193$:
	djnz	00192$
	ld	b, #0x00
	ld	a, l
	and	a, c
	ld	c, a
	ld	a, h
	and	a, b
	or	a, c
	add	a, #0xff
	ld	a, #0x00
	rla
	ld	c, a
	ld	-1 (ix), c
;inputtester_app.c:786: if (down && !btntest_buttondownlast)
	bit	0, c
	jr	Z,00102$
	ld	a,(#_btntest_buttondownlast + 0)
	or	a, a
	jr	NZ,00102$
;inputtester_app.c:788: btntest_presses[btntest_pos] = GET_TIMER;
	ld	bc, #_btntest_presses+0
	ld	iy, #_btntest_pos
	ld	l, 0 (iy)
	ld	h, #0x00
	add	hl, hl
	add	hl, bc
	ex	de, hl
	ld	a, (#(_timer + 0x0001) + 0)
	ld	b, a
	ld	c, #0x00
	ld	a, (#_timer + 0)
	ld	l, a
	ld	h, #0x00
	ld	a, c
	or	a, l
	ld	c, a
	ld	a, b
	or	a, h
	ld	b, a
	ld	a, c
	ld	(de), a
	inc	de
	ld	a, b
	ld	(de), a
;inputtester_app.c:789: btntest_pos++;
	inc	0 (iy)
00102$:
;inputtester_app.c:791: btntest_buttondownlast = down;
	ld	a, -1 (ix)
	ld	(#_btntest_buttondownlast + 0),a
;inputtester_app.c:793: if (VBLANK_RISING)
	ld	hl,#_vblank+0
	bit	0, (hl)
	jp	Z, 00125$
	ld	hl,#_vblank_last+0
	bit	0, (hl)
	jp	NZ, 00125$
;inputtester_app.c:796: btntest_timer--;
	ld	hl, #_btntest_timer+0
	dec	(hl)
;inputtester_app.c:798: set_bgcolour(0x0, btntest_highlight, 16);
	ld	a, #0x10
	push	af
	inc	sp
	ld	a, (_btntest_highlight)
	push	af
	inc	sp
	xor	a, a
	push	af
	inc	sp
	call	_set_bgcolour
	pop	af
	inc	sp
;inputtester_app.c:799: if (btntest_timer == 30)
	ld	a,(#_btntest_timer + 0)
	sub	a, #0x1e
	jr	NZ,00105$
;inputtester_app.c:801: btntest_highlight = btntest_highlight_start;
	ld	hl,#_btntest_highlight + 0
	ld	(hl), #0x02
00105$:
;inputtester_app.c:803: if (btntest_highlight > 0)
	ld	a,(#_btntest_highlight + 0)
	or	a, a
	jr	Z,00111$
;inputtester_app.c:805: if ((btntest_timer % 2) == 0)
	ld	hl,#_btntest_timer + 0
	ld	c, (hl)
	ld	b, #0x00
	ld	hl, #0x0002
	push	hl
	push	bc
	call	__modsint
	pop	af
	pop	af
	ld	a, h
	or	a, l
	jr	NZ,00111$
;inputtester_app.c:807: btntest_highlight++;
	ld	iy, #_btntest_highlight
	inc	0 (iy)
;inputtester_app.c:808: if (btntest_highlight > btntest_highlight_end)
	ld	a, #0x23
	sub	a, 0 (iy)
	jr	NC,00111$
;inputtester_app.c:810: btntest_highlight = 0;
	ld	0 (iy), #0x00
00111$:
;inputtester_app.c:814: if (btntest_highlight > 0)
	ld	a,(#_btntest_highlight + 0)
	or	a, a
	jr	Z,00113$
;inputtester_app.c:816: set_bgcolour(0xFF, btntest_highlight, 16);
	ld	a, #0x10
	push	af
	inc	sp
	ld	a, (_btntest_highlight)
	ld	d,a
	ld	e,#0xff
	push	de
	call	_set_bgcolour
	pop	af
	inc	sp
00113$:
;inputtester_app.c:819: if (btntest_aftertimer > 0)
	ld	iy, #_btntest_aftertimer
	ld	a, 0 (iy)
	or	a, a
	jr	Z,00119$
;inputtester_app.c:821: btntest_aftertimer--;
	dec	0 (iy)
;inputtester_app.c:822: if (btntest_aftertimer == 0)
	ld	a, 0 (iy)
	or	a, a
	jr	NZ,00119$
;inputtester_app.c:825: if (btntest_counter == btntest_counter_max)
	ld	a,(#_btntest_counter + 0)
	sub	a, #0x05
	jr	NZ,00119$
;inputtester_app.c:827: btntest_mode = btntest_mode_results;
	ld	hl,#_btntest_mode + 0
	ld	(hl), #0x03
;inputtester_app.c:828: btntest_results_refresh = true;
	ld	hl,#_btntest_results_refresh + 0
	ld	(hl), #0x01
;inputtester_app.c:829: page_btntest(true, true); // reset screen
	ld	de, #0x0101
	push	de
	call	_page_btntest
	pop	af
;inputtester_app.c:830: return;
	jr	00125$
00119$:
;inputtester_app.c:835: if (btntest_timer == 0)
	ld	a,(#_btntest_timer + 0)
	or	a, a
	jr	NZ,00125$
;inputtester_app.c:838: btntest_prompts[btntest_counter] = GET_TIMER;
	ld	bc, #_btntest_prompts+0
	ld	iy, #_btntest_counter
	ld	l, 0 (iy)
	ld	h, #0x00
	add	hl, hl
	add	hl, bc
	ex	de, hl
	ld	a, (#(_timer + 0x0001) + 0)
	ld	b, a
	ld	c, #0x00
	ld	a, (#_timer + 0)
	ld	l, a
	ld	h, #0x00
	ld	a, c
	or	a, l
	ld	c, a
	ld	a, b
	or	a, h
	ld	b, a
	ld	a, c
	ld	(de), a
	inc	de
	ld	a, b
	ld	(de), a
;inputtester_app.c:841: write_stringf("%2d", 0xFF, 18, 6, btntest_counter + 1);
	ld	b, 0 (iy)
	inc	b
	push	bc
	inc	sp
	ld	de, #0x0612
	push	de
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_34
	push	hl
	call	_write_stringf
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
;inputtester_app.c:843: btntest_timer = btntest_timer_interval;
	ld	hl,#_btntest_timer + 0
	ld	(hl), #0x5a
;inputtester_app.c:844: btntest_aftertimer = 33;
	ld	hl,#_btntest_aftertimer + 0
	ld	(hl), #0x21
;inputtester_app.c:845: btntest_counter++;
	ld	hl, #_btntest_counter+0
	inc	(hl)
00125$:
;inputtester_app.c:848: }
	inc	sp
	pop	ix
	ret
___str_34:
	.ascii "%2d"
	.db 0x00
;inputtester_app.c:851: void btntest_results()
;	---------------------------------
; Function btntest_results
; ---------------------------------
_btntest_results::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	hl, #-22
	add	hl, sp
	ld	sp, hl
;inputtester_app.c:854: if (btntest_results_refresh)
	ld	hl,#_btntest_results_refresh+0
	bit	0, (hl)
	jp	Z, 00117$
;inputtester_app.c:856: write_string("Prompts", 0xFF, 2, 6);
	ld	de, #0x0602
	push	de
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_35
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;inputtester_app.c:858: write_string("Presses", 0xFF, 11, 6);
	ld	de, #0x060b
	push	de
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_36
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;inputtester_app.c:861: char y = 7;
	ld	-13 (ix), #0x07
;inputtester_app.c:864: char done = false;
	ld	-16 (ix), #0x00
;inputtester_app.c:866: unsigned short prompt_last = 0;
	ld	-18 (ix), #0x00
	ld	-17 (ix), #0x00
;inputtester_app.c:869: while (!done)
	ld	-15 (ix), #0x00
	ld	-14 (ix), #0x00
00113$:
	ld	a, -16 (ix)
	or	a, a
	jp	NZ, 00115$
;inputtester_app.c:872: unsigned short prompt_time = prompt < btntest_counter_max ? btntest_prompts[prompt] : 65535;
	ld	a, -15 (ix)
	ld	-4 (ix), a
	ld	-3 (ix), #0x00
	ld	a, -4 (ix)
	ld	-6 (ix), a
	ld	a, -3 (ix)
	ld	-5 (ix), a
	sla	-6 (ix)
	rl	-5 (ix)
	ld	a, -15 (ix)
	sub	a, #0x05
	jr	NC,00126$
	ld	a, #<(_btntest_prompts)
	add	a, -6 (ix)
	ld	l, a
	ld	a, #>(_btntest_prompts)
	adc	a, -5 (ix)
	ld	h, a
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	jr	00127$
00126$:
	ld	bc, #0xffff
00127$:
;inputtester_app.c:873: unsigned short press_time = press < btntest_pos ? btntest_presses[press] : 65535;
	ld	l, -14 (ix)
	ld	h, #0x00
	add	hl, hl
	ld	-2 (ix), l
	ld	-1 (ix), h
	ld	hl, #_btntest_pos
	ld	a, -14 (ix)
	sub	a, (hl)
	jr	NC,00128$
	ld	a, #<(_btntest_presses)
	add	a, -2 (ix)
	ld	l, a
	ld	a, #>(_btntest_presses)
	adc	a, -1 (ix)
	ld	h, a
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	ld	-10 (ix), e
	ld	-9 (ix), d
	ld	-8 (ix), #0x00
	ld	-7 (ix), #0x00
	jr	00129$
00128$:
	ld	-10 (ix), #0xff
	ld	-9 (ix), #0xff
	ld	-8 (ix), #0x00
	ld	-7 (ix), #0x00
00129$:
	ld	a, -10 (ix)
	ld	-12 (ix), a
	ld	a, -9 (ix)
	ld	-11 (ix), a
;inputtester_app.c:878: y++;
	ld	a, -13 (ix)
	inc	a
	ld	-10 (ix), a
;inputtester_app.c:875: if (prompt_time < press_time)
	ld	a, c
	sub	a, -12 (ix)
	ld	a, b
	sbc	a, -11 (ix)
	jr	NC,00111$
;inputtester_app.c:877: write_stringf_ushort("%6dms", 0xFF, 2, y, btntest_prompts[prompt]);
	ld	a, -6 (ix)
	add	a, #<(_btntest_prompts)
	ld	l, a
	ld	a, -5 (ix)
	adc	a, #>(_btntest_prompts)
	ld	h, a
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	push	bc
	push	de
	ld	d, -13 (ix)
	ld	e,#0x02
	push	de
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_37
	push	hl
	call	_write_stringf_ushort
	ld	hl, #7
	add	hl, sp
	ld	sp, hl
	pop	bc
;inputtester_app.c:878: y++;
	ld	a, -10 (ix)
	ld	-13 (ix), a
;inputtester_app.c:879: prompt++;
	inc	-15 (ix)
;inputtester_app.c:880: prompt_last = prompt_time;
	ld	-18 (ix), c
	ld	-17 (ix), b
	jp	00113$
00111$:
;inputtester_app.c:882: else if (press_time < prompt_time)
	ld	a, -12 (ix)
	sub	a, c
	ld	a, -11 (ix)
	sbc	a, b
	jp	NC, 00108$
;inputtester_app.c:884: write_stringf_ushort("%6dms", 0xFF, 11, y, btntest_presses[press]);
	ld	a, -2 (ix)
	add	a, #<(_btntest_presses)
	ld	l, a
	ld	a, -1 (ix)
	adc	a, #>(_btntest_presses)
	ld	h, a
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	push	bc
	ld	d, -13 (ix)
	ld	e,#0x0b
	push	de
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_37
	push	hl
	call	_write_stringf_ushort
	ld	hl, #7
	add	hl, sp
	ld	sp, hl
;inputtester_app.c:887: unsigned short prompt_next = prompt + 1 <= btntest_counter_max ? btntest_prompts[prompt] : 65535;
	ld	c, -4 (ix)
	ld	b, -3 (ix)
	inc	bc
	ld	a, #0x05
	cp	a, c
	ld	a, #0x00
	sbc	a, b
	jp	PO, 00205$
	xor	a, #0x80
00205$:
	jp	M, 00130$
	ld	a, -6 (ix)
	add	a, #<(_btntest_prompts)
	ld	l, a
	ld	a, -5 (ix)
	adc	a, #>(_btntest_prompts)
	ld	h, a
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	jr	00131$
00130$:
	ld	bc, #0xffff
00131$:
;inputtester_app.c:889: unsigned short diff_last = abs(press_time - prompt_last);
	ld	a, -12 (ix)
	sub	a, -18 (ix)
	ld	e, a
	ld	a, -11 (ix)
	sbc	a, -17 (ix)
	ld	d, a
	push	de
	call	_abs
	pop	af
	ld	-20 (ix), l
	ld	-19 (ix), h
;inputtester_app.c:890: unsigned short diff_next = abs(prompt_next - press_time);
	ld	a, c
	sub	a, -12 (ix)
	ld	c, a
	ld	a, b
	sbc	a, -11 (ix)
	ld	b, a
	push	bc
	call	_abs
	pop	af
	inc	sp
	inc	sp
	push	hl
;inputtester_app.c:892: if (diff_next < 500)
	ld	a, -22 (ix)
	sub	a, #0xf4
	ld	a, -21 (ix)
	sbc	a, #0x01
	jr	NC,00105$
;inputtester_app.c:894: write_stringf_short("%3dms before", 0b11111000, 20, y, diff_next);
	pop	hl
	push	hl
	push	hl
	ld	d, -13 (ix)
	ld	e,#0x14
	push	de
	ld	a, #0xf8
	push	af
	inc	sp
	ld	hl, #___str_38
	push	hl
	call	_write_stringf_short
	ld	hl, #7
	add	hl, sp
	ld	sp, hl
	jr	00106$
00105$:
;inputtester_app.c:896: else if (diff_last <= 500)
	ld	a, #0xf4
	cp	a, -20 (ix)
	ld	a, #0x01
	sbc	a, -19 (ix)
	jr	C,00102$
;inputtester_app.c:898: write_stringf_short("%3dms after", 0b00111111, 20, y, diff_last);
	pop	bc
	pop	hl
	push	hl
	push	bc
	push	hl
	ld	d, -13 (ix)
	ld	e,#0x14
	push	de
	ld	a, #0x3f
	push	af
	inc	sp
	ld	hl, #___str_39
	push	hl
	call	_write_stringf_short
	ld	hl, #7
	add	hl, sp
	ld	sp, hl
	jr	00106$
00102$:
;inputtester_app.c:902: write_stringf_short("????", 0b00000111, 20, y, diff_next);
	pop	hl
	push	hl
	push	hl
	ld	d, -13 (ix)
	ld	e,#0x14
	push	de
	ld	a, #0x07
	push	af
	inc	sp
	ld	hl, #___str_40
	push	hl
	call	_write_stringf_short
	ld	hl, #7
	add	hl, sp
	ld	sp, hl
00106$:
;inputtester_app.c:904: y++;
	ld	a, -10 (ix)
	ld	-13 (ix), a
;inputtester_app.c:905: press++;
	inc	-14 (ix)
	jp	00113$
00108$:
;inputtester_app.c:909: done = true;
	ld	-16 (ix), #0x01
	jp	00113$
00115$:
;inputtester_app.c:913: btntest_results_refresh = 0;
	ld	hl,#_btntest_results_refresh + 0
	ld	(hl), #0x00
00117$:
;inputtester_app.c:916: if (VBLANK_RISING)
	ld	hl,#_vblank+0
	bit	0, (hl)
	jr	Z,00124$
	ld	hl,#_vblank_last+0
	bit	0, (hl)
	jr	NZ,00124$
;inputtester_app.c:920: basic_input();
	call	_basic_input
;inputtester_app.c:921: modeswitcher();
	call	_modeswitcher
;inputtester_app.c:923: if (input_start && !input_start_last)
	ld	hl,#_input_start+0
	bit	0, (hl)
	jr	Z,00124$
	ld	hl,#_input_start_last+0
	bit	0, (hl)
	jr	NZ,00124$
;inputtester_app.c:925: start_btntest();
	call	_start_btntest
00124$:
;inputtester_app.c:928: }
	ld	sp, ix
	pop	ix
	ret
___str_35:
	.ascii "Prompts"
	.db 0x00
___str_36:
	.ascii "Presses"
	.db 0x00
___str_37:
	.ascii "%6dms"
	.db 0x00
___str_38:
	.ascii "%3dms before"
	.db 0x00
___str_39:
	.ascii "%3dms after"
	.db 0x00
___str_40:
	.ascii "????"
	.db 0x00
;inputtester_app.c:931: void btntest()
;	---------------------------------
; Function btntest
; ---------------------------------
_btntest::
;inputtester_app.c:934: switch (btntest_mode)
	ld	iy, #_btntest_mode
	ld	a, 0 (iy)
	or	a, a
	jp	Z,_btntest_select
	ld	a, 0 (iy)
	dec	a
	jp	Z,_btntest_ready
	ld	a, 0 (iy)
	sub	a, #0x02
	jp	Z,_btntest_test
	ld	a, 0 (iy)
	sub	a, #0x03
	jp	Z,_btntest_results
	ret
;inputtester_app.c:936: case btntest_mode_select:
;inputtester_app.c:937: btntest_select();
;inputtester_app.c:938: break;
	jp  _btntest_select
;inputtester_app.c:939: case btntest_mode_ready:
;inputtester_app.c:940: btntest_ready();
;inputtester_app.c:941: break;
	jp  _btntest_ready
;inputtester_app.c:942: case btntest_mode_test:
;inputtester_app.c:943: btntest_test();
;inputtester_app.c:944: break;
	jp  _btntest_test
;inputtester_app.c:945: case btntest_mode_results:
;inputtester_app.c:946: btntest_results();
;inputtester_app.c:948: }
;inputtester_app.c:949: }
	jp  _btntest_results
	.area _CODE
	.area _INITIALIZER
__xinit__kbd_scan_last:
	.db #0x01	; 1
__xinit__kbd_ascii_last:
	.db #0x01	; 1
__xinit__mse_button1_last:
	.db #0xff	; 255
__xinit__mse_button2_last:
	.db #0xff	; 255
__xinit__mse_x_last:
	.db #0x01	;  1
__xinit__mse_y_last:
	.db #0x01	;  1
__xinit__mse_w_last:
	.db #0x01	;  1
__xinit__modeswitchtimer_select:
	.db #0x00	; 0
__xinit__modeswitchtimer_start:
	.db #0x00	; 0
__xinit__pad_offset_x:
	.db #0x07	; 7
	.db #0x07	; 7
__xinit__pad_offset_y:
	.db #0x05	; 5
	.db #0x10	; 16
__xinit__button_symbol:
	.ascii "R"
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.ascii "L"
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.ascii "D"
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.ascii "U"
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.ascii "A"
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.ascii "B"
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.ascii "X"
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.ascii "Y"
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.ascii "L"
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.ascii "R"
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.ascii "Sel"
	.db 0x00
	.db 0x00
	.db 0x00
	.ascii "Start"
	.db 0x00
__xinit__button_name:
	.ascii "DPAD Right"
	.db 0x00
	.db 0x00
	.ascii "DPAD Left"
	.db 0x00
	.db 0x00
	.db 0x00
	.ascii "DPAD Down"
	.db 0x00
	.db 0x00
	.db 0x00
	.ascii "DPAD Up"
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.ascii "A"
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.ascii "B"
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.ascii "X"
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.ascii "Y"
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.ascii "L"
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.ascii "R"
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.ascii "Select"
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.ascii "Start"
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
	.db 0x00
__xinit__button_x:
	.db #0x06	; 6
	.db #0x02	; 2
	.db #0x04	; 4
	.db #0x04	; 4
	.db #0x18	; 24
	.db #0x16	; 22
	.db #0x16	; 22
	.db #0x14	; 20
	.db #0x03	; 3
	.db #0x17	; 23
	.db #0x09	; 9
	.db #0x0d	; 13
__xinit__button_y:
	.db #0x05	; 5
	.db #0x05	; 5
	.db #0x06	; 6
	.db #0x04	; 4
	.db #0x05	; 5
	.db #0x06	; 6
	.db #0x04	; 4
	.db #0x05	; 5
	.db #0x01	; 1
	.db #0x01	; 1
	.db #0x05	; 5
	.db #0x05	; 5
__xinit__analog_offset_x:
	.db #0x01	; 1
	.db #0x14	; 20
__xinit__analog_offset_y:
	.db #0x05	; 5
	.db #0x05	; 5
__xinit__last_timestamp_clock:
	.db #0x00	;  0
__xinit__analog_pad:
	.db #0x00	; 0
__xinit__btntest_mode:
	.db #0x00	; 0
__xinit__btntest_buttonbank:
	.db #0x00	; 0
__xinit__btntest_buttonindex:
	.db #0x00	; 0
__xinit__btntest_buttonlast:
	.db #0x01	; 1
__xinit__btntest_timer:
	.db #0x00	; 0
__xinit__btntest_counter:
	.db #0x00	; 0
__xinit__btntest_pos:
	.db #0x00	; 0
__xinit__btntest_buttondownlast:
	.db #0x00	; 0
__xinit__btntest_results_refresh:
	.db #0x00	;  0
__xinit__btntest_results_offset:
	.db #0x00	; 0
__xinit__btntest_highlight:
	.db #0x00	; 0
__xinit__btntest_aftertimer:
	.db #0x00	; 0
	.area _CABS (ABS)
