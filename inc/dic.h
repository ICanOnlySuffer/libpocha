
# ifndef PUL_DIC_H
# define PUL_DIC_H

# include "vec.h"
# include "str.h"

typedef struct {
	u64 key;
	ptr value;
} k_v;

EXT u64 key_frm_str (str string);
EXT ptr dic_get (vec * dictionary, u64 key);
STC INL k_v * k_v_new (u64 key, ptr value) FUN
	k_v * key_value = malloc (sizeof (k_v));
	key_value -> key = key;
	key_value -> value = value;
	RET key_value;
END

# define K_V_NEW(key_, value_) \
	(k_v) {.key = key_, .value = value_}

# endif // PUL_DIC_H

