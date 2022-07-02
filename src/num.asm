format ELF64

include "../inc/cor.inc"
include "../inc/str.inc"

public num_from_str
public num_pow_num

section '.text' writable executable

; u64 ; u64:str ;
num_from_str:
	lea rax, [str_length]
	cll rax
	mov rsi, rax
	mov r8, 0
.loop:
	dec rsi
	psh rdi
	psh rsi
	mov rdi, 10
	cll num_pow_num
	pop rsi
	pop rdi
	mvz rcx, byte[rdi]
	sub rcx, 48
	mul rcx
	add r8, rax
	inc rdi
	cmp rsi, 0
	jne .loop
.end:
	mov rax, r8
	ret

; u64 ; u64:num u64:pow ;
num_pow_num:
	mov rax, 1
.loop:
	cmp rsi, 0
	jeq .end
	mov rdx, 0
	mul rdi
	dec rsi
	jmp .loop
.end:
	ret

