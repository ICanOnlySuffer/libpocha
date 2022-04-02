# include <unistd.h>
# include "put.h"

nil fil_put (u64 file, str string) FUN
	write (file, string, str_len (string));
END

nil fil_put_chr (u64 file, chr character) FUN
	write (file, &character, 1);
END

nil fil_put_arr (u64 file, u16 length, str strings []) FUN
	do {
		write (file, *strings, str_len (*strings));
		strings++;
	} while (--length);
END

