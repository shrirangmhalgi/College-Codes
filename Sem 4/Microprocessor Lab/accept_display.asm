%macro acc_disp 4 
    mov rax, %1
    mov rdi, %2
	mov rsi, %3
	mov rdx, %4
	syscall
%endmacro

section .data
	msg db 10, "enter 1st number ", 10
	msgl equ $-msg
	
	msg1 db "entered number 1 is = "
	msgl1 equ $-msg1
	
	msg2 db 10, "enter second number ", 10
	msgl2 equ $-msg2
	
	msg3 db "entered number 2 is = "
	msgl3 equ $-msg3
	
	msg4 db "multiplication of 2 numbers is = "
	msgl4 equ $-msg4
	 
	
section .bss
	num1 : resb 8
	num2 : resb 8
	ans : resb 8
	
section .txt
    global _start
        _start:
            acc_disp 1, 1, msg, msgl 
            acc_disp 0, 0, num1, 8
            
            acc_disp 1, 1, msg1, msgl1
            acc_disp 1, 1, num1, 8
            
            acc_disp 1, 1, msg2, msgl2
            acc_disp 0, 0, num2, 8
            
            acc_disp 1, 1, msg3, msgl3
            acc_disp 1, 1, num2, 8
            
            mov al, 00h
            mov bl, [num2]
     loop : add al, [num1]
            dec bl
            jnz loop
            
            mov [ans], al
            acc_disp 1, 1, msg4, msgl4
            
            
            mov al, [ans]
            cmp al, 09h
            jbe loop2
            add al, 07h
     loop2: add al, 30h
            mov byte[ans], al
            
            acc_disp 1, 1, ans, 8
            
            
            mov rax, 60
			mov rdi, 0
			syscall
            
            
