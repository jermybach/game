#ifndef MINMAX_H
#define MINMAX_H 1

#ifdef min
#undef min
#undef max
#endif

#define min(a, b) _Generic((a)+(b), \
    int      : min_int, \
    unsigned : min_unsigned, \
    size_t   : max_size_t, \
    float    : min_float, \
    double   : min_double)((a), (b))

#define max(a, b) _Generic((a)+(b), \
    int      : max_int, \
    unsigned : max_unsigned, \
    size_t   : max_size_t, \
    float    : max_float, \
    double   : max_double)((a), (b))

#define DECL_MIN(type) \
    inline type min_ ## type (type const a, type const b) { \
        return a < b ? a : b; \
    }

#define DECL_MAX(type) \
    inline type max_ ## type (type const a, type const b) { \
        return a > b ? a : b; \
    }

DECL_MIN(int)
DECL_MIN(unsigned)
DECL_MIN(float)
DECL_MIN(double)
DECL_MIN(size_t)

DECL_MAX(int)
DECL_MAX(unsigned)
DECL_MAX(float)
DECL_MAX(double)
DECL_MAX(size_t)


#endif//MINMAX_H
