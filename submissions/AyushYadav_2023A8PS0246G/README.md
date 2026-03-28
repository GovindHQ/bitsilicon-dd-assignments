## Approach

the seconds counter uses an adder to `add cnt` to the current value and then we add `-59` and use the MSB of result to check id the result is greater than or equal to 59 or not in which case an "overflow" signal is sent to output while the value of the register is reset to 0 in next cycle. Now i used an extra bit for the storage of seconds to keep the comparison logic. Here value of `cnt` is determined by weather the stopwatch is counting or not
- 1 if counting
- 0 if not

similar is the logic for minute counter just that in this the `cnt` is driven by overflow from seconds counter, here the minutes are allowed to roll over so the clock can count till `127:59 -> 00:00`

### NOTE

- I am still trying to learn the `verilator` part, so in that scenario i have taken help of chatGPT to write the code, verilog part is entirely written by me.
- The assignment wanted me to have 3 states `PAUSED`, `IDLE` and `RUNNING` but obviously `IDLE` and `PAUSED` were very similar - thus to reduce the complexity I combined the two, the status still shows all 3 states
    - `RUNNING` state is as stated in the question
    - the other state in the system is `IDLE` and in my code the stopwatch will be idle when not counting no mattern weather `reset` is clicked or not, but in `status` output it will show `IDLE` when `seconds + minutes = 0` otherwise `PAUSED`
