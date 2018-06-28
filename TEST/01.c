#include <stdio.h>
int main() {
  struct classroom {
    char *name;
    int area;
  };
  //  Q1-6
  typedef struct classroom classroom_t;

  classroom_t r4201 = { .name="4201", .area=10 };
  struct classroom r3201 = r4201;
  return r3201.area;
}
