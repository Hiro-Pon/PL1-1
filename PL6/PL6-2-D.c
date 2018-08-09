#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct diaries{
    int year;
    int month;
    int day;
    char title[200];
    struct diaries *next;
}Diaries;

Diaries* push_back( Diaries *list, int year, int month, int day, char title[] ){
  Diaries *diary;
  diary = malloc(sizeof(struct diaries));
  diary->year = year;
  diary->month = month;
  diary->day = day;
  strcpy(diary->title,title);
  diary->next = NULL;

   if (list == NULL){
     diary->next = NULL;
     return diary;
   }else {
     Diaries *Diary;
     for (Diary = list; Diary->next != NULL;) {
       /* code */
       Diary = Diary->next;
     }
     Diary->next = diary;
   }
   return list;
}

void print(Diaries *list){
   Diaries *diary;
   printf("%d年%d月%d日\n", list->year, list->month, list->day);
   printf("%s\n", list->title);

   for (diary = list; diary->next != list;){
     diary = diary->next;
     printf("%d年%d月%d日\n", diary->year, diary->month, diary->day);
     printf("%s\n", diary->title);

   }
}


void delete_all(Diaries *list){
  Diaries *Diary;
  Diaries *PreDiary;

  while (Diary->next != NULL) {
    for (Diary = list; Diary->next != NULL;) {
      PreDiary = Diary;
      Diary = Diary->next;
    }
    PreDiary = NULL;
    free(Diary);
    Diary = list;
  }


}

int main(void){
  Diaries *list = NULL;
  /* Add a diary to the end of the list */
  list = push_back(list, 1912, 7, 30, "大正時代スタート!");
  list = push_back(list, 1926, 12, 25, "昭和時代スタート!");
  list = push_back(list, 1989, 1, 7, "平成時代スタート!");
  /* Display all diaries */
  print(list);

   /* Delete all diaries */
  //delete_all(list);
}
