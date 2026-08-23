; Echo: read one character from the keyboard, print it to the monitor
.ORIG x3000
INPOLL  LDI     R1, KBSR_ADDR   ; wait for a new character
        BRzp    INPOLL
        LDI     R0, KBDR_ADDR   ; R0 <- ASCII of the key pressed
OUTPOLL LDI     R1, DSR_ADDR    ; wait for the display to be ready
        BRzp    OUTPOLL
        STI     R0, DDR_ADDR    ; echo the character
        HALT                    ; (loop back to INPOLL to echo forever)
KBSR_ADDR   .FILL   xFE00
KBDR_ADDR   .FILL   xFE02
DSR_ADDR    .FILL   xFE04
DDR_ADDR    .FILL   xFE06
.END
