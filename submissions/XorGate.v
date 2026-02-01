module Xor(input in1, input in2, output out);
assign out = (in1 + in2 == 1) ? 1'b1 : 1'b0;
/*
 1'b1 means we are assigning 1 bit to store the value and 'b is format of specifying the number 
 and 1 is the binary represntation
*/
/* we can also use the SOP 
 
	A B XOR

	0 0 0
	1 0 1
	0 1 1
	1 1 1
	assign out = A'B + B'A
	
 */
endmodule