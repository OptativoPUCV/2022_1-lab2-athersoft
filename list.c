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

Node * createNode(void * data){
  Node *n = (Node*) calloc(1, sizeof(Node));
  n -> data = data;
  n -> next = NULL;
  return n;
}

List * createList() {
    List* lista = (List* ) calloc(1,sizeof(List));
    lista -> head = NULL;
    lista -> current = NULL;
    lista -> tail = NULL;
    return lista;
}

void * firstList(List * list) {
  if(list -> head && list -> head -> data){
    list -> current = list -> head;
    return list-> head-> data;
  }
  return NULL;
}

void * nextList(List * list) {
  if(list -> current != NULL){
    if(list -> current -> next != NULL){
      list -> current = list -> current -> next;
      return list -> current -> data;
    }
  }
    return NULL;
}

void * lastList(List * list) {
  if(list -> tail && list -> tail -> data){
    list -> current = list -> tail;
    return list -> tail -> data;
  }else{
    return NULL;
  }
}

void * prevList(List * list) {
  if(list -> current != NULL){
    if(list -> current -> prev != NULL){
      list -> current = list -> current -> prev;
      return list -> current -> data;
    }
  }
  return NULL;
}

void pushFront(List * list, void * data) {
    Node *nodo = createNode(data);
    if(list -> head == NULL){
      list -> head = nodo;
      list -> tail = nodo;
    }else{
      list -> head -> prev = nodo;
      list -> current = list -> head;
    }
    list -> head = nodo;
    list -> head -> next = list -> current;
}

void pushBack(List * list, void * data) {
    Node *nodo = createNode(data);
    if(list -> head == NULL){
      list -> head = nodo;
    }else{
      list -> tail -> next = nodo;
    }
    list -> tail = nodo;
}

void pushCurrent(List * list, void * data) {
    //void aux = list -> current -> data;
   // list -> tail -> next = createNode(data);
   // list -> current = list -> tail -> prev;
    //while(list -> current -> prev != aux){
    //    list -> current -> next -> data = list -> current -> data;
    //    list -> current = list -> current -> prev;
    //}
    Node *nodo = createNode(data);
    nodo -> prev = list -> current;
    list -> current -> next -> prev = nodo;
    list -> current -> next = nodo;
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
    list -> current -> prev -> next = list -> current -> next;
    list -> current -> next -> prev = list -> current -> prev;
    list -> current = NULL;
    list -> current = list -> head;
  return NULL;
}

void cleanList(List * list) {
    while (list -> head != NULL) {
        popFront(list);
    }
}
