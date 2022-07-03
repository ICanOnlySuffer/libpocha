format ELF64

; the common object that is worked with is the file descriptor, here
; represented as `num`.

; object-oriented point of view:
; STD_OUT.put_str ("hi") ; prints the string "hi" to the STD_OUT
; STD_ERR.put_chr ('\n') ; prints a newline to the STD_ERR

; info:
; SYS_WRITE.call (fd, string, length)

include "../inc/cor.inc"
include "../inc/str.inc"

public num_put_str
public num_put_chr
public put
public put_chr
public put_err

STD_INN equ 0
STD_OUT equ 1
STD_ERR equ 2

section '.text' writable executable
; nil ; u64:f_d u64:str ;
num_put_str:
	psh rdx
	psh rdi
	mov rdi, rsi
	cll str_length
	mov rdx, rax
	pop rdi
	mov rax, SYS_WRITE
	sys_cll
	pop rdx
	ret

; nil ; u64:f_d u08:chr ;
num_put_chr:
	dec rsp
	mov byte [rsp], sil
	mov rsi, rsp
	mov rdx, 1
	mov rax, SYS_WRITE
	sys_cll
	inc rsp
	ret

; nil ; u64:str ;
put:
	mov rsi, rdi
	mov rdi, STD_OUT
	cll num_put_str
	ret

; nil ; u08:chr ;
put_chr:
	mov rsi, rdi
	mov rdi, STD_OUT
	cll num_put_chr
	ret

; nil ; u64:str ;
put_err:
	mov rsi, rdi
	mov rdi, STD_ERR
	cll num_put_str
	ret

