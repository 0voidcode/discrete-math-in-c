// Programs to implement Euclidean algorithms.
#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int a, b;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    int result = gcd(a, b);
    printf("GCD of %d and %d is %d\n", a, b, result);

    return 0;
}

