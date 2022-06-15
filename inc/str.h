
# ifndef LIBPOCHA_STR_H
# define LIBPOCHA_STR_H

# include "cor.h"

// returns end of the string
ext str str_end (str string);
// returns length of the string
ext u64 str_len (str string);
// chops last character of string
ext str str_chp (str string);
// reverses string
ext str str_rvs (str string);

// compares two strings
ext s16 str_cmp (str string_1, str string_2);
// compares if two strings are equal
inl u08 str_eql (str string_1, str string_2) {
	ret not str_cmp (string_1, string_2);
}

// string from u64
ext str str_frm_u64 (str destine, u64 number);
// string from u64 in hexadecimal format
ext str str_frm_hex (str destine, u64 number);

// copies a string into another
ext str str_cpy (str destine, str string);
// copies an array of strings into another
ext str str_cpy_arr (str destine, u08 n_strings, str strings []);

# define STR_CPY(destine_, ...) \
	str_cpy_arr ( \
		destine_, \
		ARR_LEN ((str []) {__VA_ARGS__}), \
		(str []) {__VA_ARGS__} \
	)

// concatenates a string to another
inl str str_cat (str destine, str string) {
	ret str_cpy (destine + str_len (destine), string);
}
// concatenates an array of strings to another
inl str str_cat_arr (str destine, u08 n_strings, str strings []) {
	ret str_cpy_arr (destine + str_len (destine), n_strings, strings);
}

# define STR_CAT(destine_, ...) \
	STR_CPY (destine_ + str_len (destine_), __VA_ARGS__)

// formats a string
ext str str_frm_fmt (str destine, str format, u64 values []);
# define STR_FRM_FMT(destine_, format_, ...) \
	str_frm_fmt (destine_, format_, (u64 []) {__VA_ARGS__})

# endif // LIBPOCHA_STR_H

