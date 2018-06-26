#include <stdio.h>
int main() {
    FILE *file_p;
    file_p = fopen("text.txt","w");
    char ch[30] = "I am a student at INIAD!";

    fwrite(ch,sizeof(char),24,file_p);
    fclose(file_ps);
}
