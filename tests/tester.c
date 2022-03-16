# include "tester.h"

chr tester_buffers [3][32];
str tester_check [] = {
	"  \e[31m[✗] ",
	"  \e[32m[✓] "
};

nil it (str should) {
	PUT_ARR ("\e[32mIt ", should, "\e[0m\n");
}

u08 eql_u64 (ptr num_1, ptr num_2) {
	str_frm_u64 (tester_buffers [1], *(u64 *) num_1);
	str_frm_u64 (tester_buffers [2], *(u64 *) num_2);
	STR_CPY (
		tester_buffers [0],
		tester_buffers [1],
		" == ",
		tester_buffers [2]
	);
	ret *(u64 *) num_1 == *(u64 *) num_2;
}

u08 eql_u08 (ptr u08_1, ptr u08_2) {
	u64 u64_1 = (u64) *(u08 *) u08_1;
	u64 u64_2 = (u64) *(u08 *) u08_2;
	ret eql_u64 (&u64_1, &u64_2);
}

u08 eql_str (ptr str_1, ptr str_2) {
	STR_CPY (
		tester_buffers [0],
		"\"", *(str *) str_1, "\" == \"", *(str *) str_2, "\""
	);
	ret STR_EQL (*(str *) str_1, *(str *) str_2);
}

nil assert (u08 (* fun) (ptr, ptr), ptr val_1, ptr val_2) {
	put (tester_check [fun (val_1, val_2)]);
	put (tester_buffers [0]);
	put ("\e[0m\n");
}

