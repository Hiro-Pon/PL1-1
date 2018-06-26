#include <stdio.h>

long file_size(FILE *fp) {
    long orig = ftell(fp);
    fseek(fp, 0, SEEK_END);
    long fs = ftell(fp);
    fseek(fp, orig, SEEK_SET);
    return fs;
}

int main() {
    const long fs = file_size(stdin);
    const long skip = 7;
    char buf[64];

    for(long offset=0; offset < fs; offset+=skip){
        fseek(stdin, offset, SEEK_END);
        int n = fread(buf, 1, 1, stdin);
        fwrite(buf, 1, n, stdout);
    }
}