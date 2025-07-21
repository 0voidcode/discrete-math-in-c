// Programs to compute linear search by using recursion.
#include <stdio.h>

int linearSearch(int arr[], int size, int key, int index)
{
  if (index == size)
    return -1;
  if (arr[index] == key)
    return index;
  return linearSearch(arr, size, key, index + 1);
}

int main()
{
  int arr[] = {3, 5, 7, 9, 11};
  int size = sizeof(arr) / sizeof(arr[0]);
  int key;

  printf("Enter key: ");
  scanf("%d", &key);

  int index = linearSearch(arr, size, key, 0);
  if (index != -1)
    printf("Element %d found at index %d\n", key, index);
  else
    printf("Element %d not found\n", key);
  return 0;
}
