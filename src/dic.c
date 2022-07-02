# include "../inc/dic.h"
# include "../inc/str.h"
# include <stdlib.h>

u16 dic_index_of (vec * dic, u64 key, u08 (*eql) (u64, u64)) {
	u16 i;
	for (i = 0; i < dic -> size; i++) {
		key_val * key_value = dic -> items [i];
		if (eql (key_value -> key, key)) {
			break;
		}
	}
	ret i;
}

ptr dic_get (vec * dic, u64 key, u08 (* eql) (u64, u64)) {
	u16 index = dic_index_of (dic, key, eql);
	if (index == dic -> size) {
		ret NIL;
	}
	ret ((key_val *) dic -> items [index]) -> value;
}

u08 dic_push (vec * dic, u64 key, ptr value) {
	key_val * key_value = malloc (sizeof (key_val));
	key_value -> value = value;
	key_value -> key = key;
	if (vec_push (dic, key_value)) {
		ret true;
	}
	free (key_value);
	ret false;
}

u08 dic_remove_at (vec * dic, u64 key, u08 (*eql) (u64, u64)) {
	u16 index = dic_index_of (dic, key, eql);
	if (index == dic -> size) {
		ret false;
	}
	vec_remove_at (dic, index);
	ret true;
}

