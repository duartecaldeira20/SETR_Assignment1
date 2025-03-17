// Implementation of the MyDLLInit Function
#include "dll.h"

void MyDLLInit(DoublyLinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        list->nodes[i].prev = NULL;
        list->nodes[i].next = NULL;
    }
}