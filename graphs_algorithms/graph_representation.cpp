// Programs to represent graphs
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node
{
  int vertex;
  struct Node *next;
} Node;

Node *adjList[MAX];
int vertices;

Node *createNode(int v)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

void addEdge(int src, int dest)
{
  Node *newNode = createNode(dest);
  newNode->next = adjList[src];
  adjList[src] = newNode;

  newNode = createNode(src);
  newNode->next = adjList[dest];
  adjList[dest] = newNode;
}

void printGraph()
{
  for (int i = 0; i < vertices; i++)
  {
    Node *temp = adjList[i];
    printf("Vertex %d: ", i);
    while (temp)
    {
      printf("%d -> ", temp->vertex);
      temp = temp->next;
    }
    printf("NULL\n");
  }
}

int main()
{
  printf("Enter number of vertices: ");
  scanf("%d", &vertices);

  for (int i = 0; i < vertices; i++)
    adjList[i] = NULL;

  int edges;
  printf("Enter number of edges: ");
  scanf("%d", &edges);

  printf("Enter edges (src dest):\n");
  for (int i = 0; i < edges; i++)
  {
    int src, dest;
    scanf("%d %d", &src, &dest);
    addEdge(src, dest);
  }

  printGraph();
  return 0;
}
