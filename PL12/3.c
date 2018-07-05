#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct diary{
  int year;
  int month;
  int day;
  char title[200];
  struct diary *next;
  struct diary *prev;
} Diary;

typedef struct diaries{
  struct diary *head;
  struct diary *tail;
} Diaries;

Diaries init_list(void){
  Diaries s;
  s.head = NULL;
  s.tail = NULL;
  return s;
}

Diary* init_element(int year, int month, int day, char title[]){
  Diary *tmp;
  tmp = malloc(sizeof(Diary));

  tmp->year=year;
  tmp->month=month;
  tmp->day=day;
  strcpy(tmp->title, title );

  return tmp;
}

Diaries push_back(Diaries s, int year, int month, int day, char title[]){
  Diary *tmp = init_element(year, month, day, title);

  if (s.head == NULL && s.tail == NULL){

    /* Problem 08-1-6 */

  }
  else{

    /* Problem 08-1-6 */

  }
  return s;
}

Diaries push_front(Diaries s, int year, int month, int day, char title[]){
  Diary *tmp = init_element(year, month, day, title);

  if (s.head == NULL && s.tail == NULL){

    /* Problem 08-1-7 */

  }
  else{

    /* Problem 08-1-7 */

  }
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

  /* Problem 08-1-8 */

  return s;
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

  /* Problem 08-1-9 */

  return s;
}

void print(Diaries s){
  if (s.head!=NULL && s.tail !=NULL){
    Diary *dia;
    for (/* Problem 08-1-4 */){
      printf("%d / %d / %d :  title: %s \n", dia->year, dia->month, dia->day, dia->title);
    }
  }
  printf("\n");
}

Diaries all_delete(Diaries s){
  if (s.head!=NULL && s.tail !=NULL){
    Diary * tmp1, *tmp2;
    tmp1 = s.head;

    /* Problem 08-1-5 */

  }
  return init_list();
}

int main(void){
  Diaries s = init_list();

  s = push_back(s, 1926, 12, 25, "昭和時代スタート!");
  s = push_front(s, 1912, 7, 30, "大正時代スタート!");
  s = push_back(s, 1989, 1, 7, "平成時代スタート!");
  print(s);

  s = pop_front(s);
  print(s);

  s = pop_back(s);
  print(s);

  s = pop_front(s);
  print(s);

  s = all_delete(s);
}
