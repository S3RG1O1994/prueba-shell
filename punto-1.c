#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	/*Declaración de Variables necesarias para el uso del getline*/
	int bytes_read;
	size_t size = 10;
	char *string;

	printf("$ ");

	/*Asignación de tamaño a la bariable string*/
	string = malloc(sizeof(char) * size);

	/*Uso de la función getline pasando los paramentros
	  (dir del string, dir del tamaño, salida estandar)*/
	bytes_read = getline(&string, &size, stdin);

	if(bytes_read == -1)
		printf("erro\n");
	else
	{
		printf("%s\n", string);
		//printf("El tamaño en bytes es %i\n, bytes_read");
	}
	return (0);
}
