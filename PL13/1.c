#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Man: 0, Woman: 1
// Student: 0, Company: 1, PartTime: 2, Others: 3
// No: 0, Yes: 1
enum gender{
  Man,
  Woman
};
enum profession{
  Student,
  Company,
  PartTime,
  Others
};

enum twoselect{
  No,
  Yes
};

// structuer questionnaire
struct questionnaire{
  enum gender Gender;
  int Age;
  enum profession Profession;
  enum twoselect LiveInAakabane;
  enum twoselect OverTwenty;
};


struct questionnaire List[100];
int maxid = 0;

void addquestionnaire(){
    int tmp;
    int flag = 1;

    printf("What is your gender?(Man: 0, Woman: 1)\n");
    scanf("%d", &tmp);
    while (!(tmp==0 ^ tmp==1)) {
      printf("What is your gender?(Man: 0, Woman: 1)\n");
      scanf("%d", &tmp);
    }
    List[maxid].Gender = tmp;

    printf("What is your age?\n");
    scanf("%d", &tmp);
    List[maxid].Age = tmp;

    printf("What is your profession?(Student: 0, Company worker: 1, Part-time worker: 2, Others: 3)\n");
    scanf("%d", &tmp);
    while (!(tmp==0 ^ tmp==1 ^ tmp==2 ^ tmp==3)) {
      printf("What is your profession?(Student: 0, Company worker: 1, Part-time worker: 2, Others: 3)\n");
      scanf("%d", &tmp);
    }
    List[maxid].Profession = tmp;

    printf("Do you live in Akabane?(No: 0, Yes: 1)\n");
    scanf("%d", &tmp);
    while (!(tmp==0 ^ tmp==1)) {
      printf("Do you live in Akabane?(No: 0, Yes: 1)\n");
      scanf("%d", &tmp);
    }
    List[maxid].LiveInAakabane = tmp;

    printf("Are you over 20 years old?(No: 0, Yes: 1)\n");
    scanf("%d", &tmp);
    while (!(tmp==0 ^ tmp==1)) {
      printf("Are you over 20 years old?(No: 0, Yes: 1)\n");
      scanf("%d", &tmp);
    }
    List[maxid].OverTwenty = tmp;

    maxid++;
}


void print(){
    for (int i = 0; i < maxid; i++){
      printf("Gender: ");
      switch(List[i].Gender){
        case Man:
          printf("Man\n");
          break;
        case Woman:
          printf("Woman\n");
          break;
      }

      printf("Age: %d\n", List[i].Age);

      printf("Profession: ");
      switch(List[i].Age){
        case Student:
          printf("Student\n");
          break;
        case Company:
          printf("Company worker\n");
          break;
        case PartTime:
          printf("Part-time worker\n");
          break;
        case Others:
          printf("Others\n");
          break;
      }

      printf("Live in Akabane: ");
      switch(List[i].LiveInAakabane){
        case No:
          printf("No\n");
          break;
        case Yes:
          printf("Yes\n");
          break;
      }

      printf("Over 20 years old: ");
      switch(List[i].OverTwenty){
        case No:
          printf("No\n\n");
          break;
        case Yes:
          printf("Yes\n\n");
          break;
      }
    }
}


int profrate(){
  int profession_List[4];
  for (int i; i < maxid; i++) {
    switch (List[i].Profession) {
      case Student:
        profession_List[0]++;
        break;
      case Company:
        profession_List[1]++;
        break;
      case PartTime:
        profession_List[2]++;
        break;
      case Others:
        profession_List[3]++;
        break;
    }
  }

  for (int i; i < 4; i++) {
    int tm = profession_List[i] / maxid;
    printf("%d\n", tm);
    printf("%d\n", profession_List[1]);
  }
}

int main(void){
  char command[100];

  while(1){
    printf("\nPlease input a command: Add, Print, Exit\n>>> ");
    scanf("%s", command); // scanfでコマンドを入力

    if (!strcmp(command,"Add")) addquestionnaire();
    else if (!strcmp(command,"Print")) print();
    else if (!strcmp(command,"Profrate")) profrate();
    else if (!strcmp(command,"Exit")) break;
  }
}
