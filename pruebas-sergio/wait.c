#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_CHILD 5

int haga_algo(void)
{
    int ret;

    srand(getpid());
    ret = (rand() % 256);
    printf("Soy el hijo numero = %d hice esto %d\n", getpid(), ret);
}

int main(void)
{
    int padre;
    int status;

    /*printf("before process\n");
    padre = getpid();
    printf("%d\n", padre);
    printf("process\n");*/

    for (int i = 0; i < NUM_CHILD; i++)
    {
        padre = fork();
        if (padre > 0)
            continue;
        else if (padre == 0)
        {
            exit(haga_algo());
        }
        else
        {/* code */}
    }

    for (int i = 0; i < NUM_CHILD; i++)
    {
        padre = wait(&status);
        printf("PADRE DE PID = %d, el PID del hijo = %d, su estado es  = %d", getpid(), padre, WEXITSTATUS(status));
    }

    while(1)
    {
        sleep(10);
    }
    return (0);
}