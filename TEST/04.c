#include <stdio.h>
#include <stdlib.h>

void print_random_char(FILE *fp) {
  fseek(fp, 0, SEEK_END);
  long fs = ftell(fp);
  int pos = rand()%fs;
  char c;
  fseek(fp, pos, SEEK_SET);
  fread(&c, 1, 1, fp);
  printf("%c at offset %d\n", c, pos);
}

int main() {
  for(int i=0; i < 10; i++) {
    print_random_char(stdin);
  }
}
