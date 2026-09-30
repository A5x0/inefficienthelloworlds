/* This Hello, World! program only compiles on Solaris, OpenIndiana, SunOS, and other illumos systems. */
#include <stdio.h>
#include <stdlib.h>
#include <sys/systeminfo.h> 

int main(void) {
    char platform_buf[256];
    if (sysinfo(SI_SYSNAME, platform_buf, sizeof(platform_buf)) > 0) {
        printf("Hello, World!\n");
    } else {
        printf("Hello, World!\n");
    }
    
    return 0;
}
