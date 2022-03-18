# include "../putils/vec.h"
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
	u08 n_names = ARR_LEN (names);
	vec * names_vector = vec_new (4);
	
	for (u08 i = 0; i < n_names; i++) {
		vec_psh (names_vector, &(names [i]));
		assert (eql_str, VEC_LST (names_vector), &(names [i]));
	}
}




