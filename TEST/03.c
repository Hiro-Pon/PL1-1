#include <stdio.h>
typedef struct {
  char loc[16];
} campus_t;

void func(campus_t s, campus_t *t) {
  s.loc[0] = 'H';
  t->loc[0] = 'A';
}

int main() {
  campus_t sa = {.loc = "hakusan" };
  campus_t ta = {.loc = "akabane-dai" };
  func(sa, &ta);
  printf("%s\n", sa.loc);
  printf("%s\n", ta.loc);
  int a = sizeof(int);
  printf("%d\n", a);
}
