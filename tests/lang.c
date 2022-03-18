# include "../putils/lng.h"
# include "tester.h"

u08 main () {
	chr * env_lang = getenv ("LANG");
	
	iff (env_lang) {
		env_lang [2] = 0;
	} els {
		env_lang = "es";
	}
	
	chr lang_path [32] = "lang/";
	STR_CAT (lang_path, env_lang);
	
	vec * lang_dictionary = lng_lod (lang_path, 256);
	unl (lang_dictionary) {
		PUT_ERR ("couldn't load language path\n");
		ret 1;
	}
	PUT (lng_get (lang_dictionary, "good_morning"));
	NEW_LNE ();
	VEC_FRE (lang_dictionary);
}

