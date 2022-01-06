;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.8.0 #10562 (Linux)
;--------------------------------------------------------
	.module zorblaxx_pickups
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _enable_sprite
	.globl _set_sprite_position
	.globl _rand_ushort
	.globl _rand_uchar
	.globl _pickup_spawn_interval
	.globl _pickup_spawn_y
	.globl _pickup_type_count
	.globl _pickup_max
	.globl _pickup_y_offset
	.globl _pickup_y_max
	.globl _pickup_timer
	.globl _pickup_value
	.globl _pickup_state
	.globl _pickup_ys
	.globl _pickup_y
	.globl _pickup_x
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
	.globl _spawn_pickup
	.globl _setup_pickups
	.globl _handle_pickups
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
_pickup_x::
	.ds 2
_pickup_y::
	.ds 2
_pickup_ys::
	.ds 1
_pickup_state::
	.ds 1
_pickup_value::
	.ds 1
_pickup_timer::
	.ds 1
_pickup_y_max::
	.ds 2
_pickup_y_offset::
	.ds 1
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
_pickup_max::
	.ds 1
_pickup_type_count::
	.ds 1
_pickup_spawn_y::
	.ds 1
_pickup_spawn_interval::
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
;zorblaxx_pickups.c:45: void spawn_pickup()
;	---------------------------------
; Function spawn_pickup
; ---------------------------------
_spawn_pickup::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	hl, #-7
	add	hl, sp
	ld	sp, hl
;zorblaxx_pickups.c:47: for (unsigned char t = 0; t < pickup_max; t++)
	ld	c, #0x00
	ld	e, #0x00
00105$:
	ld	hl, #_pickup_max
	ld	a, e
	sub	a, (hl)
	jp	NC, 00107$
;zorblaxx_pickups.c:49: if (pickup_state[t] == 0)
	ld	a, #<(_pickup_state)
	add	a, e
	ld	-7 (ix), a
	ld	a, #>(_pickup_state)
	adc	a, #0x00
	ld	-6 (ix), a
	pop	hl
	push	hl
	ld	a, (hl)
	or	a, a
	jp	NZ, 00106$
;zorblaxx_pickups.c:51: unsigned char sprite = pickup_sprite_first + t;
	ld	a, c
	add	a, #0x0a
	ld	-1 (ix), a
;zorblaxx_pickups.c:52: unsigned char type = rand_uchar(0, const_type_count - 1);
	push	bc
	ld	a, #0x03
	push	af
	inc	sp
	xor	a, a
	push	af
	inc	sp
	call	_rand_uchar
	pop	af
	pop	bc
	ld	b, l
;zorblaxx_pickups.c:54: pickup_x[t] = rand_ushort(48, 272) * x_divisor;
	ld	l, c
	ld	h, #0x00
	add	hl, hl
	ld	-3 (ix), l
	ld	-2 (ix), h
	ld	a, #<(_pickup_x)
	add	a, -3 (ix)
	ld	-5 (ix), a
	ld	a, #>(_pickup_x)
	adc	a, -2 (ix)
	ld	-4 (ix), a
	push	bc
	ld	hl, #0x0110
	push	hl
	ld	hl, #0x0030
	push	hl
	call	_rand_ushort
	pop	af
	pop	af
	pop	bc
	ld	iy, #_x_divisor
	ld	e, 0 (iy)
	ld	d, #0x00
	push	bc
	push	de
	push	hl
	call	__mulint
	pop	af
	pop	af
	ex	de,hl
	pop	bc
	ld	l, -5 (ix)
	ld	h, -4 (ix)
	ld	(hl), e
	inc	hl
	ld	(hl), d
;zorblaxx_pickups.c:55: pickup_y[t] = pickup_spawn_y * y_divisor;
	ld	a, #<(_pickup_y)
	add	a, -3 (ix)
	ld	-3 (ix), a
	ld	a, #>(_pickup_y)
	adc	a, -2 (ix)
	ld	-2 (ix), a
	ld	hl,#_y_divisor + 0
	ld	e, (hl)
	push	bc
	ld	hl,#_pickup_spawn_y + 0
	ld	h, (hl)
	ld	l, #0x00
	ld	d, l
	ld	b, #0x08
