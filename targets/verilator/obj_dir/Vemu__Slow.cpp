// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vemu.h for the primary calling header

#include "Vemu.h"
#include "Vemu__Syms.h"

//==========

Vemu::Vemu(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModule{_vcname__}
 {
    Vemu__Syms* __restrict vlSymsp = __VlSymsp = new Vemu__Syms(_vcontextp__, this, name());
    Vemu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values

    // Reset structure values
    _ctor_var_reset(this);
}

void Vemu::__Vconfigure(Vemu__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    vlSymsp->_vm_contextp__->timeunit(-12);
    vlSymsp->_vm_contextp__->timeprecision(-12);
}

Vemu::~Vemu() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = nullptr);
}

void Vemu::_initial__TOP__1(Vemu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu::_initial__TOP__1\n"); );
    Vemu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VlWide<3>/*95:0*/ __Vtemp1;
    VlWide<3>/*95:0*/ __Vtemp2;
    VlWide<3>/*95:0*/ __Vtemp3;
    // Body
    vlTOPp->ioctl_wait = 0U;
    vlTOPp->emu__DOT__pause__DOT__pause_timer = 0U;
    vlTOPp->emu__DOT__system__DOT__pause_trigger = 0U;
    vlTOPp->emu__DOT__system__DOT__ms_timer__DOT__divider = 0U;
    VL_READMEM_N(true, 8, 32768, 0, std::string("rom.hex")
                 ,  &(vlTOPp->emu__DOT__system__DOT__pgrom__DOT__mem)
                 , 0, ~0ULL);
    VL_READMEM_N(true, 8, 2048, 0, std::string("font.hex")
                 ,  &(vlTOPp->emu__DOT__system__DOT__chrom__DOT__mem)
                 , 0, ~0ULL);
    vlTOPp->emu__DOT__pause__DOT__pause_toggle = 0U;
    vlTOPp->emu__DOT__system__DOT__comet__DOT__spritelb_slot_rd = 0U;
    vlTOPp->emu__DOT__system__DOT__comet__DOT__spritelb_slot_wr = 1U;
    vlTOPp->emu__DOT__system__DOT__comet__DOT__col_primary_state = 0U;
    vlTOPp->emu__DOT__system__DOT__comet__DOT__col_secondary_state = 0U;
    __Vtemp1[0U] = 0x2e686578U;
    __Vtemp1[1U] = 0x656d6170U;
    __Vtemp1[2U] = 0x74696cU;
    VL_READMEM_N(true, 8, 32768, 0, VL_CVT_PACK_STR_NW(3, __Vtemp1)
                 ,  &(vlTOPp->emu__DOT__system__DOT__tilemaprom__DOT__mem)
                 , 0, ~0ULL);
    __Vtemp2[0U] = 0x2e686578U;
    __Vtemp2[1U] = 0x72697465U;
    __Vtemp2[2U] = 0x7370U;
    VL_READMEM_N(true, 8, 16384, 0, VL_CVT_PACK_STR_NW(3, __Vtemp2)
                 ,  &(vlTOPp->emu__DOT__system__DOT__spriterom__DOT__mem)
                 , 0, ~0ULL);
    __Vtemp3[0U] = 0x2e686578U;
    __Vtemp3[1U] = 0x65747465U;
    __Vtemp3[2U] = 0x70616cU;
    VL_READMEM_N(true, 8, 256, 0, VL_CVT_PACK_STR_NW(3, __Vtemp3)
                 ,  &(vlTOPp->emu__DOT__system__DOT__palrom__DOT__mem)
                 , 0, ~0ULL);
    vlTOPp->emu__DOT__system__DOT___hb = 0U;
    vlTOPp->emu__DOT__system__DOT___vb = 1U;
    vlTOPp->VGA_HS = 0U;
    vlTOPp->VGA_VS = 0U;
    vlTOPp->emu__DOT__system__DOT__hcnt = 0U;
    vlTOPp->emu__DOT__system__DOT__vcnt = 0U;
    vlTOPp->emu__DOT__divider__DOT__cencnt = 0U;
}

