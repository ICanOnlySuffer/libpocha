# include "../putils/put.h"
# include <stdio.h>

u08 main () {
	chr buffer [64] = "helo";
	STR_CPY (buffer, "sup ", "mogus ", "frendo");
	put (buffer);
	put_chr ('\n');
}

