#ifndef LIST_H
#define LIST_H

#include<stdio.h>

/*
define the structure of for the elements in the list
*/
typedef struct ListElmt_{
	void				*data;
	struct ListElmt_	*next;
} ListElmt;

/*
define a structure for linked lists
*/
typedef struct List_{
	int		size;

	int		(*match)(const void *key1, const void *key2);
	void	(*destory)(void *data);

	ListElmt *head;
	ListElmt *tail;
}List;

/*
public interfaces
*/

void list_init(List *list, void(*destory)(void *data));

void List_destory(List *list);

int list_ins_next(List *list, ListElmt *element, const void *data);

int list_rem_next(List *list, ListElmt *element, void **data);

void list_output(List *list);

#define list_size(list) ((list)->size)

#define list_head(list) ((list)->head)

#define list_tail(list) ((list)->tail)

#define list_is_head(list,element) ((element)==(list) -> head ? 1 : 0)

#define list_is_tail(element) ((element)->next==NULL?1:0)

#define list_data(element) ((element)->data)

#define list_next(element) ((element)->next)

#endif

