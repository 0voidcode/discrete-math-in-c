// Programs for generating minimum spanning trees.

#include <stdio.h>
#include <limits.h>

#define MAX 100

int graph[MAX][MAX];
int vertices;

void primMST()
{
  int parent[MAX], key[MAX], mstSet[MAX];

  for (int i = 0; i < vertices; i++)
  {
    key[i] = INT_MAX;
    mstSet[i] = 0;
  }

  key[0] = 0;
  parent[0] = -1;

  for (int count = 0; count < vertices - 1; count++)
  {
    int min = INT_MAX, u = -1;
    for (int v = 0; v < vertices; v++)
    {
      if (!mstSet[v] && key[v] < min)
      {
        min = key[v];
        u = v;
      }
    }

    mstSet[u] = 1;

    for (int v = 0; v < vertices; v++)
    {
      if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
      {
        parent[v] = u;
        key[v] = graph[u][v];
      }
    }
  }

  printf("Edge\tWeight\n");
  for (int i = 1; i < vertices; i++)
    printf("%d - %d\t%d\n", parent[i], i, graph[i][parent[i]]);
}

int main()
{
  printf("Enter number of vertices: ");
  scanf("%d", &vertices);

  printf("Enter adjacency matrix (0 if no edge):\n");
  for (int i = 0; i < vertices; i++)
  {
    for (int j = 0; j < vertices; j++)
    {
      scanf("%d", &graph[i][j]);
    }
  }

  primMST();

  return 0;
}
