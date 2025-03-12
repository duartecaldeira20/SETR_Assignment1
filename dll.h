#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdint.h>
#include <stddef.h>

// Struct do nó da lista
typedef struct DLL_Node {
    uint16_t key;
    unsigned char *data;
    struct DLL_Node *prev;
    struct DLL_Node *next;
} DLL_Node;

// Struct da lista
typedef struct {
    DLL_Node *head;
    DLL_Node *tail;
    size_t max_elements;
    size_t element_size;
    size_t count;
} DoublyLinkedList;

// Funções da DLL
void MyDLLInit(DoublyLinkedList *list, size_t max_elements, size_t element_size);
int MyDLLInsert(DoublyLinkedList *list, uint16_t key, unsigned char *data);
int MyDLLRemove(DoublyLinkedList *list, uint16_t key);
unsigned char *MyDLLFind(DoublyLinkedList *list, uint16_t key);
unsigned char *MyDLLFindNext(DoublyLinkedList *list, uint16_t key);
unsigned char *MyDLLFindPrevious(DoublyLinkedList *list, uint16_t key);

#endif