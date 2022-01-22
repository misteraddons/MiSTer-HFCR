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
	.globl _kill_projectile
	.globl _basic_input
	.globl _sqrtf
	.globl _set_starfield_speed_y
	.globl _set_starfield_speed_x
	.globl _enable_starfield
	.globl _enable_sprite
	.globl _update_sprites
	.globl _set_sprite_position
	.globl _write_char
	.globl _write_stringf_ushort
	.globl _write_string
	.globl _clear_bgcolor
	.globl _clear_char_area
	.globl _vector_y
	.globl _vector_x
	.globl _player_trail_freq
	.globl _player_turn_timer_max
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
	.globl _test_y
	.globl _test_x
	.globl _projectile_v_y
	.globl _projectile_v_x
	.globl _projectile_y
	.globl _projectile_x
	.globl _projectile_timer
	.globl _projectile_on
	.globl _particle_v_y
	.globl _particle_v_x
	.globl _particle_y
	.globl _particle_x
	.globl _particle_timer
	.globl _particle_on
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
	.globl _player_turn_timer
	.globl _player_a
	.globl _player_a_acc
	.globl _player_v_y
	.globl _player_v_x
	.globl _input_a
	.globl _musicram
	.globl _sndram
	.globl _tilemapram
	.globl _tilemapctl
	.globl _spritecollisionram
	.globl _spriteram
	.globl _bgcolram
	.globl _fgcolram
	.globl _chram
	.globl _system_menu
	.globl _system_pause
	.globl _starfield3
	.globl _starfield2
	.globl _starfield1
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
_starfield1	=	0x8a00
_starfield2	=	0x8a10
_starfield3	=	0x8a20
_system_pause	=	0x8a30
_system_menu	=	0x8a31
_chram	=	0x9800
_fgcolram	=	0xa000
_bgcolram	=	0xa800
_spriteram	=	0xb000
_spritecollisionram	=	0xb400
_tilemapctl	=	0x8c00
_tilemapram	=	0x8c10
_sndram	=	0x8b00
_musicram	=	0x8b10
_input_a::
	.ds 1
_player_v_x::
	.ds 2
_player_v_y::
	.ds 2
_player_a_acc::
	.ds 1
_player_a::
	.ds 1
_player_turn_timer::
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
_particle_on::
	.ds 12
_particle_timer::
	.ds 12
_particle_x::
	.ds 24
_particle_y::
	.ds 24
_particle_v_x::
	.ds 24
_particle_v_y::
	.ds 24
_projectile_on::
	.ds 8
_projectile_timer::
	.ds 8
_projectile_x::
	.ds 16
_projectile_y::
	.ds 16
_projectile_v_x::
	.ds 16
_projectile_v_y::
	.ds 16
_test_x::
	.ds 2
