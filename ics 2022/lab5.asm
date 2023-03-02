; Unfortunately we have not YET installed Windows or Linux on the LC-3,
; so we are going to have to write some operating system code to enable
; keyboard interrupts. The OS code does three things:
;
;    (1) Initializes the interrupt vector table with the starting
;        address of the interrupt service routine. The keyboard
;        interrupt vector is x80 and the interrupt vector table begins
;        at memory location x0100. The keyboard interrupt service routine
;        begins at x1000. Therefore, we must initialize memory location
;        x0180 with the value x1000.
;    (2) Sets bit 14 of the KBSR to enable interrupts.
;    (3) Pushes a PSR and PC to the system stack so that it can jump
;        to the user program at x3000 using an RTI instruction.

        .ORIG x800
        ; (1) Initialize interrupt vector table.
        LD R0, VEC
        LD R1, ISR
        STR R1, R0, #0

        ; (2) Set bit 14 of KBSR.
        LDI R0, KBSR
        LD R1, MASK
        NOT R1, R1
        AND R0, R0, R1
        NOT R1, R1
        ADD R0, R0, R1
        STI R0, KBSR

        ; (3) Set up system stack to enter user space.
        LD R0, PSR
        ADD R6, R6, #-1
        STR R0, R6, #0
        LD R0, PC
        ADD R6, R6, #-1
        STR R0, R6, #0
        ; Enter user space.
        RTI
        
VEC     .FILL x0180
ISR     .FILL x1000
KBSR    .FILL xFE00
MASK    .FILL x4000
PSR     .FILL x8002
PC      .FILL x3000
        .END

        .ORIG x3000
        ; *** Begin user program code here ***
        
            ; code of delay
        LOOP    LEA R0, PRINT
                TRAP x22
                JSR DELAY
                LDI R0, HANOI2
                BRn LOOP
                
        ;initial R6 with USP
        LD R6, USP
        JSR HANOI
        
        LEA R0, RESULT1
        TRAP x22
        JSR DEMICAL
        LEA R0, RESULT2
        TRAP x22
        HALT
        
        ;result to demical ASCII
        DEMICAL 
                LD R2, ASCIIOFFSET
                LD R3, NEG100
                ADD R1, R1, R3
                BRn BEGIN10
        LOOP100 
                ADD R2, R2, #1
                ADD R1, R1, R3
                BRn END100
                BRnzp LOOP100
        END100  ADD R0, R2, #0
                TRAP x21
                BRnzp ALL
        BEGIN10
            LD R4, POS100
            ADD R1, R1, R4
            LD R2, ASCIIOFFSET
            ADD R1, R1, #-10
            BRn BEGIN1
        LOOP10 
            ADD R2, R2, #1
            ADD R1, R1, #-10
            BRn END10
            BRnzp LOOP10
        END10  ADD R0, R2, #0
                TRAP x21
        BEGIN1  LD R2, ASCIIOFFSET
                ADD R1, R1, #10
        LOOP1   
            ADD R1, R1, #-1
            BRn BEGIN0
            ADD R2, R2, #1
            BRnzp LOOP1
        BEGIN0  ADD R0, R2, #0
                TRAP x21
        
        RET
        ALL LD R2, ASCIIOFFSET
            LD R4, POS100
            ADD R1, R1, R4
        LOOPALL 
                ADD R1, R1, #-10
                BRn PUT10
                ADD R2, R2, #1
                BRnzp LOOPALL
        PUT10   ADD R0, R2, #0
                TRAP x21
        BEGIN   LD R2, ASCIIOFFSET
                ADD R1, R1, #10
        LOOPBEGIN
                    ADD R1, R1, #-1
                    BRn PUT0
                    ADD R2, R2, #1
                    BRnzp LOOPBEGIN
        PUT0    ADD R0, R2, #0
                TRAP x21
        
        RET
        ASCIIOFFSET .FILL x0030
        NEG100 .FILL #-100
        POS100 .FILL #100
        
        
        ;recursive function
        HANOI   ADD R6, R6, #-1
                STR R7, R6, #0
                ADD R6, R6, #-1
                STR R0, R6, #0  ;the value of n
                ;check
                ADD R2, R0, #0
                BRnp SKIP
                ADD R1, R0, #0
                BRnzp DONE
        
        ;N not 0
        SKIP    ADD R0, R0, #-1
                JSR HANOI      ;R1 = HANOI(n-1)
                ADD R1, R1, R1 ;R1 = 2*R1
                ADD R1, R1, #1 ;R1 = R1+1
        
        DONE    LDR R0, R6, #0
                ADD R6, R6, #1
                LDR R7, R6, #0
                ADD R6, R6, #1
                RET
                
        DELAY   ST R1, SaveR1
                LD R1, COUNT
        REP     ADD R1, R1, #-1
                BRp REP
                LD R1, SaveR1
                RET
        
        SaveR1 .FILL x0000
        COUNT .FILL x4500
        PRINT .STRINGZ "PB20151793 "
        HANOI2 .FILL x3FFF
        USP .FILL xFDFF
        RESULT1 .STRINGZ "Tower of honoi needs "
        RESULT2 .STRINGZ " moves"
        ; *** End user program code here ***
        .END

        .ORIG x3FFF
        ; *** Begin honoi data here ***
HONOI_N .FILL xFFFF
        ; *** End honoi data here ***
        .END

        .ORIG x1000
        ; *** Begin interrupt service routine code here ***
        ST R1, SaveR11
        ST R0, SaveR10
        ST R7, SaveR17
        ST R6, SaveR16
        
        LD R0, LINE_FEED
        TRAP x21
        LD R1, VALID1
        LDI R0, KBDR
        ADD R1, R1, R0
        BRn NO
        NEXT    LD R1, VALID2
                LDI R0, KBDR
                ADD R1, R1, R0
                BRp NO
        YES LDI R0, KBDR
            TRAP x21
            LD R1, VALID1
            ADD R0, R0, R1
            STI R0, HANOI1
            LEA R0, IS
            TRAP x22
            BRnzp STORE

        NO  TRAP x21
            LEA R0, ISNT
            TRAP x22
        STORE
        LD R0, LINE_FEED
        TRAP x21
        LD R1, SaveR11
        LD R0, SaveR10
        LD R7, SaveR17
        LD R6, SaveR16
        RTI
        VALID1 .FILL #-48
        VALID2 .FILL #-57
        LINE_FEED .FILL x000A
        KBDR .FILL xFE02
        IS .STRINGZ " is a decimal digit."
        ISNT .STRINGZ " is not a decimal digit."
        SaveR10 .FILL x0000
        SaveR17 .FILL x0000
        SaveR16 .FILL x0000
        SaveR11 .FILL x0000
        HANOI1 .FILL x3FFF
        ; *** End interrupt service routine code here ***
        .END