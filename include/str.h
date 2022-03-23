
# ifndef PUTILS_STR_H
# define PUTILS_STR_H

# include "cor.h"

ext u64 str_len (str string);
ext nil str_chp (str string);
ext nil str_rvs (str string);
ext s16 str_cmp (str string_1, str string_2);
ext nil str_cpy (str buffer, u16 n_strings, str strings []);
ext nil str_frm_u64 (str buffer, u64 number);

# define STR_CPY(buffer_, ...) \
	str_cpy ( \
		buffer_, \
		sizeof ((str []) {__VA_ARGS__}) / sizeof (str), \
		(str []) {__VA_ARGS__} \
	)

# define STR_CAT(buffer_, ...) \
	STR_CPY (buffer_ + str_len (buffer_), __VA_ARGS__)

# define STR_EQL(string_1_, string_2_) \
	(not str_cmp (string_1_, string_2_))

# endif // PUTILS_STR_H

