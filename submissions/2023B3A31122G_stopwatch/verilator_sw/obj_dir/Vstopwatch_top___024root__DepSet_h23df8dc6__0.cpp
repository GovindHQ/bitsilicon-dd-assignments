// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vstopwatch_top.h for the primary calling header

#include "Vstopwatch_top__pch.h"
#include "Vstopwatch_top___024root.h"

extern const VlUnpacked<CData/*1:0*/, 16> Vstopwatch_top__ConstPool__TABLE_hf4641699_0;

VL_INLINE_OPT void Vstopwatch_top___024root___ico_sequent__TOP__0(Vstopwatch_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___ico_sequent__TOP__0\n"); );
    // Init
    CData/*3:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    __Vtableidx1 = (((IData)(vlSelf->stop) << 3U) | 
                    (((IData)(vlSelf->start) << 2U) 
                     | (IData)(vlSelf->stopwatch_top__DOT__fsm_inst__DOT__current_state)));
    vlSelf->stopwatch_top__DOT__fsm_inst__DOT__next_state 
        = Vstopwatch_top__ConstPool__TABLE_hf4641699_0
        [__Vtableidx1];
    vlSelf->stopwatch_top__DOT__min_inst__DOT__rst_combined 
        = (1U & ((~ ((~ (IData)(vlSelf->reset)) & (IData)(vlSelf->rst_n))) 
                 | ((IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff6__q) 
                    & ((IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff5__q) 
                       & ((IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff3__q) 
                          & (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff4__q))))));
    vlSelf->stopwatch_top__DOT__sec_inst__DOT__rst_combined 
        = (((IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____VdfgTmp_h45d1b877__0) 
            & (IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff2__q)) 
           | (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT__rst_combined));
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
    // Body
    vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff7__q 
        = ((1U & (~ (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT__rst_combined))) 
           && ((IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT__j7)
                ? ((1U & (~ (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT__j7))) 
                   || (1U & (~ (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff7__q))))
                : ((1U & (~ (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT__j7))) 
                   && (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff7__q))));
    vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff6__q 
        = ((1U & (~ (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT__rst_combined))) 
           && ((IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT__j6)
                ? ((1U & (~ (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT__j6))) 
                   || (1U & (~ (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff6__q))))
                : ((1U & (~ (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT__j6))) 
                   && (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff6__q))));
    vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff5__q 
        = ((1U & (~ (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT__rst_combined))) 
           && ((IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT__j5)
                ? ((1U & (~ (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT__j5))) 
                   || (1U & (~ (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff5__q))))
                : ((1U & (~ (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT__j5))) 
                   && (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff5__q))));
    vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff2__q 
        = ((1U & (~ (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT__rst_combined))) 
           && ((IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT__j2)
                ? ((1U & (~ (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT__j2))) 
                   || (1U & (~ (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff2__q))))
                : ((1U & (~ (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT__j2))) 
                   && (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff2__q))));
    vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff4__q 
        = ((1U & (~ (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT__rst_combined))) 
           && ((IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT__j4)
                ? ((1U & (~ (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT__j4))) 
                   || (1U & (~ (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff4__q))))
                : ((1U & (~ (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT__j4))) 
                   && (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff4__q))));
    vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff1__q 
        = ((1U & (~ (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT__rst_combined))) 
           && ((IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT__j1)
                ? ((1U & (~ (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT__j1))) 
                   || (1U & (~ (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff1__q))))
                : ((1U & (~ (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT__j1))) 
                   && (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff1__q))));
    vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff3__q 
        = ((1U & (~ (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT__rst_combined))) 
           && ((IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT__j3)
                ? ((1U & (~ (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT__j3))) 
                   || (1U & (~ (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff3__q))))
                : ((1U & (~ (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT__j3))) 
                   && (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff3__q))));
    vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff0__q 
        = ((1U & (~ (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT__rst_combined))) 
           && ((IData)(vlSelf->stopwatch_top__DOT__seconds_roll)
                ? ((1U & (~ (IData)(vlSelf->stopwatch_top__DOT__seconds_roll))) 
                   || (1U & (~ (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff0__q))))
                : ((1U & (~ (IData)(vlSelf->stopwatch_top__DOT__seconds_roll))) 
                   && (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff0__q))));
    vlSelf->stopwatch_top__DOT__min_inst__DOT__rst_combined 
        = (1U & ((~ ((~ (IData)(vlSelf->reset)) & (IData)(vlSelf->rst_n))) 
                 | ((IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff6__q) 
                    & ((IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff5__q) 
                       & ((IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff3__q) 
                          & (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff4__q))))));
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
}

VL_INLINE_OPT void Vstopwatch_top___024root___nba_sequent__TOP__1(Vstopwatch_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___nba_sequent__TOP__1\n"); );
    // Body
    vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff2__q 
        = ((1U & (~ (IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT__rst_combined))) 
           && ((IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT__j2)
                ? ((1U & (~ (IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT__j2))) 
                   || (1U & (~ (IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff2__q))))
                : ((1U & (~ (IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT__j2))) 
                   && (IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff2__q))));
    vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff5__q 
        = ((1U & (~ (IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT__rst_combined))) 
           && ((IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT__j5)
                ? ((1U & (~ (IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT__j5))) 
                   || (1U & (~ (IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff5__q))))
                : ((1U & (~ (IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT__j5))) 
                   && (IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff5__q))));
    vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff4__q 
        = ((1U & (~ (IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT__rst_combined))) 
           && ((IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT__j4)
                ? ((1U & (~ (IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT__j4))) 
                   || (1U & (~ (IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff4__q))))
                : ((1U & (~ (IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT__j4))) 
                   && (IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff4__q))));
    vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff3__q 
        = ((1U & (~ (IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT__rst_combined))) 
           && ((IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT__j3)
                ? ((1U & (~ (IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT__j3))) 
                   || (1U & (~ (IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff3__q))))
                : ((1U & (~ (IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT__j3))) 
                   && (IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff3__q))));
    vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff1__q 
        = ((1U & (~ (IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT__rst_combined))) 
           && ((IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT__j1)
                ? ((1U & (~ (IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT__j1))) 
                   || (1U & (~ (IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff1__q))))
                : ((1U & (~ (IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT__j1))) 
                   && (IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff1__q))));
    vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff0__q 
        = ((1U & (~ (IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT__rst_combined))) 
           && ((1U == (IData)(vlSelf->stopwatch_top__DOT__fsm_inst__DOT__current_state))
                ? ((1U != (IData)(vlSelf->stopwatch_top__DOT__fsm_inst__DOT__current_state)) 
                   || (1U & (~ (IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff0__q))))
                : ((1U != (IData)(vlSelf->stopwatch_top__DOT__fsm_inst__DOT__current_state)) 
                   && (IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff0__q))));
    vlSelf->stopwatch_top__DOT__sec_inst__DOT____VdfgTmp_h45d1b877__0 
        = ((IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff5__q) 
           & ((IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff3__q) 
              & (IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff4__q)));
    vlSelf->seconds = (((IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff5__q) 
                        << 5U) | (((IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff4__q) 
                                   << 4U) | (((IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff3__q) 
                                              << 3U) 
                                             | (((IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff2__q) 
                                                 << 2U) 
                                                | (((IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff1__q) 
                                                    << 1U) 
                                                   | (IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff0__q))))));
    vlSelf->stopwatch_top__DOT__seconds_roll = ((IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____VdfgTmp_h45d1b877__0) 
                                                & ((IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff0__q) 
                                                   & (IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff1__q)));
}

VL_INLINE_OPT void Vstopwatch_top___024root___nba_sequent__TOP__2(Vstopwatch_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___nba_sequent__TOP__2\n"); );
    // Init
    CData/*3:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelf->stopwatch_top__DOT__fsm_inst__DOT__current_state 
        = ((IData)(vlSelf->rst_n) ? ((IData)(vlSelf->reset)
                                      ? 0U : (IData)(vlSelf->stopwatch_top__DOT__fsm_inst__DOT__next_state))
            : 0U);
    vlSelf->status = vlSelf->stopwatch_top__DOT__fsm_inst__DOT__current_state;
    __Vtableidx1 = (((IData)(vlSelf->stop) << 3U) | 
                    (((IData)(vlSelf->start) << 2U) 
                     | (IData)(vlSelf->stopwatch_top__DOT__fsm_inst__DOT__current_state)));
    vlSelf->stopwatch_top__DOT__fsm_inst__DOT__next_state 
        = Vstopwatch_top__ConstPool__TABLE_hf4641699_0
        [__Vtableidx1];
}

VL_INLINE_OPT void Vstopwatch_top___024root___nba_comb__TOP__0(Vstopwatch_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___nba_comb__TOP__0\n"); );
    // Body
    vlSelf->stopwatch_top__DOT__sec_inst__DOT__rst_combined 
        = (((IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____VdfgTmp_h45d1b877__0) 
            & (IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff2__q)) 
           | (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT__rst_combined));
    vlSelf->stopwatch_top__DOT__min_inst__DOT__j1 = 
        ((IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff0__q) 
         & (IData)(vlSelf->stopwatch_top__DOT__seconds_roll));
    vlSelf->stopwatch_top__DOT__min_inst__DOT__j2 = 
        ((IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT____Vcellout__ff1__q) 
         & (IData)(vlSelf->stopwatch_top__DOT__min_inst__DOT__j1));
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

VL_INLINE_OPT void Vstopwatch_top___024root___nba_comb__TOP__1(Vstopwatch_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___nba_comb__TOP__1\n"); );
    // Body
    vlSelf->stopwatch_top__DOT__sec_inst__DOT__j1 = 
        ((IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff0__q) 
         & (1U == (IData)(vlSelf->stopwatch_top__DOT__fsm_inst__DOT__current_state)));
    vlSelf->stopwatch_top__DOT__sec_inst__DOT__j2 = 
        ((IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff1__q) 
         & (IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT__j1));
    vlSelf->stopwatch_top__DOT__sec_inst__DOT__j3 = 
        ((IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff2__q) 
         & (IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT__j2));
    vlSelf->stopwatch_top__DOT__sec_inst__DOT__j4 = 
        ((IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff3__q) 
         & (IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT__j3));
    vlSelf->stopwatch_top__DOT__sec_inst__DOT__j5 = 
        ((IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff4__q) 
         & (IData)(vlSelf->stopwatch_top__DOT__sec_inst__DOT__j4));
}

void Vstopwatch_top___024root___eval_nba(Vstopwatch_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___eval_nba\n"); );
    // Body
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vstopwatch_top___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vstopwatch_top___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vstopwatch_top___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((6ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vstopwatch_top___024root___nba_comb__TOP__0(vlSelf);
    }
    if ((3ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vstopwatch_top___024root___nba_comb__TOP__1(vlSelf);
    }
}

void Vstopwatch_top___024root___eval_triggers__act(Vstopwatch_top___024root* vlSelf);

bool Vstopwatch_top___024root___eval_phase__act(Vstopwatch_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<3> __VpreTriggered;
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
            VL_FATAL_MT("../rtl/../rtl/stopwatch_top.v", 1, "", "Input combinational region did not converge.");
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
            VL_FATAL_MT("../rtl/../rtl/stopwatch_top.v", 1, "", "NBA region did not converge.");
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
                VL_FATAL_MT("../rtl/../rtl/stopwatch_top.v", 1, "", "Active region did not converge.");
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
