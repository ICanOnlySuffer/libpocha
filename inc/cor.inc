
SYS_READ equ 0
SYS_WRITE equ 1
SYS_EXIT equ 60

define psh push
define cll call
define mvz movzx
define jeq je
define tst test
define jez jz
define set sete

define sys_cll syscall

macro qut code {
	mov l_0, SYS_EXIT
	mov b_1, code
	syscall
}

macro psh_all {
	psh rax
	psh rdi
	psh rsi
	psh rdx
	psh rcx
	psh r8
	psh r9
}

macro pop_all {
	pop r9
	pop r8
	pop rcx
	pop rdx
	pop rsi
	pop rdi
	pop rax
}

; registers
; 64bit | 32bit | 16bit | 8hbit | 8lbit | keep | description
; rax   | eax   | ax    | ah    | al    | no   | returned
; rcx   | ecx   | cx    | ch    | cl    | no   | parameter #4 (cmp)
; rdx   | edx   | dx    | dh    | dl    | no   | parameter #3
; rbx   | ebx   | bx    | bh    | bl    | yes  | -
; rsp   | esp   | sp    | n/a   | spl   | yes  | stack pointer
; rbp   | ebp   | bp    | n/a   | bpl   | yes  | stack base pointer
; rsi   | esi   | si    | n/a   | sil   | no   | parameter #2
; rdi   | edi   | di    | n/a   | dil   | no   | parameter #1
; r8    | r8d   | r8w   | n/a   | r8b   | no   | parameter #5
; r9    | r9d   | r9w   | n/a   | r9b   | no   | parameter #6
; r10   | r10d  | r10w  | n/a   | r10b  | no   | i forgor
; parameter registers
; fun cll: rdi, rsi, rdx, rcx, r8, r9
; sys cll: rdi, rsi, rdx, r10, r8, r9

