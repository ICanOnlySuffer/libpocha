# include <unistd.h>
# include "put.h"

nil fil_put (u64 file, str string) fun
	write (file, string, str_len (string));
end

nil fil_put_chr (u64 file, chr character) fun
	write (file, &character, 1);
end

nil fil_put_arr (u64 file, u16 length, str strings []) fun
	do {
		write (file, *strings, str_len (*strings));
		strings++;
	} while (--length);
end

