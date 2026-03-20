// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vcontrol_fsm__pch.h"

//============================================================
// Constructors

Vcontrol_fsm::Vcontrol_fsm(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vcontrol_fsm__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst_n{vlSymsp->TOP.rst_n}
    , start{vlSymsp->TOP.start}
    , stop{vlSymsp->TOP.stop}
    , reset{vlSymsp->TOP.reset}
    , minutes{vlSymsp->TOP.minutes}
    , seconds{vlSymsp->TOP.seconds}
    , status{vlSymsp->TOP.status}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vcontrol_fsm::Vcontrol_fsm(const char* _vcname__)
    : Vcontrol_fsm(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vcontrol_fsm::~Vcontrol_fsm() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vcontrol_fsm___024root___eval_debug_assertions(Vcontrol_fsm___024root* vlSelf);
#endif  // VL_DEBUG
void Vcontrol_fsm___024root___eval_static(Vcontrol_fsm___024root* vlSelf);
void Vcontrol_fsm___024root___eval_initial(Vcontrol_fsm___024root* vlSelf);
void Vcontrol_fsm___024root___eval_settle(Vcontrol_fsm___024root* vlSelf);
void Vcontrol_fsm___024root___eval(Vcontrol_fsm___024root* vlSelf);

void Vcontrol_fsm::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vcontrol_fsm::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vcontrol_fsm___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vcontrol_fsm___024root___eval_static(&(vlSymsp->TOP));
        Vcontrol_fsm___024root___eval_initial(&(vlSymsp->TOP));
        Vcontrol_fsm___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vcontrol_fsm___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vcontrol_fsm::eventsPending() { return false; }

uint64_t Vcontrol_fsm::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vcontrol_fsm::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vcontrol_fsm___024root___eval_final(Vcontrol_fsm___024root* vlSelf);

VL_ATTR_COLD void Vcontrol_fsm::final() {
    Vcontrol_fsm___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vcontrol_fsm::hierName() const { return vlSymsp->name(); }
const char* Vcontrol_fsm::modelName() const { return "Vcontrol_fsm"; }
unsigned Vcontrol_fsm::threads() const { return 1; }
void Vcontrol_fsm::prepareClone() const { contextp()->prepareClone(); }
void Vcontrol_fsm::atClone() const {
    contextp()->threadPoolpOnClone();
}
