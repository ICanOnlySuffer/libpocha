
# ifndef LIBPOCHA_VEC_H
# define LIBPOCHA_VEC_H

# include <stdlib.h>
# include "cor.h"

typedef struct {
	ptr * items;
	u16 capacity;
	u16 size;
} vec;

// fails if can't allocate more memory
ext u08 vec_push (vec * vector, ptr item);

// fails if can't allocate more memory
ext u08 vec_push_arr (vec * vector, u16 n_items, ptr items []);

# define VEC_PUSH(vector_, ...) \
	vec_push_arr (vector_, ARR (ptr, __VA_ARGS__))

// fails if can't allocate more memory
ext u08 vec_resize (vec * vector, u16 capacity);

// returns vector size if couldn't find it
ext u16 vec_index_of (vec * vector, ptr pointer);

// assumes you know it wont over/underflow
ext nil vec_remove_at (vec * vector, u16 index);

// fails if couldn't find it
ext u08 vec_remove (vec * vector, ptr pointer);

// for each
ext nil vec_for_all (vec * vector, nil (* function) (ptr));

// checks if vector includes a pointer
inl u08 vec_includes (vec * vector, ptr pointer) {
	ret vec_index_of (vector, pointer) != vector -> size;
}

// returns vector last value assuming vector.size > 0
inl ptr vec_last (vec * vector) {
	ret vector -> items [vector -> size - 1];
}

// removes vector last value and returns it assumming vector.size > 0
inl ptr vec_pop (vec * vector) {
	ret vector -> items [--(vector -> size)];
}

// quick sort for vector items
inl nil vec_sort (vec * vector, s32 (* compare) (ptr, ptr)) {
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

// frees vector
inl nil vec_free (vec * vector) {
	free (vector -> items);
}

# endif // LIBPOCHA_VEC_H

