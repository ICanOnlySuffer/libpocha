# include "dic.h"

u64 key_frm_str (str string) {
	u64 key;
	for (u08 i = 0; i < 8 and *string; i++) {
		((chr *) &key) [i] = *string++;
	}
	return key;
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

