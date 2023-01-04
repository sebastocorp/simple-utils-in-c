#include <stdio.h>
#include <string.h>

#define SU_STRING_VIEW_IMPLEMENTATION
#include "../../src/su_string_view.h"

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

void susv_sv_construct_test(test_t* t)
{
    t->current_test.name = __func__;

    struct test_case {
        const char* name;
        string_view_t input;
        string_view_t expected;
    };

    const char* str_example = "string literal example";
    struct test_case test_cases[] = {
            {
                .name = "construct a string_view_t",
                .input = {
                        .data = str_example,
                        .size = strlen(str_example),
                },
                .expected = {
                        .data = str_example,
                        .size = strlen(str_example),
                }
            },
    };
    t->current_test.total = sizeof(test_cases)/sizeof(test_cases[0]);

    for (size_t i = 0; i < t->current_test.total; ++i) {
        t->current_test.current_case.name = test_cases[i].name;

        string_view_t sv = sv_construct(test_cases[i].input.data, test_cases[i].input.size);

        bool condition = sv.data == test_cases[i].expected.data &&
                         sv.size == test_cases[i].expected.size;
        test_check_current_case_condition(t, condition);
    }
}

void susv_sv_cstr_construct_test(test_t* t)
{
    t->current_test.name = __func__;

    struct test_case {
        const char* name;
        const char* input;
        string_view_t expected;
    };

    const char* str_example = "string literal example";
    struct test_case test_cases[] = {
            {
                .name = "construct a string_view_t with cstr",
                .input = str_example,
                .expected = {
                        .data = str_example,
                        .size = strlen(str_example),
                }
            },
    };
    t->current_test.total = sizeof(test_cases)/sizeof(test_cases[0]);

    for (size_t i = 0; i < t->current_test.total; ++i) {
        t->current_test.current_case.name = test_cases[i].name;

        string_view_t sv = sv_cstr_construct(test_cases[i].input);
        bool condition = sv.data == test_cases[i].expected.data &&
                         sv.size == test_cases[i].expected.size;
        test_check_current_case_condition(t, condition);
    }
}

void susv_sv_trim_left_test(test_t* t)
{
    t->current_test.name = __func__;

    struct test_case {
        const char* name;
        string_view_t input;
        string_view_t expected;
    };

    const char* str_example_with_spaces = "    string literal example";
    const char* str_example_without_spaces = "string literal example";
    struct test_case test_cases[] = {
            {
                .name = "trim left a string_view_t with spaces",
                .input = {
                        .data = str_example_with_spaces,
                        .size = strlen(str_example_with_spaces),
                },
                .expected = {
                        .data = str_example_with_spaces + 4,
                        .size = strlen(str_example_without_spaces),
                },
            },
            {
                .name = "trim left a string_view_t without spaces",
                .input = {
                        .data = str_example_without_spaces,
                        .size = strlen(str_example_without_spaces),
                },
                .expected = {
                        .data = str_example_without_spaces,
                        .size = strlen(str_example_without_spaces),
                },
            },
    };
    t->current_test.total = sizeof(test_cases)/sizeof(test_cases[0]);

    for (size_t i = 0; i < t->current_test.total; ++i) {
        t->current_test.current_case.name = test_cases[i].name;

        string_view_t sv = sv_trim_left(test_cases[i].input);

        bool condition = sv.data == test_cases[i].expected.data &&
                         sv.size == test_cases[i].expected.size;
        test_check_current_case_condition(t, condition);
    }
}

void susv_sv_trim_right_test(test_t* t)
{
    t->current_test.name = __func__;

    struct test_case {
        const char* name;
        string_view_t input;
        string_view_t expected;
    };

    const char* str_example_with_spaces = "string literal example    ";
    const char* str_example_without_spaces = "string literal example";
    struct test_case test_cases[] = {
            {
                .name = "trim right a string_view_t with spaces",
                .input = {
                        .data = str_example_with_spaces,
                        .size = strlen(str_example_with_spaces),
                },
                .expected = {
                        .data = str_example_with_spaces,
                        .size = strlen(str_example_without_spaces),
                },
            },
            {
                .name = "trim right a string_view_t without spaces",
                .input = {
                        .data = str_example_without_spaces,
                        .size = strlen(str_example_without_spaces),
                },
                .expected = {
                        .data = str_example_without_spaces,
                        .size = strlen(str_example_without_spaces),
                },
            },
    };
    t->current_test.total = sizeof(test_cases)/sizeof(test_cases[0]);

    for (size_t i = 0; i < t->current_test.total; ++i) {
        t->current_test.current_case.name = test_cases[i].name;

        string_view_t sv = sv_trim_right(test_cases[i].input);

        bool condition = sv.data == test_cases[i].expected.data &&
                         sv.size == test_cases[i].expected.size;
        test_check_current_case_condition(t, condition);
    }
}

