; Would this program work?
.ORIG x3000
        AND  R1, R1, #0
        AND  R2, R2, #0
        ADD  R1, R1, #5   ; R1 = 5
        ADD  R2, R2, #2   ; R2 = 2
        JSR  SUBTR        ; R0 <- R1 - R2
        ADD  R6, R0, #0   ; copy result
        HALT
; SUBTR: R0 <- R1 - R2
SUBTR   ADD  R3, R2, #0
        JSR  NEGATE       ; R3 = -R2
        ADD  R0, R1, R3   ; R0 = R1 - R2
        RET
; NEGATE: R3 <- -R3
NEGATE  NOT  R3, R3
        ADD  R3, R3, #1
        RET
.END
