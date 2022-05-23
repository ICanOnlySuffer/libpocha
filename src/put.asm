format ELF64

include "../inc/cor.inc"
include "../inc/str.inc"

public fil_put
public fil_put_chr
public fil_put_arr

STD_INN equ 0
STD_OUT equ 1
STD_ERR equ 2

SYS_RED equ 0
SYS_WRT equ 1

section '.text' executable
; nil ; u64:fil u64:str ;
fil_put:
	psh l_1
	mov l_1, l_2
	cll str_len
	mov l_3, l_0
	pop l_1
	mov l_0, SYS_WRT
	sys_cll
	ret

; nil ; u64:fil u08:chr ;
fil_put_chr:
	psh l_2
	mov l_2, rsp
	mov l_3, 1
	mov l_0, SYS_WRT
	sys_cll
	pop l_2
	ret

; nil ; u64:fil u64:len u64:arr ;
fil_put_arr:
	mov l_5, l_1
	mov s_6, s_2
	mov l_7, l_3
.loop:
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
	jne .loop
.end:
	ret

