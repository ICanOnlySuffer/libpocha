# include "../inc/str.h"
# include <stdarg.h>

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
				STR_COPY (destine, va_arg (values, str));
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

