section .data
    msg: db 'Hello, world!',10
    msgLen: equ $-msg

section .text

global start

start:
    mov rax, 0x2000004
    mov rdi, 1
    mov rsi, msg
    mov rdx, msgLen
    
    syscall

    mov rax, 0x2000001
    mov rdi, 0

    syscall
    
