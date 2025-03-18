#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define MAX_ELEMENTS 100
#define ELEMENT_SIZE 256
#define OK 0
#define DLL_FULL -1
#define NO_EMPTY_NODE -2
#define KEY_NOT_FOUND -3

// Struct do nó da lista

typedef struct DLL_Node 
{
    uint16_t key;
    unsigned char data[ELEMENT_SIZE];
    struct DLL_Node *prev;
    struct DLL_Node *next;
    bool occupied;
    
} DLL_Node;

// Struct da lista

typedef struct 
{
	DLL_Node nodes[MAX_ELEMENTS];
    DLL_Node *head;
    DLL_Node *tail;
    int size;
    
} DoublyLinkedList;

// Funções da DLL

void MYDLLInit(DoublyLinkedList *list, int maxElements, int elementSize);
int MYDLLInsert(DoublyLinkedList *list, uint16_t key, unsigned char *data, int dataSize);
int MYDLLRemove(DoublyLinkedList *list, uint16_t key);
unsigned char *MYDLLFind(DoublyLinkedList *list, uint16_t key);
unsigned char *MYDLLFindNext(DoublyLinkedList *list, uint16_t key);
unsigned char *MYDLLFindPrevious(DoublyLinkedList *list, uint16_t key);

#endif
