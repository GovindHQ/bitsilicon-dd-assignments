`timescale 100ps/1ps
module stopwatch_tb;

  reg clk, rst_n, start, stop, reset;
  wire [5:0] seconds;
  wire [7:0] minutes;
  wire [1:0] status;

  stopwatch_top watch1 (
        .clk(clk),
        .rst_n(rst_n),
        .start(start),
        .stop(stop),
        .reset(reset),
        .minutes(minutes),
        .seconds(seconds),
        .status(status)
  );

  initial 
  begin
    clk = 1'b0;
    forever #2 clk = ~clk;
  end

  initial 
  begin
    rst_n = 1'b0;
    #4 rst_n = 1'b1;  
  end

  initial 
  begin
    start = 1'b0;
    stop  = 1'b0;
    reset = 1'b0;
  end

  initial 
  begin
    #7 start = 1'b1;
    #4 start = 1'b0;
  end

  initial 
  begin  
    #14 stop = 1'b1;
    #4 stop = 1'b0;
  end

  initial 
  begin
    #22 start = 1'b1;
    #4 start = 1'b0;
  end
  
  initial 
  begin
    #300 reset = 1'b1;
    #4 reset = 1'b0;
  end
  
  initial
  begin
    #312 start = 1'b1;
    #4 start = 1'b0;
  end


  initial begin
    $monitor("T=%0t | STATE=%b | TIME=%02d:%02d",
              $time, status, minutes, seconds);
  end
endmodule
