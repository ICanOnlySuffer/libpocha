
# ifndef LIBPOCHA_DIC_H
# define LIBPOCHA_DIC_H

# include "vec.h"
# include "str.h"
# include "num.h"

# define EQL_PRC u08 (*) (u64, u64)

typedef struct {
	u64 key;
	ptr value;
} key_val;

ext u16 dic_index_of (vec * dic, u64 key, u08 (*eql) (u64, u64));
inl u16 dic_index_of_num (vec * dic, u64 key) {
	ret dic_index_of (dic, key, num_equal);
}
inl u16 dic_index_of_str (vec * dic, str key) {
	ret dic_index_of (dic, (u64) key, (EQL_PRC) str_equal);
}

ext ptr dic_get (vec * dic, u64 key, u08 (*eql) (u64, u64));
inl ptr dic_get_num (vec * dic, u64 key) {
	ret dic_get (dic, key, num_equal);
}
inl ptr dic_get_str (vec * dic, str key) {
	ret dic_get (dic, (u64) key, (EQL_PRC) str_equal);
}

ext u08 dic_push (vec * dic, u64 key, ptr value);

ext u08 dic_remove_at (vec * dic, u64 key, u08 (*eql) (u64, u64));
inl u08 dic_remove_at_num (vec * dic, u64 key) {
	ret dic_remove_at (dic, key, num_equal);
}
inl u08 dic_remove_at_str (vec * dic, str key) {
	ret dic_remove_at (dic, (u64) key, (EQL_PRC) str_equal);
}

inl u08 dic_includes_num (vec * dic, u64 key) {
	ret dic_index_of_num (dic, key) != dic -> size;
}
inl u08 dic_includes_str (vec * dic, str key) {
	ret dic_index_of_str (dic, key) != dic -> size;
}

inl vec dic_new (u16 capacity) {
	ret vec_new (capacity);
}
inl nil dic_free (vec * dic) {
	free (dic -> items);
}

# endif // LIBPOCHA_DIC_H

