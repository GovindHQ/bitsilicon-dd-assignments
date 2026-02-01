// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vstopwatch_top.h for the primary calling header

#include "Vstopwatch_top__pch.h"

void Vstopwatch_top___024root___ctor_var_reset(Vstopwatch_top___024root* vlSelf);

Vstopwatch_top___024root::Vstopwatch_top___024root(Vstopwatch_top__Syms* symsp, const char* namep)
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vstopwatch_top___024root___ctor_var_reset(this);
}

void Vstopwatch_top___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vstopwatch_top___024root::~Vstopwatch_top___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