void Vemu::_settle__TOP__2(Vemu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vemu::_settle__TOP__2\n"); );
    Vemu* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->AUDIO_L = (0xffffU & ((IData)(0xc000U) 
                                  + ((0x7ff8U & (((IData)(0x800U) 
                                                  + (IData)(vlTOPp->emu__DOT__system__DOT__snd_audio_out)) 
                                                 << 3U)) 
                                     + ((IData)(vlTOPp->emu__DOT__system__DOT__music_audio_out) 
                                        << 5U))));
    vlTOPp->emu__DOT__system__DOT__pgrom_wr = ((IData)(vlTOPp->ioctl_wr) 
                                               & (0U 
                                                  == (IData)(vlTOPp->ioctl_index)));
    vlTOPp->emu__DOT__system__DOT__chrom_wr = ((IData)(vlTOPp->ioctl_wr) 
                                               & (1U 
                                                  == (IData)(vlTOPp->ioctl_index)));
    vlTOPp->emu__DOT__system__DOT__spriterom_wr = ((IData)(vlTOPp->ioctl_wr) 
                                                   & (3U 
                                                      == (IData)(vlTOPp->ioctl_index)));
    vlTOPp->emu__DOT__system__DOT__rgb_sprite = (((0xf80000U 
                                                   & ((IData)(vlTOPp->emu__DOT__system__DOT__spritelbram_data_out) 
                                                      << 9U)) 
                                                  | (0x70000U 
                                                     & ((IData)(vlTOPp->emu__DOT__system__DOT__spritelbram_data_out) 
                                                        << 4U))) 
                                                 | ((0xf800U 
                                                     & ((IData)(vlTOPp->emu__DOT__system__DOT__spritelbram_data_out) 
                                                        << 6U)) 
                                                    | ((0x700U 
                                                        & ((IData)(vlTOPp->emu__DOT__system__DOT__spritelbram_data_out) 
                                                           << 1U)) 
                                                       | ((0xf8U 
                                                           & ((IData)(vlTOPp->emu__DOT__system__DOT__spritelbram_data_out) 
                                                              << 3U)) 
                                                          | (7U 
                                                             & ((IData)(vlTOPp->emu__DOT__system__DOT__spritelbram_data_out) 
                                                                >> 2U))))));
    vlTOPp->emu__DOT__system__DOT__sf_on1 = ((0x3fffffU 
                                              == (0x3c3c3U 
                                                  | vlTOPp->emu__DOT__system__DOT__stars1__DOT__sf_reg)) 
                                             & (IData)(vlTOPp->emu__DOT__system__DOT__stars1__DOT__enabled));
    vlTOPp->emu__DOT__system__DOT__sf_on2 = ((0x1fffffU 
                                              == (0x1e1e1U 
                                                  | vlTOPp->emu__DOT__system__DOT__stars2__DOT__sf_reg)) 
                                             & (IData)(vlTOPp->emu__DOT__system__DOT__stars2__DOT__enabled));
    vlTOPp->emu__DOT__system__DOT__sf_on3 = ((0x1fffffU 
                                              == (0x1e1e1U 
                                                  | vlTOPp->emu__DOT__system__DOT__stars3__DOT__sf_reg)) 
                                             & (IData)(vlTOPp->emu__DOT__system__DOT__stars3__DOT__enabled));
    vlTOPp->emu__DOT____Vcellinp__system__reset = ((IData)(vlTOPp->reset) 
                                                   | (IData)(vlTOPp->ioctl_download));
    vlTOPp->emu__DOT__system__DOT__rgb_tilemap = (((IData)(vlTOPp->emu__DOT__system__DOT__tilemap_b) 
                                                   << 0x10U) 
                                                  | (((IData)(vlTOPp->emu__DOT__system__DOT__tilemap_g) 
                                                      << 8U) 
                                                     | (IData)(vlTOPp->emu__DOT__system__DOT__tilemap_r)));
    vlTOPp->emu__DOT__system__DOT__zechs__DOT__tilemap_offset_x 
        = (0x3ffU & VL_EXTENDS_II(10,8, vlTOPp->emu__DOT__system__DOT__zechs__DOT__tilemapreg
                                  [0U]));
    vlTOPp->emu__DOT__system__DOT__zechs__DOT__tilemap_offset_y 
        = (0x3ffU & VL_EXTENDS_II(10,8, vlTOPp->emu__DOT__system__DOT__zechs__DOT__tilemapreg
                                  [1U]));
    if (vlTOPp->emu__DOT__system__DOT__comet__DOT__col_buffer_primary_is_a) {
        vlTOPp->emu__DOT__system__DOT__comet__DOT__col_buffer_primary_data_out 
            = vlTOPp->emu__DOT__system__DOT__comet__DOT__col_buffer_data_out_a;
        vlTOPp->emu__DOT__system__DOT__comet__DOT__col_buffer_secondary_data_out 
            = vlTOPp->emu__DOT__system__DOT__comet__DOT__col_buffer_data_out_b;
        vlTOPp->emu__DOT__system__DOT__comet__DOT____Vcellinp__spritecollisionbufferram_a__address 
            = vlTOPp->emu__DOT__system__DOT__comet__DOT__col_buffer_primary_addr;
        vlTOPp->emu__DOT__system__DOT__comet__DOT____Vcellinp__spritecollisionbufferram_b__address 
            = vlTOPp->emu__DOT__system__DOT__comet__DOT__col_buffer_secondary_addr;
    } else {
        vlTOPp->emu__DOT__system__DOT__comet__DOT__col_buffer_primary_data_out 
            = vlTOPp->emu__DOT__system__DOT__comet__DOT__col_buffer_data_out_b;
        vlTOPp->emu__DOT__system__DOT__comet__DOT__col_buffer_secondary_data_out 
            = vlTOPp->emu__DOT__system__DOT__comet__DOT__col_buffer_data_out_a;
        vlTOPp->emu__DOT__system__DOT__comet__DOT____Vcellinp__spritecollisionbufferram_a__address 
            = vlTOPp->emu__DOT__system__DOT__comet__DOT__col_buffer_secondary_addr;
        vlTOPp->emu__DOT__system__DOT__comet__DOT____Vcellinp__spritecollisionbufferram_b__address 
            = vlTOPp->emu__DOT__system__DOT__comet__DOT__col_buffer_primary_addr;
    }
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegBusC 
        = ((vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_reg__DOT__RegsH
            [vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegAddrC] 
            << 8U) | vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_reg__DOT__RegsL
           [vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RegAddrC]);
    vlTOPp->emu__DOT__system__DOT__chram_wr = ((~ (IData)(vlTOPp->emu__DOT__system__DOT__cpu_wr_n)) 
                                               & (0x13U 
                                                  == 
                                                  (0x1fU 
                                                   & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                      >> 0xbU))));
    vlTOPp->emu__DOT__system__DOT__fgcolram_wr = ((~ (IData)(vlTOPp->emu__DOT__system__DOT__cpu_wr_n)) 
                                                  & (0x14U 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                         >> 0xbU))));
    vlTOPp->emu__DOT__system__DOT__bgcolram_wr = ((~ (IData)(vlTOPp->emu__DOT__system__DOT__cpu_wr_n)) 
                                                  & (0x15U 
                                                     == 
                                                     (0x1fU 
                                                      & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                         >> 0xbU))));
    vlTOPp->emu__DOT__system__DOT__spriteram_wr = (
                                                   (~ (IData)(vlTOPp->emu__DOT__system__DOT__cpu_wr_n)) 
                                                   & ((0x16U 
                                                       == 
                                                       (0x1fU 
                                                        & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                           >> 0xbU))) 
                                                      & (0xb4U 
                                                         != 
                                                         (0xffU 
                                                          & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                                                             >> 8U)))));
    vlTOPp->emu__DOT__system__DOT__tilemapram_wr = 
        ((~ (IData)(vlTOPp->emu__DOT__system__DOT__cpu_wr_n)) 
         & ((0x8c10U <= (IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr)) 
            & (0x8f10U > (IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr))));
    vlTOPp->emu__DOT__system__DOT____Vcellinp__stars1__write 
        = ((IData)((0x8a00U == (0xff30U & (IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr)))) 
           & (~ (IData)(vlTOPp->emu__DOT__system__DOT__cpu_wr_n)));
    vlTOPp->emu__DOT__system__DOT____Vcellinp__stars2__write 
        = ((IData)((0x8a10U == (0xff30U & (IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr)))) 
           & (~ (IData)(vlTOPp->emu__DOT__system__DOT__cpu_wr_n)));
    vlTOPp->emu__DOT__system__DOT____Vcellinp__stars3__write 
        = ((IData)((0x8a20U == (0xff30U & (IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr)))) 
           & (~ (IData)(vlTOPp->emu__DOT__system__DOT__cpu_wr_n)));
    vlTOPp->emu__DOT__system__DOT____Vcellinp__spritecollisionram__wren_a 
        = ((0xb4U == (0xffU & ((IData)(vlTOPp->emu__DOT__system__DOT__cpu_addr) 
                               >> 8U))) & (~ (IData)(vlTOPp->emu__DOT__system__DOT__cpu_wr_n)));
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__SetEI = 0U;
    if ((0U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__SetEI = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_SCF = 0U;
    if ((0U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                      >> 7U)))) {
            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                          >> 6U)))) {
                if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 3U)))) {
                            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_SCF = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_CCF = 0U;
    if ((0U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                      >> 7U)))) {
            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                          >> 6U)))) {
                if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_CCF = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_CPL = 0U;
    if ((0U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                      >> 7U)))) {
            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                          >> 6U)))) {
                if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                  >> 4U)))) {
                        if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_CPL = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__JumpXY = 0U;
    if ((0U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                  >> 4U)))) {
                        if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__JumpXY = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Prefix = 0U;
    if ((0U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Prefix = 3U;
                                    }
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Prefix = 2U;
                                }
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Prefix = 3U;
                                }
                            }
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Prefix = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IMode = 3U;
    if ((0U != (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U != (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                          >> 7U)))) {
                if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IMode 
                                            = ((1U 
                                                & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))
                                                ? 2U
                                                : 1U);
                                    }
                                }
                            }
                        } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IMode = 0U;
                                    }
                                }
                            }
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IMode = 0U;
                                }
                            }
                        }
                    } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IMode = 2U;
                                    }
                                }
                            }
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IMode = 1U;
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IMode = 0U;
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IMode = 0U;
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ExchangeRS = 0U;
    if ((0U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                              >> 5U)))) {
                    if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ExchangeRS = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ExchangeAF = 0U;
    if ((0U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                      >> 7U)))) {
            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                          >> 6U)))) {
                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                              >> 5U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                  >> 4U)))) {
                        if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ExchangeAF = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Special_LD = 0U;
    if ((0U != (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U != (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                          >> 7U)))) {
                if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                  >> 5U)))) {
                        if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Special_LD = 5U;
                                        }
                                    }
                                }
                            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Special_LD = 4U;
                                    }
                                }
                            }
                        } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Special_LD = 7U;
                                    }
                                }
                            }
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Special_LD = 6U;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDSPHL = 0U;
    if ((0U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDSPHL = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__SetDI = 0U;
    if ((0U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 3U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__SetDI = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Halt = 0U;
    if ((0U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                      >> 7U)))) {
            if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((0x36U == (0x3fU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Halt = 1U;
                }
            }
        }
    }
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ExchangeRp = 0U;
    if ((0U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                      >> 7U)))) {
            if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((0x36U != (0x3fU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                    if ((6U != (7U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                        if ((6U != (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ExchangeRp = 1U;
                        }
                    }
                }
            }
        }
    }
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__BitMask 
        = ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))
            ? ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))
                ? ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))
                    ? 0x80U : 0x40U) : ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))
                                         ? 0x20U : 0x10U))
            : ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))
                ? ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))
                    ? 8U : 4U) : ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))
                                   ? 2U : 1U)));
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ExchangeDH = 0U;
    if ((0U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                  >> 4U)))) {
                        if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ExchangeDH = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__UseCarry 
        = (IData)((1U == (5U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op_r))));
    vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__26__Carry_In 
        = (1U & (((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op_r) 
                  >> 1U) ^ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__UseCarry) 
                            & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F))));
    vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__26__Sub 
        = (1U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op_r) 
                 >> 1U));
    vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__26__B 
        = (0xfU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusB));
    vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__26__A 
        = (0xfU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusA));
    vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__26__Vfuncout 
        = (0x1fU & (((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__26__A) 
                     + (0xfU & ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__26__Sub)
                                 ? (~ (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__26__B))
                                 : (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__26__B)))) 
                    + (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__26__Carry_In)));
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__HalfCarry_v 
        = (1U & ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__26__Vfuncout) 
                 >> 4U));
    vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__27__Carry_In 
        = (1U & (((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op_r) 
                  >> 1U) ^ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__UseCarry) 
                            & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F))));
    vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__27__Sub 
        = (1U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op_r) 
                 >> 1U));
    vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__27__B 
        = (0xfU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusB));
    vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__27__A 
        = (0xfU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusA));
    vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__27__Vfuncout 
        = (0x1fU & (((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__27__A) 
                     + (0xfU & ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__27__Sub)
                                 ? (~ (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__27__B))
                                 : (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__27__B)))) 
                    + (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__27__Carry_In)));
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_v 
        = ((0xf0U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_v)) 
           | (0xfU & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub4__27__Vfuncout)));
    vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__28__Carry_In 
        = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__HalfCarry_v;
    vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__28__Sub 
        = (1U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op_r) 
                 >> 1U));
    vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__28__B 
        = (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusB) 
                 >> 4U));
    vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__28__A 
        = (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusA) 
                 >> 4U));
    vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__28__Vfuncout 
        = (0xfU & (((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__28__A) 
                    + (7U & ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__28__Sub)
                              ? (~ (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__28__B))
                              : (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__28__B)))) 
                   + (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__28__Carry_In)));
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Carry7_v 
        = (1U & ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__28__Vfuncout) 
                 >> 3U));
    vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__29__Carry_In 
        = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__HalfCarry_v;
    vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__29__Sub 
        = (1U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op_r) 
                 >> 1U));
    vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__29__B 
        = (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusB) 
                 >> 4U));
    vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__29__A 
        = (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusA) 
                 >> 4U));
    vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__29__Vfuncout 
        = (0xfU & (((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__29__A) 
                    + (7U & ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__29__Sub)
                              ? (~ (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__29__B))
                              : (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__29__B)))) 
                   + (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__29__Carry_In)));
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_v 
        = ((0x8fU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_v)) 
           | (0x70U & ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub3__29__Vfuncout) 
                       << 4U)));
    vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__30__Carry_In 
        = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Carry7_v;
    vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__30__Sub 
        = (1U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op_r) 
                 >> 1U));
    vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__30__B 
        = (1U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusB) 
                 >> 7U));
    vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__30__A 
        = (1U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusA) 
                 >> 7U));
    vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__30__Vfuncout 
        = (3U & (((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__30__A) 
                  + (1U & ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__30__Sub)
                            ? (~ (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__30__B))
                            : (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__30__B)))) 
                 + (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__30__Carry_In)));
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Carry_v 
        = (1U & ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__30__Vfuncout) 
                 >> 1U));
    vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__31__Carry_In 
        = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Carry7_v;
    vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__31__Sub 
        = (1U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op_r) 
                 >> 1U));
    vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__31__B 
        = (1U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusB) 
                 >> 7U));
    vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__31__A 
        = (1U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__BusA) 
                 >> 7U));
    vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__31__Vfuncout 
        = (3U & (((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__31__A) 
                  + (1U & ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__31__Sub)
                            ? (~ (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__31__B))
                            : (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__31__B)))) 
                 + (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__31__Carry_In)));
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_v 
        = ((0x7fU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Q_v)) 
           | (0x80U & ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__AddSub1__31__Vfuncout) 
                       << 7U)));
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__OverFlow_v 
        = ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Carry_v) 
           ^ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_alu__DOT__Carry7_v));
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__last_mcycle 
        = (1U & ((1U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles))
                  ? (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)
                  : ((2U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles))
                      ? ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                         >> 1U) : ((3U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles))
                                    ? ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                       >> 2U) : ((4U 
                                                  == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles))
                                                  ? 
                                                 ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 3U)
                                                  : 
                                                 ((5U 
                                                   == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles))
                                                   ? 
                                                  ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                   >> 4U)
                                                   : 
                                                  ((6U 
                                                    == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles))
                                                    ? 
                                                   ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 5U)
                                                    : 
                                                   ((7U 
                                                     == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles)) 
                                                    & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                       >> 6U)))))))));
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Auto_Wait = 0U;
    if (((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IntCycle) 
         | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__NMICycle))) {
        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Auto_Wait = 1U;
        }
    }
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_INRC = 0U;
    if ((0U != (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U != (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                          >> 7U)))) {
                if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 2U)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                  >> 1U)))) {
                                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                            if ((1U 
                                                 & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                                if (
                                                    (2U 
                                                     & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_INRC = 1U;
                                                }
                                            }
                                        }
                                    }
                                }
                            } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                 >> 2U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((2U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_INRC = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((2U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_INRC = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_INRC = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((2U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_INRC = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_INRC = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_INRC = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                         >> 2U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_INRC = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_RETN = 0U;
    if ((0U != (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U != (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                          >> 7U)))) {
                if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                  >> 1U)))) {
                                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                            if ((1U 
                                                 & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                         >> 1U)))) {
                                                    if (
                                                        (4U 
                                                         & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_RETN = 1U;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 1U)))) {
                                                if (
                                                    (4U 
                                                     & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_RETN = 1U;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 1U)))) {
                                                if (
                                                    (4U 
                                                     & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_RETN = 1U;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_RETN = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 1U)))) {
                                                if (
                                                    (4U 
                                                     & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_RETN = 1U;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_RETN = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_RETN = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_RETN = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_DJNZ = 0U;
    if ((0U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                      >> 7U)))) {
            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                          >> 6U)))) {
                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                              >> 5U)))) {
                    if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 3U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_DJNZ = 1U;
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_DJNZ = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Arith16 = 0U;
    if ((0U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                      >> 7U)))) {
            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                          >> 6U)))) {
                if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Arith16 = 1U;
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Arith16 = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Arith16 = 1U;
                                    } else if ((4U 
                                                & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Arith16 = 1U;
                                    }
                                }
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Arith16 = 1U;
                                    } else if ((4U 
                                                & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Arith16 = 1U;
                                    }
                                }
                            }
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                  >> 2U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Arith16 = 1U;
                                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Arith16 = 1U;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 0U;
    if ((0U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                        }
                                    }
                                }
                            }
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                }
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                }
                            }
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                }
                            }
                        }
                    }
                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            }
                        }
                    }
                }
            } else if ((6U == (7U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                    }
                }
            } else {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
            }
        } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                             >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((6U == (7U 
                                                & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U)))) {
                                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((2U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                            }
                                        }
                                    } else {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                    }
                                } else if ((6U == (7U 
                                                   & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                      >> 3U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                        }
                                    }
                                } else {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                }
                            }
                        } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                        }
                                    }
                                } else {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                }
                            } else if ((6U == (7U & 
                                               ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                    }
                                }
                            } else {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            }
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                        }
                                    }
                                } else {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                }
                            } else if ((6U == (7U & 
                                               ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                    }
                                }
                            } else {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                         >> 1U)))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            }
                        }
                    }
                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        }
                    } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                }
                            }
                        } else {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        }
                    } else if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            }
                        }
                    } else {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                    }
                }
            } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            }
                        } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                    }
                                }
                            } else {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            }
                        } else if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U)))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                }
                            }
                        } else {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                         >> 1U)))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            }
                        }
                    }
                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        }
                    } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                }
                            }
                        } else {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        }
                    } else if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            }
                        }
                    } else {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                    }
                } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                     >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        }
                    }
                }
            } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        }
                    } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                }
                            }
                        } else {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        }
                    } else if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            }
                        }
                    } else {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                    }
                } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                     >> 1U)))) {
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        }
                    }
                }
            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                    }
                } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 3U)))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            }
                        }
                    } else {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                    }
                } else if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                         >> 3U)))) {
                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        }
                    }
                } else {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                }
            }
        }
    } else if ((1U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            }
                        } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                             | ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                >> 6U))))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            }
                        }
                    } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                    }
                } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                }
            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                         | ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                            >> 6U))))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        }
                    }
                } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                }
            } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
            }
        } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                             >> 6U)))) {
            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                         | ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                            >> 6U))))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        }
                    }
                } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                }
            } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
            }
        }
    } else if ((0x80U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            }
                        } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        }
                    } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            }
                        }
                    }
                }
            }
        }
    } else if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
        if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            }
                        }
                    } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            }
                        }
                    }
                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        }
                    }
                } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        }
                    }
                }
            } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                                }
                            }
                        }
                    } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                    }
                } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        }
                    }
                }
            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 1U)))) {
                            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                            }
                        }
                    }
                } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                }
            } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                    }
                }
            }
        } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        }
                    }
                } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                        }
                    }
                }
            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                    }
                }
            } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                    }
                }
            }
        } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                    }
                }
            } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                    }
                }
            }
        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                }
            }
        } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Save_ALU = 1U;
                }
            }
        }
    }
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RstP = 0U;
    if ((0U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 1U)))) {
                                                if (
                                                    (4U 
                                                     & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RstP = 1U;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RstP = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RstP = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RstP = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RstP = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RstP = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RstP = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__RstP = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_WZ = 0U;
    if ((0U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                      >> 7U)))) {
            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                          >> 6U)))) {
                if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                  >> 4U)))) {
                        if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 2U)))) {
                                                if (
                                                    (8U 
                                                     & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_WZ = 1U;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 2U)))) {
                                            if ((8U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_WZ = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } else if ((1U != (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                      >> 7U)))) {
            if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 2U)))) {
                                                if (
                                                    (8U 
                                                     & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_WZ = 1U;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 2U)))) {
                                            if ((8U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_WZ = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 2U)))) {
                                            if ((8U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_WZ = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                         >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 2U)))) {
                                        if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_WZ = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 2U)))) {
                                            if ((8U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_WZ = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                         >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 2U)))) {
                                        if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_WZ = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 2U)))) {
                                        if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_WZ = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                     >> 2U)))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 2U)))) {
                                    if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_WZ = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PreserveC = 0U;
    if ((0U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                      >> 7U)))) {
            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                          >> 6U)))) {
                if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                        if ((6U == 
                                             (7U & 
                                              ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                               >> 3U)))) {
                                            if ((1U 
                                                 & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                                if (
                                                    (2U 
                                                     & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                                }
                                            }
                                        } else {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                        }
                                    } else if ((6U 
                                                == 
                                                (7U 
                                                 & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                    >> 3U)))) {
                                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((2U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                            }
                                        }
                                    } else {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                    }
                                }
                            }
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((6U == (7U 
                                                & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U)))) {
                                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((2U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                            }
                                        }
                                    } else {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                    }
                                } else if ((6U == (7U 
                                                   & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                      >> 3U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                        }
                                    }
                                } else {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((6U == (7U 
                                                & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U)))) {
                                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((2U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                            }
                                        }
                                    } else {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                    }
                                } else if ((6U == (7U 
                                                   & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                      >> 3U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                        }
                                    }
                                } else {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                        }
                                    }
                                } else {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                }
                            } else if ((6U == (7U & 
                                               ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                    }
                                }
                            } else {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PreserveC = 1U;
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((6U == (7U 
                                                & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U)))) {
                                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((2U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                            }
                                        }
                                    } else {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                    }
                                } else if ((6U == (7U 
                                                   & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                      >> 3U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                        }
                                    }
                                } else {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                        }
                                    }
                                } else {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                }
                            } else if ((6U == (7U & 
                                               ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                    }
                                }
                            } else {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PreserveC = 1U;
                            }
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                        }
                                    }
                                } else {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                }
                            } else if ((6U == (7U & 
                                               ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                    }
                                }
                            } else {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PreserveC = 1U;
                            }
                        }
                    }
                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                  >> 1U)))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                    }
                                }
                            } else {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PreserveC = 1U;
                            }
                        } else if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U)))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                }
                            }
                        } else {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PreserveC = 1U;
                        }
                    }
                }
            }
        }
    } else if ((1U != (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                          >> 6U)))) {
                if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                  >> 2U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__PreserveC = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_RRD = 0U;
    if ((0U != (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U != (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                          >> 7U)))) {
                if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 4U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 1U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                         >> 2U)))) {
                                                    if (
                                                        (8U 
                                                         & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_RRD = 1U;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_RLD = 0U;
    if ((0U != (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U != (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                          >> 7U)))) {
                if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 4U)))) {
                            if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 1U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                         >> 2U)))) {
                                                    if (
                                                        (8U 
                                                         & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_RLD = 1U;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_BTR = 0U;
    if ((0U != (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U != (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
            if ((0x80U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                              >> 6U)))) {
                    if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_BTR = 1U;
                                            }
                                        }
                                    }
                                } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_BTR = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 0U;
    if ((0U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                        }
                                    }
                                }
                            }
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                    }
                                }
                            }
                        } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                    } else if ((4U 
                                                & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            }
                        }
                    } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                } else if ((1U & (~ 
                                                  ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                   >> 2U)))) {
                                    if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                         >> 1U)))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            }
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            }
                        }
                    }
                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        }
                    }
                } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                     >> 1U)))) {
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        }
                    }
                }
            } else if ((6U == (7U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                }
            } else {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
            }
        } else if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((0x36U != (0x3fU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                if ((6U == (7U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                } else if ((6U != (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                         >> 3U)))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                }
            }
        } else if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((6U != (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                    }
                                }
                            }
                        } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                    }
                                }
                            } else {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        } else if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U)))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            }
                        } else {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                         >> 1U)))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        }
                    }
                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            if ((6U != (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            }
                        }
                    } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            }
                        } else {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    } else if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        }
                    } else {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                     >> 1U)))) {
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    }
                }
            } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            if ((6U != (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            }
                        }
                    } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            }
                        } else {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    } else if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        }
                    } else {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 1U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 2U)))) {
                                if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            }
                        }
                    }
                } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                }
            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    } else if ((6U != (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    }
                } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 3U)))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        }
                    } else {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                } else if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                         >> 3U)))) {
                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    }
                } else {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                }
            } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                 >> 1U)))) {
                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                }
            }
        } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        } else if ((6U != (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        }
                    } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            }
                        } else {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    } else if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        }
                    } else {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                     >> 1U)))) {
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    }
                }
            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    } else if ((6U != (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    }
                } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 3U)))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        }
                    } else {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                } else if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                         >> 3U)))) {
                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    }
                } else {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                }
            } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                 >> 1U)))) {
                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                }
            }
        } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    } else if ((6U != (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    }
                } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 3U)))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        }
                    } else {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                } else if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                         >> 3U)))) {
                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    }
                } else {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                }
            } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                 >> 1U)))) {
                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                }
            }
        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                } else if ((6U != (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                         >> 3U)))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                }
            } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                  >> 3U)))) {
                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    }
                } else {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                }
            } else if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                     >> 3U)))) {
                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                }
            } else {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
            }
        } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                             >> 1U)))) {
            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                }
            }
        }
    } else if ((1U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                             | ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                >> 6U))))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        }
                    } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                }
            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                         | ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                            >> 6U))))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    }
                } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                }
            } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
            }
        } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                             >> 6U)))) {
            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                         | ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                            >> 6U))))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    }
                } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                }
            } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
            }
        }
    } else if ((0x80U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    }
                }
            }
        }
    } else if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
        if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 2U)))) {
                                        if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                        } else if (
                                                   (0x10U 
                                                    & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                        }
                                    }
                                }
                            } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    if ((6U != (7U 
                                                & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U)))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                    }
                                }
                            }
                        }
                    }
                } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                     >> 2U)))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        }
                    } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                if ((6U != (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            }
                        }
                    }
                }
            } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            }
                        }
                    }
                } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 1U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 2U)))) {
                                if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            }
                        }
                    } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            if ((6U != (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        }
                    }
                }
            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 1U)))) {
                            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        }
                    }
                }
            } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                }
            } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        if ((6U != (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    }
                }
            }
        } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 2U)))) {
                                    if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                    } else if ((0x10U 
                                                & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                    }
                                }
                            }
                        } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                if ((6U != (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            }
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                 >> 2U)))) {
                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    }
                } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            if ((6U != (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        }
                    }
                }
            }
        } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                          >> 2U)))) {
                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 1U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 2U)))) {
                                if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                                }
                            }
                        }
                    } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            if ((6U != (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                            }
                        }
                    }
                }
            }
        } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                             >> 2U)))) {
            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                    }
                }
            } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        if ((6U != (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Reg = 1U;
                        }
                    }
                }
            }
        }
    }
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op 
        = (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                 >> 3U));
    if ((0U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                      >> 7U)))) {
            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                          >> 6U)))) {
                if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                        if ((6U == 
                                             (7U & 
                                              ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                               >> 3U)))) {
                                            if ((1U 
                                                 & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                                if (
                                                    (2U 
                                                     & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                                                }
                                            }
                                        } else {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                                        }
                                    } else if ((6U 
                                                == 
                                                (7U 
                                                 & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                    >> 3U)))) {
                                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((2U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                                            }
                                        }
                                    } else {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                                    }
                                }
                            } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                 >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                                    } else if ((4U 
                                                & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 1U;
                                    }
                                }
                            }
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((6U == (7U 
                                                & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U)))) {
                                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((2U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                                            }
                                        }
                                    } else {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                                    }
                                } else if ((6U == (7U 
                                                   & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                      >> 3U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                                        }
                                    }
                                } else {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((6U == (7U 
                                                & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U)))) {
                                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((2U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                                            }
                                        }
                                    } else {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                                    }
                                } else if ((6U == (7U 
                                                   & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                      >> 3U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                                        }
                                    }
                                } else {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                                }
                            }
                        } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 1U;
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 0xcU;
                            }
                        } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                                    }
                                }
                            } else {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                            }
                        } else if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U)))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                                }
                            }
                        } else {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                        }
                    }
                } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 8U;
                                }
                            } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                                        }
                                    }
                                } else {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                                }
                            } else if ((6U == (7U & 
                                               ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                                    }
                                }
                            } else {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                            }
                        } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 1U;
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 8U;
                            }
                        } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                                    }
                                }
                            } else {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                            }
                        } else if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U)))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                                }
                            }
                        } else {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                         >> 1U)))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                            }
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 8U;
                            }
                        } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                                    }
                                }
                            } else {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                            }
                        } else if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U)))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                                }
                            }
                        } else {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                         >> 1U)))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 1U;
                            }
                        }
                    }
                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 8U;
                        }
                    } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                                }
                            }
                        } else {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                        }
                    } else if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                            }
                        }
                    } else {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                    }
                }
            }
        }
    } else if ((1U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 0xaU;
                            }
                        } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                             | ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                >> 6U))))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 0xaU;
                            }
                        }
                    } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 0xaU;
                    }
                } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 0xaU;
                }
            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 0xbU;
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                         | ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                            >> 6U))))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 0xbU;
                        }
                    }
                } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 0xbU;
                }
            } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 0xbU;
            }
        } else if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 9U;
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                         | ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                            >> 6U))))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 9U;
                        }
                    }
                } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 9U;
                }
            } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 9U;
            }
        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 8U;
                    }
                } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                     | ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                        >> 6U))))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 8U;
                    }
                }
            } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 8U;
            }
        } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 8U;
        }
    } else if ((0x80U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                            }
                        } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                        }
                    } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 7U;
                            }
                        }
                    } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 0U;
                        }
                    }
                }
            }
        }
    } else if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
        if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                            }
                        }
                    } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 1U;
                            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 1U;
                            }
                        }
                    }
                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                        }
                    }
                } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 3U;
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 3U;
                        }
                    }
                }
            } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 0xdU;
                                }
                            }
                        }
                    } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                    }
                } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 1U;
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 1U;
                        }
                    }
                }
            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 1U)))) {
                            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 0xeU;
                            }
                        }
                    }
                } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                }
            } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 3U;
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 3U;
                    }
                }
            }
        } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                        }
                    }
                } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 1U;
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 1U;
                        }
                    }
                }
            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                    }
                }
            } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 3U;
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 3U;
                    }
                }
            }
        } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                              >> 1U)))) {
                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                    }
                }
            } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 1U;
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 1U;
                    }
                }
            }
        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 2U;
                }
            }
        } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 3U;
                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ALU_Op = 3U;
                }
            }
        }
    }
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_BT = 0U;
    if ((0U != (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U != (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
            if ((0x80U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                              >> 6U)))) {
                    if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_BT = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_BC = 0U;
    if ((0U != (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U != (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
            if ((0x80U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                              >> 6U)))) {
                    if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__I_BC = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Acc = 0U;
    if ((0U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                              >> 5U)))) {
                    if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Acc = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                             >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Acc = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Acc = 1U;
                                }
                            }
                        }
                    }
                }
            } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Acc = 1U;
                            }
                        }
                    }
                }
            }
        }
    } else if ((1U != (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                      >> 7U)))) {
            if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Acc = 1U;
                                    }
                                }
                            }
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Acc = 1U;
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Acc = 1U;
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Acc = 1U;
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Acc = 1U;
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Acc = 1U;
                            }
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Acc = 1U;
                            }
                        }
                    }
                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Read_To_Acc = 1U;
                        }
                    }
                }
            }
        }
    }
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__iorq_i = 0U;
    if ((0U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                              >> 5U)))) {
                    if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } else if ((1U != (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                          >> 6U)))) {
                if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                        }
                                    }
                                }
                            } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                }
                            }
                        }
                    }
                }
            }
        } else if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                        }
                                    }
                                } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                         >> 2U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                    }
                                }
                            } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                }
                            }
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                  >> 2U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                    }
                                }
                            } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                }
                            }
                        }
                    }
                } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                     >> 2U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                  >> 1U)))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                }
                            }
                        } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__iorq_i = 1U;
                            }
                        }
                    }
                }
            } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                  >> 2U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                    }
                                }
                            } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                }
                            }
                        }
                    }
                } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                     >> 2U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                  >> 1U)))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                }
                            }
                        } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__iorq_i = 1U;
                            }
                        }
                    }
                }
            } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                              >> 2U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                  >> 1U)))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__iorq_i = 1U;
                                }
                            }
                        } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__iorq_i = 1U;
                            }
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                 >> 2U)))) {
                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                              >> 1U)))) {
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__iorq_i = 1U;
                            }
                        }
                    } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__iorq_i = 1U;
                        }
                    }
                }
            }
        }
    }
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Call = 0U;
    if ((0U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 2U)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                         >> 3U)))) {
                                                    if (
                                                        (0x10U 
                                                         & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Call = 1U;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 2U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 3U)))) {
                                                if (
                                                    (0x10U 
                                                     & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Call = 1U;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 2U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 3U)))) {
                                                if (
                                                    (0x10U 
                                                     & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Call = 1U;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 2U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 3U)))) {
                                            if ((0x10U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Call = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 2U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 3U)))) {
                                                if (
                                                    (0x10U 
                                                     & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Call = 1U;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 2U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 3U)))) {
                                            if ((0x10U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Call = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 2U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 3U)))) {
                                            if ((0x10U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Call = 1U;
                                            }
                                        }
                                    }
                                }
                            } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                 >> 1U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 2U)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 3U)))) {
                                        if ((0x10U 
                                             & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Call = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 2U)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 3U)))) {
                                        if ((0x10U 
                                             & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Call = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDW = 0U;
    if ((0U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDW = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDW = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDW = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDW = 1U;
                                    }
                                }
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDW = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDW = 1U;
                                    }
                                }
                            }
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDW = 1U;
                                    }
                                }
                            } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                 >> 1U)))) {
                                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDW = 1U;
                                }
                            }
                        }
                    }
                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDW = 1U;
                                }
                            }
                        }
                    }
                }
            }
        } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                             >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                              >> 4U)))) {
                    if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDW = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                         >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDW = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } else if ((1U != (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                      >> 7U)))) {
            if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDW = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDW = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDW = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                         >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDW = 1U;
                                    }
                                }
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDW = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                         >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDW = 1U;
                                    }
                                }
                            }
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDW = 1U;
                                    }
                                }
                            }
                        }
                    }
                } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                     >> 2U)))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDW = 1U;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 0U;
    if ((0U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((2U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                            } else if (
                                                       (4U 
                                                        & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                            }
                                        }
                                    }
                                } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 2U)))) {
                                            if ((8U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                            } else if (
                                                       (0x10U 
                                                        & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                        }
                                    }
                                }
                            } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                    } else if ((4U 
                                                & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                    }
                                }
                            } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                 >> 1U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 2U)))) {
                                    if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                    } else if ((0x10U 
                                                & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                        }
                                    }
                                }
                            } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 2U)))) {
                                        if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                        } else if (
                                                   (0x10U 
                                                    & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                    } else if ((4U 
                                                & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                    }
                                }
                            }
                        } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                }
                            }
                        } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                             >> 1U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 2U)))) {
                                if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                }
                            }
                        }
                    } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                    } else if ((1U 
                                                & (~ 
                                                   ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 3U)))) {
                                        if ((0x10U 
                                             & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                        }
                                    }
                                }
                            } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 2U)))) {
                                        if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                        } else if (
                                                   (0x10U 
                                                    & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                    } else if ((4U 
                                                & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                    }
                                }
                            }
                        } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                }
                            }
                        } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                             >> 1U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 2U)))) {
                                if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                }
                            }
                        }
                    } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                }
                            }
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                    } else if ((4U 
                                                & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                    }
                                }
                            }
                        } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 2U)))) {
                                    if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                    } else if ((0x10U 
                                                & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                    }
                                }
                            }
                        } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                             >> 1U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 2U)))) {
                                if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                }
                            }
                        }
                    }
                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                }
                            }
                        }
                    } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                         >> 1U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 2U)))) {
                            if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                            } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                            }
                        }
                    }
                }
            }
        } else if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((0x36U != (0x3fU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                if ((6U != (7U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                    if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 3U)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                        }
                    }
                }
            }
        } else if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                    }
                                }
                            }
                        } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                        }
                                    }
                                }
                            }
                        } else if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U)))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                    }
                                }
                            }
                        }
                    }
                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                }
                            }
                        }
                    } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                }
                            }
                        }
                    }
                } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 1U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 2U)))) {
                                if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                }
                            }
                        }
                    }
                }
            } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                }
                            }
                        }
                    } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                }
                            }
                        }
                    }
                }
            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                        if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                            }
                        }
                    }
                } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 3U)))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                }
                            }
                        }
                    }
                } else if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                         >> 3U)))) {
                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 1U)))) {
                            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                            }
                        }
                    }
                }
            } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                  >> 1U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 2U)))) {
                            if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                            } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                            }
                        }
                    }
                }
            }
        } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                }
                            }
                        }
                    } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                }
                            }
                        }
                    }
                }
            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                        if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                            }
                        }
                    }
                } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 3U)))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                }
                            }
                        }
                    }
                } else if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                         >> 3U)))) {
                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 1U)))) {
                            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                            }
                        }
                    }
                }
            } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                        }
                    }
                }
            }
        } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                        if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                            }
                        }
                    }
                } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 3U)))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                }
                            }
                        }
                    }
                } else if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                         >> 3U)))) {
                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 1U)))) {
                            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                            }
                        }
                    }
                }
            }
        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                    if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 3U)))) {
                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                        }
                    }
                }
            } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                  >> 3U)))) {
                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 1U)))) {
                            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                            }
                        }
                    }
                }
            } else if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                     >> 3U)))) {
                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                  >> 1U)))) {
                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                        }
                    }
                }
            }
        } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                }
            }
        } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
            if (vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__NMICycle) {
                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                    }
                }
            } else if (vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IntCycle) {
                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                    }
                }
            }
        }
    } else if ((1U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                          | ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                             >> 6U))))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                      | ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                         >> 6U))))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                }
                            }
                        }
                    }
                }
            }
        } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                             >> 6U)))) {
            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                      | ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                         >> 6U))))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                }
                            }
                        }
                    }
                }
            }
        }
    } else if ((0x80U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                    }
                                }
                            }
                        } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                }
                            }
                        }
                    } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                }
                            }
                        }
                    }
                }
            }
        }
    } else if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
        if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                  >> 2U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                    }
                                }
                            }
                        }
                    }
                } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                     >> 2U)))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 2U)))) {
                                    if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                    } else if ((0x10U 
                                                & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                            }
                        }
                    }
                }
            } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 2U)))) {
                                    if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                    }
                                }
                            }
                        }
                    }
                } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                     >> 1U)))) {
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                            }
                        }
                    }
                }
            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 1U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 2U)))) {
                                if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                }
                            }
                        }
                    }
                }
            } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                  >> 1U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 2U)))) {
                            if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                            } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                            }
                        }
                    }
                }
            } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                    }
                }
            }
        } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                              >> 2U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                  >> 1U)))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                }
                            }
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                 >> 2U)))) {
                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 1U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 2U)))) {
                                if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                                }
                            }
                        }
                    }
                } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                        }
                    }
                }
            }
        } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                          >> 2U)))) {
                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                              >> 1U)))) {
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                            }
                        }
                    }
                }
            }
        } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                             >> 2U)))) {
            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                  >> 1U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 2U)))) {
                            if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                            } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                            }
                        }
                    }
                }
            } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__write = 1U;
                    }
                }
            }
        }
    }
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 0U;
    if ((0U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                                        }
                                    }
                                }
                            } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                                    }
                                }
                            } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                                    }
                                }
                            }
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                                    }
                                }
                            }
                        } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                                }
                            }
                        } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                                    }
                                }
                            }
                        } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                                }
                            }
                        } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                                }
                            }
                        }
                    } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                            }
                        }
                    } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                                    }
                                }
                            }
                        } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                                }
                            }
                        } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                                }
                            }
                        }
                    } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                            }
                        }
                    } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                            }
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                                }
                            } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                            }
                        }
                    } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                            }
                        }
                    } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                            }
                        }
                    } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                        }
                    }
                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                            }
                        }
                    }
                } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                        }
                    } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                    }
                } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                        }
                    }
                }
            }
        } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                             >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                         >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                                }
                            }
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                                }
                            }
                        }
                    }
                } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                     >> 2U)))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                            }
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                 >> 4U)))) {
                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                  >> 2U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__NMICycle)))) {
                                    if (vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IntCycle) {
                                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                                        } else if (
                                                   (1U 
                                                    & (~ 
                                                       ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                        >> 1U)))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 2U)))) {
                                                if (
                                                    (8U 
                                                     & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } else if ((1U != (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                      >> 7U)))) {
            if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((2U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                                            }
                                        }
                                    }
                                }
                            } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                                    }
                                }
                            }
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                                        }
                                    }
                                }
                            }
                        } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                                        }
                                    }
                                }
                            }
                        } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                                        }
                                    }
                                }
                            }
                        } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                            }
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                            }
                        }
                    }
                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                  >> 1U)))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                                }
                            }
                        }
                    }
                } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__LDZ = 1U;
                        }
                    }
                }
            }
        }
    }
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 0U;
    if ((0U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                        }
                                    }
                                } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    } else if ((4U 
                                                & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    }
                                }
                            } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    } else if ((4U 
                                                & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    }
                                }
                            }
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    }
                                }
                            } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            }
                        } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    }
                                }
                            } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            }
                        } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            }
                        } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                        }
                    } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    }
                                }
                            } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            }
                        } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            }
                        } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                        }
                    } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                        } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            }
                        } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                        } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                        }
                    } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                        }
                    }
                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                        }
                    } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                        }
                    }
                } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                        }
                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                        }
                    } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                    }
                }
            }
        } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                             >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((6U == (7U 
                                                & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U)))) {
                                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                        }
                                    } else if ((2U 
                                                & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    }
                                }
                            }
                        } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            }
                        } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    }
                                } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            }
                        }
                    } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                        }
                    } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                        }
                    } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                    }
                } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    }
                                } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            }
                        }
                    } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                        }
                    } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                        }
                    }
                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                        }
                    }
                } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                        }
                    }
                } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                    }
                } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                }
            } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    }
                                } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                         >> 1U)))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                        }
                    }
                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                        }
                    }
                } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                     >> 1U)))) {
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                        }
                    } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                        }
                    }
                }
            } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                        }
                    }
                }
            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                        if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                        } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                        }
                    }
                }
            } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                 >> 1U)))) {
                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                    }
                } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__NMICycle)))) {
                    if (vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IntCycle) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 2U)))) {
                                    if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } else if ((1U != (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                      >> 7U)))) {
            if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                        } else if (
                                                   (4U 
                                                    & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                        }
                                    }
                                }
                            }
                        } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    } else if ((4U 
                                                & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    } else if ((4U 
                                                & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                         >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    } else if ((4U 
                                                & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                    }
                                }
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                         >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            }
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                                }
                            }
                        }
                    }
                } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                     >> 2U)))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
    if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
    }
    if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
        if (((0x36U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)) 
             | (1U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet)))) {
            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Inc_PC = 1U;
        }
    }
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__JumpE = 0U;
    if ((0U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                      >> 7U)))) {
            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                          >> 6U)))) {
                if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__JumpE = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__JumpE = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__JumpE = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                         >> 2U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__JumpE = 1U;
                                    }
                                }
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__JumpE = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                         >> 2U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__JumpE = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Jump = 0U;
    if ((0U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 2U)))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__cc 
                                                    = 
                                                    (7U 
                                                     & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                        >> 3U));
                                                vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__FF 
                                                    = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F;
                                                vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__Vfuncout 
                                                    = 
                                                    (1U 
                                                     & ((4U 
                                                         & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__cc))
                                                         ? 
                                                        ((2U 
                                                          & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__cc))
                                                          ? 
                                                         ((1U 
                                                           & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__cc))
                                                           ? 
                                                          ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__FF) 
                                                           >> 7U)
                                                           : 
                                                          (~ 
                                                           ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__FF) 
                                                            >> 7U)))
                                                          : 
                                                         ((1U 
                                                           & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__cc))
                                                           ? 
                                                          ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__FF) 
                                                           >> 2U)
                                                           : 
                                                          (~ 
                                                           ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__FF) 
                                                            >> 2U))))
                                                         : 
                                                        ((2U 
                                                          & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__cc))
                                                          ? 
                                                         ((1U 
                                                           & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__cc))
                                                           ? (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__FF)
                                                           : 
                                                          (~ (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__FF)))
                                                          : 
                                                         ((1U 
                                                           & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__cc))
                                                           ? 
                                                          ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__FF) 
                                                           >> 6U)
                                                           : 
                                                          (~ 
                                                           ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__FF) 
                                                            >> 6U))))));
                                                if (vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__3__Vfuncout) {
                                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Jump = 1U;
                                                }
                                            }
                                        }
                                    }
                                } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Jump = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__cc 
                                                = (7U 
                                                   & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                      >> 3U));
                                            vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__FF 
                                                = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F;
                                            vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__Vfuncout 
                                                = (1U 
                                                   & ((4U 
                                                       & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__cc))
                                                       ? 
                                                      ((2U 
                                                        & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__cc))
                                                        ? 
                                                       ((1U 
                                                         & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__cc))
                                                         ? 
                                                        ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__FF) 
                                                         >> 7U)
                                                         : 
                                                        (~ 
                                                         ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__FF) 
                                                          >> 7U)))
                                                        : 
                                                       ((1U 
                                                         & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__cc))
                                                         ? 
                                                        ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__FF) 
                                                         >> 2U)
                                                         : 
                                                        (~ 
                                                         ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__FF) 
                                                          >> 2U))))
                                                       : 
                                                      ((2U 
                                                        & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__cc))
                                                        ? 
                                                       ((1U 
                                                         & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__cc))
                                                         ? (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__FF)
                                                         : 
                                                        (~ (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__FF)))
                                                        : 
                                                       ((1U 
                                                         & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__cc))
                                                         ? 
                                                        ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__FF) 
                                                         >> 6U)
                                                         : 
                                                        (~ 
                                                         ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__FF) 
                                                          >> 6U))))));
                                            if (vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__6__Vfuncout) {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Jump = 1U;
                                            }
                                        }
                                    }
                                }
                            } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Jump = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__cc 
                                                = (7U 
                                                   & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                      >> 3U));
                                            vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__FF 
                                                = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F;
                                            vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__Vfuncout 
                                                = (1U 
                                                   & ((4U 
                                                       & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__cc))
                                                       ? 
                                                      ((2U 
                                                        & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__cc))
                                                        ? 
                                                       ((1U 
                                                         & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__cc))
                                                         ? 
                                                        ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__FF) 
                                                         >> 7U)
                                                         : 
                                                        (~ 
                                                         ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__FF) 
                                                          >> 7U)))
                                                        : 
                                                       ((1U 
                                                         & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__cc))
                                                         ? 
                                                        ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__FF) 
                                                         >> 2U)
                                                         : 
                                                        (~ 
                                                         ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__FF) 
                                                          >> 2U))))
                                                       : 
                                                      ((2U 
                                                        & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__cc))
                                                        ? 
                                                       ((1U 
                                                         & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__cc))
                                                         ? (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__FF)
                                                         : 
                                                        (~ (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__FF)))
                                                        : 
                                                       ((1U 
                                                         & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__cc))
                                                         ? 
                                                        ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__FF) 
                                                         >> 6U)
                                                         : 
                                                        (~ 
                                                         ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__FF) 
                                                          >> 6U))))));
                                            if (vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__9__Vfuncout) {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Jump = 1U;
                                            }
                                        }
                                    }
                                }
                            } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Jump = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                         >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__cc 
                                            = (7U & 
                                               ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U));
                                        vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__FF 
                                            = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F;
                                        vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__Vfuncout 
                                            = (1U & 
                                               ((4U 
                                                 & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__cc))
                                                 ? 
                                                ((2U 
                                                  & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__cc))
                                                   ? 
                                                  ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__FF) 
                                                   >> 7U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__FF) 
                                                    >> 7U)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__cc))
                                                   ? 
                                                  ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__FF) 
                                                   >> 2U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__FF) 
                                                    >> 2U))))
                                                 : 
                                                ((2U 
                                                  & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__cc))
                                                   ? (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__FF)
                                                   : 
                                                  (~ (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__FF)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__cc))
                                                   ? 
                                                  ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__FF) 
                                                   >> 6U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__FF) 
                                                    >> 6U))))));
                                        if (vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__12__Vfuncout) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Jump = 1U;
                                        }
                                    }
                                }
                            }
                        } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Jump = 1U;
                                    }
                                }
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__cc 
                                                = (7U 
                                                   & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                      >> 3U));
                                            vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__FF 
                                                = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F;
                                            vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__Vfuncout 
                                                = (1U 
                                                   & ((4U 
                                                       & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__cc))
                                                       ? 
                                                      ((2U 
                                                        & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__cc))
                                                        ? 
                                                       ((1U 
                                                         & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__cc))
                                                         ? 
                                                        ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__FF) 
                                                         >> 7U)
                                                         : 
                                                        (~ 
                                                         ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__FF) 
                                                          >> 7U)))
                                                        : 
                                                       ((1U 
                                                         & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__cc))
                                                         ? 
                                                        ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__FF) 
                                                         >> 2U)
                                                         : 
                                                        (~ 
                                                         ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__FF) 
                                                          >> 2U))))
                                                       : 
                                                      ((2U 
                                                        & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__cc))
                                                        ? 
                                                       ((1U 
                                                         & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__cc))
                                                         ? (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__FF)
                                                         : 
                                                        (~ (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__FF)))
                                                        : 
                                                       ((1U 
                                                         & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__cc))
                                                         ? 
                                                        ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__FF) 
                                                         >> 6U)
                                                         : 
                                                        (~ 
                                                         ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__FF) 
                                                          >> 6U))))));
                                            if (vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__15__Vfuncout) {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Jump = 1U;
                                            }
                                        }
                                    }
                                }
                            } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Jump = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                         >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__cc 
                                            = (7U & 
                                               ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U));
                                        vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__FF 
                                            = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F;
                                        vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__Vfuncout 
                                            = (1U & 
                                               ((4U 
                                                 & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__cc))
                                                 ? 
                                                ((2U 
                                                  & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__cc))
                                                   ? 
                                                  ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__FF) 
                                                   >> 7U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__FF) 
                                                    >> 7U)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__cc))
                                                   ? 
                                                  ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__FF) 
                                                   >> 2U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__FF) 
                                                    >> 2U))))
                                                 : 
                                                ((2U 
                                                  & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__cc))
                                                   ? (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__FF)
                                                   : 
                                                  (~ (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__FF)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__cc))
                                                   ? 
                                                  ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__FF) 
                                                   >> 6U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__FF) 
                                                    >> 6U))))));
                                        if (vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__18__Vfuncout) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Jump = 1U;
                                        }
                                    }
                                }
                            }
                        } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Jump = 1U;
                                    }
                                }
                            }
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                  >> 2U)))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__cc 
                                            = (7U & 
                                               ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U));
                                        vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__FF 
                                            = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F;
                                        vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__Vfuncout 
                                            = (1U & 
                                               ((4U 
                                                 & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__cc))
                                                 ? 
                                                ((2U 
                                                  & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__cc))
                                                   ? 
                                                  ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__FF) 
                                                   >> 7U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__FF) 
                                                    >> 7U)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__cc))
                                                   ? 
                                                  ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__FF) 
                                                   >> 2U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__FF) 
                                                    >> 2U))))
                                                 : 
                                                ((2U 
                                                  & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__cc))
                                                   ? (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__FF)
                                                   : 
                                                  (~ (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__FF)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__cc))
                                                   ? 
                                                  ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__FF) 
                                                   >> 6U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__FF) 
                                                    >> 6U))))));
                                        if (vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__21__Vfuncout) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Jump = 1U;
                                        }
                                    }
                                }
                            }
                        } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Jump = 1U;
                                    }
                                }
                            }
                        } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Jump = 1U;
                                }
                            }
                        }
                    }
                } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                     >> 2U)))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Jump = 1U;
                            }
                        } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                             >> 1U)))) {
                            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__cc 
                                    = (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U));
                                vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__FF 
                                    = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F;
                                vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__Vfuncout 
                                    = (1U & ((4U & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__cc))
                                              ? ((2U 
                                                  & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__cc))
                                                   ? 
                                                  ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__FF) 
                                                   >> 7U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__FF) 
                                                    >> 7U)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__cc))
                                                   ? 
                                                  ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__FF) 
                                                   >> 2U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__FF) 
                                                    >> 2U))))
                                              : ((2U 
                                                  & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__cc))
                                                   ? (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__FF)
                                                   : 
                                                  (~ (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__FF)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__cc))
                                                   ? 
                                                  ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__FF) 
                                                   >> 6U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__FF) 
                                                    >> 6U))))));
                                if (vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__24__Vfuncout) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Jump = 1U;
                                }
                            }
                        }
                    } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Jump = 1U;
                                }
                            }
                        }
                    }
                }
            }
        } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                             >> 6U)))) {
            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                          >> 5U)))) {
                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                              >> 4U)))) {
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                  >> 3U)))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 2U)))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__NMICycle)))) {
                                        if (vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IntCycle) {
                                            if ((1U 
                                                 & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                                if (
                                                    (1U 
                                                     & (~ 
                                                        ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                         >> 1U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                             >> 2U)))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                                 >> 3U)))) {
                                                            if (
                                                                (0x10U 
                                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Jump = 1U;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } else if ((1U != (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                      >> 7U)))) {
            if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 1U)))) {
                                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                            if ((1U 
                                                 & (~ 
                                                    ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                     >> 1U)))) {
                                                if (
                                                    (4U 
                                                     & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Jump = 1U;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Jump = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Jump = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Jump = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 1U)))) {
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                        if ((1U & (~ 
                                                   ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                    >> 1U)))) {
                                            if ((4U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Jump = 1U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Jump = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Jump = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                  >> 1U)))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle)))) {
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Jump = 1U;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD 
        = (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                 >> 3U));
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS 
        = (7U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR));
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR 
        = (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                 >> 4U));
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 1U;
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates 
        = ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))
            ? 4U : 3U);
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0U;
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0U;
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To = 0U;
    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 7U;
    if ((0U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        if ((0x80U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 5U;
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xdU;
                                        } else if (
                                                   (2U 
                                                    & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xcU;
                                        }
                                    } else {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                                = (
                                                   (8U 
                                                    & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                                   | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS));
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                                = (7U 
                                                   | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To));
                                        }
                                    }
                                } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 5U;
                                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                                  >> 1U)))) {
                                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__2__cc 
                                                = (7U 
                                                   & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                      >> 3U));
                                            vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__2__FF 
                                                = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F;
                                            vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__2__Vfuncout 
                                                = (1U 
                                                   & ((4U 
                                                       & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__2__cc))
                                                       ? 
                                                      ((2U 
                                                        & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__2__cc))
                                                        ? 
                                                       ((1U 
                                                         & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__2__cc))
                                                         ? 
                                                        ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__2__FF) 
                                                         >> 7U)
                                                         : 
                                                        (~ 
                                                         ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__2__FF) 
                                                          >> 7U)))
                                                        : 
                                                       ((1U 
                                                         & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__2__cc))
                                                         ? 
                                                        ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__2__FF) 
                                                         >> 2U)
                                                         : 
                                                        (~ 
                                                         ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__2__FF) 
                                                          >> 2U))))
                                                       : 
                                                      ((2U 
                                                        & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__2__cc))
                                                        ? 
                                                       ((1U 
                                                         & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__2__cc))
                                                         ? (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__2__FF)
                                                         : 
                                                        (~ (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__2__FF)))
                                                        : 
                                                       ((1U 
                                                         & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__2__cc))
                                                         ? 
                                                        ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__2__FF) 
                                                         >> 6U)
                                                         : 
                                                        (~ 
                                                         ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__2__FF) 
                                                          >> 6U))))));
                                            if (vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__2__Vfuncout) {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xdU;
                                            } else {
                                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                            }
                                        } else if (
                                                   (8U 
                                                    & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xcU;
                                        }
                                    }
                                }
                            } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                }
                            } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 6U;
                            } else {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__4__cc 
                                        = (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U));
                                    vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__4__FF 
                                        = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F;
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 5U;
                                    vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__4__Vfuncout 
                                        = (1U & ((4U 
                                                  & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__4__cc))
                                                  ? 
                                                 ((2U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__4__cc))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__4__cc))
                                                    ? 
                                                   ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__4__FF) 
                                                    >> 7U)
                                                    : 
                                                   (~ 
                                                    ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__4__FF) 
                                                     >> 7U)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__4__cc))
                                                    ? 
                                                   ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__4__FF) 
                                                    >> 2U)
                                                    : 
                                                   (~ 
                                                    ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__4__FF) 
                                                     >> 2U))))
                                                  : 
                                                 ((2U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__4__cc))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__4__cc))
                                                    ? (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__4__FF)
                                                    : 
                                                   (~ (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__4__FF)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__4__cc))
                                                    ? 
                                                   ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__4__FF) 
                                                    >> 6U)
                                                    : 
                                                   (~ 
                                                    ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__4__FF) 
                                                     >> 6U))))));
                                    if (vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__4__Vfuncout) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                    } else {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 1U;
                                    }
                                } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                                }
                            }
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 5U;
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xdU;
                                    } else if ((2U 
                                                & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xcU;
                                    }
                                } else {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                            = ((8U 
                                                & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                               | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS));
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                            = (7U | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To));
                                    }
                                }
                            } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 5U;
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                        = ((3U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                                            ? 7U : 
                                           ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                            << 1U));
                                } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                        = ((3U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                                            ? 0xbU : 
                                           (1U | ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                                  << 1U)));
                                }
                            } else {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 5U;
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__5__cc 
                                            = (7U & 
                                               ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U));
                                        vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__5__FF 
                                            = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F;
                                        vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__5__Vfuncout 
                                            = (1U & 
                                               ((4U 
                                                 & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__5__cc))
                                                 ? 
                                                ((2U 
                                                  & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__5__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__5__cc))
                                                   ? 
                                                  ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__5__FF) 
                                                   >> 7U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__5__FF) 
                                                    >> 7U)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__5__cc))
                                                   ? 
                                                  ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__5__FF) 
                                                   >> 2U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__5__FF) 
                                                    >> 2U))))
                                                 : 
                                                ((2U 
                                                  & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__5__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__5__cc))
                                                   ? (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__5__FF)
                                                   : 
                                                  (~ (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__5__FF)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__5__cc))
                                                   ? 
                                                  ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__5__FF) 
                                                   >> 6U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__5__FF) 
                                                    >> 6U))))));
                                        if (vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__5__Vfuncout) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xdU;
                                        } else {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                        }
                                    } else if ((8U 
                                                & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xcU;
                                    }
                                }
                            }
                        } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            }
                        } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                            } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = ((3U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                                        ? 0xbU : ((8U 
                                                   & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                                  | (1U 
                                                     | ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                                        << 1U))));
                            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = ((3U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                                        ? 7U : ((8U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                                | ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                                   << 1U)));
                            }
                        } else {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__7__cc 
                                    = (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U));
                                vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__7__FF 
                                    = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 5U;
                                vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__7__Vfuncout 
                                    = (1U & ((4U & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__7__cc))
                                              ? ((2U 
                                                  & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__7__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__7__cc))
                                                   ? 
                                                  ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__7__FF) 
                                                   >> 7U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__7__FF) 
                                                    >> 7U)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__7__cc))
                                                   ? 
                                                  ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__7__FF) 
                                                   >> 2U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__7__FF) 
                                                    >> 2U))))
                                              : ((2U 
                                                  & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__7__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__7__cc))
                                                   ? (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__7__FF)
                                                   : 
                                                  (~ (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__7__FF)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__7__cc))
                                                   ? 
                                                  ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__7__FF) 
                                                   >> 6U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__7__FF) 
                                                    >> 6U))))));
                                if (vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__7__Vfuncout) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                } else {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 1U;
                                }
                            } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                            }
                        }
                    } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 5U;
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xdU;
                                    } else if ((2U 
                                                & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xcU;
                                    }
                                } else {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                            = ((8U 
                                                & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                               | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS));
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                            = (7U | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To));
                                    }
                                }
                            } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 5U;
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__8__cc 
                                            = (7U & 
                                               ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U));
                                        vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__8__FF 
                                            = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F;
                                        vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__8__Vfuncout 
                                            = (1U & 
                                               ((4U 
                                                 & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__8__cc))
                                                 ? 
                                                ((2U 
                                                  & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__8__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__8__cc))
                                                   ? 
                                                  ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__8__FF) 
                                                   >> 7U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__8__FF) 
                                                    >> 7U)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__8__cc))
                                                   ? 
                                                  ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__8__FF) 
                                                   >> 2U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__8__FF) 
                                                    >> 2U))))
                                                 : 
                                                ((2U 
                                                  & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__8__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__8__cc))
                                                   ? (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__8__FF)
                                                   : 
                                                  (~ (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__8__FF)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__8__cc))
                                                   ? 
                                                  ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__8__FF) 
                                                   >> 6U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__8__FF) 
                                                    >> 6U))))));
                                        if (vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__8__Vfuncout) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xdU;
                                        } else {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                        }
                                    } else if ((8U 
                                                & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xcU;
                                    }
                                }
                            }
                        } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            }
                        } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__10__cc 
                                    = (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U));
                                vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__10__FF 
                                    = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 5U;
                                vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__10__Vfuncout 
                                    = (1U & ((4U & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__10__cc))
                                              ? ((2U 
                                                  & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__10__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__10__cc))
                                                   ? 
                                                  ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__10__FF) 
                                                   >> 7U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__10__FF) 
                                                    >> 7U)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__10__cc))
                                                   ? 
                                                  ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__10__FF) 
                                                   >> 2U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__10__FF) 
                                                    >> 2U))))
                                              : ((2U 
                                                  & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__10__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__10__cc))
                                                   ? (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__10__FF)
                                                   : 
                                                  (~ (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__10__FF)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__10__cc))
                                                   ? 
                                                  ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__10__FF) 
                                                   >> 6U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__10__FF) 
                                                    >> 6U))))));
                                if (vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__10__Vfuncout) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                } else {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 1U;
                                }
                            } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 5U;
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xdU;
                                } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xcU;
                                }
                            } else {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                        = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                           | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS));
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                        = (7U | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To));
                                }
                            }
                        } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 5U;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                    = ((3U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                                        ? 7U : ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                                << 1U));
                            } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                    = ((3U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                                        ? 0xbU : (1U 
                                                  | ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                                     << 1U)));
                            }
                        } else {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 5U;
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__11__cc 
                                        = (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U));
                                    vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__11__FF 
                                        = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F;
                                    vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__11__Vfuncout 
                                        = (1U & ((4U 
                                                  & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__11__cc))
                                                  ? 
                                                 ((2U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__11__cc))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__11__cc))
                                                    ? 
                                                   ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__11__FF) 
                                                    >> 7U)
                                                    : 
                                                   (~ 
                                                    ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__11__FF) 
                                                     >> 7U)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__11__cc))
                                                    ? 
                                                   ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__11__FF) 
                                                    >> 2U)
                                                    : 
                                                   (~ 
                                                    ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__11__FF) 
                                                     >> 2U))))
                                                  : 
                                                 ((2U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__11__cc))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__11__cc))
                                                    ? (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__11__FF)
                                                    : 
                                                   (~ (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__11__FF)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__11__cc))
                                                    ? 
                                                   ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__11__FF) 
                                                    >> 6U)
                                                    : 
                                                   (~ 
                                                    ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__11__FF) 
                                                     >> 6U))))));
                                    if (vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__11__Vfuncout) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xdU;
                                    } else {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                    }
                                } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xcU;
                                }
                            }
                        }
                    } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 5U;
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                            } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To = 5U;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 5U;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                            } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To = 4U;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 4U;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                            } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 5U;
                            }
                        } else {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        }
                    } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                        } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = ((3U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                                    ? 0xbU : ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                              | (1U 
                                                 | ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                                    << 1U))));
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = ((3U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                                    ? 7U : ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                            | ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                               << 1U)));
                        }
                    } else {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__13__cc 
                                = (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                         >> 3U));
                            vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__13__FF 
                                = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 5U;
                            vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__13__Vfuncout 
                                = (1U & ((4U & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__13__cc))
                                          ? ((2U & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__13__cc))
                                              ? ((1U 
                                                  & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__13__cc))
                                                  ? 
                                                 ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__13__FF) 
                                                  >> 7U)
                                                  : 
                                                 (~ 
                                                  ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__13__FF) 
                                                   >> 7U)))
                                              : ((1U 
                                                  & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__13__cc))
                                                  ? 
                                                 ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__13__FF) 
                                                  >> 2U)
                                                  : 
                                                 (~ 
                                                  ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__13__FF) 
                                                   >> 2U))))
                                          : ((2U & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__13__cc))
                                              ? ((1U 
                                                  & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__13__cc))
                                                  ? (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__13__FF)
                                                  : 
                                                 (~ (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__13__FF)))
                                              : ((1U 
                                                  & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__13__cc))
                                                  ? 
                                                 ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__13__FF) 
                                                  >> 6U)
                                                  : 
                                                 (~ 
                                                  ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__13__FF) 
                                                   >> 6U))))));
                            if (vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__13__Vfuncout) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                            } else {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 1U;
                            }
                        } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                        }
                    }
                } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 5U;
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xdU;
                                    } else if ((2U 
                                                & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xcU;
                                    }
                                } else {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                            = ((8U 
                                                & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                               | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS));
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                            = (7U | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To));
                                    }
                                }
                            } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 5U;
                                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                              >> 1U)))) {
                                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__14__cc 
                                            = (7U & 
                                               ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U));
                                        vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__14__FF 
                                            = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F;
                                        vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__14__Vfuncout 
                                            = (1U & 
                                               ((4U 
                                                 & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__14__cc))
                                                 ? 
                                                ((2U 
                                                  & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__14__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__14__cc))
                                                   ? 
                                                  ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__14__FF) 
                                                   >> 7U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__14__FF) 
                                                    >> 7U)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__14__cc))
                                                   ? 
                                                  ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__14__FF) 
                                                   >> 2U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__14__FF) 
                                                    >> 2U))))
                                                 : 
                                                ((2U 
                                                  & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__14__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__14__cc))
                                                   ? (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__14__FF)
                                                   : 
                                                  (~ (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__14__FF)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__14__cc))
                                                   ? 
                                                  ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__14__FF) 
                                                   >> 6U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__14__FF) 
                                                    >> 6U))))));
                                        if (vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__14__Vfuncout) {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xdU;
                                        } else {
                                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                        }
                                    } else if ((8U 
                                                & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xcU;
                                    }
                                }
                            }
                        } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 4U;
                                }
                            } else {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            }
                        } else if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__16__cc 
                                    = (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U));
                                vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__16__FF 
                                    = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 5U;
                                vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__16__Vfuncout 
                                    = (1U & ((4U & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__16__cc))
                                              ? ((2U 
                                                  & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__16__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__16__cc))
                                                   ? 
                                                  ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__16__FF) 
                                                   >> 7U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__16__FF) 
                                                    >> 7U)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__16__cc))
                                                   ? 
                                                  ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__16__FF) 
                                                   >> 2U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__16__FF) 
                                                    >> 2U))))
                                              : ((2U 
                                                  & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__16__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__16__cc))
                                                   ? (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__16__FF)
                                                   : 
                                                  (~ (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__16__FF)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__16__cc))
                                                   ? 
                                                  ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__16__FF) 
                                                   >> 6U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__16__FF) 
                                                    >> 6U))))));
                                if (vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__16__Vfuncout) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                } else {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 1U;
                                }
                            } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                            }
                        }
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 5U;
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xdU;
                                } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xcU;
                                }
                            } else {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                        = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                           | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS));
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                        = (7U | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To));
                                }
                            }
                        } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 5U;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                    = ((3U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                                        ? 7U : ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                                << 1U));
                            } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                    = ((3U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                                        ? 0xbU : (1U 
                                                  | ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                                     << 1U)));
                            }
                        } else {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 5U;
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__17__cc 
                                        = (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U));
                                    vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__17__FF 
                                        = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F;
                                    vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__17__Vfuncout 
                                        = (1U & ((4U 
                                                  & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__17__cc))
                                                  ? 
                                                 ((2U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__17__cc))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__17__cc))
                                                    ? 
                                                   ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__17__FF) 
                                                    >> 7U)
                                                    : 
                                                   (~ 
                                                    ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__17__FF) 
                                                     >> 7U)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__17__cc))
                                                    ? 
                                                   ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__17__FF) 
                                                    >> 2U)
                                                    : 
                                                   (~ 
                                                    ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__17__FF) 
                                                     >> 2U))))
                                                  : 
                                                 ((2U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__17__cc))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__17__cc))
                                                    ? (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__17__FF)
                                                    : 
                                                   (~ (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__17__FF)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__17__cc))
                                                    ? 
                                                   ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__17__FF) 
                                                    >> 6U)
                                                    : 
                                                   (~ 
                                                    ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__17__FF) 
                                                     >> 6U))))));
                                    if (vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__17__Vfuncout) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xdU;
                                    } else {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                    }
                                } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xcU;
                                }
                            }
                        }
                    } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 4U;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 7U;
                            }
                        } else {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        }
                    } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                        } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = ((3U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                                    ? 0xbU : ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                              | (1U 
                                                 | ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                                    << 1U))));
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = ((3U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                                    ? 7U : ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                            | ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                               << 1U)));
                        }
                    } else {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__19__cc 
                                = (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                         >> 3U));
                            vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__19__FF 
                                = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 5U;
                            vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__19__Vfuncout 
                                = (1U & ((4U & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__19__cc))
                                          ? ((2U & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__19__cc))
                                              ? ((1U 
                                                  & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__19__cc))
                                                  ? 
                                                 ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__19__FF) 
                                                  >> 7U)
                                                  : 
                                                 (~ 
                                                  ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__19__FF) 
                                                   >> 7U)))
                                              : ((1U 
                                                  & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__19__cc))
                                                  ? 
                                                 ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__19__FF) 
                                                  >> 2U)
                                                  : 
                                                 (~ 
                                                  ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__19__FF) 
                                                   >> 2U))))
                                          : ((2U & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__19__cc))
                                              ? ((1U 
                                                  & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__19__cc))
                                                  ? (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__19__FF)
                                                  : 
                                                 (~ (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__19__FF)))
                                              : ((1U 
                                                  & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__19__cc))
                                                  ? 
                                                 ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__19__FF) 
                                                  >> 6U)
                                                  : 
                                                 (~ 
                                                  ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__19__FF) 
                                                   >> 6U))))));
                            if (vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__19__Vfuncout) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                            } else {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 1U;
                            }
                        } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                        }
                    }
                } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 5U;
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xdU;
                                } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xcU;
                                }
                            } else {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                        = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                           | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS));
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                        = (7U | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To));
                                }
                            }
                        } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 5U;
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xdU;
                                } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xcU;
                                }
                            }
                        } else {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 5U;
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__20__cc 
                                        = (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U));
                                    vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__20__FF 
                                        = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F;
                                    vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__20__Vfuncout 
                                        = (1U & ((4U 
                                                  & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__20__cc))
                                                  ? 
                                                 ((2U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__20__cc))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__20__cc))
                                                    ? 
                                                   ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__20__FF) 
                                                    >> 7U)
                                                    : 
                                                   (~ 
                                                    ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__20__FF) 
                                                     >> 7U)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__20__cc))
                                                    ? 
                                                   ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__20__FF) 
                                                    >> 2U)
                                                    : 
                                                   (~ 
                                                    ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__20__FF) 
                                                     >> 2U))))
                                                  : 
                                                 ((2U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__20__cc))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__20__cc))
                                                    ? (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__20__FF)
                                                    : 
                                                   (~ (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__20__FF)))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__20__cc))
                                                    ? 
                                                   ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__20__FF) 
                                                    >> 6U)
                                                    : 
                                                   (~ 
                                                    ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__20__FF) 
                                                     >> 6U))))));
                                    if (vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__20__Vfuncout) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xdU;
                                    } else {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                    }
                                } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xcU;
                                }
                            }
                        }
                    } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        }
                    } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 5U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                        } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                        }
                    } else {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__22__cc 
                                = (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                         >> 3U));
                            vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__22__FF 
                                = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 5U;
                            vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__22__Vfuncout 
                                = (1U & ((4U & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__22__cc))
                                          ? ((2U & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__22__cc))
                                              ? ((1U 
                                                  & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__22__cc))
                                                  ? 
                                                 ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__22__FF) 
                                                  >> 7U)
                                                  : 
                                                 (~ 
                                                  ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__22__FF) 
                                                   >> 7U)))
                                              : ((1U 
                                                  & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__22__cc))
                                                  ? 
                                                 ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__22__FF) 
                                                  >> 2U)
                                                  : 
                                                 (~ 
                                                  ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__22__FF) 
                                                   >> 2U))))
                                          : ((2U & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__22__cc))
                                              ? ((1U 
                                                  & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__22__cc))
                                                  ? (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__22__FF)
                                                  : 
                                                 (~ (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__22__FF)))
                                              : ((1U 
                                                  & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__22__cc))
                                                  ? 
                                                 ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__22__FF) 
                                                  >> 6U)
                                                  : 
                                                 (~ 
                                                  ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__22__FF) 
                                                   >> 6U))))));
                            if (vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__22__Vfuncout) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                            } else {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 1U;
                            }
                        } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                        }
                    }
                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 5U;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xdU;
                            } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xcU;
                            }
                        } else {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                    = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                       | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS));
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = (7U | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To));
                            }
                        }
                    } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 5U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                = ((3U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                                    ? 7U : ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                            << 1U));
                        } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                = ((3U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                                    ? 0xbU : (1U | 
                                              ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                               << 1U)));
                        }
                    } else {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 5U;
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 1U)))) {
                            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__23__cc 
                                    = (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U));
                                vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__23__FF 
                                    = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F;
                                vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__23__Vfuncout 
                                    = (1U & ((4U & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__23__cc))
                                              ? ((2U 
                                                  & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__23__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__23__cc))
                                                   ? 
                                                  ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__23__FF) 
                                                   >> 7U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__23__FF) 
                                                    >> 7U)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__23__cc))
                                                   ? 
                                                  ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__23__FF) 
                                                   >> 2U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__23__FF) 
                                                    >> 2U))))
                                              : ((2U 
                                                  & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__23__cc))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__23__cc))
                                                   ? (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__23__FF)
                                                   : 
                                                  (~ (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__23__FF)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__23__cc))
                                                   ? 
                                                  ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__23__FF) 
                                                   >> 6U)
                                                   : 
                                                  (~ 
                                                   ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__23__FF) 
                                                    >> 6U))))));
                                if (vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__23__Vfuncout) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xdU;
                                } else {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                }
                            } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xcU;
                            }
                        }
                    }
                } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                    } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = ((3U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                                ? 0xbU : ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                          | (1U | ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                                   << 1U))));
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = ((3U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                                ? 7U : ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                        | ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                           << 1U)));
                    }
                } else {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__25__cc 
                            = (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                     >> 3U));
                        vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__25__FF 
                            = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F;
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 5U;
                        vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__25__Vfuncout 
                            = (1U & ((4U & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__25__cc))
                                      ? ((2U & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__25__cc))
                                          ? ((1U & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__25__cc))
                                              ? ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__25__FF) 
                                                 >> 7U)
                                              : (~ 
                                                 ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__25__FF) 
                                                  >> 7U)))
                                          : ((1U & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__25__cc))
                                              ? ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__25__FF) 
                                                 >> 2U)
                                              : (~ 
                                                 ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__25__FF) 
                                                  >> 2U))))
                                      : ((2U & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__25__cc))
                                          ? ((1U & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__25__cc))
                                              ? (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__25__FF)
                                              : (~ (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__25__FF)))
                                          : ((1U & (IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__25__cc))
                                              ? ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__25__FF) 
                                                 >> 6U)
                                              : (~ 
                                                 ((IData)(vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__25__FF) 
                                                  >> 6U))))));
                        if (vlTOPp->__Vfunc_emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__is_cc_true__25__Vfuncout) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                        } else {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 1U;
                        }
                    } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                    }
                }
            } else if ((6U == (7U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                        = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                           | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS));
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                        = (7U | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To));
                }
            } else {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                    = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                       | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS));
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                    = (7U | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To));
            }
        } else if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((0x36U != (0x3fU & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                if ((6U == (7U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                    }
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                               | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                    }
                } else if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                         >> 3U)))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                            = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS;
                    }
                } else {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                        = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                           | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS));
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                        = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                           | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                }
            }
        } else if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                                if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                            = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS;
                                    }
                                } else {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                            = ((8U 
                                                & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                               | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                                    }
                                }
                            }
                        } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                                } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                        = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                           | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                                }
                            } else {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                       | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                            }
                        } else if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U)))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                            } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                       | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                            }
                        } else {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                   | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                        }
                    } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 6U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 
                                = (0xcU | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR));
                        } else {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 4U;
                            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 6U;
                            }
                        }
                    } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = (5U | (8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)));
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                = ((((0U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                   >> 4U))) 
                                     | (1U == (3U & 
                                               ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U)))) 
                                    | (2U == (3U & 
                                              ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                               >> 4U))))
                                    ? ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                       | (1U | (6U 
                                                & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U))))
                                    : 8U);
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = (4U | (8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)));
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                = ((((0U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                   >> 4U))) 
                                     | (1U == (3U & 
                                               ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U)))) 
                                    | (2U == (3U & 
                                              ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                               >> 4U))))
                                    ? ((9U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                       | (6U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)))
                                    : 9U);
                        }
                    } else {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            if ((0U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d 
                                    = ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F))
                                        ? 2U : 3U);
                            } else if ((1U == (3U & 
                                               ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d 
                                    = ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F))
                                        ? 3U : 2U);
                            } else if ((2U == (3U & 
                                               ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d 
                                    = ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F))
                                        ? 2U : 3U);
                            } else if ((3U == (3U & 
                                               ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d 
                                    = ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F))
                                        ? 3U : 2U);
                            }
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 5U;
                        }
                    }
                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                        = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS;
                                }
                            } else {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                        = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                           | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                                }
                            }
                        }
                    } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                            } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                       | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                            }
                        } else {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                   | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                        }
                    } else if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                        } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                   | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                        }
                    } else {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                               | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                    }
                } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 6U;
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 
                            = (4U | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR));
                    } else {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 4U;
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 1U)))) {
                            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 6U;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 7U;
                            }
                        }
                    }
                } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = ((3U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                                ? 8U : ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                        | (1U | ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                                 << 1U))));
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = ((3U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                                ? 9U : ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                        | ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                           << 1U)));
                    }
                } else {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        if ((0U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d 
                                = ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F))
                                    ? 2U : 3U);
                        } else if ((1U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U)))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d 
                                = ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F))
                                    ? 3U : 2U);
                        } else if ((2U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U)))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d 
                                = ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F))
                                    ? 2U : 3U);
                        } else if ((3U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U)))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d 
                                = ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F))
                                    ? 3U : 2U);
                        }
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 5U;
                    }
                }
            } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                        = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS;
                                }
                            } else {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                        = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                           | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                                }
                            }
                        }
                    } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                            } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                       | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                            }
                        } else {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                   | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                        }
                    } else if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                        } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                   | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                        }
                    } else {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                               | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                    }
                } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 6U;
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 
                            = (0xcU | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR));
                    } else {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 5U;
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 1U)))) {
                            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 6U;
                            } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = (5U | (8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)));
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 6U;
                            } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = (4U | (8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)));
                            }
                        }
                    }
                } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = (5U | (8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)));
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                            = ((((0U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                               >> 4U))) 
                                 | (1U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                 >> 4U)))) 
                                | (2U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U))))
                                ? ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                   | (1U | (6U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U))))
                                : 8U);
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = (4U | (8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)));
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                            = ((((0U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                               >> 4U))) 
                                 | (1U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                 >> 4U)))) 
                                | (2U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U))))
                                ? ((9U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                   | (6U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                            >> 3U)))
                                : 9U);
                    }
                } else {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        if ((0U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d 
                                = ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F))
                                    ? 2U : 3U);
                        } else if ((1U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U)))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d 
                                = ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F))
                                    ? 3U : 2U);
                        } else if ((2U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U)))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d 
                                = ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F))
                                    ? 2U : 3U);
                        } else if ((3U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U)))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d 
                                = ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F))
                                    ? 3U : 2U);
                        }
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 5U;
                    }
                }
            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = (7U | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To));
                    } else if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS;
                        }
                    } else {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                   | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                        }
                    }
                } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 3U)))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                        } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                   | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                        }
                    } else {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                               | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                    }
                } else if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                         >> 3U)))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                    } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                               | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                    }
                } else {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                        = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                           | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                }
            } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 6U;
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 
                        = (4U | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR));
                } else {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 5U;
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                  >> 1U)))) {
                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 6U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 5U;
                        } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 6U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 4U;
                        }
                    }
                }
            } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                        = ((3U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                            ? 8U : ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                    | (1U | ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                             << 1U))));
                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                        = ((3U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                            ? 9U : ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                    | ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                       << 1U)));
                }
            } else {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    if ((0U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 3U)))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d 
                            = ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F))
                                ? 2U : 3U);
                    } else if ((1U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d 
                            = ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F))
                                ? 3U : 2U);
                    } else if ((2U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d 
                            = ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F))
                                ? 2U : 3U);
                    } else if ((3U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d 
                            = ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__F))
                                ? 3U : 2U);
                    }
                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 5U;
                }
            }
        } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = (7U | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To));
                        } else if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                 >> 3U)))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                    = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS;
                            }
                        } else {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                       | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                            }
                        }
                    } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                            } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                       | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                            }
                        } else {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                   | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                        }
                    } else if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                        } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                   | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                        }
                    } else {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                               | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                    }
                } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 6U;
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 
                            = (0xcU | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR));
                    } else {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 1U;
                        }
                    }
                } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = (5U | (8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)));
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                            = ((((0U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                               >> 4U))) 
                                 | (1U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                 >> 4U)))) 
                                | (2U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U))))
                                ? ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                   | (1U | (6U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U))))
                                : 8U);
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = (4U | (8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)));
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                            = ((((0U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                               >> 4U))) 
                                 | (1U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                 >> 4U)))) 
                                | (2U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U))))
                                ? ((9U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                   | (6U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                            >> 3U)))
                                : 9U);
                    }
                } else {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                  >> 1U)))) {
                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 5U;
                        }
                    }
                }
            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = (7U | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To));
                    } else if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS;
                        }
                    } else {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                   | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                        }
                    }
                } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 3U)))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                        } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                   | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                        }
                    } else {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                               | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                    }
                } else if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                         >> 3U)))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                    } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                               | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                    }
                } else {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                        = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                           | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                }
            } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 6U;
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 
                        = (4U | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR));
                } else {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 1U;
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 7U;
                    }
                }
            } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                        = ((3U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                            ? 8U : ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                    | (1U | ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                             << 1U))));
                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                        = ((3U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                            ? 9U : ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                    | ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                       << 1U)));
                }
            } else {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 5U;
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                        = (8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To));
                } else if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                     >> 1U)))) {
                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 5U;
                    }
                }
            }
        } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = (7U | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To));
                    } else if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 3U)))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS;
                        }
                    } else {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                   | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                        }
                    }
                } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 3U)))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                        } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                   | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                        }
                    } else {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                               | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                    }
                } else if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                         >> 3U)))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                    } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                               | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                    }
                } else {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                        = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                           | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                }
            } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 6U;
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 
                        = (0xcU | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR));
                } else {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 0U;
                    }
                }
            } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                        = (5U | (8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)));
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                        = ((((0U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                           >> 4U))) 
                             | (1U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 4U)))) 
                            | (2U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                            >> 4U))))
                            ? ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                               | (1U | (6U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U))))
                            : 8U);
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                        = (4U | (8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)));
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                        = ((((0U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                           >> 4U))) 
                             | (1U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 4U)))) 
                            | (2U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                            >> 4U))))
                            ? ((9U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                               | (6U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                        >> 3U))) : 9U);
                }
            }
        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                        = (7U | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To));
                } else if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                         >> 3U)))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                            = vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__SSS;
                    }
                } else {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                               | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                    }
                }
            } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                  >> 3U)))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                    } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                               | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                    }
                } else {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                        = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                           | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                }
            } else if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                     >> 3U)))) {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                        = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                           | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
                }
            } else {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                    = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                       | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DDD));
            }
        } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 6U;
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 
                    = (4U | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR));
            } else {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 0U;
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 7U;
                }
            }
        } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                    = ((3U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                        ? 8U : ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                | (1U | ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                         << 1U))));
            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                    = ((3U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR))
                        ? 9U : ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                | ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__i_mcode__DOT__DPAIR) 
                                   << 1U)));
            }
        } else if (vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__NMICycle) {
            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 5U;
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xdU;
            } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xcU;
            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
            }
        } else if (vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IntCycle) {
            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 5U;
            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 5U;
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xdU;
            } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xfU;
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xcU;
            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
            }
        }
    } else if ((1U == (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__ISet))) {
        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
            = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
               | (7U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)));
        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
            = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
               | (7U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)));
        if ((0x80U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            if ((IData)((0U != (0x41U 
                                                & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                            } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                            }
                        }
                    }
                }
            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((IData)((0U != (0x41U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                        } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                        }
                    }
                }
            }
        } else if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                   | (7U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)));
                        }
                    } else {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                        if ((IData)((0U != (0x41U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                        } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                        }
                    }
                } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                        = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                           | (7U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)));
                }
            } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                    = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                       | (7U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)));
            }
        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR)))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                    if ((IData)((0U != (0x41U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                    } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                    }
                }
            }
        }
    } else if ((0x80U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                      >> 6U)))) {
            if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                              >> 2U)))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 4U;
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 5U;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To = 0U;
                            } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 6U;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 0U;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 
                                    = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))
                                        ? 0xeU : 6U);
                            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 
                                    = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))
                                        ? 0xaU : 2U);
                            } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 5U;
                            }
                        } else {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 4U;
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 0U;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 0xaU;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To = 0U;
                            } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 6U;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 
                                    = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))
                                        ? 0xeU : 6U);
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                            } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 5U;
                            }
                        }
                    } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 4U;
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xcU;
                        } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 6U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = (7U | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To));
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 
                                = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))
                                    ? 0xeU : 6U);
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 5U;
                        } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 5U;
                        }
                    } else {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 4U;
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 0xcU;
                        } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 6U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = (7U | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To));
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 1U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 
                                = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))
                                    ? 0xeU : 6U);
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 5U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 
                                = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))
                                    ? 0xdU : 5U);
                        } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 5U;
                        }
                    }
                }
            }
        }
    } else if ((0x40U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
        if ((0x20U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 1U)))) {
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                                }
                            } else {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 7U;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To = 0xaU;
                            }
                        }
                    } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 5U;
                            if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                          >> 1U)))) {
                                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 6U;
                                } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                        = ((3U == (3U 
                                                   & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                      >> 4U)))
                                            ? 8U : 
                                           ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                            | (1U | 
                                               (6U 
                                                & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U)))));
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 6U;
                                } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                        = ((3U == (3U 
                                                   & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                      >> 4U)))
                                            ? 9U : 
                                           ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                            | (6U & 
                                               ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U))));
                                }
                            }
                        } else {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = (5U | (8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)));
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                    = ((((0U == (3U 
                                                 & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                    >> 4U))) 
                                         | (1U == (3U 
                                                   & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                      >> 4U)))) 
                                        | (2U == (3U 
                                                  & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                     >> 4U))))
                                        ? ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                           | (1U | 
                                              (6U & 
                                               ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U))))
                                        : 8U);
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = (4U | (8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)));
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                    = ((((0U == (3U 
                                                 & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                    >> 4U))) 
                                         | (1U == (3U 
                                                   & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                      >> 4U)))) 
                                        | (2U == (3U 
                                                  & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                     >> 4U))))
                                        ? ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                           | (6U & 
                                              ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                               >> 3U)))
                                        : 9U);
                            }
                        }
                    } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 0U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                   | (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                            >> 3U)));
                            if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                    = (8U | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To));
                            }
                        }
                    } else {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 0U;
                        } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            if ((6U != (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                       | (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)));
                            }
                        }
                    }
                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                  >> 1U)))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                            } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                            }
                        } else {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 7U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To = 0xaU;
                        }
                    }
                } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 5U;
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 1U)))) {
                            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 6U;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                    = ((3U == (3U & 
                                               ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U)))
                                        ? 8U : (1U 
                                                | (6U 
                                                   & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                      >> 3U))));
                            } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 6U;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                    = ((3U == (3U & 
                                               ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U)))
                                        ? 9U : (6U 
                                                & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U)));
                            }
                        }
                    } else {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = (5U | (8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)));
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                = ((((0U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                   >> 4U))) 
                                     | (1U == (3U & 
                                               ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U)))) 
                                    | (2U == (3U & 
                                              ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                               >> 4U))))
                                    ? ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                       | (1U | (6U 
                                                & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U))))
                                    : 8U);
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = (4U | (8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)));
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                = ((((0U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                   >> 4U))) 
                                     | (1U == (3U & 
                                               ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U)))) 
                                    | (2U == (3U & 
                                              ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                               >> 4U))))
                                    ? ((9U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                       | (6U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)))
                                    : 9U);
                        }
                    }
                } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 0U;
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                            = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                               | (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                        >> 3U)));
                        if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                = (8U | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To));
                        }
                    }
                } else {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 0U;
                    } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        if ((6U != (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                   | (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                            >> 3U)));
                        }
                    }
                }
            } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 4U;
                            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                    = (6U | (8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)));
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = (7U | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To));
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                            }
                        }
                    } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                        } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                        }
                    } else {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 7U;
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To = 0xaU;
                    }
                } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 5U;
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 1U)))) {
                            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 6U;
                            } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = ((3U == (3U & 
                                               ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U)))
                                        ? 8U : ((8U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                                | (1U 
                                                   | (6U 
                                                      & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                         >> 3U)))));
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 6U;
                            } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = ((3U == (3U & 
                                               ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U)))
                                        ? 9U : ((8U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                                | (6U 
                                                   & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                      >> 3U))));
                            }
                        }
                    } else {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = (5U | (8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)));
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                = ((((0U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                   >> 4U))) 
                                     | (1U == (3U & 
                                               ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U)))) 
                                    | (2U == (3U & 
                                              ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                               >> 4U))))
                                    ? ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                       | (1U | (6U 
                                                & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U))))
                                    : 8U);
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = (4U | (8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)));
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                = ((((0U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                   >> 4U))) 
                                     | (1U == (3U & 
                                               ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U)))) 
                                    | (2U == (3U & 
                                              ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                               >> 4U))))
                                    ? ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                       | (6U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)))
                                    : 9U);
                        }
                    }
                } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 0U;
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                            = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                               | (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                        >> 3U)));
                        if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                = (8U | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To));
                        }
                    }
                } else {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 0U;
                    } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        if ((6U != (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                   | (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                            >> 3U)));
                        }
                    }
                }
            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 4U;
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                = (6U | (8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)));
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = (7U | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To));
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 2U;
                        }
                    }
                } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                    } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                    }
                } else {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 7U;
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To = 0xaU;
                }
            } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 5U;
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                  >> 1U)))) {
                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 6U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                = ((3U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                 >> 4U)))
                                    ? 8U : (1U | (6U 
                                                  & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                     >> 3U))));
                        } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 6U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                = ((3U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                 >> 4U)))
                                    ? 9U : (6U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)));
                        }
                    }
                } else {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = (5U | (8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)));
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                            = ((((0U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                               >> 4U))) 
                                 | (1U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                 >> 4U)))) 
                                | (2U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U))))
                                ? ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                   | (1U | (6U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U))))
                                : 8U);
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = (4U | (8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)));
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                            = ((((0U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                               >> 4U))) 
                                 | (1U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                 >> 4U)))) 
                                | (2U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U))))
                                ? ((9U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                   | (6U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                            >> 3U)))
                                : 9U);
                    }
                }
            } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 0U;
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                        = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                           | (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                    >> 3U)));
                    if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 3U)))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                            = (8U | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To));
                    }
                }
            } else {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 0U;
                } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    if ((6U != (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 3U)))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                               | (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                        >> 3U)));
                    }
                }
            }
        } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 5U;
                        }
                    } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                        } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                        }
                    } else {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 7U;
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To = 0xaU;
                    }
                } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 5U;
                        if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                      >> 1U)))) {
                            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 6U;
                            } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = ((3U == (3U & 
                                               ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U)))
                                        ? 8U : ((8U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                                | (1U 
                                                   | (6U 
                                                      & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                         >> 3U)))));
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 6U;
                            } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                    = ((3U == (3U & 
                                               ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U)))
                                        ? 9U : ((8U 
                                                 & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                                | (6U 
                                                   & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                      >> 3U))));
                            }
                        }
                    } else {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                        if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = (5U | (8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)));
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                = ((((0U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                   >> 4U))) 
                                     | (1U == (3U & 
                                               ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U)))) 
                                    | (2U == (3U & 
                                              ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                               >> 4U))))
                                    ? ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                       | (1U | (6U 
                                                & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U))))
                                    : 8U);
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = (4U | (8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)));
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                = ((((0U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                   >> 4U))) 
                                     | (1U == (3U & 
                                               ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U)))) 
                                    | (2U == (3U & 
                                              ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                               >> 4U))))
                                    ? ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                       | (6U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U)))
                                    : 9U);
                        }
                    }
                } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 0U;
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                            = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                               | (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                        >> 3U)));
                        if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                = (8U | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To));
                        }
                    }
                } else {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 0U;
                    } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        if ((6U != (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                          >> 3U)))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                   | (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                            >> 3U)));
                        }
                    }
                }
            } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 5U;
                    }
                } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                    } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                    }
                } else {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 7U;
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To = 0xaU;
                }
            } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 5U;
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                  >> 1U)))) {
                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 6U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                = ((3U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                 >> 4U)))
                                    ? 8U : (1U | (6U 
                                                  & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                     >> 3U))));
                        } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 6U;
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                                = ((3U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                 >> 4U)))
                                    ? 9U : (6U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U)));
                        }
                    }
                } else {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = (5U | (8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)));
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                            = ((((0U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                               >> 4U))) 
                                 | (1U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                 >> 4U)))) 
                                | (2U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U))))
                                ? ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                   | (1U | (6U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U))))
                                : 8U);
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = (4U | (8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)));
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                            = ((((0U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                               >> 4U))) 
                                 | (1U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                 >> 4U)))) 
                                | (2U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U))))
                                ? ((9U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                   | (6U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                            >> 3U)))
                                : 9U);
                    }
                }
            } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 0U;
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                        = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                           | (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                    >> 3U)));
                    if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 3U)))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                            = (8U | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To));
                    }
                }
            } else {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 0U;
                } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    if ((6U != (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 3U)))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                               | (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                        >> 3U)));
                    }
                }
            }
        } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 5U;
                    }
                } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                    if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                    } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                    }
                } else {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 7U;
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To = 0xaU;
                }
            } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 5U;
                    if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                                  >> 1U)))) {
                        if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 6U;
                        } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = ((3U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                 >> 4U)))
                                    ? 8U : ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                            | (1U | 
                                               (6U 
                                                & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                   >> 3U)))));
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 6U;
                        } else if ((0x10U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                                = ((3U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                 >> 4U)))
                                    ? 9U : ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                                            | (6U & 
                                               ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 3U))));
                        }
                    }
                } else {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                    if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = (5U | (8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)));
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                            = ((((0U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                               >> 4U))) 
                                 | (1U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                 >> 4U)))) 
                                | (2U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U))))
                                ? ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                   | (1U | (6U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                  >> 3U))))
                                : 8U);
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                    } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = (4U | (8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)));
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                            = ((((0U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                               >> 4U))) 
                                 | (1U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                 >> 4U)))) 
                                | (2U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                                >> 4U))))
                                ? ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                                   | (6U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                            >> 3U)))
                                : 9U);
                    }
                }
            } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 0U;
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                        = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                           | (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                    >> 3U)));
                    if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 3U)))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                            = (8U | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To));
                    }
                }
            } else {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 2U;
                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 0U;
                } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    if ((6U != (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                      >> 3U)))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                            = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                               | (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                        >> 3U)));
                    }
                }
            }
        } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 5U;
                }
            } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 5U;
                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IncDec_16 = 7U;
                }
            } else {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To = 7U;
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To = 0xaU;
            }
        } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 5U;
                if ((1U & (~ ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle) 
                              >> 1U)))) {
                    if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 6U;
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                            = ((3U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 4U)))
                                ? 8U : (1U | (6U & 
                                              ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                               >> 3U))));
                    } else if ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 6U;
                        vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                            = ((3U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 4U)))
                                ? 9U : (6U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U)));
                    }
                }
            } else {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 3U;
                if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                        = (5U | (8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)));
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                        = ((((0U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                           >> 4U))) 
                             | (1U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 4U)))) 
                            | (2U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                            >> 4U))))
                            ? ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                               | (1U | (6U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                              >> 3U))))
                            : 8U);
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__tstates = 4U;
                } else if ((4U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                        = (4U | (8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)));
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                        = ((((0U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                           >> 4U))) 
                             | (1U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                             >> 4U)))) 
                            | (2U == (3U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                            >> 4U))))
                            ? ((9U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                               | (6U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                        >> 3U))) : 9U);
                }
            }
        } else if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR))) {
            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 2U;
            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 0U;
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                    = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To)) 
                       | (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                >> 3U)));
                if ((6U == (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                  >> 3U)))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To 
                        = (8U | (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusB_To));
                }
            }
        } else {
            vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycles_d = 2U;
            if ((1U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_Addr_To = 0U;
            } else if ((2U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__mcycle))) {
                if ((6U != (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                  >> 3U)))) {
                    vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To 
                        = ((8U & (IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__Set_BusA_To)) 
                           | (7U & ((IData)(vlTOPp->emu__DOT__system__DOT__T80x__DOT__i_tv80_core__DOT__IR) 
                                    >> 3U)));
                }
            }
        }
    }
}
