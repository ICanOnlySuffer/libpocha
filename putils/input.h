# include <stdio.h>
# pragma once

void input (char * string, char * buffer, unsigned short size) {
	unsigned short i = 0;
	char c = ' ';
	
	printf (string);
	
	while (c != '\n' && c != EOF) {
		c = fgetc (stdin);
		if (i < size) {
			buffer [i++] = c;
		}
	}
	
	buffer [i - 1] = 0;
}





