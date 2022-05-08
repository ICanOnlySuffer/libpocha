
# ifndef PUL_VEC_H
# define PUL_VEC_H

# include <stdlib.h>
# include "cor.h"

typedef struct {
	ptr * items;
	u16 capacity;
	u16 size;
} vec;

ext nil vec_rsz (vec * vector, u16 capacity);
ext nil vec_psh (vec * vector, ptr item);
ext nil vec_psh_arr (vec * vector, u08 n_items, ptr items []);
ext nil vec_rmv_idx (vec * vector, u16 index);
ext u16 vec_idx (vec * vector, ptr pointer);
ext nil vec_for_all (vec * vector, nil (* function) (ptr));
ext vec * vec_new (u16 capacity);

inl nil vec_rmv (vec * vector, ptr pointer) {
	vec_rmv_idx (vector, vec_idx (vector, pointer));
}
inl u08 vec_inc (vec * vector, ptr pointer) {
	return vec_idx (vector, pointer) != vector -> size;
}
inl ptr vec_lst (vec * vector) {
	return vector -> items [vector -> size - 1];
}
inl ptr vec_pop (vec * vector) {
	return vector -> items [--(vector -> size)];
}
inl nil vec_srt (vec * vector, s32 (* compare) (con_ptr, con_ptr)) {
	qsort (vector -> items, vector -> size, sizeof (ptr), compare);
}
inl vec VEC (u16 capacity) {
	return (vec) {malloc (sizeof (ptr) * capacity), capacity, 0};
}

# endif // PUL_VEC_H

