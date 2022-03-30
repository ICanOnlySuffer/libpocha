# include "lng.h"

str lng_get (vec * dictionary, str key) {
	str value = dic_get (dictionary, key);
	ret value ? value : key;
}

enum {
	READING_VALUE,
	READING_KEY,
	NEW_LINE,
	COMMENT,
	SPACES
} state = NEW_LINE;
	
vec * lng_lod (str path, u16 size) {
	FILE * file = fopen (path, "r");
	if (not file) {
		ret NIL;
	}
	
	vec * dictionary = vec_new (32);
	str buffer = calloc (size, sizeof (chr));
	
	chr c = ' ';
	str value;
	str key;
	
	for (u16 i = 0; c != EOF and i < size; c = fgetc (file)) {
		switch (state) {
		case READING_VALUE:
			if (c == '\n') {
				state = NEW_LINE;
				buffer [i] = 0;
				vec_psh (dictionary, k_v_new (key, value));
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
	ret dictionary;
}

