// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vstopwatch_top.h for the primary calling header

#include "Vstopwatch_top.h"
#include "Vstopwatch_top__Syms.h"

//==========

void Vstopwatch_top::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vstopwatch_top::eval\n"); );
    Vstopwatch_top__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vstopwatch_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("../rtl/../rtl/stopwatch_top.v", 2, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vstopwatch_top::_eval_initial_loop(Vstopwatch_top__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("../rtl/../rtl/stopwatch_top.v", 2, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vstopwatch_top::_sequent__TOP__1(Vstopwatch_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top::_sequent__TOP__1\n"); );
    Vstopwatch_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*5:0*/ __Vdly__seconds;
    CData/*7:0*/ __Vdly__minutes;
    // Body
    __Vdly__seconds = vlTOPp->seconds;
    __Vdly__minutes = vlTOPp->minutes;
    if (vlTOPp->rst_n) {
        if (vlTOPp->stopwatch_top__DOT__fsm_clear) {
            __Vdly__seconds = 0U;
        } else {
            if (vlTOPp->stopwatch_top__DOT__fsm_count_en) {
                __Vdly__seconds = ((0x3bU == (IData)(vlTOPp->seconds))
                                    ? 0U : (0x3fU & 
                                            ((IData)(1U) 
                                             + (IData)(vlTOPp->seconds))));
            }
        }
    } else {
        __Vdly__seconds = 0U;
    }
    if (vlTOPp->rst_n) {
        if (vlTOPp->stopwatch_top__DOT__fsm_clear) {
            __Vdly__minutes = 0U;
        } else {
            if (((0x3bU == (IData)(vlTOPp->seconds)) 
                 & (IData)(vlTOPp->stopwatch_top__DOT__fsm_count_en))) {
                __Vdly__minutes = ((0x63U == (IData)(vlTOPp->minutes))
                                    ? 0U : (0xffU & 
                                            ((IData)(1U) 
                                             + (IData)(vlTOPp->minutes))));
            }
        }
    } else {
        __Vdly__minutes = 0U;
    }
    vlTOPp->stopwatch_top__DOT__u_control_fsm__DOT__current_state 
        = ((IData)(vlTOPp->rst_n) ? (IData)(vlTOPp->stopwatch_top__DOT__u_control_fsm__DOT__next_state)
            : 0U);
    vlTOPp->minutes = __Vdly__minutes;
    vlTOPp->seconds = __Vdly__seconds;
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
}

VL_INLINE_OPT void Vstopwatch_top::_combo__TOP__3(Vstopwatch_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top::_combo__TOP__3\n"); );
    Vstopwatch_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vtableidx1 = (((IData)(vlTOPp->stop) 
                             << 4U) | (((IData)(vlTOPp->reset) 
                                        << 3U) | (((IData)(vlTOPp->start) 
                                                   << 2U) 
                                                  | (IData)(vlTOPp->stopwatch_top__DOT__u_control_fsm__DOT__current_state))));
    vlTOPp->stopwatch_top__DOT__u_control_fsm__DOT__next_state 
        = vlTOPp->__Vtable1_stopwatch_top__DOT__u_control_fsm__DOT__next_state
        [vlTOPp->__Vtableidx1];
}

void Vstopwatch_top::_eval(Vstopwatch_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top::_eval\n"); );
    Vstopwatch_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlTOPp->rst_n)) & (IData)(vlTOPp->__Vclklast__TOP__rst_n)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    vlTOPp->_combo__TOP__3(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__rst_n = vlTOPp->rst_n;
}

VL_INLINE_OPT QData Vstopwatch_top::_change_request(Vstopwatch_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top::_change_request\n"); );
    Vstopwatch_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vstopwatch_top::_change_request_1(Vstopwatch_top__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top::_change_request_1\n"); );
    Vstopwatch_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vstopwatch_top::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((rst_n & 0xfeU))) {
        Verilated::overWidthError("rst_n");}
    if (VL_UNLIKELY((start & 0xfeU))) {
        Verilated::overWidthError("start");}
    if (VL_UNLIKELY((stop & 0xfeU))) {
        Verilated::overWidthError("stop");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
