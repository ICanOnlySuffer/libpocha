%include "str.inc"

global u64_pow_u64
global u64_frm_str

; u64 ; u64:num u64:pow ;
u64_pow_u64:
	mov l_0, 1
	cmp l_2, 0
	jeq u64_pow_u64_end
	mov l_3, 0
	u64_pow_u64_loop:
		mov l_3, 0
		mul l_1
		dec l_2
		cmp l_2, 0
		jne u64_pow_u64_loop
	u64_pow_u64_end:
	ret

; u64 ; u64:str ;
u64_frm_str:
	cll str_len
	mov l_2, l_0
	mov l_5, 0
	u64_frm_str_loop:
		dec l_2
		psh l_1
		psh l_2
		mov l_1, 10
		cll u64_pow_u64
		pop l_2
		pop l_1
		mvz l_4, byte[l_1]
		sub l_4, 48
		mul l_4
		add l_5, l_0
		inc l_1
		cmp l_2, 0
		jne u64_frm_str_loop
	mov l_0, l_5
	ret