00124$:
	add	hl, hl
	jr	NC,00125$
	add	hl, de
00125$:
	djnz	00124$
	pop	bc
	ex	de, hl
	ld	l, -3 (ix)
	ld	h, -2 (ix)
	ld	(hl), e
	inc	hl
	ld	(hl), d
;zorblaxx_pickups.c:56: pickup_ys[t] = rand_uchar(0, type * 12);
	ld	a, #<(_pickup_ys)
	add	a, c
	ld	e, a
	ld	a, #>(_pickup_ys)
	adc	a, #0x00
	ld	d, a
	push	de
	ld	a, b
	ld	e, a
	add	a, a
	add	a, e
	add	a, a
	add	a, a
	pop	de
	push	bc
	push	de
	push	af
	inc	sp
	xor	a, a
	push	af
	inc	sp
	call	_rand_uchar
	pop	af
	ld	a, l
	pop	de
	pop	bc
	ld	(de), a
;zorblaxx_pickups.c:57: pickup_state[t] = 1;
	pop	hl
	push	hl
	ld	(hl), #0x01
;zorblaxx_pickups.c:58: pickup_value[t] = 50 * (type + 1);
	ld	a, #<(_pickup_value)
	add	a, c
	ld	e, a
	ld	a, #>(_pickup_value)
	adc	a, #0x00
	ld	d, a
	ld	c, b
	ld	a, c
	inc	a
	push	de
	ld	e, a
	add	a, a
	add	a, e
	add	a, a
	add	a, a
	add	a, a
	add	a, e
	add	a, a
	pop	de
	ld	(de), a
;zorblaxx_pickups.c:59: enable_sprite(sprite, sprite_palette_pickups, sprite_size_pickups, 1);
	push	bc
	ld	de, #0x0101
	push	de
	ld	a, #0x01
	push	af
	inc	sp
	ld	a, -1 (ix)
	push	af
	inc	sp
	call	_enable_sprite
	pop	af
	pop	af
	pop	bc
;zorblaxx_pickups.c:60: spr_index[sprite] = sprite_index_pickups_first + type;
	ld	de, #_spr_index+0
	ld	l, -1 (ix)
	ld	h, #0x00
	add	hl, de
	ld	a, c
	add	a, #0x10
	ld	(hl), a
;zorblaxx_pickups.c:61: set_sprite_position(sprite, pickup_x[t] / x_divisor, pickup_spawn_y);
	ld	hl,#_pickup_spawn_y + 0
	ld	c, (hl)
	ld	b, #0x00
	ld	l, -5 (ix)
	ld	h, -4 (ix)
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	ld	iy, #_x_divisor
	ld	l, 0 (iy)
	ld	h, #0x00
	push	bc
	push	hl
	push	de
	call	__divuint
	pop	af
	ex	(sp),hl
	ld	a, -1 (ix)
	push	af
	inc	sp
	call	_set_sprite_position
	pop	af
	pop	af
	inc	sp
;zorblaxx_pickups.c:62: return;
	jr	00107$
00106$:
;zorblaxx_pickups.c:47: for (unsigned char t = 0; t < pickup_max; t++)
	inc	e
	ld	c, e
	jp	00105$
00107$:
;zorblaxx_pickups.c:65: }
	ld	sp, ix
	pop	ix
	ret
