#ifndef FETCHER_H_INCLUDED
#define FETCHER_H_INCLUDED

char * getDesktop();
char * getUser();
char * getShell();
char * getLang();
char * getHostname(char *str);
char * getOS(char request, char *variable);
void fetch();

#endif