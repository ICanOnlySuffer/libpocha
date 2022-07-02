format ELF64

include "../inc/cor.inc"

public str_end
public str_chomp
public str_length
public str_reverse
public str_compare
public str_equal
public str_copy
public str_from_num
public str_from_hex

section '.text' writable executable
; u64 ; u64:str ;
str_end:
	mov rax, rdi
	dec rax
.loop:
	inc rax
	cmp [rax], byte 0
	jne .loop
	ret

; u64 ; u64:str ;
str_chomp:
	cll str_end
	mov [rax-1], byte 0
	mov rax, rdi
	ret

; u64 ; u64:str ;
str_length:
	cll str_end
	sub rax, rdi
	ret

; u64 ; u64:str ;
str_reverse:
	psh rdi
	psh rdx
	cll str_end
	dec rax
	cmp rdi, rax
	jnb .end
.loop:
	mov dl, [rax]
	mov dh, [rdi]
	mov [rax], dh
	mov [rdi], dl
	dec rax
	inc rdi
	cmp rdi, rax
	jng .loop
.end:
	pop rdx
	pop rax
	ret

; s16 ; u64:s_1 u64:s_2 ;
str_compare:
	mvz ax, byte [rdi]
	tst al, al
	jeq .end
.loop:
	cmp byte [rsi], al
	jne .end
	inc rdi
	inc rsi
	mvz ax, byte [rdi]
	tst al, al
	jne .loop
.end:
	movsx dx, byte [rsi]
	sub ax, dx
	ret

; u08 ; u64:s_1 u64:s_2 ;
str_equal:
	cll str_compare
	tst ax, ax
	set al
	ret

; u64 ; u64:dst u08:len u64:arr ;
str_copy:
	psh rcx
	mov cl, sil
.loop:
	mov rsi, [rdx]
.single:
	mov al, [rsi]
	mov [rdi], al
	inc rdi
	inc rsi
	tst al, al
	jnz .single
.single_end:
	dec rdi
	add rdx, 8
	dec cl
	tst cl, cl
	jnz .loop
.end:
	mov rax, rdi
	pop rcx
	ret

; u64 ; str:dst u64:num ;
str_from_num:
	psh rdi
	mov rax, rsi
.loop:
	mov rdx, 0
	mov rsi, 10
	div rsi
	add dl, 48
	mov [rdi], dl
	inc rdi
	tst rax, rax
	jnz .loop
.end:
	mov [rdi], byte 0
	mov rdi, [rsp]
	cll str_reverse
	pop rax
	ret

; u64 ; str:dst u64:hex ;
str_from_hex:
	psh	rdi
	mov	rax,rsi
.loop:
	mov rdx, 0
	mov rsi, 16
	div rsi
	cmp dl, 9
	jng .number
	add dl, 39
.number:
	add dl, 48
	mov [rdi], dl
	inc rdi
	tst rax, rax
	jnz .loop
.end:
	mov [rdi], byte 'x'
	mov [rdi+1], byte '0'
	mov [rdi+2], byte 0
	mov rdi, [rsp]
	cll str_reverse
	pop rax
	ret

