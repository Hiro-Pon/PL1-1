#include <stdio.h>
#include <stdlib.h>

struct nd {
  struct nd *fwd;
};

struct nd *alloc_nd() {
  struct nd *p;
  p = malloc(sizeof(struct nd));
  return p;
}

int main() {
  struct nd *x = NULL;
  for (int i=0; i < 100; i++) {
      struct nd *t = alloc_nd();
      // Q1-9
      t->fwd = x;
      x = t;
  }
  for (struct nd *n=x; NULL != n; n->fwd) {
      printf("%p\n", n);
  }
}
