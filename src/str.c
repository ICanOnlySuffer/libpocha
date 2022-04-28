# include "str.h"

u64 str_len (str string) {
	u64 len = -1;
	--string;
	do {
		++len;
	} while (*++string);
	return len;
}

nil str_chp (str string) {
	string [str_len (string)] = 0;
}

nil str_rvs (str string) {
	for (u64 i = 0, j = str_len (string) - 1; i < j; i++, j--) {
		chr temp = string [i];
		string [i] = string [j];
		string [j] = temp;
	}
}

s16 str_cmp (str string_1, str string_2) {
	while (*string_1 and *string_1 == *string_2) {
		++string_1;
		++string_2;
	}
	return (s16) *string_1 - (s16) *string_2;
}

nil str_cpy (str buffer, u16 n_strings, str strings []) {
	do {
		while (**strings) {
			*buffer = **strings;
			++*strings;
			++buffer;
		}
		--n_strings;
		++strings;
	} while (n_strings);
	*buffer = 0;
}

nil str_frm_u64 (str buffer, u64 number) {
	str start = buffer;
	do {
		*buffer = 48 + (number % 10);
		++buffer;
	} while (number /= 10);
	*buffer = 0;
	str_rvs (start);
}

