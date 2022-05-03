
%ifndef PUL_COR_INC
%define PUL_COR_INC

SYS_QUT equ 60

%define l_0 rax
%define l_1 rdi
%define l_2 rsi
%define l_3 rdx
%define l_4 rcx
%define l_5 r8
%define l_6 r9
%define l_7 r10

%define i_0 eax
%define i_1 edi
%define i_2 esi
%define i_3 edx
%define i_4 ecx
%define i_5 r8d
%define i_6 r9d
%define i_7 r10d

%define s_0 ax
%define s_1 di
%define s_2 si
%define s_3 dx
%define s_4 cx
%define s_5 r8w
%define s_6 r9w
%define s_7 r10w

%define b_0 al
%define b_1 dil
%define b_2 sil
%define b_3 dl
%define b_4 cl
%define b_5 r8b
%define b_6 r9b
%define b_7 r10b

%define c_0 ah
%define c_3 dh
%define c_4 ch

%define psh push
%define cll call
%define mvz movzx
%define jeq je
%define tst test

%define sys_cll syscall

%macro qut 1
	mov l_0, SYS_QUT
	mov b_1, %1
	syscall
	%endmacro

%macro psh_all 0
	psh l_0
	psh l_1
	psh l_2
	psh l_3
	psh l_4
	psh l_5
	psh l_6
	%endmacro

%macro pop_all 0
	pop l_6
	pop l_5
	pop l_4
	pop l_3
	pop l_2
	pop l_1
	pop l_0
	%endmacro

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
; r10   | r10d  | r10w  | n/a   | r10b  | no   | parameter #7
; parameter registers
; fun cll: rdi, rsi, rdx, rcx, r8, r9
; sys cll: rdi, rsi, rdx, r10, r8, r9

%endif ; PUL_COR_INC

