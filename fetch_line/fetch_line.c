/*
    This module contains the fetch_line function,
    it fetches a line from a file stream and returns
    a NULL pointer if the stream ends or there is an
    error, otherwise it returns a pointer to the
    fetched line. The fetching includes trimming
    whitespaces and ignoring comments defined by
    the # character.

    Inspired by: Rouben Rostamian
    Written by: Tony De Corso
*/

#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "fetch_line.h"

static char *trim_line(char *s)
{
    if (*s == '\0')
        return s;

    while (isspace((unsigned char)*s))
        ++s;

    char *t = s;
    do {
        ++t;
    }
    while (*t != '#' && *t != '\0');

    if (*t == '#')
    {
        *t = '\0';
    }

    if (&s != &t)
    {
        t--;
        while (isspace((unsigned char) *t)){
            *t = '\0';
            --t;
        }
    }

    return s;
}

char *fetch_line(char *buf, int buflen, FILE *stream, int *lineno)
{
    char *s;
    if (fgets(buf, buflen, stream) == NULL)
        return NULL;

    ++*lineno;
    if (buf[strlen(buf) - 1] != '\n')
    {
        fprintf(stderr, "*** reading error: input line %d too "
                        "long for %s's buf[%d]\n",
                        *lineno, __func__, buflen);
        exit(EXIT_FAILURE);
    }
    s = trim_line(buf);
    if (*s != '\0')
        return s;
    else
        return fetch_line(buf, buflen, stream, lineno);
}
