.section .bss
    .lcomm ram, 4096
    .global ram

.section .text
    .global sum

sum:
    mov $0, %eax
    mov %rdi, %rcx
    xor %rdi, %rdi
    xor %rdx, %rdx
L1:  
    add ram(, %rdx, 4), %eax
    inc %rdx
    dec %rcx
    jnz L1

    mov %eax, ram+0x51
    ret

.section .note.GNU-stack,"",@progbits
