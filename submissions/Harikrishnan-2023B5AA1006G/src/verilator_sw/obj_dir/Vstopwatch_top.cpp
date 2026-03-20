// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vstopwatch_top__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vstopwatch_top::Vstopwatch_top(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vstopwatch_top__Syms(contextp(), _vcname__, this)}
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

Vstopwatch_top::Vstopwatch_top(const char* _vcname__)
    : Vstopwatch_top(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vstopwatch_top::~Vstopwatch_top() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vstopwatch_top___024root___eval_debug_assertions(Vstopwatch_top___024root* vlSelf);
#endif  // VL_DEBUG
void Vstopwatch_top___024root___eval_static(Vstopwatch_top___024root* vlSelf);
void Vstopwatch_top___024root___eval_initial(Vstopwatch_top___024root* vlSelf);
void Vstopwatch_top___024root___eval_settle(Vstopwatch_top___024root* vlSelf);
void Vstopwatch_top___024root___eval(Vstopwatch_top___024root* vlSelf);

void Vstopwatch_top::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vstopwatch_top::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vstopwatch_top___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vstopwatch_top___024root___eval_static(&(vlSymsp->TOP));
        Vstopwatch_top___024root___eval_initial(&(vlSymsp->TOP));
        Vstopwatch_top___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vstopwatch_top___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vstopwatch_top::eventsPending() { return false; }

uint64_t Vstopwatch_top::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vstopwatch_top::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vstopwatch_top___024root___eval_final(Vstopwatch_top___024root* vlSelf);

VL_ATTR_COLD void Vstopwatch_top::final() {
    Vstopwatch_top___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vstopwatch_top::hierName() const { return vlSymsp->name(); }
const char* Vstopwatch_top::modelName() const { return "Vstopwatch_top"; }
unsigned Vstopwatch_top::threads() const { return 1; }
void Vstopwatch_top::prepareClone() const { contextp()->prepareClone(); }
void Vstopwatch_top::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vstopwatch_top::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vstopwatch_top___024root__trace_decl_types(VerilatedVcd* tracep);

void Vstopwatch_top___024root__trace_init_top(Vstopwatch_top___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vstopwatch_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vstopwatch_top___024root*>(voidSelf);
    Vstopwatch_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vstopwatch_top___024root__trace_decl_types(tracep);
    Vstopwatch_top___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vstopwatch_top___024root__trace_register(Vstopwatch_top___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vstopwatch_top::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vstopwatch_top::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vstopwatch_top___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
