# include "vec.h"

vec * vec_new (u32 capacity) {
	vec * vector = malloc (sizeof (vec));
	vector -> items = malloc (sizeof (ptr) * capacity);
	vector -> capacity = capacity;
	vector -> size = 0;
	ret vector;
}

nil vec_rsz (vec * vector, u32 capacity) {
	ptr * items = realloc (vector -> items, sizeof (ptr) * capacity);
	if (items) {
		vector -> items = items;
		vector -> capacity = capacity;
	}
}

nil vec_psh (vec * vector, ptr item) {
	if (vector -> capacity == vector -> size) {
		vec_rsz (vector, vector -> capacity * 2);
	}
	vector -> items [vector -> size++] = item;
}

nil vec_psh_arr (vec * vector, ptr items [], u16 size) {
	if (vector -> capacity < vector -> size + size) {
		vec_rsz (vector, vector -> size * 2);
	}
	while (vector -> size < size) {
		vector -> items [vector -> size++] = *items++;
	}
}

nil vec_rmv (vec * vector, u16 index) {
	while (index < vector -> size) {
		vector -> items [index] = vector -> items [index + 1];
		index++;
	}
	vector -> items [--vector -> size] = NIL;
}

nil vec_clr (vec * vector) {
	for (u32 i = 0; i < vector -> size; i++) {
		free (vector -> items [i]);
	}
	vector -> size = 0;
}

