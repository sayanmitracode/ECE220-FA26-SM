; BALCK: is the paren string at PSTR balanced?
; OUT: R5 = 0 balanced, nonzero not  (0 = success)
; '(' -> PUSH.  ')' -> POP; underflow = unbalanced.
; At the end: balanced iff the stack is empty.
.ORIG x3000
        JSR  BALCK
        HALT
PSTR    .STRINGZ "(()())"
NEG_OPEN  .FILL xFFD8       ; -'(' = -x28
NEG_START .FILL xC000       ; -x4000
; ---- BALCK ----
BALCK   ST   R7, B_SAVER7   ; we JSR below!
        LEA  R1, PSTR
B_LOOP  LDR  R2, R1, #0     ; next char
        BRz  B_END          ; NUL: string done
; is it '(' ?  if not -> B_POP   (hint: NEG_OPEN)



        ADD  R0, R2, #0     ; '(' : push it
        JSR  PUSH
        BR   B_NEXT
B_POP   ; ')' : pop --- POP's underflow R5 is our answer!



B_NEXT  ADD  R1, R1, #1
        BR   B_LOOP
B_END   ; balanced iff the stack is empty (hint: NEG_START)



B_DONE  LD   R7, B_SAVER7
        RET
; ---- PUSH/POP from Lecture 3 ----
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
POP     ST   R3, Q_SAVER3
        ST   R6, Q_SAVER6
        AND  R5, R5, #0
        LD   R3, STACK_START
        LD   R6, STACK_TOP
        NOT  R3, R3
        ADD  R3, R3, #1     ; -START
        ADD  R3, R6, R3     ; TOP - START
        BRz  Q_UNDER        ; empty -> fail
        LDR  R0, R6, #0
        ADD  R6, R6, #1
        ST   R6, STACK_TOP
        BR   Q_DONE
Q_UNDER ADD  R5, R5, #1
Q_DONE  LD   R3, Q_SAVER3
        LD   R6, Q_SAVER6
        RET
STACK_START .FILL x4000
STACK_END   .FILL x3FF0
STACK_TOP   .FILL x4000
P_SAVER3    .BLKW #1
P_SAVER6    .BLKW #1
Q_SAVER3    .BLKW #1
Q_SAVER6    .BLKW #1
B_SAVER7    .BLKW #1
.END
