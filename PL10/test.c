#include <stdio.h>
#include <stdlib.h>

int main() {
  typedef struct {
    int n; // size of array elements;
    char s[];
  } q2_t;

  char *str = "iniad";
  q2_t *p = malloc(sizeof(q2_t));
  p->n = 1;
  p->s = str;
  printf("%s\n", p->s); // print a string "iniad"
}
