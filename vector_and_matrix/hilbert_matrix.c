/*
    This module tests the make_matrix function to create and visualize
    a hilbert matrix of n elements.
    Inspired by: Rouben Rostamian
    Written by: Tony De Corso
*/

#include "array.h"
#include "xmalloc.h"
#include <stdio.h>
#include <stdlib.h>

double **hilbert_matrix(int n);

int main(void)
{
    double **H;
    int n = 8;
    H = hilbert_matrix(n);
    for (int i = 0; i < n; i++)
    {
        if (H[i] != NULL)
        {
            for (int j = 0; j < n; j++)
            {
                fprintf(stdout, "%f\t", H[i][j]);
            }
            printf("\n");
        }
    }
    free_matrix(H);
    return 0;
}

double **hilbert_matrix(int n){
    double **H;
    make_matrix(H, n, n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            H[i][j] = 1.0 / (1 + i + j);
        }
    }
    return H;
}
