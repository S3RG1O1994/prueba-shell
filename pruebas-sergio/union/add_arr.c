#include "shell.h"

char **add_arr(char *str, char *command)
{
	int count = 0, count_2 = 0, words = 3, space = 0;
	char *copy = NULL, **arr = NULL;


	while (str[count])
	{
		if (str[count] == ' ')
		{
			space++;
		}
		count++;
	}

	if (space == 0)
	{
		arr = malloc(sizeof(char *) * (words - 1));
		if (!arr)
		{
			return (NULL);
		}
		arr[0] = command;
		arr[1] = NULL;
		return (arr);
	}

	count = 0;
	while (str[count_2] != ' ' && str[count_2] != '\n')
	{
		count_2++;
	}

	copy = strdup(&str[count_2 + 1]);

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

	arr[0] = command;
	count = 1;
	copy = strtok(copy, " ");
	while (count < words)
	{
		arr[count] = copy;
		copy = strtok(NULL, " ");
		count++;
	}
	return (arr);
}
