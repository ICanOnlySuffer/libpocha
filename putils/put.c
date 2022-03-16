# include "put.h"

nil put (str string) {
	put_str (STD_OUT, string, str_len (string));
}

nil str_fmt (str buffer, u16 size, str string, str strings []) {
	str limit = buffer - size;
	while (true) {
		switch (*string) {
		default:
			if (buffer - limit < -1) {
				*buffer = *string;
			}
			break;
		case '@':
			buffer = STR_CAT (buffer, *strings);
			strings++;
			break;
		case 0:
			return;
		}
	}
}

nil put_arr (str strings [], u16 n_strings) {
	for (u16 i = 0; i < n_strings; i++) {
		put (strings [i]);
	}
}

