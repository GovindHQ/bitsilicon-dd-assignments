// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vstopwatch_top.h for the primary calling header

#include "Vstopwatch_top__pch.h"
#include "Vstopwatch_top__Syms.h"
#include "Vstopwatch_top___024root.h"

void Vstopwatch_top___024root___ctor_var_reset(Vstopwatch_top___024root* vlSelf);

Vstopwatch_top___024root::Vstopwatch_top___024root(Vstopwatch_top__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vstopwatch_top___024root___ctor_var_reset(this);
}

void Vstopwatch_top___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vstopwatch_top___024root::~Vstopwatch_top___024root() {
}
