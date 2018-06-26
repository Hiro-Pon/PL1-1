#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data{
    char name[20];
    int score;
    struct data *next;
}student;

void print(student *first){
    printf("%s  %d\n",first->name,first->score);
    for (student *now = first->next; now != first; now = now->next ){
        printf("%s  %d\n",now->name,now->score);
    }
}

void append(student *first,student *add){
    student *last;
    add->next = first;
    for (student *now = first->next; now != first; now = now->next ){
        printf("%s  %d\n",now->name,now->score);
        last = now;
    }
    last->next = add;
}

int data(student *first, char name[20]){
  student *now;
  int score = -1;
  for (now = first->next; now != first ; now = now->next) {
    if (!strcmp(now->name , name)){
      score = now->score;
      printf("%d\n",score);
      break;
    }
  }
  return score;
}

student* search(student *first, char name[20]){
  student *now;
  for (now = first->next; now != first ; now = now->next) {
    if (!strcmp(now->name , name)){
      return &now;
    }
  }
  return NULL;
}

int main(){
    student *INIAD, *Toyo, *Jyoho, *Renke;
    Renke = malloc(sizeof(student));
    strcpy(Renke->name,"Renke");
    Renke->score = 75;
    Jyoho = malloc(sizeof(student));
    strcpy(Jyoho->name,"Jyoho");
    Jyoho->score = 70;
    Jyoho->next = Renke;
    Toyo = malloc(sizeof(student));
    strcpy(Toyo->name,"Toyo");
    Toyo->score = 80;
    Toyo->next = Jyoho;
    INIAD = malloc(sizeof(student));
    strcpy(INIAD->name,"INIAD");
    INIAD->score = 90;
    INIAD->next = Toyo;
    Renke->next = INIAD;

    print(INIAD);

    student *aaa = malloc(sizeof(student));
    strcpy(aaa->name,"aaa");
    aaa->score = 90;
    append(INIAD,aaa);
    print(INIAD);

    data(INIAD,"Jyoho");

    student *a;
    a = search(INIAD,"Jyoho");
    printf("%s\n", );

}
