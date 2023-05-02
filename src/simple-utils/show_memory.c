#include <simple-utils/show_memory.h>

#include <stdio.h>
#include <stdint.h>

void show_mem(const void *ptr, const size_t size) {
    uint8_t *tmp_ptr = (uint8_t*) ptr;
    size_t cols_num = 16;
    size_t line_num = size / cols_num;
    if (size % cols_num != 0) line_num++;

    printf("\n|                  LINE FORMAT                 |\n");
    printf("| address | %.2ld bytes in hex | %.2ld bytes as char |\n\n", cols_num, cols_num);

    uint32_t spaces = 30;
    printf("|    ADDRESS     |%*cBYTES%*c|    CHARACTERS    |\n", spaces, ' ', spaces+1, ' ');
    for (size_t line = 0; line < line_num ; ++line) {
        printf("| %p | ", tmp_ptr);
        for (size_t cols = 0; cols < cols_num; ++cols) {
            printf(" %.2X ", *(tmp_ptr + cols));
        }
        printf(" | ");

        for (size_t cols = 0; cols < cols_num; ++cols) {
            uint8_t tmp = *(tmp_ptr + cols);
            if (tmp < 32 || tmp > 126) tmp = (uint8_t) '.';
            printf("%c", tmp);
        }
        printf(" |\n");

        tmp_ptr += cols_num;
    }
}
