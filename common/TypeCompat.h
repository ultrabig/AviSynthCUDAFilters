#ifndef COMMON_TYPECOMPAT_H
#ifndef _WIN32
#include <cstdint>
#include <cmath>

typedef int64_t __int64;
#define cos std::cos
#define __forceinline __attribute__((always_inline))

#endif

#endif

#define COMMON_TYPECOMPAT_H
