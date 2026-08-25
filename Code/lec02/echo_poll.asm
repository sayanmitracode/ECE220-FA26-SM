; Lecture 1: echo by polling
.ORIG x3000
POLL1   LDI  R1, KBSR_A   ; wait for a key
        BRzp POLL1
        LDI  R0, KBDR_A   ; read it
POLL2   LDI  R1, DSR_A    ; wait for screen
        BRzp POLL2
        STI  R0, DDR_A    ; write it
        HALT
KBSR_A  .FILL xFE00
KBDR_A  .FILL xFE02
DSR_A   .FILL xFE04
DDR_A   .FILL xFE06
.END
