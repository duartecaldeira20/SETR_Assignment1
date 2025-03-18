unsigned char *MYDLLFind(DoublyLinkedList *list, uint16_t key) 
{
	
    if (list == NULL || list->head == NULL) 
    {
        return NULL;
    }

    DLL_Node *current = list->head;  

// Search the node with the key

    while (current != NULL) 
    {
		  
        if (current->key == key) 
        {  
            return current->data;	// return node data   
        }
        
        current = current->next;  
    }

    return NULL;  // not found 
}
