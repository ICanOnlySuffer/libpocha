# include "../inc/str.h"

str str_end (str string) {
	--string;
	do {
		++string;
	} while (*string);
	ret string;
}

str str_chomp (str string) {
	string [str_length (string) - 1] = 0;
	ret string;
}

u64 str_length (str string) {
	ret str_end (string) - string;
}

str str_reverse (str string) {
	for (u64 i = 0, j = str_length (string) - 1; i < j; i++, j--) {
		chr temp = string [i];
		string [i] = string [j];
		string [j] = temp;
	}
	ret string;
}

s16 str_compare (str string_1, str string_2) {
	while (*string_1 and *string_1 == *string_2) {
		++string_1;
		++string_2;
	}
	ret (s16) *string_1 - (s16) *string_2;
}

str str_from_num (str destine, u64 number) {
	str start = destine;
	do {
		*destine = 48 + (number % 10);
		++destine;
	} while (number /= 10);
	*destine = 0;
	ret str_reverse (start);
}

str str_frm_hex (str destine, u64 number) {
	str start = destine;
	do {
		u08 remainder = number % 16;
		*destine = (remainder < 10 ? 48 : 87) + remainder;
		++destine;
	} while (number /= 16);
	*destine++ = 'x';
	*destine++ = '0';
	*destine = '\0';
	ret str_reverse (start);
}

