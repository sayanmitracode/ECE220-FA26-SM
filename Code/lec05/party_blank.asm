; party.c, compiled to LC-3 by hand
; total -> TOTAL, a fixed word of memory
; the locals live together, at offsets from R5:
;   pizzas #0, each #-1, room #-2, mine #-3, enough #-4
;   inner pizzas #-5
.ORIG x3000

; int pizzas = 3;  int each = 8;






; char room = 'A';  ('A' is just x0041)


; mine = pizzas * each ...



; ... + pizzas % 2;



; { int pizzas = 2;  total = total + pizzas * each; }








; total = total + mine;




; enough = (total > TABLE);






; printf: a library call -- Thursday

; ---- MULT: R2 <- R0 * R1, from Lecture 2 ----









; ---- data ----






