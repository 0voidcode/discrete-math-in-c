#include <stdio.h>
#include "binary_utils.h"

int main() {
	char bin1[64], bin2[64], result[64];

	printf("Enter first binary number: ");
	scanf("%s", bin1);

	printf("Enter second binary number: ");
	scanf("%s", bin2);

	int a = binaryToDecimal(bin1);
	int b = binaryToDecimal(bin2);

	decimalToBinary(a - b, result);
	printf("Addition: %s - %s = %s\n", bin1, bin2, result);
	return 0;
}
