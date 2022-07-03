
# ifndef LIBPOCHA_ARR_H
# define LIBPOCHA_ARR_H

# include "cor.h"

ext nil arr_for_all (u16 size, ptr array [], nil (* proc) (ptr));
ext u08 arr_for_all_safe (u16 size, ptr array [], u08 (* proc) (ptr));

# endif // LIBPOCHA_ARR_H

