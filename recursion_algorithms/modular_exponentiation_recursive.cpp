// Programs to compute b^n mod m by using recursion.
#include <stdio.h>

int modPower(int b, int n, int m)
{
  if (n == 0)
    return 1;
  int half = modPower(b, n / 2, m);
  int result = (half * half) % m;
  if (n % 2 == 1)
  {
    result = (result * b) % m;
  }
  return result;
}

int main()
{
  int b = 2, n = 10, m = 1000;
  printf("(%d^%d) mod %d = %d\n", b, n, m, modPower(b, n, m));
  return 0;
}