/*  libsimdpp
    Copyright (C) 2011-2012  p12 tir5c3@yahoo.co.uk

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef LIBSIMDPP_SIMD_MATH_INT_ADV_H
#define LIBSIMDPP_SIMD_MATH_INT_ADV_H

#ifndef LIBSIMDPP_SIMD_H
    #error "This file must be included through simd.h"
#endif
#include <simdpp/simd/types.h>
#include <simdpp/simd/compare.h>
#include <simdpp/simd/math_shift.h>
#include <simdpp/simd/shuffle.h>

#if SIMDPP_USE_NULL || SIMDPP_USE_NEON
    #include <simdpp/null/math.h>
#endif

namespace simdpp {
SIMDPP_ARCH_NAMESPACE_BEGIN

/// @{
/** Computes minimum of signed 8-bit values.

    @code
    r0 = min(a0, b0)
    ...
    rN = min(aN, bN)
    @endcode

    @par 128-bit version:
    @icost{SSE2-SSSE3, 4}

    @par 256-bit version:
    @icost{SSE2-SSSE3, 8}
    @icost{SSE4.1-AVX, NEON, 2}
*/
inline int8x16 min(int8x16 a, int8x16 b)
{
#if SIMDPP_USE_NULL
    return null::min(a, b);
#elif SIMDPP_USE_SSE4_1
    return _mm_min_epi8(a, b);
#elif SIMDPP_USE_SSE2
    int128 mask = cmp_lt(a, b);
    return blend(a, b, mask);
#elif SIMDPP_USE_NEON
    return vminq_s8(a, b);
#endif
}

inline int8x32 min(int8x32 a, int8x32 b)
{
#if SIMDPP_USE_AVX2
    return _mm256_min_epi8(a, b);
#else
    return {min(a[0], b[0]), min(a[1], b[1])};
#endif
}
/// @}

/// @{
/** Computes minimum of the unsigned 8-bit values.

    @code
    r0 = min(a0, b0)
    ...
    rN = min(aN, bN)
    @endcode

    @par 256-bit version:
    @icost{SSE2-AVX, NEON, 2}
*/
inline uint8x16 min(uint8x16 a, uint8x16 b)
{
#if SIMDPP_USE_NULL
    return null::min(a, b);
#elif SIMDPP_USE_SSE2
    return _mm_min_epu8(a, b);
#elif SIMDPP_USE_NEON
    return vminq_u8(a, b);
#endif
}

inline uint8x32 min(uint8x32 a, uint8x32 b)
{
#if SIMDPP_USE_AVX2
    return _mm256_min_epu8(a, b);
#else
    return {min(a[0], b[0]), min(a[1], b[1])};
#endif
}
/// @}

/// @{
/** Computes minimum of the signed 16-bit values.

    @code
    r0 = min(a0, b0)
    ...
    rN = min(aN, bN)
    @endcode

    @par 256-bit version:
    @icost{SSE2-AVX, NEON, 2}
*/
inline int16x8 min(int16x8 a, int16x8 b)
{
#if SIMDPP_USE_NULL
    return null::min(a, b);
#elif SIMDPP_USE_SSE2
    return _mm_min_epi16(a, b);
#elif SIMDPP_USE_NEON
    return vminq_s16(a, b);
#endif
}

inline int16x16 min(int16x16 a, int16x16 b)
{
#if SIMDPP_USE_AVX2
    return _mm256_min_epi16(a, b);
#else
    return {min(a[0], b[0]), min(a[1], b[1])};
#endif
}
/// @}

/// @{
/** Computes minimum of the unsigned 16-bit values.

    @code
    r0 = min(a0, b0)
    ...
    rN = min(aN, bN)
    @endcode

    @par 128-bit version:
    @icost{SSE2-SSSE3, 7}

    @par 256-bit version:
    @icost{SSE2-SSSE3, 14}
    @icost{SSE4.1-AVX, NEON, 2}
*/
inline uint16x8 min(uint16x8 a, uint16x8 b)
{
#if SIMDPP_USE_NULL
    return null::min(a, b);
#elif SIMDPP_USE_SSE4_1
    return _mm_min_epu16(a, b);
#elif SIMDPP_USE_SSE2
    int128 mask = cmp_lt(a, b);
    return blend(a, b, mask);
#elif SIMDPP_USE_NEON
    return vminq_u16(a, b);
#endif
}

inline uint16x16 min(uint16x16 a, uint16x16 b)
{
#if SIMDPP_USE_AVX2
    return _mm256_min_epu16(a, b);
#else
    return {min(a[0], b[0]), min(a[1], b[1])};
#endif
}
/// @}

