// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vcontrol_fsm__pch.h"
#include "Vcontrol_fsm.h"
#include "Vcontrol_fsm___024root.h"

// FUNCTIONS
Vcontrol_fsm__Syms::~Vcontrol_fsm__Syms()
{
}

Vcontrol_fsm__Syms::Vcontrol_fsm__Syms(VerilatedContext* contextp, const char* namep, Vcontrol_fsm* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
        // Check resources
        Verilated::stackCheck(15);
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
