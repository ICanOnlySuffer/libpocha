# include "tester.h"
# include "num.h"

u08 main () {
	u64 number = u64_frm_str ("1234567");
	chr buffer [32];
	str_frm_u64 (buffer, number);
	
	PUT (buffer);
	NEW_LNE ();
}


