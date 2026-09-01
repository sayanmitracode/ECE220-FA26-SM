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
; pop first operand; on failure (R5=1) -> A_EXIT

; save it in R1

; pop second; on failure -> A_PUT1

; save it in R2; compute the sum in R0

; check range; on failure -> A_PUT2

; push the sum; then BR to A_EXIT

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
; (POP, PUSH, CHECK_RANGE as in stack_add.asm)
.END
