// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VCONTROL_FSM__SYMS_H_
#define VERILATED_VCONTROL_FSM__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vcontrol_fsm.h"

// INCLUDE MODULE CLASSES
#include "Vcontrol_fsm___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vcontrol_fsm__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vcontrol_fsm* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vcontrol_fsm___024root         TOP;

    // CONSTRUCTORS
    Vcontrol_fsm__Syms(VerilatedContext* contextp, const char* namep, Vcontrol_fsm* modelp);
    ~Vcontrol_fsm__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
