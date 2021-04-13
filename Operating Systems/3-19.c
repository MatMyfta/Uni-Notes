/* 3.19
    usage: .\a.out <string>

    parent process:
        given an argument <string>, writes the argument in a pipe
    
    child process:
        reads the <string> in written in the pipe by the parent process,
        then inverts all the capitalizations (a->A && A->a). 
        finally prints the caps-inverted string.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 25
#define READ        0
#define WRITE       1

/* 
function that inverts all the capitalizations:
    given a string: "Test", the string will become "tEST".
*/
void invertCaps(char *string) {
    for (int i = 0; i < BUFFER_SIZE; i++) {
        if (string[i] >= 'a' && string[i] <= 'z') 
            string[i] += 'A' - 'a';
        else if (string[i] >= 'A' && string[i] <= 'Z') 
            string[i] += 'a' - 'A';
    }
}

int main(int argc, char **argv) {
    // argument error handling
    if (argc != 2) {
        fprintf(stderr, "!usage: %s <string>\n", argv[0]);
        exit(1);
    }

    int fd[2];
    char *write_msg = argv[1];
    char read_msg[BUFFER_SIZE];

    // pipe creation and error handling
    if (pipe(fd) < 0) {
        fprintf(stderr, "Pipe Failed\n");
        exit(1);
    }

    pid_t pid = fork();
    // fork error handling
    if (pid < 0) {
        fprintf(stderr, "Fork Failed\n");
        exit(1);
    }

    if (pid > 0) {
        // parent process
        close(fd[READ]);

        // write the message to the write end (1)
        write(fd[WRITE], write_msg, strlen(write_msg)+1);

        close(fd[WRITE]);
    } else {
        // child process
        close(fd[WRITE]);

        // read the message from the read end (0)
        read(fd[READ], read_msg, BUFFER_SIZE);
        invertCaps(read_msg);
        printf("message: %s\n", read_msg);

        close(fd[READ]);
    }

    return 0;
}