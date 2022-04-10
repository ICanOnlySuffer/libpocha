# include "cnf.h"

vec cnf_get (str path, u16 size) FUN
	FILE * file = fopen (path, "r");
	IFF not file THN
		RET VEC_NEW (0);
	END
	
	vec dictionary = VEC_NEW (32);
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
				k_v * key_value = k_v_new (key_frm_str (key), value);
				vec_psh (&dictionary, key_value);
			ELS
				buffer [i] = c;
			END
			i++;
			BRK;
		WHN READING_KEY:
			IFF c == ' ' or c == '\t' THN
				state = SPACES;
				buffer [i] = 0;
			ELS
				buffer [i] = c;
			END
			i++;
			BRK;
		WHN NEW_LINE:
			IFF c == '#' THN
				state = COMMENT;
			ELF c != '\t' and c != ' ' and c != '\n' THN
				state = READING_KEY;
				buffer [i] = c;
				key = &buffer [i++];
			END
			BRK;
		WHN COMMENT:
			IFF c == '\n' THN
				state = NEW_LINE;
			END
			BRK;
		WHN SPACES:
			IFF c != ' ' and c != '\t' THN
				state = READING_VALUE;
				buffer [i] = c;
				value = &buffer [i++];
			END
		END
	END
	
	fclose (file);
	RET dictionary;
END

