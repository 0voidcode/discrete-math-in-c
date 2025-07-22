// Programs to generate combination
#include <stdio.h>
#include <string.h>

void generateCombinations(char *str, char *data, int start, int end, int index, int r)
{
  if (index == r)
  {
    data[r] = '\0';
    printf("%s\n", data);
    return;
  }

  for (int i = start; i <= end && end - i + 1 >= r - index; i++)
  {
    data[index] = str[i];
    generateCombinations(str, data, i + 1, end, index + 1, r);
  }
}

int main()
{
  char str[100];
  int r;

  printf("Enter a string: ");
  scanf("%s", str);

  printf("Enter combination length (r): ");
  scanf("%d", &r);

  int n = strlen(str);
  if (r > n || r < 0)
  {
    printf("Invalid combination length.\n");
    return 1;
  }

  char data[100];
  printf("Combinations of %s taken %d at a time are:\n", str, r);
  generateCombinations(str, data, 0, n - 1, 0, r);

  return 0;
}
