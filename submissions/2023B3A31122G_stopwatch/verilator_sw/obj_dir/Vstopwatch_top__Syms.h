// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VSTOPWATCH_TOP__SYMS_H_
#define VERILATED_VSTOPWATCH_TOP__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vstopwatch_top.h"

// INCLUDE MODULE CLASSES
#include "Vstopwatch_top___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vstopwatch_top__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vstopwatch_top* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vstopwatch_top___024root       TOP;

    // CONSTRUCTORS
    Vstopwatch_top__Syms(VerilatedContext* contextp, const char* namep, Vstopwatch_top* modelp);
    ~Vstopwatch_top__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
