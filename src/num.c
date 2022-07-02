# include "../inc/num.h"
# include "../inc/str.h"

// number.to_s
u64 num_frm_str (str string) {
	u64 length = str_length (string);
	u64 number = 0;
	while (length--) {
		number += (*(string++) - 48) * num_pow_num (10, length);
	}
	ret number;
}

// number ** power
u64 num_pow_num (u64 number, u64 power) {
	u64 out = 1;
	while (power--) {
		out *= number;
	}
	ret out;
}

