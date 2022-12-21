/**
 * @file su_data_structures.h
 * @version 0.0.1
 * @date 20/12/2022
 * @author Sebastian Vargas Beltran
 * @brief library.
 * @code
#include "../src/su_data_structures.h"

int main(void) {
    ht_t table;
    ht_node_t a = {
            .data = 0,
            .key = "Maren",
            .next = NULL,
    };
    ht_node_t b = {
            .data = 0,
            .key = "Jane",
            .next = NULL,
    };

    ht_init(&table);
    ht_insert(&table, &a);
    ht_insert(&table, &b);
    ht_print(&table);

    return 0;
}
 * @endcode
 */
#ifndef INCLUDE_SU_DATA_STRUCTURES_H
#define INCLUDE_SU_DATA_STRUCTURES_H

//**********************************************************************************************************************
// HASH TABLE
//**********************************************************************************************************************

#include <string.h>

#ifndef HT_KEY_LENGTH
#define HT_KEY_LENGTH 64
#endif

#ifndef HT_TABLE_LENGTH
#define HT_TABLE_LENGTH 256
#endif

#ifndef HT_DATA_TYPE
#define HT_DATA_TYPE int
#endif

/**
 * @typedef typedef struct ht_node_t ht_node_t
 * @brief typedef.
 * @warning ojooooo.
 */
typedef struct ht_node_t ht_node_t;
/**
 * @struct ht_node_t
 * @brief struct.
 * @warning ojooooo.
 */
struct ht_node_t {
    HT_DATA_TYPE data;
    char key[HT_KEY_LENGTH];
    ht_node_t* next;
};

/**
 * @typedef typedef ht_node_t* ht_t[HT_TABLE_LENGTH]
 * @brief typedef.
 * @warning ojooooo.
 */
typedef ht_node_t* ht_t[HT_TABLE_LENGTH];

/**
 * @fn void ht_init(ht_t *ht)
 * @brief function.
 * @param ht the prefix.
 * @return void.
 * @warning ojooooo.
 */
void ht_init(ht_t *ht) {
    for (size_t i = 0; i < HT_TABLE_LENGTH; ++i) {
        (*ht)[i] = NULL;
    }
}

void ht_print(ht_t* const ht) {
    printf("[\n");
    for (size_t i = 0; i < HT_TABLE_LENGTH; ++i) {
        if ((*ht)[i] == NULL) {
            printf("  %li  ---\n", i);
        } else {
            printf("  %li  ", i);
            ht_node_t* tmp = (*ht)[i];
            while (tmp != NULL) {
                printf("%s - ", tmp->key);
                tmp = tmp->next;
            }
            printf("\n");
        }
    }
    printf("]\n");
}

size_t ht_hash(const char* key) {
    size_t hash_value = 0;
    for (size_t i = 0; i < HT_KEY_LENGTH && key[i] != '\0'; ++i) {
        hash_value += key[i];
        hash_value = (hash_value * key[i]) % HT_TABLE_LENGTH;
    }
    return hash_value;
}

int ht_insert(ht_t* ht, ht_node_t* const node) {
    if (node == NULL) return -1;
    size_t index = ht_hash(node->key);
    node->next = (*ht)[index];
    (*ht)[index] = node;
    return 0;
}

ht_node_t* ht_delete(ht_t* ht, const char* key) {
    size_t index = ht_hash(key);
    ht_node_t* tmp = (*ht)[index];
    ht_node_t* prev = NULL;
    while (tmp != NULL && strncmp(tmp->key, key, HT_KEY_LENGTH) != 0) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL) return NULL;
    if (prev == NULL) {
        (*ht)[index] = tmp->next;
    } else {
        prev->next = tmp->next;
    }
    return tmp;
}

ht_node_t* ht_find(const ht_t* const ht, const char* key) {
    size_t index = ht_hash(key);
    ht_node_t* tmp = (*ht)[index];
    while (tmp != NULL && strncmp(tmp->key, key, HT_KEY_LENGTH) != 0) {
        tmp = tmp->next;
    }
    return tmp;
}

//**********************************************************************************************************************
// GENERAL TEMPLATES
//**********************************************************************************************************************

/**
 * @def SDS_GEN_NAME_WITH_AFFIX(prefix, name, suffix)
 * @brief A simple macro that concatenate the \a prefix, \a name and \a suffix passed in the parameters to generate a
 * word to use as a variable type or a function name.
 * @param prefix the prefix.
 * @param name the prefix.
 * @param suffix the prefix.
 */
#define SDS_GEN_NAME_WITH_AFFIX(prefix, name, suffix) prefix##name##suffix


//**********************************************************************************************************************
// HASH TABLE TEMPLATES
//**********************************************************************************************************************

/**
 * SDS_HT_GEN_NAME
 */
#define SDS_HT_GEN_NAME(type, suffix) SDS_GEN_NAME_WITH_AFFIX(ht_,type,suffix)
/**
 * SDS_HT_NODE_TYPE
 */
#define SDS_HT_NODE_TYPE(type) SDS_HT_GEN_NAME(type,_node_t)
/**
 * SDS_HT_TYPE
 */
#define SDS_HT_TYPE(type) SDS_HT_GEN_NAME(type,_t)

/**
 * SDS_HT_DECLARATION_TEMPLATE
 *
 * A macro that generate the header of a hash table with a value of the same type than the argument.
 */
#define SDS_HT_DECLARATION_TEMPLATE(type)                     \
typedef struct SDS_HT_NODE_TYPE(type) SDS_HT_NODE_TYPE(type); \
\
struct SDS_HT_NODE_TYPE(type) {   \
    type data;                    \
    char key[HT_KEY_LENGTH];      \
    SDS_HT_NODE_TYPE(type)* next; \
};                                \
\
typedef SDS_HT_NODE_TYPE(type)* SDS_HT_TYPE(type)[HT_TABLE_LENGTH];

#define SDS_HT_DEFINITION_TEMPLATE(type)                            \
typedef SDS_HT_NODE_TYPE(type)* SDS_HT_TYPE(type)[HT_TABLE_LENGTH]; \
\
void SDS_HT_GEN_NAME(type,_init)(SDS_HT_TYPE(type)* ht) { \
    for (size_t i = 0; i < HT_TABLE_LENGTH; ++i) {        \
        (*ht)[i] = NULL;                                  \
    }                                                     \
}                                                         \
\
void SDS_HT_GEN_NAME(type,_print)(SDS_HT_TYPE(type)* const ht) { \
    size_t i = 0;                                                \
    printf("[");                                                 \
    for (; i < HT_TABLE_LENGTH - 1; ++i) {                       \
        printf("{%li : %p}, ", i, (void*) (*ht)[i]);             \
    }                                                            \
    printf("{%li : %p}]\n", i, (void*) (*ht)[i]);                \
}                                                                \
\
int SDS_HT_GEN_NAME(type,_insert)(SDS_HT_TYPE(type)* ht, SDS_HT_NODE_TYPE(type)* const node) { \
    if(node == NULL) return -1;                                                                \
    size_t index = ht_hash(node->key);                                                         \
    node->next = (*ht)[index];                                                                 \
    (*ht)[index] = node;                                                                       \
    return 0;                                                                                  \
}


#endif // INCLUDE_SU_DATA_STRUCTURES_H

#ifdef SU_DATA_STRUCTURES_IMPLEMENTATION
#endif
