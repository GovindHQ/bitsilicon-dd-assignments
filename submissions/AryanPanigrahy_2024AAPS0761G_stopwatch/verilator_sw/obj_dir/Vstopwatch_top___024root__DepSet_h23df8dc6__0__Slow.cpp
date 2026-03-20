// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vstopwatch_top.h for the primary calling header

#include "Vstopwatch_top__pch.h"
#include "Vstopwatch_top___024root.h"

VL_ATTR_COLD void Vstopwatch_top___024root___eval_static(Vstopwatch_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___eval_static\n"); );
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
}

VL_ATTR_COLD void Vstopwatch_top___024root___eval_initial(Vstopwatch_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___eval_initial\n"); );
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vstopwatch_top___024root___eval_final(Vstopwatch_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___eval_final\n"); );
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vstopwatch_top___024root___eval_settle(Vstopwatch_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___eval_settle\n"); );
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vstopwatch_top___024root___dump_triggers__act(Vstopwatch_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___dump_triggers__act\n"); );
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vstopwatch_top___024root___dump_triggers__nba(Vstopwatch_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___dump_triggers__nba\n"); );
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vstopwatch_top___024root___ctor_var_reset(Vstopwatch_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___ctor_var_reset\n"); );
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1638864771569018232ull);
    vlSelf->start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9867861323841650631ull);
    vlSelf->stop = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16026904639853099817ull);
    vlSelf->reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9928399931838511862ull);
    vlSelf->minutes = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12308508970105077781ull);
    vlSelf->seconds = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 2737571640425906867ull);
    vlSelf->status = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 14822974759303984767ull);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9526919608049418986ull);
}
