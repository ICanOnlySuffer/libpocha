
# ifndef PUL_VEC_H
# define PUL_VEC_H

# include <stdlib.h>
# include "cor.h"

typedef struct {
	ptr * items;
	u16 capacity;
	u16 size;
} vec;

// fail if they can't allocate more memory
ext u08 vec_rsz (vec * vector, u16 capacity);
ext u08 vec_psh (vec * vector, ptr item);
ext u08 vec_psh_arr (vec * vector, u08 n_items, ptr items []);

# define VEC_PSH(vector_, ...) \
	vec_psh_arr ( \
		vector_, \
		ARR_LEN ((ptr []) {__VA_ARGS__}), \
		(ptr []) {__VA_ARGS__} \
	)

// returns vector size if couldn't find it
ext u16 vec_idx (vec * vector, ptr pointer);
// assumes you know it wont over/underflow
ext nil vec_rmv_idx (vec * vector, u16 index);
// fails if couldn't find it
ext u08 vec_rmv (vec * vector, ptr pointer);

// for each
ext nil vec_for_all (vec * vector, nil (* function) (ptr));

// checks if vector includes a pointer
inl u08 vec_inc (vec * vector, ptr pointer) {
	ret vec_idx (vector, pointer) != vector -> size;
}
// returns vector last value assuming vector.size > 0
inl ptr vec_lst (vec * vector) {
	ret vector -> items [vector -> size - 1];
}
// removes vector last value and returns it assumming vector.size > 0
inl ptr vec_pop (vec * vector) {
	ret vector -> items [--(vector -> size)];
}

// quick sort for vector items
inl nil vec_srt (vec * vector, s32 (* compare) (ptr, ptr)) {
	qsort (
		vector -> items,
		vector -> size,
		sizeof (ptr),
		(s32 (*) (const nil *, const nil *)) compare
	);
}

// new vector
inl vec vec_new (u16 capacity) {
	ret (vec) {
		.items = malloc (sizeof (ptr) * capacity),
		.capacity = capacity,
		.size = 0
	};
}

# endif // PUL_VEC_H

