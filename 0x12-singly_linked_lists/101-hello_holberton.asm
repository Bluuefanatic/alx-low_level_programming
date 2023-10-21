section .data
    hello db 'Hello, Holberton', 10, 0 ; 10 is the ASCII code for a new line character

section .text
    extern printf

    global main
    main:
        push rbp
        mov rdi, hello
        call printf
        pop rbp
        mov eax, 0
        ret
