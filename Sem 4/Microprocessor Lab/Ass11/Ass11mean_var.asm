section .data

    amsg db "Array Elements are:", 0
    mmsg db "Calculation of mean:", 0
    stdmsg db "calculation of std dev: ", 0
    varmsg db "calculation of varience is: ", 0
    fmt db "%s", 10, 0 ;nrml var ahe ha
    array dq 123.45, 120.88, 111.00
    ;array dq 1.00, 1.00, 1.00
    cnt dd 03
    fmt1 db  "%e", 10, "%e", 10, "%e", 10, 0
    fmt2 db "%e", 10, 0

section .bss

   mean resq 1
   var resq 1
   stddev resq 1

section .text

global main
   extern printf ;printf is a external entity to this program

   main:
         push rsp ;always push kar for stack printf function

         mov rdi, fmt ;kay ahe tuzha display karacha te (string msg %s wala rdi madhe jata)
         mov rsi, amsg ;(apla nrml msg la point karacha)
         mov rax, 0 ;(he kiti parameters display karacha ahe tyachasthi ahe)
         call printf ;function call dila

         mov rbx, array ;ekdach base la point kela rbx ni coz array display karacha ahe
         mov rdi, fmt1 ;kiti variable ahet tuze te ahe

         movq xmm0, [rbx] ;xmm0 is a pentium register
         add rbx, 8   ;qword ahe so 8 add kela pudhe sarkala

         movq xmm1,[rbx] ;xmm1 is a pentium register
         add rbx, 8   ;qword ahe so 8 add kela pudhe sarkala

         movq xmm2, [rbx] ;xmm2 is a pentium register
         add rbx, 8   ;qword ahe so 8 add kela pudhe sarkala
         mov rax, 3 ;3 ahet na array elements so 3
         call printf

      ;mean program
         finit
         fldz

         mov rbx, array
         mov rcx, 03
    bk : fadd qword[rbx]
         add rbx, 8
         loop bk
         fidiv dword[cnt]
         fst qword[mean]

         mov rdi, fmt
         mov rsi, mmsg
         mov rax, 0
         call printf

         mov rdi,fmt2
         movq xmm0, qword[mean]
         mov rax,1
         call printf

   ;varience code
         mov rsi, array
         mov rcx, 03
   bk1 : fldz
         fld qword[rsi]
         fsub qword[mean]
         fst ST1
         fmulp st1, st0 ; or fmulp (only)
         fadd   ;check it
         add rsi, 8
         loop bk1
         fidiv dword[cnt]
         fst qword[var]

         mov rdi, fmt
         mov rsi, varmsg
         mov rax, 0
         call printf

         mov rdi,fmt2
         movq xmm0, qword[var]
         mov rax,1
         call printf

    ;std dev code
         fldz
         fld qword[var]
         fsqrt
         fst qword[stddev]

         mov rdi, fmt
         mov rsi, stdmsg
         mov rax, 0
         call printf

         mov rdi, fmt2
         movq xmm0, qword[stddev]
         mov rax, 1
         call printf

         pop rbp
         mov rax,60
         mov rdi,0
         syscall
