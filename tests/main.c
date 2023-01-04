#include <stdio.h>
#include <string.h>

#define SU_TESTING_IMPLEMENTATION
#include "../src/su_testing.h"

#include "susv/susv_test.c"

void (*susv_tests[])(test_t* t) = {
        susv_sv_construct_test,
        susv_sv_cstr_construct_test,
        susv_sv_trim_left_test,
        susv_sv_trim_right_test,
        susv_sv_trim_test,
        susv_sv_remove_left_test,
        susv_sv_remove_right_test,
        susv_sv_chop_left_test,
        susv_sv_chop_right_test,
        susv_sv_equal_test,
};

int main(int argc, char const* argv[])
{
    size_t length = sizeof(susv_tests)/sizeof(susv_tests[0]);

    test_t t = {
            .verbose = false,
    };

    if (argc > 1) {
        for (int i = 1; i < argc; ++i) {
            if (strcmp(*argv, "--verbose")) t.verbose = true;
        }
    }

    fprintf(stdout, "################################################################################\n");
    t.name = "su_string_view";
    fprintf(stdout, "### TESTING MODULE: %s\n", t.name);
    fprintf(stdout, "################################################################################\n");
    for (size_t i = 0; i < length; ++i) {
        t.current_test.total = 0;
        t.current_test.passed = 0;
        susv_tests[i](&t);
        t.total += t.current_test.total;
        t.passed += t.current_test.passed;
        test_check_current_test_percentage(&t, 100);
        if (t.verbose) fprintf(stdout, "================================================\n");
    }
    test_check_test_percentage(&t, 100);
    fprintf(stdout, "################################################################################\n");
    return 0;
}
