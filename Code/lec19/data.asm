; data.asm: four nodes of a linked list of chars, head = x4004 (load before printlist)
; Node layout: word 0 = data, word 1 = next (x0000 is NULL)
.ORIG x4000
        .FILL x45             ; x4000  data
        .FILL x4006           ; x4001  next
        .FILL x43             ; x4002  data
        .FILL x4000           ; x4003  next
        .FILL x45             ; x4004  data
        .FILL x4002           ; x4005  next
        .FILL x42             ; x4006  data
        .FILL x0000           ; x4007  next
.END
