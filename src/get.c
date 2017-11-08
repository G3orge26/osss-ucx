/* For license: see LICENSE file at top-level */

#include "shmem/defs.h"
#include "shmemc.h"

#if 0
extern void shmem_ctx_complexf_get(COMPLEXIFY(float) * dest,
                               const COMPLEXIFY(float) * src,
                               size_t nelems, int pe);  /* ! API */
extern void shmem_ctx_complexd_get(COMPLEXIFY(double) * dest,
                               const COMPLEXIFY(double) * src,
                               size_t nelems, int pe);    /* ! API */
#endif

#ifdef ENABLE_PSHMEM
#pragma weak shmem_ctx_float_get = pshmem_ctx_float_get
#define shmem_ctx_float_get pshmem_ctx_float_get
#pragma weak shmem_ctx_double_get = pshmem_ctx_double_get
#define shmem_ctx_double_get pshmem_ctx_double_get
#pragma weak shmem_ctx_longdouble_get = pshmem_ctx_longdouble_get
#define shmem_ctx_longdouble_get pshmem_ctx_longdouble_get
#pragma weak shmem_ctx_char_get = pshmem_ctx_char_get
#define shmem_ctx_char_get pshmem_ctx_char_get
#pragma weak shmem_ctx_schar_get = pshmem_ctx_schar_get
#define shmem_ctx_schar_get pshmem_ctx_schar_get
#pragma weak shmem_ctx_short_get = pshmem_ctx_short_get
#define shmem_ctx_short_get pshmem_ctx_short_get
#pragma weak shmem_ctx_int_get = pshmem_ctx_int_get
#define shmem_ctx_int_get pshmem_ctx_int_get
#pragma weak shmem_ctx_long_get = pshmem_ctx_long_get
#define shmem_ctx_long_get pshmem_ctx_long_get
#pragma weak shmem_ctx_longlong_get = pshmem_ctx_longlong_get
#define shmem_ctx_longlong_get pshmem_ctx_longlong_get
#pragma weak shmem_ctx_uchar_get = pshmem_ctx_uchar_get
#define shmem_ctx_uchar_get pshmem_ctx_uchar_get
#pragma weak shmem_ctx_ushort_get = pshmem_ctx_ushort_get
#define shmem_ctx_ushort_get pshmem_ctx_ushort_get
#pragma weak shmem_ctx_uint_get = pshmem_ctx_uint_get
#define shmem_ctx_uint_get pshmem_ctx_uint_get
#pragma weak shmem_ctx_ulong_get = pshmem_ctx_ulong_get
#define shmem_ctx_ulong_get pshmem_ctx_ulong_get
#pragma weak shmem_ctx_ulonglong_get = pshmem_ctx_ulonglong_get
#define shmem_ctx_ulonglong_get pshmem_ctx_ulonglong_get
#pragma weak shmem_ctx_int8_get = pshmem_ctx_int8_get
#define shmem_ctx_int8_get pshmem_ctx_int8_get
#pragma weak shmem_ctx_int16_get = pshmem_ctx_int16_get
#define shmem_ctx_int16_get pshmem_ctx_int16_get
#pragma weak shmem_ctx_int32_get = pshmem_ctx_int32_get
#define shmem_ctx_int32_get pshmem_ctx_int32_get
#pragma weak shmem_ctx_int64_get = pshmem_ctx_int64_get
#define shmem_ctx_int64_get pshmem_ctx_int64_get
#pragma weak shmem_ctx_uint8_get = pshmem_ctx_uint8_get
#define shmem_ctx_uint8_get pshmem_ctx_uint8_get
#pragma weak shmem_ctx_uint16_get = pshmem_ctx_uint16_get
#define shmem_ctx_uint16_get pshmem_ctx_uint16_get
#pragma weak shmem_ctx_uint32_get = pshmem_ctx_uint32_get
#define shmem_ctx_uint32_get pshmem_ctx_uint32_get
#pragma weak shmem_ctx_uint64_get = pshmem_ctx_uint64_get
#define shmem_ctx_uint64_get pshmem_ctx_uint64_get

#pragma weak shmem_ctx_get8 = pshmem_ctx_get8
#define shmem_ctx_get8 pshmem_ctx_get8
#pragma weak shmem_ctx_get16 = pshmem_ctx_get16
#define shmem_ctx_get16 pshmem_ctx_get16
#pragma weak shmem_ctx_get32 = pshmem_ctx_get32
#define shmem_ctx_get32 pshmem_ctx_get32
#pragma weak shmem_ctx_get64 = pshmem_ctx_get64
#define shmem_ctx_get64 pshmem_ctx_get64
#pragma weak shmem_ctx_get128 = pshmem_ctx_get128
#define shmem_ctx_get128 pshmem_ctx_get128

#pragma weak shmem_ctx_getmem = pshmem_ctx_getmem
#define shmem_ctx_getmem pshmem_ctx_getmem

