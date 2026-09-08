; party.c, compiled to LC-3 by hand
; total -> TOTAL, a fixed word of memory
; the locals live together, at offsets from R5:
;   pizzas #0, each #-1, room #-2, mine #-3, enough #-4
;   inner pizzas #-5
.ORIG x3000
MAIN    LD   R5, LOCALS     ; base of the locals
; int pizzas = 3;  int each = 8;
        AND  R0, R0, #0
        ADD  R0, R0, #3
        STR  R0, R5, #0
        AND  R0, R0, #0
        ADD  R0, R0, #8
        STR  R0, R5, #-1
; char room = 'A';  ('A' is just x0041)
        LD   R0, CHA
        STR  R0, R5, #-2
; mine = pizzas * each ...
        LDR  R0, R5, #0     ; pizzas
        LDR  R1, R5, #-1    ; each
        JSR  MULT           ; R2 = R0 * R1
; ... + pizzas % 2;   (one AND does it!)


        STR  R2, R5, #-3    ; mine
; { int pizzas = 2;  total = total + pizzas * each; }
        AND  R0, R0, #0
        ADD  R0, R0, #2
        STR  R0, R5, #-5    ; the INNER pizzas
        LDR  R1, R5, #-1    ; each
        JSR  MULT           ; R2 = 2 * each
        LD   R0, TOTAL
        ADD  R0, R0, R2
        ST   R0, TOTAL
; total = total + mine;
        LD   R0, TOTAL
        LDR  R1, R5, #-3
        ADD  R0, R0, R1
        ST   R0, TOTAL
; enough = (total > TABLE);  (subtract, branch)




ENDONE  STR  R1, R5, #-4
; printf: a library call -- Thursday
        HALT
; ---- MULT: R2 <- R0 * R1, from Lecture 2 ----
MULT    ST   R3, SAVER3
        AND  R2, R2, #0     ; product = 0
        ADD  R3, R1, #0     ; counter = each
MLOOP   BRz  MDONE
        ADD  R2, R2, R0     ; product += pizzas
        ADD  R3, R3, #-1
        BR   MLOOP
MDONE   LD   R3, SAVER3
        RET
; ---- data ----
TOTAL   .FILL #0            ; int total = 0
CHA     .FILL x0041         ; 'A'
NEGTBL  .FILL #-30          ; -TABLE
SAVER3  .BLKW #1
LOCALS  .FILL x4000         ; room for the locals
.END
