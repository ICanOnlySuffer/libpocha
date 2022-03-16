
# ifndef _PUTILS_IOE_
# define _PUTILS_IOE_

# include "cor.h"

# define STD_INN 0
# define STD_OUT 1
# define STD_ERR 2

ext nil get_str (str buffer, u64 length);
ext nil put_str (str buffer, u64 length);
ext nil put_chr (chr character);

# endif // _PUTILS_IOE_

