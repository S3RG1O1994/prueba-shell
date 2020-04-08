#include "shell.h"

void first_func(void)
{
	/*Declaración de Variables necesarias para el uso del getline*/
	int bytes_read;
	size_t size = 0;
	char *string;
	char **argv;

	_putchar('$');
	_putchar(' ');

	/*Asignación de tamaño a la bariable string*/
	string = malloc(sizeof(char) * size);
	if (string == NULL)
		return;

	/*Uso de la función getline pasando los paramentros
	  (dir del string, dir del tamaño, salida estandar)*/
	bytes_read = getline(&string, &size, stdin);
	if(bytes_read == -1)
		printf("erro\n");

	if (string[0] == '\n')
		return;
	else
	{
		argv = commands(string);
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error:");
		}
	}
}
