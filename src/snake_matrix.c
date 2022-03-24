#include <stdlib.h>
#include <stdio.h>

#include "common_matrix.h"

int** get_columns_snake_matrix(int **matrix, int rows, int columns);
int** get_rows_snake_matrix(int **matrix, int rows, int columns);

int main() {
    int rows, columns;
    int** matrix = NULL;
    int** snake_matrix = NULL;
    int input_result;

    input_result = input_dimension(&rows, &columns);
    if (input_result) {
        matrix = input_matrix(rows, columns);
    }

    if (matrix) {
        snake_matrix = get_columns_snake_matrix(matrix, rows, columns);
        output_matrix(snake_matrix, rows, columns);
        free(snake_matrix);

        printf("\n");
        
        snake_matrix = get_rows_snake_matrix(matrix, rows, columns); 
        output_matrix(snake_matrix, rows, columns);
        free(snake_matrix);

        free(matrix);
    }

    return 0;
}

int** get_columns_snake_matrix(int **matrix, int rows, int columns) {
    int **snake_matrix;
    snake_matrix = create_matrix(rows, columns);

    if (snake_matrix) {
        int snake_iv, snake_j, snake_i;

        snake_iv = (rows == 1) ? 0 : 1;
        snake_i = snake_j = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                snake_matrix[snake_i][snake_j] = matrix[i][j];
                if (rows == 1) {
                    snake_j++;
                } else if (snake_iv == 1 && snake_i == rows - 1) {
                    snake_iv = 0;
                    snake_j += 1;
                } else if (snake_iv == 0 && snake_i == rows - 1) {
                    snake_iv = -1;
                } else if (snake_iv == -1 && snake_i == 0) {
                    snake_iv = 0;
                    snake_j += 1;
                } else if (snake_iv == 0 && snake_i == 0) {
                    snake_iv = 1;
                }
                snake_i += snake_iv;
            }
        }
    }
    return snake_matrix;
}

int** get_rows_snake_matrix(int **matrix, int rows, int columns) {
    int **snake_matrix;
    snake_matrix = create_matrix(rows, columns);

    if (snake_matrix) {
        int snake_jv, snake_j, snake_i;

        snake_jv = (columns == 1) ? 0 : 1;
        snake_i = snake_j = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                snake_matrix[snake_i][snake_j] = matrix[i][j];
                if (columns == 1) {
                    snake_i++;
                } else if (snake_jv == 1 && snake_j == columns - 1) {
                    snake_jv = 0;
                    snake_i += 1;
                } else if (snake_jv == 0 && snake_j == columns - 1) {
                    snake_jv = -1;
                } else if (snake_jv == -1 && snake_j == 0) {
                    snake_jv = 0;
                    snake_i += 1;
                } else if (snake_jv == 0 && snake_j == 0) {
                    snake_jv = 1;
                }
                snake_j += snake_jv;
            }
        }
    }
    return snake_matrix;
}