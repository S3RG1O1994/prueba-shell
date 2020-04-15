#include "shell.h"

/**
 * _getenv - Get environment.
 * @words: Variable char.
 * @environ: Contains the environment.
 *
 * Return: Path.
 */
char *_getenv(char *words, char **environ)
{
	char *other;
	unsigned int cnt1, cnt2, cnt3, cnt4 = 0;

	if (words == NULL)
		return (0);

	for (cnt1 = 0; words[cnt1]; cnt1++)
	{
	}

	for (cnt2 = 0; environ[cnt2]; cnt2++)
	{
		other = environ[cnt2];
		for (cnt3 = 0; other[cnt3] == words[cnt3]; cnt3++)
		{
		}
		if (cnt3 == cnt1)
		{
			for (; cnt4 < 5; cnt4++)
				other++;
			return (other);
		}
		else
			cnt3 = 0;
	}

	return ("NOT FOUND");
}
