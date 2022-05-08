%include "cor.inc"

global str_end
global str_len
global str_chp
global str_rvs
global str_cmp
global str_frm_u64
global str_cpy
global str_cpy_arr
global str_frm_fmt

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
	movsx s_3, byte [l_2]
	sub s_0, s_3
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

; nil ; str:bff u64:num ;
str_frm_u64:
	psh l_1
	mov l_0, l_2
	str_frm_u64_loop:
		mov l_3, 0
		mov l_2, 10
		div l_2
		add b_3, 48
		mov [l_1], b_3
		inc l_1
		cmp l_0, 0
		jne str_frm_u64_loop
	mov [l_1], byte 0
	pop l_1
	cll str_rvs
	ret

; nil ; u64:dst u64:str ;
str_cpy:
	mov b_0, [l_2]
	mov [l_1], b_0
	inc l_1
	inc l_2
	cmp b_0, byte 0
	jne str_cpy
	mov [l_1], byte 0
	ret

; nil ; u64:dst u08:len u64:arr ;
str_cpy_arr:
	mov b_4, b_2
	str_cpy_arr_loop:
		mov l_2, [l_3]
		cll str_cpy
		dec l_1
		add l_3, 8
		dec b_4
		cmp b_4, 0
		jne str_cpy_arr_loop
	ret

; nil ; u64:dst u64:fmt u64:arr ;
str_frm_fmt:
	dec l_2
	str_frm_fmt_loop:
		inc l_2
		cmp [l_2], byte 0
		jeq str_frm_fmt_end
		cmp [l_2], byte '%'
		jne str_frm_fmt_else
		inc l_2
		cmp [l_2], byte 'u'
		jeq str_frm_fmt_u
		cmp [l_2], byte 's'
		jeq str_frm_fmt_s
		jmp str_frm_fmt_else
		str_frm_fmt_u:
			psh l_3
			psh l_2
			mov l_2, [l_3]
			cll str_frm_u64
			cll str_end
			mov l_1, l_0
			pop l_2
			pop l_3
			add l_3, 8
			jmp str_frm_fmt_loop
		str_frm_fmt_s:
			psh l_2
			mov l_2, [l_3]
			cll str_cpy
			add l_3, 8
			pop l_2
			dec l_1
			jmp str_frm_fmt_loop
		str_frm_fmt_else:
			mov b_0, [l_2]
			mov [l_1], b_0
			inc l_1
			jmp str_frm_fmt_loop
	str_frm_fmt_end:
		mov [l_1], byte 0
	ret

