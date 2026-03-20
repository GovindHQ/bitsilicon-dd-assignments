// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vstopwatch_top.h for the primary calling header

#ifndef VERILATED_VSTOPWATCH_TOP___024ROOT_H_
#define VERILATED_VSTOPWATCH_TOP___024ROOT_H_  // guard

#include "verilated.h"


class Vstopwatch_top__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vstopwatch_top___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    CData/*0:0*/ stopwatch_top__DOT__sec_inst__DOT__rst_combined;
    CData/*0:0*/ stopwatch_top__DOT__min_inst__DOT__rst_combined;
    VL_IN8(start,0,0);
    VL_IN8(stop,0,0);
    VL_IN8(reset,0,0);
    VL_OUT8(minutes,7,0);
    VL_OUT8(seconds,5,0);
    VL_OUT8(status,1,0);
    CData/*0:0*/ stopwatch_top__DOT__seconds_roll;
    CData/*1:0*/ stopwatch_top__DOT__fsm_inst__DOT__current_state;
    CData/*1:0*/ stopwatch_top__DOT__fsm_inst__DOT__next_state;
    CData/*0:0*/ stopwatch_top__DOT__sec_inst__DOT__j1;
    CData/*0:0*/ stopwatch_top__DOT__sec_inst__DOT__j2;
    CData/*0:0*/ stopwatch_top__DOT__sec_inst__DOT__j3;
    CData/*0:0*/ stopwatch_top__DOT__sec_inst__DOT__j4;
    CData/*0:0*/ stopwatch_top__DOT__sec_inst__DOT__j5;
    CData/*0:0*/ stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff0__q;
    CData/*0:0*/ stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff1__q;
    CData/*0:0*/ stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff2__q;
    CData/*0:0*/ stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff3__q;
    CData/*0:0*/ stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff4__q;
    CData/*0:0*/ stopwatch_top__DOT__sec_inst__DOT____Vcellout__ff5__q;
    CData/*0:0*/ stopwatch_top__DOT__sec_inst__DOT____VdfgTmp_h45d1b877__0;
    CData/*0:0*/ stopwatch_top__DOT__min_inst__DOT__j1;
    CData/*0:0*/ stopwatch_top__DOT__min_inst__DOT__j2;
    CData/*0:0*/ stopwatch_top__DOT__min_inst__DOT__j3;
    CData/*0:0*/ stopwatch_top__DOT__min_inst__DOT__j4;
    CData/*0:0*/ stopwatch_top__DOT__min_inst__DOT__j5;
    CData/*0:0*/ stopwatch_top__DOT__min_inst__DOT__j6;
    CData/*0:0*/ stopwatch_top__DOT__min_inst__DOT__j7;
    CData/*0:0*/ stopwatch_top__DOT__min_inst__DOT____Vcellout__ff0__q;
    CData/*0:0*/ stopwatch_top__DOT__min_inst__DOT____Vcellout__ff1__q;
    CData/*0:0*/ stopwatch_top__DOT__min_inst__DOT____Vcellout__ff2__q;
    CData/*0:0*/ stopwatch_top__DOT__min_inst__DOT____Vcellout__ff3__q;
    CData/*0:0*/ stopwatch_top__DOT__min_inst__DOT____Vcellout__ff4__q;
    CData/*0:0*/ stopwatch_top__DOT__min_inst__DOT____Vcellout__ff5__q;
    CData/*0:0*/ stopwatch_top__DOT__min_inst__DOT____Vcellout__ff6__q;
    CData/*0:0*/ stopwatch_top__DOT__min_inst__DOT____Vcellout__ff7__q;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__stopwatch_top__DOT__sec_inst__DOT__rst_combined__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__stopwatch_top__DOT__min_inst__DOT__rst_combined__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vstopwatch_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vstopwatch_top___024root(Vstopwatch_top__Syms* symsp, const char* v__name);
    ~Vstopwatch_top___024root();
    VL_UNCOPYABLE(Vstopwatch_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
