// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vstopwatch_top.h for the primary calling header

#ifndef VERILATED_VSTOPWATCH_TOP___024ROOT_H_
#define VERILATED_VSTOPWATCH_TOP___024ROOT_H_  // guard

#include "verilated.h"


class Vstopwatch_top__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vstopwatch_top___024root final {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_IN8(start,0,0);
    VL_IN8(stop,0,0);
    VL_IN8(rst,0,0);
    VL_OUT8(minutes,7,0);
    VL_OUT8(seconds,5,0);
    VL_OUT8(status,1,0);
    CData/*1:0*/ stopwatch_top__DOT__mode_reg;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VstlPhaseResult;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __VicoPhaseResult;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
    CData/*0:0*/ __VactPhaseResult;
    CData/*0:0*/ __VnbaPhaseResult;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vstopwatch_top__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vstopwatch_top___024root(Vstopwatch_top__Syms* symsp, const char* namep);
    ~Vstopwatch_top___024root();
    VL_UNCOPYABLE(Vstopwatch_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
