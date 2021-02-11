#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char * desktop = getenv("XDG_CURRENT_DESKTOP");
    char * user = getenv("USER");
    char * shell = getenv("SHELL");
    char * language = getenv("LANG");
    char hostname[1024];
    gethostname(hostname, 1024);

    printf("hostname: %s\n", hostname);
    printf("user: %s\n", user);
    printf("shell: %s\n", shell);
    printf("desktop: %s\n", desktop);
    printf("language: %s\n", language);
}