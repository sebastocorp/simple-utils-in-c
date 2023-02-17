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
