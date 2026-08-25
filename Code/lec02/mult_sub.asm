; Multiply as a subroutine: R2 <- R0 * R1
.ORIG x3000
        AND  R0, R0, #0
        ADD  R0, R0, #5   ; R0 = 5
        AND  R1, R1, #0
        ADD  R1, R1, #4   ; R1 = 4
        JSR  MULT         ; R2 <- 5*4
        ST   R2, RES1
        AND  R0, R0, #0
        ADD  R0, R0, #6   ; R0 = 6
        AND  R1, R1, #0
        ADD  R1, R1, #3   ; R1 = 3
        JSR  MULT         ; R2 <- 6*3
        ST   R2, RES2
        HALT
; ---- MULT: R2 <- R0 * R1 (R1 >= 0) ----
MULT    ST   R3, SAVER3   ; callee-save R3
        AND  R2, R2, #0   ; product = 0
        ADD  R3, R1, #0   ; counter = R1
MLOOP   BRz  MDONE        ; counter zero?
        ADD  R2, R2, R0   ; product += R0
        ADD  R3, R3, #-1  ; count down
        BR   MLOOP
MDONE   LD   R3, SAVER3   ; restore R3
        RET               ; PC <- R7
SAVER3  .FILL x0000
RES1    .FILL x0000
RES2    .FILL x0000
.END
