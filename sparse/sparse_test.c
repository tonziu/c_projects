/*
 * =====================================================================================
 *
 *       Filename:  sparse_test.c
 *
 *    Description: This file tests the sparse_pack and sparse_unpack functions. 
 *
 *        Version:  1.0
 *        Created:  10/06/2022 22:18:28
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Tony De Corso 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include "sparse.h"
#include "xmalloc.h"
#include "array.h"

int main(void)
{
    
    int m = 4, n = 5;
    double **a;
    int *Ap, *Ai;
    double *Ax;
    double **unpacked;

    make_matrix(a, m, n);
    make_matrix(unpacked, m, n);
    make_vector(Ap, n+1);

    a[0][0] = 0; a[0][1] = 7; a[0][2] = 0; a[0][3] = 0; a[0][4] = 1;
    a[1][0] = 0; a[1][1] = 4; a[1][2] = 0; a[1][3] = 3; a[1][4] = 0;
    a[2][0] = 6; a[2][1] = 6; a[2][2] = 5; a[2][3] = 1; a[2][4] = 4;
    a[3][0] = 5; a[3][1] = 5; a[3][2] = 0; a[3][3] = 0; a[3][4] = 0;

    printf("The sparse matrix is:\n\n");

    for (int i = 0; i < m; i++)
    {
	for (int j = 0; j < n; j++)
	{
	    printf("%.0f\t", a[i][j]);
	}
	printf("\n");
    }
    
    int nz = 0;

    for (int i = 0; i < m; i++)
    {
	for (int j = 0; j < n; j++)
	{
	    if (a[i][j] != 0) nz++;
	}
    }

    make_vector(Ai, nz);
    make_vector(Ax, nz);

    sparse_pack(a, m, n, Ap, Ai, Ax);

    printf("\nAp = [ %d, %d, %d, %d, %d, %d ]\n\n", Ap[0], Ap[1], Ap[2], Ap[3], Ap[4], Ap[5]);

    printf("Ai = [ ");
    for (int i = 0; i < nz; i++)
    {
	if (i == nz - 1)
	{
	    printf("%d ]\n\n", Ai[i]);
	    continue;
	}
	printf("%d, ", Ai[i]);
    }
    
    printf("Ax = [ ");
    for (int i = 0; i < nz; i++)
    {
	if (i == nz - 1) 
	{
	    printf("%.0f ]\n\n", Ax[i]);
	    continue;
	}
	printf("%.0f, ", Ax[i]);
    }

    sparse_unpack(unpacked, m, n, Ap, Ai, Ax);


    printf("Unpacked:\n\n");
    
    for (int i = 0; i < m; i++)
    {
	for (int j = 0; j < n; j++)
	{
	    printf("%.0f\t", unpacked[i][j]);
	}
	printf("\n");
    }

    printf("\n");

    free_matrix(a);
    free_matrix(unpacked);
    free_vector(Ap);
    free_vector(Ai);
    free_vector(Ax);
    
    return 0;
}
