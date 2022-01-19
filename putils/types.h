# ifndef _PUTILS_TYPES_
# define _PUTILS_TYPES_ 1

# include <stdint.h>

// values

# define NIL NULL
# define false 0
# define true 1

// operators

# define and &&
# define not !
# define or ||

// typedefs

typedef void nil;

typedef int8_t  s08;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

typedef uint8_t  u08;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef char chr;
typedef char *str;

# endif // _PUTILS_TYPES_

