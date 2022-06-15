/*
 * =====================================================================================
 *
 *       Filename:  test3.c
 *
 *    Description:  This module tests the ll_sort function. 
 *
 *        Version:  1.0
 *        Created:  15/06/2022 23:00:11
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Tony De Corso 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "linked_list.h"
#include <stdio.h>

int cmp1(const void *a, const void *b, void *params);
int cmp2(const void *a, const void *b, void *params);

int main(void)
{
    conscell *list = NULL;

    int a = 101, b = -45, c = 1000, d = 12;

    list = ll_push(list, &a);
    list = ll_push(list, &b);
    list = ll_push(list, &c);
    list = ll_push(list, &d);

    printf("the original linked list:\n");

    for (conscell *p = list; p != NULL; p = p->next)
    {
	printf("%d ", *(int *)p->data);
    }

    putchar('\n');
    list = ll_sort(list, cmp1, NULL);

    printf("the list sorted in the ascending order:\n");
    
    for (conscell *p = list; p != NULL; p = p->next)
    {
	printf("%d ", *(int *)p->data);
    }

    putchar('\n');
    list = ll_sort(list, cmp2, NULL);

    printf("the list sorted in the descending order:\n");
    
    for (conscell *p = list; p != NULL; p = p->next)
    {
	printf("%d ", *(int *)p->data);
    }

    putchar('\n');
    ll_free(list);

    printf("linked list memory freed.\n");

    return 0;
}

int cmp1(const void *a, const void *b, void *params)
{
    int aa = *(int *)a;
    int bb = *(int *)b;
    if (aa < bb)
	return -1;
    else if(aa > bb)
	return 1;
    else
	return 0;
}

int cmp2(const void *a, const void *b, void *params)
{
    int aa = *(int *)a;
    int bb = *(int *)b;

    if (aa > bb)
	return -1;
    else if (aa > bb)
	return 1;
    else return 0;
}
