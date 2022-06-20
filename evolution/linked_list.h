/* 
 * 
 * This module defines the linked_list interface. 
 * The ll_push function insert a new item in the list and
 * returns the pointer to the list.
 * The ll_pop function deletes the first item from the list
 * and returns a pointer to the list.
 * The ll_reverse function reverse the items in the list
 * and returns a pointer to the list.
 * The ll_free function frees the memory from the whole list.
 * The ll_sort function orders the items in the list based 
 * on the cmp function and the parameters (params).
 *
 * Written by: Rouben Rostamian
 *
 * */
#ifndef H_LINKED_LIST_H
#define H_LINKED_LIST_H

typedef struct cell
{
    void *data;
    struct cell *next;
} cell;

cell *ll_push(cell *list, void *data);

cell *ll_pop(cell *list);

cell *ll_reverse(cell *list);

void ll_free(cell *list);

cell *ll_sort(cell *list, int (*cmp)(const void *item1,
	                             const void *item2, 
				     void *params), void *params);

cell *ll_filter(cell *list,
	        int (*filter) (const void *a),
		cell **removed);

int ll_length(cell *list);

cell *ll_append(cell *list1, cell *list2);

cell *ll_map(cell *list, void (*map)(void *data));

#endif
