/* lengthof
    usage: .\a.out <string>

    prints the length of <string>
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    // argument error handling
    if (argc != 2) {
        fprintf(stderr, "!usage: %s <string>\n", argv[0]);
        exit(1);
    }
    
    // counting the length of the string
    int len = 0;
    char *c = argv[1];
    while (*c != '\0') {
        len++;
        c++;
    }

    printf("%d", len);

    return 0;
}