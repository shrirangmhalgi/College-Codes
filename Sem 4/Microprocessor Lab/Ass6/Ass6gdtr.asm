%macro scall 4
   mov rax, %1
   mov rdi, %2
   mov rsi, %3
   mov rdx, %4
   syscall
%endmacro

section .data 
   pm_msg db "PROTECTED MODE IS NOT ENABLED", 10
   pm_msgl equ $-pm_msg
   
   pm_msg1 db "ALREADY IN PROTECTED MODE", 10
   pm_msg1l equ $-pm_msg1
   
   gdtr_msg db 10, "GDTR CONTENTS ARE :- "  
   gdtr_msgl equ $-gdtr_msg
   
   ldtr_msg db 10, "LDTR CONTENTS ARE :- "
   ldtr_msgl equ $-ldtr_msg
   
   idtr_msg db 10, "IDTR CONTENTS ARE :- "
   idtr_msgl equ $-idtr_msg
   
   tr_msg db 10, "TR CONTENTS ARE :- "
   tr_msgl equ $-tr_msg
   
   colon db ":"
   colon_l equ $-colon
   
   e db 10
   el equ $-e
   
section .bss
   gdtr resb 10
   idtr resb 10
   ldtr resb 10
   tr resb 10
   buff resb 10

section .txt 
   global _start
         _start :
                 smsw eax
                 bt eax, 31
                 jc l1
                 scall 1, 1, pm_msg, pm_msgl
            l1 : scall 1, 1, pm_msg1, pm_msg1l 
                 sgdt [gdtr]
                 sidt [idtr]
                 sldt [ldtr]
                 
                 ;----gdtr contents---- 
                 scall 1, 1, gdtr_msg, gdtr_msgl
                 mov bx, [gdtr + 4]
                 call display
                 scall 1, 1, buff, 10
                 scall 1, 1, colon, colon_l   
                 mov bx, [gdtr + 2]
                 call display
                 scall 1, 1, buff, 10
                 scall 1, 1, colon, colon_l
                 mov bx, [gdtr]
                 call display
                 scall 1, 1, buff, 10
                 
                 ;----idtr contents----
                 scall 1, 1, idtr_msg, idtr_msgl
                 mov bx, [idtr + 4]
                 call display
                 scall 1, 1, buff, 10
                 scall 1, 1, colon, colon_l   
                 mov bx, [idtr + 2]
                 call display
                 scall 1, 1, buff, 10
                 scall 1, 1, colon, colon_l
                 mov bx, [idtr]
                 call display
                 scall 1, 1, buff, 10
                 
                 ;----ldtr contents----
                 scall 1, 1, ldtr_msg, ldtr_msgl
                 mov bx, [ldtr]
                 call display
                 scall 1, 1, buff, 10
                 
                 ;----exit----
                 scall 1, 1, e, el
                 mov rax, 60
                 mov rdi, 0
                 syscall
                 
                 
       display :
                mov rsi, buff
                mov rcx, 4
                mov rdx, 0
          bck : rol bx, 4
                mov dl, bl
                and dl, 0fh
                cmp dl, 09
                jbe lx1
                add dl, 7h
          lx1 : add dl, 30h
                mov [rsi], dl
                inc rsi
                dec rcx 
                jnz bck
                ret           
