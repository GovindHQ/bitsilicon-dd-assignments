// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vstopwatch_top.h for the primary calling header

#include "Vstopwatch_top__pch.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vstopwatch_top___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vstopwatch_top___024root___eval_triggers__ico(Vstopwatch_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___eval_triggers__ico\n"); );
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VicoFirstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vstopwatch_top___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
}

bool Vstopwatch_top___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___trigger_anySet__ico\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vstopwatch_top___024root___ico_sequent__TOP__0(Vstopwatch_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___ico_sequent__TOP__0\n"); );
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.status = ((IData)(vlSelfRef.rst_n) ? 
                        ((0U == (IData)(vlSelfRef.stopwatch_top__DOT__mode_reg))
                          ? 0U : ((1U == (IData)(vlSelfRef.stopwatch_top__DOT__mode_reg))
                                   ? 1U : ((2U == (IData)(vlSelfRef.stopwatch_top__DOT__mode_reg))
                                            ? 2U : 0U)))
                         : 0U);
}

void Vstopwatch_top___024root___eval_ico(Vstopwatch_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___eval_ico\n"); );
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered[0U])) {
        vlSelfRef.status = ((IData)(vlSelfRef.rst_n)
                             ? ((0U == (IData)(vlSelfRef.stopwatch_top__DOT__mode_reg))
                                 ? 0U : ((1U == (IData)(vlSelfRef.stopwatch_top__DOT__mode_reg))
                                          ? 1U : ((2U 
                                                   == (IData)(vlSelfRef.stopwatch_top__DOT__mode_reg))
                                                   ? 2U
                                                   : 0U)))
                             : 0U);
    }
}

bool Vstopwatch_top___024root___eval_phase__ico(Vstopwatch_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___eval_phase__ico\n"); );
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    Vstopwatch_top___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = Vstopwatch_top___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        Vstopwatch_top___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vstopwatch_top___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vstopwatch_top___024root___eval_triggers__act(Vstopwatch_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___eval_triggers__act\n"); );
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((((~ (IData)(vlSelfRef.rst_n)) 
                                                       & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0)) 
                                                      << 1U) 
                                                     | ((IData)(vlSelfRef.clk) 
                                                        & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0 = vlSelfRef.rst_n;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vstopwatch_top___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
}

bool Vstopwatch_top___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

extern const VlUnpacked<CData/*0:0*/, 512> Vstopwatch_top__ConstPool__TABLE_hdeadfca2_0;
extern const VlUnpacked<CData/*5:0*/, 512> Vstopwatch_top__ConstPool__TABLE_h7258e8ae_0;

void Vstopwatch_top___024root___nba_sequent__TOP__0(Vstopwatch_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___nba_sequent__TOP__0\n"); );
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    SData/*8:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*7:0*/ __Vdly__minutes;
    __Vdly__minutes = 0;
    // Body
    __Vdly__minutes = vlSelfRef.minutes;
    __Vtableidx1 = (((IData)(vlSelfRef.seconds) << 3U) 
                    | (((IData)(vlSelfRef.stopwatch_top__DOT__mode_reg) 
                        << 1U) | (IData)(vlSelfRef.rst_n)));
    if (vlSelfRef.rst_n) {
        if ((0U == (IData)(vlSelfRef.stopwatch_top__DOT__mode_reg))) {
            __Vdly__minutes = 0U;
        } else if ((1U == (IData)(vlSelfRef.stopwatch_top__DOT__mode_reg))) {
            __Vdly__minutes = vlSelfRef.minutes;
        } else if ((2U == (IData)(vlSelfRef.stopwatch_top__DOT__mode_reg))) {
            if ((0x63U > (IData)(vlSelfRef.minutes))) {
                if (((2U == (IData)(vlSelfRef.stopwatch_top__DOT__mode_reg)) 
                     & (0x3bU == (IData)(vlSelfRef.seconds)))) {
                    __Vdly__minutes = (0x000000ffU 
                                       & ((IData)(1U) 
                                          + (IData)(vlSelfRef.minutes)));
                }
            }
        }
        if (vlSelfRef.rst) {
            vlSelfRef.stopwatch_top__DOT__mode_reg = 0U;
        } else if (vlSelfRef.stop) {
            vlSelfRef.stopwatch_top__DOT__mode_reg = 1U;
        } else if (vlSelfRef.start) {
            vlSelfRef.stopwatch_top__DOT__mode_reg = 2U;
        }
        vlSelfRef.status = ((0U == (IData)(vlSelfRef.stopwatch_top__DOT__mode_reg))
                             ? 0U : ((1U == (IData)(vlSelfRef.stopwatch_top__DOT__mode_reg))
                                      ? 1U : ((2U == (IData)(vlSelfRef.stopwatch_top__DOT__mode_reg))
                                               ? 2U
                                               : 0U)));
    } else {
        __Vdly__minutes = 0U;
        vlSelfRef.stopwatch_top__DOT__mode_reg = 0U;
        vlSelfRef.status = 0U;
    }
    if (Vstopwatch_top__ConstPool__TABLE_hdeadfca2_0
        [__Vtableidx1]) {
        vlSelfRef.seconds = Vstopwatch_top__ConstPool__TABLE_h7258e8ae_0
            [__Vtableidx1];
    }
    vlSelfRef.minutes = __Vdly__minutes;
}

void Vstopwatch_top___024root___eval_nba(Vstopwatch_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___eval_nba\n"); );
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    SData/*8:0*/ __Vinline__nba_sequent__TOP__0___Vtableidx1;
    __Vinline__nba_sequent__TOP__0___Vtableidx1 = 0;
    CData/*7:0*/ __Vinline__nba_sequent__TOP__0___Vdly__minutes;
    __Vinline__nba_sequent__TOP__0___Vdly__minutes = 0;
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        __Vinline__nba_sequent__TOP__0___Vdly__minutes 
            = vlSelfRef.minutes;
        __Vinline__nba_sequent__TOP__0___Vtableidx1 
            = (((IData)(vlSelfRef.seconds) << 3U) | 
               (((IData)(vlSelfRef.stopwatch_top__DOT__mode_reg) 
                 << 1U) | (IData)(vlSelfRef.rst_n)));
        if (vlSelfRef.rst_n) {
            if ((0U == (IData)(vlSelfRef.stopwatch_top__DOT__mode_reg))) {
                __Vinline__nba_sequent__TOP__0___Vdly__minutes = 0U;
            } else if ((1U == (IData)(vlSelfRef.stopwatch_top__DOT__mode_reg))) {
                __Vinline__nba_sequent__TOP__0___Vdly__minutes 
                    = vlSelfRef.minutes;
            } else if ((2U == (IData)(vlSelfRef.stopwatch_top__DOT__mode_reg))) {
                if ((0x63U > (IData)(vlSelfRef.minutes))) {
                    if (((2U == (IData)(vlSelfRef.stopwatch_top__DOT__mode_reg)) 
                         & (0x3bU == (IData)(vlSelfRef.seconds)))) {
                        __Vinline__nba_sequent__TOP__0___Vdly__minutes 
                            = (0x000000ffU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.minutes)));
                    }
                }
            }
            if (vlSelfRef.rst) {
                vlSelfRef.stopwatch_top__DOT__mode_reg = 0U;
            } else if (vlSelfRef.stop) {
                vlSelfRef.stopwatch_top__DOT__mode_reg = 1U;
            } else if (vlSelfRef.start) {
                vlSelfRef.stopwatch_top__DOT__mode_reg = 2U;
            }
            vlSelfRef.status = ((0U == (IData)(vlSelfRef.stopwatch_top__DOT__mode_reg))
                                 ? 0U : ((1U == (IData)(vlSelfRef.stopwatch_top__DOT__mode_reg))
                                          ? 1U : ((2U 
                                                   == (IData)(vlSelfRef.stopwatch_top__DOT__mode_reg))
                                                   ? 2U
                                                   : 0U)));
        } else {
            __Vinline__nba_sequent__TOP__0___Vdly__minutes = 0U;
            vlSelfRef.stopwatch_top__DOT__mode_reg = 0U;
            vlSelfRef.status = 0U;
        }
        if (Vstopwatch_top__ConstPool__TABLE_hdeadfca2_0
            [__Vinline__nba_sequent__TOP__0___Vtableidx1]) {
            vlSelfRef.seconds = Vstopwatch_top__ConstPool__TABLE_h7258e8ae_0
                [__Vinline__nba_sequent__TOP__0___Vtableidx1];
        }
        vlSelfRef.minutes = __Vinline__nba_sequent__TOP__0___Vdly__minutes;
    }
}

