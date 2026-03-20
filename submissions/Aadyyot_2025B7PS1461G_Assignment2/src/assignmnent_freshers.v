//assign statements

module alarm_system (
    input  wire [3:0] sensor_value,
    input  wire [3:0] threshold,
    input  wire       alarm_enable,
    output wire       alarm_led
);

assign alarm_led = alarm_enable && (sensor_value > threshold);

endmodule


//always @(*) block

 /* module alarm_system (
    input  wire [3:0] sensor_value,
    input  wire [3:0] threshold,
    input  wire       alarm_enable,
    output reg        alarm_led
);

always @(*) begin
    if (alarm_enable && (sensor_value > threshold))
        alarm_led = 1'b1;
    else
        alarm_led = 1'b0;
end

endmodule  */


// testbench

module tb_alarm_system;

reg  [3:0] sensor_value;
reg  [3:0] threshold;
reg        alarm_enable;
wire       alarm_led;

alarm_system uut (
    .sensor_value(sensor_value),
    .threshold(threshold),
    .alarm_enable(alarm_enable),
    .alarm_led(alarm_led)
);

initial begin
    // Initial values
    sensor_value = 4'd0;
    threshold    = 4'd5;
    alarm_enable = 1'b0;

    #10 alarm_enable = 1'b1;   // Enable alarm
    #10 sensor_value = 4'd4;   // Below threshold → OFF
    #10 sensor_value = 4'd6;   // Above threshold → ON
    #10 alarm_enable = 1'b0;   // Disable alarm → OFF
    #10 sensor_value = 4'd9;   // Still OFF due to disable
    #10 $finish;
end

endmodule
