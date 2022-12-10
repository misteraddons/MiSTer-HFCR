// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vemu.h for the primary calling header

#include "Vemu.h"
#include "Vemu__Syms.h"

void Vemu::_settle__TOP__3(Vemu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu::_settle__TOP__3\n"); );
    Vemu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VlWide<6>/*191:0*/ __Vtemp11;
    VlWide<3>/*95:0*/ __Vtemp12;
    VlWide<3>/*95:0*/ __Vtemp13;
    VlWide<3>/*95:0*/ __Vtemp14;
    // Body
    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 3U;
    }
    if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
            = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS;
        if (((0x36U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)) 
             | (0xcbU == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 7U;
        }
    }
    if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
        if ((1U != (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
        }
        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
            = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS;
    }
    vlTOPp->emu__DOT__pause_cpu = (((IData)(vlTOPp->emu__DOT__pause__DOT__pause_request) 
                                    | (IData)(vlTOPp->emu__DOT__pause__DOT__pause_toggle)) 
                                   & (~ (IData)(vlTOPp->reset)));
    vlTOPp->VGA_HB = (1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT___hb)));
    vlTOPp->VGA_VB = (1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT___vb)));
    vlTOPp->emu__DOT__system__DOT__chram_addr = ((0xfc0U 
                                                  & ((IData)(vlTOPp->emu__DOT__system__DOT__vcnt) 
                                                     << 3U)) 
                                                 | (0x3fU 
                                                    & ((IData)(vlTOPp->emu__DOT__system__DOT__hcnt) 
                                                       >> 3U)));
    vlTOPp->emu__DOT__system__DOT__casval__DOT__char_a 
        = (1U & ((IData)(vlTOPp->emu__DOT__system__DOT__chrom_data_out) 
                 >> (7U & ((IData)(7U) - (IData)(vlTOPp->emu__DOT__system__DOT__hcnt)))));
    vlTOPp->AUDIO_R = vlTOPp->AUDIO_L;
    vlTOPp->AUDIO_R = vlTOPp->AUDIO_L;
    vlTOPp->emu__DOT__system__DOT__rgb_starfield = 
        (0xffffffU & ((((((IData)(vlTOPp->emu__DOT__system__DOT__sf_on1) 
                          | (IData)(vlTOPp->emu__DOT__system__DOT__sf_on2)) 
                         | (IData)(vlTOPp->emu__DOT__system__DOT__sf_on3))
                         ? (0xffU & ((IData)(vlTOPp->emu__DOT__system__DOT__sf_on1)
                                      ? vlTOPp->emu__DOT__system__DOT__stars1__DOT__sf_reg
                                      : ((IData)(vlTOPp->emu__DOT__system__DOT__sf_on2)
                                          ? (0x7fU 
                                             & vlTOPp->emu__DOT__system__DOT__stars2__DOT__sf_reg)
                                          : ((IData)(vlTOPp->emu__DOT__system__DOT__sf_on3)
                                              ? (0x3fU 
                                                 & vlTOPp->emu__DOT__system__DOT__stars3__DOT__sf_reg)
                                              : 0U))))
                         : 0U) << 0x10U) | ((((((IData)(vlTOPp->emu__DOT__system__DOT__sf_on1) 
                                                | (IData)(vlTOPp->emu__DOT__system__DOT__sf_on2)) 
                                               | (IData)(vlTOPp->emu__DOT__system__DOT__sf_on3))
                                               ? (0xffU 
                                                  & ((IData)(vlTOPp->emu__DOT__system__DOT__sf_on1)
                                                      ? vlTOPp->emu__DOT__system__DOT__stars1__DOT__sf_reg
                                                      : 
                                                     ((IData)(vlTOPp->emu__DOT__system__DOT__sf_on2)
                                                       ? 
                                                      (0x7fU 
                                                       & vlTOPp->emu__DOT__system__DOT__stars2__DOT__sf_reg)
                                                       : 
                                                      ((IData)(vlTOPp->emu__DOT__system__DOT__sf_on3)
                                                        ? 
                                                       (0x3fU 
                                                        & vlTOPp->emu__DOT__system__DOT__stars3__DOT__sf_reg)
                                                        : 0U))))
                                               : 0U) 
                                             << 8U) 
                                            | ((((IData)(vlTOPp->emu__DOT__system__DOT__sf_on1) 
                                                 | (IData)(vlTOPp->emu__DOT__system__DOT__sf_on2)) 
                                                | (IData)(vlTOPp->emu__DOT__system__DOT__sf_on3))
                                                ? (0xffU 
                                                   & ((IData)(vlTOPp->emu__DOT__system__DOT__sf_on1)
                                                       ? vlTOPp->emu__DOT__system__DOT__stars1__DOT__sf_reg
                                                       : 
                                                      ((IData)(vlTOPp->emu__DOT__system__DOT__sf_on2)
                                                        ? 
                                                       (0x7fU 
                                                        & vlTOPp->emu__DOT__system__DOT__stars2__DOT__sf_reg)
                                                        : 
                                                       ((IData)(vlTOPp->emu__DOT__system__DOT__sf_on3)
                                                         ? 
                                                        (0x3fU 
                                                         & vlTOPp->emu__DOT__system__DOT__stars3__DOT__sf_reg)
                                                         : 0U))))
                                                : 0U))));
    vlTOPp->emu__DOT__system__DOT____Vcellinp__ms_timer__reset 
        = ((IData)(vlTOPp->emu__DOT____Vcellinp__system__reset) 
           | ((0x89U == (0xffU & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                  >> 8U))) & (~ (IData)(vlTOPp->emu__DOT__system__DOT__cpu_wr_n))));
    vlTOPp->emu__DOT__system__DOT____Vcellinp__T80x__reset_n 
        = (1U & (~ (IData)(vlTOPp->emu__DOT____Vcellinp__system__reset)));
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegAddrB 
        = (((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ExchangeDH) 
            & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstate) 
               >> 3U)) ? (1U | ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Alternate) 
                                << 2U)) : (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegAddrB_r));
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t = 0U;
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q = 0U;
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
        = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F;
    if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op_r))) {
        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op_r))) {
            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op_r))) {
                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op_r)))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                        = ((0xf0U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusA)) 
                           | (0xfU & ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op_r))
                                       ? ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusB) 
                                          >> 4U) : (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusB))));
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                        = (0xefU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out));
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                        = (0xfdU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out));
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                        = ((0xf7U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                           | (8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)));
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                        = ((0x1fU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                           | ((0x80U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)) 
                              | (((0U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)) 
                                  << 6U) | (0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)))));
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                        = ((0xfbU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                           | (4U & ((~ VL_REDXOR_32((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t))) 
                                    << 2U)));
                }
            } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op_r))) {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                    = ((0xf0U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusA)) 
                       | (0xfU & ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op_r))
                                   ? ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusB) 
                                      >> 4U) : (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusB))));
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                    = (0xefU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out));
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                    = (0xfdU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out));
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                    = ((0xf7U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                       | (8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)));
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                    = ((0x1fU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                       | ((0x80U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)) 
                          | (((0U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)) 
                              << 6U) | (0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)))));
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                    = ((0xfbU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                       | (4U & ((~ VL_REDXOR_32((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t))) 
                                << 2U)));
            } else {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                    = ((0xefU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                       | (0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F)));
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                    = ((0xfeU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                       | (1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F)));
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q 
                    = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusA;
                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F))) {
                    if ((1U & ((9U < (0xfU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q))) 
                               | ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F) 
                                  >> 4U)))) {
                        if ((5U < (0xfU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q)))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                                = (0xefU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out));
                        }
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q 
                            = ((0x100U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q)) 
                               | (0xffU & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q) 
                                           - (IData)(6U))));
                    }
                    if ((1U & ((0x99U < (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusA)) 
                               | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F)))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q 
                            = (0x1ffU & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q) 
                                         - (IData)(0x160U)));
                    }
                } else {
                    if ((1U & ((9U < (0xfU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q))) 
                               | ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F) 
                                  >> 4U)))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                            = ((0xefU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                               | ((9U < (0xfU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q))) 
                                  << 4U));
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q 
                            = (0x1ffU & ((IData)(6U) 
                                         + (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q)));
                    }
                    if ((1U & ((9U < (0x1fU & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q) 
                                               >> 4U))) 
                               | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F)))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q 
                            = (0x1ffU & ((IData)(0x60U) 
                                         + (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q)));
                    }
                }
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                    = ((0xf7U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                       | (8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q)));
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                    = ((0xdfU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                       | (0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q)));
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                    = ((0xfeU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                       | (1U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F) 
                                | ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q) 
                                   >> 8U))));
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                    = (0xffU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q));
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                    = ((0x3fU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                       | ((0x80U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q)) 
                          | ((0U == (0xffU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q))) 
                             << 6U)));
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                    = ((0xfbU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                       | (4U & ((~ VL_REDXOR_32((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q))) 
                                << 2U)));
            }
        } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op_r))) {
            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                = ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op_r))
                    ? ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusB) 
                       & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__BitMask)))
                    : ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusB) 
                       | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__BitMask)));
        } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op_r))) {
            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                = ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusB) 
                   & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__BitMask));
            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                = ((0x7fU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                   | (0x80U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)));
            if ((0U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t))) {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                    = (0x40U | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out));
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                    = (4U | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out));
            } else {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                    = (0xbfU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out));
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                    = (0xfbU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out));
            }
            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                = (0x10U | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out));
            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                = (0xfdU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out));
            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                = (0xf7U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out));
            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                = (0xdfU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out));
            if ((6U != (7U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                    = ((0xf7U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                       | (8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusB)));
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                    = ((0xdfU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                       | (0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusB)));
            }
        } else {
            if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                            = (0x7fU & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusA) 
                                        >> 1U));
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                            = ((0xfeU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                               | (1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusA)));
                    } else {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                            = (1U | (0xfeU & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusA) 
                                              << 1U)));
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                            = ((0xfeU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                               | (1U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusA) 
                                        >> 7U)));
                    }
                } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                        = ((0x80U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusA)) 
                           | (0x7fU & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusA) 
                                       >> 1U)));
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                        = ((0xfeU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                           | (1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusA)));
                } else {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                        = (0xfeU & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusA) 
                                    << 1U));
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                        = ((0xfeU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                           | (1U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusA) 
                                    >> 7U)));
                }
            } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                        = ((0x80U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F) 
                                     << 7U)) | (0x7fU 
                                                & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusA) 
                                                   >> 1U)));
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                        = ((0xfeU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                           | (1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusA)));
                } else {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                        = ((0xfeU & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusA) 
                                     << 1U)) | (1U 
                                                & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F)));
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                        = ((0xfeU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                           | (1U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusA) 
                                    >> 7U)));
                }
            } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                    = ((0x80U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusA) 
                                 << 7U)) | (0x7fU & 
                                            ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusA) 
                                             >> 1U)));
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                    = ((0xfeU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                       | (1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusA)));
            } else {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                    = ((0xfeU & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusA) 
                                 << 1U)) | (1U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusA) 
                                                  >> 7U)));
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                    = ((0xfeU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                       | (1U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusA) 
                                >> 7U)));
            }
            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                = (0xefU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out));
            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                = (0xfdU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out));
            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                = ((0xf7U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                   | (8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)));
            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                = ((0x1fU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                   | ((0x80U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)) 
                      | (((0U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)) 
                          << 6U) | (0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)))));
            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                = ((0xfbU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                   | (4U & ((~ VL_REDXOR_32((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t))) 
                            << 2U)));
            if ((0U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                    = ((0xfbU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                       | (4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F)));
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                    = ((0x3fU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                       | (0xc0U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F)));
            }
        }
    } else {
        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
            = (0xfcU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out));
        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op_r))) {
            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op_r))) {
                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op_r))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                        = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_v;
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                        = ((0xfcU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                           | (2U | (1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Carry_v)))));
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                        = ((0xefU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                           | (0x10U & ((~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__HalfCarry_v)) 
                                       << 4U)));
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                        = ((0xfbU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                           | ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__OverFlow_v) 
                              << 2U));
                } else {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                        = ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusA) 
                           | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusB));
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                        = (0xefU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out));
                }
            } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op_r))) {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                    = ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusA) 
                       ^ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusB));
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                    = (0xefU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out));
            } else {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                    = ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusA) 
                       & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusB));
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                    = (0x10U | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out));
            }
        } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op_r))) {
            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_v;
            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                = ((0xfcU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                   | (2U | (1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Carry_v)))));
            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                = ((0xefU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                   | (0x10U & ((~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__HalfCarry_v)) 
                               << 4U)));
            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                = ((0xfbU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                   | ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__OverFlow_v) 
                      << 2U));
        } else {
            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t 
                = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_v;
            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                = ((0xfeU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                   | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Carry_v));
            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                = ((0xefU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                   | ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__HalfCarry_v) 
                      << 4U));
            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                = ((0xfbU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                   | ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__OverFlow_v) 
                      << 2U));
        }
        if ((7U == (7U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op_r)))) {
            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                = ((0xf7U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                   | (8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusB)));
            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                = ((0xdfU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                   | (0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusB)));
        } else {
            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                = ((0xf7U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                   | (8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)));
            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                = ((0xdfU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                   | (0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)));
        }
        if ((0U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t))) {
            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                = (0x40U | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out));
            if (vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Z16_r) {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                    = ((0xbfU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                       | (0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F)));
            }
        } else {
            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                = (0xbfU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out));
        }
        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
            = ((0x7fU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
               | (0x80U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t)));
        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op_r))) {
            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op_r))) {
                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op_r)))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                        = ((0xfbU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                           | (4U & ((~ VL_REDXOR_32((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t))) 
                                    << 2U)));
                }
            } else {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                    = ((0xfbU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                       | (4U & ((~ VL_REDXOR_32((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t))) 
                                << 2U)));
            }
        }
        if (vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Arith16_r) {
            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                = ((0x3fU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                   | (0xc0U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F)));
            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out 
                = ((0xfbU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out)) 
                   | (4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F)));
        }
    }
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Q 
        = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t;
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PC16_B 
        = ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__JumpE)
            ? ((0xff00U & ((- (IData)((1U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__di_reg) 
                                             >> 7U)))) 
                           << 8U)) | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__di_reg))
            : ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BTR_r)
                ? 0xfffeU : 1U));
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PC16 
        = (0xffffU & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PC) 
                      + (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PC16_B)));
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__last_tstate 
        = (1U & ((0U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates))
                  ? (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstate)
                  : ((1U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates))
                      ? ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstate) 
                         >> 1U) : ((2U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates))
                                    ? ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstate) 
                                       >> 2U) : ((3U 
                                                  == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates))
                                                  ? 
                                                 ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstate) 
                                                  >> 3U)
                                                  : 
                                                 ((4U 
                                                   == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates))
                                                   ? 
                                                  ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstate) 
                                                   >> 4U)
                                                   : 
                                                  ((5U 
                                                    == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates))
                                                    ? 
                                                   ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstate) 
                                                    >> 5U)
                                                    : 
                                                   ((6U 
                                                     == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates)) 
                                                    & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstate) 
                                                       >> 6U)))))))));
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__NextIs_XY_Fetch 
        = (((0U != (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__XY_State)) 
            & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__XY_Ind))) 
           & (((2U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To)) 
               | ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                  & (0xcbU == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) 
              | ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                 & (0x36U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))));
    if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstate))) {
        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__SP16_A 
            = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegBusC;
        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__SP16_B 
            = ((0xff00U & ((- (IData)((1U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__di_reg) 
                                             >> 7U)))) 
                           << 8U)) | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__di_reg));
    } else {
        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__SP16_A 
            = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__SP;
        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__SP16_B 
            = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16))
                ? 0xffffU : 1U);
    }
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__SP16 
        = (0xffffU & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__SP16_A) 
                      + (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__SP16_B)));
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegAddrA 
        = (((((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstate) 
              >> 2U) | ((((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstate) 
                          >> 3U) & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)) 
                        & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16) 
                           >> 2U))) & (0U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__XY_State)))
            ? (((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Alternate) 
                << 2U) | (3U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16)))
            : (((((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstate) 
                  >> 2U) | ((((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstate) 
                              >> 3U) & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)) 
                            & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16) 
                               >> 2U))) & (2U == (3U 
                                                  & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16))))
                ? (3U | (4U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__XY_State) 
                               << 1U))) : (((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ExchangeDH) 
                                            & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstate) 
                                               >> 3U))
                                            ? (2U | 
                                               ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Alternate) 
                                                << 2U))
                                            : (((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ExchangeDH) 
                                                & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstate) 
                                                   >> 4U))
                                                ? (1U 
                                                   | ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Alternate) 
                                                      << 2U))
                                                : (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegAddrA_r)))));
    vlTOPp->emu__DOT__system__DOT__pause_system = ((IData)(vlTOPp->emu__DOT__pause_cpu) 
                                                   | (IData)(vlTOPp->emu__DOT__system__DOT__pause_trigger));
    __Vtemp11[0U] = vlTOPp->joystick_0;
    __Vtemp11[1U] = vlTOPp->joystick_1;
    __Vtemp11[2U] = vlTOPp->joystick_2;
    __Vtemp11[3U] = vlTOPp->joystick_3;
    __Vtemp11[4U] = (IData)((((QData)((IData)(vlTOPp->joystick_5)) 
                              << 0x20U) | (QData)((IData)(vlTOPp->joystick_4))));
    __Vtemp11[5U] = (IData)(((((QData)((IData)(vlTOPp->joystick_5)) 
                               << 0x20U) | (QData)((IData)(vlTOPp->joystick_4))) 
                             >> 0x20U));
    __Vtemp12[0U] = (((IData)(vlTOPp->joystick_l_analog_1) 
                      << 0x10U) | (IData)(vlTOPp->joystick_l_analog_0));
    __Vtemp12[1U] = (IData)((((QData)((IData)((((IData)(vlTOPp->joystick_l_analog_5) 
                                                << 0x10U) 
                                               | (IData)(vlTOPp->joystick_l_analog_4)))) 
                              << 0x20U) | (QData)((IData)(
                                                          (((IData)(vlTOPp->joystick_l_analog_3) 
                                                            << 0x10U) 
                                                           | (IData)(vlTOPp->joystick_l_analog_2))))));
    __Vtemp12[2U] = (IData)(((((QData)((IData)((((IData)(vlTOPp->joystick_l_analog_5) 
                                                 << 0x10U) 
                                                | (IData)(vlTOPp->joystick_l_analog_4)))) 
                               << 0x20U) | (QData)((IData)(
                                                           (((IData)(vlTOPp->joystick_l_analog_3) 
                                                             << 0x10U) 
                                                            | (IData)(vlTOPp->joystick_l_analog_2))))) 
                             >> 0x20U));
    __Vtemp13[0U] = (((IData)(vlTOPp->joystick_r_analog_1) 
                      << 0x10U) | (IData)(vlTOPp->joystick_r_analog_0));
    __Vtemp13[1U] = (IData)((((QData)((IData)((((IData)(vlTOPp->joystick_r_analog_5) 
                                                << 0x10U) 
                                               | (IData)(vlTOPp->joystick_r_analog_4)))) 
                              << 0x20U) | (QData)((IData)(
                                                          (((IData)(vlTOPp->joystick_r_analog_3) 
                                                            << 0x10U) 
                                                           | (IData)(vlTOPp->joystick_r_analog_2))))));
    __Vtemp13[2U] = (IData)(((((QData)((IData)((((IData)(vlTOPp->joystick_r_analog_5) 
                                                 << 0x10U) 
                                                | (IData)(vlTOPp->joystick_r_analog_4)))) 
                               << 0x20U) | (QData)((IData)(
                                                           (((IData)(vlTOPp->joystick_r_analog_3) 
                                                             << 0x10U) 
                                                            | (IData)(vlTOPp->joystick_r_analog_2))))) 
                             >> 0x20U));
    __Vtemp14[0U] = (((IData)(vlTOPp->spinner_1) << 0x10U) 
                     | (IData)(vlTOPp->spinner_0));
    __Vtemp14[1U] = (IData)((((QData)((IData)((((IData)(vlTOPp->spinner_5) 
                                                << 0x10U) 
                                               | (IData)(vlTOPp->spinner_4)))) 
                              << 0x20U) | (QData)((IData)(
                                                          (((IData)(vlTOPp->spinner_3) 
                                                            << 0x10U) 
                                                           | (IData)(vlTOPp->spinner_2))))));
    __Vtemp14[2U] = (IData)(((((QData)((IData)((((IData)(vlTOPp->spinner_5) 
                                                 << 0x10U) 
                                                | (IData)(vlTOPp->spinner_4)))) 
                               << 0x20U) | (QData)((IData)(
                                                           (((IData)(vlTOPp->spinner_3) 
                                                             << 0x10U) 
                                                            | (IData)(vlTOPp->spinner_2))))) 
                             >> 0x20U));
    vlTOPp->emu__DOT__system__DOT__cpu_din = (0xffU 
                                              & ((0x8000U 
                                                  & (IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr))
                                                  ? 
                                                 ((3U 
                                                   == 
                                                   (3U 
                                                    & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                       >> 0xeU)))
                                                   ? (IData)(vlTOPp->emu__DOT__system__DOT__wkram_data_out)
                                                   : 
                                                  ((0x13U 
                                                    == 
                                                    (0x1fU 
                                                     & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                        >> 0xbU)))
                                                    ? (IData)(vlTOPp->emu__DOT__system__DOT__chram_data_out)
                                                    : 
                                                   ((0x14U 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                         >> 0xbU)))
                                                     ? (IData)(vlTOPp->emu__DOT__system__DOT__fgcolram_data_out)
                                                     : 
                                                    ((0x15U 
                                                      == 
                                                      (0x1fU 
                                                       & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                          >> 0xbU)))
                                                      ? (IData)(vlTOPp->emu__DOT__system__DOT__bgcolram_data_out)
                                                      : 
                                                     ((0xb4U 
                                                       == 
                                                       (0xffU 
                                                        & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                           >> 8U)))
                                                       ? 
                                                      (- (IData)((IData)(vlTOPp->emu__DOT__system__DOT__spritecollisionram_data_out_cpu)))
                                                       : 
                                                      ((0x8000U 
                                                        == (IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr))
                                                        ? 
                                                       (9U 
                                                        | (((IData)(vlTOPp->VGA_HS) 
                                                            << 7U) 
                                                           | (((IData)(vlTOPp->VGA_VS) 
                                                               << 6U) 
                                                              | (((IData)(vlTOPp->VGA_HB) 
                                                                  << 5U) 
                                                                 | (((IData)(vlTOPp->VGA_VB) 
                                                                     << 4U) 
                                                                    | ((IData)(vlTOPp->menu) 
                                                                       << 1U))))))
                                                        : 
                                                       ((0x81U 
                                                         == 
                                                         (0xffU 
                                                          & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                             >> 8U)))
                                                         ? 
                                                        ((0xbfU 
                                                          >= 
                                                          (0xf8U 
                                                           & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                              << 3U)))
                                                          ? 
                                                         (((0U 
                                                            == 
                                                            (0x18U 
                                                             & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                                << 3U)))
                                                            ? 0U
                                                            : 
                                                           (__Vtemp11[
                                                            ((IData)(1U) 
                                                             + 
                                                             (7U 
                                                              & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                                 >> 2U)))] 
                                                            << 
                                                            ((IData)(0x20U) 
                                                             - 
                                                             (0x18U 
                                                              & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                                 << 3U))))) 
                                                          | (__Vtemp11[
                                                             (7U 
                                                              & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                                 >> 2U))] 
                                                             >> 
                                                             (0x18U 
                                                              & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                                 << 3U))))
                                                          : 0U)
                                                         : 
                                                        ((0x82U 
                                                          == 
                                                          (0xffU 
                                                           & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                              >> 8U)))
                                                          ? 
                                                         ((0x5fU 
                                                           >= 
                                                           (0x78U 
                                                            & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                               << 3U)))
                                                           ? 
                                                          (((0U 
                                                             == 
                                                             (0x18U 
                                                              & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                                 << 3U)))
                                                             ? 0U
                                                             : 
                                                            (__Vtemp12[
                                                             ((IData)(1U) 
                                                              + 
                                                              (3U 
                                                               & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                                  >> 2U)))] 
                                                             << 
                                                             ((IData)(0x20U) 
                                                              - 
                                                              (0x18U 
                                                               & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                                  << 3U))))) 
                                                           | (__Vtemp12[
                                                              (3U 
                                                               & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                                  >> 2U))] 
                                                              >> 
                                                              (0x18U 
                                                               & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                                  << 3U))))
                                                           : 0U)
                                                          : 
                                                         ((0x83U 
                                                           == 
                                                           (0xffU 
                                                            & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                               >> 8U)))
                                                           ? 
                                                          ((0x5fU 
                                                            >= 
                                                            (0x78U 
                                                             & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                                << 3U)))
                                                            ? 
                                                           (((0U 
                                                              == 
                                                              (0x18U 
                                                               & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                                  << 3U)))
                                                              ? 0U
                                                              : 
                                                             (__Vtemp13[
                                                              ((IData)(1U) 
                                                               + 
                                                               (3U 
                                                                & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                                   >> 2U)))] 
                                                              << 
                                                              ((IData)(0x20U) 
                                                               - 
                                                               (0x18U 
                                                                & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                                   << 3U))))) 
                                                            | (__Vtemp13[
                                                               (3U 
                                                                & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                                   >> 2U))] 
                                                               >> 
                                                               (0x18U 
                                                                & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                                   << 3U))))
                                                            : 0U)
                                                           : 
                                                          ((0x44U 
                                                            == 
                                                            (0xffU 
                                                             & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                                >> 8U)))
                                                            ? 
                                                           ((0x2fU 
                                                             >= 
                                                             (0x38U 
                                                              & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                                 << 3U)))
                                                             ? (IData)(
                                                                       ((((QData)((IData)(
                                                                                (((IData)(vlTOPp->paddle_5) 
                                                                                << 0x18U) 
                                                                                | (((IData)(vlTOPp->paddle_4) 
                                                                                << 0x10U) 
                                                                                | (((IData)(vlTOPp->paddle_3) 
                                                                                << 8U) 
                                                                                | (IData)(vlTOPp->paddle_2)))))) 
                                                                          << 0x10U) 
                                                                         | (QData)((IData)(
                                                                                (((IData)(vlTOPp->paddle_1) 
                                                                                << 8U) 
                                                                                | (IData)(vlTOPp->paddle_0))))) 
                                                                        >> 
                                                                        (0x38U 
                                                                         & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                                            << 3U))))
                                                             : 0U)
                                                            : 
                                                           ((0x85U 
                                                             == 
                                                             (0xffU 
                                                              & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                                 >> 8U)))
                                                             ? 
                                                            ((0x5fU 
                                                              >= 
                                                              (0x78U 
                                                               & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                                  << 3U)))
                                                              ? 
                                                             (((0U 
                                                                == 
                                                                (0x18U 
                                                                 & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                                    << 3U)))
                                                                ? 0U
                                                                : 
                                                               (__Vtemp14[
                                                                ((IData)(1U) 
                                                                 + 
                                                                 (3U 
                                                                  & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                                     >> 2U)))] 
                                                                << 
                                                                ((IData)(0x20U) 
                                                                 - 
                                                                 (0x18U 
                                                                  & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                                     << 3U))))) 
                                                              | (__Vtemp14[
                                                                 (3U 
                                                                  & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                                     >> 2U))] 
                                                                 >> 
                                                                 (0x18U 
                                                                  & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                                     << 3U))))
                                                              : 0U)
                                                             : 
                                                            ((0x86U 
                                                              == 
                                                              (0xffU 
                                                               & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                                  >> 8U)))
                                                              ? 
                                                             ((0xaU 
                                                               >= 
                                                               (8U 
                                                                & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                                   << 3U)))
                                                               ? 
                                                              ((IData)(vlTOPp->ps2_key) 
                                                               >> 
                                                               (8U 
                                                                & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                                   << 3U)))
                                                               : 0U)
                                                              : 
                                                             ((0x87U 
                                                               == 
                                                               (0xffU 
                                                                & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                                   >> 8U)))
                                                               ? 
                                                              ((0x2fU 
                                                                >= 
                                                                (0x38U 
                                                                 & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                                    << 3U)))
                                                                ? (IData)(
                                                                          ((((QData)((IData)(vlTOPp->ps2_mouse_ext)) 
                                                                             << 0x20U) 
                                                                            | (QData)((IData)(vlTOPp->ps2_mouse))) 
                                                                           >> 
                                                                           (0x38U 
                                                                            & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                                               << 3U))))
                                                                : 0U)
                                                               : 
                                                              ((0x88U 
                                                                == 
                                                                (0xffU 
                                                                 & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                                    >> 8U)))
                                                                ? 
                                                               ((0x20U 
                                                                 >= 
                                                                 (0x38U 
                                                                  & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                                     << 3U)))
                                                                 ? (IData)(
                                                                           (vlTOPp->timestamp 
                                                                            >> 
                                                                            (0x38U 
                                                                             & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                                                << 3U))))
                                                                 : 0U)
                                                                : 
                                                               ((0x89U 
                                                                 == 
                                                                 (0xffU 
                                                                  & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                                     >> 8U)))
                                                                 ? 
                                                                ((IData)(vlTOPp->emu__DOT__system__DOT__timer) 
                                                                 >> 
                                                                 (8U 
                                                                  & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                                     << 3U)))
                                                                 : 
                                                                ((0x2300U 
                                                                  == 
                                                                  (0x3fffU 
                                                                   & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                                      >> 2U)))
                                                                  ? 
                                                                 vlTOPp->emu__DOT__system__DOT__zechs__DOT__tilemapreg
                                                                 [
                                                                 (3U 
                                                                  & (IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr))]
                                                                  : 
                                                                 ((0x8b1U 
                                                                   == 
                                                                   (0xfffU 
                                                                    & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                                       >> 4U)))
                                                                   ? (IData)(vlTOPp->emu__DOT__system__DOT__music_data_out)
                                                                   : 
                                                                  ((0x8a31U 
                                                                    == (IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr))
                                                                    ? 
                                                                   (- (IData)((IData)(vlTOPp->emu__DOT__system__DOT__menu_trigger)))
                                                                    : 0U))))))))))))))))))
                                                  : (IData)(vlTOPp->emu__DOT__system__DOT__pgrom_data_out)));
    vlTOPp->emu__DOT__system__DOT__charmap_a = ((IData)(vlTOPp->emu__DOT__system__DOT__casval__DOT__char_a)
                                                 ? (IData)(vlTOPp->emu__DOT__system__DOT__casval__DOT__char_a)
                                                 : 
                                                (0xc7U 
                                                 != (IData)(vlTOPp->emu__DOT__system__DOT__bgcolram_data_out)));
    vlTOPp->emu__DOT__system__DOT__rgb_charmap = ((0xfc0000U 
                                                   & ((0xc00000U 
                                                       & (((IData)(vlTOPp->emu__DOT__system__DOT__casval__DOT__char_a)
                                                            ? 
                                                           ((IData)(vlTOPp->emu__DOT__system__DOT__fgcolram_data_out) 
                                                            >> 6U)
                                                            : 
                                                           ((IData)(vlTOPp->emu__DOT__system__DOT__bgcolram_data_out) 
                                                            >> 6U)) 
                                                          << 0x16U)) 
                                                      | ((0x300000U 
                                                          & (((IData)(vlTOPp->emu__DOT__system__DOT__casval__DOT__char_a)
                                                               ? 
                                                              ((IData)(vlTOPp->emu__DOT__system__DOT__fgcolram_data_out) 
                                                               >> 6U)
                                                               : 
                                                              ((IData)(vlTOPp->emu__DOT__system__DOT__bgcolram_data_out) 
                                                               >> 6U)) 
                                                             << 0x14U)) 
                                                         | (0xc0000U 
                                                            & (((IData)(vlTOPp->emu__DOT__system__DOT__casval__DOT__char_a)
                                                                 ? 
                                                                ((IData)(vlTOPp->emu__DOT__system__DOT__fgcolram_data_out) 
                                                                 >> 6U)
                                                                 : 
                                                                ((IData)(vlTOPp->emu__DOT__system__DOT__bgcolram_data_out) 
                                                                 >> 6U)) 
                                                               << 0x12U))))) 
                                                  | ((0xfc00U 
                                                      & ((0xe000U 
                                                          & (((IData)(vlTOPp->emu__DOT__system__DOT__casval__DOT__char_a)
                                                               ? 
                                                              ((IData)(vlTOPp->emu__DOT__system__DOT__fgcolram_data_out) 
                                                               >> 3U)
                                                               : 
                                                              ((IData)(vlTOPp->emu__DOT__system__DOT__bgcolram_data_out) 
                                                               >> 3U)) 
                                                             << 0xdU)) 
                                                         | (0x1c00U 
                                                            & (((IData)(vlTOPp->emu__DOT__system__DOT__casval__DOT__char_a)
                                                                 ? 
                                                                ((IData)(vlTOPp->emu__DOT__system__DOT__fgcolram_data_out) 
                                                                 >> 3U)
                                                                 : 
                                                                ((IData)(vlTOPp->emu__DOT__system__DOT__bgcolram_data_out) 
                                                                 >> 3U)) 
                                                               << 0xaU)))) 
                                                     | (0xfcU 
                                                        & ((0xe0U 
                                                            & (((IData)(vlTOPp->emu__DOT__system__DOT__casval__DOT__char_a)
                                                                 ? (IData)(vlTOPp->emu__DOT__system__DOT__fgcolram_data_out)
                                                                 : (IData)(vlTOPp->emu__DOT__system__DOT__bgcolram_data_out)) 
                                                               << 5U)) 
                                                           | (0x1cU 
                                                              & (((IData)(vlTOPp->emu__DOT__system__DOT__casval__DOT__char_a)
                                                                   ? (IData)(vlTOPp->emu__DOT__system__DOT__fgcolram_data_out)
                                                                   : (IData)(vlTOPp->emu__DOT__system__DOT__bgcolram_data_out)) 
                                                                 << 2U))))));
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegBusB 
        = ((vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH
            [vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegAddrB] 
            << 8U) | vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL
           [vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegAddrB]);
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_Mux 
        = ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ExchangeRp)
            ? (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusB)
            : ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU_r)
                ? (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Q)
                : (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__di_reg)));
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegBusA 
        = ((vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH
            [vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegAddrA] 
            << 8U) | vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL
           [vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegAddrA]);
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegWEH = 0U;
    if ((1U & (((((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstate) 
                  >> 1U) & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU_r))) 
                & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Auto_Wait_t1))) 
               | ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU_r) 
                  & (7U != (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op_r)))))) {
        if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg_r))) {
            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg_r) 
                          >> 3U)))) {
                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg_r))) {
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg_r) 
                                  >> 1U)))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegWEH 
                            = (1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg_r)));
                    }
                } else {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegWEH 
                        = (1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg_r)));
                }
            }
        }
    }
    if (((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ExchangeDH) 
         & (IData)((0U != (0x18U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstate)))))) {
        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegWEH = 1U;
    }
    if ((1U & (((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16) 
                >> 2U) & (((((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstate) 
                             >> 2U) & (~ (IData)(vlTOPp->emu__DOT__system__DOT__pause_system))) 
                           & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) 
                          | (((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstate) 
                              >> 3U) & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))))) {
        if ((((0U == (3U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16))) 
              | (1U == (3U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16)))) 
             | (2U == (3U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16))))) {
            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegWEH = 1U;
        }
    }
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegWEL = 0U;
    if ((1U & (((((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstate) 
                  >> 1U) & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU_r))) 
                & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Auto_Wait_t1))) 
               | ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU_r) 
                  & (7U != (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op_r)))))) {
        if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg_r))) {
            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg_r) 
                          >> 3U)))) {
                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg_r))) {
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg_r) 
                                  >> 1U)))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegWEL 
                            = (1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg_r));
                    }
                } else {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegWEL 
                        = (1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg_r));
                }
            }
        }
    }
    if (((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ExchangeDH) 
         & (IData)((0U != (0x18U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstate)))))) {
        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegWEL = 1U;
    }
    if ((1U & (((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16) 
                >> 2U) & (((((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstate) 
                             >> 2U) & (~ (IData)(vlTOPp->emu__DOT__system__DOT__pause_system))) 
                           & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) 
                          | (((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstate) 
                              >> 3U) & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))))) {
        if ((((0U == (3U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16))) 
              | (1U == (3U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16)))) 
             | (2U == (3U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16))))) {
            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegWEL = 1U;
        }
    }
    vlTOPp->emu__DOT__system__DOT__rgb_final = ((1U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__video_control))
                                                 ? 
                                                ((0x8000U 
                                                  & (IData)(vlTOPp->emu__DOT__system__DOT__spritelbram_data_out))
                                                  ? vlTOPp->emu__DOT__system__DOT__rgb_sprite
                                                  : 
                                                 ((IData)(vlTOPp->emu__DOT__system__DOT__charmap_a)
                                                   ? vlTOPp->emu__DOT__system__DOT__rgb_charmap
                                                   : 
                                                  ((IData)(vlTOPp->emu__DOT__system__DOT__tilemap_a)
                                                    ? vlTOPp->emu__DOT__system__DOT__rgb_tilemap
                                                    : vlTOPp->emu__DOT__system__DOT__rgb_starfield)))
                                                 : 
                                                ((IData)(vlTOPp->emu__DOT__system__DOT__charmap_a)
                                                  ? vlTOPp->emu__DOT__system__DOT__rgb_charmap
                                                  : 
                                                 ((0x8000U 
                                                   & (IData)(vlTOPp->emu__DOT__system__DOT__spritelbram_data_out))
                                                   ? vlTOPp->emu__DOT__system__DOT__rgb_sprite
                                                   : 
                                                  ((IData)(vlTOPp->emu__DOT__system__DOT__tilemap_a)
                                                    ? vlTOPp->emu__DOT__system__DOT__rgb_tilemap
                                                    : vlTOPp->emu__DOT__system__DOT__rgb_starfield))));
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ID16_B 
        = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16))
            ? 0xffffU : 1U);
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ID16 
        = (0xffffU & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegBusA) 
                      + (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ID16_B)));
    vlTOPp->emu__DOT__rgb_out = ((0xe4e1c00U <= vlTOPp->emu__DOT__pause__DOT__pause_timer)
                                  ? ((0x7f0000U & (vlTOPp->emu__DOT__system__DOT__rgb_final 
                                                   << 0xfU)) 
                                     | ((0x7f00U & 
                                         (vlTOPp->emu__DOT__system__DOT__rgb_final 
                                          >> 1U)) | 
                                        (0x7fU & (vlTOPp->emu__DOT__system__DOT__rgb_final 
                                                  >> 0x11U))))
                                  : ((0xff0000U & (vlTOPp->emu__DOT__system__DOT__rgb_final 
                                                   << 0x10U)) 
                                     | ((0xff00U & vlTOPp->emu__DOT__system__DOT__rgb_final) 
                                        | (0xffU & 
                                           (vlTOPp->emu__DOT__system__DOT__rgb_final 
                                            >> 0x10U)))));
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegDIH 
        = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_Mux;
    if (((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ExchangeDH) 
         & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstate) 
            >> 3U))) {
        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegDIH 
            = (0xffU & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegBusB) 
                        >> 8U));
    } else if (((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ExchangeDH) 
                & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstate) 
                   >> 4U))) {
        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegDIH 
            = (0xffU & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegBusA_r) 
                        >> 8U));
    } else if ((1U & (((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16) 
                       >> 2U) & ((((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstate) 
                                   >> 2U) & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) 
                                 | (((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstate) 
                                     >> 3U) & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))))) {
        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegDIH 
            = (0xffU & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ID16) 
                        >> 8U));
    }
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegDIL 
        = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_Mux;
    if (((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ExchangeDH) 
         & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstate) 
            >> 3U))) {
        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegDIL 
            = (0xffU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegBusB));
    } else if (((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ExchangeDH) 
                & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstate) 
                   >> 4U))) {
        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegDIL 
            = (0xffU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegBusA_r));
    } else if ((1U & (((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16) 
                       >> 2U) & ((((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstate) 
                                   >> 2U) & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) 
                                 | (((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstate) 
                                     >> 3U) & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))))) {
        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegDIL 
            = (0xffU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ID16));
    }
    vlTOPp->VGA_R = (0xffU & (vlTOPp->emu__DOT__rgb_out 
                              >> 0x10U));
    vlTOPp->VGA_G = (0xffU & (vlTOPp->emu__DOT__rgb_out 
                              >> 8U));
    vlTOPp->VGA_B = (0xffU & vlTOPp->emu__DOT__rgb_out);
}

