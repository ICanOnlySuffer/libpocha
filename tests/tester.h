# include <stdio.h>

char assert_str [128] = "should pass";

# define it(should_) \
	printf ("\e[32mIt %s\e[0m\n", should_)

# define assert(boolean_, ...)                                            \
	sprintf (assert_str, __VA_ARGS__);                                    \
	printf (                                                              \
			boolean_ ? "  \e[32m[✓] %s\e[0m\n" : "  \e[31m[✗] %s\e[0m\n", \
		assert_str                                                        \
	)

