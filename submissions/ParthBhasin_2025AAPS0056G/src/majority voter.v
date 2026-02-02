// Part C: Majority Voter
// Logic: Output is 1 if at least two inputs (a, b, c) are high.
module majority_voter (
    input wire a,
    input wire b,
    input wire c,
    output wire y
);

    // The logic checks every pair combination.
    // If any pair is (1,1), the output becomes 1.
    assign y = (a & b) | (b & c) | (a & c);

endmodule