void Vemu::_eval_initial(Vemu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu::_eval_initial\n"); );
    Vemu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__clk_sys = vlTOPp->clk_sys;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__emu__DOT__system__DOT____Vcellinp__T80x__reset_n 
        = vlTOPp->__VinpClk__TOP__emu__DOT__system__DOT____Vcellinp__T80x__reset_n;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__emu__DOT__system__DOT____Vcellinp__ms_timer__reset 
        = vlTOPp->__VinpClk__TOP__emu__DOT__system__DOT____Vcellinp__ms_timer__reset;
}

void Vemu::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu::final\n"); );
    // Variables
    Vemu__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vemu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vemu::_eval_settle(Vemu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu::_eval_settle\n"); );
    Vemu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
    vlTOPp->_settle__TOP__3(vlSymsp);
}

void Vemu::_ctor_var_reset(Vemu* self) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu::_ctor_var_reset\n"); );
    // Body
    if (false && self) {}  // Prevent unused
    self->clk_sys = 0;
    self->reset = 0;
    self->menu = 0;
    self->joystick_0 = 0;
    self->joystick_1 = 0;
    self->joystick_2 = 0;
    self->joystick_3 = 0;
    self->joystick_4 = 0;
    self->joystick_5 = 0;
    self->joystick_l_analog_0 = 0;
    self->joystick_l_analog_1 = 0;
    self->joystick_l_analog_2 = 0;
    self->joystick_l_analog_3 = 0;
    self->joystick_l_analog_4 = 0;
    self->joystick_l_analog_5 = 0;
    self->joystick_r_analog_0 = 0;
    self->joystick_r_analog_1 = 0;
    self->joystick_r_analog_2 = 0;
    self->joystick_r_analog_3 = 0;
    self->joystick_r_analog_4 = 0;
    self->joystick_r_analog_5 = 0;
    self->paddle_0 = 0;
    self->paddle_1 = 0;
    self->paddle_2 = 0;
    self->paddle_3 = 0;
    self->paddle_4 = 0;
    self->paddle_5 = 0;
    self->spinner_0 = 0;
    self->spinner_1 = 0;
    self->spinner_2 = 0;
    self->spinner_3 = 0;
    self->spinner_4 = 0;
    self->spinner_5 = 0;
    self->ps2_key = 0;
    self->ps2_mouse = 0;
    self->ps2_mouse_ext = 0;
    self->timestamp = 0;
    self->VGA_R = 0;
    self->VGA_G = 0;
    self->VGA_B = 0;
    self->VGA_HS = 0;
    self->VGA_VS = 0;
    self->VGA_HB = 0;
    self->VGA_VB = 0;
    self->AUDIO_L = 0;
    self->AUDIO_R = 0;
    self->ioctl_download = 0;
    self->ioctl_wr = 0;
    self->ioctl_addr = 0;
    self->ioctl_dout = 0;
    self->ioctl_index = 0;
    self->ioctl_wait = 0;
    self->emu__DOT__ce_6 = 0;
    self->emu__DOT__pause_cpu = 0;
    self->emu__DOT__rgb_out = 0;
    self->emu__DOT____Vcellinp__system__reset = 0;
    self->emu__DOT__divider__DOT__cencnt = 0;
    self->emu__DOT__pause__DOT__pause_request = 0;
    self->emu__DOT__pause__DOT__pause_toggle = 0;
    self->emu__DOT__pause__DOT__pause_timer = 0;
    self->emu__DOT__pause__DOT__unnamedblk1__DOT__user_button_last = 0;
    self->emu__DOT__system__DOT___hb = 0;
    self->emu__DOT__system__DOT___vb = 0;
    self->emu__DOT__system__DOT__hcnt = 0;
    self->emu__DOT__system__DOT__vcnt = 0;
    self->emu__DOT__system__DOT__timer = 0;
    self->emu__DOT__system__DOT____Vcellinp__ms_timer__reset = 0;
    self->emu__DOT__system__DOT__music_data_out = 0;
    self->emu__DOT__system__DOT__video_control = 0;
    self->emu__DOT__system__DOT__pause_trigger = 0;
    self->emu__DOT__system__DOT__pause_system = 0;
    self->emu__DOT__system__DOT__menu_trigger = 0;
    self->emu__DOT__system__DOT__pgrom_data_out = 0;
    self->emu__DOT__system__DOT__chrom_data_out = 0;
    self->emu__DOT__system__DOT__wkram_data_out = 0;
    self->emu__DOT__system__DOT__chram_data_out = 0;
    self->emu__DOT__system__DOT__fgcolram_data_out = 0;
    self->emu__DOT__system__DOT__bgcolram_data_out = 0;
    self->emu__DOT__system__DOT__chmap_data_out = 0;
    self->emu__DOT__system__DOT__pgrom_wr = 0;
    self->emu__DOT__system__DOT__chrom_wr = 0;
    self->emu__DOT__system__DOT__spriterom_wr = 0;
    self->emu__DOT__system__DOT__chram_wr = 0;
    self->emu__DOT__system__DOT__fgcolram_wr = 0;
    self->emu__DOT__system__DOT__bgcolram_wr = 0;
    self->emu__DOT__system__DOT__spriteram_wr = 0;
    self->emu__DOT__system__DOT__spritecollisionram_wr = 0;
    self->emu__DOT__system__DOT__tilemapram_wr = 0;
    self->emu__DOT__system__DOT__cpu_addr = 0;
    self->emu__DOT__system__DOT__cpu_din = 0;
    self->emu__DOT__system__DOT__cpu_dout = 0;
    self->emu__DOT__system__DOT__cpu_wr_n = 0;
    self->emu__DOT__system__DOT____Vcellinp__T80x__reset_n = 0;
    self->emu__DOT__system__DOT__charmap_a = 0;
    self->emu__DOT__system__DOT__chram_addr = 0;
    self->emu__DOT__system__DOT__tilemap_r = 0;
    self->emu__DOT__system__DOT__tilemap_g = 0;
    self->emu__DOT__system__DOT__tilemap_b = 0;
    self->emu__DOT__system__DOT__tilemap_a = 0;
    self->emu__DOT__system__DOT__tilemaprom_addr = 0;
    self->emu__DOT__system__DOT__tilemaprom_data_out = 0;
    self->emu__DOT__system__DOT__tilemapram_addr = 0;
    self->emu__DOT__system__DOT__tilemapram_data_out = 0;
    self->emu__DOT__system__DOT__tilemapram_ctl_wr = 0;
    self->emu__DOT__system__DOT__tilemapram_ctl_data_in = 0;
    self->emu__DOT__system__DOT__palrom_addr = 0;
    self->emu__DOT__system__DOT__palrom_data_out = 0;
    self->emu__DOT__system__DOT__spritecollisionram_data_out_cpu = 0;
    self->emu__DOT__system__DOT__sprom_addr = 0;
    self->emu__DOT__system__DOT__spriterom_data_out = 0;
    self->emu__DOT__system__DOT__spriteram_addr = 0;
    self->emu__DOT__system__DOT__spriteram_data_out = 0;
    self->emu__DOT__system__DOT__spritecollisionram_addr = 0;
    self->emu__DOT__system__DOT__spritecollisionram_data_out = 0;
    self->emu__DOT__system__DOT__spritecollisionram_data_in = 0;
    self->emu__DOT__system__DOT__spritelbram_wr_addr = 0;
    self->emu__DOT__system__DOT__spritelbram_wr = 0;
    self->emu__DOT__system__DOT__spritelbram_data_in = 0;
    self->emu__DOT__system__DOT__spritelbram_data_out = 0;
    self->emu__DOT__system__DOT__sf_on1 = 0;
    self->emu__DOT__system__DOT____Vcellinp__stars1__write = 0;
    self->emu__DOT__system__DOT__sf_on2 = 0;
    self->emu__DOT__system__DOT____Vcellinp__stars2__write = 0;
    self->emu__DOT__system__DOT__sf_on3 = 0;
    self->emu__DOT__system__DOT____Vcellinp__stars3__write = 0;
    self->emu__DOT__system__DOT__rgb_starfield = 0;
    self->emu__DOT__system__DOT__rgb_charmap = 0;
    self->emu__DOT__system__DOT__rgb_tilemap = 0;
    self->emu__DOT__system__DOT__rgb_sprite = 0;
    self->emu__DOT__system__DOT__rgb_final = 0;
    self->emu__DOT__system__DOT__music_audio_out = 0;
    self->emu__DOT__system__DOT__snd_audio_out = 0;
    self->emu__DOT__system__DOT____Vcellinp__spritecollisionram__wren_a = 0;
    self->emu__DOT__system__DOT__ms_timer__DOT__divider = 0;
    self->emu__DOT__system__DOT__T80x__DOT__write = 0;
    self->emu__DOT__system__DOT__T80x__DOT__di_reg = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ACC = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Ap = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Fp = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__SP = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PC = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegDIH = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegDIL = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegBusA = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegBusB = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegBusC = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegAddrA_r = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegAddrA = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegAddrB_r = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegAddrB = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegAddrC = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegWEH = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegWEL = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Alternate = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__TmpAddr = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegBusA_r = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ID16 = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_Mux = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstate = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__last_mcycle = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__last_tstate = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IntE_FF1 = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IntE_FF2 = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Halt_FF = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusReq_s = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusAck = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__NMI_s = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__INT_s = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IStatus = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__XY_State = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Pre_XY_F_M = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__NextIs_XY_Fetch = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__XY_Ind = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__No_BTR = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BTR_r = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Auto_Wait = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Auto_Wait_t1 = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Auto_Wait_t2 = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDecZ = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusB = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusA = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Q = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F_Out = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg_r = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Arith16_r = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Z16_r = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op_r = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU_r = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PreserveC_r = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IntCycle = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__NMICycle = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_WZ = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Prefix = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Acc = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PreserveC = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Arith16 = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Jump = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__JumpE = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__JumpXY = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Call = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RstP = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDW = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDSPHL = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__iorq_i = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Special_LD = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ExchangeDH = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ExchangeRp = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ExchangeAF = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ExchangeRS = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_DJNZ = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_CPL = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_CCF = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_SCF = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_RETN = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_BT = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_BC = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_BTR = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_RLD = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_RRD = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_INRC = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__SetDI = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__SetEI = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IMode = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Halt = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PC16 = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PC16_B = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__SP16 = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__SP16_A = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__SP16_B = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ID16_B = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__UseCarry = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Carry7_v = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__OverFlow_v = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__HalfCarry_v = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Carry_v = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_v = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__BitMask = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_t = 0;
    self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__DAA_Q = 0;
    for (int __Vi0=0; __Vi0<8; ++__Vi0) {
        self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH[__Vi0] = 0;
    }
    for (int __Vi0=0; __Vi0<8; ++__Vi0) {
        self->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL[__Vi0] = 0;
    }
    self->emu__DOT__system__DOT__casval__DOT__char_a = 0;
    for (int __Vi0=0; __Vi0<4; ++__Vi0) {
        self->emu__DOT__system__DOT__zechs__DOT__tilemapreg[__Vi0] = 0;
    }
    self->emu__DOT__system__DOT__zechs__DOT__tilemap_pos_x = 0;
    self->emu__DOT__system__DOT__zechs__DOT__tilemap_pos_y = 0;
    self->emu__DOT__system__DOT__zechs__DOT__tilemap_offset_x = 0;
    self->emu__DOT__system__DOT__zechs__DOT__tilemap_offset_y = 0;
    self->emu__DOT__system__DOT__zechs__DOT__tilemap_read_state = 0;
    self->emu__DOT__system__DOT__zechs__DOT__tilemap_read_cycles = 0;
    self->emu__DOT__system__DOT__zechs__DOT__tilemap_ctl_state = 0;
    self->emu__DOT__system__DOT__zechs__DOT__tilemap_ctl_x = 0;
    self->emu__DOT__system__DOT__zechs__DOT__tilemap_ctl_y = 0;
    self->emu__DOT__system__DOT__zechs__DOT__tilemap_ctl_cycles = 0;
    self->emu__DOT__system__DOT__zechs__DOT__tilemap_scroll_state = 0;
    self->emu__DOT__system__DOT__zechs__DOT__tilemap_scroll_state_next = 0;
    self->emu__DOT__system__DOT__zechs__DOT__tilemap_scroll_start_pos = 0;
    self->emu__DOT__system__DOT__zechs__DOT__tilemap_scroll_target_pos = 0;
    self->emu__DOT__system__DOT__zechs__DOT__tilemap_scroll_axis = 0;
    self->emu__DOT__system__DOT__zechs__DOT__tilemap_scroll_dir = 0;
    self->emu__DOT__system__DOT__zechs__DOT__tilemap_clear_state = 0;
    self->emu__DOT__system__DOT__zechs__DOT__hcnt_last = 0;
    self->emu__DOT__system__DOT__comet__DOT__spritelb_slot_rd = 0;
    self->emu__DOT__system__DOT__comet__DOT__spritelb_slot_wr = 0;
    self->emu__DOT__system__DOT__comet__DOT__hsync_last = 0;
    self->emu__DOT__system__DOT__comet__DOT__spr_state = 0;
    self->emu__DOT__system__DOT__comet__DOT__spr_state_next = 0;
    self->emu__DOT__system__DOT__comet__DOT__spr_index = 0;
    self->emu__DOT__system__DOT__comet__DOT__spr_size = 0;
    self->emu__DOT__system__DOT__comet__DOT__spr_x = 0;
    self->emu__DOT__system__DOT__comet__DOT__spr_y = 0;
    self->emu__DOT__system__DOT__comet__DOT__spr_enable = 0;
    self->emu__DOT__system__DOT__comet__DOT__spr_collide = 0;
    self->emu__DOT__system__DOT__comet__DOT__spr_palette_index = 0;
    self->emu__DOT__system__DOT__comet__DOT__spr_image_index = 0;
    self->emu__DOT__system__DOT__comet__DOT__spr_active_y = 0;
    self->emu__DOT__system__DOT__comet__DOT__spr_pixel_index = 0;
    self->emu__DOT__system__DOT__comet__DOT__spr_rom_offset = 0;
    self->emu__DOT__system__DOT__comet__DOT__spr_rom_y_offset = 0;
    self->emu__DOT__system__DOT__comet__DOT__spr_rom_offset_8x8 = 0;
    self->emu__DOT__system__DOT__comet__DOT__spr_rom_offset_16x16 = 0;
    self->emu__DOT__system__DOT__comet__DOT__spr_rom_offset_32x32 = 0;
    self->emu__DOT__system__DOT__comet__DOT__col_primary_state = 0;
    self->emu__DOT__system__DOT__comet__DOT__col_primary_state_next = 0;
    self->emu__DOT__system__DOT__comet__DOT__col_secondary_state = 0;
    self->emu__DOT__system__DOT__comet__DOT__col_secondary_state_next = 0;
    self->emu__DOT__system__DOT__comet__DOT__col_x = 0;
    self->emu__DOT__system__DOT__comet__DOT__col_spriteindex = 0;
    self->emu__DOT__system__DOT__comet__DOT__col_buffer_primary_addr = 0;
    self->emu__DOT__system__DOT__comet__DOT__col_buffer_primary_wr = 0;
    self->emu__DOT__system__DOT__comet__DOT__col_buffer_primary_data_in = 0;
    self->emu__DOT__system__DOT__comet__DOT__col_buffer_primary_data_out = 0;
    self->emu__DOT__system__DOT__comet__DOT__col_buffer_secondary_addr = 0;
    self->emu__DOT__system__DOT__comet__DOT__col_buffer_secondary_wr = 0;
    self->emu__DOT__system__DOT__comet__DOT__col_buffer_secondary_data_in = 0;
    self->emu__DOT__system__DOT__comet__DOT__col_buffer_secondary_data_out = 0;
    self->emu__DOT__system__DOT__comet__DOT__col_buffer_secondary_collisions = 0;
    self->emu__DOT__system__DOT__comet__DOT__col_buffer_secondary_collisions_count1 = 0;
    self->emu__DOT__system__DOT__comet__DOT__col_buffer_secondary_collisions_count2 = 0;
    self->emu__DOT__system__DOT__comet__DOT__col_buffer_primary_is_a = 0;
    self->emu__DOT__system__DOT__comet__DOT__col_secondary_timer = 0;
    self->emu__DOT__system__DOT__comet__DOT__col_buffer_data_out_a = 0;
    self->emu__DOT__system__DOT__comet__DOT__col_buffer_data_out_b = 0;
    self->emu__DOT__system__DOT__comet__DOT____Vcellinp__spritecollisionbufferram_a__address = 0;
    self->emu__DOT__system__DOT__comet__DOT____Vcellinp__spritecollisionbufferram_b__address = 0;
    for (int __Vi0=0; __Vi0<512; ++__Vi0) {
        self->emu__DOT__system__DOT__comet__DOT__spritecollisionbufferram_a__DOT__mem[__Vi0] = 0;
    }
    for (int __Vi0=0; __Vi0<512; ++__Vi0) {
        self->emu__DOT__system__DOT__comet__DOT__spritecollisionbufferram_b__DOT__mem[__Vi0] = 0;
    }
    self->emu__DOT__system__DOT__stars1__DOT__RST_CNT = 0;
    self->emu__DOT__system__DOT__stars1__DOT__seed = 0;
    self->emu__DOT__system__DOT__stars1__DOT__enabled = 0;
    self->emu__DOT__system__DOT__stars1__DOT__vdirection = 0;
    self->emu__DOT__system__DOT__stars1__DOT__vspeed_set = 0;
    self->emu__DOT__system__DOT__stars1__DOT__vincrement = 0;
    self->emu__DOT__system__DOT__stars1__DOT__vtimer = 0;
    self->emu__DOT__system__DOT__stars1__DOT__hdirection = 0;
    self->emu__DOT__system__DOT__stars1__DOT__hspeed_set = 0;
    self->emu__DOT__system__DOT__stars1__DOT__hincrement = 0;
    self->emu__DOT__system__DOT__stars1__DOT__htimer = 0;
    self->emu__DOT__system__DOT__stars1__DOT__sf_reg = 0;
    self->emu__DOT__system__DOT__stars1__DOT__sf_cnt = 0;
    self->emu__DOT__system__DOT__stars2__DOT__RST_CNT = 0;
    self->emu__DOT__system__DOT__stars2__DOT__seed = 0;
    self->emu__DOT__system__DOT__stars2__DOT__enabled = 0;
    self->emu__DOT__system__DOT__stars2__DOT__vdirection = 0;
    self->emu__DOT__system__DOT__stars2__DOT__vspeed_set = 0;
    self->emu__DOT__system__DOT__stars2__DOT__vincrement = 0;
    self->emu__DOT__system__DOT__stars2__DOT__vtimer = 0;
    self->emu__DOT__system__DOT__stars2__DOT__hdirection = 0;
    self->emu__DOT__system__DOT__stars2__DOT__hspeed_set = 0;
    self->emu__DOT__system__DOT__stars2__DOT__hincrement = 0;
    self->emu__DOT__system__DOT__stars2__DOT__htimer = 0;
    self->emu__DOT__system__DOT__stars2__DOT__sf_reg = 0;
    self->emu__DOT__system__DOT__stars2__DOT__sf_cnt = 0;
    self->emu__DOT__system__DOT__stars3__DOT__RST_CNT = 0;
    self->emu__DOT__system__DOT__stars3__DOT__seed = 0;
    self->emu__DOT__system__DOT__stars3__DOT__enabled = 0;
    self->emu__DOT__system__DOT__stars3__DOT__vdirection = 0;
    self->emu__DOT__system__DOT__stars3__DOT__vspeed_set = 0;
    self->emu__DOT__system__DOT__stars3__DOT__vincrement = 0;
    self->emu__DOT__system__DOT__stars3__DOT__vtimer = 0;
    self->emu__DOT__system__DOT__stars3__DOT__hdirection = 0;
    self->emu__DOT__system__DOT__stars3__DOT__hspeed_set = 0;
    self->emu__DOT__system__DOT__stars3__DOT__hincrement = 0;
    self->emu__DOT__system__DOT__stars3__DOT__htimer = 0;
    self->emu__DOT__system__DOT__stars3__DOT__sf_reg = 0;
    self->emu__DOT__system__DOT__stars3__DOT__sf_cnt = 0;
    for (int __Vi0=0; __Vi0<32768; ++__Vi0) {
        self->emu__DOT__system__DOT__pgrom__DOT__mem[__Vi0] = 0;
    }
    for (int __Vi0=0; __Vi0<2048; ++__Vi0) {
        self->emu__DOT__system__DOT__chrom__DOT__mem[__Vi0] = 0;
    }
    for (int __Vi0=0; __Vi0<2048; ++__Vi0) {
        self->emu__DOT__system__DOT__chram__DOT__mem[__Vi0] = 0;
    }
    for (int __Vi0=0; __Vi0<2048; ++__Vi0) {
        self->emu__DOT__system__DOT__fgcolram__DOT__mem[__Vi0] = 0;
    }
    for (int __Vi0=0; __Vi0<2048; ++__Vi0) {
        self->emu__DOT__system__DOT__bgcolram__DOT__mem[__Vi0] = 0;
    }
    for (int __Vi0=0; __Vi0<1024; ++__Vi0) {
        self->emu__DOT__system__DOT__tilemapram__DOT__mem[__Vi0] = 0;
    }
    for (int __Vi0=0; __Vi0<32768; ++__Vi0) {
        self->emu__DOT__system__DOT__tilemaprom__DOT__mem[__Vi0] = 0;
    }
    for (int __Vi0=0; __Vi0<128; ++__Vi0) {
        self->emu__DOT__system__DOT__spriteram__DOT__mem[__Vi0] = 0;
    }
    for (int __Vi0=0; __Vi0<32; ++__Vi0) {
        self->emu__DOT__system__DOT__spritecollisionram__DOT__mem[__Vi0] = 0;
    }
    for (int __Vi0=0; __Vi0<1024; ++__Vi0) {
        self->emu__DOT__system__DOT__spritelbram__DOT__mem[__Vi0] = 0;
    }
    for (int __Vi0=0; __Vi0<16384; ++__Vi0) {
        self->emu__DOT__system__DOT__spriterom__DOT__mem[__Vi0] = 0;
    }
    for (int __Vi0=0; __Vi0<16384; ++__Vi0) {
        self->emu__DOT__system__DOT__wkram__DOT__mem[__Vi0] = 0;
    }
    for (int __Vi0=0; __Vi0<256; ++__Vi0) {
        self->emu__DOT__system__DOT__palrom__DOT__mem[__Vi0] = 0;
    }
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__2__Vfuncout = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__2__FF = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__2__cc = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__Vfuncout = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__FF = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__cc = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__4__Vfuncout = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__4__FF = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__4__cc = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__5__Vfuncout = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__5__FF = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__5__cc = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__Vfuncout = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__FF = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__cc = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__7__Vfuncout = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__7__FF = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__7__cc = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__8__Vfuncout = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__8__FF = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__8__cc = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__Vfuncout = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__FF = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__cc = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__10__Vfuncout = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__10__FF = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__10__cc = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__11__Vfuncout = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__11__FF = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__11__cc = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__Vfuncout = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__FF = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__cc = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__13__Vfuncout = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__13__FF = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__13__cc = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__14__Vfuncout = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__14__FF = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__14__cc = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__Vfuncout = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__FF = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__cc = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__16__Vfuncout = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__16__FF = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__16__cc = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__17__Vfuncout = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__17__FF = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__17__cc = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__Vfuncout = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__FF = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__cc = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__19__Vfuncout = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__19__FF = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__19__cc = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__20__Vfuncout = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__20__FF = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__20__cc = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__Vfuncout = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__FF = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__cc = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__22__Vfuncout = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__22__FF = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__22__cc = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__23__Vfuncout = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__23__FF = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__23__cc = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__Vfuncout = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__FF = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__cc = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__25__Vfuncout = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__25__FF = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__25__cc = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__26__Vfuncout = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__26__A = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__26__B = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__26__Sub = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__26__Carry_In = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__27__Vfuncout = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__27__A = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__27__B = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__27__Sub = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__27__Carry_In = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__28__Vfuncout = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__28__A = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__28__B = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__28__Sub = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__28__Carry_In = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__29__Vfuncout = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__29__A = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__29__B = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__29__Sub = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__29__Carry_In = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__30__Vfuncout = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__30__A = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__30__B = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__30__Sub = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__30__Carry_In = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__31__Vfuncout = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__31__A = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__31__B = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__31__Sub = 0;
    self->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__31__Carry_In = 0;
    self->__Vdly__emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PC = 0;
    self->__Vdly__emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__XY_State = 0;
    self->__Vdly__emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR = 0;
    self->__Vdly__emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__TmpAddr = 0;
    self->__Vdly__emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ACC = 0;
    self->__Vdly__emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F = 0;
    self->__Vdly__emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__SP = 0;
    self->__Vdly__emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Alternate = 0;
    self->__Vdly__emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IntE_FF1 = 0;
    self->__Vdly__emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IntE_FF2 = 0;
    self->__Vdly__emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Auto_Wait_t1 = 0;
    self->__Vdly__emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusAck = 0;
    self->__Vdly__emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstate = 0;
    self->__Vdly__emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Pre_XY_F_M = 0;
    self->__Vdly__emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle = 0;
    self->__Vdly__emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__NMICycle = 0;
    self->__VinpClk__TOP__emu__DOT__system__DOT____Vcellinp__T80x__reset_n = 0;
    self->__VinpClk__TOP__emu__DOT__system__DOT____Vcellinp__ms_timer__reset = 0;
    self->__Vchglast__TOP__emu__DOT__system__DOT____Vcellinp__ms_timer__reset = 0;
    self->__Vchglast__TOP__emu__DOT__system__DOT____Vcellinp__T80x__reset_n = 0;
}
