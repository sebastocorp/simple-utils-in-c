#include <unistd.h>
#include <stdint.h>

#include "../../src/su_show_memory.c"

int main(int argc,char **argv)
{
    char str[6] = "HELLO";
    uint64_t num = 0xffffffff;
    show_mem(&num, 17);
    (void) str;
    return 0;
}
/*
#include <stdio.h>

const char* gray_scale = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";

int main(int argc, char const *argv[])
{
    printf("hello, world!\n");
    return 0;
}
*/