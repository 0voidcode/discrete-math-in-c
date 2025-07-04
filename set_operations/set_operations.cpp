// Program to implement set operations union, intersection, difference and cartesian product.
#include<stdio.h>

// Check if element exists in array
int exists(int arr[], int size, int val) {
	for(int i =0; i < size; i++)	{
		if(arr[i] == val) {
			return 1;
		}
	}
	return 0;
}


void unionSet(int A[], int sizeA, int B[], int sizeB) {
	printf("Union: {");
	for(int i = 0; i < sizeA; i++) {
		printf(" %d ", A[i]);
	}

	for(int i =0; i < sizeB; i++) {
		if(!exists(A, sizeA, B[i])) {
			printf(" %d ", B[i]);
		}
	}
	printf("}\n");
}

void intersectionSet(int A[], int sizeA, int B[], int sizeB ) {
	printf("Intersection: {");

	for(int i =0; i < sizeA; i++) {
		if(exists(B, sizeB, A[i])) {
			printf(" %d ", A[i]);
		}
	}

	printf("}\n");
}

void differenceSet(int A[], int sizeA, int B[], int sizeB) {
	printf("A-B:{");
	for(int i =0; i < sizeA; i++) {
		if(!exists(B, sizeB, A[i])) {
			printf(" %d ", A[i]);
		}
	}
	printf("}\n");
}

void cartesianProduct(int A[], int sizeA, int B[], int sizeB) {
	printf("Cartesian product A x B:\n{");
	for(int i = 0; i < sizeA; i++) {
		for(int j = 0; j < sizeB; j++) {
			printf(" (%d, %d) ", A[i], B[j]);
		}
	}
	printf("}\n");
}

int main() {
	int A[] = {1, 2, 3};
	int B[] = {3, 4, 5};

	int sizeA = sizeof(A) / sizeof(A[0]);
	int sizeB = sizeof(B) / sizeof(B[0]);

	printf("Set A: { 1 2 3 }\n");
	printf("Set B: { 3 4 5 }\n\n");

	unionSet(A, sizeA, B, sizeB);
	intersectionSet(A, sizeA, B, sizeB);
	differenceSet(A, sizeA, B, sizeB);
	cartesianProduct(A, sizeA, B, sizeB);

	return 0;
}
