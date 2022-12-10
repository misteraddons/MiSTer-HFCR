// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VEMU_H_
#define VERILATED_VEMU_H_  // guard

#include "verilated_heavy.h"

//==========

class Vemu__Syms;

//----------

VL_MODULE(Vemu) {
  public:

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk_sys,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(menu,0,0);
    VL_IN8(paddle_0,7,0);
    VL_IN8(paddle_1,7,0);
    VL_IN8(paddle_2,7,0);
    VL_IN8(paddle_3,7,0);
    VL_IN8(paddle_4,7,0);
    VL_IN8(paddle_5,7,0);
    VL_OUT8(VGA_R,7,0);
    VL_OUT8(VGA_G,7,0);
    VL_OUT8(VGA_B,7,0);
    VL_OUT8(VGA_HS,0,0);
    VL_OUT8(VGA_VS,0,0);
    VL_OUT8(VGA_HB,0,0);
    VL_OUT8(VGA_VB,0,0);
    VL_IN8(ioctl_download,0,0);
    VL_IN8(ioctl_wr,0,0);
    VL_IN8(ioctl_dout,7,0);
    VL_IN8(ioctl_index,7,0);
    VL_OUT8(ioctl_wait,0,0);
    VL_IN16(joystick_l_analog_0,15,0);
    VL_IN16(joystick_l_analog_1,15,0);
    VL_IN16(joystick_l_analog_2,15,0);
    VL_IN16(joystick_l_analog_3,15,0);
    VL_IN16(joystick_l_analog_4,15,0);
    VL_IN16(joystick_l_analog_5,15,0);
    VL_IN16(joystick_r_analog_0,15,0);
    VL_IN16(joystick_r_analog_1,15,0);
    VL_IN16(joystick_r_analog_2,15,0);
    VL_IN16(joystick_r_analog_3,15,0);
    VL_IN16(joystick_r_analog_4,15,0);
    VL_IN16(joystick_r_analog_5,15,0);
    VL_IN16(spinner_0,8,0);
    VL_IN16(spinner_1,8,0);
    VL_IN16(spinner_2,8,0);
    VL_IN16(spinner_3,8,0);
    VL_IN16(spinner_4,8,0);
    VL_IN16(spinner_5,8,0);
    VL_IN16(ps2_key,10,0);
    VL_IN16(ps2_mouse_ext,15,0);
    VL_OUT16(AUDIO_L,15,0);
    VL_OUT16(AUDIO_R,15,0);
    VL_IN(joystick_0,31,0);
    VL_IN(joystick_1,31,0);
    VL_IN(joystick_2,31,0);
    VL_IN(joystick_3,31,0);
    VL_IN(joystick_4,31,0);
    VL_IN(joystick_5,31,0);
    VL_IN(ps2_mouse,24,0);
    VL_IN(ioctl_addr,24,0);
    VL_IN64(timestamp,32,0);

    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ emu__DOT__ce_6;
    CData/*0:0*/ emu__DOT__pause_cpu;
    CData/*3:0*/ emu__DOT__divider__DOT__cencnt;
    CData/*0:0*/ emu__DOT__pause__DOT__pause_request;
    CData/*0:0*/ emu__DOT__pause__DOT__pause_toggle;
    CData/*0:0*/ emu__DOT__pause__DOT__unnamedblk1__DOT__user_button_last;
    CData/*0:0*/ emu__DOT__system__DOT___hb;
    CData/*0:0*/ emu__DOT__system__DOT___vb;
    CData/*7:0*/ emu__DOT__system__DOT__music_data_out;
    CData/*7:0*/ emu__DOT__system__DOT__video_control;
    CData/*0:0*/ emu__DOT__system__DOT__pause_trigger;
    CData/*0:0*/ emu__DOT__system__DOT__pause_system;
    CData/*0:0*/ emu__DOT__system__DOT__menu_trigger;
    CData/*7:0*/ emu__DOT__system__DOT__pgrom_data_out;
    CData/*7:0*/ emu__DOT__system__DOT__chrom_data_out;
    CData/*7:0*/ emu__DOT__system__DOT__wkram_data_out;
    CData/*7:0*/ emu__DOT__system__DOT__chram_data_out;
    CData/*7:0*/ emu__DOT__system__DOT__fgcolram_data_out;
    CData/*7:0*/ emu__DOT__system__DOT__bgcolram_data_out;
    CData/*7:0*/ emu__DOT__system__DOT__chmap_data_out;
    CData/*0:0*/ emu__DOT__system__DOT__pgrom_wr;
    CData/*0:0*/ emu__DOT__system__DOT__chrom_wr;
    CData/*0:0*/ emu__DOT__system__DOT__spriterom_wr;
    CData/*0:0*/ emu__DOT__system__DOT__chram_wr;
    CData/*0:0*/ emu__DOT__system__DOT__fgcolram_wr;
    CData/*0:0*/ emu__DOT__system__DOT__bgcolram_wr;
    CData/*0:0*/ emu__DOT__system__DOT__spriteram_wr;
    CData/*0:0*/ emu__DOT__system__DOT__spritecollisionram_wr;
    CData/*0:0*/ emu__DOT__system__DOT__tilemapram_wr;
    CData/*7:0*/ emu__DOT__system__DOT__cpu_din;
    CData/*7:0*/ emu__DOT__system__DOT__cpu_dout;
    CData/*0:0*/ emu__DOT__system__DOT__cpu_wr_n;
    CData/*0:0*/ emu__DOT__system__DOT__charmap_a;
    CData/*7:0*/ emu__DOT__system__DOT__tilemap_r;
    CData/*7:0*/ emu__DOT__system__DOT__tilemap_g;
    CData/*7:0*/ emu__DOT__system__DOT__tilemap_b;
    CData/*0:0*/ emu__DOT__system__DOT__tilemap_a;
    CData/*7:0*/ emu__DOT__system__DOT__tilemapram_data_out;
    CData/*0:0*/ emu__DOT__system__DOT__tilemapram_ctl_wr;
    CData/*7:0*/ emu__DOT__system__DOT__tilemapram_ctl_data_in;
    CData/*7:0*/ emu__DOT__system__DOT__palrom_addr;
    CData/*0:0*/ emu__DOT__system__DOT__spritecollisionram_data_out_cpu;
    CData/*7:0*/ emu__DOT__system__DOT__spriterom_data_out;
    CData/*6:0*/ emu__DOT__system__DOT__spriteram_addr;
    CData/*7:0*/ emu__DOT__system__DOT__spriteram_data_out;
    CData/*4:0*/ emu__DOT__system__DOT__spritecollisionram_addr;
    CData/*0:0*/ emu__DOT__system__DOT__spritecollisionram_data_out;
    CData/*0:0*/ emu__DOT__system__DOT__spritecollisionram_data_in;
    CData/*0:0*/ emu__DOT__system__DOT__spritelbram_wr;
    CData/*0:0*/ emu__DOT__system__DOT__sf_on1;
    CData/*0:0*/ emu__DOT__system__DOT__sf_on2;
    CData/*0:0*/ emu__DOT__system__DOT__sf_on3;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__write;
    CData/*7:0*/ emu__DOT__system__DOT__T80x__DOT__di_reg;
    CData/*7:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ACC;
    CData/*7:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F;
    CData/*7:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Ap;
    CData/*7:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Fp;
    CData/*7:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I;
    CData/*7:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegDIH;
    CData/*7:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegDIL;
    CData/*2:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegAddrA_r;
    CData/*2:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegAddrA;
    CData/*2:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegAddrB_r;
    CData/*2:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegAddrB;
    CData/*2:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegAddrC;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegWEH;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegWEL;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Alternate;
    CData/*7:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR;
    CData/*1:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet;
    CData/*7:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_Mux;
    CData/*6:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstate;
    CData/*6:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__last_mcycle;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__last_tstate;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IntE_FF1;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IntE_FF2;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Halt_FF;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusReq_s;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusAck;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__NMI_s;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__INT_s;
    CData/*1:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IStatus;
    CData/*1:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__XY_State;
    CData/*2:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Pre_XY_F_M;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__NextIs_XY_Fetch;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__XY_Ind;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__No_BTR;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BTR_r;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Auto_Wait;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Auto_Wait_t1;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Auto_Wait_t2;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDecZ;
    CData/*7:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusB;
    CData/*7:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusA;
    CData/*7:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Q;
    CData/*7:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out;
    CData/*4:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg_r;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Arith16_r;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Z16_r;
    CData/*3:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op_r;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU_r;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PreserveC_r;
    CData/*2:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles;
    CData/*2:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d;
    CData/*2:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IntCycle;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__NMICycle;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_WZ;
    CData/*3:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16;
    CData/*1:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Prefix;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Acc;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg;
    CData/*3:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To;
    CData/*3:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To;
    CData/*3:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PreserveC;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Arith16;
    CData/*2:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Jump;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__JumpE;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__JumpXY;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Call;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RstP;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDW;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDSPHL;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__iorq_i;
    CData/*2:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Special_LD;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ExchangeDH;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ExchangeRp;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ExchangeAF;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ExchangeRS;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_DJNZ;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_CPL;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_CCF;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_SCF;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_RETN;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_BT;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_BC;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_BTR;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_RLD;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_RRD;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_INRC;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__SetDI;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__SetEI;
    CData/*1:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IMode;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Halt;
    CData/*2:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD;
    CData/*2:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS;
    CData/*1:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__UseCarry;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Carry7_v;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__OverFlow_v;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__HalfCarry_v;
    CData/*0:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Carry_v;
    CData/*7:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_v;
    CData/*7:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__BitMask;
    CData/*7:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t;
    CData/*0:0*/ emu__DOT__system__DOT__casval__DOT__char_a;
    CData/*1:0*/ emu__DOT__system__DOT__zechs__DOT__tilemap_read_state;
    CData/*2:0*/ emu__DOT__system__DOT__zechs__DOT__tilemap_ctl_state;
    CData/*4:0*/ emu__DOT__system__DOT__zechs__DOT__tilemap_ctl_x;
    CData/*4:0*/ emu__DOT__system__DOT__zechs__DOT__tilemap_ctl_y;
    CData/*4:0*/ emu__DOT__system__DOT__zechs__DOT__tilemap_scroll_state;
    CData/*4:0*/ emu__DOT__system__DOT__zechs__DOT__tilemap_scroll_state_next;
    CData/*4:0*/ emu__DOT__system__DOT__zechs__DOT__tilemap_scroll_start_pos;
    CData/*4:0*/ emu__DOT__system__DOT__zechs__DOT__tilemap_scroll_target_pos;
    CData/*0:0*/ emu__DOT__system__DOT__zechs__DOT__tilemap_scroll_axis;
    CData/*0:0*/ emu__DOT__system__DOT__zechs__DOT__tilemap_scroll_dir;
    CData/*2:0*/ emu__DOT__system__DOT__zechs__DOT__tilemap_clear_state;
    CData/*0:0*/ emu__DOT__system__DOT__comet__DOT__spritelb_slot_rd;
    CData/*0:0*/ emu__DOT__system__DOT__comet__DOT__spritelb_slot_wr;
    CData/*0:0*/ emu__DOT__system__DOT__comet__DOT__hsync_last;
    CData/*4:0*/ emu__DOT__system__DOT__comet__DOT__spr_state;
    CData/*4:0*/ emu__DOT__system__DOT__comet__DOT__spr_state_next;
    CData/*5:0*/ emu__DOT__system__DOT__comet__DOT__spr_index;
    CData/*0:0*/ emu__DOT__system__DOT__comet__DOT__spr_enable;
    CData/*0:0*/ emu__DOT__system__DOT__comet__DOT__spr_collide;
    CData/*1:0*/ emu__DOT__system__DOT__comet__DOT__spr_palette_index;
    CData/*5:0*/ emu__DOT__system__DOT__comet__DOT__spr_image_index;
    CData/*5:0*/ emu__DOT__system__DOT__comet__DOT__spr_pixel_index;
    CData/*3:0*/ emu__DOT__system__DOT__comet__DOT__col_primary_state;
    CData/*3:0*/ emu__DOT__system__DOT__comet__DOT__col_primary_state_next;
    CData/*3:0*/ emu__DOT__system__DOT__comet__DOT__col_secondary_state;
    CData/*3:0*/ emu__DOT__system__DOT__comet__DOT__col_secondary_state_next;
    CData/*4:0*/ emu__DOT__system__DOT__comet__DOT__col_spriteindex;
    CData/*0:0*/ emu__DOT__system__DOT__comet__DOT__col_buffer_primary_wr;
    CData/*0:0*/ emu__DOT__system__DOT__comet__DOT__col_buffer_secondary_wr;
    CData/*4:0*/ emu__DOT__system__DOT__comet__DOT__col_buffer_secondary_collisions_count1;
    CData/*4:0*/ emu__DOT__system__DOT__comet__DOT__col_buffer_secondary_collisions_count2;
    CData/*0:0*/ emu__DOT__system__DOT__comet__DOT__col_buffer_primary_is_a;
    CData/*0:0*/ emu__DOT__system__DOT__stars1__DOT__enabled;
    CData/*0:0*/ emu__DOT__system__DOT__stars1__DOT__vdirection;
    CData/*7:0*/ emu__DOT__system__DOT__stars1__DOT__vincrement;
    CData/*0:0*/ emu__DOT__system__DOT__stars1__DOT__hdirection;
    CData/*7:0*/ emu__DOT__system__DOT__stars1__DOT__hincrement;
    CData/*0:0*/ emu__DOT__system__DOT__stars2__DOT__enabled;
    CData/*0:0*/ emu__DOT__system__DOT__stars2__DOT__vdirection;
    CData/*7:0*/ emu__DOT__system__DOT__stars2__DOT__vincrement;
    CData/*0:0*/ emu__DOT__system__DOT__stars2__DOT__hdirection;
    CData/*7:0*/ emu__DOT__system__DOT__stars2__DOT__hincrement;
    CData/*0:0*/ emu__DOT__system__DOT__stars3__DOT__enabled;
    CData/*0:0*/ emu__DOT__system__DOT__stars3__DOT__vdirection;
    CData/*7:0*/ emu__DOT__system__DOT__stars3__DOT__vincrement;
    CData/*0:0*/ emu__DOT__system__DOT__stars3__DOT__hdirection;
    CData/*7:0*/ emu__DOT__system__DOT__stars3__DOT__hincrement;
    SData/*8:0*/ emu__DOT__system__DOT__hcnt;
    SData/*8:0*/ emu__DOT__system__DOT__vcnt;
    SData/*15:0*/ emu__DOT__system__DOT__timer;
    SData/*15:0*/ emu__DOT__system__DOT__cpu_addr;
    SData/*11:0*/ emu__DOT__system__DOT__chram_addr;
    SData/*14:0*/ emu__DOT__system__DOT__tilemaprom_addr;
    SData/*15:0*/ emu__DOT__system__DOT__tilemaprom_data_out;
    SData/*9:0*/ emu__DOT__system__DOT__tilemapram_addr;
    SData/*15:0*/ emu__DOT__system__DOT__palrom_data_out;
    SData/*13:0*/ emu__DOT__system__DOT__sprom_addr;
    SData/*9:0*/ emu__DOT__system__DOT__spritelbram_wr_addr;
    SData/*15:0*/ emu__DOT__system__DOT__spritelbram_data_in;
    SData/*15:0*/ emu__DOT__system__DOT__spritelbram_data_out;
    SData/*9:0*/ emu__DOT__system__DOT__music_audio_out;
    SData/*11:0*/ emu__DOT__system__DOT__snd_audio_out;
    SData/*14:0*/ emu__DOT__system__DOT__ms_timer__DOT__divider;
    SData/*15:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__SP;
    SData/*15:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PC;
    SData/*15:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegBusA;
    SData/*15:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegBusB;
    SData/*15:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegBusC;
    SData/*15:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__TmpAddr;
    SData/*15:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegBusA_r;
    SData/*15:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ID16;
    SData/*15:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PC16;
    SData/*15:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PC16_B;
    SData/*15:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__SP16;
    SData/*15:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__SP16_A;
    SData/*15:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__SP16_B;
    SData/*15:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ID16_B;
    SData/*8:0*/ emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q;
    SData/*9:0*/ emu__DOT__system__DOT__zechs__DOT__tilemap_pos_x;
    SData/*9:0*/ emu__DOT__system__DOT__zechs__DOT__tilemap_pos_y;
    SData/*9:0*/ emu__DOT__system__DOT__zechs__DOT__tilemap_offset_x;
    SData/*9:0*/ emu__DOT__system__DOT__zechs__DOT__tilemap_offset_y;
    SData/*15:0*/ emu__DOT__system__DOT__zechs__DOT__tilemap_read_cycles;
    SData/*15:0*/ emu__DOT__system__DOT__zechs__DOT__tilemap_ctl_cycles;
    SData/*8:0*/ emu__DOT__system__DOT__zechs__DOT__hcnt_last;
    SData/*8:0*/ emu__DOT__system__DOT__comet__DOT__spr_size;
    SData/*8:0*/ emu__DOT__system__DOT__comet__DOT__spr_x;
    SData/*8:0*/ emu__DOT__system__DOT__comet__DOT__spr_y;
    SData/*8:0*/ emu__DOT__system__DOT__comet__DOT__spr_active_y;
    SData/*13:0*/ emu__DOT__system__DOT__comet__DOT__spr_rom_offset;
    SData/*9:0*/ emu__DOT__system__DOT__comet__DOT__spr_rom_y_offset;
    SData/*13:0*/ emu__DOT__system__DOT__comet__DOT__spr_rom_offset_8x8;
    SData/*13:0*/ emu__DOT__system__DOT__comet__DOT__spr_rom_offset_16x16;
    SData/*13:0*/ emu__DOT__system__DOT__comet__DOT__spr_rom_offset_32x32;
    SData/*8:0*/ emu__DOT__system__DOT__comet__DOT__col_x;
    SData/*8:0*/ emu__DOT__system__DOT__comet__DOT__col_buffer_primary_addr;
    SData/*8:0*/ emu__DOT__system__DOT__comet__DOT__col_buffer_secondary_addr;
    SData/*15:0*/ emu__DOT__system__DOT__comet__DOT__col_secondary_timer;
    SData/*14:0*/ emu__DOT__system__DOT__stars1__DOT__vspeed_set;
    SData/*15:0*/ emu__DOT__system__DOT__stars1__DOT__vtimer;
    SData/*14:0*/ emu__DOT__system__DOT__stars1__DOT__hspeed_set;
    SData/*15:0*/ emu__DOT__system__DOT__stars1__DOT__htimer;
    SData/*14:0*/ emu__DOT__system__DOT__stars2__DOT__vspeed_set;
    SData/*15:0*/ emu__DOT__system__DOT__stars2__DOT__vtimer;
    SData/*14:0*/ emu__DOT__system__DOT__stars2__DOT__hspeed_set;
    SData/*15:0*/ emu__DOT__system__DOT__stars2__DOT__htimer;
    SData/*14:0*/ emu__DOT__system__DOT__stars3__DOT__vspeed_set;
    SData/*15:0*/ emu__DOT__system__DOT__stars3__DOT__vtimer;
    SData/*14:0*/ emu__DOT__system__DOT__stars3__DOT__hspeed_set;
    SData/*15:0*/ emu__DOT__system__DOT__stars3__DOT__htimer;
    IData/*23:0*/ emu__DOT__rgb_out;
    IData/*31:0*/ emu__DOT__pause__DOT__pause_timer;
    IData/*23:0*/ emu__DOT__system__DOT__rgb_starfield;
    IData/*23:0*/ emu__DOT__system__DOT__rgb_charmap;
    IData/*23:0*/ emu__DOT__system__DOT__rgb_tilemap;
    IData/*23:0*/ emu__DOT__system__DOT__rgb_sprite;
    IData/*23:0*/ emu__DOT__system__DOT__rgb_final;
    IData/*31:0*/ emu__DOT__system__DOT__comet__DOT__col_buffer_primary_data_in;
    IData/*31:0*/ emu__DOT__system__DOT__comet__DOT__col_buffer_primary_data_out;
    IData/*31:0*/ emu__DOT__system__DOT__comet__DOT__col_buffer_secondary_data_in;
    IData/*31:0*/ emu__DOT__system__DOT__comet__DOT__col_buffer_secondary_data_out;
    IData/*31:0*/ emu__DOT__system__DOT__comet__DOT__col_buffer_secondary_collisions;
    IData/*31:0*/ emu__DOT__system__DOT__comet__DOT__col_buffer_data_out_a;
    IData/*31:0*/ emu__DOT__system__DOT__comet__DOT__col_buffer_data_out_b;
    IData/*21:0*/ emu__DOT__system__DOT__stars1__DOT__RST_CNT;
    IData/*21:0*/ emu__DOT__system__DOT__stars1__DOT__seed;
    IData/*21:0*/ emu__DOT__system__DOT__stars1__DOT__sf_reg;
    IData/*21:0*/ emu__DOT__system__DOT__stars1__DOT__sf_cnt;
    IData/*20:0*/ emu__DOT__system__DOT__stars2__DOT__RST_CNT;
    IData/*20:0*/ emu__DOT__system__DOT__stars2__DOT__seed;
    IData/*20:0*/ emu__DOT__system__DOT__stars2__DOT__sf_reg;
    IData/*20:0*/ emu__DOT__system__DOT__stars2__DOT__sf_cnt;
    IData/*20:0*/ emu__DOT__system__DOT__stars3__DOT__RST_CNT;
    IData/*20:0*/ emu__DOT__system__DOT__stars3__DOT__seed;
    IData/*20:0*/ emu__DOT__system__DOT__stars3__DOT__sf_reg;
    IData/*20:0*/ emu__DOT__system__DOT__stars3__DOT__sf_cnt;
    VlUnpacked<CData/*7:0*/, 8> emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH;
    VlUnpacked<CData/*7:0*/, 8> emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL;
    VlUnpacked<CData/*7:0*/, 4> emu__DOT__system__DOT__zechs__DOT__tilemapreg;
    VlUnpacked<IData/*31:0*/, 512> emu__DOT__system__DOT__comet__DOT__spritecollisionbufferram_a__DOT__mem;
    VlUnpacked<IData/*31:0*/, 512> emu__DOT__system__DOT__comet__DOT__spritecollisionbufferram_b__DOT__mem;
    VlUnpacked<CData/*7:0*/, 32768> emu__DOT__system__DOT__pgrom__DOT__mem;
    VlUnpacked<CData/*7:0*/, 2048> emu__DOT__system__DOT__chrom__DOT__mem;
    VlUnpacked<CData/*7:0*/, 2048> emu__DOT__system__DOT__chram__DOT__mem;
    VlUnpacked<CData/*7:0*/, 2048> emu__DOT__system__DOT__fgcolram__DOT__mem;
    VlUnpacked<CData/*7:0*/, 2048> emu__DOT__system__DOT__bgcolram__DOT__mem;
    VlUnpacked<CData/*7:0*/, 1024> emu__DOT__system__DOT__tilemapram__DOT__mem;
    VlUnpacked<CData/*7:0*/, 32768> emu__DOT__system__DOT__tilemaprom__DOT__mem;
    VlUnpacked<CData/*7:0*/, 128> emu__DOT__system__DOT__spriteram__DOT__mem;
    VlUnpacked<CData/*0:0*/, 32> emu__DOT__system__DOT__spritecollisionram__DOT__mem;
    VlUnpacked<SData/*15:0*/, 1024> emu__DOT__system__DOT__spritelbram__DOT__mem;
    VlUnpacked<CData/*7:0*/, 16384> emu__DOT__system__DOT__spriterom__DOT__mem;
    VlUnpacked<CData/*7:0*/, 16384> emu__DOT__system__DOT__wkram__DOT__mem;
    VlUnpacked<CData/*7:0*/, 256> emu__DOT__system__DOT__palrom__DOT__mem;

    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ emu__DOT__system__DOT____Vcellinp__ms_timer__reset;
    CData/*0:0*/ emu__DOT__system__DOT____Vcellinp__T80x__reset_n;
    CData/*0:0*/ emu__DOT____Vcellinp__system__reset;
    CData/*0:0*/ emu__DOT__system__DOT____Vcellinp__stars1__write;
    CData/*0:0*/ emu__DOT__system__DOT____Vcellinp__stars2__write;
    CData/*0:0*/ emu__DOT__system__DOT____Vcellinp__stars3__write;
    CData/*0:0*/ emu__DOT__system__DOT____Vcellinp__spritecollisionram__wren_a;
    CData/*0:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__2__Vfuncout;
    CData/*7:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__2__FF;
    CData/*2:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__2__cc;
    CData/*0:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__Vfuncout;
    CData/*7:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__FF;
    CData/*2:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__cc;
    CData/*0:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__4__Vfuncout;
    CData/*7:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__4__FF;
    CData/*2:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__4__cc;
    CData/*0:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__5__Vfuncout;
    CData/*7:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__5__FF;
    CData/*2:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__5__cc;
    CData/*0:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__Vfuncout;
    CData/*7:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__FF;
    CData/*2:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__cc;
    CData/*0:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__7__Vfuncout;
    CData/*7:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__7__FF;
    CData/*2:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__7__cc;
    CData/*0:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__8__Vfuncout;
    CData/*7:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__8__FF;
    CData/*2:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__8__cc;
    CData/*0:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__Vfuncout;
    CData/*7:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__FF;
    CData/*2:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__cc;
    CData/*0:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__10__Vfuncout;
    CData/*7:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__10__FF;
    CData/*2:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__10__cc;
    CData/*0:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__11__Vfuncout;
    CData/*7:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__11__FF;
    CData/*2:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__11__cc;
    CData/*0:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__Vfuncout;
    CData/*7:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__FF;
    CData/*2:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__cc;
    CData/*0:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__13__Vfuncout;
    CData/*7:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__13__FF;
    CData/*2:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__13__cc;
    CData/*0:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__14__Vfuncout;
    CData/*7:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__14__FF;
    CData/*2:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__14__cc;
    CData/*0:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__Vfuncout;
    CData/*7:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__FF;
    CData/*2:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__cc;
    CData/*0:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__16__Vfuncout;
    CData/*7:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__16__FF;
    CData/*2:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__16__cc;
    CData/*0:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__17__Vfuncout;
    CData/*7:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__17__FF;
    CData/*2:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__17__cc;
    CData/*0:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__Vfuncout;
    CData/*7:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__FF;
    CData/*2:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__cc;
    CData/*0:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__19__Vfuncout;
    CData/*7:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__19__FF;
    CData/*2:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__19__cc;
    CData/*0:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__20__Vfuncout;
    CData/*7:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__20__FF;
    CData/*2:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__20__cc;
    CData/*0:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__Vfuncout;
    CData/*7:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__FF;
    CData/*2:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__cc;
    CData/*0:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__22__Vfuncout;
    CData/*7:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__22__FF;
    CData/*2:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__22__cc;
    CData/*0:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__23__Vfuncout;
    CData/*7:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__23__FF;
    CData/*2:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__23__cc;
    CData/*0:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__Vfuncout;
    CData/*7:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__FF;
    CData/*2:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__cc;
    CData/*0:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__25__Vfuncout;
    CData/*7:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__25__FF;
    CData/*2:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__25__cc;
    CData/*4:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__26__Vfuncout;
    CData/*3:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__26__A;
    CData/*3:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__26__B;
    CData/*0:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__26__Sub;
    CData/*0:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__26__Carry_In;
    CData/*4:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__27__Vfuncout;
    CData/*3:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__27__A;
    CData/*3:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__27__B;
    CData/*0:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__27__Sub;
    CData/*0:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__27__Carry_In;
    CData/*3:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__28__Vfuncout;
    CData/*2:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__28__A;
    CData/*2:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__28__B;
    CData/*0:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__28__Sub;
    CData/*0:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__28__Carry_In;
    CData/*3:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__29__Vfuncout;
    CData/*2:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__29__A;
    CData/*2:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__29__B;
    CData/*0:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__29__Sub;
    CData/*0:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__29__Carry_In;
    CData/*1:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__30__Vfuncout;
    CData/*0:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__30__A;
    CData/*0:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__30__B;
    CData/*0:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__30__Sub;
    CData/*0:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__30__Carry_In;
    CData/*1:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__31__Vfuncout;
    CData/*0:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__31__A;
    CData/*0:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__31__B;
    CData/*0:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__31__Sub;
    CData/*0:0*/ __Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__31__Carry_In;
    CData/*1:0*/ __Vdly__emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__XY_State;
    CData/*7:0*/ __Vdly__emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR;
    CData/*7:0*/ __Vdly__emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ACC;
    CData/*7:0*/ __Vdly__emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F;
    CData/*0:0*/ __Vdly__emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Alternate;
    CData/*0:0*/ __Vdly__emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IntE_FF1;
    CData/*0:0*/ __Vdly__emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IntE_FF2;
    CData/*0:0*/ __Vdly__emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Auto_Wait_t1;
    CData/*0:0*/ __Vdly__emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusAck;
    CData/*6:0*/ __Vdly__emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstate;
    CData/*2:0*/ __Vdly__emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Pre_XY_F_M;
    CData/*6:0*/ __Vdly__emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle;
    CData/*0:0*/ __Vdly__emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__NMICycle;
    CData/*0:0*/ __VinpClk__TOP__emu__DOT__system__DOT____Vcellinp__T80x__reset_n;
    CData/*0:0*/ __VinpClk__TOP__emu__DOT__system__DOT____Vcellinp__ms_timer__reset;
    CData/*0:0*/ __Vclklast__TOP__clk_sys;
    CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__emu__DOT__system__DOT____Vcellinp__T80x__reset_n;
    CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__emu__DOT__system__DOT____Vcellinp__ms_timer__reset;
    CData/*0:0*/ __Vchglast__TOP__emu__DOT__system__DOT____Vcellinp__ms_timer__reset;
    CData/*0:0*/ __Vchglast__TOP__emu__DOT__system__DOT____Vcellinp__T80x__reset_n;
    SData/*8:0*/ emu__DOT__system__DOT__comet__DOT____Vcellinp__spritecollisionbufferram_a__address;
    SData/*8:0*/ emu__DOT__system__DOT__comet__DOT____Vcellinp__spritecollisionbufferram_b__address;
    SData/*15:0*/ __Vdly__emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PC;
    SData/*15:0*/ __Vdly__emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__TmpAddr;
    SData/*15:0*/ __Vdly__emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__SP;

    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vemu__Syms* __VlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vemu);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vemu(VerilatedContext* contextp, const char* name = "TOP");
    Vemu(const char* name = "TOP")
      : Vemu(nullptr, name) {}
    /// Destroy the model; called (often implicitly) by application code
    ~Vemu();

    // API METHODS
    /// Return current simulation context for this model.
    /// Used to get to e.g. simulation time via contextp()->time()
    VerilatedContext* contextp();
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();

    // INTERNAL METHODS
    static void _eval_initial_loop(Vemu__Syms* __restrict vlSymsp);
    void __Vconfigure(Vemu__Syms* symsp, bool first);
  private:
    static QData _change_request(Vemu__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vemu__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__11(Vemu__Syms* __restrict vlSymsp);
    static void _combo__TOP__14(Vemu__Syms* __restrict vlSymsp);
    static void _combo__TOP__8(Vemu__Syms* __restrict vlSymsp);
  private:
    static void _ctor_var_reset(Vemu* self) VL_ATTR_COLD;
  public:
    static void _eval(Vemu__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vemu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vemu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vemu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__10(Vemu__Syms* __restrict vlSymsp);
    static void _sequent__TOP__12(Vemu__Syms* __restrict vlSymsp);
    static void _sequent__TOP__13(Vemu__Syms* __restrict vlSymsp);
    static void _sequent__TOP__4(Vemu__Syms* __restrict vlSymsp);
    static void _sequent__TOP__5(Vemu__Syms* __restrict vlSymsp);
    static void _sequent__TOP__6(Vemu__Syms* __restrict vlSymsp);
    static void _sequent__TOP__7(Vemu__Syms* __restrict vlSymsp);
    static void _sequent__TOP__9(Vemu__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vemu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _settle__TOP__3(Vemu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
