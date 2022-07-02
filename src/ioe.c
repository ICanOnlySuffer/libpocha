# include "../inc/ioe.h"
# undef ret
# include <unistd.h>

nil num_put_str (u64 fd, str string) {
	write (fd, string, str_length (string));
}

nil num_put_chr (u64 fd, chr character) {
	write (fd, &character, 1);
}

