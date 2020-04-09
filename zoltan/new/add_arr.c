#include "shell.h"

char **add_arr(char *str)
{
	int count = 0, words = 2;
	char *copy = NULL, **arr = NULL;

	copy = strdup(str);
	while (copy[count])
	{
		if (copy[count] == ' ')
			words++;
		count++;
	}
	copy[count - 1] = '\0';

	arr = malloc(sizeof(char *) * words);
	if (!arr)
		return (NULL);

	count = 0;
	copy = strtok(copy, " ");
	while (count < words)
	{
		arr[count] = copy;
		copy = strtok(NULL, " ");
		count++;
	}
	return (arr);
}
