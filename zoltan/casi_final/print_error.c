#include "shell.h"

/**
 * print_error - Print the error format.
 * @av: Contains the first argument.
 * @counter: General counter.
 * @command: contains the first commands
 */
void print_error(char *av, int counter, char *command)
{
	simple_print(av);
	write(STDOUT_FILENO, ": ", 2);
	_putchar(counter + '0');
	write(STDOUT_FILENO, ": ", 2);
	simple_print(command);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "not found", 9);
	_putchar('\n');
}

/**
 * simple_print - Print strings whit _putchar.
 * @str: String to print.
 */
void simple_print(char *str)
{
	int count = 0;

	while (str[count] && str[count] != ' ' && str[count] != '\n')
	{
		_putchar(str[count]);
		count++;
	}
}
