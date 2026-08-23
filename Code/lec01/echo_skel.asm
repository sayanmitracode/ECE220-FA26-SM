.ORIG x3000
; poll the keyboard: wait for a new character

; read the character from KBDR into R0

; poll the display: wait until it is ready

; write the character from R0 to DDR

        HALT
KBSR_ADDR   .FILL   xFE00
KBDR_ADDR   .FILL   xFE02
DSR_ADDR    .FILL   xFE04
DDR_ADDR    .FILL   xFE06
.END
