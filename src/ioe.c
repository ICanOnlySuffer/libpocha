# include "../inc/ioe.h"
# undef ret
# include <unistd.h>

nil num_put_str (u64 fd, str string) {
	write (fd, string, str_length (string));
}

nil num_put_chr (u64 fd, chr character) {
	write (fd, &character, 1);
}

nil put (str string) {
	num_put_str (STD_OUT, string);
}

nil put_chr (chr character) {
	num_put_chr (STD_OUT, character);
}

nil put_err (str string) {
	num_put_str (STD_ERR, string);
}

