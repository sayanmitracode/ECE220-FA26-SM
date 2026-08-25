; Print a string with PUTS
.ORIG x3000
        LEA  R0, MSG      ; R0 <- address of MSG
        PUTS              ; TRAP x22: print string
        HALT
MSG     .STRINGZ "Hello, World!"
.END
