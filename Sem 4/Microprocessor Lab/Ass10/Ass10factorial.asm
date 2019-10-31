%macro scall 4
	mov rax, %1
	mov rdi, %2
	mov rsi, %3
	mov rdx, %4
syscall
%endmacro
;----------
section .data

m1 db "Enter the number : "
m1_l equ $-m1

m2 db "Factorial of given number is : "
m2_l equ $-m2

m3 db "Factorial of given number : 00000001",10
m3_l equ $-m3

;----------
section .bss

num resb 8
ans resb 16

;----------
section .data
   global _start
               _start:
                    	scall 1,1,m1,m1_l
	                  scall 0,0,num,9
	                  call accept
	                  mov eax,ebx
	                  cmp rax,01
                  	jbe label
	
	                  call factorial
	                  call display
	                  jmp exit
	
             label : scall 1,1,m3,m3_l
	                  jmp exit
	
;------------ exit ------------------
exit:
	mov rax,60
	mov rdi,0
	syscall
	
	
;------------ factorial --------------
factorial : 
	        cmp rax,01
	        je recton1
	        push rax
	        dec rax
	        call factorial
	
recton : pop rbx
	      mul ebx
	      jmp ret_p
	
recton1: pop rbx
      	jmp recton
	 
ret_p : ret
	
; -------------- accept ---------------
accept:
	    mov rsi,num
	    mov eax,0
	    mov ebx,0
	    mov rcx,8
	
back : rol ebx,4
	    mov al,[rsi]
	    cmp al,39h
	    jbe next
	    sub al,07h
	
next : sub al,30h
     	 add ebx,eax
 	    inc rsi
     	 dec rcx
 	    jnz back
       ret
 
;---------------- display----------------
display:
	     mov rcx,8
	     mov rbx,ans
			 
back1 : rol eax,4
	     mov dl,al
	     and dl,0Fh
	     cmp dl,09h
	     jbe next1
	     add dl,07h

next1 : add dl,30h
	     mov [rbx],dl
	     inc rbx
	     dec rcx
	     jnz back1
	     scall 1,1,m2,m2_l
	     scall 1,1,ans,8
        ret	  
