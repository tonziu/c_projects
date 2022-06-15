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