/* for Fortran */
#pragma weak shmem_ctx_complexf_get = pshmem_ctx_complexf_get
#define shmem_ctx_complexf_get pshmem_ctx_complexf_get
#pragma weak shmem_ctx_complexd_get = pshmem_ctx_complexd_get
#define shmem_ctx_complexd_get pshmem_ctx_complexd_get
#endif /* ENABLE_PSHMEM */

#define SHMEM_CTX_TYPED_GET(_name, _type)                        \
    void                                                         \
    shmem_ctx_##_name##_get(shmem_ctx_t ctx,                     \
                            _type *dest, const _type *src,       \
                            size_t nelems, int pe)               \
    {                                                            \
        const size_t typed_nelems = nelems * sizeof (_type);     \
        shmemc_ctx_get(ctx, dest, src, typed_nelems, pe);        \
    }

SHMEM_CTX_TYPED_GET(float, float)
SHMEM_CTX_TYPED_GET(double, double)
SHMEM_CTX_TYPED_GET(longdouble, long double)
SHMEM_CTX_TYPED_GET(char, char)
SHMEM_CTX_TYPED_GET(schar, signed char)
SHMEM_CTX_TYPED_GET(short, short)
SHMEM_CTX_TYPED_GET(int, int)
SHMEM_CTX_TYPED_GET(long, long)
SHMEM_CTX_TYPED_GET(longlong, long long)
SHMEM_CTX_TYPED_GET(uchar, unsigned char)
SHMEM_CTX_TYPED_GET(ushort, unsigned short)
SHMEM_CTX_TYPED_GET(uint, unsigned int)
SHMEM_CTX_TYPED_GET(ulong, unsigned long)
SHMEM_CTX_TYPED_GET(ulonglong, unsigned long long)
SHMEM_CTX_TYPED_GET(int8, int8_t)
SHMEM_CTX_TYPED_GET(int16, int16_t)
SHMEM_CTX_TYPED_GET(int32, int32_t)
SHMEM_CTX_TYPED_GET(int64, int64_t)
SHMEM_CTX_TYPED_GET(uint8, uint8_t)
SHMEM_CTX_TYPED_GET(uint16, uint16_t)
SHMEM_CTX_TYPED_GET(uint32, uint32_t)
SHMEM_CTX_TYPED_GET(uint64, uint64_t)
SHMEM_CTX_TYPED_GET(size, size_t)
SHMEM_CTX_TYPED_GET(ptrdiff, ptrdiff_t)
/* for Fortran */
SHMEM_CTX_TYPED_GET(complexf, COMPLEXIFY(float))
SHMEM_CTX_TYPED_GET(complexd, COMPLEXIFY(double))

#undef SHMEM_CTX_TYPED_GET

#define SHMEM_CTX_SIZED_GET(_size)                              \
    void                                                        \
    shmem_ctx_get##_size(shmem_ctx_t ctx,                       \
                         void *dest, const void *src,           \
                         size_t nelems, int pe)                 \
    {                                                           \
        const size_t sized_nelems = nelems * _size;             \
        shmemc_ctx_get(ctx, dest, src, sized_nelems, pe);       \
    }

SHMEM_CTX_SIZED_GET(8)
SHMEM_CTX_SIZED_GET(16)
SHMEM_CTX_SIZED_GET(32)
SHMEM_CTX_SIZED_GET(64)
SHMEM_CTX_SIZED_GET(128)

#undef SHMEM_CTX_SIZED_GET

void
shmem_ctx_getmem(shmem_ctx_t ctx,
                 void *dest, const void *src,
                 size_t nelems, int pe)
{
    shmemc_ctx_get(ctx, dest, src, nelems, pe);
}

