#ifndef INCLUDE_SU_VECTOR_H
#define INCLUDE_SU_VECTOR_H

#include <stddef.h>
#include <stdbool.h>

#ifndef SU_VECTOR_DATA_TYPE
#define SU_VECTOR_DATA_TYPE int
#endif

typedef struct vector vector_t;
struct vector {
    SU_VECTOR_DATA_TYPE* data;
    size_t capacity;
    size_t size;
};

// constructors
vector_t vector_construct();
vector_t vector_construct1s(const size_t count);
vector_t vector_construct1pv(const vector_t* const other);
vector_t vector_construct1v(const vector_t other);
// destructors
vector_t vector_destruct();
// function at
SU_VECTOR_DATA_TYPE* vector_at(vector_t* const v, const size_t pos);
const SU_VECTOR_DATA_TYPE* vector_cat(const vector_t* const v, const size_t pos);
// function front
SU_VECTOR_DATA_TYPE* vector_front(vector_t* const v);
const SU_VECTOR_DATA_TYPE* vector_cfront(const vector_t* const v);
// function back
SU_VECTOR_DATA_TYPE* vector_back(vector_t* const v);
const SU_VECTOR_DATA_TYPE* vector_cback(const vector_t* const v);
// function data????
SU_VECTOR_DATA_TYPE* vector_data(vector_t* const v);
const SU_VECTOR_DATA_TYPE* vector_cdata(const vector_t* const v);
// functions begin cbegin
SU_VECTOR_DATA_TYPE* vector_begin(vector_t* const v);
const SU_VECTOR_DATA_TYPE* vector_cbegin(const vector_t* const v);
// function end cend
SU_VECTOR_DATA_TYPE* vector_end(vector_t* const v);
const SU_VECTOR_DATA_TYPE* vector_cend(const vector_t* const v);
// function rbegin crbegin
SU_VECTOR_DATA_TYPE* vector_rbegin(vector_t* const v);
const SU_VECTOR_DATA_TYPE* vector_crbegin(const vector_t* const v);
// function rend crend
SU_VECTOR_DATA_TYPE* vector_rend(vector_t* const v);
const SU_VECTOR_DATA_TYPE* vector_crend(const vector_t* const v);
//function empty
bool vector_empty(const vector_t* const v);
// function size???
size_t vector_size(const vector_t* const v);
// function max_size
size_t vector_max_size(const vector_t* const v);
// function reserve
void vector_reserve(vector_t* const v, const size_t new_cap);
// function capacity?????
size_t vector_capacity(const vector_t* const v);
// function clear
void vector_clear(vector_t* const v);
// function insert
SU_VECTOR_DATA_TYPE* vector_insert(vector_t* const v, SU_VECTOR_DATA_TYPE* pos, const SU_VECTOR_DATA_TYPE* const value);
// function emplace
SU_VECTOR_DATA_TYPE* vector_emplace(vector_t* const v, SU_VECTOR_DATA_TYPE* pos, ...);
// function erase
SU_VECTOR_DATA_TYPE* vector_erase(vector_t* const v, SU_VECTOR_DATA_TYPE* pos);
// function push_back
void vector_push_back(vector_t* const v, const SU_VECTOR_DATA_TYPE* const value);
void vector_push_back1dt(vector_t* const v, const SU_VECTOR_DATA_TYPE value);
// function emplace_back
void vector_emplace_back(vector_t* const v, ...);
// function pop_back
void vector_pop_back(vector_t* const v);
// function resize
void vector_resize(vector_t* const v, const size_t count);
void vector_vAdd_resize(vector_t* const v, const size_t count, SU_VECTOR_DATA_TYPE value);
void vector_pAdd_resize(vector_t* const v, const size_t count, const SU_VECTOR_DATA_TYPE* const value);
// function swap
void vector_swap(vector_t* const v, vector_t* const other);


#endif // INCLUDE_SU_VECTOR_H
