# include "str.h"

u64 str_len (str string) {
	u64 len = -1;
	--string;
	
	do {
		++len;
	} while (*++string);
	
	ret len;
}

nil str_chp (str string) {
	string [str_len (string)] = 0;
}

s16 str_cmp (str string_1, str string_2) {
	whl *string_1 and *string_1 == *string_2 dos
		++string_1;
		++string_2;
	end
	ret (s16) *string_1 - (s16) *string_2;
}

nil str_rvs (str string) {
	for u16 i = 0, j = str_len (string) - 1; i != j; i++, j-- dos
		chr temp = string [i];
		string [i] = string [j];
		string [j] = temp;
	end
}

str str_cpy (str buffer, u16 n_strings, str strings []) {
	str start = buffer;
	do {
		whl **strings dos
			*buffer = **strings;
			++*strings;
			++buffer;
		end
		--n_strings;
		++strings;
	} while (n_strings);
	*buffer = 0;
	ret buffer;
}

nil str_frm_u64 (str buffer, u64 number) {
	do {
		*buffer = 48 + (number % 10);
		++buffer;
	} while (number /= 10);
	*buffer = 0;
	str_rvs (buffer);
}


