# ifndef _PUTILS_INPUT_
# define _PUTILS_INPUT_ 1

# include <stdio.h>
# include "types.h"

nil input (str string, str buffer, u32 size) {
	u32 i = 0;
	chr c = ' ';
	
	printf (string);
	
	while (c != '\n' and c != EOF) {
		c = fgetc (stdin);
		if (i < size) {
			buffer [i++] = c;
		}
	}
	
	buffer [i - 1] = 0;
}

# endif // _PUTILS_INPUT_



