#include <stdio.h>

int main(void){
  char ch[100];

  fread(ch, sizeof(char), sizeof(ch), stdin);

  
  fwrite(ch, sizeof(char), 100, stdout);

}