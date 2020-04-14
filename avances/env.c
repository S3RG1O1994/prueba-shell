#include <stdio.h>

/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
void print_env(char *string, char env[])
{
    unsigned int j = 0, h = 0;
    extern char **environ;

    for (; string[j] == env[j]; j++, h++)
    {}

    if (j == h)
    {
        for (unsigned int i = 0 ;environ[i] != NULL; i++)
        {
            printf("%s\n", environ[i]);
        }
    }
}