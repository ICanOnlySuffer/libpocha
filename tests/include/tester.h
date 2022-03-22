
# ifndef _PUTILS_TESTER_
# define _PUTILS_TESTER_

# include "put.h"

ext nil it (str should);
ext u08 eql_u08 (ptr u08_1, ptr u08_2);
ext u08 eql_u64 (ptr u64_1, ptr u64_2);
ext u08 eql_str (ptr str_1, ptr str_2);
ext nil assert (u08 (* fnc) (ptr, ptr), ptr val_1, ptr val_2);

# endif // _PUTILS_TESTER_