/// @{
/** Computes minimum of the signed 32-bit values.

    @code
    r0 = min(a0, b0)
    ...
    rN = min(aN, bN)
    @endcode

    @par 128-bit version:
    @icost{SSE2-SSSE3, 4}

    @par 256-bit version:
    @icost{SSE2-SSSE3, 8}
    @icost{SSE4.1-AVX, NEON, 2}
*/
inline int32x4 min(int32x4 a, int32x4 b)
{
#if SIMDPP_USE_NULL
    return null::min(a, b);
#elif SIMDPP_USE_SSE4_1
    return _mm_min_epi32(a, b);
#elif SIMDPP_USE_SSE2
    int128 mask = cmp_lt(a, b);
    return blend(a, b, mask);
#elif SIMDPP_USE_NEON
    return vminq_s32(a, b);
#endif
}

inline int32x8 min(int32x8 a, int32x8 b)
{
#if SIMDPP_USE_AVX2
    return _mm256_min_epi32(a, b);
#else
    return {min(a[0], b[0]), min(a[1], b[1])};
#endif
}
/// @}

/// @{
/** Computes minimum of the unsigned 32-bit values.

    @code
    r0 = min(a0, b0)
    ...
    rN = min(aN, bN)
    @endcode

    @par 128-bit version:
    @icost{SSE2-SSSE3, 7}

    @par 256-bit version:
    @icost{SSE2-SSSE3, 14}
    @icost{SSE4.1-AVX, NEON, 2}
*/
inline uint32x4 min(uint32x4 a, uint32x4 b)
{
#if SIMDPP_USE_NULL
    return null::min(a, b);
#elif SIMDPP_USE_SSE4_1
    return _mm_min_epu32(a, b);
#elif SIMDPP_USE_SSE2
    int128 mask = cmp_lt(a, b);
    return blend(a, b, mask);
#elif SIMDPP_USE_NEON
    return vminq_u32(a, b);
#endif
}

inline uint32x8 min(uint32x8 a, uint32x8 b)
{
#if SIMDPP_USE_AVX2
    return _mm256_min_epu32(a, b);
#else
    return {min(a[0], b[0]), min(a[1], b[1])};
#endif
}
/// @}

/// @{
/** Computes maximum of the signed 8-bit values.

    @code
    r0 = max(a0, b0)
    ...
    rN = max(aN, bN)
    @endcode

    @par 128-bit version:
    @icost{SSE2-SSSE3, 4}

    @par 256-bit version:
    @icost{SSE2-SSSE3, 8}
    @icost{SSE4.1-AVX, NEON, 2}
*/
inline int8x16 max(int8x16 a, int8x16 b)
{
#if SIMDPP_USE_NULL
    return null::max(a, b);
#elif SIMDPP_USE_SSE4_1
    return _mm_max_epi8(a, b);
#elif SIMDPP_USE_SSE2
    int128 mask = cmp_gt(a, b);
    return blend(a, b, mask);
#elif SIMDPP_USE_NEON
    return vmaxq_s8(a, b);
#endif
}

inline int8x32 max(int8x32 a, int8x32 b)
{
#if SIMDPP_USE_AVX2
    return _mm256_max_epi8(a, b);
#else
    return {max(a[0], b[0]), max(a[1], b[1])};
#endif
}
/// @}

/// @{
/** Computes maximum of the unsigned 8-bit values.

    @code
    r0 = max(a0, b0)
    ...
    rN = max(aN, bN)
    @endcode

    @par 256-bit version:
    @icost{SSE2-AVX, NEON, 2}
*/
inline uint8x16 max(uint8x16 a, uint8x16 b)
{
#if SIMDPP_USE_NULL
    return null::max(a, b);
#elif SIMDPP_USE_SSE2
    return _mm_max_epu8(a, b);
#elif SIMDPP_USE_NEON
    return vmaxq_u8(a, b);
#endif
}

inline uint8x32 max(uint8x32 a, uint8x32 b)
{
#if SIMDPP_USE_AVX2
    return _mm256_max_epu8(a, b);
#else
    return {max(a[0], b[0]), max(a[1], b[1])};
#endif
}
/// @}

/// @{
/** Computes maximum of the signed 16-bit values.

    @code
    r0 = max(a0, b0)
    ...
    rN = max(aN, bN)
    @endcode

    @par 256-bit version:
    @icost{SSE2-AVX, NEON, 2}
*/
inline int16x8 max(int16x8 a, int16x8 b)
{
#if SIMDPP_USE_NULL
    return null::max(a, b);
#elif SIMDPP_USE_SSE2
    return _mm_max_epi16(a, b);
#elif SIMDPP_USE_NEON
    return vmaxq_s16(a, b);
#endif
}

