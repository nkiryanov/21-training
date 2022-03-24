#include <stdlib.h>
#include <stdio.h>

#include "common_matrix.h"

int** mul_matrix(int *fr, int *fc, 
                int **left_matrix, int lr, int lc,
                int** right_matrix, int rr, int rc);

int main() {
    int lrows, lcolumns;
    int rrows, rcolumns;
    int frows, fcolumns;
    int** left_matrix = NULL;
    int** right_matrix = NULL;
    int** final_matrix = NULL;
    int input_result;

    input_result = input_dimension(&lrows, &lcolumns);
    input_result = input_dimension(&rrows, &rcolumns);
    if (input_result) {
        left_matrix = input_matrix(lrows, lcolumns);
    }

    if (left_matrix) {
        right_matrix = input_matrix(rrows, rcolumns);
    }

    if (right_matrix) {
        final_matrix = mul_matrix(&frows, &fcolumns,
                                  left_matrix, lrows, lcolumns,
                                  right_matrix, rrows, rcolumns);
    }

    if (final_matrix) {
        output_matrix(final_matrix, frows, fcolumns);
        free(left_matrix);
        free(right_matrix);
        free(final_matrix);
    }

    return 0;
}

int** mul_matrix(int *fr, int *fc, 
                int **left_matrix, int lr, int lc,
                int** right_matrix, int rr, int rc) {
    int is_could_mul = 1;
    int **final_matrix = NULL;

    if (lc != rr) {
        is_could_mul = 0;
    }

    if (is_could_mul) {
        int iter = lc;
        *fr = lr;
        *fc = rc;
        final_matrix = create_matrix(*fr, *fc);

        if (final_matrix) {
            for (int i = 0; i < *fr; i++) {
                for (int j = 0; j < *fc; j++) {
                    int value = 0;
                    for (int k = 0; k < iter; k++) {
                        value += left_matrix[i][k] * right_matrix[k][j];
                    }
                    final_matrix[i][j] = value;
                }
            }
        }
    }
    return final_matrix;;
}