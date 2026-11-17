# Reshape the Matrix

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

In MATLAB, there is a handy function called `reshape` which can reshape an `m x n` matrix into a new one with a different size `r x c` keeping its original data.

You are given an `m x n` matrix `mat` and two integers `r` and `c` representing the number of rows and the number of columns of the wanted reshaped matrix.

The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.

If the `reshape` operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

 

Original
C
 **Example 1:** 

```
Input: mat = [[1,2],[3,4]], r = 1, c = 4
Output: [[1,2,3,4]]

```

 **Example 2:** 

```
Input: mat = [[1,2],[3,4]], r = 2, c = 4
Output: [[1,2],[3,4]]

```

 

 **Constraints:** 

- m == mat.length
- n == mat[i].length
- 1 <= m, n <= 100
- -1000 <= mat[i][j] <= 1000
- 1 <= r, c <= 300

## Solution

**Language:** C  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 15.8 MB (beats 49.89%)  
**Submitted:** 2026-11-17T06:11:22.334Z  

```c
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

```

---

[View on LeetCode](https://leetcode.com/problems/reshape-the-matrix/)