#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

typedef struct list_path
{
    char *str;
    unsigned int len;
    struct list_s *next;
} dir_path;

void first_func();
int _putchar(char c);
char **add_arr(char *str);
char *_getenv(char *words);
char *contac(char **Dir, char **parameters);
#endif
