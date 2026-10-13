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
; ---- set-up: RV slot, return addr, caller's R5 ----
RUNSUM






; set R5 to the first local; make room for fn



; ---- if (n == 1) go to BASE ----



; ---- recursive case ----
; caller set-up: push n - 1, then JSR


; caller tear-down: get RV, pop RV and arg



; fn = n + RunningSum(n-1); go to RETURN




; ---- base case: fn = 1 ----
BASE



; ---- RETURN: copy fn to the RV slot ----
RETURN


; ---- tear-down: pop fn, R5, R7; RET ----






USER_STACK .FILL xFDFF
.END
