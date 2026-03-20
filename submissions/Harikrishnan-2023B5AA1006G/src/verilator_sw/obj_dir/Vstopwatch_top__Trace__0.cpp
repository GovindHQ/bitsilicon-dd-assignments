// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vstopwatch_top__Syms.h"


void Vstopwatch_top___024root__trace_chg_0_sub_0(Vstopwatch_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vstopwatch_top___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root__trace_chg_0\n"); );
    // Init
    Vstopwatch_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vstopwatch_top___024root*>(voidSelf);
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vstopwatch_top___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vstopwatch_top___024root__trace_chg_0_sub_0(Vstopwatch_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    bufp->chgBit(oldp+0,(vlSelf->clk));
    bufp->chgBit(oldp+1,(vlSelf->rst_n));
    bufp->chgBit(oldp+2,(vlSelf->start));
    bufp->chgBit(oldp+3,(vlSelf->stop));
    bufp->chgBit(oldp+4,(vlSelf->reset));
    bufp->chgCData(oldp+5,(vlSelf->minutes),8);
    bufp->chgCData(oldp+6,(vlSelf->seconds),6);
    bufp->chgCData(oldp+7,(vlSelf->status),2);
    bufp->chgBit(oldp+8,((1U == (IData)(vlSelf->stopwatch_top__DOT__fsm__DOT__state))));
    bufp->chgBit(oldp+9,(((0x3bU == (IData)(vlSelf->seconds)) 
                          & (1U == (IData)(vlSelf->stopwatch_top__DOT__fsm__DOT__state)))));
    bufp->chgCData(oldp+10,(vlSelf->stopwatch_top__DOT__fsm__DOT__state),2);
    bufp->chgCData(oldp+11,(vlSelf->stopwatch_top__DOT__fsm__DOT__next_state),2);
    bufp->chgBit(oldp+12,((IData)(((1U == (IData)(vlSelf->stopwatch_top__DOT__fsm__DOT__state)) 
                                   & (0x3bU == (IData)(vlSelf->seconds))))));
}

void Vstopwatch_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root__trace_cleanup\n"); );
    // Init
    Vstopwatch_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vstopwatch_top___024root*>(voidSelf);
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
