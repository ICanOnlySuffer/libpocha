# include "../inc/num.h"
# include "../inc/vec.h"

// vector.push value
u08 vec_push (vec * vector, ptr item) {
	if (vector -> capacity == vector -> size) {
		if (not vec_resize (vector, vector -> capacity * 2)) {
			ret false;
		}
	}
	vector -> items [vector -> size++] = item;
	ret true;
}

// vector.push values...
u08 vec_push_arr (vec * vector, u16 n_items, ptr items []) {
	if (vector -> capacity < vector -> size + n_items) {
		u16 new_size = num_max (n_items, vector -> size) * 2;
		if (not vec_resize (vector, new_size)) {
			ret false;
		}
	}
	do {
		vector -> items [vector -> size++] = *items++;
	} while (vector -> size < n_items);
	
	ret true;
}

// vector.resize capacity
u08 vec_resize (vec * vector, u16 capacity) {
	ptr * items = realloc (vector -> items, sizeof (ptr) * capacity);
	if (items) {
		vector -> capacity = capacity;
		vector -> items = items;
		ret true;
	}
	ret false;
}

// vector.index value
u16 vec_index_of (vec * vector, ptr pointer) {
	u16 i;
	for (i = 0; i < vector -> size; i++) {
		if (vector -> items [i] == pointer) {
			break;
		}
	}
	ret i;
}

// vector.delete_first_at index
nil vec_remove_at (vec * vector, u16 index) {
	while (index < vector -> size) {
		vector -> items [index] = vector -> items [index + 1];
		index++;
	}
	vector -> items [--vector -> size] = NIL;
}

// vector.delete_first value
u08 vec_remove (vec * vector, ptr pointer) {
	u16 index = vec_index_of (vector, pointer);
	if (index == vector -> size) {
		ret false;
	}
	vec_remove_at (vector, index);
	ret true;
}

// vector.for_each &:proc
nil vec_for_all (vec * vector, prc proc) {
	for (u16 i = 0; i < vector -> size; i++) {
		proc (vector -> items [i]);
	}
}

