
# ifndef PUL_VEC_H
# define PUL_VEC_H

# include <stdlib.h>
# include "cor.h"

typedef struct {
	ptr * items;
	u32 capacity;
	u16 size;
} vec;
typedef s32 (* fun_compare) (const nil *, const nil *);

extern nil vec_rsz (vec * vector, u32 capacity);
extern nil vec_psh (vec * vector, ptr item);
extern nil vec_psh_arr (vec * vector, ptr items [], u16 size);
extern nil vec_rmv_idx (vec * vector, u16 index);
extern u16 vec_idx (vec * vector, ptr pointer);
extern nil vec_clr (vec * vector);
stainl nil vec_rmv (vec * vector, ptr pointer) {
	vec_rmv_idx (vector, vec_idx (vector, pointer));
}
stainl u08 vec_inc (vec * vector, ptr pointer) {
	return vec_idx (vector, pointer) != vector -> size;
}
stainl ptr vec_lst (vec * vector) {
	return vector -> items [vector -> size - 1];
}
stainl ptr vec_pop (vec * vector) {
	return vector -> items [--(vector -> size)];
}
stainl nil vec_srt (vec * vector, fun_compare compare) {
	qsort (vector -> items, vector -> size, sizeof (ptr), compare);
}
stainl vec * vec_new (u32 capacity) {
	vec * vector = malloc (sizeof (vector));
	vector -> items = malloc (sizeof (ptr) * capacity);
	vector -> capacity = capacity;
	vector -> size = 0;
	return vector;
}
stainl vec VEC (u32 capacity) {
	return (vec) {malloc (sizeof (ptr) * capacity), capacity, 0};
}

# endif // PUL_VEC_H

