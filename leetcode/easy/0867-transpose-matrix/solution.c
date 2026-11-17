#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be separately allocated with malloc.
 */
int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    // m is the number of rows, n is the number of columns of the original matrix
    int m = matrixSize;
    int n = matrixColSize[0];
    
    // The transposed matrix will have 'n' rows and 'm' columns
    *returnSize = n;
    
    // Allocate memory for the column sizes array of the returned matrix
    *returnColumnSizes = (int*)malloc(n * sizeof(int));
    
    // Allocate memory for the row pointers of the returned matrix
    int** result = (int**)malloc(n * sizeof(int*));
    
    for (int i = 0; i < n; i++) {
        (*returnColumnSizes)[i] = m; // Each new row has 'm' elements
        result[i] = (int*)malloc(m * sizeof(int));
    }
    
    // Perform the transpose operation: swap row and column indices
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[j][i] = matrix[i][j];
        }
    }
    
    return result;
}

