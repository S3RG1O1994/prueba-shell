#include "shell.h"

char **commands(char *str)
{
	char *copy = NULL, **array = NULL, *pre_arr = NULL;
	int *metadatos = NULL;
	int count = 0, count_2 = 0, count_3 = 0, words = 2, letters = 0;

	copy = strdup(str); /*----¡¡¡CREAR FUNCION _STRDUP!!!-----*/
	while (copy[count])
	{
		if (copy[count] == ' ')  /*--contador de palabras y letras--*/
			words++;
		count++;
	}
	count--;
	copy[count] = '\0'; /*--reemplaza \n por \0 --*/
	pre_arr = strtok(copy, " ");
	metadatos = malloc(sizeof(int) * words);
	if (!metadatos)
		return (0);
	while(str[count_2])
	{
		if (str[count_2] != ' ' && str[count_2 + 1] != '\0')
			letters++;
		else
		{
			metadatos[count_3] = letters;
			count_3++;  /*--cuenta letras por palabra--*/
			letters = 0;
		}
		count_2++;
	}
	metadatos[words - 1] = 1;
	array = add_arr(pre_arr, metadatos, words);
	free (metadatos);
	return (array);
}
