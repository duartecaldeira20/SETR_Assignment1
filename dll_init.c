// Implementation of the MYDLLInit Function

void MYDLLInit(DoublyLinkedList *list, int maxElements, int elementSize)
{
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	list->maxElements = maxElements;
	
	for(int i = 0; i < maxElements; i++)
	{
		list->nodes[i].next = NULL;
		list->nodes[i].prev = NULL;
		list->nodes[i].occupied = false;
	}
	
}
