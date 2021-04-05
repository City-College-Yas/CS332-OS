
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int a = 10, b = 25, fq = 0, fr = 0;

    fq = fork(); // fork a child - call it Process Q - fk gets fork and the it returns the child process id to the parent(it executes twice one for the parent and once for the child)
    if (fq == 0) // Child successfully forked
    //this happens once for the parent,again for the child
    
    {
        a = a + b;
        //print values of a, b, and
        printf("\nValue a1:%d", a);
        printf("\nValue b1:%d", b);
        printf("\nValue of the pid is: %d\n", getpid());

        fr = fork(); // fork another child - call it Process R //process_id
        if (fr != 0)

        {
            b = b + 15;
            //print values of a, b, and process_id
            printf("\nValue a2:%d", a);
            printf("\nValue b2:%d", b);
            printf("\nValue of the pid is: %d\n", getpid());
        }
        else
        {
            a = (a * b) + 20;
            //print values of a, b, and process_id
            printf("\nValue a3:%d", a);
            printf("\nValue b3:%d", b);
            printf("\nValue of the pid is: %d\n", getpid()); //getpid - child ID
        }
    }
    else
    {
        //print values of a, b, and process_id
        b = a + b - 5;
        printf("\nValue a 4:%d", a);
        printf("\nValue b 4:%d", b);
        printf("\nValue of the pid is: %d\n", getpid());
    }
    return 0;
}
