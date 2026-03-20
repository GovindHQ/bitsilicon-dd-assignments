// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vstopwatch_top.h for the primary calling header

#include "Vstopwatch_top__pch.h"
#include "Vstopwatch_top___024root.h"

void Vstopwatch_top___024root___eval_act(Vstopwatch_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___eval_act\n"); );
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vstopwatch_top___024root___nba_sequent__TOP__0(Vstopwatch_top___024root* vlSelf);

void Vstopwatch_top___024root___eval_nba(Vstopwatch_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___eval_nba\n"); );
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vstopwatch_top___024root___nba_sequent__TOP__0(vlSelf);
    }
}

extern const VlUnpacked<CData/*0:0*/, 64> Vstopwatch_top__ConstPool__TABLE_h58dadc62_0;
extern const VlUnpacked<CData/*1:0*/, 64> Vstopwatch_top__ConstPool__TABLE_hbe93f50b_0;

VL_INLINE_OPT void Vstopwatch_top___024root___nba_sequent__TOP__0(Vstopwatch_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___nba_sequent__TOP__0\n"); );
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*5:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*5:0*/ __Vdly__seconds;
    __Vdly__seconds = 0;
    // Body
    __Vdly__seconds = vlSelfRef.seconds;
    if (vlSelfRef.rst_n) {
        if ((1U == (IData)(vlSelfRef.status))) {
            __Vdly__seconds = ((0x3bU == (IData)(vlSelfRef.seconds))
                                ? 0U : (0x3fU & ((IData)(1U) 
                                                 + (IData)(vlSelfRef.seconds))));
        }
        if (((1U == (IData)(vlSelfRef.status)) & (0x3bU 
                                                  == (IData)(vlSelfRef.seconds)))) {
            vlSelfRef.minutes = ((0x63U == (IData)(vlSelfRef.minutes))
                                  ? 0U : (0xffU & ((IData)(1U) 
                                                   + (IData)(vlSelfRef.minutes))));
        }
    } else {
        __Vdly__seconds = 0U;
        vlSelfRef.minutes = 0U;
    }
    __Vtableidx1 = ((((IData)(vlSelfRef.stop) << 5U) 
                     | ((IData)(vlSelfRef.start) << 4U)) 
                    | (((IData)(vlSelfRef.status) << 2U) 
                       | (((IData)(vlSelfRef.reset) 
                           << 1U) | (IData)(vlSelfRef.rst_n))));
    if (Vstopwatch_top__ConstPool__TABLE_h58dadc62_0
        [__Vtableidx1]) {
        vlSelfRef.status = Vstopwatch_top__ConstPool__TABLE_hbe93f50b_0
            [__Vtableidx1];
    }
    vlSelfRef.seconds = __Vdly__seconds;
}

void Vstopwatch_top___024root___eval_triggers__act(Vstopwatch_top___024root* vlSelf);

bool Vstopwatch_top___024root___eval_phase__act(Vstopwatch_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___eval_phase__act\n"); );
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vstopwatch_top___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vstopwatch_top___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vstopwatch_top___024root___eval_phase__nba(Vstopwatch_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___eval_phase__nba\n"); );
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vstopwatch_top___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vstopwatch_top___024root___dump_triggers__nba(Vstopwatch_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vstopwatch_top___024root___dump_triggers__act(Vstopwatch_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vstopwatch_top___024root___eval(Vstopwatch_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___eval\n"); );
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vstopwatch_top___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../rtl\\stopwatch_top.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vstopwatch_top___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("../rtl\\stopwatch_top.v", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vstopwatch_top___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vstopwatch_top___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vstopwatch_top___024root___eval_debug_assertions(Vstopwatch_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___eval_debug_assertions\n"); );
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY(((vlSelfRef.rst_n & 0xfeU)))) {
        Verilated::overWidthError("rst_n");}
    if (VL_UNLIKELY(((vlSelfRef.start & 0xfeU)))) {
        Verilated::overWidthError("start");}
    if (VL_UNLIKELY(((vlSelfRef.stop & 0xfeU)))) {
        Verilated::overWidthError("stop");}
    if (VL_UNLIKELY(((vlSelfRef.reset & 0xfeU)))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
