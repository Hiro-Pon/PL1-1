#include <stdio.h>
typedef struct {
  char *name;
} iniad_t;

int main() {
  iniad_t INIAD = { .name = "iniad" };
  printf("%s\n", INIAD.name);
}