void susv_sv_trim_test(test_t* t)
{
    t->current_test.name = __func__;

    struct test_case {
        const char* name;
        string_view_t input;
        string_view_t expected;
    };

    const char* str_example_with_spaces = "    string literal example    ";
    const char* str_example_without_spaces = "string literal example";
    struct test_case test_cases[] = {
            {
                .name = "trim a string_view_t with spaces",
                .input = {
                        .data = str_example_with_spaces,
                        .size = strlen(str_example_with_spaces),
                },
                .expected = {
                        .data = str_example_with_spaces + 4,
                        .size = strlen(str_example_without_spaces),
                },
            },
            {
                .name = "trim a string_view_t without spaces",
                .input = {
                        .data = str_example_without_spaces,
                        .size = strlen(str_example_without_spaces),
                },
                .expected = {
                        .data = str_example_without_spaces,
                        .size = strlen(str_example_without_spaces),
                },
            },
    };
    t->current_test.total = sizeof(test_cases)/sizeof(test_cases[0]);

    for (size_t i = 0; i < t->current_test.total; ++i) {
        t->current_test.current_case.name = test_cases[i].name;

        string_view_t sv = sv_trim(test_cases[i].input);

        bool condition = sv.data == test_cases[i].expected.data &&
                         sv.size == test_cases[i].expected.size;
        test_check_current_case_condition(t, condition);
    }
}

void susv_sv_remove_left_test(test_t* t)
{
    t->current_test.name = __func__;

    struct test_case {
        const char* name;
        struct {
            string_view_t sv;
            size_t remove;
        } input;
        string_view_t expected;
    };

    const char* str_example = "string literal example";
    struct test_case test_cases[] = {
            {
                .name = "remove left a string_view_t less than size",
                .input = {
                        .sv = {
                                .data = str_example,
                                .size = strlen(str_example),
                        },
                        .remove = 4,
                },
                .expected = {
                        .data = str_example + 4,
                        .size = strlen(str_example) - 4,
                },
            },
            {
                .name = "remove left a string_view_t equal than size",
                .input = {
                        .sv = {
                                .data = str_example,
                                .size = strlen(str_example),
                        },
                        .remove = strlen(str_example),
                },
                .expected = {
                        .data = str_example + strlen(str_example),
                        .size = strlen(str_example) - strlen(str_example),
                },
            },
            {
                .name = "remove left a string_view_t more than size",
                .input = {
                        .sv = {
                                .data = str_example,
                                .size = strlen(str_example),
                        },
                        .remove = strlen(str_example) + 4,
                },
                .expected = {
                        .data = str_example + strlen(str_example),
                        .size = strlen(str_example) - strlen(str_example),
                },
            },
    };
    t->current_test.total = sizeof(test_cases)/sizeof(test_cases[0]);

    for (size_t i = 0; i < t->current_test.total; ++i) {
        t->current_test.current_case.name = test_cases[i].name;

        string_view_t sv = sv_remove_left(test_cases[i].input.sv, test_cases[i].input.remove);

        bool condition = sv.data == test_cases[i].expected.data &&
                         sv.size == test_cases[i].expected.size;
        test_check_current_case_condition(t, condition);
    }
}

void susv_sv_remove_right_test(test_t* t)
{
    t->current_test.name = __func__;

    struct test_case {
        const char* name;
        struct {
            string_view_t sv;
            size_t remove;
        } input;
        string_view_t expected;
    };

    const char* str_example = "string literal example";
    struct test_case test_cases[] = {
            {
                .name = "remove right a string_view_t less than size",
                .input = {
                        .sv = {
                                .data = str_example,
                                .size = strlen(str_example),
                        },
                        .remove = 4,
                },
                .expected = {
                        .data = str_example,
                        .size = strlen(str_example) - 4,
                },
            },
            {
                .name = "remove right a string_view_t equal than size",
                .input = {
                        .sv = {
                                .data = str_example,
                                .size = strlen(str_example),
                        },
                        .remove = strlen(str_example),
                },
                .expected = {
                        .data = str_example,
                        .size = strlen(str_example) - strlen(str_example),
                },
            },
            {
                .name = "remove right a string_view_t more than size",
                .input = {
                        .sv = {
                                .data = str_example,
                                .size = strlen(str_example),
                        },
                        .remove = strlen(str_example) + 4,
                },
                .expected = {
                        .data = str_example,
                        .size = strlen(str_example) - strlen(str_example),
                },
            },
    };
    t->current_test.total = sizeof(test_cases)/sizeof(test_cases[0]);

    for (size_t i = 0; i < t->current_test.total; ++i) {
        t->current_test.current_case.name = test_cases[i].name;

        string_view_t sv = sv_remove_right(test_cases[i].input.sv, test_cases[i].input.remove);

        bool condition = sv.data == test_cases[i].expected.data &&
                         sv.size == test_cases[i].expected.size;
        test_check_current_case_condition(t, condition);
    }
}

