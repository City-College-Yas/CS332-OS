/* Name: Yasiris Ortiz
   Operating Systems Lab: Task 3
   Description:
   
   
    */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int child;

    child = fork();

    if (child < 0)
    {
        fprintf(stderr, "Fork Failed\n"); // checks if child successfully was forked
        return 1;
    }
    if (child == 0)
    {
        printf("The child has been sucessfully forked, PID is:%d\n", getpid());
        execl("/bin/date", "date", 0, (char *)NULL);
    }

    wait(NULL);

    return 0;
}