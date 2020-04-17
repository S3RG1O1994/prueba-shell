#include "shell.h"

/**
 * check_exit - Call the function exit.
 * @string: Contains the commands.
 * @args: All arguments
 *
 * Return: Allways 1.
 */
int check_exit(char *string, char *args)
{
	unsigned int cnt = 0, cnt_2 = 0;
	char *exitt = "exit";

	while (string[cnt] != '\0')
	{
		if (string[cnt] == exitt[cnt_2])
			cnt_2++;
		cnt++;
	}

	if (cnt == cnt_2)
	{
		free(args);
		free(string);
		exit(0);
	}

	return (1);
}
