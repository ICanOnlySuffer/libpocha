# include "../inc/arr.h"

nil arr_for_all (u16 length, ptr array [], nil (* proc) (ptr)) {
	for (u16 i = 0; i < length; i++) {
		proc (array [i]);
	}
}

u08 arr_for_all_safe (u16 length, ptr array [], u08 (* proc) (ptr)) {
	for (u16 i = 0; i < length; i++) {
		if (not proc (array [i])) {
			ret false;
		}
	}
	ret true;
}



