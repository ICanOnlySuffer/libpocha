# include "put.h"

nil put (str string) {
	put_str (string, str_len (string));
}

nil put_arr (u16 n_strings, str strings []) {
	for (u16 i = 0; i < n_strings; i++) {
		put (strings [i]);
	}
}

