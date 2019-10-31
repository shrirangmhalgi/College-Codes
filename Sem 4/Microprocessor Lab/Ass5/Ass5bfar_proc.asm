%macro scall 4
   mov rax, %1
   mov rdi, %2
   mov rsi, %3
   mov rdx, %4
   syscall
%endmacro

;----------
section .data
   smsg db 10, "no of spaces = "
   smsg_l equ $-smsg
   
   lmsg db 10, "no of lines = "
   lmsg_l equ $-lmsg
   
   cmsg db 10, "number of characters = "
   cmsg_l equ $-cmsg
   
   nline db 10
   nline_l equ $-nline
   
   
;----------
section .bss
   scnt resq 1
   ccnt resq 1
   lcnt resq 1
   temp resb 2
   
;-----------

global proc_far
extern fh, char, buff, length
  

section .txt
      global main
               main :
                     proc_far :
                                mov rax, 0
                                mov rbx, 0
                                mov rcx, 0
                                mov rdx, 0
                                mov rsi, 0
                                mov rdi, 0

                                mov bl, [char]
                                mov rsi, buff
                                mov rcx, [length]
                                
                      back :    mov al, [rsi]
                                cmp al, 20h
                                jne line
                                inc byte[scnt]
                                jmp next
                                
                      line :    cmp al, 0Ah
                                jne character
                                inc byte[lcnt]
                                jmp next
                                
                   character :  cmp al, bl
                                jne next
                                inc byte[ccnt]
                         next : inc rsi
                                dec rcx
                                jnz back
                                                    
                                scall 1, 1, smsg, smsg_l
                                mov rbx, [scnt]
                                call display_proc
                                scall 1, 1, temp,16
                                
                                scall 1, 1, cmsg, cmsg_l
                                mov rbx, [ccnt]
                                call display_proc
                                scall 1, 1, temp, 16
                                
                                scall 1, 1, lmsg, lmsg_l
                                mov rbx, [lcnt]
                                call display_proc
                                scall 1, 1, temp, 16      
                                
                                scall 3, [fh], 0, 0
                                scall 1, 1, nline, nline_l
                                ret
                                
                display_proc : 
                               mov rcx, 2
                               mov al, bl
                               mov rsi, temp
                               
                       back2 : rol al, 4
                               mov dl, al
                               and dl, 0fh
                               cmp dl, 09h
                               jbe c1
                               add dl, 07h
                                 
                          c1 : add dl, 30h
                               mov [rsi], dl
                               inc rsi
                               dec rcx
                               jnz back2
                               ret 
                               
