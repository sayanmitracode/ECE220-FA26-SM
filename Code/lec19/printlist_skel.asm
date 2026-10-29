; print_list(head) in LC-3: main calls print_list(x4004); load data.asm first
; Frame (from R5): (no locals) | CFP R5+1 | RA R5+2 | RV R5+3 | head R5+4
.ORIG x3000
MAIN    LD   R6, USER_STACK   ; R6: stack pointer
        ADD  R5, R6, #-1      ; R5: frame pointer
        ADD  R6, R6, #-1      ; main's local: head
        LD   R0, HEAD
        STR  R0, R5, #0       ; head = x4004
; ---- caller set-up: push the argument ----
        LDR  R0, R5, #0       ; R0 <- head
        ADD  R6, R6, #-1
        STR  R0, R6, #0       ; push head
        JSR  PRINT_LIST
; ---- caller tear-down ----
        ADD  R6, R6, #2       ; pop RV and argument
        HALT
HEAD       .FILL x4004
USER_STACK .FILL xFDFF
; ==== void print_list(node *head) ====
; ---- set-up: RV slot, return addr, caller's R5 ----
PRINT_LIST






; set R5: no locals, so nothing more to push


; ---- if (head == NULL) go to DONE ----



; ---- printf("%c", head->data): R0, OUT ----



; ---- print_list(head->next): push it, JSR ----




; caller tear-down: pop RV and arg


; ---- tear-down: pop locals, R5, R7; RET ----
DONE






.END
