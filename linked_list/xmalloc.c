/*
    Contains the malloc_or_exit() function.
    Written by: Rouben Rostamian (Programming Projects in C)
*/
#include <stdio.h>
#include "xmalloc.h"

/*  Its first argument is the number of bytes of memory to be allocated, the
    second argument is the file name calling the function and the third argument
    is the line in which the function has been called. If the allocation is
    successful, the function returns a pointer to the start of the allocated
    memory, otherwise it prints an error message like:
        foo.c:line 123: malloc() of 10000 bytes failed
*/

void *malloc_or_exit(size_t nbytes, const char *file, int line)
{
    void *x;
    if (nbytes == 0 || (x = malloc(nbytes)) == NULL)
    {
        fprintf(stderr, "%s: line %d: malloc() of %zu bytes failed.\n",
                         file, line, nbytes);
        exit(EXIT_FAILURE);
    }
    else
        return x;
}
