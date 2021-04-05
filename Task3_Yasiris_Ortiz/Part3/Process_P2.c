/* Name: Yasiris Ortiz
   Operating Systems Lab: Task 3
   Description: Copy the contents of source.txt into destination1.txt and destination2.txt as
per the following procedure until you reach the end of the file:
1. Read the next 50 characters from source.txt , and write to destination1.txt
2. Then the next 100 characters are read from source.txt and written into destination2.txt. 
   
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

// main function
int main()
{
    int fd[3];
    char buf1[2000];
    char buf2[2000];
    char buf3[2000];

    //open source.txt file in READ ONLY mode
    // open destination.txt file in write only mode, truncate if already exits or create if not available
    fd[0] = open("source.txt", O_RDONLY);
    fd[1] = open("destination1.txt", O_WRONLY);
    fd[2] = open("destination2.txt", O_WRONLY);

    // handling errors for all the files
    // if (fd[0] == -1 || fd[1] == -1 || fd[2] == -1)
    // {
    // printf("Error Opening file\n");
    // perror("open");
    // return -1;
    // }

    // read from the source file
    read(fd[0], buf1, 1314);

    // for loop to select the first 50 characters and then the next 100 characters
    int k = 0;
    for (int i = 0; i < 150; i++)
    {
        if (i < 50)
        {
            buf2[i] = buf1[i];
        }
        else if (i < 150)
        {
            buf3[k] = buf1[i];
            k++;
        }
    }
    // write output in files destination1.txt and destination2.txt
    write(fd[1], buf2, 50);
    write(fd[2], buf3, 100);

    // closing all the files
    close(fd[0]);
    close(fd[1]);
    close(fd[2]);

    printf("Run has finished successfully!\n");

    return 0;
}
