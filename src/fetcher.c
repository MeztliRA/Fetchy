#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/utsname.h>
#include "fetcher.h"

char * getDesktop() {
    if (getenv("XDG_CURRENT_DESKTOP") == NULL) {
        if (getenv("DESKTOP_SESSION") == NULL) {
            return "unknown";
        }
        return getenv("DESKTOP_SESSION");
    }
    return getenv("XDG_CURRENT_DESKTOP");
}

char * getUser() {
    if (getenv("USER") == NULL) {
        return "unknown";
    }
    return getenv("USER");
}

char * getShell() {
    if (getenv("SHELL") == NULL) {
        return "unknown";
    }
    return getenv("SHELL");
}

char * getLang() {
    if (getenv("LANG") == NULL) {
        return "unknown";
    }
    return getenv("LANG");
}

char * getHostname(char *str) {
    gethostname(str, 1024);
    
    return str;
}

char * getOS(char request, char *variable) {
    struct utsname unameData;

    uname(&unameData);

    switch (request) {
        case 's': 
            variable = unameData.sysname;
            return variable;
        case 'r':
            variable = unameData.release;
            return variable;
        case 'a':
            variable = unameData.machine;
            return variable;
    }
}

char * getTerm() {
    if (getenv("TERM_PROGRAM") == NULL) {
        return "unknown";
    }
    return getenv("TERM_PROGRAM");
}

void fetch() {
    char sysname[50];
    char release[50];
    char architecture[50];
    char hostname[1024];

    printf("    __");
    printf("   hostname: %s\n", getHostname(hostname));
    printf("   |     user: %s\n", getUser());
    printf("   |     os: %s %s\n", getOS('s', sysname), getOS('r', release));
    printf("   |__   shell: %s\n", getShell());
    printf("   |     desktop: %s\n", getDesktop());
    printf("   |     language: %s\n", getLang());
    printf("         terminal: %s\n", getTerm());
    printf("         architecture: %s\n", getOS('a', architecture));
}