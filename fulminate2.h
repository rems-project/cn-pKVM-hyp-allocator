#define __cerbvar_NULL 0
#include <assert.h>
// Temporary workaround for a Cerberus frontend issue
#if defined(__linux__) && defined(__GNUC__)
#define __builtin_bswap64 __builtin_bswap64_2
#endif
