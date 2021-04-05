/*
Name: Yasiris Ortiz
Class: Operating Systems Lab
Description: Repeat part 2) by writing a new C program) as per the following  procedure:
A) Read the next 50 characters from source.txt , and among characters read, replace each character
’5’ with character ‘A’’ and all characters are then written in destination.txt
B) Write characters "XYZ" into file destination.txt
C) Repeat the previous steps until the end of file source.txt . The last read step may not have 50
characters.
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define BUFSIZE 2000;

int main(int argc, char *argv[])
{

    int fd[2];
    char buff1[2000];
    char buff2[2000];

    //open source.txt file in READ ONLY mode
    fd[0] = open("source.txt", O_RDONLY);

    //open destination.txt file in WRITE ONLY mode, otherwise creates a new file
    fd[1] = open("destination.txt", O_WRONLY | O_CREAT); // detination.txt file from question2

    //handling exceptions if any of the file does not open successfully
    if (fd[0] == -1 || fd[1] == -1)
    {
        printf("\n Error opening files\n");
        perror("open"); // explain with details why the error happened
    }

    // start reading source file then enters a while loop to replce characters
    read(fd[0], buff1, 1314);

    // for loop to change chars "5" for "A" in source.txt
    for (int i = 0; i < 1314; i++)
    {
        if (buff1[i] == '5')
        {
            buff1[i] = 'A';
        }
    }

    int index_buff1 = 0; // index of buffer 1
    for (int i = 0; i < 1395; i++)
    {
        if ((i % 51) != 0)
        {
            buff2[i] = buff1[index_buff1];
            index_buff1++;
        }
        else if (i == 0) // first character
        {
            buff2[i] = buff1[index_buff1];
            index_buff1++;
        }
        else
        {
            buff2[i] = 'X';
            buff2[i + 1] = 'Y';
            buff2[i + 2] = 'Z';
            i += 2; // make sure next char comes after YZ
        }
        if (i == 1392)
        {
            buff2[i] = 'X';
            buff2[i + 1] = 'Y';
            buff2[i + 2] = 'Z';
            i += 2; // make sure next char comes after YZ
        }
    }
    write(fd[1], buff2, 1395);
    printf("\nDone Successfully\n");

    // close both files
    close(fd[0]);
    close(fd[1]);

    return 0;
}
