# include "../inc/arr.h"

nil arr_for_all (u16 length, ptr array [], nil (* proc) (ptr)) {
	for (u16 i = 0; i < length; i++) {
		proc (array [i]);
	}
}

