
# ifndef PUL_DIC_H
# define PUL_DIC_H

# include "vec.h"
# include "str.h"

typedef struct {
	u64 key;
	ptr value;
} key_val;

extern u64 key_frm_str (str string);
extern ptr dic_get (vec * dictionary, u64 key);
stainl key_val * key_val_new (u64 key, ptr value) {
	key_val * key_value = malloc (sizeof (key_val));
	key_value -> key = key;
	key_value -> value = value;
	return key_value;
}
stainl key_val KEY_VAL (u64 key, ptr value) {
	return (key_val) {key, value};
}
stainl nil dic_psh (vec * dictionary, u64 key, ptr value) {
	vec_psh (dictionary, key_val_new (key, value));
}

# endif // PUL_DIC_H

