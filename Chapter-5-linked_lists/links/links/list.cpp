#include<stdlib.h>
#include<string.h>

#include"list.h"

void list_init(List *list, void(*destory)(void *data))
{
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	list->destory = destory;
	return;
}

void list_destory(List *list)
{
	void *data;
	return;
}

int list_ins_next(List *list, ListElmt *element, const void *data)
{
	ListElmt *new_element;

	if ((new_element = (ListElmt*)malloc(sizeof(ListElmt))) == NULL)
		return -1;

	new_element->data = (void*)data;

	if (element == NULL) // the data is going to insert at the head of the list
	{
		if (list_size(list) == 0)
			list->tail = new_element;

		new_element->next = list->head;
		list->head = new_element;
	}
	else   //insert after the element instead of the head
	{
		if (element->next == NULL)
			list->tail = element;
		
		new_element->next = element->next;
		element->next = new_element;
	}
	list->size++;
	return 0;
}

int  list_rem_next(List *list, ListElmt *element, void **data)
{
	ListElmt *old_element;

	if (list_size(list) == 0)
		return -1;

	//remove the head
	if (element == NULL)
	{
		old_element = list->head;
		*data = old_element->data;
		list->head = list->head->next;

		if (list_size(list) == 1)  //the last one is going to be deleted
			list->tail = NULL;
	}
	else
	{
		if (element->next == NULL)
			return -1;

		old_element = element->next;
		*data = old_element->data;
		element->next = old_element->next->next;
		
		if (element->next == NULL)
			list->tail = element;
	}

	free(old_element);
	
	list->size--;

	return 0;
}

void list_output(List *list)
{
	ListElmt *output;
	output = list->head;
	while (output)
	{
		printf("%d ", (int)output->data);
		output = output->next;
	}
}