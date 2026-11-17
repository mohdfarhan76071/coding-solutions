/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
    int m = matSize;
    int n = matColSize[0];
    
    // 1. If reshape is illegal, fall back to the original matrix dimensions (m x n)
    if (m * n != r * c) {
        r = m;
        c = n;
    }
    
    // 2. Set the return size (number of rows in the output matrix)
    *returnSize = r;
    
    // 3. Malloc the column sizes array (*returnColumnSizes)
    *returnColumnSizes = (int*)malloc(r * sizeof(int));
    for (int i = 0; i < r; i++) {
        (*returnColumnSizes)[i] = c;
    }
    
    // 4. Malloc the 2D array memory for the result matrix
    int** result = (int**)malloc(r * sizeof(int*));
    for (int i = 0; i < r; i++) {
        result[i] = (int*)malloc(c * sizeof(int));
    }
    
    // 5. Flatten the original matrix and populate the new structure
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int target_row = count / c;
            int target_col = count % c;
            result[target_row][target_col] = mat[i][j];
            count++;
        }
    }
    
    return result;
}
