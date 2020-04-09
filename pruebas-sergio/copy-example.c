#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_CHILD 5

int doSomething(void)
{
    int ret;

    srand(getpid());
    ret = (rand() % 256);
    printf("HIJO: PID = %d, valor aleatorio calculado %d\n", getpid(), ret);
    
}
int main(void)
{
    pid_t pidC;
    int status;

    for (int i = 0; i < NUM_CHILD; i++)
    {
        pidC = fork();
        if (pidC > 0)
            continue;
        else if(pidC == 0)
        {
            exit(doSomething());
        }
        else
        {
            /* code */
        }
    }

    for (int i = 0; i < NUM_CHILD; i++)
    {
        pidC = wait(&status);
        printf("PADRE DE PID = %d, hijo de PID = %d terminado, st = %d\n", getpid(), pidC, WEXITSTATUS(status));
    }
    while(1)
    {
        sleep(10);
    }
    return(0);
}