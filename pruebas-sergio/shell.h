#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

char **add_arr(char *str, int space, int letters);
char **commands(char *str);
char *_getenv(char *words);
char *contac(char **Dir, char **parameters);
#endif
