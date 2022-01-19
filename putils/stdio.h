# ifndef _PUTILS_STDIO_
# define _PUTILS_STDIO_ 1

# include <stdio.h>
# include "types.h"

nil pprint_ (u16 size, str strings []) {
	for (u16 i = 0; i < size; i++) {
		while (*strings [i]) {
			putchar (*strings [i]++);
		}
	}
}

# define pprint(...)                                    \
	pprint_ (                                           \
		sizeof ((str []) {__VA_ARGS__}) / sizeof (str), \
		(str []) {__VA_ARGS__}                          \
	)

# define pputs(...) \
	pprint (__VA_ARGS__, "\n")

# endif // _PUTILS_STDIO_







