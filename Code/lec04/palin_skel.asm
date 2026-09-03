; PALIN: is the string at STR a palindrome?
; OUT: R5 = 0 yes, 1 no  (0 = success)
; Push ALL the chars; popping returns the string
; reversed --- and a palindrome equals its reverse.
.ORIG x3000
        JSR  PALIN
        HALT
STR     .STRINGZ "madam"
; ---- PALIN ----
PALIN   ST   R7, PL_SAVER7  ; we JSR below!
; pass 1: push every char of STR (stop at the NUL)
PL_PUSH




; pass 2: rescan; each POP must equal the char
PL_CMP  LEA  R1, STR
PL_LOOP







PL_YES  AND  R5, R5, #0     ; R5 = 0: yes
        BR   PL_DONE
PL_NO   AND  R5, R5, #0
        ADD  R5, R5, #1     ; R5 = 1: no
PL_DONE LD   R7, PL_SAVER7
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
PL_SAVER7   .BLKW #1
.END
