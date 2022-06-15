/*
 * =====================================================================================
 *
 *       Filename:  test1.c
 *
 *    Description:  This module tests the ll_push function.  
 *
 *        Version:  1.0
 *        Created:  15/06/2022 21:44:57
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rouben Rostamian 
 *
 * =====================================================================================
 */

#include "linked_list.h"
#include <stdio.h>

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
    return 0;
}
