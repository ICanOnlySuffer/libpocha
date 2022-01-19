# include "../putils/vector.h"
# include "test.h"

chr main () {
	it ("should append strings");
	
	str names [] = {
		"Paco",
		"Paca",
		"Pablo",
		"Pabla",
		"Juanito",
		"Juanita",
		"Cecilio",
		"Cecilia",
		"Victorio",
		"Victoria"
	};
	u08 n_names = sizeof (names) / sizeof (*names);
	vec *names_vector = vector_new (2);
	
	for (u08 i = 0; i < n_names; i++) {
		vector_append (names_vector, &(names [i]));
		str *last = vector_last (names_vector);
		
		assert (
			last == &names [i],
			"\"%s\" == \"%s\"", *last, names [i]
		);
	}
}




