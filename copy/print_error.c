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
	print_number(counter);
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

	while (str[count] && str[count] != ' ' && str[count] != '\0')
	{
		_putchar(str[count]);
		count++;
	}
}

/**
 * print_number - Print a number.
 * @number: number
 */

void print_number(long int number)
{
	if (number < 10)
	{
	}
	else
	{
		print_number(number / 10);
	}
	number %= 10;
	_putchar(number + '0');
}
