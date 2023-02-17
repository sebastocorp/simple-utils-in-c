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
