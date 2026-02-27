.section .bss
    .lcomm ram, 256
    .global ram

.section .text
    .global sum

sum:
    xor %eax, %eax
    mov $0, %eax
    mov %rdi, %rcx
    xor %rdi, %rdi
L1:  
    add ram(, %rdi, 1), %eax
    inc %rdi
    dec %rcx
    jnz L1
    mov %eax, ram+0x51
    ret

.section .note.GNU-stack,"",@progbits
