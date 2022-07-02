
# ifndef LIBPOCHA_PUT_H
# define LIBPOCHA_PUT_H

# include "str.h"

# define STD_INN 0
# define STD_OUT 1
# define STD_ERR 2

ext nil num_put_str (u64 fd, str string);
ext nil num_put_chr (u64 fd, chr character);

inl nil put (str string) {
	num_put_str (STD_OUT, string);
}
inl nil put_chr (chr character) {
	num_put_chr (STD_OUT, character);
}
inl nil put_err (str string) {
	num_put_str (STD_ERR, string);
}
inl nil put_lne () {
	put_chr ('\n');
}

# endif // LIBPOCHA_PUT_H

