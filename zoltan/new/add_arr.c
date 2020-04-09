#include "shell.h"

char **add_arr(char *pre_arr, int *metadatos, int words)
{
	char **arr;
	int count, count_2 = 0, count_3, count_4, count_5;

	arr = malloc(sizeof(char *) * words);
	if (arr == NULL)
		return (NULL);

	for (count = 0; count < words; count++)
	{
		arr[count] = malloc(sizeof(char) * metadatos[count_2] + 1);
		if (arr[count] == NULL)
		{
			for (count_3 = 0; count_3 < count; count_3++)
				free(arr[count_3]);
			free(arr);
		}
		count_2++;
	}

	for (count_4 = 0; pre_arr; count_4++)
	{
		for (count_5 = 0; pre_arr[count_5] != '\0'; count_5++)
			arr[count_4][count_5] = pre_arr[count_5];

		arr[count_4][count_5] = '\0';
		pre_arr = strtok(NULL, " ");
	}
	arr[count_4] = NULL;

	return (arr);
}
