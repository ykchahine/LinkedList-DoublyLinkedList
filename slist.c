#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "slist.h"
#include "utils.h"



snode* snode_create(int data, snode* next){
  snode* p = (snode*)malloc(sizeof(snode));
  p->data = data;
  p->next = next;

  return p;

}


slist* slist_create(void){

  slist* p = (slist*)malloc(sizeof(slist));
  p->head = NULL;
  p->tail = NULL;

  p->size = 0;

  return p;

}

bool slist_empty(slist* list) {return list->size == 0;}
size_t slist_size(slist* list) {return list->size;}

void slist_popfront(slist* list);
void slist_popback(slist* list);

void slist_pushfront(slist* list, int data){

  snode* p = (snode*)malloc(sizeof(snode));
  p->data = x;
  p->next = list->head;
  list->head = p;
  list->size

}
void slist_pushback(slist* list, int data){
  snode* p = (snode*)malloc(sizeof(snode));
  p->data = x;
  p->next = list->tail;
  list->head = p;


}

void slist_clear(slist* list){
  while(!slist_empty(list)){
    slist_popfront(list);
}

}

void slist_print(slist* list, const char* msg){

  printf("%s\n", msg);
  if(slist_empty(list)) { printf("List is empty!\n"); return; }

  snode* p = list->head;

  while(p != NULL){
    printf("%d --> %p\n", p->data, p->next);
    p = p->next;
  }

}

int slist_front(slist* list){

  if(slist_empty(list)) { fprintf(stderr, "list is empty\n"); exit(1); }
  return list->head->data;

}

int slist_back(slist* list){

  if(slist_empty(list)){ fprintf(stderr, "list is empty\n"); exit(1); }
  return list->tail->data;
}

void slist_test(void){

  slist* list = slist_create();

  for(int i = 10; i < 50; i+=10){

    slist_pushfront(list, i);
  }

  slist_print(list, "List is created and is... ");
  printf("List's size is: %zu\n", slist_size(list));
  printf("List is empty? %d\n", slist_empty(list));
}
