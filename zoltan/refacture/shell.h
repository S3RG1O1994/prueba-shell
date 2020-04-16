#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

extern char **environ;

char *space_eliminator(char *string);
int _putchar(char c);
char *_strdup(char *str);
void free_all(char **arr);
int validator(char *string);
int stat_func(char *command);
int check_exit(char *string);
void simple_print(char *str);
int sp_tab_finder(char *str);
char *shortener(char *string);
void short_func(int *counter);
int point_finder(char *string);
void print_number(long int number);
int _merge(char *args, char **env);
char **add_arr(char *str, char *command);
char *concatenate(char *args, char *path);
char *_getenv(char *words, char **environ);
char **simple_arr(char *command, int words);
int print_env(char *string, char **environ);
void print_error(char *av, int counter, char *command);
char **absolute_path(char *args, char *av, int counter);
char **create_arr(char *arguments);

#endif
