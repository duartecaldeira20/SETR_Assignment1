#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "dll.h"

int main() 
{
    DoublyLinkedList dll; // Estrutura da lista duplamente ligada
    bool isInitialized = false; // Indica se a lista foi inicializada
    int choice; // Armazena a opção escolhida pelo usuário
    unsigned char inputData[ELEMENT_SIZE]; // Buffer para inserir dados
    unsigned char *foundData; // Ponteiro para armazenar os dados encontrados
    int key; // Armazena a chave do elemento

    while (1) 
    {
        // Menu de opções
        printf("\n=== DOUBLY LINKED LIST MENU ===\n");
        printf("1 - Initialize List\n");
        printf("2 - Insert Element\n");
        printf("3 - Remove Element\n");
        printf("4 - Find Element\n");
        printf("5 - Find Next Element\n");
        printf("6 - Find Previous Element\n");
        printf("7 - Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Remove enter do buffer

        if (choice != 1 && !isInitialized) 
        {
            printf("Error: You must initialize the list first!\n");
            continue;
        }

        switch (choice) 
        {
            case 1:
                MYDLLInit(&dll, MAX_ELEMENTS, ELEMENT_SIZE);
                printf("List initialized successfully!\n");
                isInitialized = true;
                break;

            case 2:
                printf("Enter data: ");
                fgets((char *)inputData, ELEMENT_SIZE, stdin);
                inputData[strcspn((char *)inputData, "\n")] = '\0'; 
                
                // correção, forma de encontrar menor ID possível
                
                // erro: quando se removia um elemento com ID x de uma 
                // lista com y elementos (quando inseridos todos de 
                // seguida y elementos = y ID), o próximo elemento a ser
                // inserido não ficava com o ID que foi removido, mas 
                // sim com o ID y+1
                
                // assim, as keys são aproveitadas e evita buracos, no
                // entanto chamamos a função find e como o ID não é 
                // encontrado, ele devolve a mensagem de que o elemento 
                // no ID não foi encontrado, logo a seguir coloca o 
                // elemento nesse ID
                
				int newKey = 1;
				bool keyFound = false;
				
				for (int i = 1; i <= MAX_ELEMENTS; i++)  // percorre todos os ID
				{
					if (MYDLLFind(&dll, i) == NULL)  //  se ID não existir, é usado
					{
						newKey = i;
						keyFound = true;
						
						break;
					}
				}

                if (MYDLLInsert(&dll, newKey, inputData, ELEMENT_SIZE) == OK) 
                {
                    printf("Inserted element with ID %d: %s\n", newKey, inputData);
                }
                else 
                {
                    printf("Error: Unable to insert element.\n");
                }
                break;

            case 3:
                printf("Enter the ID to remove: ");
                scanf("%d", &key);
                getchar();

                if (MYDLLRemove(&dll, key) == OK) 
                {
                    printf("Element with ID %d removed successfully.\n", key);
                } 
                else 
                {
                    printf("Error: Element with ID %d not found.\n", key);
                }
                break;

            case 4:
                printf("Enter the ID to find: ");
                scanf("%d", &key);
                getchar();

                foundData = MYDLLFind(&dll, key);
                
                if (foundData != NULL) 
                {
                    printf("Found element - ID %d: %s\n", key, foundData);
                } 
                else 
                {
                    printf("Error: Element not found.\n");
                }
                break;

            case 5:
                printf("Enter the ID to find the next element: ");
                scanf("%d", &key);
                getchar();

                foundData = MYDLLFindNext(&dll, key);
                
                if (foundData != NULL) 
                {
                    printf("Next element after ID %d: %s\n", key, foundData);
                } 
                else 
                {
                    printf("No next element found.\n");
                }
                break;

            case 6:
                printf("Enter the ID to find the previous element: ");
                scanf("%d", &key);
                getchar();

                foundData = MYDLLFindPrevious(&dll, key);
                
                if (foundData != NULL) 
                {
                    printf("Previous element before ID %d: %s\n", key, foundData);
                } 
                else 
                {
                    printf("No previous element found.\n");
                }
                break;

            case 7:
                printf("Exiting... Goodbye!\n");
                return 0;

            default:
                printf("Invalid option. Please choose a valid number.\n");
        }
    }
}

