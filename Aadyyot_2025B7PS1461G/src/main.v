//PART B
//a 2 input AND gate
module and_gate(
    input a,
    input b,
    output y
);
assign y = a & b;
endmodule

//Modifying the module to behave like an OR gate using assign statements.
module or_gate(
    input a,
    input b,
    output y
);
assign y = a | b;
endmodule

// a 2 input XOR gate 
module xor_gate(
    input a,
    input b,
    output y
);
assign y = a ^ b;
endmodule

//PART C
module majority_voter(
    input a,
    input b,
    input c,
    output y // Output of the majority voter
);

 // If any two inputs are 1, at least one of the above terms is true.
 // The OR (|) combines these conditions to produce the final output.
assign y = (a & b) | (b & c) | (a & c);
endmodule

