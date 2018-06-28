#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>


int main() {
  void  *h = dlopen("libq3.so", RTLD_NOW);
  void *p = dlsym(h,"magic");
  char *(*p_magic)() = p;
  char *str = (*p_magic)();
  printf("%s\n", str);
}
