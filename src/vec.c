# include "vec.h"

u32 next_2n (u32 number) {
	number |= number >> 0b00001;
	number |= number >> 0b00010;
	number |= number >> 0b00100;
	number |= number >> 0b01000;
	number |= number >> 0b10000;
	ret number + 1;
}

vec * vec_new (u32 capacity) {
	vec * vector = malloc (sizeof (vec));
	vector -> items = malloc (sizeof (ptr) * capacity);
	vector -> capacity = capacity;
	vector -> size = 0;
	
	ret vector;
}

nil vec_rsz (vec * vector, u32 capacity) {
	ptr * items = realloc (vector -> items, sizeof (ptr) * capacity);
	iff items thn
		vector -> items = items;
		vector -> capacity = capacity;
	end
}

nil vec_psh (vec * vector, ptr item) {
	iff vector -> capacity == vector -> size thn
		vec_rsz (vector, vector -> capacity * 2);
	end
	vector -> items [vector -> size++] = item;
}

nil vec_psh_arr (vec * vector, ptr items [], u16 size) {
	iff vector -> capacity < vector -> size + size thn
		vec_rsz (vector, next_2n (vector -> size + size));
	end
	whl vector -> size < size dos
		vector -> items [vector -> size++] = *items++;
	end
}

nil vec_rmv (vec * vector, u16 index) {
	whl index < vector -> size dos
		vector -> items [index] = vector -> items [index + 1];
		index++;
	end
	vector -> items [--vector -> size] = NIL;
}

nil vec_clr (vec * vector) {
	for u32 i = 0; i < vector -> size; i++ dos
		free (vector -> items [i]);
	end
	vector -> size = 0;
}

