# include "num.h"

u64 u64_pow_u64 (u64 number, u64 power) {
	u64 out = 1;
	while (power--) {
		out *= number;
	}
	return out;
}

u64 u64_frm_str (str string) {
	u64 length = str_len (string);
	u64 number = 0;
	while (length--) {
		number += (*(string++) - 48) * u64_pow_u64 (10, length);
	}
	return number;
}

