#include <simple-utils/std/string_view.h>

#include <string.h>

SU_StringView SU_StringView_Construct(const char* data, size_t size)
{
    SU_StringView sv = {
        .data = data,
        .size = size,
    };

    return sv;
}

SU_StringView SU_StringView_Construct1cstr(const char* str)
{
    SU_StringView sv = {
        .data = str,
        .size = strlen(str),
    };

    return sv;
}

SU_StringView SU_StringView_TrimLeft(SU_StringView sv)
{
    size_t i = 0;
    while(i < sv.size && *(sv.data + i) == ' ') {
        ++i;
    }

    sv.data += i;
    sv.size -= i;

    return sv;
}

SU_StringView SU_StringView_TrimRight(SU_StringView sv)
{
    size_t i = 0;
    while(i < sv.size && *(sv.data + sv.size - i - 1) == ' ') {
        ++i;
    }

    sv.size -= i;

    return sv;
}

SU_StringView SU_StringView_Trim(SU_StringView sv)
{
    return SU_StringView_TrimLeft(SU_StringView_TrimRight(sv));
}

SU_StringView SU_StringView_RemoveLeft(SU_StringView sv, size_t n)
{
    if (n > sv.size) {
        n = sv.size;
    }

    sv.data += n;
    sv.size -= n;

    return sv;
}

SU_StringView SU_StringView_RemoveRight(SU_StringView sv, size_t n)
{
    if (n > sv.size) {
        n = sv.size;
    }

    sv.size -= n;

    return sv;
}

SU_StringView SU_StringView_ChopLeft(SU_StringView sv, size_t n)
{
    if (n > sv.size) {
        n = sv.size;
    }

    sv.size = n;

    return sv;
}

SU_StringView SU_StringView_ChopRight(SU_StringView sv, size_t n)
{
    if (n > sv.size) {
        n = sv.size;
    }

    sv.data += sv.size - n;
    sv.size = n;

    return sv;
}

bool SU_StringView_Equal(SU_StringView sv1, SU_StringView sv2)
{
    if (sv1.size != sv2.size) {
        return false;
    }

    return memcmp(sv1.data, sv2.data, sv1.size) == 0;
}
