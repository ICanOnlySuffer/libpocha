# ifndef _PUTILS_INPUT_
# define _PUTILS_INPUT_

# include <stdio.h>
# include "types.h"

nil input (str string, str buffer, ux4 size) {
	ux4 i = 0;
	ix1 c = ' ';
	
	printf (string);
	
	while (c != '\n' && c != EOF) {
		c = fgetc (stdin);
		if (i < size) {
			buffer [i++] = c;
		}
	}
	
	buffer [i - 1] = 0;
}

# endif // _PUTILS_INPUT_



