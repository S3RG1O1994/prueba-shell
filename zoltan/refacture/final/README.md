# Simple Shell:

It's a interface to the Unix System that recieve commands and executes programs based on that input. Finally displays that's programs output.

### Prerequisites

You'll need at least a Linux terminal for run this program.

### Installing

Copy this repo into your terminal. Enter in the main folder and execute the following command: `gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`
Then you can execute the Simple Shell just writing `./hsh` and typing enter.

You're now in the Simple Shell and you can typing some commands like: `ls -l`. That command will list all the contents in the current folder with
a long format.

## The 2 ways to acces the Simple Shell

## The Interactive Mode

In the interactive mode you run the shell and type the command that you want to execute.

Is something like this:

`$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$`

In the example above, you run the shell and type the path of the `bin` folder and the type the command, `ls`, for list the content of the folder.
Then type exit to finish the program.

## The Non-Interactive Mode

In this method, you first pass the command and then run the shell through a pipe.

Look at the example below:

`$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
$`

In that example, first through `echo` you pass the command and with a pipe execute the shell. In the second part,
the command is in the `test_ls_2` file. With the commands cat, you pass the file with the command and with the pipe run
the shell. The result is same in both cases.

## Files

add_arr.c

check_exit.c

concatenate.c

create_arr.c

env.c

free_all.c

_getenv.c

main.c

merge.c

_putchar.c

shell.h

simple_arr.c

stat.c

_strdup.c

## Functions

int _putchar(char c);

char *_strdup(char *str);

void free_all(char **arr);

int stat_func(char *command);

int check_exit(char *string);

int _merge(char *args, char **env);

char **add_arr(char *str, char *command);

char *concatenate(char *args, char *path);

char *_getenv(char *words, char **environ);

char **create_arr(char *str_g, char **env);

char **simple_arr(char *command, int words);

int print_env(char *string, char **environ);

## Libraries

#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <sys/types.h>

#include <sys/wait.h>

#include <sys/stat.h>

#include <string.h>

## Built in

C programming language

## Version

Version of the current program: 1.0. For the versions available, see the (https://github.com/S3RG1O1994/simple_shell). Pending change

## Authors

* **Zoltan Mora**   -   *Holberton Student* - (https://github.com/ZoltanMG)
* **Sergio Diaz**   -   *Holberton Student* - (https://github.com/S3RG1O1994)
* **Steven Mosquera** - *Holberton Student* - (https://github.com/SimpleSteven)
