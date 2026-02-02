module majority_voter (
    input a,
    input b,
    input c,
    output f
);

    //assigns 1 if & of any two inputs are 1
    assign f = (a & b) | (b & c) | (a & c);

endmodule