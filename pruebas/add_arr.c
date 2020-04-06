#include "shell.h"

char **add_arr(char * str, int space, int letters)
{
	char **arr;
	int a;
	int b;
	int count;

	arr = (char **)malloc(space * sizeof(char *));

	for (count = 0; count < space; count++) {
		arr[count] = (char *)malloc(letters * sizeof(char));
	}

	for (a = 0; str; a++)
	{
		for (b = 0; str[b] != '\0'; b++)
		{
			arr[a][b] = str[b];
		}
		arr[a][b] = '\0';
		str = strtok(NULL, " ");
	}
	return (arr);
}
