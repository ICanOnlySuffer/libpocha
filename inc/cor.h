
# ifndef PUL_COR_H
# define PUL_COR_H
# include <stdint.h>

// version

# define PUL_VERSION_MAYOR 0
# define PUL_VERSION_MINOR 4
# define PUL_VERSION_PATCH 0

// values

# define NIL NULL
# define false 0
# define true 1

// operators

# define and &&
# define not !
# define or ||

typedef void nil;
typedef void * ptr;

typedef int8_t  s08;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

typedef uint8_t  u08;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef float flt;
typedef double dbl;

typedef char chr;
typedef char * str;

// etc

# define stainl static inline
# define ARR_LEN(array_) (sizeof (array_) / sizeof (*array_))

# endif // PUL_COR_H

