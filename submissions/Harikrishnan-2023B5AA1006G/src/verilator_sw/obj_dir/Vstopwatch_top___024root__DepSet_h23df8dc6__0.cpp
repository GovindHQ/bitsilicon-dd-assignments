// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vstopwatch_top.h for the primary calling header

#include "Vstopwatch_top__pch.h"
#include "Vstopwatch_top___024root.h"

extern const VlUnpacked<CData/*1:0*/, 32> Vstopwatch_top__ConstPool__TABLE_hc8992a99_0;

VL_INLINE_OPT void Vstopwatch_top___024root___ico_sequent__TOP__0(Vstopwatch_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___ico_sequent__TOP__0\n"); );
    // Init
    CData/*4:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    __Vtableidx1 = (((IData)(vlSelf->stop) << 4U) | 
                    (((IData)(vlSelf->reset) << 3U) 
                     | (((IData)(vlSelf->start) << 2U) 
                        | (IData)(vlSelf->stopwatch_top__DOT__fsm__DOT__state))));
    vlSelf->stopwatch_top__DOT__fsm__DOT__next_state 
        = Vstopwatch_top__ConstPool__TABLE_hc8992a99_0
        [__Vtableidx1];
}

void Vstopwatch_top___024root___eval_ico(Vstopwatch_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vstopwatch_top___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vstopwatch_top___024root___eval_triggers__ico(Vstopwatch_top___024root* vlSelf);

bool Vstopwatch_top___024root___eval_phase__ico(Vstopwatch_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vstopwatch_top___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vstopwatch_top___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vstopwatch_top___024root___eval_act(Vstopwatch_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vstopwatch_top___024root___nba_sequent__TOP__0(Vstopwatch_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*4:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*5:0*/ __Vdly__seconds;
    __Vdly__seconds = 0;
    CData/*7:0*/ __Vdly__minutes;
    __Vdly__minutes = 0;
    // Body
    __Vdly__seconds = vlSelf->seconds;
    __Vdly__minutes = vlSelf->minutes;
    if (vlSelf->rst_n) {
        if (vlSelf->reset) {
            __Vdly__seconds = 0U;
            __Vdly__minutes = 0U;
        } else {
            if ((1U == (IData)(vlSelf->stopwatch_top__DOT__fsm__DOT__state))) {
                __Vdly__seconds = ((0x3bU == (IData)(vlSelf->seconds))
                                    ? 0U : (0x3fU & 
                                            ((IData)(1U) 
                                             + (IData)(vlSelf->seconds))));
            }
            if ((IData)(((1U == (IData)(vlSelf->stopwatch_top__DOT__fsm__DOT__state)) 
                         & (0x3bU == (IData)(vlSelf->seconds))))) {
                __Vdly__minutes = ((0x63U == (IData)(vlSelf->minutes))
                                    ? 0U : (0xffU & 
                                            ((IData)(1U) 
                                             + (IData)(vlSelf->minutes))));
            }
        }
        vlSelf->stopwatch_top__DOT__fsm__DOT__state 
            = vlSelf->stopwatch_top__DOT__fsm__DOT__next_state;
    } else {
        __Vdly__seconds = 0U;
        __Vdly__minutes = 0U;
        vlSelf->stopwatch_top__DOT__fsm__DOT__state = 0U;
    }
    vlSelf->minutes = __Vdly__minutes;
    vlSelf->seconds = __Vdly__seconds;
    vlSelf->status = vlSelf->stopwatch_top__DOT__fsm__DOT__state;
    __Vtableidx1 = (((IData)(vlSelf->stop) << 4U) | 
                    (((IData)(vlSelf->reset) << 3U) 
                     | (((IData)(vlSelf->start) << 2U) 
                        | (IData)(vlSelf->stopwatch_top__DOT__fsm__DOT__state))));
    vlSelf->stopwatch_top__DOT__fsm__DOT__next_state 
        = Vstopwatch_top__ConstPool__TABLE_hc8992a99_0
        [__Vtableidx1];
}

void Vstopwatch_top___024root___eval_nba(Vstopwatch_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vstopwatch_top___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vstopwatch_top___024root___eval_triggers__act(Vstopwatch_top___024root* vlSelf);

bool Vstopwatch_top___024root___eval_phase__act(Vstopwatch_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vstopwatch_top___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vstopwatch_top___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vstopwatch_top___024root___eval_phase__nba(Vstopwatch_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vstopwatch_top___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vstopwatch_top___024root___dump_triggers__ico(Vstopwatch_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vstopwatch_top___024root___dump_triggers__nba(Vstopwatch_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vstopwatch_top___024root___dump_triggers__act(Vstopwatch_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vstopwatch_top___024root___eval(Vstopwatch_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vstopwatch_top___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("../rtl/stopwatch_top.v", 3, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vstopwatch_top___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vstopwatch_top___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../rtl/stopwatch_top.v", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vstopwatch_top___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("../rtl/stopwatch_top.v", 3, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vstopwatch_top___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vstopwatch_top___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vstopwatch_top___024root___eval_debug_assertions(Vstopwatch_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst_n & 0xfeU))) {
        Verilated::overWidthError("rst_n");}
    if (VL_UNLIKELY((vlSelf->start & 0xfeU))) {
        Verilated::overWidthError("start");}
    if (VL_UNLIKELY((vlSelf->stop & 0xfeU))) {
        Verilated::overWidthError("stop");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
