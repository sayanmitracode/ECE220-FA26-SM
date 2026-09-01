; POP: pop the top of the stack into R0
; OUT: R5 = 0 success, 1 underflow
.ORIG x3000
        JSR  POP
        HALT
; ---- POP ----
POP     ST   R3, Q_SAVER3
        ST   R6, Q_SAVER6
; init R5 = 0 (assume success)


; R3 <- STACK_START, R6 <- STACK_TOP


; empty when TOP - START == 0 -> Q_UNDER



; else: R0 <- top value, increment TOP, save TOP



        BR   Q_DONE
Q_UNDER ; set R5 = 1 (underflow)


Q_DONE  LD   R3, Q_SAVER3
        LD   R6, Q_SAVER6
        RET
STACK_START .FILL x4000
STACK_END   .FILL x3FF0
STACK_TOP   .FILL x4000   ; empty: TOP = START
Q_SAVER3    .BLKW #1
Q_SAVER6    .BLKW #1
.END
