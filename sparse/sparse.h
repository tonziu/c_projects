/*
 * =====================================================================================
 *
 *       Filename:  sparse.h
 *
 *    Description:  Interface for the module sparse.c 
 *
 *        Version:  1.0
 *        Created:  10/06/2022 21:37:09
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Tony De Corso
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef H_SPARSE_H
#define H_SPARSE_H

#include "array.h"

void sparse_pack(double **a, int m, int n, int *Ap, int *Ai, double *Ax);
void sparse_unpack(double **a, int m, int n, int *Ap, int *Ai, double *Ax);

#endif // H_SPARSE_H
