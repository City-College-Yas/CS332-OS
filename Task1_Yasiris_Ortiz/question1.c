/*
Name: Yasiris Ortiz
Class: Operating Systems Lab
Description: Write a C program to implement a command called printcontent that takes a (text) file
as argument and display its contents. 
Report an appropiate message of the file does not exits or can't be opened.

Use: open(), read(), write(), and close() system calls
Note:  you can name the executable file printcontent and execute the program as ./printcontent filename 
*/

#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#define BUFSIZE 1024 // buffer size

void printcontent(char *argv[1])
{
    errno = 0;
    char buffer[BUFSIZE];
    int fd = open("source.txt", O_RDONLY | O_CREAT); // opens a text file or creates a new one to display its content
    //int fd = open(argv[1], O_RDONLY | O_CREAT); //uncomment if willing to print the content of this file itself

    // handling errors if the file doesn't exits or can't be opened
    if (fd == -1)
    {
        if (errno == ENOENT)
            printf("File does not exits\n");
        else if (errno == EACCES)
            printf("File is not accesible\n");
        printf("\n open() failed with error [%s]\n", strerror(errno));
    }
    else
    {
        // while loop to read the content of the file
        while (read(fd, buffer, 1))
            write(STDIN_FILENO, buffer, 1); // STDIN_FILENO: integer file descripto that writes the bytes on stdout(for ouput)

        close(fd); // close file
    }
}

// main function 
int main(int argc, char *argv[])
{
    printcontent(argv); // calling printcontent function
    return 0;
}
