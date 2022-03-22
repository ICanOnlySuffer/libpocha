
# ifndef PUTILS_DIC_H
# define PUTILS_DIC_H

# include "str.h"
# include "vec.h"

typedef struct {
	str key;
	nil * value;
} k_v; // key_val

extern k_v * k_v_new (str key, nil * value);
extern str dic_get (vec * dictionary, str key);

# endif // PUTILS_DIC_H

