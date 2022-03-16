# include "tester.h"

chr tester_buffers [3][32];
str tester_check [] = {
	"  \e[31m[✗] ",
	"  \e[32m[✓] "
};

nil it (str should) {
	PUT_ARR ("\e[32mIt ", should, "\e[0m\n");
}

nil assert_equal_u64 (u64 value_1, u64 value_2) {
	str_frm_u64 (tester_buffers [1], value_1);
	str_frm_u64 (tester_buffers [2], value_2);
	STR_CPY (
		tester_buffers [0],
		tester_buffers [1],
		" == ",
		tester_buffers [2]
	);
	PUT_ARR (
		tester_check [value_1 == value_2],
		tester_buffers [0], "\e[0m\n"
	);
}

nil assert_equal_str (str string_1, str string_2) {
	PUT_ARR (
		tester_check [STR_EQL (string_1, string_2)],
		"\"", string_1, "\" == \"", string_2, "\"\e[0m\n"
	);
}

