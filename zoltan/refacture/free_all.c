#include "shell.h"

/**
 * free_all - Free allocations.
 * @arr: Array to free.
 */
void free_all(char **arr)
{
	int count = 0;

	while (arr[count])
		count++;
	count = 0;
	while (count < 2 && arr[count])
	{
		free(arr[count]);
		count++;
	}
	if(arr[count + 1])
	{
		free(arr[count + 1]);
	}
	free(arr);
}
