#include <stdio.h>



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

Diary* init_element(int Y, int M, int D, char T[200]){
  Diary *tmp;
  tmp = malloc(sizeof(Diary));
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
    s.tail =  a;
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

void print(Diaries s){
  if (s.head!=NULL && s.tail !=NULL){
    Diary *tmp;
    printf("%d 年 %d 月 %d 日 :  %s \n", tmp->year, tmp->month, tmp->day, tmp->title);
    for (tmp = tmp->next; s.head != tmp->next; tmp = tmp->next ){
      printf("%d 年 %d 月 %d 日 :  %s \n", tmp->year, tmp->month, tmp->day, tmp->title);
    }
  }
  printf("\n");
}







int main(void){
  Diaries s = init_list();

  s = push_back(s,1926, 12, 25, "昭和時代スタート!");

  s = push_front(s, 1912, 7, 30, "大正時代スタート!");
  s = push_back(s, 1989, 1, 7, "平成時代スタート!");
  print(s);
  /*


  s = pop_front(s);
  print(s);

  s = pop_back(s);
  print(s);

  s = pop_front(s);
  print(s);

  s = delete_all(s);

  */
}
