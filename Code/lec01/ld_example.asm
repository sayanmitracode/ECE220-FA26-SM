; LC-3 review: LD, LDI, LDR, LEA
.ORIG x3000
    LD   R6, LABEL    ; R6 <- M[LABEL]
    LDI  R6, LABEL    ; R6 <- M[M[LABEL]]
    LDR  R2, R6, #1   ; R2 <- M[R6 + 1]
    LEA  R2, LABEL    ; R2 <- addr of LABEL
LABEL   .FILL x5001
.END
