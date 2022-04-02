
# ifndef PUTILS_COR_H
# define PUTILS_COR_H

# include <stdint.h>

// values

# define NIL NULL
# define false 0
# define true 1

// operators

# define and &&
# define not !
# define or ||

// logic

# define IFF if (
# define THN ) {
# define ELF } else if (
# define ELS } else {
# define END }
# define FUN {
# define FOR for (
# define DOS ) {
# define WHL while (
# define SWI switch (
# define WHN case

// typedefs

# define con const
# define enm enum

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

# define ret return
# define def default
# define nxt continue
# define ext extern

# define QUT(code_) exit (code_)
# define ARR_LEN(array_) sizeof (array_) / sizeof (*array_)

# endif // PUTILS_COR_H