void Vstopwatch_top___024root___trigger_orInto__act(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___trigger_orInto__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vstopwatch_top___024root___eval_phase__act(Vstopwatch_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___eval_phase__act\n"); );
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vstopwatch_top___024root___eval_triggers__act(vlSelf);
    Vstopwatch_top___024root___trigger_orInto__act(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vstopwatch_top___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vstopwatch_top___024root___eval_phase__nba(Vstopwatch_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___eval_phase__nba\n"); );
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vstopwatch_top___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vstopwatch_top___024root___eval_nba(vlSelf);
        Vstopwatch_top___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vstopwatch_top___024root___eval(Vstopwatch_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___eval\n"); );
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vstopwatch_top___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("rtl/stopwatch_top.v", 1, "", "DIDNOTCONVERGE: Input combinational region did not converge after 100 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        vlSelfRef.__VicoPhaseResult = Vstopwatch_top___024root___eval_phase__ico(vlSelf);
        vlSelfRef.__VicoFirstIteration = 0U;
    } while (vlSelfRef.__VicoPhaseResult);
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vstopwatch_top___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("rtl/stopwatch_top.v", 1, "", "DIDNOTCONVERGE: NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vstopwatch_top___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("rtl/stopwatch_top.v", 1, "", "DIDNOTCONVERGE: Active region did not converge after 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactPhaseResult = Vstopwatch_top___024root___eval_phase__act(vlSelf);
        } while (vlSelfRef.__VactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vstopwatch_top___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void Vstopwatch_top___024root___eval_debug_assertions(Vstopwatch_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___eval_debug_assertions\n"); );
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.rst_n & 0xfeU)))) {
        Verilated::overWidthError("rst_n");
    }
    if (VL_UNLIKELY(((vlSelfRef.start & 0xfeU)))) {
        Verilated::overWidthError("start");
    }
    if (VL_UNLIKELY(((vlSelfRef.stop & 0xfeU)))) {
        Verilated::overWidthError("stop");
    }
    if (VL_UNLIKELY(((vlSelfRef.rst & 0xfeU)))) {
        Verilated::overWidthError("rst");
    }
}
#endif  // VL_DEBUG
