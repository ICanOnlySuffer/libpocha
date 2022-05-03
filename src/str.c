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

nil str_cpy (str destine, str string) {
	do {
		*destine++ = *string;
	} while (*string++);
	*destine = 0;
}

nil str_cpy_arr (str destine, u08 n_strings, str strings []) {
	do {
		do {
			*destine++ = **strings;
		} while (*(*strings)++);
		--destine;
		++strings;
	} while (--n_strings);
	*destine = 0;
}

nil str_frm_u64 (str destine, u64 number) {
	str start = destine;
	do {
		*destine = 48 + (number % 10);
		++destine;
	} while (number /= 10);
	*destine = 0;
	str_rvs (start);
}

nil str_frm_fmt (str destine, str format, ptr pointers []) {
	chr buffer [21];
	u16 index = 0;
	u16 size;
	do {
		if (*format == '%') {
			switch (*++format) {	
			case 'u':
				str_frm_u64 (buffer, *(u64 *) *pointers++);
				size = str_len (buffer);
				str_cpy (destine + index, buffer);
				index += size;
				break;
			case 's':
				size = str_len ((str) *pointers);
				str_cpy (destine + index, (str) *pointers++);
				index += size;
				break;
			case '%':
				destine [index++] = '%';
				break;
			}
		} else {
			destine [index++] = *format;
		}
	} while (*++format);
	destine [index] = 0;
}



