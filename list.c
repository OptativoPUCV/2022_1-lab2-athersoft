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
    Node *nodo = createNode(data);
    if(list -> current != NULL){
      if(list -> current -> next != NULL){
        nodo -> next = list -> current -> next;
      }
      if(list -> current -> prev != NULL){
        nodo -> prev = list -> current;
      }
      list -> current -> next = nodo;
    }else{
      list -> head = nodo;
    }
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
  Node *curr = list->current;  // Nodo "actual", el que será eliminado.
  Node *last = curr->prev;     // Nodo anterior al actual.
  Node *next = curr->next;     // Nodo siguiente al actual.
  //void *data = curr->data;

  // Verificamos que el actual sea la cabeza (aka head):
  if (list->current == list->head) {
    list->current = next;
    list->head = next;          // Recuerda asignar la nueva cabeza y el nuevo nodo "actual"
    list->current->prev = NULL; // Recuerda eliminar la cabeza anterior.
  }
  // Si no es la cabeza, entonces o es la cola, o es algo del medio.
  else {
    list->current = next;
    if (next) // Sin esto, "next" puede ser NULL (cola) y causar segfault.
      next->prev = last;  
  }
  free(curr); // Luego de aislar este nodo, podemos eliminarlo.
  return NULL;
}

void cleanList(List * list) {
    while (list -> head != NULL) {
        popFront(list);
    }
}
