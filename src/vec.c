# include "../inc/vec.h"

nil vec_rsz (vec * vector, u16 capacity) {
	ptr * items = realloc (vector -> items, sizeof (ptr) * capacity);
	if (items) {
		vector -> capacity = capacity;
		vector -> items = items;
	}
}

nil vec_psh (vec * vector, ptr item) {
	if (vector -> capacity == vector -> size) {
		vec_rsz (vector, vector -> capacity * 2);
	}
	vector -> items [vector -> size++] = item;
}

nil vec_psh_arr (vec * vector, u08 n_items, ptr items []) {
	if (vector -> capacity < vector -> size + n_items) {
		vec_rsz (vector, vector -> size * 2);
	}
	while (vector -> size < n_items) {
		vector -> items [vector -> size++] = *items++;
	}
}

nil vec_rmv_idx (vec * vector, u16 index) {
	while (index < vector -> size) {
		vector -> items [index] = vector -> items [index + 1];
		index++;
	}
	vector -> items [--vector -> size] = NIL;
}

u16 vec_idx (vec * vector, ptr pointer) {
	u16 i;
	for (i = 0; i < vector -> size; i++) {
		if (vector -> items [i] == pointer) {
			break;
		}
	}
	return i;
}

nil vec_for_all (vec * vector, nil (* function) (ptr)) {
	for (u16 i = 0; i < vector -> size; i++) {
		function (vector -> items [i]);
	}
}

vec * vec_new (u16 capacity) {
	vec * vector = malloc (sizeof (vec));
	vector -> items = malloc (sizeof (ptr) * capacity);
	vector -> capacity = capacity;
	vector -> size = 0;
	return vector;
}

