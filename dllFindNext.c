unsigned char *MYDLLFindNext(DoublyLinkedList *list, uint16_t key) 
{
	
    if (list == NULL || list->head == NULL) 
    {
        return NULL;
    }

    DLL_Node *current = list->head;
    
    // search the node with the key
    
    while (current != NULL) 
    {
        if (current->key == key) 
        {
            if (current->next != NULL) 
            {
                return current->next->data;  // return node data
            }
            
            return NULL; 
        }
        
        current = current->next;
    }

    return NULL;  // not found
