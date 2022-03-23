%include "cor.inc"

; u64 ; u64:str ;
str_end:
	mov l_0, l_1
	dec l_0
	str_end_loop:
		inc l_0
		cmp [l_0], byte 0
		jne str_end_loop
	ret

; u64 ; u64:str ;
str_len:
	cll str_end
	sub l_0, l_1
	ret

; nil ; u64:str ;
str_chp:
	cll str_end
	mov [l_0-1], byte 0
	ret

; s16 ; u64:s_1 u64:s_2 ;
str_cmp:
	mvz s_0, byte [l_1]
	tst b_0, b_0
	jeq str_cmp_end
	str_cmp_loop:
		cmp byte [l_2], b_0
		jne str_cmp_end
		inc l_1
		inc l_2
		mvz s_0, byte [l_1]
		tst b_0, b_0
		jne str_cmp_loop
	str_cmp_end:
	movsx dx, byte [rsi]
	sub ax, dx
	ret

; nil ; u64:str ;
str_rvs:
	cll str_end
	dec l_0
	cmp l_1, l_0
	jnb str_rvs_end
	str_rvs_loop:
		mov b_3, [l_0]
		mov c_3, [l_1]
		mov [l_0], c_3
		mov [l_1], b_3
		dec l_0
		inc l_1
		cmp l_1, l_0
		jb str_rvs_loop
	str_rvs_end:
	ret

; nil ; u64:bff u16:len u64:arr ;
str_cpy:
	mov r8, [rdx]
	str_cpy_loop:
		mov r9b, [r8]
		cmp r9b, 0
		jeq str_cpy_end
		mov [rdi], r9b
		inc rdi
		inc r8
		jmp str_cpy_loop
	str_cpy_end:
	add rdx, 8
	dec sil
	cmp sil, 0
	jnz str_cpy
	mov [rdi], byte 0
	ret

; nil ; str:bff u64:num ;
str_frm_u64:
	psh rdi
	mov rax, rsi
	u64_tos_loop:
		mov rdx, 0
		mov rsi, 10
		div rsi
		add dl, 48
		mov [rdi], dl
		inc rdi
		cmp rax, 0
		jne u64_tos_loop
	mov [rdi], byte 0
	pop rdi
	cll str_rvs
	ret

section .text
	global str_len
	global str_chp
	global str_rvs
	global str_cmp
	global str_cpy
	global str_frm_u64

