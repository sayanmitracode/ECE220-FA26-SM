; Stack calculator pieces: ADD on a stack
; Stack: PUSH/POP with R5 = 0 ok, 1 fail
.ORIG x3000
; driver: push 3, push 4, ADD, result on top
        AND  R0, R0, #0
        ADD  R0, R0, #3
        JSR  PUSH
        AND  R0, R0, #0
        ADD  R0, R0, #4
        JSR  PUSH
        JSR  ADDSUB
        HALT
; ---- ADDSUB: pop two, add, push sum ----
; OUT: R5 = 0 success, 1 failure
ADDSUB  ST   R1, A_SAVER1
        ST   R2, A_SAVER2
        ST   R7, A_SAVER7   ; we call subroutines!
        JSR  POP            ; R0 <- first
        ADD  R5, R5, #0
        BRp  A_EXIT         ; underflow: fail
        ADD  R1, R0, #0     ; R1 = first
        JSR  POP            ; R0 <- second
        ADD  R5, R5, #0
        BRp  A_PUT1         ; put first back
        ADD  R2, R0, #0     ; R2 = second
        ADD  R0, R1, R2     ; sum
        JSR  CHECK_RANGE
        ADD  R5, R5, #0
        BRp  A_PUT2         ; put both back
        JSR  PUSH           ; push the sum
        BR   A_EXIT
A_PUT2  ADD  R0, R2, #0     ; second first...
        JSR  PUSH
A_PUT1  ADD  R0, R1, #0     ; ...then first
        JSR  PUSH
        AND  R5, R5, #0
        ADD  R5, R5, #1     ; report failure
A_EXIT  LD   R1, A_SAVER1
        LD   R2, A_SAVER2
        LD   R7, A_SAVER7
        RET
; ---- POP: R0 <- top; R5 = 0 ok, 1 empty ----
POP     ST   R3, Q_SAVER3
        ST   R6, Q_SAVER6
        AND  R5, R5, #0
        LD   R3, STACK_START
        LD   R6, STACK_TOP
        NOT  R3, R3
        ADD  R3, R3, #1     ; -START
        ADD  R3, R6, R3     ; TOP - START
        BRz  Q_UNDER        ; empty -> fail
        LDR  R0, R6, #0     ; read the top
        ADD  R6, R6, #1     ; shrink
        ST   R6, STACK_TOP
        BR   Q_DONE
Q_UNDER ADD  R5, R5, #1
Q_DONE  LD   R3, Q_SAVER3
        LD   R6, Q_SAVER6
        RET
; ---- PUSH: push R0; R5 = 0 ok, 1 full ----
PUSH    ST   R3, P_SAVER3
        ST   R6, P_SAVER6
        AND  R5, R5, #0
        LD   R3, STACK_END
        LD   R6, STACK_TOP
        NOT  R3, R3
        ADD  R3, R3, #1     ; -END
        ADD  R3, R6, R3     ; TOP - END
        BRz  P_OVER         ; full -> fail
        ADD  R6, R6, #-1
        STR  R0, R6, #0
        ST   R6, STACK_TOP
        BR   P_DONE
P_OVER  ADD  R5, R5, #1
P_DONE  LD   R3, P_SAVER3
        LD   R6, P_SAVER6
        RET
; ---- CHECK_RANGE: R5 = 0 if -100 <= R0 <= 100 ----
CHECK_RANGE ST R1, C_SAVER1
        AND  R5, R5, #0
        LD   R1, NEG100
        ADD  R1, R0, R1     ; R0 - 100
        BRp  C_FAIL
        LD   R1, POS100
        ADD  R1, R0, R1     ; R0 + 100
        BRn  C_FAIL
        BR   C_DONE
C_FAIL  ADD  R5, R5, #1
C_DONE  LD   R1, C_SAVER1
        RET
STACK_START .FILL x4000
STACK_END   .FILL x3FF0
STACK_TOP   .FILL x4000
NEG100      .FILL #-100
POS100      .FILL #100
A_SAVER1    .BLKW #1
A_SAVER2    .BLKW #1
A_SAVER7    .BLKW #1
Q_SAVER3    .BLKW #1
Q_SAVER6    .BLKW #1
P_SAVER3    .BLKW #1
P_SAVER6    .BLKW #1
C_SAVER1    .BLKW #1
.END
