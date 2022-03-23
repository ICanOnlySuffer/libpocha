# include "num.h"

u64 u64_pow_u64 (u64 number, u64 power) fun
	u64 out = 1;
	whl power-- dos
		out *= number;
	end
	ret out;
end

u64 u64_frm_str (str string) fun
	u64 length = str_len (string);
	u64 number = 0;
	
	whl length-- dos
		number += (*(string++) - 48) * u64_pow_u64 (10, length);
	end
	
	ret number;
end

