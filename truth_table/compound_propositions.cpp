#include <stdio.h>

int implies(int p, int q)
{
  return (!p) || q;
}

int main()
{
  int p, q, r;

  printf("Truth Table for (p ^ q) --> r\n");
  printf(" p | q | r | (p ∧ q) → r\n");
  printf("---------------------------\n");

  for (p = 0; p <= 1; p++)
  {
    for (q = 0; q <= 1; q++)
    {
      for (r = 0; r <= 1; r++)
      {
        int conjuction = p && q;
        int result = implies(conjuction, r);
        printf(" %d | %d | %d |     %d\n", p, q, r, result);
      }
    }
  }

  return 0;
}