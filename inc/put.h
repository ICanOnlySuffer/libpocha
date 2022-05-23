
# ifndef PUL_PUT_H
# define PUL_PUT_H

# include "str.h"

# define STD_INN 0
# define STD_OUT 1
# define STD_ERR 2

ext nil fil_put (u64 file, str string);
ext nil fil_put_chr (u64 file, chr character);
ext nil fil_put_arr (u64 file, u16 n_strings, str strings []);
inl nil put (str string) {
	fil_put (STD_OUT, string);
}
inl nil put_err (str string) {
	fil_put (STD_ERR, string);
}
inl nil put_chr (chr character) {
	fil_put_chr (STD_OUT, character);
}
inl nil put_chr_err (chr character) {
	fil_put_chr (STD_ERR, character);
}
inl nil new_lne () {
	put_chr ('\n');
}
inl nil new_lne_err () {
	put_chr_err ('\n');
}

# define FIL_PUT(file_, ...) \
	fil_put_arr ( \
		file_, \
		ARR_LEN ((str []) {__VA_ARGS__}), \
		(str []) {__VA_ARGS__} \
	)

# define PUT(...) \
	FIL_PUT (STD_OUT, __VA_ARGS__)

# define PUT_ERR(...) \
	FIL_PUT (STD_ERR, __VA_ARGS__)

# endif // PUL_PUT_H

