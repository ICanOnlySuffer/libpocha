
%ifndef PUTILS_COR_INC
%define PUTILS_COR_INC

STD_INN equ 0		  ; con STD_INN 0
STD_OUT equ 1		  ; con STD_OUT 1
STD_ERR equ 2		  ; con STD_ERR 2

SYS_RED equ 0		  ; con SYS_RED 0
SYS_WRT equ 1		  ; con SYS_WRT 1
SYS_QUT equ 60		  ; con SUS_QUT 60

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

%define h_0 ah
%define h_3 dh
%define h_4 ch

%define psh push
%define cll call
%define mvz movzx
%define sys_cll syscall

%macro qut 1		  ; mac qut u08:cde dos
	mov rax, SYS_QUT  ; 	u64 sys <-- SYS_QUT
	mov dil, %1 	  ; 	u08 __0 <-- cde
	syscall			  ; 	SYS_QUT.cll __0
	%endmacro		  ; 	end

%macro psh_all 0	  ; mac psh_all nil dos
	psh rax
	psh rdi
	psh rsi
	psh rdx
	psh rcx
	psh r8
	psh r9
	%endmacro		  ; 	end

%macro pop_all 0	  ; mac pop_all nil dos
	pop r9
	pop r8
	pop rcx
	pop rdx
	pop rsi
	pop rdi
	pop rax
	%endmacro		  ; 	end

%endif ; PUTILS_COR_INC

; registers
; 64bit | 32bit | 16bit | 8hbit | 8lbit | keep | description
; rax   | eax   | ax    | ah    | al    | no   | returned
; rcx   | ecx   | cx    | ch    | cl    | no   | parameter #4 (cmp out)
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

