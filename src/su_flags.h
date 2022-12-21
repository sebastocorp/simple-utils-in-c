/**
 * @file su_flags.h
 * @version 0.0.1
 * @date 20/12/2022
 * @author Sebastian Vargas Beltran
 * @brief library.
 * @code
#include "../src/su_flags.h"

int main(void) {
    return 0;
}
 * @endcode
 */
#ifndef INCLUDE_SU_FLAGS_H
#define INCLUDE_SU_FLAGS_H

#include <inttypes.h>
#include <stdbool.h>

bool* flag_bool(const char* name, bool value, const char* usage);
int32_t* flag_int32(const char* name, int32_t value, const char* usage);
int64_t* flag_int64(const char* name, int64_t value, const char* usage);
uint32_t* flag_uint32(const char* name, uint32_t value, const char* usage);
uint64_t* flag_uint64(const char* name, uint64_t value, const char* usage);
float* flag_float32(const char* name, float value, const char* usage);
double* flag_float64(const char* name, double value, const char* usage);
const char** flag_string(const char* name, const char* value, const char* usage);
void flag_print_usage(void);
void flag_parse(void);

#endif //INCLUDE_SU_FLAGS_H

#ifdef SU_FLAGS_IMPLEMENTATION

typedef enum {
    FLAG_BOOL = 0,
    FLAG_I32,
    FLAG_I64,
    FLAG_U32,
    FLAG_U64,
    FLAG_F32,
    FLAG_F64,
    FLAG_STR,
} flag_type;

typedef union {
    bool b;
    int32_t i32;
    int64_t i64;
    uint32_t u32;
    uint64_t u64;
    float f32;
    double f64;
    char* str;
} flag_data_t;

typedef struct {
    flag_type type;
    flag_data_t value;
    flag_data_t default_value;
    const char* name;
    const char* short_name;
    const char* usage;
} flag_t;

#endif
