#include <su_testing.h>

#include <stdio.h>

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
