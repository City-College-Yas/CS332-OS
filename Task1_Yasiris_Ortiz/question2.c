/*
Name: Yasiris Ortiz
Class: Operating Systems Lab
Description: Write a C program that mimics the cp command using open() system call to open source.txt file
in read-only mode and copy the content of it to destimation.txt using read() and write() system calls
NOTE: destinatio.txt file will be created once question1.c is run.
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define BUFSIZE 1314

// main function
int main(int argc, char *argv[])
{
    char buff[BUFSIZE];
    int fd[2];
    //open source.txt file in READ ONLY mode
    // open destination.txt file in write only mode, truncate if already exits or create if not available
    fd[0] = open("source.txt", O_RDONLY);
    fd[1] = open("destination.txt", O_WRONLY | O_CREAT | O_TRUNC);

    // handling errors for both files
    if (fd[0] == -1 || fd[1] == -1)
    {
        printf("Error Opening file\n");
        perror("open");
        return -1;
    }

    //system call functions to read and write the content from one file to the other
    read(fd[0], buff, 1314);
    write(fd[1], buff, 1314);

    printf("\nContents successfully copied!\n");
    
    // close both of the files
    close(fd[0]);
    close(fd[1]);

    return 0;
}