/* Name: Yasiris Ortiz
   Operating Systems Lab: Task 3
   Description: execute the files as per the following procedure using execv system call */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()

{

    pid_t child1;
    pid_t child2;

    /* Child one is being forked here */
    child1 = fork();
    if (child1 < 0)
    {
        fprintf(stderr, "Fork Failed\n"); // checks if child successfully was forked
        return 1;
    }
    char *argv[] = {"process1", NULL};

    if (child1 == 0)
    {
        // execute process 1 here /* This will create two destination files according to step 2 */
        execv(argv[0], argv);
    }

    /* Child one is being forked here */
    child2 = fork();
    if (child2 < 0)
    {
        fprintf(stderr, "Fork Failed\n"); // checks if child successfully was forked
        return 1;
    }
    char *argc[] = {"process2", NULL};
    if (child2 == 0)
    {
        // execute process 2 here
        execv(argc[0], argc);
    }

    // parent process waits for child1 and child2
    wait(NULL);
    wait(NULL);
    return 0;
}