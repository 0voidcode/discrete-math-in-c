#include <stdio.h>
#include <stdlib.h>

// structure for a tree node
struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
};

// function to create a new node
struct Node *createNode(int value)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = value;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

// function to insert a node into BST
struct Node *insert(struct Node *root, int value)
{
  if (root == NULL)
  {
    return createNode(value);
  }

  if (value < root->data)
  {
    root->left = insert(root->left, value);
  }
  else if (value > root->data)
  {
    root->right = insert(root->right, value);
  }

  return root;
}

// function for inorder traversal
void inorder(struct Node *root)
{
  if (root != NULL)
  {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}
int main()
{
  struct Node *root = NULL;

  int n, value;

  printf("Enter number of nodes to insert: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    printf("Enter a value #%d: ", i + 1);
    scanf("%d", &value);
    root = insert(root, value);
  }

  printf("Inorder traversal of BST: ");
  inorder(root);
  printf("\n");
  return 0;
}