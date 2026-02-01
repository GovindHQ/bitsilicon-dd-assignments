// 2. OR Gate Module
// Logic: Output is high if either 'a' OR 'b' (or both) are high.
module or_gate(
    input a,  //Input Signal A    
    input b,  //Input Signal B    
    output out
    );
    
    assign out = a | b; // Using the bitwise OR operator
endmodule