unsigned char* MyDLLFindPrevious(DoublyLinkedList* list, uint16_t key) 
{
    
    if (list->size == 0) 
    {
        return NULL;                    
    }

    DLL_Node *currentNode = list->head;
    
    while (currentNode != NULL) 
    {
        if (currentNode->key == key) 
        
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
