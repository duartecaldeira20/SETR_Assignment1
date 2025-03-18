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

