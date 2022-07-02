# include "../inc/cnf.h"
# include <stdio.h>

# define READING_VALUE 0
# define READING_KEY 1
# define NEW_LINE 2
# define COMMENT 3
# define SPACES 4

vec cnf_get (str path, u16 size) {
	FILE * file = fopen (path, "r");
	if (not file) {
		return vec_new (0);
	}
	
	vec dictionary = vec_new (32);
	str buffer = calloc (size, sizeof (chr));
	u08 state = NEW_LINE;
	
	chr c = ' ';
	str value;
	str key;
	
	for (u16 i = 0; c != EOF and i < size; c = fgetc (file)) {
		switch (state) {
		case READING_VALUE:
			if (c == '\n') {
				state = NEW_LINE;
				buffer [i] = 0;
				dic_push (&dictionary, (u64) key, value);
			} else {
				buffer [i] = c;
			}
			i++;
			break;
		case READING_KEY:
			if (c == ' ' or c == '\t') {
				state = SPACES;
				buffer [i] = 0;
			} else {
				buffer [i] = c;
			}
			i++;
			break;
		case NEW_LINE:
			if (c == '#') {
				state = COMMENT;
			} else if (c != '\t' and c != ' ' and c != '\n') {
				state = READING_KEY;
				buffer [i] = c;
				key = &buffer [i++];
			}
			break;
		case COMMENT:
			if (c == '\n') {
				state = NEW_LINE;
			}
			break;
		case SPACES:
			if (c != ' ' and c != '\t') {
				state = READING_VALUE;
				buffer [i] = c;
				value = &buffer [i++];
			}
		}
	}
	
	fclose (file);
	return dictionary;
}

