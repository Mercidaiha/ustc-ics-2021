.ORIG x3000
ADD R1,R1, #1
ADD R2,R2, #2
JSR JUDGE
HALT
JUDGE ADD R4,R2, #-1
      ADD R5,R2, #0
AGAIN ADD R5,R5, R2
      ADD R4,R4, #-1
      BRp AGAIN
      NOT R5,R5
      ADD R5,R5, #1
      ADD R5,R0,R5
      BRn RETURN
      ADD R3,R0, #0
      ADD R6,R2, #0
      NOT R6,R6
      ADD R6,R6, #1
AGAIN2 ADD R3,R3,R6
       BRz TRUE
       BRp AGAIN2
       ADD R2,R2, #1
       BRnzp JUDGE
RETURN RET
TRUE AND R1,R1, #0
     RET
.END