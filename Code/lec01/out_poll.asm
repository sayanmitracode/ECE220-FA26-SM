; Write one character to the monitor by polling DSR/DDR
.ORIG x3000
        LD      R0, CHAR        ; character to display
POLL    LDI     R1, DSR_ADDR    ; R1 <- DSR; ready bit is DSR[15]
        BRzp    POLL            ; display busy (DSR[15]=0) -> keep polling
        STI     R0, DDR_ADDR    ; DDR <- R0: character appears on screen
        HALT
CHAR        .FILL   x0041       ; 'A'
DSR_ADDR    .FILL   xFE04
DDR_ADDR    .FILL   xFE06
.END
