# include "tester.h"

chr tester_buffers [3][32];
str tester_check [] = {
	"  \e[31m[✗] ",
	"  \e[32m[✓] "
};

nil it (str should) fun
	PUT_ARR ("\e[32mIt ", should, "\e[0m\n");
end

u08 eql_u64 (ptr num_1, ptr num_2) fun
	str_frm_u64 (tester_buffers [1], *(u64 *) num_1);
	str_frm_u64 (tester_buffers [2], *(u64 *) num_2);
	STR_CPY (
		tester_buffers [0],
		tester_buffers [1],
		" == ",
		tester_buffers [2]
	);
	ret *(u64 *) num_1 == *(u64 *) num_2;
end

u08 eql_u08 (ptr u08_1, ptr u08_2) fun
	u64 u64_1 = (u64) *(u08 *) u08_1;
	u64 u64_2 = (u64) *(u08 *) u08_2;
	ret eql_u64 (&u64_1, &u64_2);
end

u08 eql_str (ptr str_1, ptr str_2) fun
	STR_CPY (
		tester_buffers [0],
		"\"", *(str *) str_1, "\" == \"", *(str *) str_2, "\""
	);
	ret STR_EQL (*(str *) str_1, *(str *) str_2);
end

nil assert (u08 (* fnc) (ptr, ptr), ptr val_1, ptr val_2) fun
	PUT_ARR (
		tester_check [fnc (val_1, val_2)],
		tester_buffers [0],
		"\e[0m\n"
	);
end

