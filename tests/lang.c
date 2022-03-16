# include "../putils/lng.h"
# include "tester.h"

u08 main () {
	vec * lang_dictionary = lng_lod ("lang/es", 256);
	unl (lang_dictionary) {
		put ("couldn't load language path\n");
		ret 1;
	}
	put (lng_get (lang_dictionary, "good_morning"));
	put_chr ('\n');
	VEC_FRE (lang_dictionary);
}

