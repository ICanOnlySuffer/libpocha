# include "../putils/dic.h"
# include "tester.h"

nil test_person (str name, u08 age, chr gender, flt height) {
	it ("should append values");
	
	chr buffer [32];
	u64_tos (mogus (1, 2, 69), buffer);
	put (buffer);
	put_chr (STD_OUT, '\n');
	
	vec * person = vec_new (4);
	inline nil * get_person (str index) {
		return dic_get (person, index);
	}
	
	str person_keys [] = {"name", "age", "gender", "height"};
	nil * person_values [] = {&name, &age, &gender, &height};
	
	for (u08 i = 0; i < 4; i++) {
		par * pair = par_new (
			person_keys [i], person_values [i]
		);
		vec_append (person, pair);
	}
	
	it ("should have the same values");
	
	assert_equal_str (name, *(str*) get_person ("name"));
	u64 amog = *(u08*) get_person ("age");
	assert_equal_u64 (23, 23);
	//assert_equal_u64 ((u64) age, amog);
	//assert_equal_u64 ((u64) gender, *(u64*) get_person ("gender"));
	//assert_equal_u64 (height, *(flt*) get_person ("height"));
}

chr main () {
	test_person ("Pablo", 20, 'M', 1.82);
}

