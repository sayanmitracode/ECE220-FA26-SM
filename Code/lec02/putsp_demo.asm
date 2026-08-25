; PUTS: one char per word; PUTSP: two per word
.ORIG x3000
        LEA  R0, S1
        PUTS              ; prints abcd
        LEA  R0, S2
        PUTSP             ; also prints abcd
        HALT
S1      .STRINGZ "abcd"
S2      .FILL x6261       ; 'b''a' (low byte first)
        .FILL x6463       ; 'd''c'
        .FILL x0000       ; terminator
.END
