
# ifndef LIBPOCHA_STR_H
# define LIBPOCHA_STR_H

# include "cor.h"

// returns end of the string
ext str str_end (str string);
// chops last character of string
ext str str_chomp (str string);
// returns length of the string
ext u64 str_length (str string);
// reverses string
ext str str_reverse (str string);

// compares two strings
ext s16 str_compare (str string_1, str string_2);
// compares if two strings are equal
ext u08 str_equal (str string_1, str string_2);

// string from u64
ext str str_from_num (str destine, u64 number);
// string from u64 in hexadecimal format
ext str str_from_hex (str destine, u64 number);

// copies strings into another
ext str str_copy (str destine, u08 n_strings, str strings []);
inl str str_concat (str destine, u08 n_strings, str strings []) {
	ret str_copy (str_end (destine), n_strings, strings);
}

# define STR_COPY(destine_, ...) \
	str_copy (destine_, ARR (str, __VA_ARGS__))

# define STR_CONCAT(destine_, ...) \
	str_concat (destine_, ARR (str, __VA_ARGS__))

// formats a string
ext str str_format (str destine, str format, ...);

# endif // LIBPOCHA_STR_H