inline int16x16 max(int16x16 a, int16x16 b)
{
#if SIMDPP_USE_AVX2
    return _mm256_max_epi16(a, b);
#else
    return {max(a[0], b[0]), max(a[1], b[1])};
#endif
}
/// @}

/// @{
/** Computes maximum of the unsigned 16-bit values.

    @code
    r0 = max(a0, b0)
    ...
    rN = max(aN, bN)
    @endcode

    @par 128-bit version:
    @icost{SSE2-SSSE3, 7}

    @par 256-bit version:
    @icost{SSE2-SSSE3, 14}
    @icost{SSE4.1-AVX, NEON, 2}
*/
inline uint16x8 max(uint16x8 a, uint16x8 b)
{
#if SIMDPP_USE_NULL
    return null::max(a, b);
#elif SIMDPP_USE_SSE4_1
    return _mm_max_epu16(a, b);
#elif SIMDPP_USE_SSE2
    int128 mask = cmp_gt(a, b);
    return blend(a, b, mask);
#elif SIMDPP_USE_NEON
    return vmaxq_u16(a, b);
#endif
}

inline uint16x16 max(uint16x16 a, uint16x16 b)
{
#if SIMDPP_USE_AVX2
    return _mm256_max_epu16(a, b);
#else
    return {max(a[0], b[0]), max(a[1], b[1])};
#endif
}
/// @}

/// @{
/** Computes maximum of the signed 32-bit values.

    @code
    r0 = max(a0, b0)
    ...
    rN = max(aN, bN)
    @endcode

    @par 128-bit version:
    @icost{SSE2-SSSE3, 4}

    @par 256-bit version:
    @icost{SSE2-SSSE3, 8}
    @icost{SSE4.1-AVX, NEON, 2}
*/
inline int32x4 max(int32x4 a, int32x4 b)
{
#if SIMDPP_USE_NULL
    return null::max(a, b);
#elif SIMDPP_USE_SSE4_1
    return _mm_max_epi32(a, b);
#elif SIMDPP_USE_SSE2
    int128 mask = cmp_gt(a, b);
    return blend(a, b, mask);
#elif SIMDPP_USE_NEON
    return vmaxq_s32(a, b);
#endif
}


inline int32x8 max(int32x8 a, int32x8 b)
{
#if SIMDPP_USE_AVX2
    return _mm256_max_epi32(a, b);
#else
    return {max(a[0], b[0]), max(a[1], b[1])};
#endif
}
/// @}

/// @{
/** Computes maximum of the unsigned 32-bit values.

    @code
    r0 = max(a0, b0)
    ...
    rN = max(aN, bN)
    @endcode

    @par 128-bit version:
    @icost{SSE2-SSSE3, 7}

    @par 256-bit version:
    @icost{SSE2-SSSE3, 14}
    @icost{SSE4.1-AVX, NEON, 2}
*/
inline uint32x4 max(uint32x4 a, uint32x4 b)
{
#if SIMDPP_USE_NULL
    return null::max(a, b);
#elif SIMDPP_USE_SSE4_1
    return _mm_max_epu32(a, b);
#elif SIMDPP_USE_SSE2
    int128 mask = cmp_gt(a, b);
    return blend(a, b, mask);
#elif SIMDPP_USE_NEON
    return vmaxq_u32(a, b);
#endif
}

inline uint32x8 max(uint32x8 a, uint32x8 b)
{
#if SIMDPP_USE_AVX2
    return _mm256_max_epu32(a, b);
#else
    return {max(a[0], b[0]), max(a[1], b[1])};
#endif
}
/// @}

/// @{
/** Computes average of the unsigned 8-bit values.

    @code
    r0 = (a0 + b0 + 1) / 2
    ...
    rN = (aN + bN + 1) / 2
    @endcode

    @par 256-bit version:
    @icost{SSE2-AVX, NEON, 2}
*/
inline uint8x16 avg(uint8x16 a, uint8x16 b)
{
#if SIMDPP_USE_NULL
    return null::foreach<uint8x16>(a, b, [](uint8_t a, uint8_t b){
        return (uint16_t(a) + b + 1) >> 1;
    });
#elif SIMDPP_USE_SSE2
    return _mm_avg_epu8(a, b);
#elif SIMDPP_USE_NEON
    return vrhaddq_u8(a, b);
#endif
}

inline uint8x32 avg(uint8x32 a, uint8x32 b)
{
#if SIMDPP_USE_AVX2
    return _mm256_avg_epu8(a, b);
#else
    return {avg(a[0], b[0]), avg(a[1], b[1])};
#endif
}
/// @}

