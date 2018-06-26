#include <stdio.h>
#include "iniad.h"

int main() {
  iniad_t *ptr = new_iniad();
  char *name = get_name(ptr);
  printf("%s\n", name);
}