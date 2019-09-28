/* File: solve.c
Main program with solve function for the robot grid problem */
#include <stdio.h>
#include <stdlib.h>
#include "robot_functions.h"

void solve(int, int, int **);

int main(void) {
    int nrows, mcols;
    // read size of array
    scanf("%d %d", &nrows, &mcols);
    // dynamic memory allocation for grid
    int **grid = malloc(nrows * sizeof(int *));
    if (grid == NULL) {
        return -1;
    }
    for (int i = 0; i < nrows; i++) {
        *(grid + i) = malloc(mcols * sizeof(int));
        if (*(grid + i) == NULL) return -1;
    }
    // read array
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < mcols; j++) {
            char x;
            scanf("\n%c", &x);
            if (x == 'C')
                grid[i][j] = 1;
            else
                grid[i][j] = 0;
        }
    }
    solve(nrows, mcols, grid);
    // memory deallocation for grid
    for (int i = 0; i < nrows; i++) {
        free(*(grid + i));
    }
    free(grid);
    return 0;
}

void solve(int N, int M, int **grid) {
    int i, j, **matrix, coins;
#ifdef PUREREC
    i = N - 1;
    j = M - 1;
    printf("Maximum number of coins to pick up is: %d\n",
           pureRecursive(grid, N, M, i, j));
#elif defined(MATRREC)
    matrix = malloc(N * sizeof(int *));  // dynamic memory allocation for matrix
    if (matrix == NULL) {
        return;
    }
    for (i = 0; i < N; i++) {
        *(matrix + i) = malloc(M * sizeof(int));
        if (*(matrix + i) == NULL) return;
    }
    for (i = 0; i < N; i++)  // initialization of matrix to -1
        for (j = 0; j < M; j++) matrix[i][j] = -1;
    i = N - 1;
    j = M - 1;
    coins = matrRecursive(grid, matrix, N, M, i, j);
    printf("Path is: ");
    pathfinder(matrix, grid, N, M, i, j);
    printf("Picked up %d coins\n", coins);
    for (i = 0; i < N; i++)  // memory deallocation for matrix
        free(*(matrix + i));
    free(matrix);
#elif defined(ITERDP)
    matrix = malloc(N * sizeof(int *));  // dynamic memory allocation for matrix
    if (matrix == NULL) {
        return;
    }
    for (i = 0; i < N; i++) {
        *(matrix + i) = malloc(M * sizeof(int));
        if (*(matrix + i) == NULL) return;
    }
    for (i = 0; i < N; i++)  // initialization of matrix to -1
        for (j = 0; j < M; j++) matrix[i][j] = -1;
    coins = iterativeDP(grid, matrix, N, M);
    printf("Path is: ");
    i = N - 1;
    j = M - 1;
    pathfinder(matrix, grid, N, M, i, j);
    printf("Picked up %d coins\n", coins);
    for (i = 0; i < N; i++)  // memory deallocation for matrix
        free(*(matrix + i));
    free(matrix);
#endif
}
