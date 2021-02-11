#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/utsname.h>

int main() {
    struct utsname uname_data;

    char * desktop = getenv("XDG_CURRENT_DESKTOP");
    char * user = getenv("USER");
    char * shell = getenv("SHELL");
    char * language = getenv("LANG");
    char hostname[1024];
    gethostname(hostname, 1024);

    uname(&uname_data);

    printf("    __");
    printf("   hostname: %s\n", hostname);
    printf("   |     user: %s\n", user);
    printf("   |     os: %s %s\n", uname_data.sysname, uname_data.release);
    printf("   |__   shell: %s\n", shell);
    printf("   |     desktop: %s\n", desktop);
    printf("   |     language: %s\n", language);
}