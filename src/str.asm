format ELF64

include "../inc/cor.inc"

public str_end
public str_len
public str_chp
public str_rvs
public str_cmp
public str_frm_u64
public str_frm_hex
public str_cpy
public str_cpy_arr
public str_frm_fmt

section '.text' executable
; u64 ; u64:str ;
str_end:
	mov l_0, l_1
	dec l_0
.loop:
	inc l_0
	cmp [l_0], byte 0
	jne .loop
.end:
	ret

; u64 ; u64:str ;
str_len:
	cll str_end
	sub l_0, l_1
	ret

; u64 ; u64:str ;
str_chp:
	cll str_end
	mov [l_0-1], byte 0
	mov l_0, l_1
	ret

; s16 ; u64:s_1 u64:s_2 ;
str_cmp:
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

; u64 ; u64:str ;
str_rvs:
	psh l_1
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
	pop l_0
	ret

; u64 ; u64:dst u64:str ;
str_cpy:
	mov b_0, [l_2]
	mov [l_1], b_0
	inc l_1
	inc l_2
	cmp b_0, byte 0
	jne str_cpy
.end:
	mov [l_1], byte 0
	mov l_0, l_1
	ret

; u64 ; u64:dst u08:len u64:arr ;
str_cpy_arr:
	mov b_4, b_2
.loop:
	mov l_2, [l_3]
	cll str_cpy
	dec l_1
	add l_3, 8
	dec b_4
	cmp b_4, 0
	jne .loop
.end:
	mov l_0, l_1
	ret

; u64 ; str:dst u64:num ;
str_frm_u64:
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
	cll str_rvs
	pop l_0
	ret

; u64 ; str:dst u64:hex ;
str_frm_hex:
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
	cll str_rvs
	pop l_0
	ret

; u64 ; u64:dst u64:fmt u64:arr ;
str_frm_fmt:
	psh l_1
	dec l_2
.loop:
	inc l_2
	cmp [l_2], byte 0
	jeq .end
	cmp [l_2], byte '%'
	jne .else
	inc l_2
	cmp [l_2], byte 'u'
	jeq .whn_u
	cmp [l_2], byte 'x'
	jeq .whn_x
	cmp [l_2], byte 's'
	jeq .whn_s
.else:
	mov b_0, [l_2]
	mov [l_1], b_0
	inc l_1
	jmp .loop
.whn_u:
	psh l_3
	psh l_2
	mov l_2, [l_3]
	cll str_frm_u64
	cll str_end
	mov l_1, l_0
	pop l_2
	pop l_3
	add l_3, 8
	jmp .loop
.whn_x:
	psh l_3
	psh l_2
	mov l_2, [l_3]
	cll str_frm_hex
	cll str_end
	mov l_1, l_0
	pop l_2
	pop l_3
	add l_3, 8
	jmp .loop
.whn_s:
	psh l_2
	mov l_2, [l_3]
	cll str_cpy
	add l_3, 8
	pop l_2
	dec l_1
	jmp .loop
.end:
	mov [l_1], byte 0
	pop l_0
	ret

