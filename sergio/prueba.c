#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char **args(char *str)
{
	int c = 0, words = 1;
	char *copy = NULL, **arr = NULL;

	copy = strdup(str);
	while (copy[c])
	{
		if (copy[c] == ' ')
			words++;
		c++;
	}
	copy[c - 1] = '\0';

	arr = malloc(sizeof(char *) * words);

	copy = strtok(copy, " ");
	c = 0;
	while (c < words)
	{
		arr[c] = copy;
		copy = strtok(NULL, " ");
		c++;
	}
	return (arr);
}

int main(void)
{
	char *str = "this is a string\n";
	char **arr;

	arr = args(str);

	printf("%s\n", arr[0]);
	printf("%s\n", arr[3]);

	free(arr[0]);
	free(arr);
	return (0);
}
