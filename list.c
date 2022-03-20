#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    return NULL;
  }

List * createList() {
    List* lista;
    lista = (List* ) malloc(sizeof(List));
    lista -> head = NULL;
    lista -> tail = NULL;
    lista -> current = NULL;
  return lista;
}

void * firstList(List * list) {
  list -> current = list -> head;
  return list-> head-> data;
}

void * nextList(List * list) {
    if(list -> current -> next != NULL){
      list -> current = list -> current -> next;
    }
  return list -> current -> data;
}

void * lastList(List * list) {
  list -> current = list -> tail;
  return list -> current -> data;
}

void * prevList(List * list) {
  list -> current = list -> current -> prev;
  return list -> current -> data;
}

void pushFront(List * list, void * data) {
    /*
    list -> current = list -> tail;
    list -> current -> next -> data = createNode(data);
    while (list-> current-> prev != NULL) {
        list -> current -> next -> data = list -> current -> data;
        list -> current = list -> current -> prev;
    }
    list -> head -> data = data;
    */
}

void pushBack(List * list, void * data) {
    //list -> current = list->tail;
   // list -> current -> next -> data = createNode(data);
   // pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
    //void aux = list -> current -> data;
   // list -> tail -> next = createNode(data);
   // list -> current = list -> tail -> prev;
    //while(list -> current -> prev != aux){
    //    list -> current -> next -> data = list -> current -> data;
    //    list -> current = list -> current -> prev;
    //}
}

void * popFront(List * list) {
    list -> current = list -> head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list -> current = list -> tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    //list -> current -> prev -> next = list -> current -> next;
   // list -> current -> next -> prev = list -> current -> prev;
    //list -> current = NULL;
    //list -> current = list -> head;
  return NULL;
}

void cleanList(List * list) {
    while (list -> head != NULL) {
        popFront(list);
    }
}
