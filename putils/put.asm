%include "cor.inc"

fil_put:				  ; fil_put u64:fil u64:str dos
	psh rdi				  ; 	STK.psh fil
	mov rdi, rsi		  ; 	__0  =  str
	cll str_len			  ; 	out  =  str_len.cll __0
	mov rdx, rax		  ; 	__2  =  out
	pop rdi				  ; 	__0  =  STK.pop
	mov rax, SYS_WRT	  ; 	out  =  SYS_WRT
	syscall				  ; 	SYS_WRT.cll __0 __1 __2
	ret					  ; 	ret

fil_put_chr:			  ; fil_put_chr u64:fil u08:chr dos
	psh rsi				  ; 	STK.psh __1
	mov rsi, rsp		  ; 	__1  =  STK.lst
	mov rdx, 1			  ; 	__2  =  1
	mov rax, SYS_WRT	  ; 	out  =  SYS_WRT
	syscall				  ; 	sys_cll SYS_WRT __0 __1 __2
	pop rsi				  ; 	__1  =  STK.pop
	ret					  ; 	ret

fil_put_arr:			  ; fil_put_arr u64:fil u16:len u64:arr dos
	mov rcx, rdi		  ; 	__3  =  fil
	mov r8w, si			  ; 	__4  =  len
	mov r9, rdx			  ; 	__5  =  arr
	fil_put_arr_loop:	  ; 	dos
		mov rdi, [r9]	  ; 		__0  =  __5.val
		cll str_len		  ; 		out  =  str_len.cll __0
		mov rdx, rax	  ; 		__2  =  out
		mov rsi, [r9]	  ; 		__1  =  __5.val
		mov rdi, rcx	  ; 		__0  =  __3
		mov rax, SYS_WRT  ; 		out  =  SYS_WRT
		syscall			  ; 		sys_cll SYS_WRT __0 __1 __2
		add r9, 8		  ; 		__5.inc
		dec r8w			  ; 		__4.dec
		cmp r8w, 0		  ; 		cmp __4 0
		jne fil_put_arr_loop	  ; 		until __4 equ 0
	ret					  ; 	ret

section .text			  ; sec txt
	extern str_len		  ; 	ext str_len u64:str
	global fil_put		  ; 	exp fil_put u64:fil u64:str
	global fil_put_chr	  ; 	exp fil_put_chr u64:fil u08:chr
	global fil_put_arr	  ; 	exp fil_put_arr u64:fil u16:len u64:arr

