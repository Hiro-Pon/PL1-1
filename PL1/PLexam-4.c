#include <stdio.h>
#include <stdlib.h>
int main() {
    struct node {
        struct node *next;
    };
    typedef struct node node_t;
    node_t *x = NULL;
    for (int i=0; i < 99; i++) {
        node_t *t = malloc(sizeof(t)); // assignment 1a
        t->next = x;
        x = t;
    }
    for (node_t *p=x; p->next != NULL; p = p->next) {
        printf("%p\n", p);
        
    }
}

