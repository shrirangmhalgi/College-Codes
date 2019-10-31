;write a ALP menu driven program to implement following dos commands
; 1. Type
; 2. Copy
; 3. Delete
;using file operations

;----------MACROS----------
%macro scall 4
    mov rax, %1
    mov rdi, %2
    mov rsi, %3
    mov rdx, %4
    syscall
%endmacro

;----------SECTION.BSS----------
section .bss
   choice resb 2
   filename resb 50
   file1 resb 20
   file2 resb 20
   filehandler resq 1
   
   buffer resb 1024
   buffer_len equ $-buffer
   
   length resq 1
   
;----------SECTION.DATA----------
section .data
   menu_msg db 10, "----------WELCOME----------"
            db 10, "1 : TYPE "
            db 10, "2 : COPY "
            db 10, "3 : DELETE "
            db 10, "0 : EXIT "
            db 10, ">> "
   menu_msg_len equ $-menu_msg
   
   file_name_msg db 10, "ENTER FILE NAME >> "
   file_name_msg_len equ $-file_name_msg
   
   src_des_msg db 10, "ENTER SOURCE AND DESTINATION FILE SEPARATED BY A SPACE >> "
   src_des_msg_len equ $-src_des_msg
   
   err_msg db 10, "-----ERROR IN FILE-----", 10 
   err_msg_len equ $-err_msg
   
   del_msg db 10, "FILE SUCCESSFULLY DELETED ", 10
   del_msg_len equ $-del_msg
   
   cpy_msg db 10, "FILE SUCCESSFULLY COPIED"
   cpy_msgl equ $-cpy_msg 
;----------SECTION.TXT----------
section .txt
   global _start
      _start :
              scall 1, 1, menu_msg, menu_msg_len
              scall 0, 0, choice, 2              
              
              cmp byte[choice], 31h
              je case1
              
              cmp byte[choice], 32h
              je case2
              
              cmp byte[choice], 33h
              je case3
              
              cmp byte[choice], 30h
              je case0
              
      case1 : call type
              jmp exit_proc
                      
      case2 : call copy
              call exit_proc
              
      case3 : call delete
              call exit_proc
              
      case0 : call exit_proc
      
            
              
;----------EXIT_PROC---------
exit_proc : 
            mov rax, 60
            mov rdi, 0
            syscall   
            
;----------DISPLAY_PROC----------



;----------TYPE----------
type : 
      scall 1, 1, file_name_msg, file_name_msg_len
      scall 0, 0, filename, 50
      dec rax
      mov byte[filename + rax], 0
      scall 2, filename, 2, 0777o
      cmp rax, -1
      jle error
      mov [filehandler], rax
      scall 0, [filehandler], buffer, 1024
      mov [length], rax
      scall 1, 1, buffer, length
      scall 3, [filehandler], 0, 0
      ret

;----------COPY----------
copy :
       scall 1, 1, src_des_msg, src_des_msg_len
       scall 0, 0, filename, 50
       
       dec rax
       mov byte[filename + rax], 0
       
       call file_n
         
       scall 2, file1, 2, 0777o
       cmp rax, -1h
       jle error
       mov [filehandler], rax
       scall 0, [filehandler], buffer, 1024      
       mov [length], rax 
       scall 3, filehandler, 0, 0                 
       
       scall 2, file2, 2, 0777o
       cmp rax, -1h
       jle error
       mov [filehandler], rax
       scall 1, [filehandler], buffer, [length]   
       scall 3, filehandler, 0, 0
       scall 1, 1, cpy_msg, cpy_msgl
       ret
 
;----------DELETE-----------
delete :
         scall 1, 1, file_name_msg, file_name_msg_len
         scall 0, 0, filename, 50
         dec rax
         mov byte[filename + rax], 0
         
         scall 2, filename, 2, 0777o
         cmp rax, -1
         jle error
         mov rax, 87
         mov rdi, filename
         syscall
         scall 1, 1, del_msg, del_msg_len
         ret
       
;---------ERROR----------      

error : scall 1, 1, err_msg, err_msg_len
       jmp exit_proc
      
;---------FILE_N---------
file_n :
          mov rsi, filename
          mov rdi, file1
    bck : mov al, [rsi]
          cmp al, 20h
          je nex
          mov [rdi], al
          inc rsi
          inc rdi
          jmp bck
    nex : mov byte[rdi], 0
            
          mov rdi, file2
          inc rsi
          
   bck1 : mov al, [rsi]
          cmp al, 0h
          je next5
          mov [rdi], al
          inc rsi
          inc rdi
          jmp bck1
  next5 : mov byte[rdi], 0
          ret      
