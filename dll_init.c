// Implementation of the MYDLLInit Function
#include "dll.h"
#include <stdlib.h>

void MYDLLInit(DoublyLinkedList* list, size_t max_elements, size_t element_size) {
    if (list == NULL) return;

    list->head = NULL;
    list->tail = NULL;
    list->count = 0;  // Correção: usar count em vez de size
    list->max_elements = max_elements;
    list->element_size = element_size;
}
