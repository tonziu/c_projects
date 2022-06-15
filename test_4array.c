/*
    This module tests the make_4array function defined in
    array.h.

    Written by: Tony De Corso
*/

#include "array.h"
#include "xmalloc.h"
#include <stdio.h>

int main(void)
{
    int ****array;
    int n1 = 2, n2 = 3, n3 = 4, n4 = 5;
    make_4array(array, n1, n2, n3, n4);
    array[0][0][0][0] = 1;
    for (int i = 0; i < n1; i++){
        for (int j = 0; j < n2; j++){
            for (int k = 0; k < n3; k++){
                for (int z = 0; z < n4; z++){
                    fprintf(stdout, "%d\t", array[i][j][k][z]);
                }
                printf("\n");
            }
            printf("\n");
        }
        printf("\n");
    }
    free_vector(array);
    return 0;
}
