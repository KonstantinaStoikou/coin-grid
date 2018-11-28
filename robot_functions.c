/*Source file of functions used in solve */
#include <stdio.h> 
#include "robot_functions.h"


int pureRecursive(int **px, int rows, int cols, int i, int j){
	if ((i == 0) && (j == 0))
		return px[0][0];
	if ((i == 0) && (j < cols))
		return pureRecursive(px, rows, cols, i, j - 1) + px[i][j];
	if ((j == 0) && (i < rows))
		return pureRecursive(px, rows, cols, i - 1, j) + px[i][j];
	if ((i < rows) && (j < cols))
		return (pureRecursive(px, rows, cols, i, j - 1) > pureRecursive(px, rows, cols, i - 1, j) ? pureRecursive(px, rows, cols, i, j - 1) : pureRecursive(px, rows, cols, i - 1, j)) + px[i][j];
}


int matrRecursive(int **px, int **matrix, int rows, int cols, int i, int j){ 
	if (matrix[i][j] != -1)
		return matrix[i][j];
	if ((i == 0) && (j == 0)){
		matrix[i][j] = px[0][0];
		return matrix[i][j];
	}
	if ((i == 0) && (j < cols)){
		matrix[i][j] =  matrRecursive(px, matrix, rows, cols, i, j - 1) + px[i][j];
		return matrix[i][j];
	}
	if ((j == 0) && (i < rows)){
		matrix[i][j] = matrRecursive(px, matrix, rows, cols, i - 1, j) + px[i][j];
		return matrix[i][j];
	}
	if ((i < rows) && (j < cols)){
		matrix[i][j] = (matrRecursive(px, matrix, rows, cols, i, j - 1) > matrRecursive(px, matrix, rows, cols, i - 1, j) ? matrRecursive(px, matrix, rows, cols, i, j - 1) : matrRecursive(px, matrix, rows, cols, i - 1, j)) + px[i][j];
		return matrix[i][j];
	}
}


int iterativeDP(int **px, int **matrix, int rows, int cols){ 
	int i,j;
	for (i = 0; i < rows; i++){
		for (j = 0; j < cols; j++){
			if ((i == 0) && (j == 0))
				matrix[i][j] = px[0][0];
			else if (i == 0)
				matrix[i][j] = matrix[i][j - 1] + px[i][j];
			else if (j == 0)
				matrix[i][j] = matrix[i - 1][j] + px[i][j];
			else 
				matrix[i][j] = ((matrix[i - 1][j] > matrix[i][j - 1]) ? matrix[i - 1][j] : matrix[i][j - 1]) + px[i][j];
		}
	}
	return matrix[rows - 1][cols - 1];	
}


void pathfinder(int **matrix, int **px, int rows, int cols, int i ,int j){
	if ((i == 0) && (j == 0)){
		if (px[i][j] == 1)
			printf("C");
		else
			printf(".");
		printf("(%d,%d)/%d --> ", i + 1, j + 1, matrix[i][j]);
        return;
	}
	else if ((i == 0) && (j < cols)){
		pathfinder(matrix, px, rows, cols, i, j - 1);
		if (px[i][j] == 1)
			printf("C");
		else
			printf(".");
		printf("(%d,%d)/%d --> ", i + 1, j + 1, matrix[i][j]);
	}
	else if ((j == 0) && (i < rows)){
		pathfinder(matrix, px, rows, cols, i - 1, j);
		if (px[i][j] == 1)
			printf("C");
		else
			printf(".");
		printf("(%d,%d)/%d --> ", i + 1, j + 1, matrix[i][j]);
	}
	else if ((i < rows) && (j < cols)){
		if (matrix[i][j-1] == matrix[i][j]){
			pathfinder(matrix, px, rows, cols, i, j - 1);
			if (px[i][j] == 1)
				printf("C");
			else
				printf(".");
			printf("(%d,%d)/%d --> ", i + 1, j + 1, matrix[i][j]);
		}
		else if (matrix[i - 1][j] == matrix[i][j]){
			pathfinder(matrix, px, rows, cols, i - 1, j);
			if (px[i][j] == 1)
				printf("C");
			else
				printf(".");
			printf("(%d,%d)/%d --> ", i + 1, j + 1, matrix[i][j]);
		}
		else if (matrix[i - 1][j] == matrix[i][j] - 1){
			pathfinder(matrix, px, rows, cols, i - 1, j);
			if (px[i][j] == 1)
				printf("C");
			else
				printf(".");
			printf("(%d,%d)/%d --> ", i + 1, j + 1, matrix[i][j]);
		}
		else{
			pathfinder(matrix, px, rows, cols, i , j - 1);
			if (px[i][j] == 1)
			printf("C");
		else
			printf(".");
		printf("(%d,%d)/%d --> ", i + 1, j + 1, matrix[i][j]);
		}
	}
}
