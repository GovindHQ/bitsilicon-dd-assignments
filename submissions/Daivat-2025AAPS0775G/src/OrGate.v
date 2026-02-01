module OrGate(input in1, input in2, output out);
assign out = in1&(~in2) | (~in1)&in2 | in1&in2;

/*  
A B A|B
0 0 0
1 0 1
0 1 1
1 1 1
SOP = AB' + A'B + AB
	
*/ 

endmodule