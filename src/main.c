#include <stdio.h>
#include "dll.h"


int main() {
    DoublyLinkedList list;
    
    // Inicializa a lista com capacidade para 10 elementos
    MYDLLInit(&list, 10, ELEMENT_SIZE); 
    printf("DLL inicializada: head = %p, tail = %p, size = %d\n",
           (void*)list.head, (void*)list.tail, list.size);

    // Teste de inserção
    int value1 = 42;
    int value2 = 99;
    int value3 = 123;

    if (MYDLLInsert(&list, 1, (unsigned char*)&value1, sizeof(value1)) == OK) {
        printf("Inserção do valor %d com chave 1 bem-sucedida!\n", value1);
    } else {
        printf("Erro ao inserir o valor %d\n", value1);
    }

    if (MYDLLInsert(&list, 2, (unsigned char*)&value2, sizeof(value2)) == OK) {
        printf("Inserção do valor %d com chave 2 bem-sucedida!\n", value2);
    } else {
        printf("Erro ao inserir o valor %d\n", value2);
    }
    
    if (MYDLLInsert(&list, 3, (unsigned char*)&value3, sizeof(value3)) == OK) {
        printf("Inserção do valor %d com chave 3 bem-sucedida!\n", value3);
    } else {
        printf("Erro ao inserir o valor %d\n", value3);
    }

    // Exibir os elementos inseridos
    DLL_Node *current = list.head;
    while (current) {
        printf("Nó: chave = %d, valor = %d\n", current->key, *(int*)current->data);
        current = current->next;
    }

    // Teste da função MYDLLFind
    uint16_t keyToFind = 2;
    unsigned char *foundData = MYDLLFind(&list, keyToFind);
    if (foundData != NULL) {
        printf("Encontrado valor %d para a chave %d.\n", *(int*)foundData, keyToFind);
    }

    // Teste da função MYDLLRemove
    uint16_t keyToRemove = 2;
    if (MYDLLRemove(&list, keyToRemove) == OK) {
        printf("Remoção do valor com chave %d bem-sucedida!\n", keyToRemove);
    } else {
        printf("Erro ao remover o valor com chave %d.\n", keyToRemove);
    }

    // Exibir os elementos após a remoção
    printf("Elementos após remoção:\n");
    current = list.head;
    while (current) {
        printf("Nó: chave = %d, valor = %d\n", current->key, *(int*)current->data);
        current = current->next;
    }

    // Teste da função MYDLLFindNext
    uint16_t keyToFindNext = 1;
    unsigned char *foundNextData = MYDLLFindNext(&list, keyToFindNext);
    if (foundNextData != NULL) {
        printf("Encontrado próximo valor %d após a chave %d.\n", *(int*)foundNextData, keyToFindNext);
    } else {
        printf("Nenhum próximo valor encontrado após a chave %d.\n", keyToFindNext);
    }

    // Teste da função MYDLLFindPrevious
    uint16_t keyToFindPrev = 3;
    unsigned char *foundPrevData = MYDLLFindPrevious(&list, keyToFindPrev);
    if (foundPrevData != NULL) {
        printf("Encontrado valor anterior %d antes da chave %d.\n", *(int*)foundPrevData, keyToFindPrev);
    } else {
        printf("Nenhum valor anterior encontrado antes da chave %d.\n", keyToFindPrev);
    }

    return 0;
}