/// @{
/** Computes average of the unsigned 16-bit values.

    @code
    r0 = (a0 + b0 + 1) / 2
    ...
    rN = (aN + bN + 1) / 2
    @endcode

    @par 256-bit version:
    @icost{SSE2-AVX, NEON, 2}
*/
inline uint16x8 avg(uint16x8 a, uint16x8 b)
{
#if SIMDPP_USE_NULL
    return null::foreach<uint16x8>(a, b, [](uint16_t a, uint16_t b){
        return (uint32_t(a) + b + 1) >> 1;
    });
#elif SIMDPP_USE_SSE2
    return _mm_avg_epu16(a, b);
#elif SIMDPP_USE_NEON
    return vrhaddq_u16(a, b);
#endif
}

inline uint16x16 avg(uint16x16 a, uint16x16 b)
{
#if SIMDPP_USE_AVX2
    return _mm256_avg_epu16(a, b);
#else
    return {avg(a[0], b[0]), avg(a[1], b[1])};
#endif
}
/// @}

/// @{
/** Computes absolute value of 8-bit integer values.

    @code
    r0 = abs(a0)
    ...
    rN = abs(aN)
    @endcode

    @par 128-bit version:
    @icost{SSE2-SSE3, 4}

    @par 256-bit version:
    @icost{SSE2-SSE3, 8}
    @icost{SSSE3-AVX, NEON, 2}
*/
inline uint8x16 abs(int8x16 a)
{
#if SIMDPP_USE_NULL
    return null::abs(a);
#elif SIMDPP_USE_SSSE3
    return _mm_abs_epi8(a);
#elif SIMDPP_USE_SSE2
    int8x16 t;
    t = cmp_lt(a, int8x16::zero());
    a = bit_xor(a, t);
    a = sub(a, t);
    return a;
#elif SIMDPP_USE_NEON
    return int8x16(vabsq_s8(a));
#endif
}

inline uint8x32 abs(int8x32 a)
{
#if SIMDPP_USE_AVX2
    return _mm256_abs_epi8(a);
#else
    return {abs(a[0]), abs(a[1])};
#endif
}
/// @}

/// @{
/** Computes absolute value of 16-bit integer values.

    @code
    r0 = abs(a0)
    ...
    rN = abs(aN)
    @endcode
    @par 128-bit version:
    @icost{SSE2-SSE3, 4}

    @par 256-bit version:
    @icost{SSE2-SSE3, 8}
    @icost{SSSE3-AVX, NEON, 2}
*/
inline uint16x8 abs(int16x8 a)
{
#if SIMDPP_USE_NULL
    return null::abs(a);
#elif SIMDPP_USE_SSSE3
    return _mm_abs_epi16(a);
#elif SIMDPP_USE_SSE2
    int16x8 t;
    t = cmp_lt(a, int16x8::zero());
    a = bit_xor(a, t);
    a = sub(a, t);
    return a;
#elif SIMDPP_USE_NEON
    return int16x8(vabsq_s16(a));
#endif
}

inline uint16x16 abs(int16x16 a)
{
#if SIMDPP_USE_AVX2
    return _mm256_abs_epi16(a);
#else
    return {abs(a[0]), abs(a[1])};
#endif
}
/// @}

/// @{
/** Computes absolute value of 32-bit integer values.

    @code
    r0 = abs(a0)
    ...
    rN = abs(aN)
    @endcode
    @par 128-bit version:
    @icost{SSE2-SSE3, 4}

    @par 256-bit version:
    @icost{SSE2-SSE3, 8}
    @icost{SSSE3-AVX, NEON, 2}
*/
inline uint32x4 abs(int32x4 a)
{
#if SIMDPP_USE_NULL
    return null::abs(a);
#elif SIMDPP_USE_SSSE3
    return _mm_abs_epi32(a);
#elif SIMDPP_USE_SSE2
    int32x4 t;
    t = cmp_lt(a, int32x4::zero());
    a = bit_xor(a, t);
    a = sub(a, t);
    return a;
#elif SIMDPP_USE_NEON
    return int32x4(vabsq_s32(a));
#endif
}

inline uint32x8 abs(int32x8 a)
{
#if SIMDPP_USE_AVX2
    return _mm256_abs_epi32(a);
#else
    return {abs(a[0]), abs(a[1])};
#endif
}
/// @}

