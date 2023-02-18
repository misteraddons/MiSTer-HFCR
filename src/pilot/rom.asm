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
	.globl _basic_input
	.globl _handle_projectiles
	.globl _init_projectiles
	.globl _update_particles
	.globl _spawn_particle
	.globl _init_particles
	.globl _set_starfield_speed_y
	.globl _set_starfield_speed_x
	.globl _enable_starfield
	.globl _clear_sprites
	.globl _enable_sprite
	.globl _update_sprites
	.globl _set_sprite_position
	.globl _write_bgcol_row
	.globl _write_stringf_ushort
	.globl _write_stringf
	.globl _write_string
	.globl _set_default_char_palette
	.globl _clear_bgcolor
	.globl _clear_char_area
	.globl _rand_ushort
	.globl _rand_uchar
	.globl _vector_y
	.globl _vector_x
	.globl _player_trail_freq
	.globl _screen_center_scaled_y
	.globl _screen_center_scaled_x
	.globl _input_a_last
	.globl _input_down_last
	.globl _input_down
	.globl _input_up_last
	.globl _input_up
	.globl _input_right_last
	.globl _input_right
	.globl _input_left_last
	.globl _input_left
	.globl _enemy_y
	.globl _enemy_x
	.globl _enemy_on
	.globl _sf_dir_y_last
	.globl _sf_dir_x_last
	.globl _player_shot_timer
	.globl _player_trail_timer
	.globl _player_shot_offset_y
	.globl _player_shot_offset_x
	.globl _player_trail_offset_y
	.globl _player_trail_offset_x
	.globl _player_thrust_rev_y
	.globl _player_thrust_rev_x
	.globl _player_thrust_y
	.globl _player_thrust_x
	.globl _player_a
	.globl _player_a_acc
	.globl _scroll_v_y
	.globl _scroll_v_x
	.globl _input_a
	.globl _spritecollisionram
	.globl _spriteram
	.globl _charpaletteram
	.globl _bgcolram
	.globl _fgcolram
	.globl _chram
	.globl _tilemapram
	.globl _tilemapctl
	.globl _musicram
	.globl _sndram
	.globl _system_menu
	.globl _system_pause
	.globl _starfield3
	.globl _starfield2
	.globl _starfield1
	.globl _ps2_mouse
	.globl _ps2_key
	.globl _spinner
	.globl _paddle
	.globl _analog_r
	.globl _analog_l
	.globl _joystick
	.globl _timer
	.globl _timestamp
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
_timestamp	=	0x8080
_timer	=	0x80c0
_joystick	=	0x8100
_analog_l	=	0x8200
_analog_r	=	0x8280
_paddle	=	0x8300
_spinner	=	0x8380
_ps2_key	=	0x8400
_ps2_mouse	=	0x8480
_starfield1	=	0x8500
_starfield2	=	0x8510
_starfield3	=	0x8520
_system_pause	=	0x8530
_system_menu	=	0x8531
_sndram	=	0x8580
_musicram	=	0x8590
_tilemapctl	=	0x8600
_tilemapram	=	0x8610
_chram	=	0x9200
_fgcolram	=	0x9a00
_bgcolram	=	0xa200
_charpaletteram	=	0xaa00
_spriteram	=	0xb000
_spritecollisionram	=	0xb400
_input_a::
	.ds 1
_scroll_v_x::
	.ds 2
_scroll_v_y::
	.ds 2
_player_a_acc::
	.ds 1
_player_a::
	.ds 1
_player_thrust_x::
	.ds 32
_player_thrust_y::
	.ds 32
_player_thrust_rev_x::
	.ds 32
_player_thrust_rev_y::
	.ds 32
_player_trail_offset_x::
	.ds 32
_player_trail_offset_y::
	.ds 32
_player_shot_offset_x::
	.ds 32
_player_shot_offset_y::
	.ds 32
_player_trail_timer::
	.ds 1
_player_shot_timer::
	.ds 1
_sf_dir_x_last::
	.ds 1
_sf_dir_y_last::
	.ds 1
_enemy_on::
	.ds 3
_enemy_x::
	.ds 6
_enemy_y::
	.ds 6
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
_input_a_last::
	.ds 1
_screen_center_scaled_x::
	.ds 2
_screen_center_scaled_y::
	.ds 2
_player_trail_freq::
	.ds 1
_vector_x::
	.ds 16
