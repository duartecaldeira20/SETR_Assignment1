// Implementation of the MYDLLInsert Function
#include "dll.h"
#include <stdlib.h>
#include <string.h> 

int MYDLLInsert(DoublyLinkedList *list, uint16_t key, unsigned char *data){
      if (list == NULL || list->count >= list->max_elements) {
        return -1; // Retorna erro se a lista for nula ou se atingiu o limite de elementos maximo 
    }

    // Alocar memória para o novo nó
    DLL_Node* new_node = (DLL_Node*)malloc(sizeof(DLL_Node));

    // Alocar memória para os dados e copiá-los
    new_node->data = (unsigned char*)malloc(list->element_size);
    if (new_node->data == NULL) {
        free(new_node);
        return -3;
    }
    memcpy(new_node->data, data, list->element_size);

    // Inicializa o novo nó
    new_node->key = key;
    new_node->prev = NULL;
    new_node->next = list->head;

    // Ajusta os ponteiros da lista
    if (list->head != NULL) {
        list->head->prev = new_node;
    }
    list->head = new_node;
    if (list->tail == NULL) {
        list->tail = new_node;
    }

    list->count++;
    return 0; // Inserção bem-sucedida
}