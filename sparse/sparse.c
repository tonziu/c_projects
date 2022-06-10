/* 
 * This module defines two functions:
 * sparse_pack and sparse_unpack which respectively
 * packs a matrix in the CCS format and viceversa.
 * The module comprehends a test demo.
 *
 * Inspired by: Rouben Rostamian
 * Written by: Tony De Corso
 *
 */

#include "sparse.h"
#include "array.h"
#include <stdio.h>

void sparse_pack(double **a, int m, int n, int *Ap, int *Ai, double *Ax)
{
    int i, j, k;
    int count = 0;

    Ap[0] = 0;

    for (j = 0; j < n; j++)
    {
	for (i = 0; i < m; i++)
	{
	    if (a[i][j] != 0.0)
	    {
		count++;
	    }
	}

	Ap[j+1] = count;

    }

    k = 0;
    for (j = 0; j < n; j++)
    {
	for (i = 0; i < m; i++)
	{
	    if (a[i][j] != 0.0)
	    {
		Ai[k] = i;
		Ax[k] = a[i][j];
		k++;
	    }
	}
    }

}

void sparse_unpack(double **a, int m, int n,  int *Ap, int *Ai, double *Ax)
{
    int i, j, k;
    for (i = 0; i < m; i++)
    {
	
	for (j = 0; j < n; j++)
	{
	    a[i][j] = 0.0;
	}
    }

    for (j = 0; j < n; j++)
    {
	for (k = Ap[j]; k < Ap[j+1]; k++)
	{
	    i = Ai[k];
	    a[i][j] = Ax[k];
	}
    }

}
