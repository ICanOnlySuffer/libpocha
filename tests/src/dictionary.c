# include "tester.h"
# include "dic.h"

chr main () {
	str name = "Paco";
	u08 age = 20;
	dbl height = 1.87;
	
	chr buffer [32];
	vec * person = vec_new (4);
	
	str keys [] = {"name", "age", "height"};
	ptr values [] = {&name, &age, &height};
	
	for u08 i = 0; i < ARR_LEN (keys); i++ dos
		vec_psh (person, k_v_new (keys [i], values [i]));
	end
	
	it ("should have the same values");
	
	assert (eql_str, &name, dic_get (person, "name"));
	assert (eql_u08, &age, dic_get (person, "age"));
	// assert (eql_dbl, &height, dic_get (person, "height"));
}
