#include <stdlib.h>
#include <stdio.h>

#include "common_matrix.h"

int** create_matrix(int rows, int columns) {
    int **matrix = NULL;
    int *values_pointer = NULL;

    matrix = (int**)realloc(matrix, rows * sizeof(int*) + rows * columns * sizeof(int));
    if (!matrix) {
        perror("Errors during memory allocation for matrix.");
        exit(1);
    }
    values_pointer = (int*)(matrix + rows);
    for (int i = 0; i < rows; i++) {
        matrix[i] = values_pointer + i * columns;
    }
    return matrix;
}

int** input_matrix(int rows, int columns) {
    int **matrix;
    int input_result = 1;

    matrix = create_matrix(rows, columns);

    for (int i = 0; i < rows && input_result; i++) {
        for (int j = 0; j < columns && input_result; j++) {
            char end;
            int scanf_result;

            scanf_result = scanf("%d%c", &matrix[i][j], &end);
            if (scanf_result != 2 || (end != ' ' && end != '\n')) {
                input_result = 0;
                printf("n/a\n");
            }
        }
    }

    if (!input_result) {
        free(matrix);
        matrix = NULL;
    }
    return matrix;
}

int input_dimension(int *rows, int *columns) {
    int scanf_result = 0;
    int input_result = 1;
    char end;
    scanf_result = scanf("%d %d%c", rows, columns, &end);
    if (scanf_result != 3) {
        printf("n/a\n");
        input_result = 0;
    }
    return input_result;
}

void output_matrix(int **matrix, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            if (j == 0) {
                printf("%d", matrix[i][j]);
            } else {
                printf(" %d", matrix[i][j]);
            }
        }
        printf("\n");
    }
}
