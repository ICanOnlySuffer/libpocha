
# ifndef PUL_STR_H
# define PUL_STR_H

# include "cor.h"

ext str str_end (str string);
ext u64 str_len (str string);
ext nil str_chp (str string);
ext nil str_rvs (str string);
ext s16 str_cmp (str string_1, str string_2);
ext nil str_frm_u64 (str destine, u64 number);

ext nil str_cpy (str destine, str string);
inl nil str_cat (str destine, str string) {
	str_cpy (destine + str_len (destine), string);
}

ext nil str_cpy_arr (str destine, u08 n_strings, str strings []);
inl nil str_cat_arr (str destine, u08 n_strings, str strings []) {
	str_cpy_arr (destine + str_len (destine), n_strings, strings);
}
inl u08 str_eql (str string_1, str string_2) {
	return not str_cmp (string_1, string_2);
}

ext nil str_frm_fmt (str destine, str format, u64 pointers []);

# define STR_CPY(destine_, ...) \
	str_cpy_arr ( \
		destine_, \
		ARR_LEN (((str []) {__VA_ARGS__})), \
		(str []) {__VA_ARGS__} \
	)

# define STR_CAT(destine_, ...) \
	STR_CPY (destine_ + str_len (destine_), __VA_ARGS__)

# define STR_FRM_FMT(destine_, format_, ...) \
	str_frm_fmt (destine_, format_, (u64 []) {__VA_ARGS__})

# endif // PUL_STR_H

