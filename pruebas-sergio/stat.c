#include "shell.h"
/**
 * main - stat example
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
    // creación de variables.
    struct stat st;
    unsigned int i = 0, cnt1;
    int space = 0, count = 0;
    char *s = _getenv("PATH");
    char *aux;
    char **arrDir;
    char *result; 
    
    // Conteo y separación de los valores que vienen en el PATH para ser asignados en la matriz

    while (s[cnt1])
    {
        if (s[cnt1] == ':')
            space++;
        count++;
    }

    count -=1; 
    space += 2;

    aux = strtok(s, ":");

    // Conteo y separación de los valores que vienen en el PATH para ser asignados en la matriz de elementos.

    while (aux)
    {
        arrDir = add_arr(aux, space, count);
        aux = strtok(NULL, ":");
    }

    // Conteo y separación de los valores que vienen en el PATH para ser asignados en la matriz de elementos.

    // Concatenación
    while(arrDir)
    {
        result = contac(arrDir[i], av[1]);
        if (stat(result, &st) == 0)
        {
            printf("encontre [%s]\n", result);
            excev(result, result);
        }
        else
            i++;
    }

    printf("Comando no encontrado %s\n", av[1]);
    // Concatenación
}