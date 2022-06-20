#include "linked_list.h"
#include <stdio.h>

void print(cell *list);
int cmp(const void *item1,const void *item2, void *params);
int catch_the_odds(const void *aa);
void square_me(void *data);

int main(void)
{
    cell *list = NULL;

    int a = 10, b = 2, c = -6, d = 53, e = -23;
    
    printf("Creating a new list...\n");
    printf("pushing 5 elements...\n");
    printf("Items:\n");

    list = ll_push(list, &a);
    list = ll_push(list, &b);
    list = ll_push(list, &c);
    list = ll_push(list, &d);
    list = ll_push(list, &e);

    print(list);

    printf("Popping two elements...\n");

    list = ll_pop(list);
    list = ll_pop(list);

    print(list);

    printf("Popping four more elements...\n");

    list = ll_pop(list);
    list = ll_pop(list);
    list = ll_pop(list);
    list = ll_pop(list);

    print(list);

    printf("Pushing items back in...\n");
    list = ll_push(list, &a);
    list = ll_push(list, &b);
    list = ll_push(list, &c);
    list = ll_push(list, &d);
    list = ll_push(list, &e);
    
    print(list);

    printf("Reversing the list...\n");
    list = ll_reverse(list);

    print(list);

    printf("Sorting the list in ascending order...\n");
    list = ll_sort(list, cmp, NULL);

    print(list);
    
    printf("filtering the odd values\n");
    cell *removed = NULL;
    list = ll_filter(list, catch_the_odds, &removed);
    print(list);
    printf("appending the removed items\n");
    list = ll_append(list, removed);
    print(list);

    printf("squaring the items\n");
    list = ll_map(list, square_me);
    print(list);

    printf("deleting the list...\n");
    ll_free(list);

    return 0;
}

void print(cell *list)
{
    if (list == NULL)
    {
	printf("\tNo items.\n");
	return;
    }

    while (list != NULL)
    {
	printf("\t%d\t", *(int*)list->data);
	list = list->next;
    }
    putchar('\n');
}

int cmp(const void *item1,const void *item2, void *params)
{
    int a = *(int *)item1;
    int b = *(int *)item2;

    if (a < b)
    {
	return -1;
    }
    else if (a > b)
    {
	return 1;
    }
    else 
	return 0;
}

int catch_the_odds(const void *aa)
{
    int a = *(int*)aa;
    return a%2;
}

void square_me(void *data)
{
    int *n = data;
    *n = (*n) * (*n);
}
