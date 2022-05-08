
# ifndef PUL_DIC_H
# define PUL_DIC_H

# include "vec.h"
# include "str.h"

typedef struct {
	u64 key;
	ptr value;
} key_val;

ext u64 key_frm_str (str string);
ext ptr dic_get (vec * dictionary, u64 key);
ext key_val * key_val_new (u64 key, ptr value);
inl key_val KEY_VAL (u64 key, ptr value) {
	return (key_val) {key, value};
}
inl nil dic_psh (vec * dictionary, u64 key, ptr value) {
	vec_psh (dictionary, key_val_new (key, value));
}

# endif // PUL_DIC_H

