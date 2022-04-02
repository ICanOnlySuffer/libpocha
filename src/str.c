# include "str.h"

u64 str_len (str string) FUN
	u64 len = -1;
	--string;
	
	do {
		++len;
	} while (*++string);
	
	ret len;
END

nil str_chp (str string) FUN
	string [str_len (string)] = 0;
END

s16 str_cmp (str string_1, str string_2) FUN
	WHL *string_1 and *string_1 == *string_2 DOS
		++string_1;
		++string_2;
	END
	ret (s16) *string_1 - (s16) *string_2;
END

nil str_rvs (str string) FUN
	FOR u64 i = 0, j = str_len (string) - 1; i < j; i++, j-- DOS
		chr temp = string [i];
		string [i] = string [j];
		string [j] = temp;
	END
END

nil str_cpy (str buffer, u16 n_strings, str strings []) FUN
	do {
		WHL **strings THN
			*buffer = **strings;
			++*strings;
			++buffer;
		END
		--n_strings;
		++strings;
	} while (n_strings);
	*buffer = 0;
END

nil str_frm_u64 (str buffer, u64 number) FUN
	str start = buffer;
	do {
		*buffer = 48 + (number % 10);
		++buffer;
	} while (number /= 10);
	*buffer = 0;
	str_rvs (start);
END

