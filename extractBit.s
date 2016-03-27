@ First partner's name: Lingfei Lu, A91046735
@ Second partner's name: Junxi Li, A91105747

.syntax unified

.text

.align 3
.global extractBit
.func extractBit, extractBit
.type extractBit, %function

@ int extractBit(char c, int index)
extractBit:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}
    
    @r4 = c
    mov r4, r0
    
    @r5 = index
    mov r5, r1
    
    @r6 = clear = 1
    mov r6, #1
    
    @clear = clear << index
    lsl r6, r6, r5
    
    @int output = clear & c
    and r7, r6, r4
    
    @output = output >> index
    lsr r7, r7, r5
   
    @return output
    mov r0, r7
    
    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end
