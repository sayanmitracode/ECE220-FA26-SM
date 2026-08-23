.ORIG x3000
        LD      R0, CHAR        ; character to display

; set up a loop to check the ready bit in DSR

; branch back to the beginning if the display is not ready

; otherwise, store the data from R0 into DDR

        HALT
CHAR        .FILL   x0041       ; 'A'
DSR_ADDR    .FILL   xFE04
DDR_ADDR    .FILL   xFE06
.END
