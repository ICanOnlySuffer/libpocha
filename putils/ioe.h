
# ifndef _PUTILS_IOE_
# define _PUTILS_IOE_

# include "cor.h"

# define STD_INN 0
# define STD_OUT 1
# define STD_ERR 2

extern nil get_str (str buffer, u64 length);

extern nil put_str (u64 file, str buffer, u64 length);
extern nil put_chr (chr character);

# endif // _PUTILS_IOE_

