// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vstopwatch_top.h for the primary calling header

#include "Vstopwatch_top.h"
#include "Vstopwatch_top__Syms.h"

//==========
CData/*1:0*/ Vstopwatch_top::__Vtable1_stopwatch_top__DOT__fsm_inst__DOT__next_state[32];
CData/*0:0*/ Vstopwatch_top::__Vtable1_stopwatch_top__DOT__stopwatch_start[32];
CData/*1:0*/ Vstopwatch_top::__Vtable1_status[32];

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
    minutes = VL_RAND_RESET_I(7);
    seconds = VL_RAND_RESET_I(6);
    status = VL_RAND_RESET_I(2);
    stopwatch_top__DOT__stopwatch_start = VL_RAND_RESET_I(1);
    stopwatch_top__DOT__fsm_inst__DOT__current_state = VL_RAND_RESET_I(2);
    stopwatch_top__DOT__fsm_inst__DOT__next_state = VL_RAND_RESET_I(2);
    __Vtableidx1 = 0;
    __Vtable1_stopwatch_top__DOT__fsm_inst__DOT__next_state[0] = 0U;
    __Vtable1_stopwatch_top__DOT__fsm_inst__DOT__next_state[1] = 1U;
    __Vtable1_stopwatch_top__DOT__fsm_inst__DOT__next_state[2] = 2U;
    __Vtable1_stopwatch_top__DOT__fsm_inst__DOT__next_state[3] = 0U;
    __Vtable1_stopwatch_top__DOT__fsm_inst__DOT__next_state[4] = 1U;
    __Vtable1_stopwatch_top__DOT__fsm_inst__DOT__next_state[5] = 1U;
    __Vtable1_stopwatch_top__DOT__fsm_inst__DOT__next_state[6] = 1U;
    __Vtable1_stopwatch_top__DOT__fsm_inst__DOT__next_state[7] = 0U;
    __Vtable1_stopwatch_top__DOT__fsm_inst__DOT__next_state[8] = 0U;
    __Vtable1_stopwatch_top__DOT__fsm_inst__DOT__next_state[9] = 2U;
    __Vtable1_stopwatch_top__DOT__fsm_inst__DOT__next_state[10] = 2U;
    __Vtable1_stopwatch_top__DOT__fsm_inst__DOT__next_state[11] = 0U;
    __Vtable1_stopwatch_top__DOT__fsm_inst__DOT__next_state[12] = 1U;
    __Vtable1_stopwatch_top__DOT__fsm_inst__DOT__next_state[13] = 2U;
    __Vtable1_stopwatch_top__DOT__fsm_inst__DOT__next_state[14] = 1U;
    __Vtable1_stopwatch_top__DOT__fsm_inst__DOT__next_state[15] = 0U;
    __Vtable1_stopwatch_top__DOT__fsm_inst__DOT__next_state[16] = 0U;
    __Vtable1_stopwatch_top__DOT__fsm_inst__DOT__next_state[17] = 1U;
    __Vtable1_stopwatch_top__DOT__fsm_inst__DOT__next_state[18] = 0U;
    __Vtable1_stopwatch_top__DOT__fsm_inst__DOT__next_state[19] = 0U;
    __Vtable1_stopwatch_top__DOT__fsm_inst__DOT__next_state[20] = 1U;
    __Vtable1_stopwatch_top__DOT__fsm_inst__DOT__next_state[21] = 1U;
    __Vtable1_stopwatch_top__DOT__fsm_inst__DOT__next_state[22] = 1U;
    __Vtable1_stopwatch_top__DOT__fsm_inst__DOT__next_state[23] = 0U;
    __Vtable1_stopwatch_top__DOT__fsm_inst__DOT__next_state[24] = 0U;
    __Vtable1_stopwatch_top__DOT__fsm_inst__DOT__next_state[25] = 2U;
    __Vtable1_stopwatch_top__DOT__fsm_inst__DOT__next_state[26] = 0U;
    __Vtable1_stopwatch_top__DOT__fsm_inst__DOT__next_state[27] = 0U;
    __Vtable1_stopwatch_top__DOT__fsm_inst__DOT__next_state[28] = 1U;
    __Vtable1_stopwatch_top__DOT__fsm_inst__DOT__next_state[29] = 2U;
    __Vtable1_stopwatch_top__DOT__fsm_inst__DOT__next_state[30] = 1U;
    __Vtable1_stopwatch_top__DOT__fsm_inst__DOT__next_state[31] = 0U;
    __Vtable1_stopwatch_top__DOT__stopwatch_start[0] = 0U;
    __Vtable1_stopwatch_top__DOT__stopwatch_start[1] = 1U;
    __Vtable1_stopwatch_top__DOT__stopwatch_start[2] = 0U;
    __Vtable1_stopwatch_top__DOT__stopwatch_start[3] = 0U;
    __Vtable1_stopwatch_top__DOT__stopwatch_start[4] = 0U;
    __Vtable1_stopwatch_top__DOT__stopwatch_start[5] = 1U;
    __Vtable1_stopwatch_top__DOT__stopwatch_start[6] = 0U;
    __Vtable1_stopwatch_top__DOT__stopwatch_start[7] = 0U;
    __Vtable1_stopwatch_top__DOT__stopwatch_start[8] = 0U;
    __Vtable1_stopwatch_top__DOT__stopwatch_start[9] = 1U;
    __Vtable1_stopwatch_top__DOT__stopwatch_start[10] = 0U;
    __Vtable1_stopwatch_top__DOT__stopwatch_start[11] = 0U;
    __Vtable1_stopwatch_top__DOT__stopwatch_start[12] = 0U;
    __Vtable1_stopwatch_top__DOT__stopwatch_start[13] = 1U;
    __Vtable1_stopwatch_top__DOT__stopwatch_start[14] = 0U;
    __Vtable1_stopwatch_top__DOT__stopwatch_start[15] = 0U;
    __Vtable1_stopwatch_top__DOT__stopwatch_start[16] = 0U;
    __Vtable1_stopwatch_top__DOT__stopwatch_start[17] = 1U;
    __Vtable1_stopwatch_top__DOT__stopwatch_start[18] = 0U;
    __Vtable1_stopwatch_top__DOT__stopwatch_start[19] = 0U;
    __Vtable1_stopwatch_top__DOT__stopwatch_start[20] = 0U;
    __Vtable1_stopwatch_top__DOT__stopwatch_start[21] = 1U;
    __Vtable1_stopwatch_top__DOT__stopwatch_start[22] = 0U;
    __Vtable1_stopwatch_top__DOT__stopwatch_start[23] = 0U;
    __Vtable1_stopwatch_top__DOT__stopwatch_start[24] = 0U;
    __Vtable1_stopwatch_top__DOT__stopwatch_start[25] = 1U;
    __Vtable1_stopwatch_top__DOT__stopwatch_start[26] = 0U;
    __Vtable1_stopwatch_top__DOT__stopwatch_start[27] = 0U;
    __Vtable1_stopwatch_top__DOT__stopwatch_start[28] = 0U;
    __Vtable1_stopwatch_top__DOT__stopwatch_start[29] = 1U;
    __Vtable1_stopwatch_top__DOT__stopwatch_start[30] = 0U;
    __Vtable1_stopwatch_top__DOT__stopwatch_start[31] = 0U;
    __Vtable1_status[0] = 0U;
    __Vtable1_status[1] = 1U;
    __Vtable1_status[2] = 2U;
    __Vtable1_status[3] = 3U;
    __Vtable1_status[4] = 0U;
    __Vtable1_status[5] = 1U;
    __Vtable1_status[6] = 2U;
    __Vtable1_status[7] = 3U;
    __Vtable1_status[8] = 0U;
    __Vtable1_status[9] = 1U;
    __Vtable1_status[10] = 2U;
    __Vtable1_status[11] = 3U;
    __Vtable1_status[12] = 0U;
    __Vtable1_status[13] = 1U;
    __Vtable1_status[14] = 2U;
    __Vtable1_status[15] = 3U;
    __Vtable1_status[16] = 0U;
    __Vtable1_status[17] = 1U;
    __Vtable1_status[18] = 2U;
    __Vtable1_status[19] = 3U;
    __Vtable1_status[20] = 0U;
    __Vtable1_status[21] = 1U;
    __Vtable1_status[22] = 2U;
    __Vtable1_status[23] = 3U;
    __Vtable1_status[24] = 0U;
    __Vtable1_status[25] = 1U;
    __Vtable1_status[26] = 2U;
    __Vtable1_status[27] = 3U;
    __Vtable1_status[28] = 0U;
    __Vtable1_status[29] = 1U;
    __Vtable1_status[30] = 2U;
    __Vtable1_status[31] = 3U;
}
