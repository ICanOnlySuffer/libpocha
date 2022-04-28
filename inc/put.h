
# ifndef PUL_PUT_H
# define PUL_PUT_H

# include "str.h"

# define STD_INN 0
# define STD_OUT 1
# define STD_ERR 2

extern nil fil_put (u64 file, str string);
extern nil fil_put_chr (u64 file, chr character);
extern nil fil_put_arr (u64 file, u16 n_strings, str strings []);
stainl nil put (str string) {
	fil_put (STD_OUT, string);
}
stainl nil put_err (str string) {
	fil_put (STD_ERR, string);
}
stainl nil put_chr (chr character) {
	fil_put_chr (STD_OUT, character);
}
stainl nil put_chr_err (chr character) {
	fil_put_chr (STD_ERR, character);
}
stainl nil new_lne () {
	put_chr ('\n');
}
stainl nil new_lne_err () {
	put_chr_err ('\n');
}

# define FIL_PUT_ARR(file_, ...) \
	fil_put_arr ( \
		file_, \
		sizeof ((str []) {__VA_ARGS__}) / sizeof (str), \
		(str []) {__VA_ARGS__} \
	)

# define PUT_ARR(...) \
	FIL_PUT_ARR (STD_OUT, __VA_ARGS__)

# define PUT_ERR_ARR(...) \
	FIL_PUT_ARR (STD_ERR, __VA_ARGS__)

# endif // PUL_PUT_H

