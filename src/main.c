#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/utsname.h>

char * get_desktop() {
    if (getenv("XDG_CURRENT_DESKTOP") == NULL) {
        return getenv("DESKTOP_SESSION");
    } else {
        return getenv("XDG_CURRENT_DESKTOP");
    }
}

char * get_user() {
    char * user = getenv("USER");

    return user;
}

char * get_shell() {
    char * shell = getenv("SHELL");

    return shell;
}

char * get_lang() {
    char * language = getenv("LANG");

    return language;
} 

char * get_hostname(char *str) {
    gethostname(str, 1024);

    return str;
}

char * get_os(char request, char *variable) {
    struct utsname uname_data;

    uname(&uname_data);

    if(request == 's') {
        variable = uname_data.sysname;
        return variable;
    } else if (request == 'r') {
        variable = uname_data.release;
        return variable;
    }
}

void fetch() {
    char sysname[50];
    char release[50];
    char hostname[1024];

    printf("    __");
    printf("   hostname: %s\n", get_hostname(hostname));
    printf("   |     user: %s\n", get_user());
    printf("   |     os: %s %s\n", get_os('s', sysname), get_os('r', release));
    printf("   |__   shell: %s\n", get_shell());
    printf("   |     desktop: %s\n", get_desktop());
    printf("   |     language: %s\n", get_lang());
}

int main() {
    fetch();
}