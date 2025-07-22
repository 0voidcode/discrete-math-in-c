// Programs for representing relations, testing its properties, and testing equivalence.
#include <stdio.h>

#define MAX 100

typedef struct
{
  int first;
  int second;
} Pair;

Pair relation[MAX];
int relationSize = 0;

int set[MAX];
int setSize = 0;

// function to Check if pair exists in relation
int pairExists(int a, int b)
{
  for (int i = 0; i < relationSize; i++)
  {
    if (relation[i].first == a && relation[i].second == b)
      return 1;
  }
  return 0;
}

// function to Check Reflexive: (a, a) exists for all a in set
int isReflexive()
{
  for (int i = 0; i < setSize; i++)
  {
    if (!pairExists(set[i], set[i]))
      return 0;
  }
  return 1;
}

// function to Check Symmetric: if (a, b) exists, then (b, a) must exist
int isSymmetric()
{
  for (int i = 0; i < relationSize; i++)
  {
    int a = relation[i].first;
    int b = relation[i].second;
    if (!pairExists(b, a))
      return 0;
  }
  return 1;
}

// function to Check Transitive: if (a, b) and (b, c) exist, (a, c) must exist
int isTransitive()
{
  for (int i = 0; i < relationSize; i++)
  {
    for (int j = 0; j < relationSize; j++)
    {
      if (relation[i].second == relation[j].first)
      {
        int a = relation[i].first;
        int c = relation[j].second;
        if (!pairExists(a, c))
          return 0;
      }
    }
  }
  return 1;
}

void inputSet()
{
  printf("Enter size of set: ");
  scanf("%d", &setSize);
  printf("Enter elements of set:\n");
  for (int i = 0; i < setSize; i++)
  {
    scanf("%d", &set[i]);
  }
}

void inputRelation()
{
  printf("Enter number of pairs in relation: ");
  scanf("%d", &relationSize);
  printf("Enter pairs (a b):\n");
  for (int i = 0; i < relationSize; i++)
  {
    scanf("%d %d", &relation[i].first, &relation[i].second);
  }
}

int main()
{
  inputSet();
  inputRelation();

  int reflexive = isReflexive();
  int symmetric = isSymmetric();
  int transitive = isTransitive();

  printf("\nProperties of the relation:\n");
  printf("Reflexive: %s\n", reflexive ? "Yes" : "No");
  printf("Symmetric: %s\n", symmetric ? "Yes" : "No");
  printf("Transitive: %s\n", transitive ? "Yes" : "No");

  if (reflexive && symmetric && transitive)
    printf("\n The relation is an Equivalence Relation.\n");
  else
    printf("\n The relation is NOT an Equivalence Relation.\n");

  return 0;
}
