// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vemu.h for the primary calling header

#include "Vemu.h"
#include "Vemu__Syms.h"

VL_INLINE_OPT void Vemu::_sequent__TOP__13(Vemu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu::_sequent__TOP__13\n"); );
    Vemu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegBusB 
        = ((vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH
            [vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegAddrB] 
            << 8U) | vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL
           [vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegAddrB]);
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
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegBusA 
        = ((vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH
            [vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegAddrA] 
            << 8U) | vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL
           [vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegAddrA]);
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ID16_B 
        = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16))
            ? 0xffffU : 1U);
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ID16 
        = (0xffffU & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegBusA) 
                      + (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ID16_B)));
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
}

VL_INLINE_OPT void Vemu::_combo__TOP__14(Vemu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu::_combo__TOP__14\n"); );
    Vemu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VlWide<6>/*191:0*/ __Vtemp108;
    VlWide<3>/*95:0*/ __Vtemp109;
    VlWide<3>/*95:0*/ __Vtemp110;
    VlWide<3>/*95:0*/ __Vtemp111;
    // Body
    __Vtemp108[0U] = vlTOPp->joystick_0;
    __Vtemp108[1U] = vlTOPp->joystick_1;
    __Vtemp108[2U] = vlTOPp->joystick_2;
    __Vtemp108[3U] = vlTOPp->joystick_3;
    __Vtemp108[4U] = (IData)((((QData)((IData)(vlTOPp->joystick_5)) 
                               << 0x20U) | (QData)((IData)(vlTOPp->joystick_4))));
    __Vtemp108[5U] = (IData)(((((QData)((IData)(vlTOPp->joystick_5)) 
                                << 0x20U) | (QData)((IData)(vlTOPp->joystick_4))) 
                              >> 0x20U));
    __Vtemp109[0U] = (((IData)(vlTOPp->joystick_l_analog_1) 
                       << 0x10U) | (IData)(vlTOPp->joystick_l_analog_0));
    __Vtemp109[1U] = (IData)((((QData)((IData)((((IData)(vlTOPp->joystick_l_analog_5) 
                                                 << 0x10U) 
                                                | (IData)(vlTOPp->joystick_l_analog_4)))) 
                               << 0x20U) | (QData)((IData)(
                                                           (((IData)(vlTOPp->joystick_l_analog_3) 
                                                             << 0x10U) 
                                                            | (IData)(vlTOPp->joystick_l_analog_2))))));
    __Vtemp109[2U] = (IData)(((((QData)((IData)((((IData)(vlTOPp->joystick_l_analog_5) 
                                                  << 0x10U) 
                                                 | (IData)(vlTOPp->joystick_l_analog_4)))) 
                                << 0x20U) | (QData)((IData)(
                                                            (((IData)(vlTOPp->joystick_l_analog_3) 
                                                              << 0x10U) 
                                                             | (IData)(vlTOPp->joystick_l_analog_2))))) 
                              >> 0x20U));
    __Vtemp110[0U] = (((IData)(vlTOPp->joystick_r_analog_1) 
                       << 0x10U) | (IData)(vlTOPp->joystick_r_analog_0));
    __Vtemp110[1U] = (IData)((((QData)((IData)((((IData)(vlTOPp->joystick_r_analog_5) 
                                                 << 0x10U) 
                                                | (IData)(vlTOPp->joystick_r_analog_4)))) 
                               << 0x20U) | (QData)((IData)(
                                                           (((IData)(vlTOPp->joystick_r_analog_3) 
                                                             << 0x10U) 
                                                            | (IData)(vlTOPp->joystick_r_analog_2))))));
    __Vtemp110[2U] = (IData)(((((QData)((IData)((((IData)(vlTOPp->joystick_r_analog_5) 
                                                  << 0x10U) 
                                                 | (IData)(vlTOPp->joystick_r_analog_4)))) 
                                << 0x20U) | (QData)((IData)(
                                                            (((IData)(vlTOPp->joystick_r_analog_3) 
                                                              << 0x10U) 
                                                             | (IData)(vlTOPp->joystick_r_analog_2))))) 
                              >> 0x20U));
    __Vtemp111[0U] = (((IData)(vlTOPp->spinner_1) << 0x10U) 
                      | (IData)(vlTOPp->spinner_0));
    __Vtemp111[1U] = (IData)((((QData)((IData)((((IData)(vlTOPp->spinner_5) 
                                                 << 0x10U) 
                                                | (IData)(vlTOPp->spinner_4)))) 
                               << 0x20U) | (QData)((IData)(
                                                           (((IData)(vlTOPp->spinner_3) 
                                                             << 0x10U) 
                                                            | (IData)(vlTOPp->spinner_2))))));
    __Vtemp111[2U] = (IData)(((((QData)((IData)((((IData)(vlTOPp->spinner_5) 
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
                                                           (__Vtemp108[
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
                                                          | (__Vtemp108[
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
                                                            (__Vtemp109[
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
                                                           | (__Vtemp109[
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
                                                             (__Vtemp110[
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
                                                            | (__Vtemp110[
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
                                                               (__Vtemp111[
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
                                                              | (__Vtemp111[
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
    vlTOPp->emu__DOT__system__DOT__pause_system = ((IData)(vlTOPp->emu__DOT__pause_cpu) 
                                                   | (IData)(vlTOPp->emu__DOT__system__DOT__pause_trigger));
    vlTOPp->emu__DOT__system__DOT____Vcellinp__T80x__reset_n 
        = (1U & (~ (IData)(vlTOPp->emu__DOT____Vcellinp__system__reset)));
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
}

void Vemu::_eval(Vemu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu::_eval\n"); );
    Vemu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clk_sys) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_sys))) 
         | ((~ (IData)(vlTOPp->__VinpClk__TOP__emu__DOT__system__DOT____Vcellinp__T80x__reset_n)) 
            & (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__emu__DOT__system__DOT____Vcellinp__T80x__reset_n)))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    if (((IData)(vlTOPp->clk_sys) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_sys)))) {
        vlTOPp->_sequent__TOP__5(vlSymsp);
    }
    if (((~ (IData)(vlTOPp->clk_sys)) & (IData)(vlTOPp->__Vclklast__TOP__clk_sys))) {
        vlTOPp->_sequent__TOP__6(vlSymsp);
    }
    if ((((IData)(vlTOPp->clk_sys) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_sys))) 
         | ((IData)(vlTOPp->__VinpClk__TOP__emu__DOT__system__DOT____Vcellinp__ms_timer__reset) 
            & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__emu__DOT__system__DOT____Vcellinp__ms_timer__reset))))) {
        vlTOPp->_sequent__TOP__7(vlSymsp);
    }
    vlTOPp->_combo__TOP__8(vlSymsp);
    if ((((IData)(vlTOPp->clk_sys) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_sys))) 
         | ((~ (IData)(vlTOPp->__VinpClk__TOP__emu__DOT__system__DOT____Vcellinp__T80x__reset_n)) 
            & (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__emu__DOT__system__DOT____Vcellinp__T80x__reset_n)))) {
        vlTOPp->_sequent__TOP__9(vlSymsp);
    }
    if (((IData)(vlTOPp->clk_sys) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_sys)))) {
        vlTOPp->_sequent__TOP__10(vlSymsp);
    }
    vlTOPp->_combo__TOP__11(vlSymsp);
    if ((((IData)(vlTOPp->clk_sys) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk_sys))) 
         | ((~ (IData)(vlTOPp->__VinpClk__TOP__emu__DOT__system__DOT____Vcellinp__T80x__reset_n)) 
            & (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__emu__DOT__system__DOT____Vcellinp__T80x__reset_n)))) {
        vlTOPp->_sequent__TOP__12(vlSymsp);
        vlTOPp->_sequent__TOP__13(vlSymsp);
    }
    vlTOPp->_combo__TOP__14(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk_sys = vlTOPp->clk_sys;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__emu__DOT__system__DOT____Vcellinp__T80x__reset_n 
        = vlTOPp->__VinpClk__TOP__emu__DOT__system__DOT____Vcellinp__T80x__reset_n;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__emu__DOT__system__DOT____Vcellinp__ms_timer__reset 
        = vlTOPp->__VinpClk__TOP__emu__DOT__system__DOT____Vcellinp__ms_timer__reset;
    vlTOPp->__VinpClk__TOP__emu__DOT__system__DOT____Vcellinp__T80x__reset_n 
        = vlTOPp->emu__DOT__system__DOT____Vcellinp__T80x__reset_n;
    vlTOPp->__VinpClk__TOP__emu__DOT__system__DOT____Vcellinp__ms_timer__reset 
        = vlTOPp->emu__DOT__system__DOT____Vcellinp__ms_timer__reset;
}

VL_INLINE_OPT QData Vemu::_change_request(Vemu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu::_change_request\n"); );
    Vemu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vemu::_change_request_1(Vemu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu::_change_request_1\n"); );
    Vemu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->emu__DOT__system__DOT____Vcellinp__ms_timer__reset ^ vlTOPp->__Vchglast__TOP__emu__DOT__system__DOT____Vcellinp__ms_timer__reset)
         | (vlTOPp->emu__DOT__system__DOT____Vcellinp__T80x__reset_n ^ vlTOPp->__Vchglast__TOP__emu__DOT__system__DOT____Vcellinp__T80x__reset_n));
    VL_DEBUG_IF( if(__req && ((vlTOPp->emu__DOT__system__DOT____Vcellinp__ms_timer__reset ^ vlTOPp->__Vchglast__TOP__emu__DOT__system__DOT____Vcellinp__ms_timer__reset))) VL_DBG_MSGF("        CHANGE: ../../rtl/generic_timer.v:29: emu.system.__Vcellinp__ms_timer__reset\n"); );
    VL_DEBUG_IF( if(__req && ((vlTOPp->emu__DOT__system__DOT____Vcellinp__T80x__reset_n ^ vlTOPp->__Vchglast__TOP__emu__DOT__system__DOT____Vcellinp__T80x__reset_n))) VL_DBG_MSGF("        CHANGE: ../../rtl/tv80/tv80e.v:38: emu.system.__Vcellinp__T80x__reset_n\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__emu__DOT__system__DOT____Vcellinp__ms_timer__reset 
        = vlTOPp->emu__DOT__system__DOT____Vcellinp__ms_timer__reset;
    vlTOPp->__Vchglast__TOP__emu__DOT__system__DOT____Vcellinp__T80x__reset_n 
        = vlTOPp->emu__DOT__system__DOT____Vcellinp__T80x__reset_n;
    return __req;
}

#ifdef VL_DEBUG
void Vemu::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk_sys & 0xfeU))) {
        Verilated::overWidthError("clk_sys");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((menu & 0xfeU))) {
        Verilated::overWidthError("menu");}
    if (VL_UNLIKELY((spinner_0 & 0xfe00U))) {
        Verilated::overWidthError("spinner_0");}
    if (VL_UNLIKELY((spinner_1 & 0xfe00U))) {
        Verilated::overWidthError("spinner_1");}
    if (VL_UNLIKELY((spinner_2 & 0xfe00U))) {
        Verilated::overWidthError("spinner_2");}
    if (VL_UNLIKELY((spinner_3 & 0xfe00U))) {
        Verilated::overWidthError("spinner_3");}
    if (VL_UNLIKELY((spinner_4 & 0xfe00U))) {
        Verilated::overWidthError("spinner_4");}
    if (VL_UNLIKELY((spinner_5 & 0xfe00U))) {
        Verilated::overWidthError("spinner_5");}
    if (VL_UNLIKELY((ps2_key & 0xf800U))) {
        Verilated::overWidthError("ps2_key");}
    if (VL_UNLIKELY((ps2_mouse & 0xfe000000U))) {
        Verilated::overWidthError("ps2_mouse");}
    if (VL_UNLIKELY((timestamp & 0ULL))) {
        Verilated::overWidthError("timestamp");}
    if (VL_UNLIKELY((ioctl_download & 0xfeU))) {
        Verilated::overWidthError("ioctl_download");}
    if (VL_UNLIKELY((ioctl_wr & 0xfeU))) {
        Verilated::overWidthError("ioctl_wr");}
    if (VL_UNLIKELY((ioctl_addr & 0xfe000000U))) {
        Verilated::overWidthError("ioctl_addr");}
}
#endif  // VL_DEBUG
