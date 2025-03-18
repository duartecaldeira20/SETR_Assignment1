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
