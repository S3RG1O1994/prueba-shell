#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

char **add_arr(char *pre_arr, int *metadatos, int words);
char **commands(char *str);
int _putchar(char c);
void first_func(void);

#endif
