module Majority(input in1, input in2, input in3, output out);
assign out = (in2&in1) | (in1&in3) | (in2&in3);
/* we can also use this expression: A.B + B.C + A.C
	where A,B,C are the inputs
	A B C Out
	1 0 0 0
	1 1 0 1
	1 0 1 1
	0 1 1 1
	0 1 0 0
	0 0 1 0
	1 1 1 1
	0 0 0 0
*/
endmodule

