; Compute 5 * 4 (LC-3 has no multiply!)
.ORIG x3000
; R0 result, R1 multiplicand, R2 counter
     AND  R0, R0, #0   ; result = 0
     AND  R1, R1, #0
     ADD  R1, R1, #5   ; R1 = 5
     AND  R2, R2, #0
     ADD  R2, R2, #4   ; R2 = 4
LOOP BRz  DONE         ; counter zero?
     ADD  R0, R0, R1   ; result += R1
     ADD  R2, R2, #-1  ; count down
     BR   LOOP
DONE HALT
.END
