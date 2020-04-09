#include "shell.h"

int main()
{
	char str[] = "This is a string the example";
	char *res;
	char **array;
	int count = 0;
	int space = 0;
	int i;
	
	res = strtok(str, " ");

	while (res)
	{
		array = add_arr(res);
		res = strtok(NULL, " ");
	}

	for (i = 0; i < space; i++)
		printf("%s\n", array[i]);
	return (0);
}
