/*
SIMPLE COMMAND INTERPRETER
Name: Yasiris Ortiz
Class: Operating Systems Lab - Task 4
Description: Write a special simple command interpreter that takes command and its arguments. This interpreter
is a program where the main process creates a child process to execute the command using exec()
family functions. After executing the command, it asks for a new command input (i.e., parent wait for
child). The interpreter program will get terminated when the user enters quit. */

// Import libraries
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    printf("\nEnter a command or press 'q' or 'Q' to quit:\n");
    int cont = 1;
    pid_t pid;

    while (1) // while true
    {
        char commandInput[1000];
        printf("(base-yasiris) >>>> ");

        /* read input until ENTER is pressed */
        // %[^\n]s : it is an edit conversion code that can be an alternative of gets(), and terminates with a newline
        scanf(" %[^\n]s", commandInput); // scanf allow us to scan input from standard in pr keyboard

        // block pf code to quit the program if the user enters either 'q' or 'Q'
        if (!strcmp(commandInput, "q") || !strcmp(commandInput, "Q"))
            break;
        // continue the program if not quit is pressed!
        char *arg[100], *token, *status = NULL;
        int i = 0;

        // array pointer going to the next token, or NULL if there ar enot more tokens
        for (token = strtok_r(commandInput, " ", &status); token != NULL; token = strtok_r(NULL, " ", &status))
        {
            arg[i] = token; // arguments store in array arg
            i++;
        }
        arg[i] = NULL; // clear array

        pid = fork(); // fork child process to be executed

        if (pid == 0)
        {
            execvp(arg[0], arg); // replaces the current process with a new one specified by the file
            printf("File/command NOT Found\n");
            return 0;
        }

        else
        {
            wait(NULL); // parent waits until child finishes
        }
    }
    return 0;
}