#include <stdio.h>
int main() {
  struct contact {
    char *name;
    char *email;
  };
  struct contact enryo;
  struct contact *p_enryo = &enryo;
  p_enryo->name = "Enryo Inoue";
  p_enryo->email = "enryo_inoue@toyo.jp";
}
