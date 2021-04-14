#include <stdio.h>
#include <stdlib.h>

int lengthofstring(char* str) {
    int counter = 0;
    while (str[counter] != '\0')
        counter++;
    return counter;
}

char* stringrev(char* str) {
    int dim;
    dim = lengthofstring(str);
    char* result;
    result = malloc(sizeof(char)*(dim+1));
    result[dim] = '\0';
    for (int i = 0, j = dim - 1; i < dim; i++, j--)
    {
        result[j]=str[i];
    }
    return result;
}

int stringpos(char* str, char chr) {
    int res = -1;
    int dim, i = 0;
    dim = lengthofstring(str);
    while ((i < dim) && (str[i] != chr)) {
        i++;
    }
    if (str[i] == chr)
        res = i;
    return res;
}

int main(int argc, char **argv) {
    int code=0;
    if (argc<2) {
        printf("Usage: %s \"stringa\"\n", argv[0]);
        code=2;
    } else if (argc == 2) {
        char* stringa = stringrev(argv[1]);
        printf("length of \"%s\" == %d\n", argv[1], lengthofstring(argv[1]));
        printf("reverse of \"%s\": %s\n", argv[1], stringa);
        free(stringa);
    } else {
        char* stringa = stringrev(argv[1]);
        printf("length of \"%s\" == %d\n", argv[1], lengthofstring(argv[1]));
        printf("reverse of \"%s\": %s\n", argv[1], stringa);
        printf("position of %c in \"%s\": %d\n", argv[2][0], argv[1], stringpos(argv[1], argv[2][0]));
        free(stringa);
    }
    return code;
};
