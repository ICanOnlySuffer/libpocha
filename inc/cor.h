
# ifndef LIBPOCHA_COR_H
# define LIBPOCHA_COR_H
# include <stdint.h>

// version

# define LIBPOCHA_VERSION_MAYOR 0
# define LIBPOCHA_VERSION_MINOR 5
# define LIBPOCHA_VERSION_PATCH 0

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

typedef float f32;
typedef double f64;

typedef char chr;
typedef char * str;

typedef nil (* prc) (ptr);

// etc

# define inl static inline
# define prv static
# define ext extern
# define ret return

// ARR_LEN ((str []) {"hola", "que", "tal?"})
// => 3
# define ARR_LEN(...) (sizeof __VA_ARGS__ / sizeof *__VA_ARGS__)

// ARR (str, "buen", "día", "!")
// => 3, (str []) {"buen", "día", "!"}
# define ARR(type_, ...) \
	ARR_LEN ((type_ []) {__VA_ARGS__}), \
	(type_ []) {__VA_ARGS__}

# endif // LIBPOCHA_COR_H

