/* stringfun
    NOT FUNCTIONING
    usage .\a.out <string> <character>

    implementation of some function that uses the <string>

    char *stringrev(char *str) 
    int chrpos(char *str, char c) 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    return the length of the string
*/
int strlength (char *str) {
    int len = 0;
    while (*(str++) != '\0') len++;
    return len;
}
/*
    reverse the string.
*/
char* stringrev(char *str) {
    int len = strlength(str), i;
    char *tail = str+len;
    char *rev = strcpy(rev, str);

    // reversing
    for (i = 0; i < len; i++) {
        *(rev+i) = *(str+(len-i));
    }
    
    return rev;
}
/*
    returns the position of the first occurence of the
    character c in the string str.

    returns -1 if the character is not in the string
*/
int chrpos(char *str, char c) {
    int pos = 0;
    while (str[pos] != '\0' && str[pos] != c) 
        pos++;
    if (str[pos] == '\0')
        return -1;
    return pos;
}

int main(int argc, char **argv) {
    // argument error handling
    if (argc != 3) {
        fprintf(stderr, "!usage: %s <string> <character>\n", argv[0]);
        exit(1);
    }

    int len = strlength(argv[1]);
    char* str = strcpy(str, argv[1]);
    char* c = argv[2];
    char *rev = stringrev(argv[1]);

    printf("length: %d\n", len);
    printf("reversed: %s\n", rev);
    printf("position of character %s: %d\n", c, chrpos(str, *c));

    return 0;
}