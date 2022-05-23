# include "../inc/u64.h"
# include "../inc/vec.h"

// vector.resize capacity
u08 vec_rsz (vec * vector, u16 capacity) {
	ptr * items = realloc (vector -> items, sizeof (ptr) * capacity);
	if (items) {
		vector -> capacity = capacity;
		vector -> items = items;
		ret true;
	}
	ret false;
}

// vector.push value
u08 vec_psh (vec * vector, ptr item) {
	if (vector -> capacity == vector -> size) {
		if (not vec_rsz (vector, vector -> capacity * 2)) {
			ret false;
		}
	}
	vector -> items [vector -> size++] = item;
	ret true;
}

// vector.push *values
u08 vec_psh_arr (vec * vector, u08 n_items, ptr items []) {
	if (vector -> capacity < vector -> size + n_items) {
		u16 new_size = u64_max (n_items, vector -> size) * 2;
		if (not vec_rsz (vector, new_size)) {
			ret false;
		}
	}
	while (vector -> size < n_items) {
		vector -> items [vector -> size++] = *items++;
	}
	ret true;
}

// vector.index value
u16 vec_idx (vec * vector, ptr pointer) {
	u16 i;
	for (i = 0; i < vector -> size; i++) {
		if (vector -> items [i] == pointer) {
			break;
		}
	}
	ret i;
}

// vector.delete_first_at index
nil vec_rmv_idx (vec * vector, u16 index) {
	while (index < vector -> size) {
		vector -> items [index] = vector -> items [index + 1];
		index++;
	}
	vector -> items [--vector -> size] = NIL;
}

// vector.delete_first value
u08 vec_rmv (vec * vector, ptr pointer) {
	u16 index = vec_idx (vector, pointer);
	if (index == vector -> size) {
		ret false;
	}
	vec_rmv_idx (vector, index);
	ret true;
}

// vector.for_each &:proc
nil vec_for_all (vec * vector, prc proc) {
	for (u16 i = 0; i < vector -> size; i++) {
		proc (vector -> items [i]);
	}
}

