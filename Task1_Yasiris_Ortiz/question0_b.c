/*
Name: Yasiris Ortiz 
Course: Operating Systems Lab
Description: Write a C program where OPEN system call creates a new file and then opens it
(Hint: use the bitwise OR flag)
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h> //close library

int main(int argc, char *argv[])
{
    int fd;
    // open the file if it exits otherwise creates a new file and opens it
    fd = open("destination.txt", O_CREAT|O_RDONLY);

    // handling errors
    if (fd < 0)
    {
        printf("\n There was an error creating the file\n");
        perror("open"); // prints a descriptive the error message
        return 1;
    }
    else
    {
        printf("\n File was created Succesfully\n");
    }
    close(fd); // close file 
    return 0;
}
