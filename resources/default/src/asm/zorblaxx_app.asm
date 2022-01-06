;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.8.0 #10562 (Linux)
;--------------------------------------------------------
	.module zorblaxx_app
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _update_scroller
	.globl _setup_variables
	.globl _handle_asteroids
	.globl _setup_asteroids
	.globl _handle_pickups
	.globl _setup_pickups
	.globl _spawn_pickup
	.globl _handle_explosions
	.globl _setup_explosions
	.globl _handle_trails
	.globl _add_player_trail
	.globl _setup_trails
	.globl _handle_player
	.globl _setup_player
	.globl _move_player_to_target
	.globl _set_player_target
	.globl _play_sound
	.globl _stop_music
	.globl _play_music
	.globl _write_stringf_ulong
	.globl _write_stringf_short
	.globl _write_stringf_ushort
	.globl _write_stringf
	.globl _write_string
	.globl _clear_bgcolor
	.globl _clear_char_area
	.globl _clear_chars
	.globl _clear_tilemap
	.globl _scroll_tilemap_left
	.globl _update_tilemap_offset
	.globl _clear_sprites
	.globl _enable_sprite
	.globl _update_sprites
	.globl _set_sprite_position
	.globl _strlen
	.globl _sf_speed1
	.globl _scroll_speed_last
	.globl _scroller_entry_pos
	.globl _scroller_pos
	.globl _scroller_text
	.globl _player_score_timer_frequency
	.globl _player_score_timer
	.globl _high_score_passed
	.globl _player_score
	.globl _bonus_score_multiplier
	.globl _high_score
	.globl _pickup_spawn_timer_min
	.globl _pickup_spawn_timer
	.globl _player_lives_default
	.globl _game_state_gameover_timeout
	.globl _game_state_danger_timeout
	.globl _game_state_warp_timeout
	.globl _game_state_warp_timeout_first
	.globl _level_progress_base
	.globl _level_progress_timer
	.globl _level_progress
	.globl _level_playercontrol
	.globl _level_time_timer
	.globl _level_time
	.globl _level_number
	.globl _game_state_timer
	.globl _game_state
	.globl _player_spawn_y
	.globl _player_spawn_x
	.globl _x_max
	.globl _x_min
	.globl _pleaseStop
	.globl _button_a_last
	.globl _button_a
	.globl _pickup_bonuses_collected
	.globl _time_bonuses_collected
	.globl _player_score_last
	.globl _level_progress_max
	.globl _scroll_speed
	.globl _x_h_max
	.globl _x_h_min
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
	.globl _asteroids_difficulty_multiplier
	.globl _asteroids_difficulty_base
	.globl _level_progress_per_level
	.globl _y_divisor
	.globl _x_divisor
	.globl _intro_loop
	.globl _game_loop
	.globl _app_zorblaxx
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
_x_h_min::
	.ds 2
_x_h_max::
	.ds 2
_scroll_speed::
	.ds 1
_level_progress_max::
	.ds 2
_player_score_last::
	.ds 4
_time_bonuses_collected::
	.ds 4
_pickup_bonuses_collected::
	.ds 4
_button_a::
	.ds 1
_button_a_last::
	.ds 1
_pleaseStop::
	.ds 1
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
_x_min::
	.ds 2
_x_max::
	.ds 2
_player_spawn_x::
	.ds 2
_player_spawn_y::
	.ds 2
_game_state::
	.ds 1
_game_state_timer::
	.ds 2
_level_number::
	.ds 1
_level_time::
	.ds 1
_level_time_timer::
	.ds 1
_level_playercontrol::
	.ds 1
_level_progress::
	.ds 2
_level_progress_timer::
	.ds 1
_level_progress_base::
	.ds 2
_game_state_warp_timeout_first::
	.ds 2
_game_state_warp_timeout::
	.ds 2
_game_state_danger_timeout::
	.ds 2
_game_state_gameover_timeout::
	.ds 2
_player_lives_default::
	.ds 1
_pickup_spawn_timer::
	.ds 1
_pickup_spawn_timer_min::
	.ds 1
_high_score::
	.ds 4
_bonus_score_multiplier::
	.ds 1
_player_score::
	.ds 4
_high_score_passed::
	.ds 1
_player_score_timer::
	.ds 1
_player_score_timer_frequency::
	.ds 1
_scroller_text::
	.ds 2
_scroller_pos::
	.ds 1
_scroller_entry_pos::
	.ds 2
_scroll_speed_last::
	.ds 1
_sf_speed1::
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
;zorblaxx_app.c:114: void setup_variables()
;	---------------------------------
; Function setup_variables
; ---------------------------------
_setup_variables::
;zorblaxx_app.c:116: pleaseStop = 0;
	ld	hl,#_pleaseStop + 0
	ld	(hl), #0x00
;zorblaxx_app.c:117: x_h_min = (unsigned short)(x_min * x_divisor);
	ld	hl,#_x_divisor + 0
	ld	c, (hl)
	ld	b, #0x00
	push	bc
	push	bc
	ld	hl, (_x_min)
	push	hl
	call	__mulint
	pop	af
	pop	af
	pop	bc
	ld	(_x_h_min), hl
;zorblaxx_app.c:118: x_h_max = (unsigned short)(x_max * x_divisor);
	push	bc
	ld	hl, (_x_max)
	push	hl
	call	__mulint
	pop	af
	pop	af
	ld	(_x_h_max), hl
;zorblaxx_app.c:120: unsigned char debug = CHECK_BIT(input0, 0);
	ld	hl,#_input0+0
	bit	0, (hl)
	ret	Z
;zorblaxx_app.c:121: if (debug)
;zorblaxx_app.c:123: game_state_warp_timeout_first /= 10;
	ld	hl, #0x000a
	push	hl
	ld	hl, (_game_state_warp_timeout_first)
	push	hl
	call	__divuint
	pop	af
	pop	af
	ld	(_game_state_warp_timeout_first), hl
;zorblaxx_app.c:124: game_state_warp_timeout /= 10;
	ld	hl, #0x000a
	push	hl
	ld	hl, (_game_state_warp_timeout)
	push	hl
	call	__divuint
	pop	af
	pop	af
	ld	(_game_state_warp_timeout), hl
;zorblaxx_app.c:125: game_state_danger_timeout /= 10;
	ld	hl, #0x000a
	push	hl
	ld	hl, (_game_state_danger_timeout)
	push	hl
	call	__divuint
	pop	af
	pop	af
	ld	(_game_state_danger_timeout), hl
;zorblaxx_app.c:126: game_state_gameover_timeout /= 10;
	ld	hl, #0x000a
	push	hl
	ld	hl, (_game_state_gameover_timeout)
	push	hl
	call	__divuint
	pop	af
	pop	af
	ld	(_game_state_gameover_timeout), hl
;zorblaxx_app.c:127: player_lives_default = 1;
	ld	hl,#_player_lives_default + 0
	ld	(hl), #0x01
;zorblaxx_app.c:128: level_progress_base = 2000;
	ld	hl, #0x07d0
	ld	(_level_progress_base), hl
;zorblaxx_app.c:130: }
	ret
_x_divisor:
	.db #0x10	; 16
_y_divisor:
	.db #0x10	; 16
_level_progress_per_level:
	.dw #0x0bb8
_asteroids_difficulty_base:
	.db #0x03	; 3
_asteroids_difficulty_multiplier:
	.db #0x02	; 2
;zorblaxx_app.c:136: void update_scroller()
;	---------------------------------
; Function update_scroller
; ---------------------------------
_update_scroller::
;zorblaxx_app.c:138: tilemap_offset_x += 2;
	ld	iy, #_tilemap_offset_x
	inc	0 (iy)
	inc	0 (iy)
;zorblaxx_app.c:139: if (tilemap_offset_x >= 16)
	ld	a, 0 (iy)
	xor	a, #0x80
	sub	a, #0x90
	ret	C
;zorblaxx_app.c:141: tilemap_offset_x -= 16;
	ld	hl, #_tilemap_offset_x
	ld	a, (hl)
	add	a, #0xf0
	ld	(hl), a
;zorblaxx_app.c:143: scroll_tilemap_left();
	call	_scroll_tilemap_left
;zorblaxx_app.c:145: tilemapram[scroller_entry_pos] = scroller_text[scroller_pos] - 45;
	ld	iy, #_scroller_entry_pos
	ld	a, 0 (iy)
	add	a, #<(_tilemapram)
	ld	c, a
	ld	a, 1 (iy)
	adc	a, #>(_tilemapram)
	ld	b, a
	ld	iy, (_scroller_text)
	ld	de, (_scroller_pos)
	ld	d, #0x00
	add	iy, de
	ld	a, 0 (iy)
	add	a, #0xd3
	ld	(bc), a
;zorblaxx_app.c:146: scroller_pos++;
	ld	hl, #_scroller_pos+0
	inc	(hl)
;zorblaxx_app.c:147: if (scroller_pos == strlen(scroller_text))
	ld	hl, (_scroller_text)
	push	hl
	call	_strlen
	pop	af
	ld	c, l
	ld	b, h
	ld	iy, #_scroller_pos
	ld	e, 0 (iy)
	ld	d, #0x00
	ld	a, c
	sub	a, e
	ret	NZ
	ld	a, b
	sub	a, d
	ret	NZ
