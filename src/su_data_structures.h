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

#ifndef SUDS_HT_KEY_LENGTH
#define SUDS_HT_KEY_LENGTH 64
#endif

#ifndef SUDS_HT_TABLE_LENGTH
#define SUDS_HT_TABLE_LENGTH 256
#endif

#ifndef SUDS_HT_DATA_TYPE
#define SUDS_HT_DATA_TYPE int
#endif

/**
 * @typedef typedef struct ht_node_t ht_node_t
 * @brief typedef.
 * @warning ojooooo.
 */
typedef struct ht_node ht_node_t;
/**
 * @struct ht_node_t
 * @brief struct.
 * @warning ojooooo.
 */
struct ht_node {
    SUDS_HT_DATA_TYPE data;
    char key[SUDS_HT_KEY_LENGTH];
    ht_node_t* next;
};

/**
 * @typedef typedef ht_node_t* ht_t[SUDS_HT_TABLE_LENGTH]
 * @brief typedef.
 * @warning ojooooo.
 */
typedef ht_node_t* ht_t[SUDS_HT_TABLE_LENGTH];

/**
 * @fn void ht_init(ht_t *ht)
 * @brief function.
 * @param ht the prefix.
 * @return void.
 * @warning warn.
 */
void ht_init(ht_t *ht);

/**
 * @fn void ht_print(ht_t* const ht)
 * @brief function.
 * @param ht pointer to the hash map.
 * @return void.
 */
void ht_print(ht_t* const ht);

/**
 * @fn size_t ht_hash(const char* key)
 * @brief function.
 * @param key pointer to the key.
 * @return size_t.
 */
size_t ht_hash(const char* key);

/**
 * @fn int ht_insert(ht_t* ht, ht_node_t* const node)
 * @brief function.
 * @param ht pointer to the hash map.
 * @param node pointer to the node.
 * @return size_t.
 */
int ht_insert(ht_t* ht, ht_node_t* const node);

/**
 * @fn ht_node_t* ht_delete(ht_t* ht, const char* key)
 * @brief function.
 * @param ht pointer to the hash map.
 * @param key pointer to the key.
 * @return size_t.
 */
ht_node_t* ht_delete(ht_t* ht, const char* key);

/**
 * @fn ht_node_t* ht_find(const ht_t* const ht, const char* key)
 * @brief function.
 * @param ht pointer to the hash map.
 * @param key pointer to the key.
 * @return size_t.
 */
ht_node_t* ht_find(const ht_t* const ht, const char* key);

#endif // INCLUDE_SU_DATA_STRUCTURES_H

#ifdef SU_DATA_STRUCTURES_IMPLEMENTATION

void ht_init(ht_t *ht) {
    for (size_t i = 0; i < SUDS_HT_TABLE_LENGTH; ++i) {
        (*ht)[i] = NULL;
    }
}

void ht_print(ht_t* const ht) {
    printf("[\n");
    for (size_t i = 0; i < SUDS_HT_TABLE_LENGTH; ++i) {
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
    for (size_t i = 0; i < SUDS_HT_KEY_LENGTH && key[i] != '\0'; ++i) {
        hash_value += key[i];
        hash_value = (hash_value * key[i]) % SUDS_HT_TABLE_LENGTH;
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
    while (tmp != NULL && strncmp(tmp->key, key, SUDS_HT_KEY_LENGTH) != 0) {
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
    while (tmp != NULL && strncmp(tmp->key, key, SUDS_HT_KEY_LENGTH) != 0) {
        tmp = tmp->next;
    }
    return tmp;
}

#endif
