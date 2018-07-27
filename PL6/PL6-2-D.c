#include<stdio.h>

typedef struct diaries{
    int year;
    int month;
    int day;
    char title[200];
    struct diaries *next;
}Diaries;

Diaries* push_back( Diaries *list, int year, int month, int day, char title[] ){
   Diaries *diary;

   if (list == NULL){

      diary->year =  year;
      diary->month = month;
      diary->day = day;
      diary->title[200] = title;
      diary->next = NULL;

      return diary;
   }
   else {

      

   }
   return list;
}

void print(Diaries *list){
   Diaries *diary;

   for ( ここを考える ){
      printf("%d年%d月%d日\n", diary->year, diary->month, diary->day);
      printf("%s\n", diary->title);
   }
}

void delete_all(Diaries *list){

   ここを考える

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
   delete_all(list);
}
