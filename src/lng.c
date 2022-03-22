# include "lng.h"

str lng_get (vec * dictionary, str key) fun
	str value = dic_get (dictionary, key);
	ret value ? value : key;
end

enum {
	READING_VALUE,
	READING_KEY,
	NEW_LINE,
	COMMENT,
	SPACES
} state = NEW_LINE;
	
vec * lng_lod (str path, u16 size) fun
	FILE * file = fopen (path, "r");
	iff not file thn
		ret NIL;
	end
	
	vec * dictionary = vec_new (32);
	str buffer = calloc (size, sizeof (chr));
	
	chr c = ' ';
	str value;
	str key;
	
	for u16 i = 0; c != EOF and i < size; c = fgetc (file) dos
		swi state dos
		whn READING_VALUE:
			iff c == '\n' thn
				state = NEW_LINE;
				buffer [i] = 0;
				vec_psh (dictionary, k_v_new (key, value));
			els
				buffer [i] = c;
			end
			i++;
			break;
		whn READING_KEY:
			iff c == ' ' or c == '\t' thn
				state = SPACES;
				buffer [i] = 0;
			els
				buffer [i] = c;
			end
			i++;
			break;
		whn NEW_LINE:
			iff c == '#' thn
				state = COMMENT;
			elf c != '\t' and c != ' ' and c != '\n' thn
				state = READING_KEY;
				buffer [i] = c;
				key = &buffer [i++];
			end
			break;
		whn COMMENT:
			iff c == '\n' thn
				state = NEW_LINE;
			end
			break;
		whn SPACES:
			iff c != ' ' and c != '\t' thn
				state = READING_VALUE;
				buffer [i] = c;
				value = &buffer [i++];
			end
		end
	end
	
	fclose (file);
	ret dictionary;
end

