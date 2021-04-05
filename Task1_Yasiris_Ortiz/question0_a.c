/*
Name: Yasiris Ortiz 
Course: Operating Systems Lab
Description: complete the code snippet given to read and write access permissions of a given file
*/

#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    char *filepath = argv[1];
    int returnval;

    // check if the file exits
    returnval = access(filepath, F_OK);

    if (returnval == 0)
        printf("\n %s exists\n", filepath);
    else
    {
        // handle errors if file does not exits or if it's not accesible
        if (errno == ENOENT)
            printf("%s does not exist\n", filepath);
        else if (errno == EACCES)
            printf("%s is not accessible\n", filepath);
        return 0;
    }

    // Check read access of the file
    returnval = access(filepath, R_OK);
    if (returnval == 0)
    {
        printf("\n %s File has Read permissions\n", filepath);
    }
    else
    {
        // handling errors
        if (errno == ENOENT)
            printf("%s No such file or directory.\n", filepath);
        else if (errno == EACCES)
            printf("%s Read Permission denied .\n", filepath);
    }

    // Check write access of the file
    returnval = access(filepath, W_OK);
    if (returnval == 0)
    {
        printf("\n%s File has Write permissions\n", filepath);
    }
    else
    {
        // handling errors
        if (errno == ENOENT)
            printf("%s No such file or directory.\n", filepath);
        else if (errno == EACCES)
            printf("%s Write Permission denied .\n", filepath);
    }

    return 0; // return 0 if the program runs succesfully
}