;zorblaxx_pickups.c:67: void setup_pickups()
;	---------------------------------
; Function setup_pickups
; ---------------------------------
_setup_pickups::
;zorblaxx_pickups.c:69: pickup_y_max = 272 * y_divisor;
	ld	hl,#_y_divisor + 0
	ld	c, (hl)
	ld	e, c
	ld	d, #0x00
	ld	l, e
	ld	h, d
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, de
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	ld	(_pickup_y_max), hl
;zorblaxx_pickups.c:70: pickup_y_offset = (8 * y_divisor);
	ld	a, c
	add	a, a
	add	a, a
	add	a, a
	ld	(#_pickup_y_offset + 0),a
;zorblaxx_pickups.c:71: for (int t = pickup_sprite_first; t < pickup_sprite_first + pickup_max; t++)
	ld	bc, #0x000a
00103$:
	ld	hl,#_pickup_max + 0
	ld	e, (hl)
	ld	d, #0x00
	ld	hl, #0x000a
	add	hl, de
	ld	a, c
	sub	a, l
	ld	a, b
	sbc	a, h
	jp	PO, 00118$
	xor	a, #0x80
00118$:
	ret	P
;zorblaxx_pickups.c:73: enable_sprite(t, sprite_palette_pickups, sprite_size_pickups, false);
	ld	d, c
	push	bc
	xor	a, a
	ld	b,a
	ld	c,#0x01
	push	bc
	ld	a, #0x01
	push	af
	inc	sp
	push	de
	inc	sp
	call	_enable_sprite
	pop	af
	pop	af
	pop	bc
;zorblaxx_pickups.c:74: spr_on[t] = false;
	ld	hl, #_spr_on
	add	hl, bc
	ld	(hl), #0x00
;zorblaxx_pickups.c:71: for (int t = pickup_sprite_first; t < pickup_sprite_first + pickup_max; t++)
	inc	bc
;zorblaxx_pickups.c:76: }
	jr	00103$
;zorblaxx_pickups.c:78: void handle_pickups()
;	---------------------------------
; Function handle_pickups
; ---------------------------------
_handle_pickups::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	hl, #-8
	add	hl, sp
	ld	sp, hl
;zorblaxx_pickups.c:80: for (unsigned char t = 0; t < pickup_max; t++)
	ld	c, #0x00
00112$:
	ld	hl, #_pickup_max
	ld	a, c
	sub	a, (hl)
	jp	NC, 00113$
;zorblaxx_pickups.c:82: if (pickup_state[t] > 0)
	ld	a, #<(_pickup_state)
	add	a, c
	ld	e, a
	ld	a, #>(_pickup_state)
	adc	a, #0x00
	ld	d, a
	ld	a, (de)
	or	a, a
	jp	Z, 00109$
;zorblaxx_pickups.c:84: unsigned char sprite = pickup_sprite_first + t;
	ld	a, c
	add	a, #0x0a
	ld	b, a