/// @{
/** Computes absolute value of 64-bit integer values.

    @code
    r0 = abs(a0)
    ...
    rN = abs(aN)
    @endcode
    @par 128-bit version:
    @icost{SSE2-AVX, NEON, 5}

    @par 256-bit version:
    @icost{SSE2-AVX, NEON, 10}
    @icost{AVX2, 4}
*/
inline uint64x2 abs(int64x2 a)
{
#if SIMDPP_USE_NULL
    return null::abs(a);
#elif SIMDPP_USE_SSE4_1
    int64x2 t = shift_r<63>(uint64x2(a));
    t = _mm_cmpeq_epi64(t, int64x2::zero());
    t = bit_not(t);
    a = bit_xor(a, t);
    a = sub(a, t);
    return a;
#elif SIMDPP_USE_SSE2
    float64x2 ta;
    int64x2 t;
    ta = float64x2(shift_r<63>(uint64x2(a)));
    t = cmp_neq(ta, float64x2::zero());
    a = bit_xor(a, t);
    a = sub(a, t);
    return a;
#elif SIMDPP_USE_NEON
    int32x4 z = shift_r<63>(uint64x2(a));
    z = cmp_eq(z, int32x4::zero());
    z = permute<0,0,2,2>(z);
    z = bit_not(z);
    int64x2 t = z;
    a = bit_xor(a, t);
    a = sub(a, t);
    return a;
#endif
}

inline uint64x4 abs(int64x4 a)
{
#if SIMDPP_USE_AVX2
    int64x4 t;
    t = _mm256_cmpgt_epi64(int64x4::zero(), a);
    a = bit_xor(a, t);
    a = sub(a, t);
    return a;
#else
    return {abs(a[0]), abs(a[1])};
#endif
}
/// @}

/// @{
/** Divides one 8-bit unsigned number by another. The precision of the operation
    is configurable: only P least significant bits of both numerator and
    denumerator are considered.

    @code
    r0 = num0 / den0
    ...
    rN = numN / denN
    @endcode
    @par 128-bit version:
    The operations costs at least 9 instructions per bit of precision.

    @par 256-bit version:
    @icost{SSE2-AVX, NEON, 10}
    @icost{AVX2, 4}
*/
template<unsigned P>
uint8x16 div_p(uint8x16 num, uint8x16 den)
{
#if SIMDPP_USE_NULL
    return null::div_p<P>(num, den);
#else
    static_assert(P <= 8, "Precision too large");
    uint8x16 r, q, bit_mask;
    r = q = uint8x16::zero();
    bit_mask = uint8x16::make_const(1 << (P-1));

    for (unsigned i = P; i > 0; i--) {
        unsigned bit = i-1;
        uint8x16 n_bit;
        // we'll never shift out any bits, so larger shift doesn't matter
        r = shift_l<1>((uint16x8)r);

        n_bit = bit_and(num, bit_mask);
        n_bit = shift_r((uint16x8)n_bit, bit);
        r = bit_or(r, n_bit);

        uint8x16 cmp, csub, cbit;
        cmp = cmp_lt(r, den);

        csub = bit_andnot(den, cmp);
        cbit = bit_andnot(bit_mask, cmp);
        r = sub(r, csub);
        q = bit_or(q, cbit);

        bit_mask = shift_r<1>((uint16x8)bit_mask);
    }
    return q;

    /*
    The actual algorithm is as follows:
    N - numerator, D - denominator, R - remainder, Q - quetient
    R = 0; Q = 0;
    for (unsigned i = P; i > 0; i--) {
        unsigned bit = i-1;
        R <<= 1;
        R |= (N >> bit) & 1;
        if (R >= D) {
            R = R - D;
            Q |= 1 << bit;
        }
    }*/
#endif
}

template<unsigned P>
uint16x8 div_p(uint16x8 num, uint16x8 den)
{
#if SIMDPP_USE_NULL
    return null::div_p<P>(num, den);
#else
    static_assert(P <= 16, "Precision too large");
    uint16x8 r, q, bit_mask;

    r = q = uint16x8::zero();
    bit_mask = uint16x8::make_const(1 << (P-1));

    for (unsigned i = P; i > 0; i--) {
        unsigned bit = i-1; // TODO precision
        uint16x8 n_bit;
        r = shift_l<1>(r);

        n_bit = bit_and(num, bit_mask);
        n_bit = shift_r(n_bit, bit);
        r = bit_or(r, n_bit);

        uint16x8 cmp, csub, cbit;
        cmp = cmp_lt(r, den);

        csub = bit_andnot(den, cmp);
        cbit = bit_andnot(bit_mask, cmp);
        r = sub(r, csub);
        q = bit_or(q, cbit);

        bit_mask = shift_r<1>(bit_mask);
    }
    return q;
#endif
}

/// @}

SIMDPP_ARCH_NAMESPACE_END
} // namespace simdpp

#endif
