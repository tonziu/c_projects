/*
    Demo to test different uses of the xmalloc function.
    Written by: Rouben Rostamian (Programming Projects in C)
*/
#include "xmalloc.h"
#include <stdio.h>
#include <stdlib.h>

void test_xmalloc(size_t nbytes);

int main(void)
{
    test_xmalloc(1000);
    test_xmalloc(0);
}

void test_xmalloc(size_t nbytes)
{
    void* result = xmalloc(nbytes);

    if (result != NULL)
    {
        fprintf(stdout, "%zu bytes allocated\n", nbytes);
        free(result);
        printf("memory freed\n");
    }
}
