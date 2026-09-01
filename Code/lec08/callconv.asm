; The C calling convention in LC-3: answer = Fact(number)
; Frame (from R5): locals R5, R5-1, ... | CFP R5+1 | RA R5+2 |
;                  RV R5+3 | args R5+4, R5+5, ...
.ORIG x3000
        LD   R6, USER_STACK   ; R6: stack pointer
        ADD  R5, R6, #-1      ; R5: frame pointer
        ADD  R6, R6, #-2      ; main's locals: number, answer
        AND  R0, R0, #0
        ADD  R0, R0, #4
        STR  R0, R5, #0       ; number = 4
; ---- 1. caller setup: push the argument ----
        LDR  R0, R5, #0       ; R0 <- number
        ADD  R6, R6, #-1
        STR  R0, R6, #0       ; push it
; ---- 2. pass control to the callee ----
        JSR  FACT
; ---- 7. caller teardown ----
        LDR  R0, R6, #0       ; return value is on top
        STR  R0, R5, #-1      ; answer = Fact(number)
        ADD  R6, R6, #2       ; pop RV + argument
        HALT
; ==== int Fact(int n) ====
; ---- 3. callee setup ----
FACT    ADD  R6, R6, #-1      ; reserve return-value slot
        ADD  R6, R6, #-1
        STR  R7, R6, #0       ; push return address
        ADD  R6, R6, #-1
        STR  R5, R6, #0       ; push caller's frame ptr
        ADD  R5, R6, #-1      ; R5 -> first local
        ADD  R6, R6, #-2      ; locals: i, result
; ---- 4. execute (loop in registers for brevity) ----
        LDR  R1, R5, #4       ; R1 <- n  (the argument!)
        AND  R0, R0, #0
        ADD  R0, R0, #1       ; result = 1
FLOOP   ADD  R1, R1, #0
        BRz  FDONE            ; n reached 0
        AND  R2, R2, #0       ; result = result * n
        ADD  R3, R1, #0       ;   (repeated addition)
FMUL    BRz  FMULD
        ADD  R2, R2, R0
        ADD  R3, R3, #-1
        BR   FMUL
FMULD   ADD  R0, R2, #0
        ADD  R1, R1, #-1
        BR   FLOOP
FDONE   STR  R0, R5, #-1      ; result (local, R5-1)
; ---- 5. callee teardown ----
        LDR  R0, R5, #-1      ; copy result...
        STR  R0, R5, #3       ; ...into the RV slot
        ADD  R6, R5, #1       ; pop ALL locals at once
        LDR  R5, R6, #0       ; restore caller's R5
        ADD  R6, R6, #1
        LDR  R7, R6, #0       ; restore return address
        ADD  R6, R6, #1       ; R6 -> return value
; ---- 6. return to the caller ----
        RET
USER_STACK .FILL xFDFF
.END
