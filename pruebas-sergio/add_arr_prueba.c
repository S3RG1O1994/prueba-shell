#include "shell.h"

char **commands(char *str)
{
	char *res;
	char **array;
	int count = 0;
	int space = 0;

	while (str[count])
	{
		if (str[count] == ' ')
			space++;
		count++;
	}
	count -= 1;
	space += 2;

	res = strtok(str, " ");

	while (res)
	{
		array = add_arr(res, space, count);
		res = strtok(NULL, " ");
	}
	return (array);
}

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
	arr[a - 1][b - 1] = '\0';
	arr[a] = NULL;
	return (arr);
}
