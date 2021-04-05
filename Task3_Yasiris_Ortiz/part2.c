/* Name: Yasiris Ortiz
   Operating Systems Lab: Task 3
   Description:  */



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int child;
    char *argv[] = {"/bin/ls", "-la", NULL};

    child = fork();

    if (child < 0)
    {
        fprintf(stderr, "Fork Failed\n"); // checks if child successfully was forked
        return 1;
    }
    if (child == 0)
    {
        printf("The child has been sucessfully forked, PID is:%d\n", getpid());
        execvp(argv[0], argv);
    }

    wait(NULL);

    return 0;
}