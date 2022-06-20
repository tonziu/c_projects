/* 
 * This module implements the usage of linked lists in C.
 *  
 * Inspired by: Rouben Rostamian
 * Written (except for the ll_sort function) by: Tony De Corso
 *
 * */

#include "xmalloc.h"
#include "linked_list.h"

cell *ll_push(cell *list, void *data)
{
    cell *head = xmalloc(sizeof *head);  
    head->data = data;
    head->next = list;
    return head;
}

cell *ll_pop(cell *list)
{
    if (list == NULL)
    {
	return NULL;
    }
    free(list);
    list = list->next;
    return list;
}

void ll_free(cell *list)
{
    if (list == NULL)
	return;

    else 
    {
	cell *head = list->next;
	free(list);
	ll_free(head);
    }
}

cell *ll_reverse(cell *list)
{
    if (list == NULL)
	return NULL;

    cell *reversed = NULL;

    while (list != NULL)
    {
	reversed = ll_push(reversed, list->data);
	list = list->next;
    }

    return reversed;
    
}

cell *ll_sort(cell *list, int (*cmp)(const void *item1,
	                             const void *item2, 
				     void *params), void *params)
{
    
    cell *list1 = NULL;
    cell *list2 = NULL;
    cell *p, *q, *head; // p is the list cursor and 
			// q is needed for remembering
			// the item next to p

    if (list == NULL)
        return list;

    head = list;
    p = list->next;

    while (p != NULL)
    {
        q = p->next;

        if (cmp(p->data, head->data, params) < 0)
        {
	    p->next = list1;
	    list1 = p;
        }
        else
        {
	    p->next = list2;
	    list2 = p;
        }
        p = q;
    }

    list1 = ll_sort(list1, cmp, params);
    list2 = ll_sort(list2, cmp, params);
    head->next = list2;

    if (list1 == NULL)
        return head;

    for (p = list1; p->next != NULL; p = p->next)
    {
        ;
    }
    p->next = head;
    return list1;
}

cell *ll_filter(cell *list, int (*filter) (const void *a), cell **removed)
{
    if (list == NULL)
	return list;
    else if (filter(list->data)) 
    {
	cell *p = list->next;
	list->next = *removed;
	*removed = list;
	return ll_filter(p, filter, removed);
    }
    else
    {
	list->next = ll_filter(list->next, filter, removed);
	return list;
    }
}

int ll_length(cell *list)
{
    int count = 0;
    while (list != NULL)
    {
	count++;
	list = list->next;
    }
    return count;
}

cell *ll_append(cell *list1, cell *list2)
{
    if (list1 == NULL)
    {
	return list2;
    }
    else if (list2 == NULL)
    {
	return list1;
    }
    else
    {
	cell *p = list1;
	while (list1->next != NULL)
	{
	    list1 = list1->next;
	}
	list1->next = list2;
	return p;
    }
}

cell *ll_map(cell *list, void (*map)(void *data))
{
    if (list == NULL)
	return list;
    else
    {
	cell *p = list;
	while (p != NULL)
	{
	   map(p->data);
	   p = p->next;
	}

	return list;
    }
}
