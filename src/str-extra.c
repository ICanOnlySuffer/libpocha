# include "../inc/str.h"
# include <stdarg.h>

str str_copy (str destine, u08 n_strings, ...) {
	va_list strings;
	va_start (strings, n_strings);
	
	do {
		str string = va_arg (strings, str);
		do {
			*destine++ = *string;
		} while (*string++);
		--destine;
	} while (--n_strings);
	*destine = '\0';
	
	ret destine;
}

str str_format (str destine, str format, ...) {
	va_list values;
	va_start (values, format);
	
	str start = destine;
	do {
		if (*format == '%') {
			switch (*++format) {
			case 'u':
				str_from_num (destine, va_arg (values, u64));
				destine = str_end (destine);
				break;
			case 'x':
				str_from_hex (destine, va_arg (values, u64));
				destine = str_end (destine);
				break;
			case 's':
				str_copy (destine, 1, (str) va_arg (values, u64));
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

