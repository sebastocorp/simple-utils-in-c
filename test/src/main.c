#include <stdio.h>
#include <string.h>

#include "simple-utils/std/string_view_test.h"

int main(int argc, char const* argv[])
{
    size_t length = sizeof(string_view_tests)/sizeof(string_view_tests[0]);

    test_t t = {
            .verbose = false,
    };

    if (argc > 1) {
        for (int i = 1; i < argc; ++i) {
            if (strcmp(*argv, "--verbose") >= 0) t.verbose = true;
        }
    }

    fprintf(stdout, "################################################################################\n");
    t.name = "string_view";
    fprintf(stdout, "### TESTING MODULE: %s\n", t.name);
    fprintf(stdout, "################################################################################\n");
    for (size_t i = 0; i < length; ++i) {
        t.current_test.total = 0;
        t.current_test.passed = 0;
        string_view_tests[i](&t);
        t.total += t.current_test.total;
        t.passed += t.current_test.passed;
        test_check_current_test_percentage(&t, 100);
        if (t.verbose) fprintf(stdout, "================================================\n");
    }
    test_check_test_percentage(&t, 100);
    fprintf(stdout, "################################################################################\n");
    return 0;
}