#ifdef ENABLE_PSHMEM
#pragma weak shmem_ctx_float_g = pshmem_ctx_float_g
#define shmem_ctx_float_g pshmem_ctx_float_g
#pragma weak shmem_ctx_double_g = pshmem_ctx_double_g
#define shmem_ctx_double_g pshmem_ctx_double_g
#pragma weak shmem_ctx_longdouble_g = pshmem_ctx_longdouble_g
#define shmem_ctx_longdouble_g pshmem_ctx_longdouble_g
#pragma weak shmem_ctx_char_g = pshmem_ctx_char_g
#define shmem_ctx_char_g pshmem_ctx_char_g
#pragma weak shmem_ctx_schar_g = pshmem_ctx_schar_g
#define shmem_ctx_schar_g pshmem_ctx_schar_g
#pragma weak shmem_ctx_short_g = pshmem_ctx_short_g
#define shmem_ctx_short_g pshmem_ctx_short_g
#pragma weak shmem_ctx_int_g = pshmem_ctx_int_g
#define shmem_ctx_int_g pshmem_ctx_int_g
#pragma weak shmem_ctx_long_g = pshmem_ctx_long_g
#define shmem_ctx_long_g pshmem_ctx_long_g
#pragma weak shmem_ctx_longlong_g = pshmem_ctx_longlong_g
#define shmem_ctx_longlong_g pshmem_ctx_longlong_g
#pragma weak shmem_ctx_uchar_g = pshmem_ctx_uchar_g
#define shmem_ctx_uchar_g pshmem_ctx_uchar_g
#pragma weak shmem_ctx_ushort_g = pshmem_ctx_ushort_g
#define shmem_ctx_ushort_g pshmem_ctx_ushort_g
#pragma weak shmem_ctx_uint_g = pshmem_ctx_uint_g
#define shmem_ctx_uint_g pshmem_ctx_uint_g
#pragma weak shmem_ctx_ulong_g = pshmem_ctx_ulong_g
#define shmem_ctx_ulong_g pshmem_ctx_ulong_g
#pragma weak shmem_ctx_ulonglong_g = pshmem_ctx_ulonglong_g
#define shmem_ctx_ulonglong_g pshmem_ctx_ulonglong_g
#pragma weak shmem_ctx_int8_g = pshmem_ctx_int8_g
#define shmem_ctx_int8_g pshmem_ctx_int8_g
#pragma weak shmem_ctx_int16_g = pshmem_ctx_int16_g
#define shmem_ctx_int16_g pshmem_ctx_int16_g
#pragma weak shmem_ctx_int32_g = pshmem_ctx_int32_g
#define shmem_ctx_int32_g pshmem_ctx_int32_g
#pragma weak shmem_ctx_int64_g = pshmem_ctx_int64_g
#define shmem_ctx_int64_g pshmem_ctx_int64_g
#pragma weak shmem_ctx_uint8_g = pshmem_ctx_uint8_g
#define shmem_ctx_uint8_g pshmem_ctx_uint8_g
#pragma weak shmem_ctx_uint16_g = pshmem_ctx_uint16_g
#define shmem_ctx_uint16_g pshmem_ctx_uint16_g
#pragma weak shmem_ctx_uint32_g = pshmem_ctx_uint32_g
#define shmem_ctx_uint32_g pshmem_ctx_uint32_g
#pragma weak shmem_ctx_uint64_g = pshmem_ctx_uint64_g
#define shmem_ctx_uint64_g pshmem_ctx_uint64_g
/* for Fortran */
#pragma weak shmem_ctx_complexf_g = pshmem_ctx_complexf_g
#define shmem_ctx_complexf_g pshmem_ctx_complexf_g
#pragma weak shmem_ctx_complexd_g = pshmem_ctx_complexd_g
#define shmem_ctx_complexd_g pshmem_ctx_complexd_g
#endif /* ENABLE_PSHMEM */

#define SHMEM_CTX_TYPED_G(_name, _type)                               \
    _type                                                             \
    shmem_ctx_##_name##_g(shmem_ctx_t ctx,                            \
                          const _type *addr, int pe)                  \
    {                                                                 \
        _type val;                                                    \
        shmemc_ctx_get(ctx, &val, addr, sizeof(val), pe);             \
        return val;                                                   \
    }

SHMEM_CTX_TYPED_G(float, float)
SHMEM_CTX_TYPED_G(double, double)
SHMEM_CTX_TYPED_G(longdouble, long double)
SHMEM_CTX_TYPED_G(char, char)
SHMEM_CTX_TYPED_G(schar, signed char)
SHMEM_CTX_TYPED_G(short, short)
SHMEM_CTX_TYPED_G(int, int)
SHMEM_CTX_TYPED_G(long, long)
SHMEM_CTX_TYPED_G(longlong, long long)
SHMEM_CTX_TYPED_G(uchar, unsigned char)
SHMEM_CTX_TYPED_G(ushort, unsigned short)
SHMEM_CTX_TYPED_G(uint, unsigned int)
SHMEM_CTX_TYPED_G(ulong, unsigned long)
SHMEM_CTX_TYPED_G(ulonglong, unsigned long long)
SHMEM_CTX_TYPED_G(int8, int8_t)
SHMEM_CTX_TYPED_G(int16, int16_t)
SHMEM_CTX_TYPED_G(int32, int32_t)
SHMEM_CTX_TYPED_G(int64, int64_t)
SHMEM_CTX_TYPED_G(uint8, uint8_t)
SHMEM_CTX_TYPED_G(uint16, uint16_t)
SHMEM_CTX_TYPED_G(uint32, uint32_t)
SHMEM_CTX_TYPED_G(uint64, uint64_t)
SHMEM_CTX_TYPED_G(size, size_t)
SHMEM_CTX_TYPED_G(ptrdiff, ptrdiff_t)
/* for Fortran */
SHMEM_CTX_TYPED_G(complexf, COMPLEXIFY(float))
SHMEM_CTX_TYPED_G(complexd, COMPLEXIFY(double))

#undef SHMEM_CTX_TYPED_G
