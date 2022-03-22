# include "dic.h"

k_v * k_v_new (str key, ptr value) {
	k_v * key_value = malloc (sizeof (k_v));
	key_value -> key = key;
	key_value -> value = value;
	
	ret key_value;
}

str dic_get (vec * dictionary, str key) {
	for u16 i = 0; i < dictionary -> size; i++ dos
		k_v * key_value = dictionary -> items [i];
		iff STR_EQL (key_value -> key, key) thn
			ret key_value -> value;
		}
	}
	
	ret NIL;
}

