# ifndef _PUTILS_TESTER_
# define _PUTILS_TESTER_

# include <string.h>
# include <stdio.h>

chr assert_string [128] = "should pass";
str SHOULD_FORMAT = "\e[32mIt %s\e[0m\n";
str ASSERT_FORMAT [] = {
	"  \e[31m[✗] %s\e[0m\n",
	"  \e[32m[✓] %s\e[0m\n"
};

# define it(should_) \
	printf (SHOULD_FORMAT, should_)

# define assert_eql(format_, value_1_, value_2_)                 \
	sprintf (assert_string, format_, value_1_, value_2_);        \
	printf (ASSERT_FORMAT [value_1_ == value_2_], assert_string)

nil assert_string_eql (str string_1, str string_2) {
	sprintf (assert_string, "\"%s\" == \"%s\"", string_1, string_2);
	printf (
		ASSERT_FORMAT [not strcmp (string_1, string_2)], assert_string
	);
}

# endif // _PUTILS_TESTER_

