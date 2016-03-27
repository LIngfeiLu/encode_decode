@ First partner's name: Lingfei Lu, A91046735
@ Second partner's name: Junxi Li, A91105747

.syntax unified
string: .asciz "%c"
.text

.align 3
.global codeToBinary
.func codeToBinary, codeToBinary
.type codeToBinary, %function

@void codeToBinary(FILE *in, FILE *out, int index);

codeToBinary:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @r4 = *in
    mov r4, r0
    
    @r5 = *out
    mov r5, r1
    
    @r6 = index
    mov r6, r2
    
    @if(in == NULL || out == NULL)
    cmp r4, #0
    beq break
    
    cmp r5, #0
    beq break
    
    while:
    @fgetc(in)
    mov r0, r4
    
    bl fgetc
    @char temp = fgetc(in)
    mov r7, r0
    
    @feof(in)
    mov r0, r4
    bl feof
    
    @if(feof(in))
    cmp r0, #1
    
    @break
    beq break
    
    @r0 = temp
    mov r0, r7
    
    @r1 = index
    mov r1, r6
    
    @extract(temp, index)
    bl extractBit
    
    @extract(temp, index)+'0'
    add r2, r0, #'0'
    
    @r0 = out
    mov r0, r5
    
    @r1 = "%c"
    ldr r1, =string
    
    
    bl fprintf
    b while
    
    break:
    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end
