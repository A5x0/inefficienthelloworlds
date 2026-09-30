/* This Hello, World! program only compiles on GCC 13/Clang 15 or earlier. */
#include <stdio.h>
int main(void) {
    long long address = (long long)"Hello, World!\n";
    printf(address); 
    return 0;
}
