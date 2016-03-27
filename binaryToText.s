@ First partner's name: Lingfei Lu, A91046735
@ Second partner's name: Junxi Li, A91105747

.syntax unified
string: .asciz "%c"
.text

.align 3
.global binaryToText
.func binaryToText, binaryToText
.type binaryToText, %function

@ void binaryToText(FILE *in, FILE *out)
binaryToText:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}

    @r4 = in
    mov r4, r0
    
    @r5 = out
    mov r5, r1
    
    @if(in == NULL | out == NULL)
    cmp r4, #0
    beq next
    
    cmp r5, #0
    beq next
    
    @r8 = 6
    mov r8, #6
    
    @r0 = r8
    mov r0, r8
    
    @malloc(6)
    bl malloc 
    
    @if(arr = NULL)
    cmp r0, #0
    beq next
    
    @r6 = arr
    mov r6, r0
    
    while:
    @r0 = arr
    mov r0, r6
    
    @r1 = 1
    mov r1, #1
    
    @r2 = 6
    mov r2, #6
    
    @r3 = in
    mov r3, r4
    
    @fread(arr, 1, 6, in)
    bl fread
    
    @r7 = check
    mov r7, r0
    
    @if(check < 6)
    cmp r7, #6
    
    @break
    blt break
    
    @decodeChar(arr)
    mov r0, r6
    bl decodeChar
    
    @if(test ==0)
    cmp r0, #0
    beq next
    
    @r2 = r0 = test
    mov r2, r0
    
    @r0 = out
    mov r0, r5
    
    @r1 = "%c"
    ldr r1, =string
    
    @fprintf
    bl fprintf
    
    b while
    
    
    break:cmp r6, #0
    beq next
    
    @free(arr)
    mov r0, r6
    bl free
    
    next:

    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end
