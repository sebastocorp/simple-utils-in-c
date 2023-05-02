#include <simple-utils/data_structures.h>

#include <stdio.h>

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
        hash_value += (size_t) key[i];
        hash_value = (hash_value * (size_t) key[i]) % SUDS_HT_TABLE_LENGTH;
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
