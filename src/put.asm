%include "cor.inc"

fil_put: ; u64:fil u64:str ;
	psh l_1
	mov l_1, l_2
	cll str_len
	mov l_3, l_0
	pop l_1
	mov l_0, SYS_WRT
	sys_cll
	ret

fil_put_chr: ; u64:fil u08:chr ;
	psh l_2
	mov l_2, rsp
	mov l_3, 1
	mov l_0, SYS_WRT
	sys_cll
	pop l_2
	ret

fil_put_arr: ; u64:fil u64:len u64:arr ;
	mov l_5, l_1
	mov s_6, s_2
	mov l_7, l_3
	fil_put_arr_loop:
		mov l_1, [l_7]
		cll str_len
		mov l_3, l_0
		mov l_2, [l_7]
		mov l_1, l_5
		mov l_0, SYS_WRT
		sys_cll
		add l_7, 8
		dec s_6
		cmp s_6, 0
		jne fil_put_arr_loop
	ret

section .text
	extern str_len
	global fil_put
	global fil_put_chr
	global fil_put_arr

