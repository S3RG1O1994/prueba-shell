#include "shell.h"

int main(void)
{
	char str[] = "hola putos";
	char **arr;
	int i;


	arr = commands(str);
	for (i = 0; arr[i]; i++)
		printf("%s\n", arr[i]);
	return (0);
}
