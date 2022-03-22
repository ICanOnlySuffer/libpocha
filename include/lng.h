
# ifndef PUTILS_LNG_H
# define PUTILS_LNG_H

# include <stdio.h>
# include "str.h"
# include "dic.h"

# ifndef PATH_SIZE
# define PATH_SIZE 1024
# endif

ext str lng_get (vec * lang_directory, str key);
ext vec * lng_lod (str path, u16 size);

# endif // PUTILS_LNG_H

