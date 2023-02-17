#ifndef INCLUDE_SU_STRING_VIEW_H
#define INCLUDE_SU_STRING_VIEW_H
#include <stddef.h>
#include <stdbool.h>

#define STRING_VIEW_FMT "%.*s"
#define STRING_VIEW_FMT_ARGS(sv) (int) (sv).size, (sv).data

typedef struct string_view string_view_t;

struct string_view {
    const char*  data;
    size_t size;
};

string_view_t sv_construct(const char* data, size_t size);
string_view_t sv_cstr_construct(const char* str);
string_view_t sv_trim_left(string_view_t sv);
string_view_t sv_trim_right(string_view_t sv);
string_view_t sv_trim(string_view_t sv);
string_view_t sv_remove_left(string_view_t sv, size_t n);
string_view_t sv_remove_right(string_view_t sv, size_t n);
string_view_t sv_chop_left(string_view_t sv, size_t n);
string_view_t sv_chop_right(string_view_t sv, size_t n);
bool sv_equal(string_view_t sv1, string_view_t sv2);

#endif //INCLUDE_SU_STRING_VIEW_H
