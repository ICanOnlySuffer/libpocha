
# ifndef PUTILS_VEC_H
# define PUTILS_VEC_H

# include <stdlib.h>
# include "cor.h"

typedef struct {
	nil ** items;
	u32 capacity;
	u16 size;
} vec;

extern vec * vec_new (u32 capacity);
extern nil vec_rsz (vec * vector, u32 capacity);
extern nil vec_psh (vec * vector, nil * item);
extern nil vec_psh_arr (vec * vector, nil * items [], u16 size);
extern nil vec_rmv (vec * vector, u16 index);
extern nil vec_clr (vec * vector);

# define VEC_SRT(vector_, compare_) \
	qsort (vector_ -> items, vector_ -> size, sizeof (nil *), compare_)

# define VEC_LST(vector_) \
	vector_ -> items [vector_ -> size - 1]

# define VEC_DEL(vector_) \
	vec_clr (vector_); \
	free (vector_)

# endif // PUTILS_VEC_H

