// Programs to implement Extended Euclidean algorithms.
#include <stdio.h>

// Returns gcd, and updates x and y such that: ax + by = gcd(a, b)
int extendedGCD(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }

    int x1, y1;
    int gcd = extendedGCD(b, a % b, &x1, &y1);

    *x = y1;
    *y = x1 - (a / b) * y1;

    return gcd;
}

int main() {
    int a, b, x, y;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    int gcd = extendedGCD(a, b, &x, &y);
    printf("GCD of %d and %d is %d\n", a, b, gcd);
    printf("Values x and y such that %d*x + %d*y = %d: x = %d, y = %d\n", a, b, gcd, x, y);

    return 0;
}

