#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct diary{
  int year;
  int month;
  int day;
  char title[200];
  struct diary *prev;
  struct diary *next;
}Diary;

typedef struct diaries{
  struct diary *head;
  struct diary *tail;
}Diaries;


Diaries init_list(void){
  Diaries s;
  s.head = NULL;
  s.tail = NULL;
  return s;
}
/*
Diary* init_element(int Y, int M, int D, char T[200]){
  Diary *tmp;
  tmp = malloc(sizeof(Diary));
  tmp->year=Y;
  tmp->day=D;
  tmp->month=M;
  strcpy(tmp->title, T );
  return tmp;
}*/

Diary* init_element(){
  Diary *tmp;
  tmp = malloc(sizeof(Diary));
  int Y,M,D;
  char T[200];


  printf("Year: ");
  scanf("%d", &Y);

  printf("Month: ");
  scanf("%d", &M);

  printf("Day: ");
  scanf("%d", &D);

  printf("Diary title: ");
  scanf("%s", &T);

  tmp->year=Y;
  tmp->day=D;
  tmp->month=M;
  strcpy(tmp->title, T );
  return tmp;
}

Diaries push_back(Diaries s, int Y, int M, int D, char T[200]){
  Diary *a = init_element(Y,M,D,T);


  if (s.head == NULL && s.tail == NULL){
    s.head = a;
    s.tail = a;
    a->prev = a;
    a->next = a;
  }
  else{
    a->next = s.head;
    a->prev = s.tail;
    Diary *tail;
    tail = s.tail;
    tail->next = a;
    s.tail =  a;
    printf("BC\n");
  }

  return s;
}

Diaries push_front(Diaries s, int Y, int M, int D, char T[200]){
  Diary *a = init_element(Y,M,D,T);


  if (s.head == NULL && s.tail == NULL){
    s.head = a;
    s.tail = a;
    a->prev = a;
    a->next = a;
  }
  else{
    a->next = s.head;
    a->prev = s.tail;
    s.head =  a;
  }

  return s;
}

Diaries delete_all(Diaries s){
  if (s.head!=NULL && s.tail !=NULL){
    Diary *tmp1, *tmp2;
    tmp1 = s.head;
    tmp2 = s.tail;
    free(tmp1);
    free(tmp2);
  }
  return init_list();
}


Diaries pop_front(Diaries s){
  if (s.head == NULL && s.tail == NULL){
    return init_list();
  }
  else if( s.head == s.tail  ){
    free(s.tail);
    return init_list();
  }
  Diary *tmp;
  tmp = s.head;
  s.head = tmp->next;
  tmp = s.tail;
  tmp->next = s.head;
  free(tmp);

  return s;
}

Diaries pop_back(Diaries s){
  if (s.head == NULL && s.tail == NULL){
    return init_list();
  }
  else if( s.head == s.tail  ){
    free(s.tail);
    return init_list();
  }
  Diary *tmp;
  tmp = s.tail;
  s.tail = tmp->prev;
  tmp = s.head;
  tmp->prev = s.tail;
  free(tmp);


  return s;
}


Diaries print(Diaries s){
  if (s.head!=NULL && s.tail !=NULL){
    Diary *tmp;
    tmp = s.head;
    printf("%d 年 %d 月 %d 日 :  %s \n", tmp->year, tmp->month, tmp->day, tmp->title);
    for (tmp = tmp->next; s.head != tmp; tmp = tmp->next ){
      printf("%d 年 %d 月 %d 日 :  %s \n", tmp->year, tmp->month, tmp->day, tmp->title);
    }
  }else{
    printf("空\n");
  }
  printf("\n");
  return s;
}


/*
int main(void){
  Diaries s = init_list();
  s = push_back(s,1926, 12, 25, "昭和時代スタート!");
  s = push_front(s, 1912, 7, 30, "大正時代スタート!");
  s = push_back(s, 1989, 1, 7, "平成時代スタート!");
  print(s);



  s = pop_front(s);
  print(s);


  s = pop_back(s);
  print(s);

  s = pop_front(s);
  print(s);

  s = delete_all(s);
}*/

typedef struct command{
  char command[200];
  Diaries (*p)(Diaries);
} Command;

Command C[5] = {
  {"fpush", push_front},
  {"bpush", push_back},
  {"fpop", pop_front},
  {"bpop", pop_back},
  {"disp", print}
};

int main(void){
  Diaries s = init_list();
  char com[20];

  while (1){
    printf("Please input a command (fpush, bpush, fpop, bpop, disp, exit): \n");
    scanf("%s",&com);// scanfでコマンドを入力

    for (int i = 0; i < 5; i++){
      if (!strcmp(com,C[i].command)){
        C[i].p();
        break;
      }
    }

    if (!strcmp(com, "exit")) break;
  }

  s = all_delete(s);
}
