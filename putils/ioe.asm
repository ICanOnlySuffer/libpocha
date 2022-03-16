%include "cor.inc"

get_str:			  ; nil get_str u64:bff u64:len dos
	mov rax, SYS_RED  ; 	u64 sys  =  SYS_RED
	mov rdx, rsi	  ; 	u64 len  =  len
	mov rsi, rdi	  ; 	u64 str  =  bff
	mov rdi, STD_INN  ; 	u64 rdi  =  STD_INN
	syscall			  ; 	sys_cll SYS_RED rdi rsi rdx
	ret				  ; 	ret

put_str:			  ; nil put_str u64:str u64:len dos
	mov rax, SYS_WRT  ; 	u64 sys  =  SYS_WRT
	mov rsi, rdi	  ; 	u64 str  =  str
	mov rdi, STD_OUT  ; 	u64 fil  =  STD_OUT
	syscall			  ; 	sys_cll SYS_WRT STD_OUT str len
	ret				  ; 	ret

put_chr:			  ; nil put_chr u08:chr dos
	psh rdi			  ; 	STK.psh chr
	mov rsi, rsp	  ; 	u64 str  =  STK.ptr
	mov rdi, STD_OUT  ; 	u64 fil  =  STD_OUT
	mov rax, SYS_WRT  ; 	u64 sys  =  SYS_WRT
	mov rdx, 1		  ; 	u64 len  =  1
	syscall			  ; 	sys_cll SYS_WRT STD_OUT STK.ptr rdx
	pop rdi			  ; 	chr  =  STK.pop
	ret				  ; 	ret

put_wrn:			  ; nil put_wrn u64:str dos

section .text		  ; sec txt
	global get_str	  ; 	exp get_str
	global put_str	  ; 	exp put_str
	global put_chr	  ; 	exp put_chr

