#include <stdio.h>

#define HT_TABLE_LENGTH 5
#define HT_KEY_LENGTH 20
#define SDS_IMPLEMENTATION

#include "../../src/su_data_structures.h"

#define UNUSED(x) (void) x;
#define VAR_NAME(var) #var

SDS_HT_DECLARATION_TEMPLATE(int)

int main(int argc, char const *argv[]) {
    UNUSED(argc)
    UNUSED(argv)
    SDS_HT_NODE_TYPE(int) t;
    SDS_HT_TYPE(int) ht;
    UNUSED(t)
    UNUSED(ht)


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
    ht_node_t c = {
            .data = 0,
            .key = "Kate",
            .next = NULL,
    };
    ht_node_t d = {
            .data = 0,
            .key = "Robert",
            .next = NULL,
    };
    ht_node_t e = {
            .data = 0,
            .key = "Jacob",
            .next = NULL,
    };
    ht_node_t f = {
            .data = 0,
            .key = "Jacob",
            .next = NULL,
    };

    ht_init(&table);
    ht_print(&table);
    ht_insert(&table, &a);
    ht_insert(&table, &b);
    ht_insert(&table, &c);
    ht_insert(&table, &d);
    ht_insert(&table, &e);
    ht_insert(&table, &f);
    ht_print(&table);

    UNUSED(table)
    UNUSED(a)
    UNUSED(b)
    UNUSED(c)
    UNUSED(d)
    UNUSED(e)
    UNUSED(f)

    return 0;
}
