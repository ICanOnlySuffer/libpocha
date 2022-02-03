# include "../putils/hashmap.h"
# include "tester.h"

nil test_person (str name, u08 age, chr gender, flt height) {
	it ("should append values");
	
	vec * person = vector_new (4);
	inline nil * get_person (str index) {
		return hashmap_get (person, index);
	}
	
	str person_keys [] = {"name", "age", "gender", "height"};
	nil * person_values [] = {&name, &age, &gender, &height};
	
	for (u08 i = 0; i < 4; i++) {
		struct hash * hash = hash_new (
			person_keys [i], person_values [i]
		);
		vector_append (person, hash);
		assert_eql ("%p == %p", hash, vector_last (person));
	}
	
	it ("should have the same values");
	
	assert_string_eql (name, *(str*) get_person ("name"));
	assert_eql ("%u == %u", age, *(u08*)get_person ("age"));
	assert_eql ("'%c' == '%c'", gender, *(chr*)get_person ("gender"));
	assert_eql ("%.2f == %.2f", height, *(flt*)get_person ("height"));
}

chr main () {
	test_person ("Pablo", 20, 'M', 1.82);
}

