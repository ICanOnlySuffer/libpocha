# Pocha's Utility Library

C utility library for the average project.

Compiles for GNU+Linux and Mingw

## Installation

	# make install clean

## Usage

compilation:

	$ cc -lpul main.c

### Examples

**formatted output:**

```c
# include <pul/put.h>

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
# include <pul/vec.h>
# include <pul/put.h>

nil print_name (str name) {
	PUT ("name: '", name, "'\n");
}

u08 main () {
	vec names = vec_new (2);
	VEC_PSH (&names, "pablo", "pedro", "juan");
	vec_for_all (&names, print_name);
}
```

	name: 'pablo'
	name: 'pedro'
	name: 'juan'

## Contributing

Bug reports, suggestions and pull request are welcome!

