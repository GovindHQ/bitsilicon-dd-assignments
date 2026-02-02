// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vstopwatch_top.h for the primary calling header

#include "Vstopwatch_top.h"
#include "Vstopwatch_top__Syms.h"

//==========
CData/*1:0*/ Vstopwatch_top::__Vtable1_status[64];

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
    stopwatch_top__DOT__rollover = VL_RAND_RESET_I(1);
    __Vtablechg1[0] = 1U;
    __Vtablechg1[1] = 0U;
    __Vtablechg1[2] = 1U;
    __Vtablechg1[3] = 1U;
    __Vtablechg1[4] = 1U;
    __Vtablechg1[5] = 0U;
    __Vtablechg1[6] = 1U;
    __Vtablechg1[7] = 1U;
    __Vtablechg1[8] = 1U;
    __Vtablechg1[9] = 0U;
    __Vtablechg1[10] = 1U;
    __Vtablechg1[11] = 1U;
    __Vtablechg1[12] = 1U;
    __Vtablechg1[13] = 1U;
    __Vtablechg1[14] = 1U;
    __Vtablechg1[15] = 1U;
    __Vtablechg1[16] = 1U;
    __Vtablechg1[17] = 1U;
    __Vtablechg1[18] = 1U;
    __Vtablechg1[19] = 1U;
    __Vtablechg1[20] = 1U;
    __Vtablechg1[21] = 0U;
    __Vtablechg1[22] = 1U;
    __Vtablechg1[23] = 1U;
    __Vtablechg1[24] = 1U;
    __Vtablechg1[25] = 1U;
    __Vtablechg1[26] = 1U;
    __Vtablechg1[27] = 1U;
    __Vtablechg1[28] = 1U;
    __Vtablechg1[29] = 1U;
    __Vtablechg1[30] = 1U;
    __Vtablechg1[31] = 1U;
    __Vtablechg1[32] = 1U;
    __Vtablechg1[33] = 0U;
    __Vtablechg1[34] = 1U;
    __Vtablechg1[35] = 1U;
    __Vtablechg1[36] = 1U;
    __Vtablechg1[37] = 1U;
    __Vtablechg1[38] = 1U;
    __Vtablechg1[39] = 1U;
    __Vtablechg1[40] = 1U;
    __Vtablechg1[41] = 0U;
    __Vtablechg1[42] = 1U;
    __Vtablechg1[43] = 1U;
    __Vtablechg1[44] = 1U;
    __Vtablechg1[45] = 1U;
    __Vtablechg1[46] = 1U;
    __Vtablechg1[47] = 1U;
    __Vtablechg1[48] = 1U;
    __Vtablechg1[49] = 1U;
    __Vtablechg1[50] = 1U;
    __Vtablechg1[51] = 1U;
    __Vtablechg1[52] = 1U;
    __Vtablechg1[53] = 1U;
    __Vtablechg1[54] = 1U;
    __Vtablechg1[55] = 1U;
    __Vtablechg1[56] = 1U;
    __Vtablechg1[57] = 1U;
    __Vtablechg1[58] = 1U;
    __Vtablechg1[59] = 1U;
    __Vtablechg1[60] = 1U;
    __Vtablechg1[61] = 1U;
    __Vtablechg1[62] = 1U;
    __Vtablechg1[63] = 1U;
    __Vtable1_status[0] = 0U;
    __Vtable1_status[1] = 0U;
    __Vtable1_status[2] = 0U;
    __Vtable1_status[3] = 0U;
    __Vtable1_status[4] = 0U;
    __Vtable1_status[5] = 0U;
    __Vtable1_status[6] = 0U;
    __Vtable1_status[7] = 0U;
    __Vtable1_status[8] = 0U;
    __Vtable1_status[9] = 0U;
    __Vtable1_status[10] = 0U;
    __Vtable1_status[11] = 0U;
    __Vtable1_status[12] = 0U;
    __Vtable1_status[13] = 0U;
    __Vtable1_status[14] = 0U;
    __Vtable1_status[15] = 0U;
    __Vtable1_status[16] = 0U;
    __Vtable1_status[17] = 1U;
    __Vtable1_status[18] = 0U;
    __Vtable1_status[19] = 0U;
    __Vtable1_status[20] = 0U;
    __Vtable1_status[21] = 0U;
    __Vtable1_status[22] = 0U;
    __Vtable1_status[23] = 0U;
    __Vtable1_status[24] = 0U;
    __Vtable1_status[25] = 1U;
    __Vtable1_status[26] = 0U;
    __Vtable1_status[27] = 0U;
    __Vtable1_status[28] = 0U;
    __Vtable1_status[29] = 0U;
    __Vtable1_status[30] = 0U;
    __Vtable1_status[31] = 0U;
    __Vtable1_status[32] = 0U;
    __Vtable1_status[33] = 0U;
    __Vtable1_status[34] = 0U;
    __Vtable1_status[35] = 0U;
    __Vtable1_status[36] = 0U;
    __Vtable1_status[37] = 2U;
    __Vtable1_status[38] = 0U;
    __Vtable1_status[39] = 0U;
    __Vtable1_status[40] = 0U;
    __Vtable1_status[41] = 0U;
    __Vtable1_status[42] = 0U;
    __Vtable1_status[43] = 0U;
    __Vtable1_status[44] = 0U;
    __Vtable1_status[45] = 0U;
    __Vtable1_status[46] = 0U;
    __Vtable1_status[47] = 0U;
    __Vtable1_status[48] = 0U;
    __Vtable1_status[49] = 1U;
    __Vtable1_status[50] = 0U;
    __Vtable1_status[51] = 0U;
    __Vtable1_status[52] = 0U;
    __Vtable1_status[53] = 2U;
    __Vtable1_status[54] = 0U;
    __Vtable1_status[55] = 0U;
    __Vtable1_status[56] = 0U;
    __Vtable1_status[57] = 1U;
    __Vtable1_status[58] = 0U;
    __Vtable1_status[59] = 0U;
    __Vtable1_status[60] = 0U;
    __Vtable1_status[61] = 0U;
    __Vtable1_status[62] = 0U;
    __Vtable1_status[63] = 0U;
    { int __Vi0=0; for (; __Vi0<1; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
