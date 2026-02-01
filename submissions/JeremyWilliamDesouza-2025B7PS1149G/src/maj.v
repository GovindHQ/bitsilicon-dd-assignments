// PARTC. Majority Voter (2-out-of-3 Logic)
// Logic: Output is high if at least TWO inputs are high.
module majority_voter(
    input a,
    input b,
    input c,
    output out);
    
    // Checks all pair combinations: (A&B), (A&C), or (B&C)
    assign out = (a & b) | (a & c) | (b & c); 
endmodule
  