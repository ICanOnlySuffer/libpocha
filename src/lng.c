# include "lng.h"

str lng_get (vec * dictionary, str key) FUN
	str value = dic_get (dictionary, key);
	ret value ? value : key;
END

vec * lng_lod (str path, u16 size) FUN
	FILE * file = fopen (path, "r");
	IFF not file THN
		ret NIL;
	END
	
	vec * dictionary = vec_new (32);
	str buffer = calloc (size, sizeof (chr));
	u08 state = NEW_LINE;
	
	chr c = ' ';
	str value;
	str key;
	
	FOR u16 i = 0; c != EOF and i < size; c = fgetc (file) DOS
		SWI state DOS
		WHN READING_VALUE:
			IFF c == '\n' THN
				state = NEW_LINE;
				buffer [i] = 0;
				vec_psh (dictionary, k_v_new (key, value));
			ELS
				buffer [i] = c;
			END
			i++;
			break;
		WHN READING_KEY:
			IFF c == ' ' or c == '\t' THN
				state = SPACES;
				buffer [i] = 0;
			ELS
				buffer [i] = c;
			END
			i++;
			break;
		WHN NEW_LINE:
			IFF c == '#' THN
				state = COMMENT;
			ELF c != '\t' and c != ' ' and c != '\n' THN
				state = READING_KEY;
				buffer [i] = c;
				key = &buffer [i++];
			END
			break;
		WHN COMMENT:
			IFF c == '\n' THN
				state = NEW_LINE;
			END
			break;
		WHN SPACES:
			IFF c != ' ' and c != '\t' THN
				state = READING_VALUE;
				buffer [i] = c;
				value = &buffer [i++];
			END
		END
	END
	
	fclose (file);
	ret dictionary;
END

