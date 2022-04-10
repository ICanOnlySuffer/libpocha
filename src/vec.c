# include "vec.h"

nil vec_rsz (vec * vector, u32 capacity) FUN
	ptr * items = realloc (vector -> items, sizeof (ptr) * capacity);
	IFF items THN
		vector -> items = items;
		vector -> capacity = capacity;
	END
END

nil vec_psh (vec * vector, ptr item) FUN
	IFF vector -> capacity == vector -> size THN
		vec_rsz (vector, vector -> capacity * 2);
	END
	vector -> items [vector -> size++] = item;
END

nil vec_psh_arr (vec * vector, ptr items [], u16 size) FUN
	IFF vector -> capacity < vector -> size + size THN
		vec_rsz (vector, vector -> size * 2);
	END
	WHL vector -> size < size DOS
		vector -> items [vector -> size++] = *items++;
	END
END

nil vec_rmv (vec * vector, u16 index) FUN
	WHL index < vector -> size DOS
		vector -> items [index] = vector -> items [index + 1];
		index++;
	END
	vector -> items [--vector -> size] = NIL;
END

nil vec_clr (vec * vector) FUN
	FOR u32 i = 0; i < vector -> size; i++ DOS
		free (vector -> items [i]);
	END
	vector -> size = 0;
END

