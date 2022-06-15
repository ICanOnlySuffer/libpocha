
# ifndef LIBPOCHA_DIC_H
# define LIBPOCHA_DIC_H

# include "vec.h"
# include "str.h"

/*
NOTES:
- remember to always do `vec_for_all (dictionary, free)`
*/

typedef struct {
	u64 key;
	ptr value;
} key_val;

ext u16 dic_idx (vec * dictionary, u64 key);
ext u16 dic_str_idx (vec * dictionary, str key);

ext ptr dic_get (vec * dictionary, u64 key);
ext ptr dic_str_get (vec * dictionary, str key);

ext u08 dic_psh (vec * dictionary, u64 key, ptr value);
ext u08 dic_rmv (vec * dictionary, u64 key);

inl u08 dic_inc (vec * dictionary, u64 key) {
	ret dic_idx (dictionary, key) != dictionary -> size;
}

# endif // LIBPOCHA_DIC_H

