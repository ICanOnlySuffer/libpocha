
# ifndef PUL_VEC_H
# define PUL_VEC_H

# include <stdlib.h>
# include "cor.h"

typedef struct {
	ptr * items;
	u32 capacity;
	u16 size;
} vec;

EXT nil vec_rsz (vec * vector, u32 capacity);
EXT nil vec_psh (vec * vector, ptr item);
EXT nil vec_psh_arr (vec * vector, ptr items [], u16 size);
EXT nil vec_rmv (vec * vector, u16 index);
EXT nil vec_clr (vec * vector);
STC INL vec * vec_new (u32 capacity) FUN
	vec * vector = malloc (sizeof (vector));
	vector -> items = malloc (sizeof (ptr) * capacity);
	vector -> capacity = capacity;
	vector -> size = 0;
	RET vector;
END

# define VEC_NEW(capacity_) \
	(vec) { \
		.items = malloc (sizeof (ptr) * capacity_), \
		.capacity = capacity_, \
		.size = 0 \
	}

# define VEC_SRT(vector_, compare_) \
	qsort ( \
		(vector_) -> items, \
		(vector_) -> size, \
		sizeof (ptr), \
		compare_ \
	)

# define VEC_LST(vector_) \
	vector_ -> items [vector_ -> size - 1]

# define VEC_DEL(vector_) \
	vec_clr (vector_); \
	free (vector_)

# endif // PUL_VEC_H

