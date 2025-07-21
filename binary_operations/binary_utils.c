#include <stdio.h>
#include "binary_utils.h"

// function to find the length of string;
int stringLength(const char *s)
{
	int len = 0;
	while (s[len] != '\0')
		len++;
	return len;
}

// function to reverse the string
void reverse(char *s)
{
	int len = stringLength(s);
	int i = 0;
	for (i = 0; i < len / 2; i++)
	{
		char temp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = temp;
	}
}

// function to convert binary to decimal
int binaryToDecimal(const char *bin)
{
	int result = 0;
	int i = 0;
	while (bin[i] != '\0')
	{
		result = result * 2 + (bin[i] - '0');
		i++;
	}

	return result;
}

// function to convert decimal to binary
void decimalToBinary(int num, char *bin)
{
	if (num == 0)
	{
		bin[0] = '0';
		bin[1] = '\0';
		return;
	}

	int i = 0;
	while (num > 0)
	{
		bin[i++] = (num % 2) + '0';
		num /= 2;
	}

	bin[i] = '\0';
	reverse(bin);
}
