/* fork.c
    this example is copied from the book 'Operating System 
    Concepts - A. Silberschatz, B. Galvin (9th edition)'.

    simple creation of a separate process using UNIX fork() 
    system call.
*/

#include <sys/types.h>      //
#include <stdio.h>          // printf
#include <stdlib.h>         // exit
#include <unistd.h>         // fork
#include <sys/wait.h>       // wait

int main(int argc, char **argv) {
    // fork a child process
    int pid = fork();
    int status;

    // fork error handling
    if (pid < 0) {
        fprintf(stderr, "Fork Failed");
        exit(1);
    }

    if (pid == 0) {
        // child process
        printf("C PID: %5d\n", pid);
    }
    else {
        // parent process
        // wait for the child process to termine
        wait(&status);
        printf("P PID: %5d\n", pid);
    }

    return 0;
}