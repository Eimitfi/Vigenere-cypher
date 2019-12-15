/*
proprietà intellettuale(?) di: Iftimie Dragos Mihaita 
matricola:0000873762
numero prova:
*/

#ifndef _LIST_H
#define _LIST_H
#include <stdio.h>
#include <stdlib.h>
typedef enum{ false, true} boolean;
typedef char element;
typedef struct list_element 
{ 
    element value; 
    struct list_element  *next; 
} item; 
typedef  item* list; 
int equals(element e1, element e2);  //per member
void freelist(list l);
list empty_list(void);
boolean empty(list l);
element head(list l);
list tail(list l);
void showlist(list l);
list cons(element n, list l);
void print_list(list l);
int member(element n, list l);
int length(list l);
list sub_list(int n, list l);
list add(element n, list l);
list append(list l1, list l2) ; //unisce due liste
list reverse(list l) ;
list copy(list l) ;
list delete_element(int el, list l);
 int confronta(element e1, element e2);    //per ordinamento
list insElementOrdInList(element el, list l) ;
list mergeList(list l1, list l2);

#endif


