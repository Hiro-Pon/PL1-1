#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*-------------------------------*/
/*------------- 7th -------------*/
/*-------------------------------*/

/*------------- 7-1-1 -------------*/
typedef struct data{
  char name[20];
  int score;
  struct data* next;
} student;

/*------------- 7-1-4 -------------*/
// The function append that adds one element to a circular linked list
void append(student *first,student *add){
    student *last;
    add->next = first;
    for (student *now = first->next; now != first; now = now->next ){
        printf("%s  %d\n",now->name,now->score);
        last = now;
    }
    last->next = add;
}

/*------------- 7-1-5 -------------*/
// The function data that returns the score of the element of a circular linked list whose names match
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
/*------------- 7-1-6 -------------*/
// The function search that returns the element of a circular linked list whose names match
student* search(student *List, char name[]){

}


/*-------------------------------*/
/*------------- 9th -------------*/
/*-------------------------------*/

/*------------- 9-1-1 -------------*/
// Declare a pointer array to be a hash table
// ここを考える
static *hashtable[111];
static int tablesize = 111;
/*------------- 9-1-2 -------------*/
// The function hash that returns a hash value for an argument string
int hash(char s[]){
  int i = 0;
  while (*s) {
    /* code */
    i += *s++;
  }
  // ここを考える
  return i%tablesize;
}

/*------------- 9-1-3 -------------*/
// The function init_hashtable that assigns NULL to all elements of the hash table
void init_hashtable(void){
  for (int i = 0; i < tablesize; i++){
    hashtable[i] = NULL;
  }
}

/*------------- 9-1-4 -------------*/
// The function hsearch that returns the element of a hash table whose names match
student* hsearch(char name[]){

  // ここを考える

}

/*------------- 9-1-5 -------------*/
// The function hdata that returns the score of  the element of a hash table whose names match
int hdata(char name[]){

  // ここを考える

}

/*------------- 9-1-6 -------------*/
// The function create_key is a function for registering names and scores in the hash table
void create_key( char name[], int score){

  // ここを考える

}

/*-------------------------------*/
/*------------- main ------------*/
/*-------------------------------*/
int main(void){
  init_hashtable();

  create_key("INIAD", 100);
  create_key("Jyoho", 20);
  create_key("Renke", 30);
  create_key("Engineer", 10);
  create_key("Toyo", 80);

  printf("%d , %d\n", hdata("INIAD"), hash("INIAD"));
  printf("%d , %d\n", hdata("Jyoho"), hash("Jyoho"));
  printf("%d , %d\n", hdata("Renke"), hash("Renke"));
  printf("%d , %d\n", hdata("Engineer"), hash("Engineer"));
  printf("%d , %d\n", hdata("Toyo"), hash("Toyo"));
  printf("%d , %d\n", hdata("INIAD"), hash("INIAD"));
}
