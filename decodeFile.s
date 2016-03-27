@ First partner's name: Lingfei Lu, A91046735
@ Second partner's name: Junxi Li, A91105747

.syntax unified
read: .asciz "r"
write: .asciz "w"
.text

.align 3
.global decodeFile
.func decodeFile, decodeFile
.type decodeFile, %function
 
@ void decodeFile(char *input, char *bin, char * output, int index)
decodeFile:
    @ Save caller's registers on the stack
    push {r4-r11, ip, lr}
    
    @if(input == NULL || bin == NULL || output == NULL)
    cmp r0, #0
    beq return
    
    cmp r1, #0
    beq return
    
    cmp r2, #0
    beq return
    
    
    @r4 = input
    mov r4, r0
    
    @r5 = bin
    mov r5, r1
    
    @r6 = output
    mov r6, r2
    
    r7 = index
    mov r7, r3
    
    @r0 = input
    mov r0, r4
    
    @r1 = "r"
    ldr r1, =read
    
    bl fopen
    
    @if(in == NULL)
    cmp r0, #0
    beq return
    
    @r8 = in
    mov r8, r0
    
    @r0 = r5 = bin
    mov r0, r5
    
    @r1 = "w"
    ldr r1, =write
    
    bl fopen
    
    @if(out == NULL)
    cmp r0, #0
    beq return
    
    @r9 = binary
    mov r9, r0
    
    @r0 = in
    mov r0, r8
    
    @r1 = binary
    mov r1, r9
    
    @r2 = index
    mov r2, r7
    
    bl codeToBinary
    
    @r0 = binary, fclose(binary)
    mov r0, r9
    bl fclose
    
    @r0 = bin
    mov r0, r5
    
    @r1 = "r"
    ldr r1, =read
    
    bl fopen
    
    @if(binary == NULL)
    cmp r0, #0
    beq return
    
    @r9 = binary = fopen(bin, "r")
    mov r9, r0
    
    @r0 = r6 = output
    mov r0, r6
    
    @r1 = "w"
    ldr r1, =write
    
    bl fopen
    
    @if(character == NULL)
    cmp r0, #0
    beq return
    
    @r10 = charatcer = fopen(output, "w")
    mov r10, r0
    
    @r0 = r9 = binary
    mov r0, r9
    
    @r1 = r10 = character
    mov r1, r10
    
    bl binaryToText
    
    @r0 = r8 = in
    mov r0, r8
    
    bl fclose
    
    @r0 = r9 = binary
    mov r0, r9
    
    bl fclose
    
    @r0 = r10 = character
    mov r0, r10
    
    bl fclose
    
    return: 
    @ restore caller's registers
    pop {r4-r11, ip, lr}

    @ ARM equivalent of return
    BX lr
.endfunc

.end
