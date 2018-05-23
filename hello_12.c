#include<stdio.h>
#include<stdlib.h>

struct student{
        int id;
        char *name;
        struct student *next;
};

int main(void){
        struct student *list, *head, *final;

        list = malloc(sizeof(struct student));
        list->id = 3;
        list->name = "Jyouho";
        list->next = NULL;
        head = list;
        final = list;
        /*
          問題2-1:
        */
                                
        list = malloc(sizeof(struct student));
        list->id = 1;
        list->name = "Toyo";
        list->next = head;
        head = list;

        /*
        問題2-2:
        */
       for (list = head;list!=NULL;list=list->next){
           printf("id: %d, name: %s\n", list->id, list->name);
           }   


        /*
          問題2-3:
        */
       list = final;

       list = malloc(sizeof(struct student));
       list->id = 4;
       list->name = "Renka";
       list->next = NULL;

       final->next = list;
       final = list;



       for (list = head;list!=NULL;list=list->next){
           printf("id: %d, name: %s\n", list->id, list->name);
           }  
        /*
          発展問題2-4:
        */

       list = malloc(sizeof(struct student));
       list->id = 2;
       list->name = "INIAD";
       list->next = head->next;
       head->next = list;

       for (list = head;list!=NULL;list=list->next){
           printf("id: %d, name: %s\n", list->id, list->name);
           }  
                                
        /*
          発展問題2-5:
        */
       list = head->next;
       list->next = final;

       for (list = head;list!=NULL;list=list->next){
           printf("id: %d, name: %s\n", list->id, list->name);
           } 
       
                                
        /*
          問題2-2:
        */
}