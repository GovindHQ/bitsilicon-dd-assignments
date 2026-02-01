//1.Module: AND GATE
// Logic: The output is high (1) ONLY if both inputs 'a' AND 'b' are high.

module and_gate(
    input a,      // Input signal A
    input b,      // Input signal B
    output out    
);

  // 'assign' creates a continuous driving connection.
  assign out = a & b; // '&' is the bitwise AND operator in Verilog.

endmodule