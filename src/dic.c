# include "../inc/dic.h"

key_val * key_val_new (u64 key, ptr value) {
	key_val * key_value = malloc (sizeof (key_val));
	key_value -> value = value;
	key_value -> key = key;
	return key_value;
}

ptr dic_get (vec * dictionary, u64 key) {
	for (u16 i = 0; i < dictionary -> size; i++) {
		key_val * key_value = dictionary -> items [i];
		if (key_value -> key == key) {
			return key_value -> value;
		}
	}
	return NIL;
}

ptr dic_get_wth_str (vec * dictionary, str key) {
	for (u16 i = 0; i < dictionary -> size; i++) {
		key_val * key_value = dictionary -> items [i];
		if (str_eql ((str) key_value -> key, key)) {
			return key_value -> value;
		}
	}
	return NIL;
}

