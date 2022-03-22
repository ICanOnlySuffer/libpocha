# include "tester.h"
# include "lng.h"

u08 main () {
	str env_lang = getenv ("LANG");
	
	iff env_lang and str_len (env_lang) > 2 thn
		env_lang [2] = 0;
	els
		env_lang = "es";
	end
	
	chr lang_path [32] = "../share/lang/";
	STR_CAT (lang_path, env_lang);
	
	vec * dictionary = lng_lod (lang_path, 256);
	iff not dictionary thn
		PUT_ERR ("couldn't load language path\n");
		ret 1;
	end
	PUT (lng_get (dictionary, "good_morning"));
	NEW_LNE ();
	VEC_FRE (dictionary);
}

