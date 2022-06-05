/*
    Demo to test different uses of the xmalloc function.
    Inspired by: Rouben Rostamian (Programming Projects in C)
    Written by: Tony De Corso
*/
#include "xmalloc.h"
#include <stdio.h>
#include <stdlib.h>

void test_xmalloc();

int main(void)
{
    test_xmalloc();
}

void test_xmalloc()
{
    size_t nbytes = 1000000000;
    while (1)
    {
        void *x = xmalloc(nbytes);
        fprintf(stdout, "%zu bytes allocated\n", nbytes);
    }
}
