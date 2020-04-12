//
//  dlist.h
//  linked_list
//
//  Created by William McCarthy on 084//20.
//  Copyright © 2020 William McCarthy. All rights reserved.
//

#ifndef dlist_h
#define dlist_h

#include <stdio.h>
#include <stdbool.h>


//-------------------------------------------------
typedef struct dnode dnode;
struct dnode {
  int data;
  dnode* prev;
  dnode* next;
};

typedef struct dlist dlist;
struct dlist {
  dnode* head;
  dnode* tail;
  size_t size;
};

//-------------------------------------------------
dnode* dnode_create(int data, dnode* prev, dnode* next){
  dnode* p = (dnode*)malloc(sizeof(dnode));

	p->data = data;
	p->prev = prev;
	p->next = next;
	return p;

}
dlist* dlist_create(void){

  dlist* p = (dlist*)malloc(sizeof(dlist));
  list->head = NULL;
  list->tail = NULL;

  list->size = 0;

  return p;

}

bool dlist_empty(dlist* list) {return list->size == 0;}
size_t dlist_size(dlist* list){return list->size;}

void dlist_popfront(dlist* list){

  dnode* p = list->tail;
  while(list->tail != NULL) { free(p); list->size = list->size - 1; }

}

void dlist_popback(dlist* list){

  dnode* p = list->head;
  while(list->head != NULL){free(p); list->size = list->size - 1;}
}

void dlist_pushfront(dlist* list, int data){

  struct dnode* newNode = dnode_create(data, dnode* prev, dnode* next);
	if(list->head == NULL) {
		list->head = newNode;
		return;
	}

  dnode* temp = list->head;
  temp->prev = newNode;
	newNode->next = list->head;
	list->head = newNode;



}
void dlist_pushback(dlist* list, int data){

    struct dnode* temp = list->head;
  	struct dnode* p = dnode_create(data, dnode* prev, dnode* next);
  	if(list->head == NULL) {
  		list->head = p;
  		return;
  	}

    while(temp->next != NULL) temp = temp->next; // Go To last Node
  	temp->next = p;
  	p->prev = temp;


}

void dlist_clear(dlist* list){

  while(!dlist_empty(list)){
    dlist_popfront(list);
}

}

void dlist_print(dlist* list, const char* msg){

  printf("%s\n", msg);
  if(dlist_empty(list)) { printf("List is empty!\n"); return; }

  snode* p = list->head;

  while(p != NULL){
    printf("%d --> %p\n", p->data, p->next);
    p = p->next;
  }

}

int dlist_front(dlist* list){

  if(dlist_empty(list)) { fprintf(stderr, "list is empty\n"); exit(1); }
  return list->head->data;
}

int dlist_back(dlist* list){

  if(dlist_empty(list)){ fprintf(stderr, "list is empty\n"); exit(1); }
  return list->tail->data;
}

void dlist_test(void){

  dlist* list = dlist_create();

  for(int i = 10; i < 50; i+=10){

    dlist_pushfront(list, i);
  }

  dlist_print(list, "List is created and is... ");
  printf("List's size is: %zu\n", dlist_size(list));
  printf("List is empty? %d\n", dlist_empty(list));
}


#endif /* dlist_h */
