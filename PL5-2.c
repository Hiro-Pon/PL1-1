#include <stdio.h>

int main(void){
  char ch[10];
  FILE * fp1 = fopen("text.txt","r"); // text.txt
  FILE * fp2 = fopen("text_copy.txt","w"); // text_copy.txt

  while (!feof(fp1)){
        int a = fread(ch,1, sizeof(char), fp1);
        fwrite(ch, 1, a, fp2);
  }
  fclose(fp1);
  fclose(fp2);
}