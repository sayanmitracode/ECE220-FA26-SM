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
; init R5 = 0 (assume success)


; R3 <- STACK_END, R6 <- STACK_TOP


; full when TOP - END == 0 -> P_OVER



; else: decrement TOP, store R0, save TOP



        BR   P_DONE
P_OVER  ; set R5 = 1 (overflow)


P_DONE  LD   R3, P_SAVER3
        LD   R6, P_SAVER6
        RET
STACK_START .FILL x4000
STACK_END   .FILL x3FF0
STACK_TOP   .FILL x4000   ; empty: TOP = START
P_SAVER3    .BLKW #1
P_SAVER6    .BLKW #1
.END
