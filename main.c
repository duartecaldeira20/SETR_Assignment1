// main.c
#include <stdio.h>
#include "dll.h"

int main() {
    DoublyLinkedList list;
    
    MYDLLInit(&list, 10, sizeof(DLL_Node)); // Valores para teste da MYDLLINIT

    printf("DLL inicializada: head = %p, tail = %p, count = %zu\n",
           (void*)list.head, (void*)list.tail, list.count);

    return 0;
}
