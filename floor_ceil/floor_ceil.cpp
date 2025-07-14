#include <stdio.h>

int floor(float num) {
	int intPart = (int)num;

	if(num >= 0 || intPart == num) {
		return intPart;
	}

	return intPart - 1;
}

int ceil(float num) {
	int intPart = (int)num;

	if(intPart = num) {
		return intPart;
	} else if(num >= 0) {
		return intPart + 1;
	} else {
		return intPart ;
	}

}
int main() {

	float input;

	printf("Enter a number: ");
	scanf("%f", &input);

	printf("Floor of %.2f is %d\n", input, floor(input));
	printf("Ceiling of %.2f is %d\n", input, ceil(input));

	return 0;
}
