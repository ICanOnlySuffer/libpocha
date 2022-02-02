# ifndef _HASHMAP_
# define _HASHMAP_ 2

# include "string.h"
# include "vector.h"

struct hash {
	str key;
	str value;
};

struct hash * hash_new (str key, str value) {
	struct hash * hash = malloc (sizeof (struct hash));
	
	hash -> key = key;
	hash -> value = value;
	
	return hash;
}

str hashmap_get (vec * hashmap, str key) {
	for (u16 i = 0; i < hashmap -> size; i++) {
		struct hash * hash = hashmap -> items [i];
		if (streql (hash -> key, key)) {
			key = hash -> value;
			break;
		}
	}
	
	return key;
}

# endif // _PUTILS_HASHMAP_

