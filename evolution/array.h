/*
    Defines an interface for creating type-independent vectors and matrixes.
    Author: Rouben Rostamian
*/

#ifndef H_ARRAY_H
#define H_ARRAY_H
#include "xmalloc.h"

#define make_vector(v,n) do { (v) = xmalloc((n) * sizeof *(v)); } while (0)
#define free_vector(v) do { free(v); v = NULL; } while (0)

#define make_matrix(a, m, n) do {                           \
    size_t make_matrix_loop_counter;                        \
    make_vector(a, (m) + 1);                                \
    for (make_matrix_loop_counter = 0;                      \
            make_matrix_loop_counter < (m);                 \
            make_matrix_loop_counter++)                     \
        make_vector((a)[make_matrix_loop_counter], (n));    \
    (a)[m] = NULL;                                          \
} while (0)

#define free_matrix(a) do {                                 \
    if (a != NULL){                                         \
        size_t make_matrix_loop_counter;                    \
        for (make_matrix_loop_counter = 0;                  \
                (a)[make_matrix_loop_counter] != NULL;      \
                make_matrix_loop_counter++){                \
            free_vector((a)[make_matrix_loop_counter]);     \
        }                                                   \
        free_vector(a);                                     \
    }                                                       \
} while (0)

#define make_3array(v, n1, n2, n3) do {                     \
    make_vector(v, (n1));                                   \
    size_t make_3array_loop_counter;                        \
    for (make_3array_loop_counter = 0;                      \
         make_3array_loop_counter<(n1);                     \
         make_3array_loop_counter++)                        \
    {                                                       \
        make_matrix(v[make_3array_loop_counter], (n2), (n3));   \
    }                                                       \
} while (0)

#define make_4array(v, n1, n2, n3, n4) do {                 \
    make_vector(v, (n1));                                   \
    size_t make_4array_loop_counter;                        \
    for (make_4array_loop_counter = 0;                      \
         make_4array_loop_counter<(n1);                     \
