#ifndef INCLUDE_SUSV_TEST_H
#define INCLUDE_SUSV_TEST_H

#include <su_testing.h>

void susv_sv_construct_test(test_t* t);
void susv_sv_cstr_construct_test(test_t* t);
void susv_sv_trim_left_test(test_t* t);
void susv_sv_trim_right_test(test_t* t);
void susv_sv_trim_test(test_t* t);
void susv_sv_remove_left_test(test_t* t);
void susv_sv_remove_right_test(test_t* t);
void susv_sv_chop_left_test(test_t* t);
void susv_sv_chop_right_test(test_t* t);
void susv_sv_equal_test(test_t* t);

#endif
