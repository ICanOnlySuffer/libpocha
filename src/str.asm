format ELF64

include "../inc/cor.inc"

public str_end
public str_chomp
public str_length
public str_reverse
public str_compare
public str_from_num
public str_from_hex

section '.text' writable executable
; u64 ; u64:str ;
str_end:
	mov l_0, l_1
	dec l_0
.loop:
	inc l_0
	cmp [l_0], byte 0
	jne .loop
	ret

; u64 ; u64:str ;
str_chomp:
	cll str_end
	mov [l_0-1], byte 0
	mov l_0, l_1
	ret

; u64 ; u64:str ;
str_length:
	cll str_end
	sub l_0, l_1
	ret

; u64 ; u64:str ;
str_reverse:
	psh l_1
	psh l_3
	cll str_end
	dec l_0
	cmp l_1, l_0
	jnb .end
.loop:
	mov b_3, [l_0]
	mov c_3, [l_1]
	mov [l_0], c_3
	mov [l_1], b_3
	dec l_0
	inc l_1
	cmp l_1, l_0
	jng .loop
.end:
	pop l_3
	pop l_0
	ret

; s16 ; u64:s_1 u64:s_2 ;
str_compare:
	mvz s_0, byte [l_1]
	tst b_0, b_0
	jeq .end
.loop:
	cmp byte [l_2], b_0
	jne .end
	inc l_1
	inc l_2
	mvz s_0, byte [l_1]
	tst b_0, b_0
	jne .loop
.end:
	movsx s_3, byte [l_2]
	sub s_0, s_3
	ret

; u64 ; str:dst u64:num ;
str_from_num:
	psh l_1
	mov l_0, l_2
.loop:
	mov l_3, 0
	mov l_2, 10
	div l_2
	add b_3, 48
	mov [l_1], b_3
	inc l_1
	cmp l_0, 0
	jne .loop
.end:
	mov [l_1], byte 0
	mov l_1, [rsp]
	cll str_reverse
	pop l_0
	ret

; u64 ; str:dst u64:hex ;
str_from_hex:
	psh l_1
	mov l_0, l_2
.loop:
	mov l_3, 0
	mov l_2, 16
	div l_2
	cmp b_3, 9
	jng .number
	add b_3, 39
.number:
	add b_3, 48
	mov [l_1], b_3
	inc l_1
	cmp l_0, 0
	jne .loop
.end:
	mov [l_1], byte 'x'
	mov [l_1+1], byte '0'
	mov [l_1+2], byte 0
	mov l_1, [rsp]
	cll str_reverse
	pop l_0
	ret


