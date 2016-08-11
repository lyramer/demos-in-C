// Andy Wynden, V00746343

#include <stdio.h>
#include <stdlib.h>

void readMat(int numRows, int numCols, float matrix[numRows][numCols]) {
	int i, j;
// how to use this function to read multiple matrices?

	setvbuf(stdout, NULL, _IONBF, 0);
	for(i = 0; i < numRows; i++) {
		for(j = 0; j < numCols; j++) {
			fflush(stdout);
			scanf("%f", &matrix[i][j]);
		};
	}

}

void printMat(int numRows, int numCols, float matrix[numRows][numCols], int matFlag)  {

	int i, j;

	switch (matFlag) {
		case 0:
			printf("Matrix 1: \n");
			break;

		case 1:
			printf("Matrix 2: \n");
			break;

		case 2:
			printf("Product: \n");
			break;

		default:
			break;
	}

	for(i = 0; i < numRows; i++) {
		for(j = 0; j < numCols; j++) {
			printf("%7.2f\t", matrix[i][j]);
		};
		printf("\n");
	};


}

void matProduct(int numRows, int numCols, float matrixA[numRows][numCols], float matrixB[numCols][numRows], int matMsize, float matrixM[matMsize][matMsize]) {

	int h, i, j;

	for(i = 0; i < matMsize; i++) {
		for(j = 0; j < matMsize; j++) {
			matrixM[i][j] = 0.0;
		}
	}


	for (h = 0; h < numRows; h++) {
		for(i = 0; i < numRows; i++) {
			for(j = 0; j < numCols; j++) {
				matrixM[h][i] += (matrixA[h][j] * matrixB[j][i]);
			}
		}
	}

}

int main(void) {

	int numRowsA, numColsA, numRowsB, numColsB, matFlag, matMsize;

	// READS MATRIX A
	setvbuf(stdout, NULL, _IONBF, 0);
	fflush(stdout);
	scanf("%d %d", &numRowsA, &numColsA);

	float matrixA[numRowsA][numColsA];

	readMat(numRowsA, numColsA, matrixA);

	// READS MATRIX B
	fflush(stdout);
	scanf("%d %d", &numRowsB, &numColsB);
	float matrixB[numRowsB][numColsB];

	readMat(numRowsB, numColsB, matrixB);

	// PRINTS MATRICES
	matFlag = 0; // informs the printMat function which case to use for printing
	printMat(numRowsA, numColsA, matrixA, matFlag);
	matFlag = 1;
	printMat(numRowsB, numColsB, matrixB, matFlag);

	// COMPUTES PRODUCT OF TWO MATRICES

	if (numRowsA < numColsA) {matMsize = numRowsA;} // sets the size for the matrix product of the two matrices
	else {matMsize = numColsA;}
	float matrixM[matMsize][matMsize];

	matProduct(numRowsA, numColsA, matrixA, matrixB, matMsize, matrixM);
	matFlag = 2; // informs the printMat function which case to use for printing
	printMat(matMsize, matMsize, matrixM, matFlag);
	return EXIT_SUCCESS;
}
