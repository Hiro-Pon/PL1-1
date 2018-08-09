#include <stdio.h>
typedef struct {
  char color[16];
} watch_t;

void func(watch_t *s, watch_t t) {
  s->color[0] = 'R';
  t.color[0] = 'B';
}
int *num = 0;

int next(){
  return *num + 2;
}
// int main() {
//   for(int i=next(); i <= 12; i=next()) {
//     if (i % 5 == 0) {
//       break;
//     }
//     switch(i) {
//     case 6:
//       continue;
//     case 8:
//       break;
//     }
//     printf("%d ", i);
//   }
//   printf("\n");
// }

int main() {
  for(int i = 2; i <= 12; i = i + 2) {
    printf("aaa%d\n", i);
    if (i % 5 == 0) {
      break;
    }
    switch(i) {
    case 6:
     continue;
    case 8:
     break;
    }
    printf("%d ", i);
  }
  printf("\n");
}
