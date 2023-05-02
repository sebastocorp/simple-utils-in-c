#ifndef INCLUDE_SU_STRING_VIEW_H
#define INCLUDE_SU_STRING_VIEW_H
#include <stddef.h>
#include <stdbool.h>

#define STRING_VIEW_FMT "%.*s"
#define STRING_VIEW_FMT_ARGS(sv) (int) (sv).size, (sv).data

typedef struct SU_StringView SU_StringView;

struct SU_StringView {
    const char*  data;
    size_t size;
};

SU_StringView SU_StringView_Construct(const char* data, size_t size);
SU_StringView SU_StringView_Construct1cstr(const char* str);
SU_StringView SU_StringView_TrimLeft(SU_StringView sv);
SU_StringView SU_StringView_TrimRight(SU_StringView sv);
SU_StringView SU_StringView_Trim(SU_StringView sv);
SU_StringView SU_StringView_RemoveLeft(SU_StringView sv, size_t n);
SU_StringView SU_StringView_RemoveRight(SU_StringView sv, size_t n);
SU_StringView SU_StringView_ChopLeft(SU_StringView sv, size_t n);
SU_StringView SU_StringView_ChopRight(SU_StringView sv, size_t n);
bool SU_StringView_Equal(SU_StringView sv1, SU_StringView sv2);

// Modifiers
void SU_StringView_RemovePrefix(SU_StringView* sv, size_t n);
void SU_StringView_RemoveSuffix(SU_StringView* sv, size_t n);
void SU_StringView_Swap(SU_StringView* sv, SU_StringView* v);

// Operations
size_t SU_StringView_Copy(const SU_StringView* sv, const char* dest, size_t count, size_t pos);
SU_StringView SU_StringView_Substr(const SU_StringView* sv, size_t pos, size_t count);
int SU_StringView_Compare(const SU_StringView* sv, SU_StringView v);
bool SU_StringView_StartsWith(const SU_StringView* sv, SU_StringView v);
bool SU_StringView_EndsWith(const SU_StringView* sv, SU_StringView v);
bool SU_StringView_Contains(const SU_StringView* sv, SU_StringView v);
size_t SU_StringView_Find(const SU_StringView* sv, SU_StringView v, size_t pos);
size_t SU_StringView_Rfind(const SU_StringView* sv, SU_StringView v, size_t npos);
size_t SU_StringView_FindFirstOf(const SU_StringView* sv, SU_StringView v, size_t pos);
size_t SU_StringView_FindLastOf(const SU_StringView* sv, SU_StringView v, size_t pos);
size_t SU_StringView_FindFirstNotOf(const SU_StringView* sv, SU_StringView v, size_t pos);
size_t SU_StringView_FindLastNotOf(const SU_StringView* sv, SU_StringView v, size_t pos);

#endif //INCLUDE_SU_STRING_VIEW_H
