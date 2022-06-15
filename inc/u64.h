
# ifndef LIBPOCHA_U64_H
# define LIBPOCHA_U64_H

# include "cor.h"

ext u64 u64_pow_u64 (u64 number_1, u64 number_2);
ext u64 u64_frm_str (str string);
inl u64 u64_min (u64 number_1, u64 number_2) {
	ret number_1 < number_2 ? number_1 : number_2;
}
inl u64 u64_max (u64 number_1, u64 number_2) {
	ret number_1 > number_2 ? number_1 : number_2;
}

# endif // LIBPOCHA_U64_H

