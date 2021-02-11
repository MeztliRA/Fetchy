#include <stdio.h>
#include <stdlib.h>

int main() {
    char * desktop = getenv("XDG_CURRENT_DESKTOP");
    char * user = getenv("USER");
    char * shell = getenv("SHELL");
    char * language = getenv("LANG");

    printf("user: %s\n", user);
    printf("shell: %s\n", shell);
    printf("desktop: %s\n", desktop);
    printf("language: %s\n", language);
}