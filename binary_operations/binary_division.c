#include <stdio.h>
#include "binary_utils.h"

int main() {
    char bin1[64], bin2[64], quotient[64], remainder[64];

    printf("Enter dividend (binary): ");
    scanf("%s", bin1);

    printf("Enter divisor (binary): ");
    scanf("%s", bin2);

    int a = binaryToDecimal(bin1);
    int b = binaryToDecimal(bin2);

    if (b == 0) {
        printf("Error: Cannot divide by 0.\n");
        return 1;
    }

    decimalToBinary(a / b, quotient);
    decimalToBinary(a % b, remainder);

    printf("Division:\nQuotient: %s\nRemainder: %s\n", quotient, remainder);

    return 0;
}
