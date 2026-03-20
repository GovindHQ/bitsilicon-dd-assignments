// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vstopwatch_top.h for the primary calling header

#include "Vstopwatch_top__pch.h"
#include "Vstopwatch_top__Syms.h"
#include "Vstopwatch_top___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vstopwatch_top___024root___dump_triggers__act(Vstopwatch_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vstopwatch_top___024root___eval_triggers__act(Vstopwatch_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vstopwatch_top___024root___eval_triggers__act\n"); );
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vstopwatch_top___024root___dump_triggers__act(vlSelf);
    }
#endif
}
