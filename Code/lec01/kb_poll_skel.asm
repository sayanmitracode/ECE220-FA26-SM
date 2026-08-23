.ORIG x3000
; set up a loop to check the ready bit in KBSR

; branch to the beginning if no keyboard input

; otherwise, load the data from KBDR into R0

        HALT
KBSR_ADDR   .FILL   xFE00
KBDR_ADDR   .FILL   xFE02
.END
