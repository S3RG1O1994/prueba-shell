#include "shell.h"

char **commands(char *str)
{
	char *res;
	char *dup;
	char **array;
	int count = 0;
	int space = 0;

	dup = strdup(str);
	while (str[count])
	{
		if (str[count] == ' ')
			space++;
		count++;
	}
	count -= 1;
	space += 2;

	res = strtok(dup, " ");

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
	int count2;

	printf("Error: 1\n");
	arr = malloc(sizeof(char *) * space);
	if (arr == NULL)
		return (NULL);

	printf("Error: 2\n");
	for (count = 0; count < space; count++)
	{
		arr[count] = malloc(sizeof(char) * letters + 1);
		if (arr[count] == NULL)
		{
			for (count2 = 0; count2 < count; count2++)
				free(arr[count2]);
			free(arr);
		}
	}

	printf("Error: 3\n");
	for (a = 0; str; a++)
	{
		for (b = 0; str[b] != '\0'; b++)
			arr[a][b] = str[b];

		arr[a][b] = '\0';
		str = strtok(NULL, " ");
	}
	arr[a - 1][b - 1] = '\0';
	arr[a] = NULL;
	printf("Error: 4\n");
	return (arr);
}
