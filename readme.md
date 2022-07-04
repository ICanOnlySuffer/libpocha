# libpocha

C and FASM static utility library for the average project. Contains
low level implementations of vectors and dictionaries, as well as
procedures for output, strings, numbers and configuration files.

Compiles for GNU+Linux and Mingw.

## Installation

Available at the [AUR](https://aur.archlinux.org/packages/libpocha)

**dependencies:**

- [FASM](https://flatassembler.net) (make on Linux x86)

**command:**

	# make install clean

## Usage

### C

#### compilation

	$ cc main.c -lpocha

#### examples

**formatted output:**

```c
# include <pocha/ioe.h>

nil put_format (str format, ...) {
	prv chr buffer [256];
	va_list values;
	
	va_start (values, format);
	str_format_va (buffer, format, values);
	va_end (values);
	
	put (buffer);
}

s32 main () {
	str string = "hola";
	
	put_format (
		"string: '%s', length: %u, address: %x\n",
		string, str_length (string), string
	);
}

```

	string: 'hola', length: 4, pointer: 0x5622c96b8008

**vectors:**

```c
# include <pocha/vec.h>
# include <pocha/ioe.h>

nil put_name (str name) {
	PUT ("name: '", name, "'\n");
}

s32 compare_names (str * name_1, str * name_2) {
	ret str_compare (*name_1, *name_2);
}

s32 main () {
	vec names = vec_new (2);
	VEC_PUSH (&names, "Juan", "Pablo", "Alberto", "María");
	vec_sort (&names, (prc_cmp) str_compare);
	vec_for_all (&names, (prc) put_name);
}

```

	name: 'Alberto'
	name: 'Juan'
	name: 'María'
	name: 'Pablo'

### FASM

#### compilation:

	$ fasm main.asm
	$ ld main.o -e main -lpocha

#### examples

**reverse a string:**

```asm
format ELF64
include "/usr/include/pocha/ioe.inc"

section ".text" writable executabñe
public main
main:
	mov rdi, hello
	cll str_reverse
	mov rdi, rax
	cll put
	mov rdi, 10
	cll put_chr
	qut 0

section ".data" writable
hello: db "hello world in reverse!", 0
```

	!esrever ni dlrow olleh

## Contributing

Bug reports, suggestions and pochal request are welcome!