_vector_y::
	.ds 16
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
;os.c:48: void basic_input()
;	---------------------------------
; Function basic_input
; ---------------------------------
_basic_input::
;os.c:50: input_up_last = input_up;
	ld	a,(#_input_up + 0)
	ld	iy, #_input_up_last
	ld	0 (iy), a
;os.c:51: input_down_last = input_down;
	ld	a,(#_input_down + 0)
	ld	iy, #_input_down_last
	ld	0 (iy), a
;os.c:52: input_left_last = input_left;
	ld	a,(#_input_left + 0)
	ld	iy, #_input_left_last
	ld	0 (iy), a
;os.c:53: input_right_last = input_right;
	ld	a,(#_input_right + 0)
	ld	iy, #_input_right_last
	ld	0 (iy), a
;os.c:54: input_a_last = input_a;
	ld	a,(#_input_a + 0)
	ld	iy, #_input_a_last
	ld	0 (iy), a
;os.c:55: input_up = CHECK_BIT(joystick[0], 3);
	ld	a, (#_joystick + 0)
	and	a, #0x08
	ld	c, a
	xor	a, a
	cp	a, c
	rla
	ld	(_input_up+0), a
;os.c:56: input_down = CHECK_BIT(joystick[0], 2);
	ld	a, (#_joystick + 0)
	and	a, #0x04
	ld	c, a
	xor	a, a
	cp	a, c
	rla
	ld	(_input_down+0), a
;os.c:57: input_left = CHECK_BIT(joystick[0], 1);
	ld	a, (#_joystick + 0)
	and	a, #0x02
	ld	c, a
	xor	a, a
	cp	a, c
	rla
	ld	(_input_left+0), a
;os.c:58: input_right = CHECK_BIT(joystick[0], 0);
	ld	a, (#_joystick + 0)
	and	a, #0x01
	ld	(_input_right+0), a
;os.c:59: input_a = CHECK_BIT(joystick[0], 4);
	ld	a, (#_joystick + 0)
	and	a, #0x10
	ld	c, a
	xor	a, a
	cp	a, c
	rla
	ld	(_input_a+0), a
;os.c:60: }
	ret
;os.c:110: void main()
;	---------------------------------
; Function main
; ---------------------------------
_main::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	hl, #-8
	add	hl, sp
	ld	sp, hl
;os.c:113: chram_size = chram_cols * chram_rows;
	ld	hl,#_chram_rows + 0
	ld	e, (hl)
	ld	hl,#_chram_cols + 0
	ld	h, (hl)
	ld	l, #0x00
	ld	d, l
	ld	b, #0x08
00371$:
	add	hl, hl
	jr	NC,00372$
	add	hl, de
00372$:
	djnz	00371$
	ld	(_chram_size), hl
;os.c:114: set_default_char_palette();
	call	_set_default_char_palette
;os.c:115: clear_bgcolor(transparent_char);
	ld	a, #0xc7
	push	af
	inc	sp
	call	_clear_bgcolor
	inc	sp
;os.c:116: clear_sprites();
	call	_clear_sprites
;os.c:118: write_string("CALCULATING VECTORS", 15, 0, 0);
	xor	a, a
	push	af
	inc	sp
	xor	a, a
	ld	d,a
	ld	e,#0x0f
	push	de
	ld	hl, #___str_0
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;os.c:121: for (unsigned char v = 0; v < direction_count; v++)
	xor	a, a
	ld	-1 (ix), a
00167$:
	ld	a, -1 (ix)
	sub	a, #0x10
	jp	NC, 00101$
;os.c:124: player_thrust_x[v] = (vector_x[v] * player_thrust_mag) / 100;
	ld	a, -1 (ix)
	ld	-3 (ix), a
	xor	a, a
	ld	-2 (ix), a
	ld	a, -3 (ix)
	ld	-7 (ix), a
	ld	a, -2 (ix)
	ld	-6 (ix), a
	sla	-7 (ix)
	rl	-6 (ix)
	ld	a, #<(_player_thrust_x)
	add	a, -7 (ix)
	ld	e, a
	ld	a, #>(_player_thrust_x)
	adc	a, -6 (ix)
	ld	d, a
	ld	a, #<(_vector_x)
	add	a, -1 (ix)
	ld	c, a
	ld	a, #>(_vector_x)
	adc	a, #0x00
	ld	b, a
	ld	a, (bc)
	ld	l, a
	rla
	sbc	a, a
	ld	h, a
	push	de
	ld	e, l
	ld	d, h
	add	hl, hl
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, hl
	pop	de
	ld	-3 (ix), l
	ld	-2 (ix), h
	push	bc
	push	de
	ld	hl, #0x0064
	push	hl
	ld	l, -3 (ix)
	ld	h, -2 (ix)
	push	hl
	call	__divsint
	pop	af
	pop	af
	pop	de
	pop	bc
	ld	-3 (ix), l
	ld	-2 (ix), h
	ld	a, -3 (ix)
	ld	(de), a
	inc	de
	ld	a, -2 (ix)
	ld	(de), a
;os.c:125: player_thrust_y[v] = (vector_y[v] * player_thrust_mag) / 100;
	ld	a, #<(_player_thrust_y)
	add	a, -7 (ix)
	ld	-3 (ix), a
	ld	a, #>(_player_thrust_y)
	adc	a, -6 (ix)
	ld	-2 (ix), a
	ld	a, #<(_vector_y)
	add	a, -1 (ix)
	ld	-5 (ix), a
	ld	a, #>(_vector_y)
	adc	a, #0x00
	ld	-4 (ix), a
	ld	l, -5 (ix)
	ld	h, -4 (ix)
	ld	a, (hl)
	ld	e, a
	rla
	sbc	a, a
	ld	d, a
	ld	l, e
	ld	h, d
	add	hl, hl
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, hl
	push	bc
	ld	de, #0x0064
	push	de
	push	hl
	call	__divsint
	pop	af
	pop	af
	pop	bc
	ex	de,hl
	ld	l, -3 (ix)
	ld	h, -2 (ix)
	ld	(hl), e
	inc	hl
	ld	(hl), d
;os.c:126: player_thrust_rev_x[v] = (vector_x[v] * player_thrust_rev_mag) / 100;
	ld	a, #<(_player_thrust_rev_x)
	add	a, -7 (ix)
	ld	-3 (ix), a
	ld	a, #>(_player_thrust_rev_x)
	adc	a, -6 (ix)
	ld	-2 (ix), a
	ld	a, (bc)
	ld	e, a
	rlc	a
	sbc	a, a
	ld	d, a
	ld	l, e
	ld	h, d
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	push	bc
	ld	de, #0x0064
	push	de
	push	hl
	call	__divsint
	pop	af
	pop	af
	pop	bc
	ex	de,hl
	ld	l, -3 (ix)
	ld	h, -2 (ix)
	ld	(hl), e
	inc	hl
	ld	(hl), d
;os.c:127: player_thrust_rev_y[v] = (vector_y[v] * player_thrust_rev_mag) / 100;
	ld	a, #<(_player_thrust_rev_y)
	add	a, -7 (ix)
	ld	-3 (ix), a
	ld	a, #>(_player_thrust_rev_y)
	adc	a, -6 (ix)
	ld	-2 (ix), a
	ld	l, -5 (ix)
	ld	h, -4 (ix)
	ld	e, (hl)
	ld	a, e
	rlc	a
	sbc	a, a
	ld	d, a
	ld	l, e
	ld	h, d
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	push	bc
	ld	de, #0x0064
	push	de
	push	hl
	call	__divsint
	pop	af
	pop	af
	pop	bc
	ex	de,hl
	ld	l, -3 (ix)
	ld	h, -2 (ix)
	ld	(hl), e
	inc	hl
	ld	(hl), d
;os.c:130: player_trail_offset_x[v] = (vector_x[v]) * -8;
	ld	a, #<(_player_trail_offset_x)
	add	a, -7 (ix)
	ld	-3 (ix), a
	ld	a, #>(_player_trail_offset_x)
	adc	a, -6 (ix)
	ld	-2 (ix), a
	ld	a, (bc)
	ld	e, a
	rlc	a
	sbc	a, a
	ld	d, a
	ld	l, e
	ld	h, d
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, hl
	add	hl, hl
	ex	de, hl
	ld	l, -3 (ix)
	ld	h, -2 (ix)
	ld	(hl), e
	inc	hl
	ld	(hl), d
;os.c:131: player_trail_offset_y[v] = (vector_y[v]) * -8;
	ld	a, #<(_player_trail_offset_y)
	add	a, -7 (ix)
	ld	-3 (ix), a
	ld	a, #>(_player_trail_offset_y)
	adc	a, -6 (ix)
	ld	-2 (ix), a
	ld	l, -5 (ix)
	ld	h, -4 (ix)
	ld	e, (hl)
	ld	a, e
	rlc	a
	sbc	a, a
	ld	d, a
	ld	l, e
	ld	h, d
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, hl
	add	hl, hl
	ex	de, hl
	ld	l, -3 (ix)
	ld	h, -2 (ix)
	ld	(hl), e
	inc	hl
	ld	(hl), d
;os.c:134: player_shot_offset_x[v] = (vector_x[v]) * 11;
	ld	a, #<(_player_shot_offset_x)
	add	a, -7 (ix)
	ld	e, a
	ld	a, #>(_player_shot_offset_x)
	adc	a, -6 (ix)
	ld	d, a
	ld	a, (bc)
	ld	c, a
	rla
	sbc	a, a
	ld	b, a
	ld	l, c
	ld	h, b
	add	hl, hl
	add	hl, hl
	add	hl, bc
	add	hl, hl
	add	hl, bc
	ld	c, l
	ld	b, h
	ld	a, c
	ld	(de), a
	inc	de
	ld	a, b
	ld	(de), a
;os.c:135: player_shot_offset_y[v] = (vector_y[v]) * 11;
	ld	a, #<(_player_shot_offset_y)
	add	a, -7 (ix)
	ld	c, a
	ld	a, #>(_player_shot_offset_y)
	adc	a, -6 (ix)
	ld	b, a
	ld	l, -5 (ix)
	ld	h, -4 (ix)
	ld	a, (hl)
	ld	e, a
	rla
	sbc	a, a
	ld	d, a
	ld	l, e
	ld	h, d
	add	hl, hl
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, de
	ex	de, hl
	ld	a, e
	ld	(bc), a
	inc	bc
	ld	a, d
	ld	(bc), a
;os.c:121: for (unsigned char v = 0; v < direction_count; v++)
	inc	-1 (ix)
	jp	00167$
00101$:
;os.c:137: clear_char_area(0, 0, 0, 40, 0);
	xor	a, a
	ld	d,a
	ld	e,#0x28
	push	de
	xor	a, a
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
;os.c:140: enable_sprite(player_sprite, sprite_palette_player, sprite_size_player, 1);
	ld	de, #0x0101
	push	de
	xor	a, a
	ld	d,a
	ld	e,#0x10
	push	de
	call	_enable_sprite
	pop	af
	pop	af
;os.c:142: set_sprite_position(player_sprite, screen_center_x - sprite_halfpixelsize_player, screen_center_y - sprite_halfpixelsize_player);
	ld	hl, #0x0088
	push	hl
	ld	l, #0xa8
	push	hl
	ld	a, #0x10
	push	af
	inc	sp
	call	_set_sprite_position
	pop	af
	pop	af
	inc	sp
;os.c:145: enable_starfield();
	call	_enable_starfield
;os.c:148: init_particles();
	call	_init_particles
;os.c:150: init_projectiles();
	call	_init_projectiles
;os.c:154: for (unsigned char e = 0; e < const_enemy_max; e++)
	ld	c, #0x00
00170$:
;os.c:156: unsigned char s = const_enemy_sprite_first + e;
	ld	a,c
	cp	a,#0x03
	jr	NC,00102$
	add	a, #0x11
	ld	e, a
;os.c:157: enable_sprite(s, sprite_palette_enemy, sprite_size_enemy, true);
	push	bc
	push	de
	ld	bc, #0x0101
	push	bc
	ld	d,#0x02
	push	de
	call	_enable_sprite
	pop	af
	pop	af
	pop	de
	pop	bc
;os.c:158: spr_index[s] = sprite_index_enemy_first;
	ld	hl, #_spr_index
	ld	d, #0x00
	add	hl, de
	ld	(hl), #0x00
;os.c:159: spr_on[s] = 0;
	ld	hl, #_spr_on
	ld	d, #0x00
	add	hl, de
	ld	(hl), #0x00
;os.c:154: for (unsigned char e = 0; e < const_enemy_max; e++)
	inc	c
	jr	00170$
00102$:
;os.c:163: write_bgcol_row(0b00000000, 1, 29, 40);
	ld	de, #0x281d
	push	de
	ld	a, #0x01
	push	af
	inc	sp
	xor	a, a
	push	af
	inc	sp
	call	_write_bgcol_row
	pop	af
;os.c:164: write_string("Score might be here, or some other stuff", 15, 0, 29);
	ld	h,#0x1d
	ex	(sp),hl
	inc	sp
	xor	a, a
	ld	d,a
	ld	e,#0x0f
	push	de
	ld	hl, #___str_1
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;os.c:166: while (1)
	xor	a, a
	ld	-2 (ix), a
00164$:
;os.c:168: vblank = CHECK_BIT(input0, INPUT_VBLANK);
	ld	a,(#_input0 + 0)
	and	a, #0x10
	ld	c, a
	xor	a, a
	cp	a, c
	rla
	ld	(_vblank+0), a
;os.c:170: if (VBLANK_RISING)
	ld	iy, #_vblank
	bit	0, 0 (iy)
	jr	Z,00104$
	ld	iy, #_vblank_last
	bit	0, 0 (iy)
	jr	NZ,00104$
;os.c:172: update_sprites();
	call	_update_sprites
00104$:
;os.c:174: if (VBLANK_FALLING)
	ld	iy, #_vblank
	bit	0, 0 (iy)
	jp	NZ, 00161$
	ld	iy, #_vblank_last
	bit	0, 0 (iy)
	jp	Z, 00161$
;os.c:176: basic_input();
	call	_basic_input
;os.c:179: timer[0] = 0;
	ld	hl, #_timer
	ld	(hl), #0x00
;os.c:181: unsigned char target_a_acc = player_a_acc;
	ld	a,(#_player_a_acc + 0)
	ld	-1 (ix), a
;os.c:182: if (input_left)
	ld	iy, #_input_left
	bit	0, 0 (iy)
	jr	Z,00127$
;os.c:184: if (input_up)
	ld	iy, #_input_up
	bit	0, 0 (iy)
	jr	Z,00110$
;os.c:186: target_a_acc = 231;
	ld	-1 (ix), #0xe7
	jr	00128$
00110$:
;os.c:188: else if (input_down)
	ld	iy, #_input_down
	bit	0, 0 (iy)
	jr	Z,00107$
;os.c:190: target_a_acc = 167;
	ld	-1 (ix), #0xa7
	jr	00128$
00107$:
;os.c:194: target_a_acc = 200;
	ld	-1 (ix), #0xc8
	jr	00128$
00127$:
;os.c:197: else if (input_right)
	ld	iy, #_input_right
	bit	0, 0 (iy)
	jr	Z,00124$
;os.c:199: if (input_up)
	ld	iy, #_input_up
	bit	0, 0 (iy)
	jr	Z,00116$
;os.c:201: target_a_acc = 40;
	ld	-1 (ix), #0x28
	jr	00128$
00116$:
;os.c:203: else if (input_down)
	ld	iy, #_input_down
	bit	0, 0 (iy)
	jr	Z,00113$
;os.c:205: target_a_acc = 104;
	ld	-1 (ix), #0x68
	jr	00128$
00113$:
;os.c:209: target_a_acc = 72;
	ld	-1 (ix), #0x48
	jr	00128$
00124$:
;os.c:214: if (input_up)
	ld	iy, #_input_up
	bit	0, 0 (iy)
	jr	Z,00121$
;os.c:216: target_a_acc = 8;
	ld	-1 (ix), #0x08
	jr	00128$
00121$:
;os.c:218: else if (input_down)
	ld	iy, #_input_down
	bit	0, 0 (iy)
	jr	Z,00128$
;os.c:220: target_a_acc = 136;
	ld	-1 (ix), #0x88
00128$:
;os.c:224: if (target_a_acc != player_a_acc)
	ld	a,(#_player_a_acc + 0)
	sub	a, -1 (ix)
	jr	Z,00137$
;os.c:226: unsigned char diff = target_a_acc - player_a_acc;
	ld	hl, #_player_a_acc
	ld	a, -1 (ix)
	sub	a, (hl)
	ld	-1 (ix), a
;os.c:227: if (diff > 127)
	ld	a, #0x7f
	sub	a, -1 (ix)
	jr	NC,00134$
;os.c:229: diff = 255 - (diff - 1);
	ld	c, -1 (ix)
	dec	c
	ld	a, #0xff
	sub	a, c
	ld	c, a
;os.c:230: if (diff > player_turn_speed_max)
	ld	a, #0x04
	sub	a, c
	jr	NC,00130$
;os.c:232: diff = player_turn_speed_max;
	ld	c, #0x04
00130$:
;os.c:234: player_a_acc -= diff;
	ld	hl, #_player_a_acc
	ld	a, (hl)
	sub	a, c
	ld	(hl), a
	jr	00137$
00134$:
;os.c:238: if (diff > player_turn_speed_max)
	ld	a, #0x04
	sub	a, -1 (ix)
	jr	NC,00132$
;os.c:240: diff = player_turn_speed_max;
	ld	-1 (ix), #0x04
00132$:
;os.c:242: player_a_acc += diff;
	ld	hl, #_player_a_acc
	ld	a, (hl)
	add	a, -1 (ix)
	ld	(hl), a
00137$:
;os.c:246: player_a = player_a_acc >> 4;
	ld	a,(#_player_a_acc + 0)
	rlca
	rlca
	rlca
	rlca
	and	a, #0x0f
	ld	(_player_a+0), a
;os.c:249: spr_index[player_sprite] = sprite_index_player_first + player_a;
	ld	bc, #_spr_index + 16
	ld	iy, #_player_a
	ld	a, 0 (iy)
	add	a, #0x09
	ld	(bc), a
;os.c:251: scroll_v_x += player_thrust_x[player_a];
	ld	l, 0 (iy)
	ld	h, #0x00
	add	hl, hl
	ld	c, l
	ld	b, h
	ld	hl, #_player_thrust_x
	add	hl, bc
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	ld	hl, #_scroll_v_x
	ld	a, (hl)
	add	a, e
	ld	(hl), a
	inc	hl
	ld	a, (hl)
	adc	a, d
	ld	(hl), a
;os.c:252: scroll_v_y += player_thrust_y[player_a];
	ld	hl, #_player_thrust_y
	add	hl, bc
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	ld	hl, #_scroll_v_y
	ld	a, (hl)
	add	a, c
	ld	(hl), a
	inc	hl
	ld	a, (hl)
	adc	a, b
	ld	(hl), a
;os.c:257: scroll_v_x = (signed short)(((signed long)scroll_v_x * player_v_friction) / 100);
	ld	hl,#_scroll_v_x
	ld	c, (hl)
	inc	hl
	ld	a, (hl)
	ld	b, a
	rla
	sbc	a, a
	ld	e, a
	ld	d, a
	push	de
	push	bc
	ld	hl, #0x0000
	push	hl
	ld	hl, #0x005a
	push	hl
	call	__mullong
	pop	af
	pop	af
	pop	af
	ex	(sp),hl
	pop	iy
	ld	hl, #0x0000
	push	hl
	ld	hl, #0x0064
	push	hl
	push	de
	push	iy
	call	__divslong
	pop	af
	pop	af
	pop	af
	pop	af
	ld	iy, #_scroll_v_x
	ld	0 (iy), l
	ld	1 (iy), h
;os.c:258: scroll_v_y = (signed short)(((signed long)scroll_v_y * player_v_friction) / 100);
	ld	hl,#_scroll_v_y
	ld	c, (hl)
	inc	hl
	ld	a, (hl)
	ld	b, a
	rla
	sbc	a, a
	ld	e, a
	ld	d, a
	push	de
	push	bc
	ld	hl, #0x0000
	push	hl
	ld	hl, #0x005a
	push	hl
	call	__mullong
	pop	af
	pop	af
	pop	af
	ex	(sp),hl
	pop	iy
	ld	hl, #0x0000
	push	hl
	ld	hl, #0x0064
	push	hl
	push	de
	push	iy
	call	__divslong
	pop	af
	pop	af
	pop	af
	pop	af
	ld	iy, #_scroll_v_y
	ld	0 (iy), l
	ld	1 (iy), h
;os.c:260: if (player_shot_timer > 0)
	ld	iy, #_player_shot_timer
	ld	a, 0 (iy)
	or	a, a
	jr	Z,00144$
;os.c:262: player_shot_timer--;
	dec	0 (iy)
	jp	00145$
00144$:
;os.c:266: if (input_a)
	ld	hl,#_input_a+0
	bit	0, (hl)
	jp	Z, 00145$
;os.c:268: for (unsigned char p = 0; p < const_projectile_max; p++)
	xor	a, a
	ld	-1 (ix), a
	xor	a, a
	ld	-3 (ix), a
00173$:
	ld	a, -3 (ix)
	sub	a, #0x08
	jp	NC, 00140$
;os.c:270: if (!projectile_on[p])
	ld	a, #<(_projectile_on)
	add	a, -3 (ix)
	ld	-5 (ix), a
	ld	a, #>(_projectile_on)
	adc	a, #0x00
	ld	-4 (ix), a
	ld	l, -5 (ix)
	ld	h, -4 (ix)
	bit	0, (hl)
	jp	NZ, 00174$
;os.c:272: projectile_on[p] = true;
	ld	l, -5 (ix)
	ld	h, -4 (ix)
	ld	(hl), #0x01
;os.c:273: projectile_x[p] = (screen_center_scaled_x + player_shot_offset_x[player_a]) + scale_half;
	ld	l, -1 (ix)
	ld	h, #0x00
	add	hl, hl
	ld	-6 (ix), l
	ld	-5 (ix), h
	ld	a, #<(_projectile_x)
	add	a, -6 (ix)
	ld	-4 (ix), a
	ld	a, #>(_projectile_x)
	adc	a, -5 (ix)
	ld	-3 (ix), a
	ld	iy, #_player_a
	ld	l, 0 (iy)
	ld	h, #0x00
	add	hl, hl
	ld	de, #_player_shot_offset_x
	add	hl, de
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	ld	hl, (_screen_center_scaled_x)
	add	hl, bc
	ld	bc, #0x0040
	add	hl, bc
	ld	c, l
	ld	b, h
	ld	l, -4 (ix)
	ld	h, -3 (ix)
	ld	(hl), c
	inc	hl
	ld	(hl), b
;os.c:274: projectile_y[p] = (screen_center_scaled_y + player_shot_offset_y[player_a]) + scale_half;
	ld	a, #<(_projectile_y)
	add	a, -6 (ix)
	ld	-4 (ix), a
	ld	a, #>(_projectile_y)
	adc	a, -5 (ix)
	ld	-3 (ix), a
	ld	l, 0 (iy)
	ld	h, #0x00
	add	hl, hl
	ld	de, #_player_shot_offset_y
	add	hl, de
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	ld	hl, (_screen_center_scaled_y)
	add	hl, bc
	ld	bc, #0x0040
	add	hl, bc
	ld	c, l
	ld	b, h
	ld	l, -4 (ix)
	ld	h, -3 (ix)
	ld	(hl), c
	inc	hl
	ld	(hl), b
;os.c:275: projectile_v_x[p] = scroll_v_x + (vector_x[player_a] * player_shot_speed);
	ld	a, #<(_projectile_v_x)
	add	a, -6 (ix)
	ld	c, a
	ld	a, #>(_projectile_v_x)
	adc	a, -5 (ix)
	ld	b, a
	ld	a, #<(_vector_x)
	ld	hl, #_player_a
	add	a, (hl)
	ld	e, a
	ld	a, #>(_vector_x)
	adc	a, #0x00
	ld	d, a
	ld	a, (de)
	ld	e, a
	rla
	sbc	a, a
	ld	d, a
	ld	l, e
	ld	h, d
	add	hl, hl
	add	hl, de
	add	hl, hl
	ex	de, hl
	ld	hl, (_scroll_v_x)
	add	hl, de
	ex	de, hl
	ld	a, e
	ld	(bc), a
	inc	bc
	ld	a, d
	ld	(bc), a
;os.c:276: projectile_v_y[p] = scroll_v_y + (vector_y[player_a] * player_shot_speed);
	ld	a, #<(_projectile_v_y)
	add	a, -6 (ix)
	ld	c, a
	ld	a, #>(_projectile_v_y)
	adc	a, -5 (ix)
	ld	b, a
	ld	a, #<(_vector_y)
	ld	hl, #_player_a
	add	a, (hl)
	ld	e, a
	ld	a, #>(_vector_y)
	adc	a, #0x00
	ld	d, a
	ld	a, (de)
	ld	e, a
	rla
	sbc	a, a
	ld	d, a
	ld	l, e
	ld	h, d
	add	hl, hl
	add	hl, de
	add	hl, hl
	ex	de, hl
	ld	hl, (_scroll_v_y)
	add	hl, de
	ex	de, hl
	ld	a, e
	ld	(bc), a
	inc	bc
	ld	a, d
	ld	(bc), a
;os.c:277: projectile_timer[p] = projectile_timer_max;
	ld	bc, #_projectile_timer+0
	ld	l, -1 (ix)
	ld	h, #0x00
	add	hl, bc
	ld	(hl), #0x28
;os.c:278: unsigned char s = const_projectile_sprite_first + p;
	ld	a, -1 (ix)
	add	a, #0x08
	ld	c, a
;os.c:279: spr_on[s] = 1;
	ld	hl, #_spr_on
	ld	b, #0x00
	add	hl, bc
	ld	(hl), #0x01
;os.c:280: spr_index[s] = sprite_index_shots_first + player_a;
	ld	hl, #_spr_index
	ld	b, #0x00
	add	hl, bc
	ld	a, 0 (iy)
	ld	(hl), a
;os.c:281: break;
	jr	00140$
00174$:
;os.c:268: for (unsigned char p = 0; p < const_projectile_max; p++)
	inc	-3 (ix)
	ld	a, -3 (ix)
	ld	-1 (ix), a
	jp	00173$
00140$:
;os.c:284: player_shot_timer = player_shot_timer_max;
	ld	hl,#_player_shot_timer + 0
	ld	(hl), #0x06
00145$:
;os.c:288: set_starfield_speed_x(scroll_v_x >> 2);
	ld	hl, (_scroll_v_x)
	sra	h
	rr	l
	sra	h
	rr	l
	push	hl
	call	_set_starfield_speed_x
	pop	af
;os.c:289: set_starfield_speed_y(scroll_v_y >> 2);
	ld	hl, (_scroll_v_y)
	sra	h
	rr	l
	sra	h
	rr	l
	push	hl
	call	_set_starfield_speed_y
	pop	af
;os.c:294: if (player_trail_timer == 0)
	ld	a,(#_player_trail_timer + 0)
	or	a, a
	jr	NZ,00147$
;os.c:296: player_trail_timer = player_trail_freq;
	ld	a,(#_player_trail_freq + 0)
	ld	(#_player_trail_timer + 0),a
;os.c:297: spawn_particle(screen_center_scaled_x + player_trail_offset_x[player_a], screen_center_scaled_y + player_trail_offset_y[player_a]);
	ld	iy, #_player_a
	ld	l, 0 (iy)
	ld	h, #0x00
	add	hl, hl
	ld	c, l
	ld	b, h
	ld	hl, #_player_trail_offset_y
	add	hl, bc
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	ld	iy, #_screen_center_scaled_y
	ld	a, 0 (iy)
	add	a, e
	ld	-4 (ix), a
	ld	a, 1 (iy)
	adc	a, d
	ld	-3 (ix), a
	ld	hl, #_player_trail_offset_x
	add	hl, bc
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	ld	hl, (_screen_center_scaled_x)
	add	hl, bc
	ld	c, -4 (ix)
	ld	b, -3 (ix)
	push	bc
	push	hl
	call	_spawn_particle
	pop	af
	pop	af
	jr	00148$
00147$:
;os.c:301: player_trail_timer--;
	ld	hl, #_player_trail_timer+0
	dec	(hl)
00148$:
;os.c:305: update_particles();
	call	_update_particles
;os.c:311: handle_projectiles();
	call	_handle_projectiles
;os.c:316: if (enemy_active_count < enemy_wanted_count)
	ld	a, -2 (ix)
	sub	a, #0x03
	jp	NC, 00218$
;os.c:318: for (unsigned char e = 0; e < const_enemy_max; e++)
	xor	a, a
	ld	-3 (ix), a
	xor	a, a
	ld	-1 (ix), a
00176$:
	ld	a, -1 (ix)
	sub	a, #0x03
	jp	NC, 00218$
;os.c:320: if (!enemy_on[e])
	ld	bc, #_enemy_on+0
	ld	l, -1 (ix)
	ld	h, #0x00
	add	hl, bc
	bit	0, (hl)
	jp	NZ, 00177$
;os.c:323: unsigned char side = rand_uchar(0, 3);
	push	bc
	ld	a, #0x03
	push	af
	inc	sp
	xor	a, a
	push	af
	inc	sp
	call	_rand_uchar
	pop	af
	ld	a, l
	pop	bc
	ld	e, a
;os.c:324: write_stringf("%d", 15, 5, 3 + e, side);
	ld	a, -3 (ix)
	ld	-1 (ix), a
	add	a, #0x03
	ld	-4 (ix), a
	push	bc
	push	de
	ld	a, e
	push	af
	inc	sp
	ld	d, -4 (ix)
	ld	e,#0x05
	push	de
	ld	a, #0x0f
	push	af
	inc	sp
	ld	hl, #___str_2
	push	hl
	call	_write_stringf
	ld	hl, #6
	add	hl, sp
	ld	sp, hl
	pop	de
	pop	bc
;os.c:329: enemy_y[e] = bounds_y_min + scale;
	ld	l, -3 (ix)
	ld	h, #0x00
	add	hl, hl
	ex	(sp), hl
;os.c:325: switch (side)
	ld	a, e
	or	a, a
	jr	Z,00149$
	ld	a, e
	dec	a
	jr	Z,00150$
	ld	a,e
	cp	a,#0x02
	jr	Z,00151$
	sub	a, #0x04
	jr	Z,00152$
	jp	00153$
;os.c:327: case 0:
00149$:
;os.c:329: enemy_y[e] = bounds_y_min + scale;
	ld	de, #_enemy_y+0
	pop	hl
	push	hl
	add	hl, de
	ld	(hl), #0x50
	inc	hl
	ld	(hl), #0x08
;os.c:330: enemy_x[e] = rand_ushort(bounds_x_min + scale, bounds_x_max - scale);
	ld	de, #_enemy_x+0
	pop	hl
	push	hl
	add	hl, de
	push	hl
	push	bc
	ld	de, #0xb330
	push	de
	ld	de, #0x0850
	push	de
	call	_rand_ushort
	pop	af
	pop	af
	ex	de,hl
	pop	bc
	pop	hl
	ld	(hl), e
	inc	hl
	ld	(hl), d
;os.c:331: break;
	jr	00153$
;os.c:332: case 1:
00150$:
;os.c:334: enemy_y[e] = rand_ushort(bounds_y_min + scale, bounds_y_max - scale);
	ld	de, #_enemy_y+0
	pop	hl
	push	hl
	add	hl, de
	push	hl
	push	bc
	ld	de, #0x8068
	push	de
	ld	de, #0x0850
	push	de
	call	_rand_ushort
	pop	af
	pop	af
	ex	de,hl
	pop	bc
	pop	hl
	ld	(hl), e
	inc	hl
	ld	(hl), d
;os.c:335: enemy_x[e] = bounds_x_max - scale;
	ld	de, #_enemy_x+0
	pop	hl
	push	hl
	add	hl, de
	ld	(hl), #0x30
	inc	hl
	ld	(hl), #0xb3
;os.c:336: break;
	jr	00153$
;os.c:337: case 2:
00151$:
;os.c:339: enemy_y[e] = bounds_y_max - scale;
	ld	de, #_enemy_y+0
	pop	hl
	push	hl
	add	hl, de
	ld	(hl), #0x68
	inc	hl
	ld	(hl), #0x80
;os.c:340: enemy_x[e] = rand_ushort(bounds_x_min + scale, bounds_x_max - scale);
	ld	de, #_enemy_x+0
	pop	hl
	push	hl
	add	hl, de
	push	hl
	push	bc
	ld	de, #0xb330
	push	de
	ld	de, #0x0850
	push	de
	call	_rand_ushort
	pop	af
	pop	af
	ex	de,hl
	pop	bc
	pop	hl
	ld	(hl), e
	inc	hl
	ld	(hl), d
;os.c:341: break;
	jr	00153$
;os.c:342: case 4:
00152$:
;os.c:344: enemy_y[e] = rand_ushort(bounds_y_min + scale, bounds_y_max - scale);
	ld	de, #_enemy_y+0
	pop	hl
	push	hl
	add	hl, de
	push	hl
	push	bc
	ld	de, #0x8068
	push	de
	ld	de, #0x0850
	push	de
	call	_rand_ushort
	pop	af
	pop	af
	ex	de,hl
	pop	bc
	pop	hl
	ld	(hl), e
	inc	hl
	ld	(hl), d
;os.c:345: enemy_x[e] = bounds_x_min + scale;
	ld	de, #_enemy_x+0
	pop	hl
	push	hl
	add	hl, de
	ld	(hl), #0x50
	inc	hl
	ld	(hl), #0x08
;os.c:347: }
00153$:
;os.c:349: enemy_on[e] = true;
	ld	l, -3 (ix)
	ld	h, #0x00
	add	hl, bc
	ld	(hl), #0x01
;os.c:350: enemy_active_count++;
	inc	-2 (ix)
;os.c:352: unsigned char s = const_enemy_sprite_first + e;
	ld	a, -1 (ix)
	add	a, #0x11
	ld	-1 (ix), a
;os.c:353: spr_on[s] = true;
	ld	a, #<(_spr_on)
	add	a, -1 (ix)
	ld	l, a
	ld	a, #>(_spr_on)
	adc	a, #0x00
	ld	h, a
	ld	(hl), #0x01
;os.c:354: set_sprite_position(s, enemy_x[e] / scale, enemy_y[e] / scale);
	ld	bc, #_enemy_y+0
	pop	hl
	push	hl
	add	hl, bc
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	ld	-6 (ix), c
	ld	-5 (ix), b
	srl	-5 (ix)
	rr	-6 (ix)
	srl	-5 (ix)
	rr	-6 (ix)
	srl	-5 (ix)
	rr	-6 (ix)
	srl	-5 (ix)
	rr	-6 (ix)
	srl	-5 (ix)
	rr	-6 (ix)
	srl	-5 (ix)
	rr	-6 (ix)
	srl	-5 (ix)
	rr	-6 (ix)
	ld	a, #<(_enemy_x)
	add	a, -8 (ix)
	ld	-4 (ix), a
	ld	a, #>(_enemy_x)
	adc	a, -7 (ix)
	ld	-3 (ix), a
	ld	l, -4 (ix)
	ld	h, -3 (ix)
	ld	a, (hl)
	ld	-4 (ix), a
	inc	hl
	ld	a, (hl)
	ld	-3 (ix), a
	ld	a, -4 (ix)
	ld	-4 (ix), a
	ld	a, -3 (ix)
	ld	-3 (ix), a
	srl	-3 (ix)
	rr	-4 (ix)
	srl	-3 (ix)
	rr	-4 (ix)
	srl	-3 (ix)
	rr	-4 (ix)
	srl	-3 (ix)
	rr	-4 (ix)
	srl	-3 (ix)
	rr	-4 (ix)
	srl	-3 (ix)
	rr	-4 (ix)
	srl	-3 (ix)
	rr	-4 (ix)
	pop	bc
	pop	hl
	push	hl
	push	bc
	push	hl
	ld	l, -4 (ix)
	ld	h, -3 (ix)
	push	hl
	ld	a, -1 (ix)
	push	af
	inc	sp
	call	_set_sprite_position
	pop	af
	pop	af
	inc	sp
;os.c:356: break;
	jr	00218$
00177$:
;os.c:318: for (unsigned char e = 0; e < const_enemy_max; e++)
	inc	-1 (ix)
	ld	a, -1 (ix)
	ld	-3 (ix), a
	jp	00176$
;os.c:361: for (unsigned char e = 0; e < const_enemy_max; e++)
00218$:
	xor	a, a
	ld	-1 (ix), a
00179$:
	ld	a, -1 (ix)
	sub	a, #0x03
	jp	NC, 00159$
;os.c:363: unsigned char s = const_enemy_sprite_first + e;
	ld	a, -1 (ix)
	ld	-3 (ix), a
	add	a, #0x11
	ld	-7 (ix), a
;os.c:364: enemy_x[e] = (enemy_x[e] - scroll_v_x);
	ld	a, -1 (ix)
	ld	-4 (ix), a
	xor	a, a
	ld	-3 (ix), a
	ld	a, -4 (ix)
	ld	-6 (ix), a
	ld	a, -3 (ix)
	ld	-5 (ix), a
	sla	-6 (ix)
	rl	-5 (ix)
	ld	a, #<(_enemy_x)
	add	a, -6 (ix)
	ld	-4 (ix), a
	ld	a, #>(_enemy_x)
	adc	a, -5 (ix)
	ld	-3 (ix), a
	ld	l, -4 (ix)
	ld	h, -3 (ix)
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	ld	hl, (_scroll_v_x)
	ld	a, c
	sub	a, l
	ld	c, a
	ld	a, b
	sbc	a, h
	ld	b, a
	ld	l, -4 (ix)
	ld	h, -3 (ix)
	ld	(hl), c
	inc	hl
	ld	(hl), b
;os.c:365: enemy_y[e] = (enemy_y[e] - scroll_v_y);
	ld	a, #<(_enemy_y)
	add	a, -6 (ix)
	ld	-4 (ix), a
	ld	a, #>(_enemy_y)
	adc	a, -5 (ix)
	ld	-3 (ix), a
	ld	l, -4 (ix)
	ld	h, -3 (ix)
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	ld	hl, (_scroll_v_y)
	ld	a, e
	sub	a, l
	ld	e, a
	ld	a, d
	sbc	a, h
	ld	d, a
	ld	l, -4 (ix)
	ld	h, -3 (ix)
	ld	(hl), e
	inc	hl
	ld	(hl), d
;os.c:366: set_sprite_position(s, enemy_x[e] / scale, enemy_y[e] / scale);
	srl	d
	rr	e
	srl	d
	rr	e
	srl	d
	rr	e
	srl	d
	rr	e
	srl	d
	rr	e
	srl	d
	rr	e
	srl	d
	rr	e
	srl	b
	rr	c
	srl	b
	rr	c
	srl	b
	rr	c
	srl	b
	rr	c
	srl	b
	rr	c
	srl	b
	rr	c
	srl	b
	rr	c
	push	de
	push	bc
	ld	a, -7 (ix)
	push	af
	inc	sp
	call	_set_sprite_position
	pop	af
	pop	af
	inc	sp
;os.c:372: if (spritecollisionram[s])
	ld	bc, #_spritecollisionram+0
	ld	l, -7 (ix)
	ld	h, #0x00
	add	hl, bc
	ld	a,(hl)
;os.c:361: for (unsigned char e = 0; e < const_enemy_max; e++)
	inc	-1 (ix)
	jp	00179$
00159$:
;os.c:388: unsigned short l = (GET_TIMER);
	ld	a, (#(_timer + 0x0001) + 0)
	ld	b, a
	ld	c, #0x00
	ld	a, (#_timer + 0)
	ld	e, a
	ld	d, #0x00
	ld	a, c
	or	a, e
	ld	c, a
	ld	a, b
	or	a, d
	ld	b, a
;os.c:389: write_stringf_ushort("%6d", 15, 0, 0, l);
	push	bc
	xor	a, a
	push	af
	inc	sp
	xor	a, a
	ld	d,a
	ld	e,#0x0f
	push	de
	ld	hl, #___str_3
	push	hl
	call	_write_stringf_ushort
	ld	hl, #7
	add	hl, sp
	ld	sp, hl
00161$:
;os.c:391: vblank_last = vblank;
	ld	a,(#_vblank + 0)
	ld	iy, #_vblank_last
	ld	0 (iy), a
;os.c:393: }
	jp	00164$
___str_0:
	.ascii "CALCULATING VECTORS"
	.db 0x00
___str_1:
	.ascii "Score might be here, or some other stuff"
	.db 0x00
___str_2:
	.ascii "%d"
	.db 0x00
___str_3:
	.ascii "%6d"
	.db 0x00
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
__xinit__input_a_last:
	.db #0x00	;  0
__xinit__screen_center_scaled_x:
	.dw #0x5600
__xinit__screen_center_scaled_y:
	.dw #0x4600
__xinit__player_trail_freq:
	.db #0x04	; 4
__xinit__vector_x:
	.db #0x00	;  0
	.db #0x31	;  49	'1'
	.db #0x5a	;  90	'Z'
	.db #0x75	;  117	'u'
	.db #0x7f	;  127
	.db #0x75	;  117	'u'
	.db #0x5a	;  90	'Z'
	.db #0x31	;  49	'1'
	.db #0x00	;  0
	.db #0xcf	; -49
	.db #0xa6	; -90
	.db #0x8b	; -117
	.db #0x81	; -127
	.db #0x8b	; -117
	.db #0xa6	; -90
	.db #0xcf	; -49
__xinit__vector_y:
	.db #0x81	; -127
	.db #0x8b	; -117
	.db #0xa6	; -90
	.db #0xcf	; -49
	.db #0x00	;  0
	.db #0x31	;  49	'1'
	.db #0x5a	;  90	'Z'
	.db #0x75	;  117	'u'
	.db #0x7f	;  127
	.db #0x75	;  117	'u'
	.db #0x5a	;  90	'Z'
	.db #0x31	;  49	'1'
	.db #0x00	;  0
	.db #0xcf	; -49
	.db #0xa6	; -90
	.db #0x8b	; -117
	.area _CABS (ABS)
