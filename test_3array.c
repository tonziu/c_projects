/*
    This module tests the make_3array function defined in
    array.h.

    Written by: Tony De Corso
*/

#include "array.h"
#include "xmalloc.h"
#include <stdio.h>

int main(void)
{
    int ***array;
    int n1 = 2, n2 = 3, n3 = 4;
    make_3array(array, n1, n2, n3);
    array[0][0][0] = 1;
    array[0][1][1] = 2;
    array[1][2][2] = 3;
    for (int i = 0; i < n1; i++){
        for (int j = 0; j < n2; j++){
            for (int k = 0; k < n3; k++){
                fprintf(stdout, "%d\t", array[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    free_vector(array);
    return 0;
}
