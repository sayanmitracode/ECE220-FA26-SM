; POP: pop the top of the stack into R0
; OUT: R5 = 0 success, 1 underflow
.ORIG x3000
        JSR  POP
        HALT
; ---- POP ----
POP     ST   R3, Q_SAVER3
        ST   R6, Q_SAVER6
        AND  R5, R5, #0   ; assume success
        LD   R3, STACK_START
        LD   R6, STACK_TOP
        NOT  R3, R3       ; R3 = -START
        ADD  R3, R3, #1
        ADD  R3, R6, R3   ; TOP - START
        BRz  Q_UNDER      ; empty -> fail
        LDR  R0, R6, #0   ; R0 <- top value
        ADD  R6, R6, #1   ; shrink the stack
        ST   R6, STACK_TOP
        BR   Q_DONE
Q_UNDER ADD  R5, R5, #1   ; R5 = 1: underflow
Q_DONE  LD   R3, Q_SAVER3
        LD   R6, Q_SAVER6
        RET
STACK_START .FILL x4000
STACK_END   .FILL x3FF0
STACK_TOP   .FILL x4000   ; empty: TOP = START
Q_SAVER3    .BLKW #1
Q_SAVER6    .BLKW #1
.END
