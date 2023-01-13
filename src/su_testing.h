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

#ifdef SU_TESTING_IMPLEMENTATION

void test_check_current_case_condition(test_t* t, bool condition)
{
    t->current_test.current_case.result = "FAIL";
    if (condition) {
        ++t->current_test.passed;
        t->current_test.current_case.result = "PASS";
    }

    if (t->verbose) fprintf(stdout, "[CURRENT CASE RESULT] %s: %s\n",
                            t->current_test.current_case.name,
                            t->current_test.current_case.result);
}

void test_check_current_test_percentage(test_t* t, size_t percentage)
{
    t->current_test.result = "FAIL";
    size_t result = ((t->current_test.passed*100)/t->current_test.total);
    if (percentage <= result) {
        t->current_test.result = "PASS";
    }

    if (t->verbose) fprintf(stdout, "[CURRENT TEST RESULTS] %s (%ld%%): %s\n",
                            t->current_test.name, result,
                            t->current_test.result);
}

void test_check_test_percentage(test_t* t, size_t percentage)
{
    t->result = "FAIL";
    size_t result = ((t->passed*100)/t->total);
    if (percentage <= result) {
        t->result = "PASS";
    }

    fprintf(stdout, "[MODULE TEST RESULTS] %s (%ld%%): %s\n", t->name, result, t->result);
}

#endif //SU_TESTING_IMPLEMENTATION
