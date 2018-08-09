#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Random(int minvalue, int maxvalue){
  static int RAND_SEED_FLAG;
  if (RAND_SEED_FLAG == 0){
    srand((unsigned int)time(NULL));
    RAND_SEED_FLAG = 1;
  }
  return minvalue + (int)(rand()*(maxvalue - minvalue + 1.0)/(1.0 + RAND_MAX));
}

int Num[4];
int In[4];
int Pl[4] = {0 , 0 , 0 , 0 };

void create_random(){
  In[0] = Random(0,9);
  int flag;
  for (int i = 1; i < 4; i++){
    while(1){
      int flag = 0;
      int tmp = Random(0,9);
      for (int j = 0; j < i; j++){
        if (tmp == In[j]){
          flag = 1;
        }
      }
      if (flag == 0){
        In[i] = tmp;
        break;
      }
    }
  }
}


void  input_num() {
  int flag;
  while (1) {
    int tmp;
    printf("Please input 4 numbers for Num:\n");
    scanf("%d", &tmp);
    if (tmp/1000 == 0) continue;
    if (tmp/10000 != 0) continue;

    int k = 1000;
    for (int i = 0; i < 4; i++){
      Num[i] = tmp/k;
      tmp %= k;
      k /= 10;
    }

    flag = 0;
    for (int i = 0; i < 3; i++){
      for (int j = i+1; j < 4; j++){
        if (Num[i] == Num[j]){
          flag = 1;
        }
      }
    }
    if (flag == 1) continue;

    break;
  }
}






int main(void){
  input_num();

  int tmp;
  int flag;
  int stage = 0;
  int hit = 0;
  int blow = 0;
  int prehit;

  while (1){
    // printf("Please input 4 numbers:\n");
    // scanf("%d", &tmp);
    if (stage == 0){
      create_random();
    }else if (stage == 1) {
      /* code */
      if (prehit) {

      }
    }else if (stage == 2) {
      /* code */
    }else if (stage == 3) {
      /* code */
    }

    // In[0] = 1;
    // In[1] = 2;
    // In[2] = 3;
    // In[3] = 4;
    // if (tmp/1000 == 0) continue;
    // if (tmp/10000 != 0) continue;
    //
    // int k = 1000;
    // for (int i = 0; i < 4; i++){
    //   In[i] = tmp/k;
    //   tmp %= k;
    //   k /= 10;
    // }
    //
    // flag = 0;
    // for (int i = 0; i < 3; i++){
    //   for (int j = i+1; j < 4; j++){
    //     if (In[i] == In[j]){
    //       flag = 1;
    //     }
    //   }
    // }
    // if (flag == 1) continue;

    for (int i = 0; i < 4; i++) {
      if (In[i] == Num[i]) {
        hit++;
      }
      for (int j = 0; j < 4; j++) {
        if (In[i] == Num[j]) {
          blow++;
        }
      }
    }


    blow-=hit;
    printf("Hit: %d", hit);
    printf("  Blow: %d\n", blow);

    if (hit == 4) break;

    prehit = hit;
    if (stage <= hit) {
      stage = hit;
    }

    hit = 0;
    blow = 0;
  }

}
