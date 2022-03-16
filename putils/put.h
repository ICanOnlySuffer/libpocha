
# ifndef _PUTILS_PUT_
# define _PUTILS_PUT_

# include "cor.h"
# include "str.h"
# include "ioe.h"

ext nil put (str string);
ext nil put_arr (u16 n_strings, str strings []);

# define PUT_ARR(...)                                   \
	put_arr (                                           \
		sizeof ((str []) {__VA_ARGS__}) / sizeof (str), \
		(str []) {__VA_ARGS__}                          \
	)

# endif // _PUTILS_PUT_

