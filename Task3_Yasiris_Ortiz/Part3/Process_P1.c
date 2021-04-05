/* Name: Yasiris Ortiz
   Operating Systems Lab: Task 3
   Description: 
   Part 1: Create two files namely, destination1.txt and destination2.txt with read, write and execute
permissions. */

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main()
{
    int fd[2];

    // create two files destination1.txt and destination2.txt
    fd[0] = open("destination1.txt", O_CREAT | O_RDWR, 0777);
    fd[1] = open("destination2.txt", O_CREAT | O_RDWR, 0777);

    // close both files
    close(fd[0]);
    close(fd[1]);

    printf("Files have been created suscessfully!\n");
    return 0;
}