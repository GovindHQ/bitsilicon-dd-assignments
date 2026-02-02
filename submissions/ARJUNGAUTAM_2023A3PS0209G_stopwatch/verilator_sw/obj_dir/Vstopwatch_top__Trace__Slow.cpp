// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vstopwatch_top__Syms.h"


//======================

void Vstopwatch_top::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vstopwatch_top::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vstopwatch_top__Syms* __restrict vlSymsp = static_cast<Vstopwatch_top__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vstopwatch_top::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vstopwatch_top::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vstopwatch_top__Syms* __restrict vlSymsp = static_cast<Vstopwatch_top__Syms*>(userp);
    Vstopwatch_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vstopwatch_top::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vstopwatch_top__Syms* __restrict vlSymsp = static_cast<Vstopwatch_top__Syms*>(userp);
    Vstopwatch_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"clk", false,-1);
        tracep->declBit(c+2,"rst_n", false,-1);
        tracep->declBit(c+3,"start", false,-1);
        tracep->declBit(c+4,"stop", false,-1);
        tracep->declBit(c+5,"reset", false,-1);
        tracep->declBus(c+6,"minutes", false,-1, 7,0);
        tracep->declBus(c+7,"seconds", false,-1, 5,0);
        tracep->declBus(c+8,"status", false,-1, 1,0);
        tracep->declBit(c+1,"stopwatch_top clk", false,-1);
        tracep->declBit(c+2,"stopwatch_top rst_n", false,-1);
        tracep->declBit(c+3,"stopwatch_top start", false,-1);
        tracep->declBit(c+4,"stopwatch_top stop", false,-1);
        tracep->declBit(c+5,"stopwatch_top reset", false,-1);
        tracep->declBus(c+6,"stopwatch_top minutes", false,-1, 7,0);
        tracep->declBus(c+7,"stopwatch_top seconds", false,-1, 5,0);
        tracep->declBus(c+8,"stopwatch_top status", false,-1, 1,0);
        tracep->declBit(c+9,"stopwatch_top rollover", false,-1);
        tracep->declBit(c+10,"stopwatch_top running", false,-1);
        tracep->declBit(c+1,"stopwatch_top fsm_inst clk", false,-1);
        tracep->declBit(c+2,"stopwatch_top fsm_inst rst_n", false,-1);
        tracep->declBit(c+3,"stopwatch_top fsm_inst start", false,-1);
        tracep->declBit(c+4,"stopwatch_top fsm_inst stop", false,-1);
        tracep->declBit(c+5,"stopwatch_top fsm_inst reset", false,-1);
        tracep->declBus(c+8,"stopwatch_top fsm_inst status", false,-1, 1,0);
        tracep->declBus(c+11,"stopwatch_top fsm_inst IDLE", false,-1, 1,0);
        tracep->declBus(c+12,"stopwatch_top fsm_inst RUNNING", false,-1, 1,0);
        tracep->declBus(c+13,"stopwatch_top fsm_inst PAUSED", false,-1, 1,0);
        tracep->declBit(c+1,"stopwatch_top sec_inst clk", false,-1);
        tracep->declBit(c+2,"stopwatch_top sec_inst rst_n", false,-1);
        tracep->declBit(c+5,"stopwatch_top sec_inst reset", false,-1);
        tracep->declBit(c+10,"stopwatch_top sec_inst enable", false,-1);
        tracep->declBus(c+7,"stopwatch_top sec_inst seconds", false,-1, 5,0);
        tracep->declBit(c+9,"stopwatch_top sec_inst rollover", false,-1);
        tracep->declBit(c+1,"stopwatch_top min_inst clk", false,-1);
        tracep->declBit(c+2,"stopwatch_top min_inst rst_n", false,-1);
        tracep->declBit(c+5,"stopwatch_top min_inst reset", false,-1);
        tracep->declBit(c+9,"stopwatch_top min_inst enable", false,-1);
        tracep->declBus(c+6,"stopwatch_top min_inst minutes", false,-1, 7,0);
    }
}

void Vstopwatch_top::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vstopwatch_top::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vstopwatch_top__Syms* __restrict vlSymsp = static_cast<Vstopwatch_top__Syms*>(userp);
    Vstopwatch_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vstopwatch_top::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vstopwatch_top__Syms* __restrict vlSymsp = static_cast<Vstopwatch_top__Syms*>(userp);
    Vstopwatch_top* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->clk));
        tracep->fullBit(oldp+2,(vlTOPp->rst_n));
        tracep->fullBit(oldp+3,(vlTOPp->start));
        tracep->fullBit(oldp+4,(vlTOPp->stop));
        tracep->fullBit(oldp+5,(vlTOPp->reset));
        tracep->fullCData(oldp+6,(vlTOPp->minutes),8);
        tracep->fullCData(oldp+7,(vlTOPp->seconds),6);
        tracep->fullCData(oldp+8,(vlTOPp->status),2);
        tracep->fullBit(oldp+9,(vlTOPp->stopwatch_top__DOT__rollover));
        tracep->fullBit(oldp+10,((1U == (IData)(vlTOPp->status))));
        tracep->fullCData(oldp+11,(0U),2);
        tracep->fullCData(oldp+12,(1U),2);
        tracep->fullCData(oldp+13,(2U),2);
    }
}
