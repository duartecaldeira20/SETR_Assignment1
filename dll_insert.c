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
