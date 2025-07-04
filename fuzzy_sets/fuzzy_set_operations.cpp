// Program to implement fuzzy set operations.
#include<stdio.h>

#define SIZE 5

void printSet(float set[], int elements[]) {
	printf("{");
	for (int i = 0; i < SIZE; i++) {
		printf(" (%d, %.1f) ", elements[i], set[i]);
	}
	printf("}\n");
}

void fuzzyUnion(float A[], float B[], float result[]) {
    for (int i = 0; i < SIZE; i++)
        result[i] = (A[i] > B[i]) ? A[i] : B[i];
}

void fuzzyIntersection(float A[], float B[], float result[]) {
    for (int i = 0; i < SIZE; i++)
        result[i] = (A[i] < B[i]) ? A[i] : B[i];
}

void fuzzyComplement(float A[], float result[]) {
    for (int i = 0; i < SIZE; i++)
        result[i] = 1.0 - A[i];
}

int main() {
	int universe[SIZE] = {1, 2, 3, 4, 5};

	float A[SIZE] = {0.2, 0.5, 0.9, 0.1, 0.7};
	float B[SIZE] = {0.4, 0.3, 0.6, 0.9, 0.2};

	float unionSet[SIZE], intersectionSet[SIZE], complementA[SIZE];

	printf("Fuzzy Set A: ");
	printSet(A, universe);

	printf("Fuzzy Set B: ");
	printSet(B, universe);

	fuzzyUnion(A, B, unionSet);
	printf("\nUnion (A u B): ");
	printSet(unionSet, universe);

	fuzzyIntersection(A, B, intersectionSet);
	printf("Intersection (A n B): ");
	printSet(intersectionSet, universe);

	fuzzyComplement(A, complementA);
	printf("Complement of A: ");
	printSet(complementA, universe);

}
