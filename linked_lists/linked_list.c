/* 
 * This module implements the linked lists
 * module, for using linked lists in C.
 * 
 * Inspired by: Rouben Rostamian
 * Written by: Tony De Corso
 *
 */

#include "linked_list.h"
#include "xmalloc.h"

conscell *ll_push(conscell *list, void *data)
{
    conscell *new = xmalloc(sizeof *new);
    new->data = data;
    new->next = list;
    return new;
}

conscell *ll_pop(conscell *list)
{
    conscell *new_head = xmalloc(sizeof *new_head);

    if (list == NULL)
    {
	return NULL;
    }

    if (list->next == NULL)
    {
	free(list);
	return NULL;
    }

    new_head->data = (conscell *)(list->next)->data;
    new_head->next = (conscell *)(list->next)->next;
    free(list);
    return new_head;
}

void ll_free(conscell *list)
{
    if (list != NULL)
    {
	conscell *new_head = list->next;
	free(list);
	ll_free(new_head);
    }
}

conscell *ll_reverse(conscell *list)
{
    if (list == NULL)
    {
	return NULL;
    }

    conscell *reversed = NULL;

    while (list != NULL)
    {
	reversed = ll_push(reversed, list->data);
	list = list->next;
    }

    return reversed;
}

conscell *ll_sort(conscell *list,
	          int (*cmp)(const void *a,
		             const void *b,
			     void *params),
		  void *params)
{
    conscell *list1 = NULL;
    conscell *list2 = NULL;
    conscell *p, *q, *head;

    if (list == NULL)
    {
	return list;
    }

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