void susv_sv_chop_left_test(test_t* t)
{
    t->current_test.name = __func__;

    struct test_case {
        const char* name;
        struct {
            string_view_t sv;
            size_t chop;
        } input;
        string_view_t expected;
    };

    const char* str_example = "string literal example";
    struct test_case test_cases[] = {
            {
                .name = "chop left a string_view_t less than size",
                .input = {
                        .sv = {
                                .data = str_example,
                                .size = strlen(str_example),
                        },
                        .chop = 4,
                },
                .expected = {
                        .data = str_example,
                        .size = 4,
                },
            },
            {
                .name = "chop left a string_view_t equal than size",
                .input = {
                        .sv = {
                                .data = str_example,
                                .size = strlen(str_example),
                        },
                        .chop = strlen(str_example),
                },
                .expected = {
                        .data = str_example,
                        .size = strlen(str_example),
                },
            },
            {
                .name = "chop left a string_view_t more than size",
                .input = {
                        .sv = {
                                .data = str_example,
                                .size = strlen(str_example),
                        },
                        .chop = strlen(str_example) + 4,
                },
                .expected = {
                        .data = str_example,
                        .size = strlen(str_example),
                },
            },
    };
    t->current_test.total = sizeof(test_cases)/sizeof(test_cases[0]);

    for (size_t i = 0; i < t->current_test.total; ++i) {
        t->current_test.current_case.name = test_cases[i].name;

        string_view_t sv = sv_chop_left(test_cases[i].input.sv, test_cases[i].input.chop);

        bool condition = sv.data == test_cases[i].expected.data &&
                         sv.size == test_cases[i].expected.size;
        test_check_current_case_condition(t, condition);
    }
}

void susv_sv_chop_right_test(test_t* t)
{
    t->current_test.name = __func__;

    struct test_case {
        const char* name;
        struct {
            string_view_t sv;
            size_t chop;
        } input;
        string_view_t expected;
    };

    const char* str_example = "string literal example";
    struct test_case test_cases[] = {
            {
                .name = "chop right a string_view_t less than size",
                .input = {
                        .sv = {
                                .data = str_example,
                                .size = strlen(str_example),
                        },
                        .chop = 4,
                },
                .expected = {
                        .data = str_example + strlen(str_example) - 4,
                        .size = 4,
                },
            },
            {
                .name = "chop right a string_view_t equal than size",
                .input = {
                        .sv = {
                                .data = str_example,
                                .size = strlen(str_example),
                        },
                        .chop = strlen(str_example),
                },
                .expected = {
                        .data = str_example,
                        .size = strlen(str_example),
                },
            },
            {
                .name = "chop right a string_view_t more than size",
                .input = {
                        .sv = {
                                .data = str_example,
                                .size = strlen(str_example),
                        },
                        .chop = strlen(str_example) + 4,
                },
                .expected = {
                        .data = str_example,
                        .size = strlen(str_example),
                },
            },
    };
    t->current_test.total = sizeof(test_cases)/sizeof(test_cases[0]);

    for (size_t i = 0; i < t->current_test.total; ++i) {
        t->current_test.current_case.name = test_cases[i].name;

        string_view_t sv = sv_chop_right(test_cases[i].input.sv, test_cases[i].input.chop);

        bool condition = sv.data == test_cases[i].expected.data &&
                         sv.size == test_cases[i].expected.size;
        test_check_current_case_condition(t, condition);
    }
}

void susv_sv_equal_test(test_t* t)
{
    t->current_test.name = __func__;

    struct test_case {
        const char* name;
        struct {
            string_view_t sv1;
            string_view_t sv2;
        } input;
        bool expected;
    };

    const char* str1_example = "string literal example";
    const char* str2_example = "string literal samples";
    struct test_case test_cases[] = {
            {
                .name = "compare two identical string_view_t",
                .input = {
                        .sv1 = {
                                .data = str1_example,
                                .size = strlen(str1_example),
                        },
                        .sv2 = {
                                .data = str1_example,
                                .size = strlen(str1_example),
                        },
                },
                .expected = true,
            },
            {
                .name = "compare two different sizes string_view_t",
                .input = {
                        .sv1 = {
                                .data = str1_example,
                                .size = strlen(str1_example),
                        },
                        .sv2 = {
                                .data = str1_example,
                                .size = strlen(str1_example) - 4,
                        },
                    },
                    .expected = false,
            },
            {
                .name = "compare two different string_view_t",
                .input = {
                        .sv1 = {
                                .data = str1_example,
                                .size = strlen(str1_example),
                        },
                        .sv2 = {
                                .data = str2_example,
                                .size = strlen(str2_example),
                        },
                    },
                    .expected = false,
            },
    };
    t->current_test.total = sizeof(test_cases)/sizeof(test_cases[0]);

    for (size_t i = 0; i < t->current_test.total; ++i) {
        t->current_test.current_case.name = test_cases[i].name;

        bool result = sv_equal(test_cases[i].input.sv1, test_cases[i].input.sv2);

        test_check_current_case_condition(t, result == test_cases[i].expected);
    }
}
