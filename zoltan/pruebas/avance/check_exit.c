#include "shell.h"
/*
*
*
*
*/

int check_exit(char *string)
{
	unsigned int cnt = 0, cnt_2 = 0;
	char *exitt = "exit";

	while (string[cnt] != '\n')
	{
		if (string[cnt] == exitt[cnt_2])
			cnt_2++;
		cnt++;
	}

	if(cnt == cnt_2)
	{
		free(string);
		exit(0);
	}

	return (1);
}
