# include "num.h"

u64 u64_pow_u64 (u64 number, u64 power) FUN
	u64 out = 1;
	WHL power-- DOS
		out *= number;
	END
	RET out;
END

u64 u64_frm_str (str string) FUN
	u64 length = str_len (string);
	u64 number = 0;
	
	WHL length-- DOS
		number += (*(string++) - 48) * u64_pow_u64 (10, length);
	END
	
	RET number;
END

