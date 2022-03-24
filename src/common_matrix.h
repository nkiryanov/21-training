#ifndef SRC_COMMON_MATRIX_H_
#define SRC_COMMON_MATRIX_H_

int** create_matrix(int rows, int columns);
int input_dimension(int *rows, int *columns);
int** input_matrix(int rows, int columns);
void output_matrix(int **matrix, int rows, int columns);

#endif  // SRC_COMMON_MATRIX_H_
