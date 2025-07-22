// Programs for finding shortest path
#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF 99999

int graph[MAX][MAX];
int vertices;

void dijkstra(int src)
{
  int dist[MAX], visited[MAX];

  for (int i = 0; i < vertices; i++)
  {
    dist[i] = INF;
    visited[i] = 0;
  }

  dist[src] = 0;

  for (int count = 0; count < vertices - 1; count++)
  {
    int min = INF, u = -1;
    for (int i = 0; i < vertices; i++)
    {
      if (!visited[i] && dist[i] <= min)
      {
        min = dist[i];
        u = i;
      }
    }

    visited[u] = 1;

    for (int v = 0; v < vertices; v++)
    {
      if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
      {
        dist[v] = dist[u] + graph[u][v];
      }
    }
  }

  printf("Vertex\tDistance from Source %d\n", src);
  for (int i = 0; i < vertices; i++)
  {
    printf("%d\t%d\n", i, dist[i]);
  }
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

  int src;
  printf("Enter source vertex: ");
  scanf("%d", &src);

  dijkstra(src);

  return 0;
}
