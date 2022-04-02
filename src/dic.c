# include "dic.h"

k_v * k_v_new (str key, ptr value) FUN
	k_v * key_value = malloc (sizeof (k_v));
	key_value -> key = key;
	key_value -> value = value;
	
	ret key_value;
END

str dic_get (vec * dictionary, str key) FUN
	FOR u16 i = 0; i < dictionary -> size; i++ DOS
		k_v * key_value = dictionary -> items [i];
		IFF STR_EQL (key_value -> key, key) THN
			ret key_value -> value;
		END
	END
	
	ret NIL;
END

