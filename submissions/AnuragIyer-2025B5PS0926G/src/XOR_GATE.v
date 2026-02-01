module xor_gate( // Created a XOR Gate module
  input a,
  input b,
  output out);
  assign out=~(a&b)&(a|b);
endmodule 

