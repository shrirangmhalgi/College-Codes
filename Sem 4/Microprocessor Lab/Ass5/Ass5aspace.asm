extern proc_far
global fh, char, buff, length

%macro scall 4
   mov rax, %1
   mov rdi, %2
   mov rsi, %3
   mov rdx, %4
   syscall
%endmacro

;--------------
section .data
   msg db 10, "ENTER FILE NAME >> "
   msg_l equ $-msg
   
   msg1 db 10, "ENTER THE CHARACTER TO BE SEARCHED "
   msg1_l equ $-msg1
   
   err_msg db 10, "FILE NOT FOUND "
   err_msg_l equ $-err_msg
;----------- 
section .bss
   filename resb 50
   buff resb 1024
   buff_len equ $-buff
   char resb 2
   fh resq 1
   length resq 1
   
;----------
section .txt
   global _start
               _start :
                        scall 1, 1, msg, msg_l
                        scall 0, 0, filename, 50
                        dec rax
                        mov byte[filename + rax], 0
                        
                        scall 1, 1, msg1, msg1_l
                        scall 0, 0, char, 2
                        
                        scall 2, filename, 2, 0777o
                        cmp rax, -1h
                        jle error
                        mov [fh], rax
                        
                        scall 0, [fh], buff, buff_len
                        mov [length], rax
                        call proc_far
                        jmp exit
                        
              error :   scall 1, 1, err_msg, err_msg_l
                        jmp exit
                        
               exit :   mov rax, 60
                        mov rdi, 0
                        syscall
