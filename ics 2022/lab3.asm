.ORIG x3000
LDI R0,NUM
LD R1,DATA ; R1 is the pointer of the string
ADD R6, R6, #1; R6 store the length
ADD R0, R0, #-1; NUM--
BRNZ STORE
LOOP
LDR R3, R1, #0 ;
LDR R4, R1, #1
NOT R3, R3
ADD R3, R3, #1
ADD R3, R3, R4
BRNP NEQ
ADD R6, R6, #1
BRNZP NEXT
NEQ
ADD R5, R6, #0 ;store the last result
NOT R5, R5
ADD R5, R5, #1
ADD R5, R5, R2
BRZP NMAX
ADD R2, R6, #0
NMAX
AND R6, R6, #0
ADD R6, R6, #1
NEXT
ADD R1, R1, #1
ADD R0, R0, #-1
BRP LOOP
STORE
ADD R5, R6, #0 ;store the last result
NOT R5, R5
ADD R5, R5, #1
ADD R5, R5, R2
BRZP YES
ADD R2, R6, #0
YES
STI R2,RESULT
HALT
RESULT .FILL x3050
NUM .FILL x3100
DATA .FILL x3101
.END