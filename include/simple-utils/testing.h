#ifndef INCLUDE_SU_TESTING_H
#define INCLUDE_SU_TESTING_H
#include <stddef.h>
#include <stdbool.h>

typedef struct test test_t;

struct test {
    const char* name;
    const char* result;
    size_t passed;
    size_t total;
    bool verbose;
    struct {
        const char* name;
        const char* result;
        size_t passed;
        size_t total;
        struct {
            const char* name;
            const char* result;
        } current_case;
    } current_test;
};

void test_check_current_case_condition(test_t* t, bool condition);
void test_check_current_test_percentage(test_t* t, size_t percentage);
void test_check_test_percentage(test_t* t, size_t percentage);

#endif //INCLUDE_SU_TESTING_H
