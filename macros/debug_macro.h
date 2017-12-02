#ifndef __debug_macro__
#define __debug_macro__

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#ifdef NDEBUG
#define log_debug(fmt, ...)  do {} while (0)
#define log_err(fmt, ...)  do {} while (0)
#define log_warn(fmt, ...)  do {} while (0)
#define log_info(fmt, ...)  do {} while (0)
#else // NDEBUG

#define log_debug(fmt, ...)\
        do { fprintf(stderr, "[DEBUG] %10s:%10d:%15s(): " fmt, __FILE__, __LINE__, __func__,## __VA_ARGS__); } while (0)

#define log_err(fmt, ...) \
        do { fprintf(stderr, "[ERROR] %10s:%10d:%15s(): " fmt, __FILE__,  __LINE__, __func__,## __VA_ARGS__); } while (0)

#define log_warn(fmt, ...) \
        do { fprintf(stderr, "[WARN] %10s:%10d:%15s(): " fmt, __FILE__, \
                                __LINE__, __func__, ##__VA_ARGS__); } while (0)
#define log_info(fmt, ...) \
        do { fprintf(stderr, "[INFO] %10s:%10d:%15s(): " fmt, __FILE__, \
                                __LINE__, __func__, ##__VA_ARGS__); } while (0)
#endif //NDEBUG

#endif // __debug_macro__
