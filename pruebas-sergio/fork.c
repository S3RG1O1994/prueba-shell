#include <stdio.h>
#include <unistd.h>

/**
 * main - fork example
 *
 * Return: Always 0.
 */
int main(void)
{
    int pid; // por lo general se usa pid_t el cual por debajo es un int.

    printf("Before fork\n");

    printf("Yo soy el id inicial = %d\n", getpid());

    printf("after fork\n");
    
    /*Fork es la función que clona un proceso dado y le permite operar 
    de forma independiente a su parte original que en el sistema es tomado
    como el padre
    
    con el comando KILL -9 (numero del pid del proceso) puedo terminar procesos.
    y saber su nuevo padre con el comando ps -lp (numero pid)
    */

    pid = fork(); // fork es una función que no recibe argumentos -> fork(void)

    if (pid == -1) // Esto sucede si el hijo no es creado
    {
        perror("Error:");
        return (1);
    }
    // Imprimiendo el hijo (si el hijo es creado su valor de retorno 0)
    if (pid == 0)
    {
        printf("Yo soy el hijo mi id es %d\n", getpid());
        pid = getpid();
    }
    else
    {
        // imprimiendo el padre del proceso. -> Este mismo recibe como retorno el valor del PID del hijo.
        printf("Yo soy el padre %d\n", getpid());
    }
    
    return (0);
}