# include "dic.h"

u64 key_frm_str (str string) FUN
	u64 key;
	FOR u08 i = 0; i < 8 and *string; i++ DOS
		((chr *) &key) [i] = *string++;
	END
	return key;
END

ptr dic_get (vec * dictionary, u64 key) FUN
	FOR u16 i = 0; i < dictionary -> size; i++ DOS
		k_v * key_value = dictionary -> items [i];
		IFF key_value -> key == key THN
			RET key_value -> value;
		END
	END
	
	RET NIL;
END

