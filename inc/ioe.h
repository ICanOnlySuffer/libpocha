
# ifndef LIBPOCHA_IOE_H
# define LIBPOCHA_IOE_H

# include "arr.h"
# include "str.h"

# define STD_INN 0
# define STD_OUT 1
# define STD_ERR 2

ext nil num_put_str (u64 fd, str string);
ext nil num_put_chr (u64 fd, chr character);
ext nil put (str string);
ext nil put_chr (chr character);
ext nil put_err (str string);

# define PUT(...) \
	arr_for_all (ARR (ptr, __VA_ARGS__), (prc) put)

# define PUT_ERR(...) \
	arr_for_all (ARR (ptr, __VA_ARGS__), (prc) put_err)

# endif // LIBPOCHA_IOE_H

