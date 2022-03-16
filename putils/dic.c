# include "dic.h"

par * par_new (str key, nil * value) {
	par * pair = malloc (sizeof (par));
	pair -> key = key;
	pair -> value = value;
	
	return pair;
}

str dic_get (vec * dictionary, str key) {
	for (u16 i = 0; i < dictionary -> size; i++) {
		par * pair = dictionary -> items [i];
		if (STR_EQL (pair -> key, key)) {
			return pair -> value;
		}
	}
	
	return NIL;
}

