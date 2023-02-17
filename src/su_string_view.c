#include <su_string_view.h>

#include <string.h>

string_view_t sv_construct(const char* data, size_t size)
{
    string_view_t sv = {
        .data = data,
        .size = size,
    };

    return sv;
}

string_view_t sv_cstr_construct(const char* str)
{
        string_view_t sv = {
        .data = str,
        .size = strlen(str),
    };

    return sv;
}

string_view_t sv_trim_left(string_view_t sv)
{
    size_t i = 0;
    while(i < sv.size && *(sv.data + i) == ' ') {
        ++i;
    }

    sv.data += i;
    sv.size -= i;

    return sv;
}

string_view_t sv_trim_right(string_view_t sv)
{
    size_t i = 0;
    while(i < sv.size && *(sv.data + sv.size - i - 1) == ' ') {
        ++i;
    }

    sv.size -= i;

    return sv;
}

string_view_t sv_trim(string_view_t sv)
{
    return sv_trim_left(sv_trim_right(sv));
}

string_view_t sv_remove_left(string_view_t sv, size_t n)
{
    if (n > sv.size) {
        n = sv.size;
    }

    sv.data += n;
    sv.size -= n;

    return sv;
}

string_view_t sv_remove_right(string_view_t sv, size_t n)
{
    if (n > sv.size) {
        n = sv.size;
    }

    sv.size -= n;

    return sv;
}

string_view_t sv_chop_left(string_view_t sv, size_t n)
{
    if (n > sv.size) {
        n = sv.size;
    }

    sv.size = n;

    return sv;
}

string_view_t sv_chop_right(string_view_t sv, size_t n)
{
    if (n > sv.size) {
        n = sv.size;
    }

    sv.data += sv.size - n;
    sv.size = n;

    return sv;
}

bool sv_equal(string_view_t sv1, string_view_t sv2)
{
    if (sv1.size != sv2.size) {
        return false;
    }

    return memcmp(sv1.data, sv2.data, sv1.size) == 0;
}
