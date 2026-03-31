module or_gate (
    input wire a,
    input wire b,
    output wire y
);

    // Using the pipe symbol for OR logic
    assign y = a | b;

endmodule