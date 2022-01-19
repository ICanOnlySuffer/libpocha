# ifndef _HASHMAP_
# define _HASHMAP_ 1

# include "string.h"
# include "vector.h"

struct hash {
	str key;
	str value;
};

str hashmap_get (vec *hashmap, str key) {
	for (u16 i = 0; i < hashmap -> size; i++) {
		struct hash *hash = hashmap -> items [i];
		if (streql (hash -> key, key)) {
			key = hash -> value;
			break;
		}
	}
	
	return key;
}

# endif
















