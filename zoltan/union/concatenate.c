#include "shell.h"

char *concatenate(char *str_g, char *path)
{
	int count = 0, count_2 = 0, count_3 = 0, size = 0;
	char *arr;

	while (str_g[count] != '\n' && str_g[count] != ' ')
		count++;

	while (path[count_2])
		count_2++;

	size = count_2 + count + 2;

	arr = malloc(sizeof(char) * size);
	if (!arr)
		return (NULL);

	for (count = 0; path[count]; count++)
		arr[count] = path[count];
	arr[count] = '/';

	count++;

	while ( str_g[count_3] != '\n' && str_g[count_3] != ' ')
	{
		arr[count] = str_g[count_3];
		count++;
		count_3++;
	}
	arr[count] = '\0';

	return (arr);
}
