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

; ---- 2. pass control to the callee ----

; ---- 7. caller teardown ----
; load the return value (where is it?)

; perform the assignment: answer = ...

; pop the return value and the argument

        HALT
; ==== int Fact(int n) ====
; ---- 3. callee setup ----
FACT ; reserve the return-value slot

; push the return address (which register?)

; push the caller's frame pointer

; set the new frame pointer; make room for locals

; ---- 4. execute (given in callconv.asm) ----
; ...
; ---- 5. callee teardown ----
; copy the result into the RV slot

; pop the locals (one instruction!)

; restore caller's R5, then R7

; ---- 6. return to the caller ----

USER_STACK .FILL xFDFF
.END
