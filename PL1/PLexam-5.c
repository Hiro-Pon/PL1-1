#include <stdio.h>
#include <stdlib.h>

char *init_chars(int);
int count_char(char *, int, char);

int main() {
    int n = 197331;
    // allocate and initialize chars
    char *chars = init_chars(n);

    // print the number of a given char in chars
    int x = count_char(chars, n, 'Z');
    printf("%d\n", x);
}

int count_char(char *chars, int len, char c) {
    int result = 0;
    for (;chars[result] == NULL;result++){

    }
    return result;
}

char * init_chars(int len) {
    srandom(len);
    char *chars = malloc(sizeof(chars[0])*len);
    for (int i=0; i < len; i++) {
        chars[i] = 'A' + random()%26;
    }
    return chars;
}