/* 3-12.c
    exercise 3.12 of the book

    create a zombie process

    usage: run 
    .\a.out &
    # wait 2 seconds
    ps -l
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pid = fork();

    // fork error handling
    if (pid < 0) {
        fprintf(stderr, "Fork Failed\n");
        exit(1);
    }

    if (pid) {
        // parent process
        sleep(10);
        // return 0;
    } else {
        // child process
        sleep(3);
        exit(1);
    }

    return 0;
}