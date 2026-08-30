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
MULT


; set product to 0, counter to R1


; loop: add R0 into product, count down



MDONE

; return to the caller (which instruction?)

SAVER3  .FILL x0000
RES1    .FILL x0000
RES2    .FILL x0000
.END
