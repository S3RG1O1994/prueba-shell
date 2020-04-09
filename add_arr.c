#include "shell.h"

char **add_arr(char *str)
{
	char **arr;
	int a;
	int b;
	int count;
	int count1 = 0;
	int space = 0;

	if (str == NULL)
		return (-1);
	
	if (str == NULL)
		return (0);
		
	while (str[count1])
	{
		if (str[count1] == ' ')
			space++;
		count1++;
	}
	count1 -= 1;
	space += 1;

	arr = (char **)malloc(space * sizeof(char *));

	for (count = 0; count < space; count++) {
		arr[count] = (char *)malloc(count1 * sizeof(char));
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
