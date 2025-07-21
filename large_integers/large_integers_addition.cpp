#include <stdio.h>

#define MAX 1000

void addLargeNumbers(int num1[], int len1, int num2[], int len2, int result[], int *resultLen)
{
  int carry = 0, i = 0;
  int maxLen = len1 > len2 ? len1 : len2;

  for (i = 0; i < maxLen; i++)
  {
    int digit1 = i < len1 ? num1[i] : 0;
    int digit2 = i < len2 ? num2[i] : 0;
    int sum = digit1 + digit2 + carry;
    result[i] = sum % 10;
    carry = sum / 10;
  }

  if (carry)
  {
    result[i++] = carry;
  }

  *resultLen = i;
}

// function to read input number
void readNumber(int num[], int *len)
{
  char input[MAX];
  printf("Enter number: ");
  scanf("%s", input);

  int i = 0;
  while (input[i] != '\0')
    i++;

  *len = i;

  for (int j = 0; j < i; j++)
  {
    num[j] = input[i - j - 1] - '0';
  }
}

void printNumber(int num[], int len)
{
  for (int i = len - 1; i >= 0; i--)
  {
    printf("%d", num[i]);
  }

  printf("\n");
}

int main()
{
  int num1[MAX], num2[MAX], result[MAX];
  int len1, len2, resultLen;

  printf("Large Integer Addition: ");
  readNumber(num1, &len1);
  readNumber(num2, &len2);

  addLargeNumbers(num1, len1, num2, len2, result, &resultLen);

  printf("Sum: ");
  printNumber(result, resultLen);
  
  return 0;
}