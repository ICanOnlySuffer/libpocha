# include "../inc/dic.h"
# include "../inc/str.h"

u16 dic_idx (vec * dictionary, u64 key) {
	u16 i;
	for (i = 0; i < dictionary -> size; i++) {
		key_val * key_value = dictionary -> items [i];
		if (key_value -> key == key) {
			break;
		}
	}
	ret i;
}

u16 dic_str_idx (vec * dictionary, str key) {
	u16 i;
	for (i = 0; i < dictionary -> size; i++) {
		key_val * key_value = dictionary -> items [i];
		if (str_eql ((str) key_value -> key, key)) {
			break;
		}
	}
	ret i;
}

ptr dic_get (vec * dictionary, u64 key) {
	u16 index = dic_idx (dictionary, key);
	if (index == dictionary -> size) {
		ret NIL;
	}
	ret ((key_val *) dictionary -> items [index]) -> value;
}

ptr dic_str_get (vec * dictionary, str key) {
	u16 index = dic_str_idx (dictionary, key);
	if (index == dictionary -> size) {
		ret NIL;
	}
	ret ((key_val *) dictionary -> items [index]) -> value;
}

u08 dic_psh (vec * dictionary, u64 key, ptr value) {
	key_val * key_value = malloc (sizeof (key_val));
	key_value -> value = value;
	key_value -> key = key;
	if (vec_psh (dictionary, key_value)) {
		ret true;
	}
	free (key_value);
	ret false;
}

u08 dic_rmv (vec * dictionary, u64 key) {
	u16 index = dic_idx (dictionary, key);
	if (index == dictionary -> size) {
		ret false;
	}
	vec_rmv_idx (dictionary, index);
	ret true;
}

