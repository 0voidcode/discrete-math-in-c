// Programs to implement Boolean matrix operations join, meet, and Boolean product.
#include <stdio.h>

#define SIZE 3

void printMatrix(int M[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++)
			printf("%d ", M[i][j]);
		printf("\n");
	}
	printf("\n");
}


// Element-wise OR
void booleanJoin(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			C[i][j] = A[i][j] || B[i][j];
}

// Element-wise AND
void booleanMeet(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			C[i][j] = A[i][j] && B[i][j];
}

// Boolean matrix product (v over ^)
void booleanProduct(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE]) {
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++) {
			C[i][j] = 0;
			for (int k = 0; k < SIZE; k++)
				C[i][j] = C[i][j] || (A[i][k] && B[k][j]);
		}
}

int main() {
	int A[SIZE][SIZE] = {
		{1, 0, 1},
		{0, 1, 0},
		{1, 1, 0}
	};

	int B[SIZE][SIZE] = {
		{0, 1, 1},
		{1, 0, 0},
		{0, 1, 0}
	};

	int C[SIZE][SIZE];

	printf("Matrix A:\n");
	printMatrix(A);

	printf("Matrix B:\n");
	printMatrix(B);

	booleanJoin(A, B, C);
	printf("Join (A v B):\n");
	printMatrix(C);

	booleanMeet(A, B, C);
	printf("Meet (A ^ B):\n");
	printMatrix(C);

	booleanProduct(A, B, C);
	printf("Boolean Product (A × B):\n");
	printMatrix(C);

	return 0;
}
