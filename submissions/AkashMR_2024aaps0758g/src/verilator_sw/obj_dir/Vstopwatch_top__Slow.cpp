// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vstopwatch_top.h for the primary calling header

#include "Vstopwatch_top.h"
#include "Vstopwatch_top__Syms.h"

//==========
CData/*1:0*/ Vstopwatch_top::__Vtable1_stopwatch_top__DOT__u_control_fsm__DOT__next_state[32];

VL_CTOR_IMP(Vstopwatch_top) {
    Vstopwatch_top__Syms* __restrict vlSymsp = __VlSymsp = new Vstopwatch_top__Syms(this, name());
    Vstopwatch_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vstopwatch_top::__Vconfigure(Vstopwatch_top__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vstopwatch_top::~Vstopwatch_top() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vstopwatch_top::_settle__TOP__2(Vstopwatch_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top::_settle__TOP__2\n"); );
    Vstopwatch_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->status = vlTOPp->stopwatch_top__DOT__u_control_fsm__DOT__current_state;
    vlTOPp->stopwatch_top__DOT__fsm_count_en = 0U;
    if ((0U != (IData)(vlTOPp->stopwatch_top__DOT__u_control_fsm__DOT__current_state))) {
        if ((1U == (IData)(vlTOPp->stopwatch_top__DOT__u_control_fsm__DOT__current_state))) {
            vlTOPp->stopwatch_top__DOT__fsm_count_en = 1U;
        } else {
            if ((2U == (IData)(vlTOPp->stopwatch_top__DOT__u_control_fsm__DOT__current_state))) {
                vlTOPp->stopwatch_top__DOT__fsm_count_en = 0U;
            }
        }
    }
    vlTOPp->stopwatch_top__DOT__fsm_clear = 0U;
    if ((0U == (IData)(vlTOPp->stopwatch_top__DOT__u_control_fsm__DOT__current_state))) {
        vlTOPp->stopwatch_top__DOT__fsm_clear = 1U;
    } else {
        if ((1U != (IData)(vlTOPp->stopwatch_top__DOT__u_control_fsm__DOT__current_state))) {
            if ((2U != (IData)(vlTOPp->stopwatch_top__DOT__u_control_fsm__DOT__current_state))) {
                vlTOPp->stopwatch_top__DOT__fsm_clear = 1U;
            }
        }
    }
    vlTOPp->__Vtableidx1 = (((IData)(vlTOPp->stop) 
                             << 4U) | (((IData)(vlTOPp->reset) 
                                        << 3U) | (((IData)(vlTOPp->start) 
                                                   << 2U) 
                                                  | (IData)(vlTOPp->stopwatch_top__DOT__u_control_fsm__DOT__current_state))));
    vlTOPp->stopwatch_top__DOT__u_control_fsm__DOT__next_state 
        = vlTOPp->__Vtable1_stopwatch_top__DOT__u_control_fsm__DOT__next_state
        [vlTOPp->__Vtableidx1];
}

void Vstopwatch_top::_eval_initial(Vstopwatch_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top::_eval_initial\n"); );
    Vstopwatch_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__rst_n = vlTOPp->rst_n;
}

void Vstopwatch_top::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top::final\n"); );
    // Variables
    Vstopwatch_top__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vstopwatch_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vstopwatch_top::_eval_settle(Vstopwatch_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top::_eval_settle\n"); );
    Vstopwatch_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

void Vstopwatch_top::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    rst_n = VL_RAND_RESET_I(1);
    start = VL_RAND_RESET_I(1);
    stop = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    minutes = VL_RAND_RESET_I(8);
    seconds = VL_RAND_RESET_I(6);
    status = VL_RAND_RESET_I(2);
    stopwatch_top__DOT__fsm_count_en = VL_RAND_RESET_I(1);
    stopwatch_top__DOT__fsm_clear = VL_RAND_RESET_I(1);
    stopwatch_top__DOT__u_control_fsm__DOT__current_state = VL_RAND_RESET_I(2);
    stopwatch_top__DOT__u_control_fsm__DOT__next_state = VL_RAND_RESET_I(2);
    __Vtableidx1 = 0;
    __Vtable1_stopwatch_top__DOT__u_control_fsm__DOT__next_state[0] = 0U;
    __Vtable1_stopwatch_top__DOT__u_control_fsm__DOT__next_state[1] = 1U;
    __Vtable1_stopwatch_top__DOT__u_control_fsm__DOT__next_state[2] = 2U;
    __Vtable1_stopwatch_top__DOT__u_control_fsm__DOT__next_state[3] = 0U;
    __Vtable1_stopwatch_top__DOT__u_control_fsm__DOT__next_state[4] = 1U;
    __Vtable1_stopwatch_top__DOT__u_control_fsm__DOT__next_state[5] = 1U;
    __Vtable1_stopwatch_top__DOT__u_control_fsm__DOT__next_state[6] = 1U;
    __Vtable1_stopwatch_top__DOT__u_control_fsm__DOT__next_state[7] = 0U;
    __Vtable1_stopwatch_top__DOT__u_control_fsm__DOT__next_state[8] = 0U;
    __Vtable1_stopwatch_top__DOT__u_control_fsm__DOT__next_state[9] = 0U;
    __Vtable1_stopwatch_top__DOT__u_control_fsm__DOT__next_state[10] = 0U;
    __Vtable1_stopwatch_top__DOT__u_control_fsm__DOT__next_state[11] = 0U;
    __Vtable1_stopwatch_top__DOT__u_control_fsm__DOT__next_state[12] = 1U;
    __Vtable1_stopwatch_top__DOT__u_control_fsm__DOT__next_state[13] = 0U;
    __Vtable1_stopwatch_top__DOT__u_control_fsm__DOT__next_state[14] = 0U;
    __Vtable1_stopwatch_top__DOT__u_control_fsm__DOT__next_state[15] = 0U;
    __Vtable1_stopwatch_top__DOT__u_control_fsm__DOT__next_state[16] = 0U;
    __Vtable1_stopwatch_top__DOT__u_control_fsm__DOT__next_state[17] = 2U;
    __Vtable1_stopwatch_top__DOT__u_control_fsm__DOT__next_state[18] = 2U;
    __Vtable1_stopwatch_top__DOT__u_control_fsm__DOT__next_state[19] = 0U;
    __Vtable1_stopwatch_top__DOT__u_control_fsm__DOT__next_state[20] = 1U;
    __Vtable1_stopwatch_top__DOT__u_control_fsm__DOT__next_state[21] = 2U;
    __Vtable1_stopwatch_top__DOT__u_control_fsm__DOT__next_state[22] = 1U;
    __Vtable1_stopwatch_top__DOT__u_control_fsm__DOT__next_state[23] = 0U;
    __Vtable1_stopwatch_top__DOT__u_control_fsm__DOT__next_state[24] = 0U;
    __Vtable1_stopwatch_top__DOT__u_control_fsm__DOT__next_state[25] = 0U;
    __Vtable1_stopwatch_top__DOT__u_control_fsm__DOT__next_state[26] = 0U;
    __Vtable1_stopwatch_top__DOT__u_control_fsm__DOT__next_state[27] = 0U;
    __Vtable1_stopwatch_top__DOT__u_control_fsm__DOT__next_state[28] = 1U;
    __Vtable1_stopwatch_top__DOT__u_control_fsm__DOT__next_state[29] = 0U;
    __Vtable1_stopwatch_top__DOT__u_control_fsm__DOT__next_state[30] = 0U;
    __Vtable1_stopwatch_top__DOT__u_control_fsm__DOT__next_state[31] = 0U;
}
