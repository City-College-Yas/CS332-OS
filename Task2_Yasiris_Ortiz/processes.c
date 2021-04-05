/* Name: Yasiris Ortiz
   Operating Systems Lab: Task 2
   Description: Write a program processes.c, and let the parent process produce  
   two child processes.
   One - prints prints out  "I am first child: my pid is: PID, 
   and the other prints out "I am second child: my pid is: PID. 
   Note: Guarantee that the parent terminates after the children terminates */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{

   int child_1, child_2; /* Create child_1 & child_2 */

   child_1 = fork(); /* fork() first child process  */
   if (child_1 < 0)
   {
      fprintf(stderr, "Fork Failed\n"); // checks if child successfully was forked
      return 1;
   }
   else if (child_1 == 0) /* child process here */
   {
      printf("\nI am first child, my pid is:%d", getpid());
   }
   else
   {
      child_2 = fork(); /* fork() second child process */
      if (child_2 < 0)
      {
         fprintf(stderr, "Fork Failed\n"); // checks if child successfully was forked
         return 1;
      }
      else if (child_2 == 0) /* child proccess here */
      {
         printf("\nI am second child, my pid is:%d", getpid());
      }
      else
      {
         /* wait(NULL) will block the parent process until both children has finished */
         wait(NULL);
         wait(NULL);

         /* message that parent process has been finished */
         printf("\nParent Process has finished\n");
      }

      return 0; //means the process has been completed successfully
   }
}