;zorblaxx_pickups.c:85: pickup_y[t] += (pickup_ys[t] + scroll_speed);
	ld	l, c
	ld	h, #0x00
	add	hl, hl
	ld	-2 (ix), l
	ld	-1 (ix), h
	ld	a, #<(_pickup_y)
	add	a, -2 (ix)
	ld	-6 (ix), a
	ld	a, #>(_pickup_y)
	adc	a, -1 (ix)
	ld	-5 (ix), a
	ld	l, -6 (ix)
	ld	h, -5 (ix)
	ld	a, (hl)
	ld	-4 (ix), a
	inc	hl
	ld	a, (hl)
	ld	-3 (ix), a
	ld	a, #<(_pickup_ys)
	add	a, c
	ld	l, a
	ld	a, #>(_pickup_ys)
	adc	a, #0x00
	ld	h, a
	ld	a, (hl)
	ld	-8 (ix), a
	rla
	sbc	a, a
	ld	-7 (ix), a
	ld	a,(#_scroll_speed + 0)
	ld	h, #0x00
	add	a, -8 (ix)
	ld	l, a
	ld	a, h
	adc	a, -7 (ix)
	ld	h, a
	ld	a, l
	add	a, -4 (ix)
	ld	-8 (ix), a
	ld	a, h
	adc	a, -3 (ix)
	ld	-7 (ix), a
	ld	l, -6 (ix)
	ld	h, -5 (ix)
	ld	a, -8 (ix)
	ld	(hl), a
	inc	hl
	ld	a, -7 (ix)
	ld	(hl), a
;zorblaxx_pickups.c:86: if ((pickup_y[t] > pickup_y_max) > 0)
	ld	hl, #_pickup_y_max
	ld	a, (hl)
	sub	a, -8 (ix)
	inc	hl
	ld	a, (hl)
	sbc	a, -7 (ix)
	jr	NC,00102$
;zorblaxx_pickups.c:88: spr_on[sprite] = false;
	ld	a, #<(_spr_on)
	add	a, b
	ld	l, a
	ld	a, #>(_spr_on)
	adc	a, #0x00
	ld	h, a
	ld	(hl), #0x00
;zorblaxx_pickups.c:89: pickup_state[t] = 0;
	xor	a, a
	ld	(de), a
;zorblaxx_pickups.c:90: continue;
	jp	00109$
00102$:
;zorblaxx_pickups.c:93: if (pickup_state[t] == 2)
	ld	a, (de)
	sub	a, #0x02
	jr	NZ,00106$
;zorblaxx_pickups.c:95: pickup_timer[t]--;
	ld	a, #<(_pickup_timer)
	add	a, c
	ld	-8 (ix), a
	ld	a, #>(_pickup_timer)
	adc	a, #0x00
	ld	-7 (ix), a
	pop	hl
	push	hl
	ld	a, (hl)
	dec	a
	pop	hl
	push	hl
	ld	(hl), a
;zorblaxx_pickups.c:96: if (pickup_timer[t] == 0)
	or	a, a
	jr	NZ,00106$
;zorblaxx_pickups.c:98: spr_on[sprite] = false;
	ld	a, #<(_spr_on)
	add	a, b
	ld	l, a
	ld	a, #>(_spr_on)
	adc	a, #0x00
	ld	h, a
	ld	(hl), #0x00
;zorblaxx_pickups.c:99: pickup_state[t] = 0;
	xor	a, a
	ld	(de), a
;zorblaxx_pickups.c:100: pickup_timer[t] = pickup_spawn_interval;
	pop	hl
	push	hl
	ld	a,(#_pickup_spawn_interval + 0)
	ld	(hl), a
;zorblaxx_pickups.c:101: continue;
	jr	00109$
00106$:
;zorblaxx_pickups.c:104: set_sprite_position(sprite, pickup_x[t] / x_divisor, pickup_y[t] / y_divisor);
	ld	l, -6 (ix)
	ld	h, -5 (ix)
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	ld	iy, #_y_divisor
	ld	l, 0 (iy)
	ld	h, #0x00
	push	bc
	push	hl
	push	de
	call	__divuint
	pop	af
	pop	af
	ld	-7 (ix), h
	ld	-8 (ix), l
	pop	bc
	ld	a, -2 (ix)
	add	a, #<(_pickup_x)
	ld	l, a
	ld	a, -1 (ix)
	adc	a, #>(_pickup_x)
	ld	h, a
	ld	e, (hl)
	inc	hl
	ld	d, (hl)
	ld	iy, #_x_divisor
	ld	l, 0 (iy)
	ld	h, #0x00
	push	bc
	push	hl
	push	de
	call	__divuint
	pop	af
	pop	af
	pop	bc
	push	bc
	ld	e, -8 (ix)
	ld	d, -7 (ix)
	push	de
	push	hl
	push	bc
	inc	sp
	call	_set_sprite_position
	pop	af
	pop	af
	inc	sp
	pop	bc
00109$:
;zorblaxx_pickups.c:80: for (unsigned char t = 0; t < pickup_max; t++)
	inc	c
	jp	00112$
00113$:
;zorblaxx_pickups.c:107: }
	ld	sp, ix
	pop	ix
	ret
	.area _CODE
	.area _INITIALIZER
__xinit__pickup_max:
	.db #0x01	; 1
__xinit__pickup_type_count:
	.db #0x04	; 4
__xinit__pickup_spawn_y:
	.db #0x00	; 0
__xinit__pickup_spawn_interval:
	.db #0x0a	; 10
	.area _CABS (ABS)
