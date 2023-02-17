#include <su_flags.h>

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
