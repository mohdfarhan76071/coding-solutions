# Transpose Matrix

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given a 2D integer array `matrix`, return  *the  **transpose**  of*  `matrix`.

The  **transpose**  of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

 

Original
C
 **Example 1:** 

```
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]

```

 **Example 2:** 

```
Input: matrix = [[1,2,3],[4,5,6]]
Output: [[1,4],[2,5],[3,6]]

```

 

 **Constraints:** 

- m == matrix.length
- n == matrix[i].length
- 1 <= m, n <= 1000
- 1 <= m * n <= 105
- -109 <= matrix[i][j] <= 109

## Solution

**Language:** C  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 16 MB (beats 28.68%)  
**Submitted:** 2026-11-17T06:16:12.668Z  

```c
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


```

---

[View on LeetCode](https://leetcode.com/problems/transpose-matrix/)