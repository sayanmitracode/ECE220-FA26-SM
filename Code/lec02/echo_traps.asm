; Lecture 2: echo by TRAPs
.ORIG x3000
        GETC              ; TRAP x20: R0 <- key
        OUT               ; TRAP x21: screen <- R0
        HALT              ; TRAP x25
.END
