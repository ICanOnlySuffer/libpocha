# include "tester.h"

u08 main () {
	u64 number = 326742;
	chr buffer [32] = "hola";
	
	str_frm_u64 (buffer, number);
	
	PUT (buffer);
	NEW_LNE ();
}


