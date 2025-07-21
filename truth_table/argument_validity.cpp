// Programs to test validity of arguments by using truth tables.
#include <stdio.h>

// Implication: p --> q
int implies(int p, int q)
{
  return (!p) || q;
}

// Conjunction (AND)
int conjuction(int p, int q)
{
  return p && q;
}

int main()
{

  int p, q;

  printf("Testing validity of argument: ( (p --> q) ^ p ) --> q\n");
  printf(" p | q | ( (p --> q) ∧ p ) --> q\n");
  printf("------------------------------\n");

  int isValid = 1;

  for (p = 0; p <= 1; p++)
  {
    for (q = 0; q <= 1; q++)
    {
      int premise1 = implies(p, q);
      int premise2 = p;
      int combinedPremises = conjuction(premise1, premise2);
      int expression = implies(combinedPremises, q);

      printf(" %d | %d |         %d\n", p, q, expression);

      if (expression == 0)
      {
        isValid = 0;
      }
    }
  }

  if (isValid)
  {
    printf("\n The argument is VALID (tautology).\n");
  }
  else
  {
    printf("\n The argument is INVALID.\n");
  }
  return 0;
}