;zorblaxx_app.c:149: scroller_pos = 0;
	ld	0 (iy), #0x00
;zorblaxx_app.c:152: }
	ret
;zorblaxx_app.c:154: void intro_loop()
;	---------------------------------
; Function intro_loop
; ---------------------------------
_intro_loop::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	hl, #-13
	add	hl, sp
	ld	sp, hl
;zorblaxx_app.c:157: clear_bgcolor(0);
	xor	a, a
	push	af
	inc	sp
	call	_clear_bgcolor
	inc	sp
;zorblaxx_app.c:160: play_music(0);
	xor	a, a
	push	af
	inc	sp
	call	_play_music
	inc	sp
;zorblaxx_app.c:163: starfield[0] = 8;
	ld	hl, #_starfield
	ld	(hl), #0x08
;zorblaxx_app.c:164: starfield[1] = 1;
	ld	hl, #(_starfield + 0x0001)
	ld	(hl), #0x01
;zorblaxx_app.c:165: starfield[2] = 16;
	ld	hl, #(_starfield + 0x0002)
	ld	(hl), #0x10
;zorblaxx_app.c:166: starfield[3] = 1;
	ld	hl, #(_starfield + 0x0003)
	ld	(hl), #0x01
;zorblaxx_app.c:167: starfield[4] = 32;
	ld	hl, #(_starfield + 0x0004)
	ld	(hl), #0x20
;zorblaxx_app.c:168: starfield[5] = 1;
	ld	hl, #(_starfield + 0x0005)
	ld	(hl), #0x01
;zorblaxx_app.c:171: unsigned char title_sprite = 16;
	ld	e, #0x10
;zorblaxx_app.c:173: signed short title_y = -32 * y_divisor;
	ld	hl,#_y_divisor + 0
	ld	c, (hl)
	ld	b, #0x00
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	ld	-5 (ix), l
	ld	-4 (ix), h
;zorblaxx_app.c:174: signed short title_target_y = 100 * y_divisor;
	ld	b, #0x00
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl, hl
	ld	-2 (ix), l
	ld	-1 (ix), h
;zorblaxx_app.c:175: unsigned char si = 0;
	ld	c, #0x00
;zorblaxx_app.c:176: for (unsigned char y = 0; y < 1; y++)
	ld	-3 (ix), #0x00
00139$:
	ld	a, -3 (ix)
	sub	a, #0x01
	jr	NC,00102$
;zorblaxx_app.c:178: for (unsigned char x = 0; x < 4; x++)
	ld	-11 (ix), c
	ld	-10 (ix), e
	ld	c, #0x00
00136$:
	ld	a, c
	sub	a, #0x04
	jr	NC,00173$
;zorblaxx_app.c:180: enable_sprite(title_sprite, sprite_palette_title, sprite_size_title, 0);
	push	bc
	xor	a, a
	push	af
	inc	sp
	xor	a, a
	ld	d,a
	ld	e,#0x02
	push	de
	ld	a, -10 (ix)
	push	af
	inc	sp
	call	_enable_sprite
	pop	af
	pop	af
	pop	bc
;zorblaxx_app.c:181: spr_index[title_sprite] = sprite_index_title_first + si;
	ld	a, #<(_spr_index)
	add	a, -10 (ix)
	ld	e, a
	ld	a, #>(_spr_index)
	adc	a, #0x00
	ld	d, a
	ld	a, -11 (ix)
	ld	(de), a
;zorblaxx_app.c:182: set_sprite_position(title_sprite, title_x + (x * 32), -32);
	ld	l, c
	ld	h, #0x00
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	ld	de, #0x0080
	add	hl, de
	push	bc
	ld	de, #0xffe0
	push	de
	push	hl
	ld	a, -10 (ix)
	push	af
	inc	sp
	call	_set_sprite_position
	pop	af
	pop	af
	inc	sp
	pop	bc
;zorblaxx_app.c:183: si++;
	inc	-11 (ix)
;zorblaxx_app.c:184: title_sprite++;
	inc	-10 (ix)
;zorblaxx_app.c:178: for (unsigned char x = 0; x < 4; x++)
	inc	c
	jr	00136$
00173$:
	ld	c, -11 (ix)
	ld	e, -10 (ix)
;zorblaxx_app.c:176: for (unsigned char y = 0; y < 1; y++)
	inc	-3 (ix)
	jr	00139$
00102$:
;zorblaxx_app.c:188: unsigned char show_instruction = 0;
	ld	-8 (ix), #0x00
;zorblaxx_app.c:189: unsigned char title_ready = 0;
	ld	-9 (ix), #0x00
