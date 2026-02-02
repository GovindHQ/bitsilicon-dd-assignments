module and_gate (
    input wire a,
    input wire b,
    output wire y
);

    // This "wires" the output to the AND logic of a and b
    assign y = a & b;

endmodule