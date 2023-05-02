#ifndef INCLUDE_SUSV_TEST_H
#define INCLUDE_SUSV_TEST_H

#include <string.h>
#include <simple-utils/testing.h>
#include <simple-utils/std/string_view.h>

#include "string_view_test.h"

void SU_StringView_Construct_test(test_t* t)
{
    t->current_test.name = __func__;

    struct test_case {
        const char* name;
        SU_StringView input;
        SU_StringView expected;
    };

    const char* str_example = "string literal example";
    struct test_case test_cases[] = {
            {
                    .name = "construct a SU_StringView",
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

        SU_StringView sv = SU_StringView_Construct(test_cases[i].input.data, test_cases[i].input.size);

        bool condition = sv.data == test_cases[i].expected.data &&
                         sv.size == test_cases[i].expected.size;
        test_check_current_case_condition(t, condition);
    }
}

void SU_StringView_Construct1cstr_test(test_t* t)
{
    t->current_test.name = __func__;

    struct test_case {
        const char* name;
        const char* input;
        SU_StringView expected;
    };

    const char* str_example = "string literal example";
    struct test_case test_cases[] = {
            {
                    .name = "construct a SU_StringView with cstr",
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

        SU_StringView sv = SU_StringView_Construct1cstr(test_cases[i].input);
        bool condition = sv.data == test_cases[i].expected.data &&
                         sv.size == test_cases[i].expected.size;
        test_check_current_case_condition(t, condition);
    }
}

void SU_StringView_TrimLeft_test(test_t* t)
{
    t->current_test.name = __func__;

    struct test_case {
        const char* name;
        SU_StringView input;
        SU_StringView expected;
    };

    const char* str_example_with_spaces = "    string literal example";
    const char* str_example_without_spaces = "string literal example";
    struct test_case test_cases[] = {
            {
                    .name = "trim left a SU_StringView with spaces",
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
                    .name = "trim left a SU_StringView without spaces",
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

        SU_StringView sv = SU_StringView_TrimLeft(test_cases[i].input);

        bool condition = sv.data == test_cases[i].expected.data &&
                         sv.size == test_cases[i].expected.size;
        test_check_current_case_condition(t, condition);
    }
}

void SU_StringView_TrimRight_test(test_t* t)
{
    t->current_test.name = __func__;

    struct test_case {
        const char* name;
        SU_StringView input;
        SU_StringView expected;
    };

    const char* str_example_with_spaces = "string literal example    ";
    const char* str_example_without_spaces = "string literal example";
    struct test_case test_cases[] = {
            {
                    .name = "trim right a SU_StringView with spaces",
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
                    .name = "trim right a SU_StringView without spaces",
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

        SU_StringView sv = SU_StringView_TrimRight(test_cases[i].input);

        bool condition = sv.data == test_cases[i].expected.data &&
                         sv.size == test_cases[i].expected.size;
        test_check_current_case_condition(t, condition);
    }
}

void SU_StringView_Trim_test(test_t* t)
{
    t->current_test.name = __func__;

    struct test_case {
        const char* name;
        SU_StringView input;
        SU_StringView expected;
    };

    const char* str_example_with_spaces = "    string literal example    ";
    const char* str_example_without_spaces = "string literal example";
    struct test_case test_cases[] = {
            {
                    .name = "trim a SU_StringView with spaces",
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
                    .name = "trim a SU_StringView without spaces",
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

        SU_StringView sv = SU_StringView_Trim(test_cases[i].input);

        bool condition = sv.data == test_cases[i].expected.data &&
                         sv.size == test_cases[i].expected.size;
        test_check_current_case_condition(t, condition);
    }
}

void SU_StringView_RemoveLeft_test(test_t* t)
{
    t->current_test.name = __func__;

    struct test_case {
        const char* name;
        struct {
            SU_StringView sv;
            size_t remove;
        } input;
        SU_StringView expected;
    };

    const char* str_example = "string literal example";
    struct test_case test_cases[] = {
            {
                    .name = "remove left a SU_StringView less than size",
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
                    .name = "remove left a SU_StringView equal than size",
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
                    .name = "remove left a SU_StringView more than size",
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

        SU_StringView sv = SU_StringView_RemoveLeft(test_cases[i].input.sv, test_cases[i].input.remove);

        bool condition = sv.data == test_cases[i].expected.data &&
                         sv.size == test_cases[i].expected.size;
        test_check_current_case_condition(t, condition);
    }
}

void SU_StringView_RemoveRight_test(test_t* t)
{
    t->current_test.name = __func__;

    struct test_case {
        const char* name;
        struct {
            SU_StringView sv;
            size_t remove;
        } input;
        SU_StringView expected;
    };

    const char* str_example = "string literal example";
    struct test_case test_cases[] = {
            {
                    .name = "remove right a SU_StringView less than size",
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
                    .name = "remove right a SU_StringView equal than size",
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
                    .name = "remove right a SU_StringView more than size",
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

        SU_StringView sv = SU_StringView_RemoveRight(test_cases[i].input.sv, test_cases[i].input.remove);

        bool condition = sv.data == test_cases[i].expected.data &&
                         sv.size == test_cases[i].expected.size;
        test_check_current_case_condition(t, condition);
    }
}

void SU_StringView_ChopLeft_test(test_t* t)
{
    t->current_test.name = __func__;

    struct test_case {
        const char* name;
        struct {
            SU_StringView sv;
            size_t chop;
        } input;
        SU_StringView expected;
    };

    const char* str_example = "string literal example";
    struct test_case test_cases[] = {
            {
                    .name = "chop left a SU_StringView less than size",
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
                    .name = "chop left a SU_StringView equal than size",
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
                    .name = "chop left a SU_StringView more than size",
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

        SU_StringView sv = SU_StringView_ChopLeft(test_cases[i].input.sv, test_cases[i].input.chop);

        bool condition = sv.data == test_cases[i].expected.data &&
                         sv.size == test_cases[i].expected.size;
        test_check_current_case_condition(t, condition);
    }
}

void SU_StringView_ChopRight_test(test_t* t)
{
    t->current_test.name = __func__;

    struct test_case {
        const char* name;
        struct {
            SU_StringView sv;
            size_t chop;
        } input;
        SU_StringView expected;
    };

    const char* str_example = "string literal example";
    struct test_case test_cases[] = {
            {
                    .name = "chop right a SU_StringView less than size",
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
                    .name = "chop right a SU_StringView equal than size",
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
                    .name = "chop right a SU_StringView more than size",
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

        SU_StringView sv = SU_StringView_ChopRight(test_cases[i].input.sv, test_cases[i].input.chop);

        bool condition = sv.data == test_cases[i].expected.data &&
                         sv.size == test_cases[i].expected.size;
        test_check_current_case_condition(t, condition);
    }
}

void SU_StringView_Equal_test(test_t* t)
{
    t->current_test.name = __func__;

    struct test_case {
        const char* name;
        struct {
            SU_StringView sv1;
            SU_StringView sv2;
        } input;
        bool expected;
    };

    const char* str1_example = "string literal example";
    const char* str2_example = "string literal samples";
    struct test_case test_cases[] = {
            {
                    .name = "compare two identical SU_StringView",
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
                    .name = "compare two different sizes SU_StringView",
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
                    .name = "compare two different SU_StringView",
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

        bool result = SU_StringView_Equal(test_cases[i].input.sv1, test_cases[i].input.sv2);

        test_check_current_case_condition(t, result == test_cases[i].expected);
    }
}

void (*string_view_tests[])(test_t* t) = {
        SU_StringView_Construct_test,
        SU_StringView_Construct1cstr_test,
        SU_StringView_TrimLeft_test,
        SU_StringView_TrimRight_test,
        SU_StringView_Trim_test,
        SU_StringView_RemoveLeft_test,
        SU_StringView_RemoveRight_test,
        SU_StringView_ChopLeft_test,
        SU_StringView_ChopRight_test,
        SU_StringView_Equal_test,
};

#endif
