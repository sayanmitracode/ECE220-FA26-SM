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
; ---- callee set-up ----
PRINT_LIST
        ADD  R6, R6, #-1      ; return-value slot
        ADD  R6, R6, #-1
        STR  R7, R6, #0       ; push return address
        ADD  R6, R6, #-1
        STR  R5, R6, #0       ; push caller's R5
        ADD  R5, R6, #-1      ; R5 -> first local (none)
; ---- if (head == NULL) return; ----
        LDR  R1, R5, #4       ; R1 <- head
        BRz  DONE             ; head == NULL
; ---- printf("%c", head->data); ----
        LDR  R0, R1, #0       ; R0 <- head->data
        OUT                   ; R7 changes: RA is safe
; ---- print_list(head->next); ----
        LDR  R1, R1, #1       ; R1 <- head->next
        ADD  R6, R6, #-1
        STR  R1, R6, #0       ; push head->next
        JSR  PRINT_LIST
        ADD  R6, R6, #2       ; pop RV and argument
; ---- callee tear-down ----
DONE    ADD  R6, R5, #1       ; pop the locals (none)
        LDR  R5, R6, #0       ; restore caller's R5
        ADD  R6, R6, #1
        LDR  R7, R6, #0       ; restore return address
        ADD  R6, R6, #1       ; R6 -> return value
        RET
.END
