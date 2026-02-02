// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vstopwatch_top.h for the primary calling header

#include "Vstopwatch_top__pch.h"
#include "Vstopwatch_top___024root.h"

VL_ATTR_COLD void Vstopwatch_top___024root___eval_static(Vstopwatch_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vstopwatch_top___024root___eval_initial(Vstopwatch_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = vlSelf->rst_n;
    vlSelf->__Vtrigprevexpr___TOP__stopwatch_top__DOT__sec_inst__DOT__rst_combined__0 
        = vlSelf->stopwatch_top__DOT__sec_inst__DOT__rst_combined;
    vlSelf->__Vtrigprevexpr___TOP__stopwatch_top__DOT__min_inst__DOT__rst_combined__0 
        = vlSelf->stopwatch_top__DOT__min_inst__DOT__rst_combined;
}

VL_ATTR_COLD void Vstopwatch_top___024root___eval_final(Vstopwatch_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vstopwatch_top___024root___dump_triggers__stl(Vstopwatch_top___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vstopwatch_top___024root___eval_phase__stl(Vstopwatch_top___024root* vlSelf);

VL_ATTR_COLD void Vstopwatch_top___024root___eval_settle(Vstopwatch_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vstopwatch_top___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("../rtl/../rtl/stopwatch_top.v", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vstopwatch_top___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vstopwatch_top___024root___dump_triggers__stl(Vstopwatch_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

extern const VlUnpacked<CData/*1:0*/, 16> Vstopwatch_top__ConstPool__TABLE_hf4641699_0;

VL_ATTR_COLD void Vstopwatch_top___024root___stl_sequent__TOP__0(Vstopwatch_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___stl_sequent__TOP__0\n"); );
    // Init
    CData/*3:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelf->status = vlSelf->stopwatch_top__DOT__fsm_inst__DOT__current_state;
    __Vtableidx1 = (((IData)(vlSelf->stop) << 3U) | 
                    (((IData)(vlSelf->start) << 2U) 
                     | (IData)(vlSelf->stopwatch_top__DOT__fsm_inst__DOT__current_state)));
    vlSelf->stopwatch_top__DOT__fsm_inst__DOT__next_state 
        = Vstopwatch_top__ConstPool__TABLE_hf4641699_0
        [__Vtableidx1];
    vlSelf->seconds = (((IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff5__q) 
                        << 5U) | (((IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff4__q) 
                                   << 4U) | (((IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff3__q) 
                                              << 3U) 
                                             | (((IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff2__q) 
                                                 << 2U) 
                                                | (((IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff1__q) 
                                                    << 1U) 
                                                   | (IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff0__q))))));
    vlSelf->minutes = (((IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff7__q) 
                        << 7U) | (((IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff6__q) 
                                   << 6U) | (((IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff5__q) 
                                              << 5U) 
                                             | (((IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff4__q) 
                                                 << 4U) 
                                                | (((IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff3__q) 
                                                    << 3U) 
                                                   | (((IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff2__q) 
                                                       << 2U) 
                                                      | (((IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff1__q) 
                                                          << 1U) 
                                                         | (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff0__q))))))));
    vlSelf->stopwatch_top__DOT__min_inst__DOT__rst_combined 
        = (1U & ((~ ((~ (IData)(vlSelf->reset)) & (IData)(vlSelf->rst_n))) 
                 | ((IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff6__q) 
                    & ((IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff5__q) 
                       & ((IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff3__q) 
                          & (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff4__q))))));
    vlSelf->stopwatch_top__DOT__sec_inst__DOT__j1 = 
        ((IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff0__q) 
         & (1U == (IData)(vlSelf->stopwatch_top__DOT__fsm_inst__DOT__current_state)));
    vlSelf->stopwatch_top__DOT__sec_inst__DOT____VdfgTmp_h45d1b877__0 
        = ((IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff5__q) 
           & ((IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff3__q) 
              & (IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff4__q)));
    vlSelf->stopwatch_top__DOT__sec_inst__DOT__j2 = 
        ((IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff1__q) 
         & (IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT__j1));
    vlSelf->stopwatch_top__DOT__sec_inst__DOT__rst_combined 
        = (((IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____VdfgTmp_h45d1b877__0) 
            & (IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff2__q)) 
           | (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT__rst_combined));
    vlSelf->stopwatch_top__DOT__seconds_roll = ((IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____VdfgTmp_h45d1b877__0) 
                                                & ((IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff0__q) 
                                                   & (IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff1__q)));
    vlSelf->stopwatch_top__DOT__sec_inst__DOT__j3 = 
        ((IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff2__q) 
         & (IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT__j2));
    vlSelf->stopwatch_top__DOT__min_inst__DOT__j1 = 
        ((IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff0__q) 
         & (IData)(vlSelf->stopwatch_top__DOT__seconds_roll));
    vlSelf->stopwatch_top__DOT__sec_inst__DOT__j4 = 
        ((IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff3__q) 
         & (IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT__j3));
    vlSelf->stopwatch_top__DOT__min_inst__DOT__j2 = 
        ((IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff1__q) 
         & (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT__j1));
    vlSelf->stopwatch_top__DOT__sec_inst__DOT__j5 = 
        ((IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff4__q) 
         & (IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT__j4));
    vlSelf->stopwatch_top__DOT__min_inst__DOT__j3 = 
        ((IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff2__q) 
         & (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT__j2));
    vlSelf->stopwatch_top__DOT__min_inst__DOT__j4 = 
        ((IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff3__q) 
         & (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT__j3));
    vlSelf->stopwatch_top__DOT__min_inst__DOT__j5 = 
        ((IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff4__q) 
         & (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT__j4));
    vlSelf->stopwatch_top__DOT__min_inst__DOT__j6 = 
        ((IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff5__q) 
         & (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT__j5));
    vlSelf->stopwatch_top__DOT__min_inst__DOT__j7 = 
        ((IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff6__q) 
         & (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT__j6));
}

VL_ATTR_COLD void Vstopwatch_top___024root___eval_stl(Vstopwatch_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vstopwatch_top___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vstopwatch_top___024root___eval_triggers__stl(Vstopwatch_top___024root* vlSelf);

VL_ATTR_COLD bool Vstopwatch_top___024root___eval_phase__stl(Vstopwatch_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vstopwatch_top___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vstopwatch_top___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vstopwatch_top___024root___dump_triggers__ico(Vstopwatch_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vstopwatch_top___024root___dump_triggers__act(Vstopwatch_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk or negedge rst_n)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge clk or posedge stopwatch_top.sec_inst.rst_combined)\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(posedge clk or posedge stopwatch_top.min_inst.rst_combined)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vstopwatch_top___024root___dump_triggers__nba(Vstopwatch_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk or negedge rst_n)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge clk or posedge stopwatch_top.sec_inst.rst_combined)\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(posedge clk or posedge stopwatch_top.min_inst.rst_combined)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vstopwatch_top___024root___ctor_var_reset(Vstopwatch_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst_n = VL_RAND_RESET_I(1);
    vlSelf->start = VL_RAND_RESET_I(1);
    vlSelf->stop = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->minutes = VL_RAND_RESET_I(8);
    vlSelf->seconds = VL_RAND_RESET_I(6);
    vlSelf->status = VL_RAND_RESET_I(2);
    vlSelf->stopwatch_top__DOT__seconds_roll = VL_RAND_RESET_I(1);
    vlSelf->stopwatch_top__DOT__fsm_inst__DOT__current_state = VL_RAND_RESET_I(2);
    vlSelf->stopwatch_top__DOT__fsm_inst__DOT__next_state = VL_RAND_RESET_I(2);
    vlSelf->stopwatch_top__DOT__sec_inst__DOT__rst_combined = VL_RAND_RESET_I(1);
    vlSelf->stopwatch_top__DOT__sec_inst__DOT__j1 = VL_RAND_RESET_I(1);
    vlSelf->stopwatch_top__DOT__sec_inst__DOT__j2 = VL_RAND_RESET_I(1);
    vlSelf->stopwatch_top__DOT__sec_inst__DOT__j3 = VL_RAND_RESET_I(1);
    vlSelf->stopwatch_top__DOT__sec_inst__DOT__j4 = VL_RAND_RESET_I(1);
    vlSelf->stopwatch_top__DOT__sec_inst__DOT__j5 = VL_RAND_RESET_I(1);
    vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff0__q = VL_RAND_RESET_I(1);
    vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff1__q = VL_RAND_RESET_I(1);
    vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff2__q = VL_RAND_RESET_I(1);
    vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff3__q = VL_RAND_RESET_I(1);
    vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff4__q = VL_RAND_RESET_I(1);
    vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff5__q = VL_RAND_RESET_I(1);
    vlSelf->stopwatch_top__DOT__sec_inst__DOT____VdfgTmp_h45d1b877__0 = 0;
    vlSelf->stopwatch_top__DOT__min_inst__DOT__rst_combined = VL_RAND_RESET_I(1);
    vlSelf->stopwatch_top__DOT__min_inst__DOT__j1 = VL_RAND_RESET_I(1);
    vlSelf->stopwatch_top__DOT__min_inst__DOT__j2 = VL_RAND_RESET_I(1);
    vlSelf->stopwatch_top__DOT__min_inst__DOT__j3 = VL_RAND_RESET_I(1);
    vlSelf->stopwatch_top__DOT__min_inst__DOT__j4 = VL_RAND_RESET_I(1);
    vlSelf->stopwatch_top__DOT__min_inst__DOT__j5 = VL_RAND_RESET_I(1);
    vlSelf->stopwatch_top__DOT__min_inst__DOT__j6 = VL_RAND_RESET_I(1);
    vlSelf->stopwatch_top__DOT__min_inst__DOT__j7 = VL_RAND_RESET_I(1);
    vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff0__q = VL_RAND_RESET_I(1);
    vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff1__q = VL_RAND_RESET_I(1);
    vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff2__q = VL_RAND_RESET_I(1);
    vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff3__q = VL_RAND_RESET_I(1);
    vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff4__q = VL_RAND_RESET_I(1);
    vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff5__q = VL_RAND_RESET_I(1);
    vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff6__q = VL_RAND_RESET_I(1);
    vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff7__q = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__stopwatch_top__DOT__sec_inst__DOT__rst_combined__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__stopwatch_top__DOT__min_inst__DOT__rst_combined__0 = VL_RAND_RESET_I(1);
}
