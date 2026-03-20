// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vcontrol_fsm.h for the primary calling header

#ifndef VERILATED_VCONTROL_FSM___024ROOT_H_
#define VERILATED_VCONTROL_FSM___024ROOT_H_  // guard

#include "verilated.h"


class Vcontrol_fsm__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vcontrol_fsm___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_IN8(start,0,0);
    VL_IN8(stop,0,0);
    VL_IN8(reset,0,0);
    VL_OUT8(minutes,7,0);
    VL_OUT8(seconds,5,0);
    VL_OUT8(status,1,0);
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vcontrol_fsm__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vcontrol_fsm___024root(Vcontrol_fsm__Syms* symsp, const char* v__name);
    ~Vcontrol_fsm___024root();
    VL_UNCOPYABLE(Vcontrol_fsm___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
