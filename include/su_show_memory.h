/**
 * @file su_show_memory.h
 * @version 0.0.1
 * @date 20/12/2022
 * @author Sebastian Vargas Beltran
 * @brief library.
 * @code
#include "../src/su_show_memory.h"

int main(void) {
    return 0;
}
 * @endcode
 */

#ifndef INCLUDE_SU_SHOW_MEMORY_H
#define INCLUDE_SU_SHOW_MEMORY_H

#include <stdio.h>

void show_mem(const void *ptr, const size_t size);

#endif //INCLUDE_SU_SHOW_MEMORY_H
