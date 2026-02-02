module xor_gate (
    input wire a,
    input wire b,
    output wire y
);

    // Logic: (NOT a AND b) OR (a AND NOT b)
    // This produces a 1 only when inputs are different
    assign y = (~a & b) | (a & ~b);

endmodule