;zorblaxx_app.c:191: while (1)
00133$:
;zorblaxx_app.c:193: vblank = CHECK_BIT(input0, INPUT_VBLANK);
	ld	a,(#_input0 + 0)
	and	a, #0x10
	ld	c, a
	xor	a, a
	cp	a, c
	rla
	ld	iy, #_vblank
	ld	0 (iy), a
;zorblaxx_app.c:195: if (VBLANK_RISING)
	bit	0, 0 (iy)
	jr	Z,00109$
	ld	hl,#_vblank_last+0
	bit	0, (hl)
	jr	NZ,00109$
;zorblaxx_app.c:198: button_a_last = button_a;
	ld	a,(#_button_a + 0)
	ld	(#_button_a_last + 0),a
;zorblaxx_app.c:199: button_a = CHECK_BIT(joystick[0], 4);
	ld	a, (#_joystick + 0)
	and	a, #0x10
	ld	iy, #_button_a
	ld	0 (iy), a
;zorblaxx_app.c:201: if (button_a && !button_a_last)
	ld	a, 0 (iy)
	or	a, a
	jr	Z,00104$
	ld	a,(#_button_a_last + 0)
	or	a, a
;zorblaxx_app.c:203: return;
	jp	Z,00147$
00104$:
;zorblaxx_app.c:205: update_scroller();
	call	_update_scroller
;zorblaxx_app.c:206: update_tilemap_offset();
	call	_update_tilemap_offset
;zorblaxx_app.c:207: update_sprites();
	call	_update_sprites
;zorblaxx_app.c:210: if (CHECK_BIT(joystick[1], 2))
	ld	a, (#(_joystick + 0x0001) + 0)
	bit	2, a
	jr	Z,00109$
;zorblaxx_app.c:212: pleaseStop = 1;
	ld	hl,#_pleaseStop + 0
	ld	(hl), #0x01
;zorblaxx_app.c:213: return;
	jp	00147$
00109$:
;zorblaxx_app.c:217: if (VBLANK_FALLING)
	ld	hl,#_vblank+0
	bit	0, (hl)
	jp	NZ, 00130$
	ld	hl,#_vblank_last+0
	bit	0, (hl)
	jp	Z, 00130$
;zorblaxx_app.c:220: if (title_y < title_target_y)
	ld	a, -5 (ix)
	sub	a, -2 (ix)
	ld	a, -4 (ix)
	sbc	a, -1 (ix)
	jp	PO, 00274$
	xor	a, #0x80
00274$:
	jp	P, 00119$
;zorblaxx_app.c:222: signed short diff = (title_target_y - title_y) / 6;
	ld	a, -2 (ix)
	sub	a, -5 (ix)
	ld	c, a
	ld	a, -1 (ix)
	sbc	a, -4 (ix)
	ld	b, a
	ld	hl, #0x0006
	push	hl
	push	bc
	call	__divsint
	pop	af
	pop	af
;zorblaxx_app.c:223: if (diff > 64)
	ld	a, #0x40
	cp	a, l
	ld	a, #0x00
	sbc	a, h
	jp	PO, 00275$
	xor	a, #0x80
00275$:
	jp	P, 00114$
;zorblaxx_app.c:225: diff = 64;
	ld	hl, #0x0040
	jr	00115$
00114$:
;zorblaxx_app.c:227: else if (diff == 0)
	ld	a, h
	or	a, l
	jr	NZ,00115$
;zorblaxx_app.c:229: diff = 2;
	ld	hl, #0x0002
00115$:
;zorblaxx_app.c:231: title_y += diff;
	ld	a, -5 (ix)
	add	a, l
	ld	-5 (ix), a
	ld	a, -4 (ix)
	adc	a, h
	ld	-4 (ix), a
;zorblaxx_app.c:232: title_sprite = 16;
	ld	c, #0x10
;zorblaxx_app.c:233: for (unsigned char y = 0; y < 2; y++)
	ld	e, #0x00
00145$:
	ld	a, e
	sub	a, #0x02
	jr	NC,00120$
;zorblaxx_app.c:235: unsigned short sy = (title_y / y_divisor) + (y * 16);
	ld	iy, #_y_divisor
	ld	l, 0 (iy)
	ld	h, #0x00
	push	bc
	push	de
	push	hl
	ld	l, -5 (ix)
	ld	h, -4 (ix)
	push	hl
	call	__divsint
	pop	af
	pop	af
	ld	b, l
	ld	a, h
	pop	de
	ld	d, a
	ld	a, b
	pop	bc
	ld	b, a
	ld	l, e
	ld	h, #0x00
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	ld	a, b
	add	a, l
	ld	b, a
	ld	a, d
	adc	a, h
	ld	d, a
	ld	-7 (ix), b
;zorblaxx_app.c:236: for (unsigned char x = 0; x < 8; x++)
	ld	-6 (ix), d
	ld	-13 (ix), d
	ld	-12 (ix), #0x00
	ld	d, #0x00
00142$:
	ld	a, d
	sub	a, #0x08
	jr	NC,00174$
;zorblaxx_app.c:238: spr_y_h[title_sprite] = sy >> 8;
	ld	hl, #_spr_y_h
	ld	b, #0x00
	add	hl, bc
	ld	a, -13 (ix)
	ld	(hl), a
;zorblaxx_app.c:239: spr_y_l[title_sprite] = (unsigned char)sy;
	ld	hl, #_spr_y_l
	ld	b, #0x00
	add	hl, bc
	ld	a, -7 (ix)
	ld	(hl), a
;zorblaxx_app.c:240: title_sprite++;
	inc	c
;zorblaxx_app.c:236: for (unsigned char x = 0; x < 8; x++)
	inc	d
	jr	00142$
00174$:
;zorblaxx_app.c:233: for (unsigned char y = 0; y < 2; y++)
	inc	e
	jr	00145$
00119$:
;zorblaxx_app.c:246: title_ready = 1;
	ld	-9 (ix), #0x01
00120$:
;zorblaxx_app.c:250: move_player_to_target();
	call	_move_player_to_target
;zorblaxx_app.c:252: if (show_instruction == 0 && player_ready == 1 && title_ready == 1)
	ld	a, -8 (ix)
	or	a, a
	jr	NZ,00122$
	ld	a,(#_player_ready + 0)
	dec	a
	jr	NZ,00122$
	ld	a, -9 (ix)
	dec	a
	jr	NZ,00122$
;zorblaxx_app.c:254: write_string("Press A to start", 0xFF, 12, 17);
	ld	de, #0x110c
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
;zorblaxx_app.c:255: show_instruction = 1;
	ld	-8 (ix), #0x01
00122$:
;zorblaxx_app.c:259: player_trail_timer--;
	ld	iy, #_player_trail_timer
	dec	0 (iy)
;zorblaxx_app.c:260: if (player_trail_timer <= 0)
	xor	a, a
	sub	a, 0 (iy)
	jp	PO, 00280$
	xor	a, #0x80
00280$:
	jp	M, 00128$
;zorblaxx_app.c:262: player_trail_timer = player_trail_frequency - ((player_speed * 10) / 50);
	ld	hl,#_player_speed + 0
	ld	c, (hl)
	ld	b, #0x00
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, hl
	add	hl, bc
	add	hl, hl
	ld	bc, #0x0032
	push	bc
	push	hl
	call	__divsint
	pop	af
	pop	af
	ld	c, l
	ld	a,(#_player_trail_frequency + 0)
	ld	hl, #_player_trail_timer
	sub	a, c
	ld	(hl), a
;zorblaxx_app.c:263: if (player_trail_timer <= 0)
	xor	a, a
	ld	iy, #_player_trail_timer
	sub	a, 0 (iy)
	jp	PO, 00281$
	xor	a, #0x80
00281$:
	jp	M, 00126$
;zorblaxx_app.c:265: player_trail_timer = 1;
	ld	hl,#_player_trail_timer + 0
	ld	(hl), #0x01
00126$:
;zorblaxx_app.c:267: add_player_trail();
	call	_add_player_trail
00128$:
;zorblaxx_app.c:269: handle_trails();
	call	_handle_trails
00130$:
;zorblaxx_app.c:271: vblank_last = vblank;
	ld	a,(#_vblank + 0)
	ld	(#_vblank_last + 0),a
	jp	00133$
00147$:
;zorblaxx_app.c:273: }
	ld	sp, ix
	pop	ix
	ret
___str_0:
	.ascii "Press A to start"
	.db 0x00
;zorblaxx_app.c:279: void game_loop()
;	---------------------------------
; Function game_loop
; ---------------------------------
_game_loop::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	hl, #-7
	add	hl, sp
	ld	sp, hl
;zorblaxx_app.c:282: game_state = game_start;
	ld	hl,#_game_state + 0
	ld	(hl), #0x00
;zorblaxx_app.c:284: while (1)
00186$:
;zorblaxx_app.c:286: vblank = CHECK_BIT(input0, INPUT_VBLANK);
	ld	a,(#_input0 + 0)
	and	a, #0x10
	ld	c, a
	xor	a, a
	cp	a, c
	rla
	ld	iy, #_vblank
	ld	0 (iy), a
;zorblaxx_app.c:288: if (VBLANK_RISING)
	bit	0, 0 (iy)
	jp	Z, 00117$
	ld	hl,#_vblank_last+0
	bit	0, (hl)
	jp	NZ, 00117$
;zorblaxx_app.c:292: if (spritecollisionram[player_sprite])
	ld	a, (#(_spritecollisionram + 0x000b) + 0)
	or	a, a
	jp	Z, 00211$
;zorblaxx_app.c:294: if (spritecollisionram[pickup_sprite_first])
	ld	a, (#(_spritecollisionram + 0x000a) + 0)
	or	a, a
	jr	Z,00209$
;zorblaxx_app.c:297: if (pickup_state[0] == 1)
	ld	a, (#_pickup_state + 0)
	dec	a
	jp	NZ,00211$
;zorblaxx_app.c:299: enable_sprite(pickup_sprite_first, sprite_palette_pickups, sprite_size_pickups, 0);
	xor	a, a
	ld	d,a
	ld	e,#0x01
	push	de
	ld	de, #0x010a
	push	de
	call	_enable_sprite
	pop	af
	pop	af
;zorblaxx_app.c:300: player_score += pickup_value[0];
	ld	a, (#_pickup_value + 0)
	ld	c, a
	ld	b, #0x00
	ld	de, #0x0000
	ld	hl, #_player_score
	ld	a, (hl)
	add	a, c
	ld	(hl), a
	inc	hl
	ld	a, (hl)
	adc	a, b
	ld	(hl), a
	inc	hl
	ld	a, (hl)
	adc	a, e
	ld	(hl), a
	inc	hl
	ld	a, (hl)
	adc	a, d
	ld	(hl), a
;zorblaxx_app.c:301: pickup_bonuses_collected += pickup_value[0];
	ld	a, (#_pickup_value + 0)
	ld	c, a
	ld	b, #0x00
	ld	de, #0x0000
	ld	hl, #_pickup_bonuses_collected
	ld	a, (hl)
	add	a, c
	ld	(hl), a
	inc	hl
	ld	a, (hl)
	adc	a, b
	ld	(hl), a
	inc	hl
	ld	a, (hl)
	adc	a, e
	ld	(hl), a
	inc	hl
	ld	a, (hl)
	adc	a, d
	ld	(hl), a
;zorblaxx_app.c:302: pickup_state[0] = 2;
	ld	hl, #_pickup_state
	ld	(hl), #0x02
;zorblaxx_app.c:303: pickup_timer[0] = 40;
	ld	hl, #_pickup_timer
	ld	(hl), #0x28
;zorblaxx_app.c:304: spr_index[pickup_sprite_first] += pickup_type_count;
	ld	bc, #_spr_index+10
	ld	a, (bc)
	ld	hl, #_pickup_type_count
	add	a, (hl)
	ld	(bc), a
;zorblaxx_app.c:305: play_sound(const_sound_pickup_collect);
	ld	a, #0x01
	push	af
	inc	sp
	call	_play_sound
	inc	sp
	jr	00211$
;zorblaxx_app.c:310: for (unsigned char a = 0; a < asteroids_max; a++)
00209$:
	ld	c, #0x00
00189$:
	ld	hl, #_asteroids_max
	ld	a, c
	sub	a, (hl)
	jr	NC,00211$
;zorblaxx_app.c:312: if (spritecollisionram[asteroids_sprite_first + a])
	ld	de, #_spritecollisionram+0
	ld	a, c
	add	a, #0x0c
	ld	l, a
	rla
	sbc	a, a
	ld	h, a
	add	hl, de
	ld	a, (hl)
	or	a, a
	jr	Z,00190$
;zorblaxx_app.c:314: player_hit = true;
	ld	hl,#_player_hit + 0
	ld	(hl), #0x01
;zorblaxx_app.c:315: break;
	jr	00211$
00190$:
;zorblaxx_app.c:310: for (unsigned char a = 0; a < asteroids_max; a++)
	inc	c
	jr	00189$
;zorblaxx_app.c:320: for (unsigned char sprite = 0; sprite < sprite_max; sprite++)
00211$:
	ld	-1 (ix), #0x00
00192$:
	ld	hl, #_sprite_max
	ld	a, -1 (ix)
	sub	a, (hl)
	jr	NC,00111$
;zorblaxx_app.c:322: spritecollisionram[sprite] = 0;
	ld	a, #<(_spritecollisionram)
	add	a, -1 (ix)
	ld	-7 (ix), a
	ld	a, #>(_spritecollisionram)
	adc	a, #0x00
	ld	-6 (ix), a
	pop	hl
	push	hl
	ld	(hl), #0x00
;zorblaxx_app.c:320: for (unsigned char sprite = 0; sprite < sprite_max; sprite++)
	inc	-1 (ix)
	jr	00192$
00111$:
;zorblaxx_app.c:326: update_sprites();
	call	_update_sprites
;zorblaxx_app.c:329: scroll_speed = player_speed;
	ld	a,(#_player_speed + 0)
	ld	iy, #_scroll_speed
	ld	0 (iy), a
;zorblaxx_app.c:330: if (scroll_speed != scroll_speed_last)
	ld	a, 0 (iy)
	ld	iy, #_scroll_speed_last
	sub	a, 0 (iy)
	jr	Z,00113$
;zorblaxx_app.c:332: scroll_speed_last = scroll_speed;
	ld	a,(#_scroll_speed + 0)
	ld	(#_scroll_speed_last + 0),a
;zorblaxx_app.c:333: unsigned char s = scroll_speed >> 2;
	ld	hl,#_scroll_speed + 0
	ld	c, (hl)
	srl	c
	srl	c
;zorblaxx_app.c:334: starfield[0] = s;
	ld	hl, #_starfield
	ld	(hl), c
;zorblaxx_app.c:335: starfield[2] = s >> 1;
	ld	hl, #_starfield+2
	srl	c
	ld	(hl), c
;zorblaxx_app.c:336: starfield[4] = s >> 1;
	ld	hl, #(_starfield + 0x0004)
	ld	(hl), c
00113$:
;zorblaxx_app.c:340: button_a_last = button_a;
	ld	a,(#_button_a + 0)
	ld	(#_button_a_last + 0),a
;zorblaxx_app.c:341: button_a = CHECK_BIT(joystick[0], 4);
	ld	a, (#_joystick + 0)
	and	a, #0x10
	ld	(#_button_a + 0),a
;zorblaxx_app.c:344: if (CHECK_BIT(joystick[1], 2))
	ld	a, (#(_joystick + 0x0001) + 0)
	bit	2, a
	jr	Z,00117$
;zorblaxx_app.c:346: pleaseStop = 1;
	ld	hl,#_pleaseStop + 0
	ld	(hl), #0x01
;zorblaxx_app.c:347: return;
	jp	00194$
00117$:
;zorblaxx_app.c:351: if (VBLANK_FALLING)
	ld	hl,#_vblank+0
	bit	0, (hl)
	jp	NZ, 00183$
	ld	hl,#_vblank_last+0
	bit	0, (hl)
	jp	Z, 00183$
;zorblaxx_app.c:353: if (player_lives > 0)
	ld	a,(#_player_lives + 0)
	or	a, a
	jr	Z,00120$
;zorblaxx_app.c:355: handle_player(level_playercontrol);
	xor	a, a
	ld	iy, #_level_playercontrol
	cp	a, 0 (iy)
	rla
	push	af
	inc	sp
	call	_handle_player
	inc	sp
00120$:
;zorblaxx_app.c:357: handle_trails();
	call	_handle_trails
;zorblaxx_app.c:358: handle_explosions();
	call	_handle_explosions
;zorblaxx_app.c:359: handle_asteroids(game_state == in_field);
	ld	a,(#_game_state + 0)
	sub	a, #0x02
	jr	NZ, 00432$
	ld	a, #0x01
	.db	#0x20
00432$:
	xor	a, a
00433$:
	push	af
	inc	sp
	call	_handle_asteroids
	inc	sp
;zorblaxx_app.c:360: handle_pickups();
	call	_handle_pickups
;zorblaxx_app.c:362: if (game_state == in_field || game_state == field_ending)
	ld	iy, #_game_state
	ld	a, 0 (iy)
	sub	a, #0x02
	jr	Z,00127$
	ld	a, 0 (iy)
	sub	a, #0x03
	jr	NZ,00128$
00127$:
;zorblaxx_app.c:364: level_time_timer++;
	ld	iy, #_level_time_timer
	inc	0 (iy)
;zorblaxx_app.c:365: if (level_time_timer >= 60)
	ld	a, 0 (iy)
	sub	a, #0x3c
	jr	C,00122$
;zorblaxx_app.c:367: level_time++;
	ld	hl, #_level_time+0
	inc	(hl)
;zorblaxx_app.c:368: level_time_timer = 0;
	ld	hl,#_level_time_timer + 0
	ld	(hl), #0x00
00122$:
;zorblaxx_app.c:370: if (player_lives_changed)
	ld	a,(#_player_lives_changed + 0)
	or	a, a
	jr	Z,00128$
;zorblaxx_app.c:372: write_stringf("%2d", 0xFF, 38, 1, player_lives);
	ld	a, (_player_lives)
	ld	d,a
	ld	e,#0x01
	push	de
	ld	de, #0x26ff
	push	de
	ld	hl, #___str_1
	push	hl
	call	_write_stringf
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
;zorblaxx_app.c:373: player_lives_changed = false;
	ld	hl,#_player_lives_changed + 0
	ld	(hl), #0x00
;zorblaxx_app.c:374: if (player_lives == 0)
	ld	a,(#_player_lives + 0)
	or	a, a
	jr	NZ,00128$
;zorblaxx_app.c:376: game_state = game_over;
	ld	hl,#_game_state + 0
	ld	(hl), #0x07
00128$:
;zorblaxx_app.c:382: switch (game_state)
	ld	a, #0x0a
	ld	iy, #_game_state
	sub	a, 0 (iy)
	jp	C, 00177$
	ld	c, 0 (iy)
	ld	b, #0x00
	ld	hl, #00437$
	add	hl, bc
	add	hl, bc
	add	hl, bc
	jp	(hl)
00437$:
	jp	00130$
	jp	00131$
	jp	00134$
	jp	00143$
	jp	00155$
	jp	00159$
	jp	00162$
	jp	00169$
	jp	00170$
	jp	00177$
	jp	00173$
;zorblaxx_app.c:384: case game_start:
00130$:
;zorblaxx_app.c:387: level_number = 0;
	ld	hl,#_level_number + 0
	ld	(hl), #0x00
;zorblaxx_app.c:388: level_progress = 0;
	ld	hl, #0x0000
	ld	(_level_progress), hl
;zorblaxx_app.c:389: level_playercontrol = 0;
	ld	hl,#_level_playercontrol + 0
	ld	(hl), #0x00
;zorblaxx_app.c:392: setup_player(player_spawn_x, 260, player_lives_default);
	ld	a, (_player_lives_default)
	push	af
	inc	sp
	ld	hl, #0x0104
	push	hl
	ld	hl, (_player_spawn_x)
	push	hl
	call	_setup_player
	pop	af
	pop	af
	inc	sp
;zorblaxx_app.c:393: player_speed = player_speed_warp; // Preset player to warp speed!
	ld	a,(#_player_speed_warp + 0)
	ld	(#_player_speed + 0),a
;zorblaxx_app.c:396: player_score = 0;
	xor	a, a
	ld	iy, #_player_score
	ld	0 (iy), a
	ld	1 (iy), a
	ld	2 (iy), a
	ld	3 (iy), a
;zorblaxx_app.c:397: player_score_last = 999;
	ld	iy, #_player_score_last
	ld	0 (iy), #0xe7
	ld	1 (iy), #0x03
	ld	2 (iy), #0x00
	ld	3 (iy), #0x00
;zorblaxx_app.c:398: player_score_timer = 0;
	ld	hl,#_player_score_timer + 0
	ld	(hl), #0x00
;zorblaxx_app.c:399: high_score_passed = 0;
	ld	hl,#_high_score_passed + 0
	ld	(hl), #0x00
;zorblaxx_app.c:400: asteroids_evaded = 0;
	ld	hl, #0x0000
	ld	(_asteroids_evaded), hl
;zorblaxx_app.c:403: setup_asteroids();
	call	_setup_asteroids
;zorblaxx_app.c:406: setup_explosions();
	call	_setup_explosions
;zorblaxx_app.c:409: setup_pickups();
	call	_setup_pickups
;zorblaxx_app.c:410: pickup_spawn_timer = pickup_spawn_timer_min;
	ld	a,(#_pickup_spawn_timer_min + 0)
	ld	(#_pickup_spawn_timer + 0),a
;zorblaxx_app.c:413: write_string("1UP", 0b00111111, 2, 0);
	xor	a, a
	ld	d,a
	ld	e,#0x02
	push	de
	ld	a, #0x3f
	push	af
	inc	sp
	ld	hl, #___str_2
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;zorblaxx_app.c:414: write_string("HIGH SCORE", 0b00111111, 15, 0);
	xor	a, a
	ld	d,a
	ld	e,#0x0f
	push	de
	ld	a, #0x3f
	push	af
	inc	sp
	ld	hl, #___str_3
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;zorblaxx_app.c:415: write_string("SHIPS", 0b00111111, 35, 0);
	xor	a, a
	ld	d,a
	ld	e,#0x23
	push	de
	ld	a, #0x3f
	push	af
	inc	sp
	ld	hl, #___str_4
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;zorblaxx_app.c:416: write_stringf("%2d", 0xFF, 38, 1, player_lives);
	ld	a, (_player_lives)
	ld	d,a
	ld	e,#0x01
	push	de
	ld	de, #0x26ff
	push	de
	ld	hl, #___str_1
	push	hl
	call	_write_stringf
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
;zorblaxx_app.c:419: write_string("Avoid the asteroids!", 0b00111111, 10, 11);
	ld	de, #0x0b0a
	push	de
	ld	a, #0x3f
	push	af
	inc	sp
	ld	hl, #___str_5
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;zorblaxx_app.c:420: write_string("Use A to boost for time bonus", 0b00111000, 5, 14);
	ld	de, #0x0e05
	push	de
	ld	a, #0x38
	push	af
	inc	sp
	ld	hl, #___str_6
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;zorblaxx_app.c:421: write_string("Collect gems for extra points", 0b00011111, 5, 17);
	ld	de, #0x1105
	push	de
	ld	a, #0x1f
	push	af
	inc	sp
	ld	hl, #___str_7
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;zorblaxx_app.c:423: game_state = in_warp;
	ld	hl,#_game_state + 0
	ld	(hl), #0x05
;zorblaxx_app.c:424: game_state_timer = game_state_warp_timeout_first;
	ld	hl, (_game_state_warp_timeout_first)
	ld	(_game_state_timer), hl
;zorblaxx_app.c:426: break;
	jp	00177$
;zorblaxx_app.c:427: case enter_field: // Player is entering a new field
00131$:
;zorblaxx_app.c:428: game_state = in_field;
	ld	hl,#_game_state + 0
	ld	(hl), #0x02
;zorblaxx_app.c:429: level_progress = 0;
	ld	hl, #0x0000
	ld	(_level_progress), hl
;zorblaxx_app.c:430: level_progress_timer = 0;
	ld	hl,#_level_progress_timer + 0
	ld	(hl), #0x00
;zorblaxx_app.c:431: level_number++;
	ld	hl, #_level_number+0
	inc	(hl)
;zorblaxx_app.c:432: level_time = 0;
	ld	hl,#_level_time + 0
	ld	(hl), #0x00
;zorblaxx_app.c:433: level_time_timer = 0;
	ld	hl,#_level_time_timer + 0
	ld	(hl), #0x00
;zorblaxx_app.c:434: level_playercontrol = 1;
	ld	hl,#_level_playercontrol + 0
	ld	(hl), #0x01
;zorblaxx_app.c:435: unsigned short per_level = level_number < 13 ? (level_number * level_progress_per_level) : 13 * level_progress_per_level;
	ld	iy, #_level_number
	ld	a, 0 (iy)
	sub	a, #0x0d
	jr	NC,00196$
	ld	de, (_level_progress_per_level)
	ld	c, 0 (iy)
	ld	b, #0x00
	push	de
	push	bc
	call	__mulint
	pop	af
	pop	af
	jr	00197$
00196$:
	ld	hl, (_level_progress_per_level)
	ld	c, l
	ld	b, h
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl, hl
	add	hl, bc
00197$:
	ld	c, l
	ld	b, h
;zorblaxx_app.c:436: level_progress_max = level_progress_base + per_level;
	ld	hl, #_level_progress_max
	ld	iy, #_level_progress_base
	ld	a, 0 (iy)
	add	a, c
	ld	(hl), a
	ld	a, 1 (iy)
	adc	a, b
	inc	hl
	ld	(hl), a
;zorblaxx_app.c:442: asteroids_difficulty = asteroids_difficulty_base + (level_number * asteroids_difficulty_multiplier);
	ld	hl,#_asteroids_difficulty_multiplier + 0
	ld	e, (hl)
	ld	hl,#_level_number + 0
	ld	h, (hl)
	ld	l, #0x00
	ld	d, l
	ld	b, #0x08
00438$:
	add	hl, hl
	jr	NC,00439$
	add	hl, de
00439$:
	djnz	00438$
	ld	c, l
	ld	a,(#_asteroids_difficulty_base + 0)
	add	a, c
	ld	iy, #_asteroids_difficulty
	ld	0 (iy), a
;zorblaxx_app.c:443: asteroids_difficulty_speedspread = 2 + (asteroids_difficulty / 4);
	ld	c, 0 (iy)
	ld	b, #0x00
	ld	e, c
	ld	l, b
	bit	7, b
	jr	Z,00198$
	inc	bc
	inc	bc
	inc	bc
	ld	e, c
	ld	l, b
00198$:
	sra	l
	rr	e
	sra	l
	rr	e
	ld	a, e
	add	a, #0x02
	ld	(#_asteroids_difficulty_speedspread + 0),a
;zorblaxx_app.c:445: asteroids_active_max = 5 + asteroids_difficulty;
	ld	a,(#_asteroids_difficulty + 0)
	add	a, #0x05
	ld	iy, #_asteroids_active_max
	ld	0 (iy), a
;zorblaxx_app.c:446: if (asteroids_active_max > asteroids_max)
	ld	a, (#_asteroids_max)
	sub	a, 0 (iy)
	jr	NC,00133$
;zorblaxx_app.c:448: asteroids_active_max = asteroids_max;
	ld	a,(#_asteroids_max + 0)
	ld	(#_asteroids_active_max + 0),a
00133$:
;zorblaxx_app.c:452: write_stringf("%3d%%", 0xFF, 18, 29, 0);
	xor	a, a
	ld	d,a
	ld	e,#0x1d
	push	de
	ld	de, #0x12ff
	push	de
	ld	hl, #___str_8
	push	hl
	call	_write_stringf
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
;zorblaxx_app.c:454: break;
	jp	00177$
;zorblaxx_app.c:455: case in_field:
00134$:
;zorblaxx_app.c:457: level_progress += player_speed;
	ld	hl,#_player_speed + 0
	ld	c, (hl)
	ld	b, #0x00
	ld	hl, #_level_progress
	ld	a, (hl)
	add	a, c
	ld	(hl), a
	inc	hl
	ld	a, (hl)
	adc	a, b
	ld	(hl), a
;zorblaxx_app.c:458: level_progress_timer++;
	ld	iy, #_level_progress_timer
	inc	0 (iy)
;zorblaxx_app.c:459: if (level_progress_timer > 10)
	ld	a, #0x0a
	sub	a, 0 (iy)
	jr	NC,00136$
;zorblaxx_app.c:461: unsigned char progress = level_progress / (level_progress_max / 100);
	ld	hl, #0x0064
	push	hl
	ld	hl, (_level_progress_max)
	push	hl
	call	__divuint
	pop	af
	ex	(sp),hl
	ld	hl, (_level_progress)
	push	hl
	call	__divuint
	pop	af
	pop	af
	ld	b, l
;zorblaxx_app.c:462: write_stringf("%3d%%", 0xFF, 18, 29, progress);
	push	bc
	inc	sp
	ld	de, #0x1d12
	push	de
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_8
	push	hl
	call	_write_stringf
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
;zorblaxx_app.c:463: level_progress_timer = 0;
	ld	hl,#_level_progress_timer + 0
	ld	(hl), #0x00
00136$:
;zorblaxx_app.c:465: if (level_progress >= level_progress_max)
	ld	hl, #_level_progress_max
	ld	iy, #_level_progress
	ld	a, 0 (iy)
	sub	a, (hl)
	ld	a, 1 (iy)
	inc	hl
	sbc	a, (hl)
	jr	C,00138$
;zorblaxx_app.c:467: write_string("100%", 0xFF, 18, 29);
	ld	de, #0x1d12
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
;zorblaxx_app.c:468: game_state = field_ending;
	ld	hl,#_game_state + 0
	ld	(hl), #0x03
00138$:
;zorblaxx_app.c:472: pickup_spawn_timer--;
	ld	iy, #_pickup_spawn_timer
	dec	0 (iy)
;zorblaxx_app.c:473: if (pickup_spawn_timer == 0)
	ld	a, 0 (iy)
	or	a, a
	jr	NZ,00140$
;zorblaxx_app.c:475: pickup_spawn_timer = pickup_spawn_timer_min;
	ld	a,(#_pickup_spawn_timer_min + 0)
	ld	(#_pickup_spawn_timer + 0),a
;zorblaxx_app.c:476: spawn_pickup();
	call	_spawn_pickup
00140$:
;zorblaxx_app.c:480: player_score_timer += player_speed;
	ld	hl, #_player_score_timer
	ld	a, (hl)
	ld	iy, #_player_speed
	add	a, 0 (iy)
	ld	(hl), a
;zorblaxx_app.c:481: if (player_score_timer >= player_score_timer_frequency)
	ld	hl, #_player_score_timer_frequency
	ld	iy, #_player_score_timer
	ld	a, 0 (iy)
	sub	a, (hl)
	jp	C, 00177$
;zorblaxx_app.c:483: player_score_timer -= player_score_timer_frequency;
	ld	hl, #_player_score_timer_frequency
	push	de
	push	iy
	pop	de
	ld	a, (de)
	sub	a, (hl)
	ld	(de), a
	pop	de
;zorblaxx_app.c:484: player_score++;
	ld	iy, #_player_score
	inc	0 (iy)
	jp	NZ,00177$
	inc	1 (iy)
	jp	NZ,00177$
	inc	2 (iy)
	jp	NZ,00177$
	inc	3 (iy)
;zorblaxx_app.c:486: break;
	jp	00177$
;zorblaxx_app.c:487: case field_ending:
00143$:
;zorblaxx_app.c:491: player_score_timer += player_speed;
	ld	hl, #_player_score_timer
	ld	a, (hl)
	ld	iy, #_player_speed
	add	a, 0 (iy)
	ld	(hl), a
;zorblaxx_app.c:492: if (player_score_timer >= player_score_timer_frequency)
	ld	hl, #_player_score_timer_frequency
	ld	iy, #_player_score_timer
	ld	a, 0 (iy)
	sub	a, (hl)
	jr	C,00145$
;zorblaxx_app.c:494: player_score_timer -= player_score_timer_frequency;
	ld	hl, #_player_score_timer_frequency
	push	de
	push	iy
	pop	de
	ld	a, (de)
	sub	a, (hl)
	ld	(de), a
	pop	de
;zorblaxx_app.c:495: player_score++;
	ld	iy, #_player_score
	inc	0 (iy)
	jr	NZ,00441$
	inc	1 (iy)
	jr	NZ,00441$
	inc	2 (iy)
	jr	NZ,00441$
	inc	3 (iy)
00441$:
00145$:
;zorblaxx_app.c:497: if (asteroids_active == 0)
	ld	a,(#_asteroids_active + 0)
	or	a, a
	jp	NZ, 00177$
;zorblaxx_app.c:499: game_state = field_complete;
	ld	hl,#_game_state + 0
	ld	(hl), #0x04
;zorblaxx_app.c:501: game_state_timer = game_state_warp_timeout;
	ld	hl, (_game_state_warp_timeout)
	ld	(_game_state_timer), hl
;zorblaxx_app.c:506: level_playercontrol = 0;
	ld	hl,#_level_playercontrol + 0
	ld	(hl), #0x00
;zorblaxx_app.c:507: set_player_target(player_spawn_x * x_divisor, player_spawn_y * y_divisor, 6, 24);
	ld	hl,#_y_divisor + 0
	ld	c, (hl)
	ld	b, #0x00
	push	bc
	ld	hl, (_player_spawn_y)
	push	hl
	call	__mulint
	pop	af
	pop	af
	ld	c, l
	ld	b, h
	ld	hl,#_x_divisor + 0
	ld	e, (hl)
	ld	d, #0x00
	push	bc
	push	de
	ld	hl, (_player_spawn_x)
	push	hl
	call	__mulint
	pop	af
	pop	af
	pop	bc
	ld	de, #0x1806
	push	de
	push	bc
	push	hl
	call	_set_player_target
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
;zorblaxx_app.c:509: write_stringf_ushort("-- FIELD %d COMPLETED --", 0xFF, 9, 11, level_number);
	ld	hl,#_level_number + 0
	ld	c, (hl)
	ld	b, #0x00
	push	bc
	ld	de, #0x0b09
	push	de
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_10
	push	hl
	call	_write_stringf_ushort
	ld	hl, #7
	add	hl, sp
	ld	sp, hl
;zorblaxx_app.c:511: unsigned char par_speed = ((player_speed_max - player_speed_min) / 2);
	ld	iy, #_player_speed_max
	ld	l, 0 (iy)
	ld	h, #0x00
	ld	iy, #_player_speed_min
	ld	c, 0 (iy)
	ld	b, #0x00
	cp	a, a
	sbc	hl, bc
	ld	e, l
	ld	d, h
	bit	7, h
	jr	Z,00199$
	ex	de,hl
	inc	de
00199$:
	sra	d
	rr	e
;zorblaxx_app.c:512: unsigned short par_time = level_progress_max / 60 / par_speed;
	push	de
	ld	hl, #0x003c
	push	hl
	ld	hl, (_level_progress_max)
	push	hl
	call	__divuint
	pop	af
	pop	af
	pop	de
	ld	d, #0x00
	push	de
	push	hl
	call	__divuint
	pop	af
	pop	af
	ld	-3 (ix), l
	ld	-2 (ix), h
;zorblaxx_app.c:513: signed short bonus = (par_time - level_time) * bonus_score_multiplier;
	ld	hl,#_level_time + 0
	ld	c, (hl)
	ld	b, #0x00
	ld	a, -3 (ix)
	sub	a, c
	ld	c, a
	ld	a, -2 (ix)
	sbc	a, b
	ld	b, a
	ld	hl,#_bonus_score_multiplier + 0
	ld	e, (hl)
	ld	d, #0x00
	push	de
	push	bc
	call	__mulint
	pop	af
	pop	af
;zorblaxx_app.c:514: time_bonuses_collected += bonus;
	ld	-5 (ix), l
	ld	-4 (ix), h
	ld	c, l
	ld	a, h
	ld	b, a
	rla
	sbc	a, a
	ld	e, a
	ld	d, a
	ld	hl, #_time_bonuses_collected
	ld	a, (hl)
	add	a, c
	ld	(hl), a
	inc	hl
	ld	a, (hl)
	adc	a, b
	ld	(hl), a
	inc	hl
	ld	a, (hl)
	adc	a, e
	ld	(hl), a
	inc	hl
	ld	a, (hl)
	adc	a, d
	ld	(hl), a
;zorblaxx_app.c:515: if (bonus < 0)
	bit	7, -4 (ix)
	jr	Z,00149$
;zorblaxx_app.c:517: if ((-bonus) > player_score)
	xor	a, a
	sub	a, -5 (ix)
	ld	c, a
	ld	a, #0x00
	sbc	a, -4 (ix)
	ld	b, a
	rla
	sbc	a, a
	ld	e, a
	ld	d, a
	ld	hl, #_player_score
	ld	a, (hl)
	sub	a, c
	inc	hl
	ld	a, (hl)
	sbc	a, b
	inc	hl
	ld	a, (hl)
	sbc	a, e
	inc	hl
	ld	a, (hl)
	sbc	a, d
	jr	NC,00149$
;zorblaxx_app.c:519: bonus = -player_score;
	ld	hl, #_player_score
	xor	a, a
	sub	a, (hl)
	ld	c, a
	ld	a, #0x00
	inc	hl
	sbc	a, (hl)
	ld	b, a
	ld	a, #0x00
	inc	hl
	sbc	a, (hl)
	ld	a, #0x00
	inc	hl
	sbc	a, (hl)
	ld	-5 (ix), c
	ld	-4 (ix), b
00149$:
;zorblaxx_app.c:522: player_score += bonus;
	ld	c, -5 (ix)
	ld	a, -4 (ix)
	ld	b, a
	rla
	sbc	a, a
	ld	e, a
	ld	d, a
	ld	hl, #_player_score
	ld	a, (hl)
	add	a, c
	ld	(hl), a
	inc	hl
	ld	a, (hl)
	adc	a, b
	ld	(hl), a
	inc	hl
	ld	a, (hl)
	adc	a, e
	ld	(hl), a
	inc	hl
	ld	a, (hl)
	adc	a, d
	ld	(hl), a
;zorblaxx_app.c:524: write_stringf_ushort("Time: %6d", 0xFF, 14, 13, level_time);
	ld	hl,#_level_time + 0
	ld	c, (hl)
	ld	b, #0x00
	push	bc
	ld	de, #0x0d0e
	push	de
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_11
	push	hl
	call	_write_stringf_ushort
	ld	hl, #7
	add	hl, sp
	ld	sp, hl
;zorblaxx_app.c:525: write_stringf_ushort("Par: %6d", 0xFF, 15, 14, par_time);
	ld	l, -3 (ix)
	ld	h, -2 (ix)
	push	hl
	ld	de, #0x0e0f
	push	de
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_12
	push	hl
	call	_write_stringf_ushort
	ld	hl, #7
	add	hl, sp
	ld	sp, hl
;zorblaxx_app.c:526: if (bonus > 0)
	xor	a, a
	cp	a, -5 (ix)
	sbc	a, -4 (ix)
	jp	PO, 00442$
	xor	a, #0x80
00442$:
	jp	P, 00151$
;zorblaxx_app.c:528: write_stringf_short("Bonus: %6d", 0b00011000, 13, 16, bonus);
	pop	bc
	pop	hl
	push	hl
	push	bc
	push	hl
	ld	de, #0x100d
	push	de
	ld	a, #0x18
	push	af
	inc	sp
	ld	hl, #___str_13
	push	hl
	call	_write_stringf_short
	ld	hl, #7
	add	hl, sp
	ld	sp, hl
	jr	00152$
00151$:
;zorblaxx_app.c:532: write_string("No bonus :(", 0b01011011, 14, 16);
	ld	de, #0x100e
	push	de
	ld	a, #0x5b
	push	af
	inc	sp
	ld	hl, #___str_14
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
00152$:
;zorblaxx_app.c:534: write_stringf_ulong("Score: %6d", 0xFF, 13, 18, player_score);
	ld	hl, (_player_score + 2)
	push	hl
	ld	hl, (_player_score)
	push	hl
	ld	de, #0x120d
	push	de
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_15
	push	hl
	call	_write_stringf_ulong
	ld	hl, #9
	add	hl, sp
	ld	sp, hl
;zorblaxx_app.c:535: clear_char_area(0, 10, 29, 30, 29);
	ld	de, #0x1d1e
	push	de
	ld	de, #0x1d0a
	push	de
	xor	a, a
	push	af
	inc	sp
	call	_clear_char_area
	pop	af
	pop	af
	inc	sp
;zorblaxx_app.c:537: break;
	jp	00177$
;zorblaxx_app.c:538: case field_complete: // Display field completed screen while bringing ship up to speed
00155$:
;zorblaxx_app.c:539: move_player_to_target();
	call	_move_player_to_target
;zorblaxx_app.c:540: if (player_speed < player_speed_warp)
	ld	hl,#_player_speed_warp + 0
	ld	c, (hl)
	ld	iy, #_player_speed
	ld	a, 0 (iy)
	sub	a, c
	jr	NC,00157$
;zorblaxx_app.c:542: player_speed++;
	inc	0 (iy)
	jp	00177$
00157$:
;zorblaxx_app.c:546: game_state = in_warp;
	ld	hl,#_game_state + 0
	ld	(hl), #0x05
;zorblaxx_app.c:548: break;
	jp	00177$
;zorblaxx_app.c:549: case in_warp: // Do a bit of warp speed
00159$:
;zorblaxx_app.c:550: move_player_to_target();
	call	_move_player_to_target
;zorblaxx_app.c:551: game_state_timer--;
	ld	hl, (_game_state_timer)
	dec	hl
	ld	(_game_state_timer), hl
;zorblaxx_app.c:552: if (game_state_timer == 0)
	ld	iy, #_game_state_timer
	ld	a, 1 (iy)
	or	a, 0 (iy)
	jp	NZ, 00177$
;zorblaxx_app.c:554: clear_char_area(0, 0, 2, 39, 20);
	ld	de, #0x1427
	push	de
	ld	a, #0x02
	push	af
	inc	sp
	xor	a, a
	push	af
	inc	sp
	xor	a, a
	push	af
	inc	sp
	call	_clear_char_area
	pop	af
	pop	af
	inc	sp
;zorblaxx_app.c:555: write_string("- Entering asteroid field -", 0xFF, 07, 16);
	ld	de, #0x1007
	push	de
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_16
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;zorblaxx_app.c:556: game_state = approaching_field;
	ld	hl,#_game_state + 0
	ld	(hl), #0x06
;zorblaxx_app.c:557: game_state_timer = game_state_danger_timeout;
	ld	hl, (_game_state_danger_timeout)
	ld	(_game_state_timer), hl
;zorblaxx_app.c:558: level_time = 0;
	ld	hl,#_level_time + 0
	ld	(hl), #0x00
;zorblaxx_app.c:560: break;
	jp	00177$
;zorblaxx_app.c:561: case approaching_field: // Slow down again ready for start
00162$:
;zorblaxx_app.c:562: move_player_to_target();
	call	_move_player_to_target
;zorblaxx_app.c:563: if (player_speed > player_speed_min)
	ld	a,(#_player_speed_min + 0)
	ld	iy, #_player_speed
	sub	a, 0 (iy)
	jr	NC,00164$
;zorblaxx_app.c:565: player_speed--;
	dec	0 (iy)
00164$:
;zorblaxx_app.c:568: level_time_timer++;
	ld	iy, #_level_time_timer
	inc	0 (iy)
;zorblaxx_app.c:569: if (level_time_timer >= 15)
	ld	a, 0 (iy)
	sub	a, #0x0f
	jr	C,00166$
;zorblaxx_app.c:571: play_sound(const_sound_alarm);
	ld	a, #0x02
	push	af
	inc	sp
	call	_play_sound
	inc	sp
;zorblaxx_app.c:572: write_string("DANGER!", level_time ? 0b00000111 : 0b00111111, 16, 14);
	ld	a,(#_level_time + 0)
	or	a, a
	jr	Z,00200$
	ld	bc, #0x0007
	jr	00201$
00200$:
	ld	bc, #0x003f
00201$:
	ld	b, c
	ld	de, #0x0e10
	push	de
	push	bc
	inc	sp
	ld	hl, #___str_17
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;zorblaxx_app.c:573: level_time = !level_time;
	ld	iy, #_level_time
	ld	a, 0 (iy)
	sub	a,#0x01
	ld	a, #0x00
	rla
	ld	0 (iy), a
;zorblaxx_app.c:574: level_time_timer = 0;
	ld	hl,#_level_time_timer + 0
	ld	(hl), #0x00
00166$:
;zorblaxx_app.c:577: game_state_timer--;
	ld	hl, (_game_state_timer)
	dec	hl
	ld	(_game_state_timer), hl
;zorblaxx_app.c:578: if (game_state_timer == 0)
	ld	iy, #_game_state_timer
	ld	a, 1 (iy)
	or	a, 0 (iy)
	jp	NZ, 00177$
;zorblaxx_app.c:580: clear_char_area(0, 0, 14, 39, 16);
	ld	de, #0x1027
	push	de
	ld	a, #0x0e
	push	af
	inc	sp
	xor	a, a
	push	af
	inc	sp
	xor	a, a
	push	af
	inc	sp
	call	_clear_char_area
	pop	af
	pop	af
	inc	sp
;zorblaxx_app.c:581: game_state = enter_field;
	ld	hl,#_game_state + 0
	ld	(hl), #0x01
;zorblaxx_app.c:582: setup_asteroids();
	call	_setup_asteroids
;zorblaxx_app.c:584: break;
	jp	00177$
;zorblaxx_app.c:585: case game_over:
00169$:
;zorblaxx_app.c:586: write_string("GAME OVER", 0b00000011, 16, 14);
	ld	de, #0x0e10
	push	de
	ld	a, #0x03
	push	af
	inc	sp
	ld	hl, #___str_18
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;zorblaxx_app.c:587: game_state_timer = game_state_gameover_timeout;
	ld	hl, (_game_state_gameover_timeout)
	ld	(_game_state_timer), hl
;zorblaxx_app.c:588: game_state = game_over_waitforstats;
	ld	hl,#_game_state + 0
	ld	(hl), #0x08
;zorblaxx_app.c:589: break;
	jp	00177$
;zorblaxx_app.c:590: case game_over_waitforstats:
00170$:
;zorblaxx_app.c:591: game_state_timer--;
	ld	hl, (_game_state_timer)
	dec	hl
	ld	(_game_state_timer), hl
;zorblaxx_app.c:592: if (game_state_timer == 0)
	ld	iy, #_game_state_timer
	ld	a, 1 (iy)
	or	a, 0 (iy)
	jp	NZ, 00177$
;zorblaxx_app.c:594: clear_char_area(0, 0, 14, 39, 14);
	ld	de, #0x0e27
	push	de
	ld	a, #0x0e
	push	af
	inc	sp
	xor	a, a
	push	af
	inc	sp
	xor	a, a
	push	af
	inc	sp
	call	_clear_char_area
	pop	af
	pop	af
	inc	sp
;zorblaxx_app.c:597: write_stringf_ulong("Final Score: %6d", 0xFF, 10, 11, player_score);
	ld	hl, (_player_score + 2)
	push	hl
	ld	hl, (_player_score)
	push	hl
	ld	de, #0x0b0a
	push	de
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_19
	push	hl
	call	_write_stringf_ulong
	ld	hl, #9
	add	hl, sp
	ld	sp, hl
;zorblaxx_app.c:599: write_stringf_ulong("Asteroids evaded: %6d", 0b00111111, 5, 14, asteroids_evaded);
	ld	hl,#_asteroids_evaded
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	ld	de, #0x0000
	push	de
	push	bc
	ld	de, #0x0e05
	push	de
	ld	a, #0x3f
	push	af
	inc	sp
	ld	hl, #___str_20
	push	hl
	call	_write_stringf_ulong
	ld	hl, #9
	add	hl, sp
	ld	sp, hl
;zorblaxx_app.c:600: write_stringf_ulong("Time bonuses: %6d", 0b00111000, 9, 16, time_bonuses_collected);
	ld	hl, (_time_bonuses_collected + 2)
	push	hl
	ld	hl, (_time_bonuses_collected)
	push	hl
	ld	de, #0x1009
	push	de
	ld	a, #0x38
	push	af
	inc	sp
	ld	hl, #___str_21
	push	hl
	call	_write_stringf_ulong
	ld	hl, #9
	add	hl, sp
	ld	sp, hl
;zorblaxx_app.c:601: write_stringf_ulong("Pickup bonuses: %6d", 0b00011111, 7, 18, pickup_bonuses_collected);
	ld	hl, (_pickup_bonuses_collected + 2)
	push	hl
	ld	hl, (_pickup_bonuses_collected)
	push	hl
	ld	de, #0x1207
	push	de
	ld	a, #0x1f
	push	af
	inc	sp
	ld	hl, #___str_22
	push	hl
	call	_write_stringf_ulong
	ld	hl, #9
	add	hl, sp
	ld	sp, hl
;zorblaxx_app.c:603: write_string("Press A to continue", 0xFF, 10, 21);
	ld	de, #0x150a
	push	de
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_23
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;zorblaxx_app.c:605: game_state = game_over_waitforscoreentry;
	ld	hl,#_game_state + 0
	ld	(hl), #0x0a
;zorblaxx_app.c:607: break;
	jr	00177$
;zorblaxx_app.c:608: case game_over_waitforscoreentry:
00173$:
;zorblaxx_app.c:609: if (button_a && !button_a_last)
	ld	a,(#_button_a + 0)
	or	a, a
	jr	Z,00177$
	ld	a,(#_button_a_last + 0)
	or	a, a
;zorblaxx_app.c:611: return;
;zorblaxx_app.c:614: }
	jp	Z,00194$
00177$:
;zorblaxx_app.c:617: if (player_score != player_score_last)
	ld	a,(#_player_score + 0)
	ld	iy, #_player_score_last
	sub	a, 0 (iy)
	jr	NZ,00443$
	ld	a,(#_player_score + 1)
	ld	iy, #_player_score_last
	sub	a, 1 (iy)
	jr	NZ,00443$
	ld	a,(#_player_score + 2)
	ld	iy, #_player_score_last
	sub	a, 2 (iy)
	jr	NZ,00443$
	ld	a,(#_player_score + 3)
	ld	iy, #_player_score_last
	sub	a, 3 (iy)
	jr	Z,00183$
00443$:
;zorblaxx_app.c:620: if (player_score > high_score)
	ld	hl, #_high_score
	ld	a, (hl)
	ld	iy, #_player_score
	sub	a, 0 (iy)
	inc	hl
	ld	a, (hl)
	sbc	a, 1 (iy)
	inc	hl
	ld	a, (hl)
	sbc	a, 2 (iy)
	inc	hl
	ld	a, (hl)
	sbc	a, 3 (iy)
	jr	NC,00179$
;zorblaxx_app.c:622: high_score = player_score;
	ld	de, #_high_score
	ld	hl, #_player_score
	ld	bc, #4
	ldir
00179$:
;zorblaxx_app.c:626: write_stringf_ulong("%d", 0xFF, 0, 1, player_score);
	ld	hl, (_player_score + 2)
	push	hl
	ld	hl, (_player_score)
	push	hl
	ld	a, #0x01
	push	af
	inc	sp
	xor	a, a
	ld	d,a
	ld	e,#0xff
	push	de
	ld	hl, #___str_24
	push	hl
	call	_write_stringf_ulong
	ld	hl, #9
	add	hl, sp
	ld	sp, hl
;zorblaxx_app.c:629: write_stringf_ulong("%6d", 0xFF, 16, 1, high_score);
	ld	hl, (_high_score + 2)
	push	hl
	ld	hl, (_high_score)
	push	hl
	ld	de, #0x0110
	push	de
	ld	a, #0xff
	push	af
	inc	sp
	ld	hl, #___str_25
	push	hl
	call	_write_stringf_ulong
	ld	hl, #9
	add	hl, sp
	ld	sp, hl
;zorblaxx_app.c:631: player_score_last = player_score;
	ld	de, #_player_score_last
	ld	hl, #_player_score
	ld	bc, #4
	ldir
00183$:
;zorblaxx_app.c:635: vblank_last = vblank;
	ld	a,(#_vblank + 0)
	ld	(#_vblank_last + 0),a
	jp	00186$
00194$:
;zorblaxx_app.c:637: }
	ld	sp, ix
	pop	ix
	ret
___str_1:
	.ascii "%2d"
	.db 0x00
___str_2:
	.ascii "1UP"
	.db 0x00
___str_3:
	.ascii "HIGH SCORE"
	.db 0x00
___str_4:
	.ascii "SHIPS"
	.db 0x00
___str_5:
	.ascii "Avoid the asteroids!"
	.db 0x00
___str_6:
	.ascii "Use A to boost for time bonus"
	.db 0x00
___str_7:
	.ascii "Collect gems for extra points"
	.db 0x00
___str_8:
	.ascii "%3d%%"
	.db 0x00
___str_9:
	.ascii "100%"
	.db 0x00
___str_10:
	.ascii "-- FIELD %d COMPLETED --"
	.db 0x00
___str_11:
	.ascii "Time: %6d"
	.db 0x00
___str_12:
	.ascii "Par: %6d"
	.db 0x00
___str_13:
	.ascii "Bonus: %6d"
	.db 0x00
___str_14:
	.ascii "No bonus :("
	.db 0x00
___str_15:
	.ascii "Score: %6d"
	.db 0x00
___str_16:
	.ascii "- Entering asteroid field -"
	.db 0x00
___str_17:
	.ascii "DANGER!"
	.db 0x00
___str_18:
	.ascii "GAME OVER"
	.db 0x00
___str_19:
	.ascii "Final Score: %6d"
	.db 0x00
___str_20:
	.ascii "Asteroids evaded: %6d"
	.db 0x00
___str_21:
	.ascii "Time bonuses: %6d"
	.db 0x00
___str_22:
	.ascii "Pickup bonuses: %6d"
	.db 0x00
___str_23:
	.ascii "Press A to continue"
	.db 0x00
___str_24:
	.ascii "%d"
	.db 0x00
___str_25:
	.ascii "%6d"
	.db 0x00
;zorblaxx_app.c:639: void app_zorblaxx()
;	---------------------------------
; Function app_zorblaxx
; ---------------------------------
_app_zorblaxx::
;zorblaxx_app.c:641: setup_variables();
	call	_setup_variables
;zorblaxx_app.c:642: while (1)
00106$:
;zorblaxx_app.c:644: clear_chars(0);
	xor	a, a
	push	af
	inc	sp
	call	_clear_chars
	inc	sp
;zorblaxx_app.c:645: clear_sprites();
	call	_clear_sprites
;zorblaxx_app.c:646: stop_music();
	call	_stop_music
;zorblaxx_app.c:647: if (pleaseStop)
	ld	a,(#_pleaseStop + 0)
	or	a, a
;zorblaxx_app.c:649: return;
	ret	NZ
;zorblaxx_app.c:652: setup_player(player_spawn_x, 256, player_lives_default);
	ld	a, (_player_lives_default)
	push	af
	inc	sp
	ld	hl, #0x0100
	push	hl
	ld	hl, (_player_spawn_x)
	push	hl
	call	_setup_player
	pop	af
	pop	af
	inc	sp
;zorblaxx_app.c:653: set_player_target(player_spawn_x * x_divisor, player_spawn_y * y_divisor, 6, 24);
	ld	hl,#_y_divisor + 0
	ld	c, (hl)
	ld	b, #0x00
	push	bc
	ld	hl, (_player_spawn_y)
	push	hl
	call	__mulint
	pop	af
	pop	af
	ld	c, l
	ld	b, h
	ld	hl,#_x_divisor + 0
	ld	e, (hl)
	ld	d, #0x00
	push	bc
	push	de
	ld	hl, (_player_spawn_x)
	push	hl
	call	__mulint
	pop	af
	pop	af
	pop	bc
	ld	de, #0x1806
	push	de
	push	bc
	push	hl
	call	_set_player_target
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
;zorblaxx_app.c:654: setup_trails();
	call	_setup_trails
;zorblaxx_app.c:656: intro_loop();
	call	_intro_loop
;zorblaxx_app.c:659: clear_tilemap();
	call	_clear_tilemap
;zorblaxx_app.c:660: clear_chars(0);
	xor	a, a
	push	af
	inc	sp
	call	_clear_chars
	inc	sp
;zorblaxx_app.c:661: clear_sprites();
	call	_clear_sprites
;zorblaxx_app.c:662: stop_music();
	call	_stop_music
;zorblaxx_app.c:663: if (pleaseStop)
	ld	a,(#_pleaseStop + 0)
	or	a, a
;zorblaxx_app.c:665: return;
	ret	NZ
;zorblaxx_app.c:668: game_loop();
	call	_game_loop
;zorblaxx_app.c:670: }
	jr	00106$
	.area _CODE
___str_26:
	.ascii "CODE AND GFX BY JIMMYSTONES   ...   MUSIC BY DARRIN CARDANI "
	.ascii "  ...   "
	.db 0x00
	.area _INITIALIZER
__xinit__x_min:
	.dw #0x0002
__xinit__x_max:
	.dw #0x0150
__xinit__player_spawn_x:
	.dw #0x00b8
__xinit__player_spawn_y:
	.dw #0x00c8
__xinit__game_state:
	.db #0x00	; 0
__xinit__game_state_timer:
	.dw #0x0000
__xinit__level_number:
	.db #0x00	; 0
__xinit__level_time:
	.db #0x00	; 0
__xinit__level_time_timer:
	.db #0x00	; 0
__xinit__level_playercontrol:
	.db #0x00	; 0
__xinit__level_progress:
	.dw #0x0000
__xinit__level_progress_timer:
	.db #0x00	; 0
__xinit__level_progress_base:
	.dw #0x4e20
__xinit__game_state_warp_timeout_first:
	.dw #0x0078
__xinit__game_state_warp_timeout:
	.dw #0x00f0
__xinit__game_state_danger_timeout:
	.dw #0x0078
__xinit__game_state_gameover_timeout:
	.dw #0x0078
__xinit__player_lives_default:
	.db #0x03	; 3
__xinit__pickup_spawn_timer:
	.db #0x00	; 0
__xinit__pickup_spawn_timer_min:
	.db #0x78	; 120	'x'
__xinit__high_score:
	.byte #0x88,#0x13,#0x00,#0x00	; 5000
__xinit__bonus_score_multiplier:
	.db #0x0a	; 10
__xinit__player_score:
	.byte #0x00,#0x00,#0x00,#0x00	; 0
__xinit__high_score_passed:
	.db #0x00	; 0
__xinit__player_score_timer:
	.db #0x00	; 0
__xinit__player_score_timer_frequency:
	.db #0x64	; 100	'd'
__xinit__scroller_text:
	.dw ___str_26
__xinit__scroller_pos:
	.db #0x00	; 0
__xinit__scroller_entry_pos:
	.dw #0x01d5
__xinit__scroll_speed_last:
	.db #0x00	; 0
__xinit__sf_speed1:
	.db #0x04	; 4
	.area _CABS (ABS)
