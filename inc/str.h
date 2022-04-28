
# ifndef PUL_STR_H
# define PUL_STR_H

# include "cor.h"

extern u64 str_len (str string);
extern nil str_chp (str string);
extern nil str_rvs (str string);
extern s16 str_cmp (str string_1, str string_2);
extern nil str_cpy (str buffer, u16 n_strings, str strings []);
extern nil str_frm_u64 (str buffer, u64 number);
stainl nil str_cat (str buffer, u16 n_strings, str strings []) {
	str_cpy (buffer + str_len (buffer), n_strings, strings);
}
stainl u08 str_eql (str string_1, str string_2) {
	return not str_cmp (string_1, string_2);
}

# define STR_CPY(buffer_, ...) \
	str_cpy ( \
		buffer_, \
		sizeof ((str []) {__VA_ARGS__}) / sizeof (str), \
		(str []) {__VA_ARGS__} \
	)

# define STR_CAT(buffer_, ...) \
	STR_CPY (buffer_ + str_len (buffer_), __VA_ARGS__)

# endif // PUL_STR_H

