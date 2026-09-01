; PUSH: push R0 onto the stack
; OUT: R5 = 0 success, 1 overflow
.ORIG x3000
        AND  R0, R0, #0
        ADD  R0, R0, #7   ; value to push
        JSR  PUSH
        HALT
; ---- PUSH ----
PUSH    ST   R3, P_SAVER3
        ST   R6, P_SAVER6
        AND  R5, R5, #0   ; assume success
        LD   R3, STACK_END
        LD   R6, STACK_TOP
        NOT  R3, R3       ; R3 = -END
        ADD  R3, R3, #1
        ADD  R3, R6, R3   ; TOP - END
        BRz  P_OVER       ; full -> fail
        ADD  R6, R6, #-1  ; grow downward
        STR  R0, R6, #0   ; store the value
        ST   R6, STACK_TOP
        BR   P_DONE
P_OVER  ADD  R5, R5, #1   ; R5 = 1: overflow
P_DONE  LD   R3, P_SAVER3
        LD   R6, P_SAVER6
        RET
STACK_START .FILL x4000
STACK_END   .FILL x3FF0
STACK_TOP   .FILL x4000   ; empty: TOP = START
P_SAVER3    .BLKW #1
P_SAVER6    .BLKW #1
.END
