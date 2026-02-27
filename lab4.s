.section .bss
    #configures ram 
    .lcomm ram, 4096
    .global ram

.section .text
    .global sum

sum:
    #zeros eax
    mov $0, %eax
    #moves arg from c file into rcx
    mov %rdi, %rcx
    #zeros rdi and rdx
    xor %rdi, %rdi
    xor %rdx, %rdx
L1:  
    #adds value at rdx in ram to eax, incriments by 4 because ram is unsinged int and not char
    add ram(, %rdx, 4), %eax
    #incriements ram index and subtracts count index
    inc %rdx
    dec %rcx
    jnz L1
    ret

.section .note.GNU-stack,"",@progbits
