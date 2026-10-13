; RunningSum(n) in LC-3: result = RunningSum(3)
; Frame (from R5): fn R5+0 | CFP R5+1 | RA R5+2 | RV R5+3 | n R5+4
.ORIG x3000
MAIN    LD   R6, USER_STACK   ; R6: stack pointer
        ADD  R5, R6, #-1      ; R5: frame pointer
        ADD  R6, R6, #-1      ; main's local: result
; ---- caller set-up: push the argument ----
        AND  R0, R0, #0
        ADD  R0, R0, #3
        ADD  R6, R6, #-1
        STR  R0, R6, #0       ; push 3
        JSR  RUNSUM
; ---- caller tear-down ----
        LDR  R0, R6, #0       ; R0 <- return value
        STR  R0, R5, #0       ; result = RunningSum(3)
        ADD  R6, R6, #2       ; pop RV and argument
        HALT
; ==== int RunningSum(int n) ====
; ---- callee set-up ----
RUNSUM  ADD  R6, R6, #-1      ; return-value slot
        ADD  R6, R6, #-1
        STR  R7, R6, #0       ; push return address
        ADD  R6, R6, #-1
        STR  R5, R6, #0       ; push caller's R5
        ADD  R5, R6, #-1      ; R5 -> first local (fn)
        ADD  R6, R6, #-1      ; local: fn
; ---- if (n == 1) ----
        LDR  R1, R5, #4       ; R1 <- n
        ADD  R2, R1, #-1      ; R2 <- n - 1
        BRz  BASE             ; n == 1
; ---- recursive case ----
        ADD  R6, R6, #-1
        STR  R2, R6, #0       ; push n - 1
        JSR  RUNSUM           ; RunningSum(n - 1)
        LDR  R2, R6, #0       ; R2 <- its return value
        ADD  R6, R6, #2       ; pop RV and argument
        LDR  R1, R5, #4       ; n again: R1 was changed
        ADD  R1, R1, R2       ; n + RunningSum(n - 1)
        STR  R1, R5, #0       ; fn = the sum
        BR   RETURN
; ---- base case ----
BASE    AND  R1, R1, #0
        ADD  R1, R1, #1
        STR  R1, R5, #0       ; fn = 1
; ---- return fn ----
RETURN  LDR  R1, R5, #0       ; R1 <- fn
        STR  R1, R5, #3       ; return value <- fn
; ---- callee tear-down ----
        ADD  R6, R5, #1       ; pop the local
        LDR  R5, R6, #0       ; restore caller's R5
        ADD  R6, R6, #1
        LDR  R7, R6, #0       ; restore return address
        ADD  R6, R6, #1       ; R6 -> return value
        RET
USER_STACK .FILL xFDFF
.END
