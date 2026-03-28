1)	Decimal – 255.375
Binary – 11111111.011
Octal – 377.3
Hexadecimal – FF.6

2)	Decimal – 53.625

3)	Yes. Since 22n is always of the form 3k+1, and 22n+1 is always of the form 3m+2, a binary number with x ones at odd places and y even ones can be represented as 3t+x+2y. In the number 100111, there are 2 odd and 2 even ones, which is why it can be represented as 3t+2+4 = 3(t+6), and is divisible by 3.

4)	11101001

5)	F = (A+B)(A’+C)(B+C’)
Opening the first two brackets, we get:
(AA’ + A’B + AC + BC)(B+C’)
AA’ = 0 and if both B and C are 1, then either A’B or AC will be 1, making the term BC redundant:
(A’B+AC)(B+C’) = (A’B+A’BC’+ABC+ACC’)
ACC’ = 0 and if A’BC’ = 1, A’B = 1 as well, making the term A’BC’ redundant:
(A’B+ABC) = B(A’ + AC)
If A = 0 and B = 1, F = 1. If A = 1, then C must be 1. This means we can change the term AC to just A without changing the logic of the statement, since when A = 1, AC = A, and when A = 0, F is always 1.
So, F = B(A’+C)

Therefore, F is 1 when B is 1 and either both A and C are 1 or A is 0.
6)	F(A,B,C) = C’
