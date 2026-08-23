; Read one character from the keyboard by polling KBSR/KBDR
.ORIG x3000
POLL    LDI     R1, KBSR_ADDR   ; R1 <- KBSR; ready bit is KBSR[15]
        BRzp    POLL            ; not ready (KBSR[15]=0) -> keep polling
        LDI     R0, KBDR_ADDR   ; R0 <- KBDR: ASCII of the key pressed
        HALT
KBSR_ADDR   .FILL   xFE00
KBDR_ADDR   .FILL   xFE02
.END
