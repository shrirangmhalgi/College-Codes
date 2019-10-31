%macro scall 4
	mov rax,%1
	mov rdi,%2
	mov rsi,%3
	mov rdx,%4
syscall
%endmacro

section .data
arr dw 05h,-15h,-21h,13h,-06h

pos db 10,"count of positive numbers is : "
pos_l equ $-pos

negt db 10,"count of negative numbers is : "
negt_l equ $-negt

endl db " ",10
endl_l equ $-endl

section .bss
pcnt resb 1
ncnt resb 1
ans resb 2

section .txt
global _start
_start:
	mov rcx,5
	mov rbx,arr
  bck :	mov rax,[rbx]
	BT rax,63
	jnc nxt
	inc byte[ncnt]
	jmp loop
  nxt : inc byte[pcnt]
 loop : inc rbx
 	dec rcx
 	jnz bck 		
	
	scall 1,1,pos,pos_l
	mov rdx,[pcnt]
	call display
	
	scall 1,1,negt,negt_l
	mov rdx,[ncnt]
	call display
	
	mov rax,60
	mov rdi,0
	syscall
	
display:				;for one digit number
	mov rsi,ans
	
	cmp dl,09h
	jle nxt1
	add dl,07h
  nxt1 :add dl,30h
	mov [rsi],dl
	
	scall 1,1,ans,1
	scall 1,1,endl,endl_l
ret
