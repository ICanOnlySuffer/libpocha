
# ifndef LIBPOCHA_NUM_H
# define LIBPOCHA_NUM_H

# include "cor.h"

ext u64 num_from_str (str string);
ext u64 num_pow_num (u64 number_1, u64 number_2);

inl u08 num_equal (u64 number_1, u64 number_2) {
	ret number_1 == number_2;
}

inl u64 num_min (u64 number_1, u64 number_2) {
	ret number_1 < number_2 ? number_1 : number_2;
}
inl u64 num_max (u64 number_1, u64 number_2) {
	ret number_1 > number_2 ? number_1 : number_2;
}

# endif // LIBPOCHA_NUM_H

