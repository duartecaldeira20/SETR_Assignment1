// main.c
#include <stdio.h>
#include "dll.h"

int main() {
    DoublyLinkedList list;
    
    // Inicializa a lista com capacidade para 10 elementos do tipo DLL_Node
    MYDLLInit(&list, 10, sizeof(DLL_Node)); 

    printf("DLL inicializada: head = %p, tail = %p, count = %zu\n",
           (void*)list.head, (void*)list.tail, list.count);

    // Teste da MYDLLInsert
    int value1 = 42;
    int value2 = 99;

    if (MYDLLInsert(&list, 1, (unsigned char*)&value1) == 0) {
        printf("Inserção do valor %d com chave 1 bem-sucedida!\n", value1);
    } else {
        printf("Erro ao inserir o valor %d\n", value1);
    }

    if (MYDLLInsert(&list, 2, (unsigned char*)&value2) == 0) {
        printf("Inserção do valor %d com chave 2 bem-sucedida!\n", value2);
    } else {
        printf("Erro ao inserir o valor %d\n", value2);
    }

    // Exibir os elementos inseridos
    DLL_Node *current = list.head;
    while (current) {
        printf("Nó: chave = %d, valor = %d\n", current->key, *(int*)current->data);
        current = current->next;
    }

    return 0;
}

