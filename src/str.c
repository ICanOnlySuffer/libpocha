# include "../inc/str.h"

str str_end (str string) {
	--string;
	do {
		++string;
	} while (*string);
	ret string;
}

u64 str_len (str string) {
	ret str_end (string) - string;
}

str str_chp (str string) {
	string [str_len (string) - 1] = 0;
	ret string;
}

str str_rvs (str string) {
	for (u64 i = 0, j = str_len (string) - 1; i < j; i++, j--) {
		chr temp = string [i];
		string [i] = string [j];
		string [j] = temp;
	}
	ret string;
}

s16 str_cmp (str string_1, str string_2) {
	while (*string_1 and *string_1 == *string_2) {
		++string_1;
		++string_2;
	}
	ret (s16) *string_1 - (s16) *string_2;
}

str str_cpy (str destine, str string) {
	do {
		*destine++ = *string;
	} while (*string++);
	*destine = 0;
	ret destine;
}

str str_cpy_arr (str destine, u08 n_strings, str strings []) {
	do {
		do {
			*destine++ = **strings;
		} while (*(*strings)++);
		--destine;
		++strings;
	} while (--n_strings);
	*destine = 0;
	ret destine;
}

str str_frm_u64 (str destine, u64 number) {
	str start = destine;
	do {
		*destine = 48 + (number % 10);
		++destine;
	} while (number /= 10);
	*destine = 0;
	ret str_rvs (start);
}

str str_frm_hex (str destine, u64 number) {
	str start = destine;
	do {
		u08 remainder = number % 16;
		*destine = (remainder < 10 ? 48 : 87) + remainder;
		++destine;
	} while (number /= 16);
	*destine++ = 'x';
	*destine++ = '0';
	*destine = 0;
	ret str_rvs (start);
}

str str_frm_fmt (str destine, str format, u64 values []) {
	str start = destine;
	do {
		if (*format == '%') {
			switch (*++format) {
			case 'u':
				str_frm_u64 (destine, *values++);
				destine = str_end (destine);
				break;
			case 'x':
				str_frm_hex (destine, *values++);
				destine = str_end (destine);
				break;
			case 's':
				str_cpy (destine, (str) *values++);
				destine = str_end (destine);
				break;
			case '%':
				*destine++ = '%';
				break;
			}
		} else {
			*destine++ = *format;
		}
	} while (*++format);
	*destine = 0;
	
	ret start;
}

