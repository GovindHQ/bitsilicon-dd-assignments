// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vstopwatch_top__Syms.h"


void Vstopwatch_top::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vstopwatch_top__Syms* __restrict vlSymsp = static_cast<Vstopwatch_top__Syms*>(userp);
    Vstopwatch_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vstopwatch_top::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vstopwatch_top__Syms* __restrict vlSymsp = static_cast<Vstopwatch_top__Syms*>(userp);
    Vstopwatch_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgBit(oldp+0,(vlTOPp->clk));
        tracep->chgBit(oldp+1,(vlTOPp->rst_n));
        tracep->chgBit(oldp+2,(vlTOPp->start));
        tracep->chgBit(oldp+3,(vlTOPp->stop));
        tracep->chgBit(oldp+4,(vlTOPp->reset));
        tracep->chgCData(oldp+5,(vlTOPp->minutes),8);
        tracep->chgCData(oldp+6,(vlTOPp->seconds),6);
        tracep->chgCData(oldp+7,(vlTOPp->status),2);
        tracep->chgBit(oldp+8,(vlTOPp->stopwatch_top__DOT__rollover));
        tracep->chgBit(oldp+9,((1U == (IData)(vlTOPp->status))));
    }
}

void Vstopwatch_top::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vstopwatch_top__Syms* __restrict vlSymsp = static_cast<Vstopwatch_top__Syms*>(userp);
    Vstopwatch_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
    }
}