_test_y::
	.ds 2
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
_player_turn_timer_max::
	.ds 1
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
;os.c:45: void basic_input()
;	---------------------------------
; Function basic_input
; ---------------------------------
_basic_input::
;os.c:47: input_up_last = input_up;
	ld	a,(#_input_up + 0)
	ld	iy, #_input_up_last
	ld	0 (iy), a
;os.c:48: input_down_last = input_down;
	ld	a,(#_input_down + 0)
	ld	iy, #_input_down_last
	ld	0 (iy), a
;os.c:49: input_left_last = input_left;
	ld	a,(#_input_left + 0)
	ld	iy, #_input_left_last
	ld	0 (iy), a
;os.c:50: input_right_last = input_right;
	ld	a,(#_input_right + 0)
	ld	iy, #_input_right_last
	ld	0 (iy), a
;os.c:51: input_a_last = input_a;
	ld	a,(#_input_a + 0)
	ld	iy, #_input_a_last
	ld	0 (iy), a
;os.c:52: input_up = CHECK_BIT(joystick[0], 3);
	ld	a, (#_joystick + 0)
	and	a, #0x08
	ld	c, a
	xor	a, a
	cp	a, c
	rla
	ld	(_input_up+0), a
;os.c:53: input_down = CHECK_BIT(joystick[0], 2);
	ld	a, (#_joystick + 0)
	and	a, #0x04
	ld	c, a
	xor	a, a
	cp	a, c
	rla
	ld	(_input_down+0), a
;os.c:54: input_left = CHECK_BIT(joystick[0], 1);
	ld	a, (#_joystick + 0)
	and	a, #0x02
	ld	c, a
	xor	a, a
	cp	a, c
	rla
	ld	(_input_left+0), a
;os.c:55: input_right = CHECK_BIT(joystick[0], 0);
	ld	a, (#_joystick + 0)
	and	a, #0x01
	ld	(_input_right+0), a
;os.c:56: input_a = CHECK_BIT(joystick[0], 4);
	ld	a, (#_joystick + 0)
	and	a, #0x10
	ld	c, a
	xor	a, a
	cp	a, c
	rla
	ld	(_input_a+0), a
;os.c:57: }
	ret
;os.c:127: void kill_projectile(unsigned char p)
;	---------------------------------
; Function kill_projectile
; ---------------------------------
_kill_projectile::
	push	ix
	ld	ix,#0
	add	ix,sp
;os.c:129: spr_on[const_projectile_sprite_first + p] = 0;
	ld	bc, #_spr_on+0
	ld	e, 4 (ix)
	ld	d, #0x00
	ld	hl, #0x000d
	add	hl, de
	add	hl, bc
	ld	(hl), #0x00
;os.c:130: projectile_on[p] = 0;
	ld	bc, #_projectile_on+0
	ld	l, 4 (ix)
	ld	h, #0x00
	add	hl, bc
	ld	(hl), #0x00
;os.c:131: }
	pop	ix
	ret
;os.c:134: void main()
;	---------------------------------
; Function main
; ---------------------------------
_main::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	hl, #-13
	add	hl, sp
	ld	sp, hl
;os.c:137: chram_size = chram_cols * chram_rows;
	ld	hl,#_chram_rows + 0
	ld	e, (hl)
	ld	hl,#_chram_cols + 0
	ld	h, (hl)
	ld	l, #0x00
	ld	d, l
	ld	b, #0x08
00443$:
	add	hl, hl
	jr	NC,00444$
	add	hl, de
00444$:
	djnz	00443$
	ld	(_chram_size), hl
;os.c:138: clear_bgcolor(0);
	xor	a, a
	push	af
	inc	sp
	call	_clear_bgcolor
	inc	sp
;os.c:140: write_string("CALCULATING VECTORS", 0xFF, 0, 0);
	xor	a, a
	push	af
	inc	sp
	xor	a, a
	ld	d,a
	ld	e,#0xff
	push	de
	ld	hl, #___str_0
	push	hl
	call	_write_string
	pop	af
	pop	af
	inc	sp
;os.c:143: for (unsigned char v = 0; v < direction_count; v++)
	xor	a, a
	ld	-1 (ix), a
00182$:
	ld	a, -1 (ix)
	sub	a, #0x10
	jp	NC, 00101$
;os.c:146: player_thrust_x[v] = (vector_x[v] * player_thrust_mag) / 100;
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
;os.c:147: player_thrust_y[v] = (vector_y[v] * player_thrust_mag) / 100;
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
;os.c:148: player_thrust_rev_x[v] = (vector_x[v] * player_thrust_rev_mag) / 100;
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
;os.c:149: player_thrust_rev_y[v] = (vector_y[v] * player_thrust_rev_mag) / 100;
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
;os.c:152: player_trail_offset_x[v] = (vector_x[v]) * -8;
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
;os.c:153: player_trail_offset_y[v] = (vector_y[v]) * -8;
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
;os.c:156: player_shot_offset_x[v] = (vector_x[v]) * 11;
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
;os.c:157: player_shot_offset_y[v] = (vector_y[v]) * 11;
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
;os.c:143: for (unsigned char v = 0; v < direction_count; v++)
	inc	-1 (ix)
	jp	00182$
00101$:
;os.c:159: clear_char_area(0, 0, 0, 40, 0);
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
;os.c:162: enable_sprite(player_sprite, sprite_palette_player, sprite_size_player, 1);
	ld	de, #0x0101
	push	de
	xor	a, a
	push	af
	inc	sp
	xor	a, a
	push	af
	inc	sp
	call	_enable_sprite
	pop	af
	pop	af
;os.c:164: set_sprite_position(player_sprite, screen_center_x - sprite_halfpixelsize_player, screen_center_y - sprite_halfpixelsize_player);
	ld	hl, #0x0088
	push	hl
	ld	l, #0xa8
	push	hl
	xor	a, a
	push	af
	inc	sp
	call	_set_sprite_position
	pop	af
	pop	af
	inc	sp
;os.c:167: enable_starfield();
	call	_enable_starfield
;os.c:170: for (unsigned char p = 0; p < const_particle_max; p++)
	ld	c, #0x00
00185$:
	ld	a, c
	sub	a, #0x0c
	jr	NC,00102$
;os.c:172: unsigned char s = p + const_particle_sprite_first;
	ld	b, c
	inc	b
;os.c:173: enable_sprite(s, sprite_palette_trails, sprite_size_trails, 0);
	push	bc
	xor	a, a
	ld	d,a
	ld	e,#0x02
	push	de
	xor	a, a
	push	af
	inc	sp
	push	bc
	inc	sp
	call	_enable_sprite
	pop	af
	pop	af
	pop	bc
;os.c:174: spr_on[s] = 0;
	ld	a, #<(_spr_on)
	add	a, b
	ld	e, a
	ld	a, #>(_spr_on)
	adc	a, #0x00
	ld	d, a
	xor	a, a
	ld	(de), a
;os.c:170: for (unsigned char p = 0; p < const_particle_max; p++)
	inc	c
	jr	00185$
00102$:
;os.c:177: for (unsigned char p = 0; p < const_projectile_max; p++)
	ld	c, #0x00
00188$:
;os.c:179: unsigned char s = p + const_projectile_sprite_first;
	ld	a,c
	cp	a,#0x08
	jr	NC,00103$
	add	a, #0x0d
	ld	b, a
;os.c:180: enable_sprite(s, sprite_palette_shots, sprite_size_shots, 1);
	push	bc
	ld	de, #0x0102
	push	de
	xor	a, a
	push	af
	inc	sp
	push	bc
	inc	sp
	call	_enable_sprite
	pop	af
	pop	af
	pop	bc
;os.c:181: spr_on[s] = 0;
	ld	a, #<(_spr_on)
	add	a, b
	ld	e, a
	ld	a, #>(_spr_on)
	adc	a, #0x00
	ld	d, a
	xor	a, a
	ld	(de), a
;os.c:177: for (unsigned char p = 0; p < const_projectile_max; p++)
	inc	c
	jr	00188$
00103$:
;os.c:184: enable_sprite(31, sprite_palette_player, sprite_size_player, 1);
	ld	de, #0x0101
	push	de
	xor	a, a
	ld	d,a
	ld	e,#0x1f
	push	de
	call	_enable_sprite
	pop	af
	pop	af
;os.c:185: spr_index[31] = sprite_index_player_first;
	ld	hl, #(_spr_index + 0x001f)
	ld	(hl), #0x08
;os.c:186: test_x = (screen_center_x - sprite_halfpixelsize_player + 64) * scale;
	ld	hl, #0x7400
	ld	(_test_x), hl
;os.c:187: test_y = (screen_center_y - sprite_halfpixelsize_player + 64) * scale;
	ld	h, #0x64
	ld	(_test_y), hl
;os.c:189: while (1)
00179$:
;os.c:191: vblank = CHECK_BIT(input0, INPUT_VBLANK);
	ld	a,(#_input0 + 0)
	and	a, #0x10
	ld	c, a
	xor	a, a
	cp	a, c
	rla
	ld	(_vblank+0), a
;os.c:193: if (VBLANK_RISING)
	ld	iy, #_vblank
	bit	0, 0 (iy)
	jr	Z,00105$
	ld	iy, #_vblank_last
	bit	0, 0 (iy)
	jr	NZ,00105$
;os.c:195: update_sprites();
	call	_update_sprites
00105$:
;os.c:197: if (VBLANK_FALLING)
	ld	iy, #_vblank
	bit	0, 0 (iy)
	jp	NZ, 00176$
	ld	iy, #_vblank_last
	bit	0, 0 (iy)
	jp	Z, 00176$
;os.c:199: basic_input();
	call	_basic_input
;os.c:201: unsigned short t = GET_TIMER;
	ld	a,(#(_timer + 0x0001) + 0)
	ld	-1 (ix), a
	ld	-2 (ix), a
	xor	a, a
	ld	-1 (ix), a
	ld	a, -2 (ix)
	ld	-5 (ix), a
	ld	-6 (ix), #0x00
	ld	a,(#_timer + 0)
	ld	-1 (ix), a
	ld	-4 (ix), a
	xor	a, a
	ld	-3 (ix), a
	ld	a, -6 (ix)
	or	a, -4 (ix)
	ld	-2 (ix), a
	ld	a, -5 (ix)
	or	a, -3 (ix)
	ld	-1 (ix), a
	ld	a, -2 (ix)
	ld	-11 (ix), a
	ld	a, -1 (ix)
	ld	-10 (ix), a
;os.c:225: unsigned char target_a_acc = player_a_acc;
	ld	a,(#_player_a_acc + 0)
	ld	-1 (ix), a
;os.c:226: if (input_left)
	ld	hl,#_input_left+0
	bit	0, (hl)
	jr	Z,00128$
;os.c:228: if (input_up)
	ld	hl,#_input_up+0
	bit	0, (hl)
	jr	Z,00111$
;os.c:230: target_a_acc = 231;
	ld	-1 (ix), #0xe7
	jr	00129$
00111$:
;os.c:232: else if (input_down)
	ld	hl,#_input_down+0
	bit	0, (hl)
	jr	Z,00108$
;os.c:234: target_a_acc = 167;
	ld	-1 (ix), #0xa7
	jr	00129$
00108$:
;os.c:238: target_a_acc = 200;
	ld	-1 (ix), #0xc8
	jr	00129$
00128$:
;os.c:241: else if (input_right)
	ld	hl,#_input_right+0
	bit	0, (hl)
	jr	Z,00125$
;os.c:243: if (input_up)
	ld	hl,#_input_up+0
	bit	0, (hl)
	jr	Z,00117$
;os.c:245: target_a_acc = 40;
	ld	-1 (ix), #0x28
	jr	00129$
00117$:
;os.c:247: else if (input_down)
	ld	hl,#_input_down+0
	bit	0, (hl)
	jr	Z,00114$
;os.c:249: target_a_acc = 104;
	ld	-1 (ix), #0x68
	jr	00129$
00114$:
;os.c:253: target_a_acc = 72;
	ld	-1 (ix), #0x48
	jr	00129$
00125$:
;os.c:258: if (input_up)
	ld	hl,#_input_up+0
	bit	0, (hl)
	jr	Z,00122$
;os.c:260: target_a_acc = 8;
	ld	-1 (ix), #0x08
	jr	00129$
00122$:
;os.c:262: else if (input_down)
	ld	hl,#_input_down+0
	bit	0, (hl)
	jr	Z,00129$
;os.c:264: target_a_acc = 136;
	ld	-1 (ix), #0x88
00129$:
;os.c:270: if (target_a_acc != player_a_acc)
	ld	a,(#_player_a_acc + 0)
	sub	a, -1 (ix)
	jr	Z,00138$
;os.c:272: unsigned char diff = target_a_acc - player_a_acc;
	ld	hl, #_player_a_acc
	ld	a, -1 (ix)
	sub	a, (hl)
	ld	-1 (ix), a
;os.c:274: if (diff > 127)
	ld	a, #0x7f
	sub	a, -1 (ix)
	jr	NC,00135$
;os.c:276: diff = 255 - (diff - 1);
	ld	c, -1 (ix)
	dec	c
	ld	a, #0xff
	sub	a, c
	ld	c, a
;os.c:277: if (diff > 4)
	ld	a, #0x04
	sub	a, c
	jr	NC,00131$
;os.c:279: diff = 4;
	ld	c, #0x04
00131$:
;os.c:282: player_a_acc -= diff;
	ld	hl, #_player_a_acc
	ld	a, (hl)
	sub	a, c
	ld	(hl), a
	jr	00138$
00135$:
;os.c:286: if (diff > 4)
	ld	a, #0x04
	sub	a, -1 (ix)
	jr	NC,00133$
;os.c:288: diff = 4;
	ld	-1 (ix), #0x04
00133$:
;os.c:291: player_a_acc += diff;
	ld	hl, #_player_a_acc
	ld	a, (hl)
	add	a, -1 (ix)
	ld	(hl), a
00138$:
;os.c:295: player_a = player_a_acc / 16;
	ld	hl,#_player_a_acc + 0
	ld	c, (hl)
	ld	b, #0x00
	ld	l, c
	ld	h, b
	bit	7, b
	jr	Z,00205$
	ld	hl, #0x000f
	add	hl, bc
00205$:
	sra	h
	rr	l
	sra	h
	rr	l
	sra	h
	rr	l
	sra	h
	rr	l
	ld	iy, #_player_a
	ld	0 (iy), l
;os.c:298: spr_index[player_sprite] = sprite_index_player_first + player_a;
	ld	a, 0 (iy)
	add	a, #0x08
	ld	(#_spr_index),a
;os.c:300: player_v_x += player_thrust_x[player_a];
	ld	l, 0 (iy)
	ld	h, #0x00
	add	hl, hl
	ld	c, l
	ld	b, h
	ld	hl, #_player_thrust_x
	add	hl, bc
	ld	-2 (ix), l
	ld	-1 (ix), h
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	ld	hl, #_player_v_x
	ld	a, (hl)
	add	a, e
	ld	(hl), a
	inc	hl
	ld	a, (hl)
	adc	a, d
	ld	(hl), a
;os.c:301: player_v_y += player_thrust_y[player_a];
	ld	hl, #_player_thrust_y
	add	hl, bc
	ex	de, hl
	ld	l, e
	ld	h, d
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	ld	hl, #_player_v_y
	ld	a, (hl)
	add	a, c
	ld	(hl), a
	inc	hl
	ld	a, (hl)
	adc	a, b
	ld	(hl), a
;os.c:304: player_v_x += player_thrust_x[player_a];
	ld	l, -2 (ix)
	ld	h, -1 (ix)
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	ld	hl, #_player_v_x
	ld	a, (hl)
	add	a, c
	ld	(hl), a
	inc	hl
	ld	a, (hl)
	adc	a, b
	ld	(hl), a
;os.c:305: player_v_y += player_thrust_y[player_a];
	ex	de,hl
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	ld	hl, #_player_v_y
	ld	a, (hl)
	add	a, c
	ld	(hl), a
	inc	hl
	ld	a, (hl)
	adc	a, b
	ld	(hl), a
;os.c:310: player_v_x = (signed short)(((signed long)player_v_x * player_v_friction) / 100);
	ld	hl,#_player_v_x
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
	ld	iy, #_player_v_x
	ld	0 (iy), l
	ld	1 (iy), h
;os.c:311: player_v_y = (signed short)(((signed long)player_v_y * player_v_friction) / 100);
	ld	hl,#_player_v_y
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
	ld	iy, #_player_v_y
	ld	0 (iy), l
	ld	1 (iy), h
;os.c:329: if (player_shot_timer > 0)
	ld	iy, #_player_shot_timer
	ld	a, 0 (iy)
	or	a, a
	jr	Z,00145$
;os.c:331: player_shot_timer--;
	dec	0 (iy)
	jp	00146$
00145$:
;os.c:335: if (input_a)
	ld	hl,#_input_a+0
	bit	0, (hl)
	jp	Z, 00146$
;os.c:337: for (unsigned char p = 0; p < const_projectile_max; p++)
	xor	a, a
	ld	-5 (ix), a
	xor	a, a
	ld	-1 (ix), a
00191$:
	ld	a, -1 (ix)
	sub	a, #0x08
	jp	NC, 00141$
;os.c:339: if (!projectile_on[p])
	ld	a, #<(_projectile_on)
	add	a, -1 (ix)
	ld	-3 (ix), a
	ld	a, #>(_projectile_on)
	adc	a, #0x00
	ld	-2 (ix), a
	ld	l, -3 (ix)
	ld	h, -2 (ix)
	bit	0, (hl)
	jp	NZ, 00192$
;os.c:341: projectile_on[p] = true;
	ld	l, -3 (ix)
	ld	h, -2 (ix)
	ld	(hl), #0x01
;os.c:342: projectile_x[p] = (screen_center_scaled_x + player_shot_offset_x[player_a]) + scale_half;
	ld	l, -5 (ix)
	ld	h, #0x00
	add	hl, hl
	ld	-4 (ix), l
	ld	-3 (ix), h
	ld	a, #<(_projectile_x)
	add	a, -4 (ix)
	ld	-2 (ix), a
	ld	a, #>(_projectile_x)
	adc	a, -3 (ix)
	ld	-1 (ix), a
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
	ld	l, -2 (ix)
	ld	h, -1 (ix)
	ld	(hl), c
	inc	hl
	ld	(hl), b
;os.c:343: projectile_y[p] = (screen_center_scaled_y + player_shot_offset_y[player_a]) + scale_half;
	ld	a, #<(_projectile_y)
	add	a, -4 (ix)
	ld	-2 (ix), a
	ld	a, #>(_projectile_y)
	adc	a, -3 (ix)
	ld	-1 (ix), a
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
	ld	l, -2 (ix)
	ld	h, -1 (ix)
	ld	(hl), c
	inc	hl
	ld	(hl), b
;os.c:344: projectile_v_x[p] = player_v_x + (vector_x[player_a] * player_shot_speed);
	ld	a, #<(_projectile_v_x)
	add	a, -4 (ix)
	ld	c, a
	ld	a, #>(_projectile_v_x)
	adc	a, -3 (ix)
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
	ld	hl, (_player_v_x)
	add	hl, de
	ex	de, hl
	ld	a, e
	ld	(bc), a
	inc	bc
	ld	a, d
	ld	(bc), a
;os.c:345: projectile_v_y[p] = player_v_y + (vector_y[player_a] * player_shot_speed);
	ld	a, #<(_projectile_v_y)
	add	a, -4 (ix)
	ld	c, a
	ld	a, #>(_projectile_v_y)
	adc	a, -3 (ix)
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
	ld	hl, (_player_v_y)
	add	hl, de
	ex	de, hl
	ld	a, e
	ld	(bc), a
	inc	bc
	ld	a, d
	ld	(bc), a
;os.c:346: projectile_timer[p] = projectile_timer_max;
	ld	bc, #_projectile_timer+0
	ld	l, -5 (ix)
	ld	h, #0x00
	add	hl, bc
	ld	(hl), #0x28
;os.c:347: unsigned char s = const_projectile_sprite_first + p;
	ld	a, -5 (ix)
	add	a, #0x0d
	ld	c, a
;os.c:348: spr_on[s] = 1;
	ld	hl, #_spr_on
	ld	b, #0x00
	add	hl, bc
	ld	(hl), #0x01
;os.c:349: spr_index[s] = sprite_index_shots_first + player_a;
	ld	hl, #_spr_index
	ld	b, #0x00
	add	hl, bc
	ld	a, 0 (iy)
	ld	(hl), a
;os.c:350: break;
	jr	00141$
00192$:
;os.c:337: for (unsigned char p = 0; p < const_projectile_max; p++)
	inc	-1 (ix)
	ld	a, -1 (ix)
	ld	-5 (ix), a
	jp	00191$
00141$:
;os.c:353: player_shot_timer = player_shot_timer_max;
	ld	hl,#_player_shot_timer + 0
	ld	(hl), #0x06
00146$:
;os.c:357: float player_speed = sqrtf((player_v_x * player_v_x) + (player_v_y * player_v_y));
	ld	hl, (_player_v_x)
	push	hl
	ld	hl, (_player_v_x)
	push	hl
	call	__mulint
	pop	af
	ex	(sp),hl
	ld	hl, (_player_v_y)
	push	hl
	ld	hl, (_player_v_y)
	push	hl
	call	__mulint
	pop	af
	pop	af
	pop	bc
	add	hl, bc
	push	hl
	call	___sint2fs
	pop	af
	push	de
	push	hl
	call	_sqrtf
	pop	af
	pop	af
;os.c:360: set_starfield_speed_x(player_v_x >> 2);
	ld	hl, (_player_v_x)
	sra	h
	rr	l
	sra	h
	rr	l
	push	hl
	call	_set_starfield_speed_x
	pop	af
;os.c:361: set_starfield_speed_y(player_v_y >> 2);
	ld	hl, (_player_v_y)
	sra	h
	rr	l
	sra	h
	rr	l
	push	hl
	call	_set_starfield_speed_y
	pop	af
;os.c:364: if (player_trail_timer == 0)
	ld	a,(#_player_trail_timer + 0)
	or	a, a
	jp	NZ, 00153$
;os.c:368: player_trail_timer = player_trail_freq;
	ld	a,(#_player_trail_freq + 0)
	ld	(#_player_trail_timer + 0),a
;os.c:370: for (unsigned char pt = 0; pt < const_particle_max; pt++)
	xor	a, a
	ld	-3 (ix), a
	ld	c, #0x00
00194$:
	ld	a, c
	sub	a, #0x0c
	jp	NC, 00243$
;os.c:372: if (!particle_on[pt])
	ld	de, #_particle_on+0
	ld	l, c
	ld	h, #0x00
	add	hl, de
	bit	0, (hl)
	jp	NZ, 00195$
;os.c:374: particle_on[pt] = true;
	ld	(hl), #0x01
;os.c:375: particle_x[pt] = screen_center_scaled_x + player_trail_offset_x[player_a];
	ld	l, -3 (ix)
	ld	h, #0x00
	add	hl, hl
	ld	c, l
	ld	b, h
	ld	hl, #_particle_x
	add	hl, bc
	ld	-2 (ix), l
	ld	-1 (ix), h
	ld	iy, #_player_a
	ld	l, 0 (iy)
	ld	h, #0x00
	add	hl, hl
	ld	de, #_player_trail_offset_x
	add	hl, de
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	ld	iy, #_screen_center_scaled_x
	ld	a, 0 (iy)
	add	a, e
	ld	e, a
	ld	a, 1 (iy)
	adc	a, d
	ld	d, a
	ld	l, -2 (ix)
	ld	h, -1 (ix)
	ld	(hl), e
	inc	hl
	ld	(hl), d
;os.c:376: particle_y[pt] = screen_center_scaled_y + player_trail_offset_y[player_a];
	ld	hl, #_particle_y+0
	add	hl, bc
	ex	de, hl
	ld	iy, #_player_a
	ld	l, 0 (iy)
	ld	h, #0x00
	add	hl, hl
	ld	bc, #_player_trail_offset_y
	add	hl, bc
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	ld	iy, #_screen_center_scaled_y
	ld	a, 0 (iy)
	add	a, c
	ld	c, a
	ld	a, 1 (iy)
	adc	a, b
	ld	b, a
	ld	a, c
	ld	(de), a
	inc	de
	ld	a, b
	ld	(de), a
;os.c:379: particle_timer[pt] = particle_timer_max;
	ld	bc, #_particle_timer+0
	ld	l, -3 (ix)
	ld	h, #0x00
	add	hl, bc
	ld	(hl), #0x04
;os.c:380: unsigned char ps = const_particle_sprite_first + pt;
	ld	c, -3 (ix)
	inc	c
;os.c:381: spr_on[ps] = 1;
	ld	hl, #_spr_on
	ld	b, #0x00
	add	hl, bc
	ld	(hl), #0x01
;os.c:382: spr_index[ps] = sprite_index_trails_first;
	ld	hl, #_spr_index
	ld	b, #0x00
	add	hl, bc
	ld	(hl), #0x10
;os.c:383: break;
	jr	00243$
00195$:
;os.c:370: for (unsigned char pt = 0; pt < const_particle_max; pt++)
	inc	c
	ld	-3 (ix), c
	jp	00194$
00153$:
;os.c:390: player_trail_timer--;
	ld	hl, #_player_trail_timer+0
	dec	(hl)
;os.c:394: for (unsigned char p = 0; p < const_particle_max; p++)
00243$:
	ld	c, #0x00
00197$:
	ld	a, c
	sub	a, #0x0c
	jp	NC, 00163$
;os.c:396: if (particle_on[p])
	ld	a, #<(_particle_on)
	add	a, c
	ld	-4 (ix), a
	ld	a, #>(_particle_on)
	adc	a, #0x00
	ld	-3 (ix), a
	ld	l, -4 (ix)
	ld	h, -3 (ix)
	bit	0, (hl)
	jp	Z, 00162$
;os.c:398: unsigned char s = const_particle_sprite_first + p;
	ld	b, c
	inc	b
;os.c:399: particle_timer[p]--;
	ld	a, #<(_particle_timer)
	add	a, c
	ld	-2 (ix), a
	ld	a, #>(_particle_timer)
	adc	a, #0x00
	ld	-1 (ix), a
	ld	l, -2 (ix)
	ld	h, -1 (ix)
	ld	a, (hl)
	dec	a
	ld	l, -2 (ix)
	ld	h, -1 (ix)
	ld	(hl), a
;os.c:400: if (particle_timer[p] == 0)
	or	a, a
	jr	NZ,00159$
;os.c:402: if (spr_index[s] == sprite_index_trails_last)
	ld	a, #<(_spr_index)
	add	a, b
	ld	e, a
	ld	a, #>(_spr_index)
	adc	a, #0x00
	ld	d, a
	ld	a, (de)
	sub	a, #0x13
	jr	NZ,00156$
;os.c:404: spr_on[s] = 0;
	ld	a, #<(_spr_on)
	add	a, b
	ld	e, a
	ld	a, #>(_spr_on)
	adc	a, #0x00
	ld	d, a
	xor	a, a
	ld	(de), a
;os.c:405: particle_on[p] = 0;
	ld	l, -4 (ix)
	ld	h, -3 (ix)
	ld	(hl), #0x00
;os.c:406: continue;
	jp	00162$
00156$:
;os.c:410: particle_timer[p] = particle_timer_max;
	ld	l, -2 (ix)
	ld	h, -1 (ix)
	ld	(hl), #0x04
;os.c:411: spr_index[s]++;
	ld	a, (de)
	inc	a
	ld	(de), a
00159$:
;os.c:414: set_sprite_position(s, particle_x[p] / scale, particle_y[p] / scale);
	ld	l, c
	ld	h, #0x00
	add	hl, hl
	ex	(sp), hl
	ld	a, #<(_particle_y)
	add	a, -13 (ix)
	ld	-8 (ix), a
	ld	a, #>(_particle_y)
	adc	a, -12 (ix)
	ld	-7 (ix), a
	ld	l, -8 (ix)
	ld	h, -7 (ix)
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
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
	ld	a, #<(_particle_x)
	add	a, -13 (ix)
	ld	-6 (ix), a
	ld	a, #>(_particle_x)
	adc	a, -12 (ix)
	ld	-5 (ix), a
	ld	l, -6 (ix)
	ld	h, -5 (ix)
	ld	a, (hl)
	inc	hl
	ld	h, (hl)
	ld	l, a
	srl	h
	rr	l
	srl	h
	rr	l
	srl	h
	rr	l
	srl	h
	rr	l
	srl	h
	rr	l
	srl	h
	rr	l
	srl	h
	rr	l
	push	bc
	push	de
	push	hl
	push	bc
	inc	sp
	call	_set_sprite_position
	pop	af
	pop	af
	inc	sp
	pop	bc
;os.c:415: particle_x[p] -= player_v_x;
	ld	l, -6 (ix)
	ld	h, -5 (ix)
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	ld	hl, (_player_v_x)
	ld	a, e
	sub	a, l
	ld	e, a
	ld	a, d
	sbc	a, h
	ld	d, a
	ld	l, -6 (ix)
	ld	h, -5 (ix)
	ld	(hl), e
	inc	hl
	ld	(hl), d
;os.c:416: particle_y[p] -= player_v_y;
	ld	l, -8 (ix)
	ld	h, -7 (ix)
	ld	a, (hl)
	ld	-4 (ix), a
	inc	hl
	ld	a, (hl)
	ld	-3 (ix), a
	ld	hl, (_player_v_y)
	ld	a, -4 (ix)
	sub	a, l
	ld	-2 (ix), a
	ld	a, -3 (ix)
	sbc	a, h
	ld	-1 (ix), a
	ld	l, -8 (ix)
	ld	h, -7 (ix)
	ld	a, -2 (ix)
	ld	(hl), a
	inc	hl
	ld	a, -1 (ix)
	ld	(hl), a
;os.c:417: particle_x[p] += particle_v_x[p];
	ld	a, #<(_particle_v_x)
	add	a, -13 (ix)
	ld	l, a
	ld	a, #>(_particle_v_x)
	adc	a, -12 (ix)
	ld	h, a
	ld	a, (hl)
	inc	hl
	ld	h, (hl)
	ld	l, a
	add	hl, de
	ex	de, hl
	ld	l, -6 (ix)
	ld	h, -5 (ix)
	ld	(hl), e
	inc	hl
	ld	(hl), d
;os.c:418: particle_y[p] += particle_v_y[p];
	ld	a, -13 (ix)
	add	a, #<(_particle_v_y)
	ld	l, a
	ld	a, -12 (ix)
	adc	a, #>(_particle_v_y)
	ld	h, a
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	ld	a, e
	add	a, -2 (ix)
	ld	e, a
	ld	a, d
	adc	a, -1 (ix)
	ld	d, a
	ld	l, -8 (ix)
	ld	h, -7 (ix)
	ld	(hl), e
	inc	hl
	ld	(hl), d
00162$:
;os.c:394: for (unsigned char p = 0; p < const_particle_max; p++)
	inc	c
	jp	00197$
00163$:
;os.c:423: for (unsigned char p = 0; p < const_projectile_max; p++)
	xor	a, a
	ld	-1 (ix), a
00199$:
	ld	a, -1 (ix)
	sub	a, #0x08
	jp	NC, 00169$
;os.c:425: if (projectile_on[p])
	ld	a, #<(_projectile_on)
	add	a, -1 (ix)
	ld	c, a
	ld	a, #>(_projectile_on)
	adc	a, #0x00
	ld	b, a
	ld	a, (bc)
	bit	0, a
	jp	Z, 00168$
;os.c:427: projectile_timer[p]--;
	ld	a, #<(_projectile_timer)
	add	a, -1 (ix)
	ld	c, a
	ld	a, #>(_projectile_timer)
	adc	a, #0x00
	ld	b, a
	ld	a, (bc)
	dec	a
	ld	(bc), a
;os.c:428: if (projectile_timer[p] == 0)
	or	a, a
	jr	NZ,00165$
;os.c:430: kill_projectile(p);
	ld	a, -1 (ix)
	push	af
	inc	sp
	call	_kill_projectile
	inc	sp
;os.c:431: continue;
	jp	00168$
00165$:
;os.c:433: set_sprite_position(const_projectile_sprite_first + p, projectile_x[p] / scale, projectile_y[p] / scale);
	ld	l, -1 (ix)
	ld	h, #0x00
	add	hl, hl
	ld	c, l
	ld	b, h
	ld	hl, #_projectile_y
	add	hl, bc
	ld	-9 (ix), l
	ld	-8 (ix), h
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
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
	ld	hl, #_projectile_x
	add	hl, bc
	ld	-7 (ix), l
	ld	-6 (ix), h
	ld	a, (hl)
	inc	hl
	ld	h, (hl)
	ld	l, a
	srl	h
	rr	l
	srl	h
	rr	l
	srl	h
	rr	l
	srl	h
	rr	l
	srl	h
	rr	l
	srl	h
	rr	l
	srl	h
	rr	l
	ld	a, -1 (ix)
	add	a, #0x0d
	push	bc
	push	de
	push	hl
	push	af
	inc	sp
	call	_set_sprite_position
	pop	af
	pop	af
	inc	sp
	pop	bc
;os.c:434: projectile_x[p] -= player_v_x;
	ld	l, -7 (ix)
	ld	h, -6 (ix)
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	ld	hl, (_player_v_x)
	ld	a, e
	sub	a, l
	ld	e, a
	ld	a, d
	sbc	a, h
	ld	d, a
	ld	l, -7 (ix)
	ld	h, -6 (ix)
	ld	(hl), e
	inc	hl
	ld	(hl), d
;os.c:435: projectile_y[p] -= player_v_y;
	ld	l, -9 (ix)
	ld	h, -8 (ix)
	ld	a, (hl)
	ld	-5 (ix), a
	inc	hl
	ld	a, (hl)
	ld	-4 (ix), a
	ld	hl, (_player_v_y)
	ld	a, -5 (ix)
	sub	a, l
	ld	-3 (ix), a
	ld	a, -4 (ix)
	sbc	a, h
	ld	-2 (ix), a
	ld	l, -9 (ix)
	ld	h, -8 (ix)
	ld	a, -3 (ix)
	ld	(hl), a
	inc	hl
	ld	a, -2 (ix)
	ld	(hl), a
;os.c:436: projectile_x[p] += projectile_v_x[p];
	ld	hl, #_projectile_v_x
	add	hl, bc
	ld	a, (hl)
	inc	hl
	ld	h, (hl)
	ld	l, a
	add	hl, de
	ex	de, hl
	ld	l, -7 (ix)
	ld	h, -6 (ix)
	ld	(hl), e
	inc	hl
	ld	(hl), d
;os.c:437: projectile_y[p] += projectile_v_y[p];
	ld	hl, #_projectile_v_y
	add	hl, bc
	ld	c, (hl)
	inc	hl
	ld	b, (hl)
	ld	a, -3 (ix)
	add	a, c
	ld	c, a
	ld	a, -2 (ix)
	adc	a, b
	ld	b, a
	ld	l, -9 (ix)
	ld	h, -8 (ix)
	ld	(hl), c
	inc	hl
	ld	(hl), b
00168$:
;os.c:423: for (unsigned char p = 0; p < const_projectile_max; p++)
	inc	-1 (ix)
	jp	00199$
00169$:
;os.c:441: test_x -= player_v_x;
	ld	bc, (_player_v_x)
	ld	hl, #_test_x
	ld	a, (hl)
	sub	a, c
	ld	(hl), a
	inc	hl
	ld	a, (hl)
	sbc	a, b
	ld	(hl), a
;os.c:442: test_y -= player_v_y;
	ld	bc, (_player_v_y)
	ld	hl, #_test_y
	ld	a, (hl)
	sub	a, c
	ld	(hl), a
	inc	hl
	ld	a, (hl)
	sbc	a, b
	ld	(hl), a
;os.c:444: set_sprite_position(31, test_x / scale, test_y / scale);
	ld	bc, (_test_y)
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
	ld	hl, (_test_x)
	srl	h
	rr	l
	srl	h
	rr	l
	srl	h
	rr	l
	srl	h
	rr	l
	srl	h
	rr	l
	srl	h
	rr	l
	srl	h
	rr	l
	push	bc
	push	hl
	ld	a, #0x1f
	push	af
	inc	sp
	call	_set_sprite_position
	pop	af
	pop	af
	inc	sp
;os.c:446: if (spritecollisionram[31])
	ld	a, (#(_spritecollisionram + 0x001f) + 0)
	or	a, a
	jr	Z,00174$
;os.c:449: for (unsigned char p = 0; p < const_projectile_max; p++)
	xor	a, a
	ld	-1 (ix), a
00201$:
	ld	a, -1 (ix)
	sub	a, #0x08
	jr	NC,00172$
;os.c:451: if (spritecollisionram[const_projectile_sprite_first + p])
	ld	de, #_spritecollisionram+0
	ld	c, -1 (ix)
	ld	a, c
	add	a, #0x0d
	ld	-3 (ix), a
	rla
	sbc	a, a
	ld	-2 (ix), a
	ld	l, -3 (ix)
	ld	h, -2 (ix)
	add	hl, de
	ld	a, (hl)
	or	a, a
	jr	Z,00202$
;os.c:453: write_char('P', 0xFF, 0, p + 1);
	ld	a, c
	inc	a
	push	af
	inc	sp
	xor	a, a
	ld	d,a
	ld	e,#0xff
	push	de
	ld	a, #0x50
	push	af
	inc	sp
	call	_write_char
	pop	af
	pop	af
;os.c:454: kill_projectile(p);
	ld	a, -1 (ix)
	push	af
	inc	sp
	call	_kill_projectile
	inc	sp
;os.c:455: spritecollisionram[const_projectile_sprite_first + p] = 0;
	ld	bc, #_spritecollisionram+0
	ld	l, -3 (ix)
	ld	h, -2 (ix)
	add	hl, bc
	ld	(hl), #0x00
00202$:
;os.c:449: for (unsigned char p = 0; p < const_projectile_max; p++)
	inc	-1 (ix)
	jr	00201$
00172$:
;os.c:458: spritecollisionram[31] = 0;
	ld	hl, #(_spritecollisionram + 0x001f)
	ld	(hl), #0x00
00174$:
;os.c:461: unsigned short l = (GET_TIMER)-t;
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
	ld	a, c
	sub	a, -11 (ix)
	ld	c, a
	ld	a, b
	sbc	a, -10 (ix)
	ld	b, a
;os.c:462: write_stringf_ushort("%6d", 0xFF, 0, 0, l);
	push	bc
	xor	a, a
	push	af
	inc	sp
	xor	a, a
	ld	d,a
	ld	e,#0xff
	push	de
	ld	hl, #___str_1
	push	hl
	call	_write_stringf_ushort
	ld	hl, #7
	add	hl, sp
	ld	sp, hl
00176$:
;os.c:464: vblank_last = vblank;
	ld	a,(#_vblank + 0)
	ld	iy, #_vblank_last
	ld	0 (iy), a
;os.c:466: }
	jp	00179$
___str_0:
	.ascii "CALCULATING VECTORS"
	.db 0x00
___str_1:
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
__xinit__player_turn_timer_max:
	.db #0x04	;  4
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
