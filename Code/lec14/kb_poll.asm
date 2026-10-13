; Lecture 1: read one character by polling KBSR and KBDR
.ORIG x3000
POLL  LDI  R1, KBSR_ADDR  ; R1 <- KBSR
      BRzp POLL           ; not ready: wait
      LDI  R0, KBDR_ADDR  ; R0 <- KBDR
      HALT
KBSR_ADDR   .FILL   xFE00
KBDR_ADDR   .FILL   xFE02
.END
