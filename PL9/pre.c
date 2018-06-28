#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>


int main() {
  void  *h = dlopen("libtoday.so", RTLD_NOW);
  if (NULL == h){
    printf("EEEEEEEEEE\n");
    /*
    fprintf(stderr, "faild%s\n", RTDL_NOW());
    exit(-1);*/
  }
  printf("h----%p\n",h );
  void *p = dlsym(h,"today");
  printf("p----%p\n",p );
  char *(*p_today)() = p;
  char  *str = (*p_today)();
  printf("%s\n", str);
}
