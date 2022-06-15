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

**compilation:**

	$ cc main.c -lpocha

### Examples

**formatted output:**

```c
# include <pocha/put.h>

chr BUFFER [256];

# define put_fmt(format_, ...) \
	put (STR_FRM_FMT (BUFFER, format_, __VA_ARGS__))

u08 main () {
	str string = "hola";
	put_fmt (
		"string: %s, length: %u, pointer: %x\n",
		(u64) string, str_len (string), (u64) string
	);
}
```

	string: 'hola', length: 4, pointer: 0x55a274c68006

**vectors:**

```c
# include <pocha/vec.h>
# include <pocha/put.h>

nil print_name (ptr name) {
	PUT ("name: '", (str) name, "'\n");
}

u08 main () {
	vec names = vec_new (2);
	VEC_PSH (&names, "Juan", "Pablo", "Alberto", "María");
	vec_srt (&names, compare_name);
	vec_for_all (&names, print_name);
}
```

	name: 'Alberto'
	name: 'Juan'
	name: 'María'
	name: 'Pablo'

## Contributing

Bug reports, suggestions and pochal request are welcome!

