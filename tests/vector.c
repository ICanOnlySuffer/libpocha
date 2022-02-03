# include "../putils/vector.h"
# include "tester.h"

chr main () {
	it ("should append strings");
	
	str names [] = {
		"Juanito",
		"Juanita",
		"Cecilio",
		"Cecilia",
		"Victorio",
		"Victoria"
	};
	u08 n_names = sizeof (names) / sizeof (*names);
	vec * names_vector = vector_new (4);
	
	for (u08 i = 0; i < n_names; i++) {
		vector_append (names_vector, &(names [i]));
		assert_string_eql (
			*(str *) vector_last (names_vector), names [i]
		);
	}
}




