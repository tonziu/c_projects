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
