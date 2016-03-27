@ First partner's name: Lingfei Lu, A91046735
@ Second partner's name: Junxi Li, A91105747

.syntax unified
.text

.align 3
.global decodeChar
.func decodeChar, decodeChar
.type decodeChar, %function

@ char decodeChar(char *b)
decodeChar:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}
	
    @r4 = r0 = *b
    mov r4, r0
    
    @if(b == NULL)
    cmp r4, #0
    beq return0
    
    
    @r5 = i = 5
    mov r5, #5
    
    @r6 = num = 0
    mov r6, #0
    
    @r7 = count = 1
    mov r7, #1
    
    @for(i = 5; i >=0; i--) 
    for:cmp r5, #0
    blt return
    
    @if(*(b+i) == '1')
    @r8 = *(b+i)
    ldrb r8, [r4, r5]
    
    @r9 = '1'
    @mov r9, #'1'
    
    @*(b+i) == '1'
    cmp r8, #'1'
    
    @branch to count *= 2
    bne next
    
    @num += count
    add r6, r6, r7
    
    next:lsl r7, r7, #1
    
    @i--
    sub r5, r5, #1
    b for
    
    
    @return 0
    return0:mov r0, #0
    b end
    
    return:
    ldr r1, =MAPPING
    ldrb r0, [r1, r6]
    
    end:
    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end
