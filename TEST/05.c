#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char *to_lower(int, char *); // lower-cases a string
char *to_upper(int, char *); // upper-cases a string

int main() {
  char *data[] = { "Linux", "iPad" };
  for(int i=0; i<sizeof(data)/sizeof(data[0]); i++) {
    char *d = data[i];
    char *(*p)(int, char*);
    if (islower(d[0])) {
      p = to_lower;
    } else {
      p = to_upper;
    }
    char *s = (*p)(strlen(d), d);
    printf("%s\n", s);
  }
}

char *to_lower(int n, char *s) {
  char *r = malloc(n+1);
  for(int i=0; i<n; i++) r[i]= tolower(s[i]);
  r[n] = 0;
  return r;
}

char *to_upper(int n, char *s) {
  char *r = malloc(n+1);
  for(int i=0; i<n; i++) r[i]= toupper(s[i]);
  r[n] = 0;
  return r;
}
