module majority_voter(
  input a,
  input b,
  input c,
  output out);
  assign out=(a&b)|(a&c)|(b&c);
  endmodule