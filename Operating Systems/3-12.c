/* 3-12.c
    exercise 3.12 of the book

    create a zombie process

    usage: run 
    .\a.out &
    ps -l
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    // fork error handling
    if (pid < 0) {
        fprintf(stderr, "Fork Failed\n");
        exit(1);
    }

    if (pid) {
        // parent process
        printf("parent: %d\n", getpid());
        while (1) 
            sleep(1);
        // return 0;
    } else {
        // child process
        printf("child: %d\n", getpid());
        sleep(2);
        printf("child exit\n");
        exit(1);
    }

    return 0;
}