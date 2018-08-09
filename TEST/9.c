#include <stdio.h>
#include <stdlib.h>

struct watch {
  struct watch *lnk;
  char name[16];
};

struct watch *alloc_watch() {
  struct watch *p;
  p = malloc(sizeof(struct watch));
  return p;
}

int main() {
  struct watch *x = NULL;
  for (int i=0; i < 10; i++) {
      struct watch *t = alloc_watch();
      sprintf(t->name, "INIAD-%d", i);
      // Q1-9
      x = t;
  }
  for (struct watch *n=x; NULL != n; [Q1-10]) {
      printf("%s\n", n->name);
  }
}
