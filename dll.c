#include<stdlib.h>
#include<stdio.h>
#include "dll.h"

void MYDLLInit(DoublyLinkedList *list, int maxElements, int elementSize)
{
	list->size = 0;							// size of list = 0;
	list->head = NULL;						// 
	list->tail = NULL;
	list->maxElements = maxElements;
	
	for(int i = 0; i < maxElements; i++)
	{
		list->nodes[i].next = NULL;
		list->nodes[i].prev = NULL;
		list->nodes[i].occupied = false;
	}
	
}

// Implementation of the MYDLLInsert Function

int MYDLLInsert(DoublyLinkedList *list, uint16_t key, unsigned char *data, int dataSize) 
{
    if (list->size >= MAX_ELEMENTS) 
    {
        printf("The list is full.\n");
        
        return DLL_FULL;                      
    }

    DLL_Node *newNode = NULL;
    
    for (int i = 0; i < MAX_ELEMENTS; i++) 
    {
        if (!list->nodes[i].occupied) 
        {   
            newNode = &list->nodes[i];
            break;                      
        }
    }

    if (newNode == NULL) 
    {
        printf("No empty node found.\n");
        return NO_EMPTY_NODE;                      
    }

    newNode->key = key;
    
    int copySize = (dataSize > ELEMENT_SIZE) ? ELEMENT_SIZE : dataSize;
    
    for (int i = 0; i < copySize; i++) 
    {
        newNode->data[i] = data[i];
    }
    
    newNode->occupied = true;            

    newNode->prev = list->tail;
    newNode->next = NULL;
    
    if (list->tail != NULL) 
    {
        list->tail->next = newNode;
    }
    
    list->tail = newNode;
    
    if (list->head == NULL) 
    {
        list->head = newNode;
    }

    list->size++;
    
    return OK;                           
}



int MYDLLRemove(DoublyLinkedList *list, uint16_t key)
{
	DLL_Node *current = list->head;
	
    while (current != NULL && current->key != key) 
    {
        current = current->next;
    }

    if (current == NULL) 
    {
        printf("Element of the list with key %d not found.\n", key);
        
        return KEY_NOT_FOUND;                      
    }

    if (current->prev != NULL) 
    {
        current->prev->next = current->next;
    } 
    else 
    {
        list->head = current->next;      
    }

    if (current->next != NULL) 
    {
        current->next->prev = current->prev;
    } 
    else 
    {
        list->tail = current->prev;      
    }

    current->occupied = false;           

    list->size--;
                            
    return OK;                           
}


unsigned char *MYDLLFind(DoublyLinkedList *list, uint16_t key) 
{
	
	DLL_Node *current = list->head;
	
	while(current != NULL && current->key != key)
	{
		current = current->next;
	}
	
	if(current == NULL)
	{
		printf("Element of list with the key %d not found\n", key);
		
		return NULL;
	}
	
	return current->data;
	
}


unsigned char *MYDLLFindNext(DoublyLinkedList *list, uint16_t key) 
{
	
	if (list->size == 0) 
	{               
        return NULL;
    }

    DLL_Node *currentNode = list->head;
    
    while (currentNode != NULL) 
    {
        if (currentNode->key == key) 
        {
            break;                      
        }
        
        currentNode = currentNode->next;
    }

    if (currentNode == NULL) 
    {
        return NULL;                    
    }

    if (currentNode->next == NULL || !currentNode->next->occupied) 
    {
		return NULL;
	}

    return currentNode->next->data;     
}


unsigned char* MYDLLFindPrevious(DoublyLinkedList *list, uint16_t key) 
{
    
    if (list->size == 0) 
    {
        return NULL;                    
    }

    DLL_Node *currentNode = list->head;
    
    while (currentNode != NULL) 
    {
        if (currentNode->key == key)
        { 
        
            break;                      
        }
        
        currentNode = currentNode->next;
    }
    
    if (currentNode == NULL) 
    {
        return NULL;                    
    }
    
	if (currentNode->prev == NULL || !currentNode->prev->occupied) 
	{
		return NULL;
	}
    
    return currentNode->prev->data;     
}
