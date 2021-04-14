/* charcount
    usage: <input> | ./a.out <matching_character>

    given an input, this program counts the number of occurences
    of the <matching_character>.
    the output of this program is the input, but with all the
    matching character marked in red; and finally, the number
    of occurrences of the matching character in the input.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int count_c = 0;
    char match, c;

    // argument error handling
    if (argc != 2) {
        fprintf(stderr, "!usage: %s <character>\n", argv[0]);
        exit(1);
    }

    match = *(argv[1]);

    while ((c = getchar()) != EOF) {
        if (c == match) {
            count_c++;
            printf("\033[0;31m%c\033[0;0m", match);
        } else
            printf("%c",c);
    }

    printf("\n\033[0;33mnumber of '%c' character found: %d\033[0;0m\n", match, count_c);
}