// 3. XOR Gate (Structural Logic)
// Logic: Output is high ONLY if inputs are different.
// Formula used: (A NAND B) AND (A OR B)
module xor_gate(
    input a,
    input b,
    output out);
    
    // This implementation filters out the 'both 1s' case via ~(a&b)
    assign out = ~(a & b) & (a | b); 
endmodule